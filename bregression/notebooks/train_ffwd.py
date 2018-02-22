#!/usr/bin/env python

import numpy as np

import bregnn.ffwd as ffwd 
import bregnn.io as io

import os
import json

from pprint import pprint

from sklearn.model_selection import train_test_split,KFold

from optparse import OptionParser, make_option

##
raw_features = ['Jet_pt',
                    'Jet_eta',
                    'rho',
                    'Jet_mt',
                    'Jet_leadTrackPt',
                    'Jet_leptonPtRel',
                    'Jet_leptonDeltaR',
                    'Jet_neHEF',
                    'Jet_neEmEF',
                    'Jet_vtxPt',
                    'Jet_vtxMass',
                    'Jet_vtx3dL',
                    'Jet_vtxNtrk',
                    'Jet_vtx3deL',
                    'Jet_numDaughters_pt03']
rings=[
                    'Jet_energyRing_dR0_em',
                    'Jet_energyRing_dR1_em',
                    'Jet_energyRing_dR2_em',
                    'Jet_energyRing_dR3_em',
                    'Jet_energyRing_dR4_em',
                    'Jet_energyRing_dR0_neut',
                    'Jet_energyRing_dR1_neut',
                    'Jet_energyRing_dR2_neut',
                    'Jet_energyRing_dR3_neut',
                    'Jet_energyRing_dR4_neut',
                    'Jet_energyRing_dR0_ch',
                    'Jet_energyRing_dR1_ch',
                    'Jet_energyRing_dR2_ch',
                    'Jet_energyRing_dR3_ch',
                    'Jet_energyRing_dR4_ch',
                    'Jet_energyRing_dR0_mu',
                    'Jet_energyRing_dR1_mu',
                    'Jet_energyRing_dR2_mu',
                    'Jet_energyRing_dR3_mu',
                    'Jet_energyRing_dR4_mu']

features=raw_features
for ring in rings:
    features.append('%s_Jet_rawEnergy'%ring)
print(features)

## command_line options
parser = OptionParser(option_list=[
    make_option("--inp-dir",type='string',dest="inp_dir",default=os.environ['SCRATCH']+'/bregression'),
    make_option("--out-dir",type='string',dest="out_dir",default=os.environ['SCRATCH']+'/bregression/NN_output/'),
    make_option("--inp-file",type='string',dest='inp_file',default='ttbar_unweighted_full80M_selected_train.hd5'),
    make_option("--features",type='string',dest='features',default=''),
    make_option("--normalize-target",action="store_true",dest="normalize_target",default=True),
    make_option("--no-normalize-target",action="store_false",dest="normalize_target"),
    make_option("--loss",type='string',dest="loss",default="HybridLoss"),
    make_option("--valid-frac",type='float',dest='valid_frac',default=0.10),
    make_option("--batch-size",type='int',dest='batch_size',default=1024),
    make_option("--epochs",type='int',dest='epochs',default=20),
    make_option("--hparams",type='string',dest='hparams',default=None),
    make_option("--seed",type='int',dest='seed',default=98543),
    make_option("--x-val",action="store_true",dest='x_val',default=False),
    make_option("--nkfolds",type='int',dest='nkfolds',default=5),
])

## parse options
(options, args) = parser.parse_args()

if options.features == '':
    features = features
    options.features = ','.join(features)
else:
    features = options.features.split(',')

if os.path.exists(options.inp_file):
    inp_file = options.inp_file
else:
    inp_file = options.inp_dir+'/'+options.inp_file

hparams = {}
if options.hparams is not None:
    for fname in  options.hparams.split(','):
       with open(fname) as hf:
          pars = json.loads(hf.read())
          hparams.update(pars)    # if inside several files we change the same parameter, it will overwrite for the one in the last file    
    
## read data
columns = raw_features + rings + ['Jet_mcPt'] + ['Jet_rawEnergy'] + ['Jet_e'] + ['Jet_corr_JEC'] + ['Jet_corr_JER']
data = io.read_data(inp_file, columns = columns)

#Get rid of JEC and JER and bring back to raw
for ring in rings:
    data['%s_Jet_rawEnergy'%ring]=data['%s'%ring]/data['Jet_rawEnergy']
data['Jet_pt']=data['Jet_pt']*data['Jet_rawEnergy']/data['Jet_e']*data['Jet_corr_JEC']
data['Jet_mt']=data['Jet_mt']*data['Jet_rawEnergy']/data['Jet_e']*data['Jet_corr_JEC']

X = data[features].values
y = (data['Jet_mcPt']/data['Jet_pt']).values.reshape(-1,1)

y_mean = np.median(y)
y_std = y.std()
print(y_mean,y_std)

# normalize target
if options.normalize_target:
    y -= y_mean
    y /= y_std



# sort out model parameters
def get_kwargs(fn,**kwargs):
    params = set(fn.__code__.co_varnames[:fn.__code__.co_argcount]+tuple(kwargs.keys()))
    for par in params:
        if hasattr(options,par):
            kwargs[par] = getattr(options,par)
        if par in hparams:
            kwargs[par] = hparams.pop(par)
    return kwargs

loss_params=dict()
#if options.loss == 'QuantileLoss' : loss_params=dict(taus=[0.4,0.25,0.75])
init_kwargs = get_kwargs(ffwd.FFWDRegression.__init__,monitor_dir=options.out_dir,loss_params=loss_params)
fit_kwargs = get_kwargs(ffwd.FFWDRegression.fit,batch_size=options.batch_size,epochs=options.epochs)

print(init_kwargs)
print(fit_kwargs)

reg = ffwd.FFWDRegression('ffwd',X.shape[1:],**init_kwargs)

pprint(reg.get_params())

model = reg()

print(model.summary())
model_summary = str(model.to_json()) 

trainable_count = int(np.sum([ffwd.K.count_params(p) for p in set(model.trainable_weights)]))
non_trainable_count = int(np.sum([ffwd.K.count_params(p) for p in set(model.non_trainable_weights)]))

if not os.path.exists(options.out_dir):
    os.mkdir(options.out_dir)

with open(options.out_dir+'/model_summary.txt','w+') as fo:
    fo.write(model_summary)

store = dict( y_mean=float(y_mean), y_std=float(y_std),
              Trainable_params=trainable_count,
              Nontrainable_params=non_trainable_count,
              model_params = reg.get_params(),
              fit_kwargs = fit_kwargs,
              options = options.__dict__
              )
with open(options.out_dir+'/config.json','w+') as fo:
    fo.write( json.dumps( store, indent=4 ) )
    fo.close()

if options.x_val==True:
    kf = KFold(n_splits=int(1./options.valid_frac),shuffle=True,random_state=options.seed) 
    kf_idx = iter(kf.split(X)) 
    for kfold in range(options.nkfolds):
        # split data
        train_idx,valid_idx = next(kf_idx)
        X_train, X_valid = X[train_idx], X[valid_idx]
        y_train, y_valid = y[train_idx], y[valid_idx]
        reg.fit(X_train,y_train,kfold=kfold, 
            validation_data=(X_valid,y_valid),
            **fit_kwargs)
else :
    X_train,X_valid,y_train,y_valid = train_test_split(X,y,test_size=options.valid_frac,random_state=options.seed)
    reg.fit(X_train,y_train,kfold=-1,  ### here if you want to save hdf file after each better epoch, put -1
        validation_data=(X_valid,y_valid),
        **fit_kwargs)


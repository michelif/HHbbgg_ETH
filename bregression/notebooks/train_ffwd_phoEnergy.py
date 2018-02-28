#!/usr/bin/env python

import numpy as np

import bregnn.ffwd as ffwd 
import bregnn.io as io

import os
import json

from pprint import pprint

from sklearn.model_selection import train_test_split

from optparse import OptionParser, make_option

##
default_features = ['scRawEnergy',
                    'scEtaWidth',
                    'scPhiWidth',
                    'full5x5_e5x5',
                    'hadronicOverEm',
                    'rhoValue',
                    'delEtaSeed',
                    'delPhiSeed',
                    'full5x5_r9',
                    'full5x5_sigmaIetaIeta',
                    'full5x5_sigmaIetaIphi',
                    'full5x5_sigmaIphiIphi',
                    'full5x5_eMax',
                    'full5x5_e2nd',
                    'full5x5_eTop',
                    'full5x5_eBottom',
                    'full5x5_eLeft',
                    'full5x5_eRight',
                    'full5x5_e2x5Max',
                    'full5x5_e2x5Left',
                    'full5x5_e2x5Right',
                    'full5x5_e2x5Top',
                    'full5x5_e2x5Bottom',
                    'N_SATURATEDXTALS',
                    'N_ECALClusters'
                    ]
                    


## command_line options
parser = OptionParser(option_list=[
    make_option("--inp-dir",type='string',dest="inp_dir",default=os.environ['SCRATCH']+'/bregression'),
    make_option("--out-dir",type='string',dest="out_dir",default='.'),
    make_option("--inp-file",type='string',dest='inp_file',default='ttbar_unweighted_full80M_selected_train.hd5'),
    make_option("--features",type='string',dest='features',default=''),
    make_option("--normalize-target",action="store_true",dest="normalize_target",default=True),
    make_option("--no-normalize-target",action="store_false",dest="normalize_target"),
    make_option("--loss",type='string',dest="loss",default="mse"),
    make_option("--valid-frac",type='float',dest='valid_frac',default=0.05),
    make_option("--batch-size",type='int',dest='batch_size',default=1024),
    make_option("--epochs",type='int',dest='epochs',default=20),
    make_option("--hparams",type='string',dest='hparams',default=None),
    make_option("--seed",type='int',dest='seed',default=98543),
])

## parse options
(options, args) = parser.parse_args()

if options.features == '':
    features = default_features
    options.features = ','.join(features)
else:
    features = options.features.split(',')

if os.path.exists(options.inp_file):
    inp_file = options.inp_file
else:
    inp_file = options.inp_dir+'/'+options.inp_file

hparams = {}
if options.hparams is not None:
    with open(options.hparams) as hf:
        hparams = json.loads(hf.read())        
    
## read data
#columns = features + ['genPt']
columns = features + ['genEnergy']
#data = io.read_data(inp_file, columns = columns,data_columns=['NtupID'],where='NtupID<3000')
data = io.read_data(inp_file, columns = columns,data_columns=['NtupID'],stop=1500000)
data.describe()
#data = io.read_data(inp_file, columns = columns)
#data = io.read_data(inp_file, columns = columns,where=['data_column[NtupID][:].values.reshape(-1)<300'])

data['full5x5_e5x5']=data['full5x5_e5x5']/data['scRawEnergy']
data['full5x5_eMax']=data['full5x5_eMax']/data['full5x5_e5x5']
data['full5x5_e2nd']=data['full5x5_e2nd']/data['full5x5_e5x5']
data['full5x5_eTop']=data['full5x5_eTop']/data['full5x5_e5x5']
data['full5x5_eBottom']=data['full5x5_eBottom']/data['full5x5_e5x5']
data['full5x5_eLeft']=data['full5x5_eLeft']/data['full5x5_e5x5']
data['full5x5_eRight']=data['full5x5_eRight']/data['full5x5_e5x5']
data['full5x5_e2x5Max']=data['full5x5_e2x5Max']/data['full5x5_e5x5']
data['full5x5_e2x5Left']=data['full5x5_e2x5Left']/data['full5x5_e5x5']
data['full5x5_e2x5Right']=data['full5x5_e2x5Right']/data['full5x5_e5x5']
data['full5x5_e2x5Top']=data['full5x5_e2x5Top']/data['full5x5_e5x5']
data['full5x5_e2x5Bottom']=data['full5x5_e2x5Bottom']/data['full5x5_e5x5']


X = data[features].values
y = (data['genEnergy']/data['scRawEnergy']).values.reshape(-1,1)


y_mean = np.median(y)
y_std = y.std()
#y_std = y[np.where(y<3)].std() #if you want to apply a cut to remove crazy events
print(y_mean,y_std)

# normalize target
if options.normalize_target:
    y -= y_mean
    y /= y_std

# split data
X_train,X_valid,y_train,y_valid = train_test_split(X,y,test_size=options.valid_frac,random_state=options.seed)


# sort out model parameters
def get_kwargs(fn,**kwargs):
    params = set(fn.__code__.co_varnames[:fn.__code__.co_argcount]+tuple(kwargs.keys()))
    for par in params:
        if hasattr(options,par):
            kwargs[par] = getattr(options,par)
        if par in hparams:
            kwargs[par] = hparams.pop(par)
    return kwargs

init_kwargs = get_kwargs(ffwd.FFWDRegression.__init__,monitor_dir=options.out_dir)
fit_kwargs = get_kwargs(ffwd.FFWDRegression.fit,batch_size=options.batch_size,epochs=options.epochs)

print(init_kwargs)
print(fit_kwargs)

reg = ffwd.FFWDRegression('ffwd',X.shape[1:],**init_kwargs)

pprint(reg.get_params())

model = reg()

print(model.summary())

if not os.path.exists(options.out_dir):
    os.mkdir(options.out_dir)

store = dict( y_mean=float(y_mean), y_std=float(y_std),
              model_params = reg.get_params(),
              fit_kwargs = fit_kwargs,
              options = options.__dict__
              )
with open(options.out_dir+'/config.json','w+') as fo:
    fo.write( json.dumps( store, indent=4 ) )
    fo.close()

reg.fit(X_train,y_train,
        validation_data=(X_valid,y_valid),
        **fit_kwargs)

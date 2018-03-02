# # Characterize FFWD NN output
#load libs
import keras.models
import os
import bregnn.io as io
import matplotlib.pyplot as plt
import sys
import json
import datetime
from optparse import OptionParser, make_option
sys.path.insert(0, '/users/micheki/HHbbgg_ETH/bregression/python/')#--->edit this line
import plotting_utils as plotting


parser = OptionParser(option_list=[
    make_option("--training",type='string',dest="training",default='HybridLoss'),
    make_option("--inp-dir",type='string',dest="inp_dir",default='/users/nchernya//HHbbgg_ETH/root_files/'),
    make_option("--target-dir",type='string',dest="target_dir",default='/scratch/snx3000/nchernya/bregression/NN_output/'),
    make_option("--inp-file",type='string',dest='inp_file',default='ttbar_RegressionPerJet_heppy_energyRings3_forTesting.hd5'),
    make_option("--out-dir",type='string',dest="out_dir",default='/scratch/snx3000/nchernya/bregression/output_root/'),
])

## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')

# ## Read test data and model
# load data
data = io.read_data('%s%s'%(options.inp_dir,options.inp_file),columns=None)
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

for idx,name in enumerate(input_trainings):
    # list all model files in the training folder
#    target='/users/nchernya/HHbbgg_ETH/bregression/notebooks/'+input_trainings[idx]
  #  target=options.target_dir+input_trainings[idx]
    print
    target=options.target_dir
    models = get_ipython().getoutput('ls -t $target/*.hdf5')
    print("models")
    print(models)
  
    # read training configuration
    import json
    with open('%s/config.json' % target) as fin:
        config = json.loads(fin.read())
    config
  
    # ## Compute predictions
    features = config['options']['features'].split(',')
    print(features)
    X = data[features].values
    
    print("accessing x")
    print(X)


    model = keras.models.load_model(models[0],compile=False)
    y_pred = model.predict(X)
  
    print("prediction")
    print(y_pred)

    # *Note*: the target is typically normalized in the training y = (y-mu)/sigma
    # ## Convert raw prediction into actual scale and resolution estimation

    if y_pred.shape[1] == 1: # with one output we only have a scale correction
        corr = y_pred
        res = None
    elif y_pred.shape[1] == 2: # with two outputs first is mean and second is sigma
        corr = y_pred[:,0]
        res = y_pred[:,1]
    elif y_pred.shape[1] == 3: # assume that 3 outputs are mean + 2 quantile
        corr = y_pred[:,0]
        res = 0.5*(y_pred[:,2] - y_pred[:,1])

    # normalize back to energy scale
    if config['options']['normalize_target']:
        corr *= config['y_std']
        corr += config['y_mean']
    
        if res is not None:
            res *= config['y_std']
  
    # Add new prediction to data frame
    data = data.assign(newNNreg=y_pred[:,0])
    data = data.rename(columns={'newNNreg':'response_NN_%s'%input_trainings[idx]})
    if res is not None :
        data = data.assign(newNNreg_res=res)
        data = data.rename(columns={'newNNreg_res':'resolution_NN_%s'%input_trainings[idx]})

# save dataframe with added corrections
now = datetime.datetime.now()
now = str(now).split(' ')[0] 
outfilename=options.out_dir+'applied_res_%s_'%str(now)+options.inp_file
data.to_hdf(outfilename,'w')


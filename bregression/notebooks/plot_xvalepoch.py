# # Characterize FFWD NN output
#load libs
import os
import pandas as pd
import matplotlib.pyplot as plt
import sys
import json
from optparse import OptionParser, make_option
sys.path.insert(0, '/users/nchernya/HHbbgg_ETH/bregression/python/')
import plotting_utils as plotting


parser = OptionParser(option_list=[
    make_option("--training",type='string',dest="training",default='HybridLossRaw'),
    make_option("--inp-dir",type='string',dest="inp_dir",default='/users/nchernya/HHbbgg_ETH/bregression/notebooks/'),
    make_option("--inp-file",type='string',dest='inp_file',default='metrics'),
    make_option("--out-dir",type='string',dest="out_dir",default='/users/nchernya//HHbbgg_ETH/bregression/plots/NN_epochs/'),
    make_option("--metrics",type='string',dest="metrics",default='loss,mae0,mse0,r2_score0'),
])

colors=['r','b','g']
## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')
input_metrics = options.metrics.split(',')

nxval=5

#for each metric we plot it for train and validation sample vs epoch 
for idx_nn,nn in enumerate(input_trainings): 
    data_frames=[]
    for xval in range(0,nxval):
       # load data from metrics.csv file
        tmp_data = pd.read_csv('%s/%s/%s_kfold%i.csv'%(options.inp_dir,nn,options.inp_file,xval))
        data_frames.append(tmp_data)
    data = data_frames[0]
    for xval in range(1,nxval):
       data = data.add(data_frames[xval])
    data = data.div(nxval, axis=0)
    #plot results
    for idx,met in enumerate(input_metrics):
        plt.scatter(data['epoch'],data['%s'%met],linestyle='-',label='%s Training'%(nn.split('HybridLoss')[1]),color=colors[idx_nn])
        plt.scatter(data['epoch'],data['val_%s'%met],label='%s Validation'%(nn.split('HybridLoss')[1]),color=colors[idx_nn])
        plt.xlabel('# epochs')
        plt.ylabel('%s'%met)
        plt.legend()
        pltsavename = options.out_dir+'/xval/loss_vs_epoch_%s'%(met)
        plt.savefig(pltsavename+'.png')
        plt.savefig(pltsavename+'.pdf')
        plt.clf()
  

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
    make_option("--inp-file",type='string',dest='inp_file',default='metrics.csv'),
    make_option("--out-dir",type='string',dest="out_dir",default='/users/nchernya//HHbbgg_ETH/bregression/plots/NN_epochs/'),
    make_option("--metrics",type='string',dest="metrics",default='loss,mae0,mse0,r2_score0'),
])

colors=['r','b']
## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')
input_metrics = options.metrics.split(',')

# load data from metrics.csv file
data = pd.read_csv('%s/%s/%s'%(options.inp_dir,options.training,options.inp_file))

#for each metric we plot it for train and validation sample vs epoch 
for idx,met in enumerate(input_metrics):
    plt.scatter(data['epoch'],data['%s'%met],marker='s',label='Training',color=colors[0])
    plt.scatter(data['epoch'],data['val_%s'%met],marker='o',label='Validation',color=colors[1])
    plt.xlabel('# epochs')
    plt.ylabel('%s'%met)
    plt.legend()
    pltsavename = options.out_dir+'/%s/loss_vs_epoch_%s_%s'%(input_trainings[0],input_trainings[0],met)
    plt.savefig(pltsavename+'.png')
    plt.savefig(pltsavename+'.pdf')
    plt.clf()


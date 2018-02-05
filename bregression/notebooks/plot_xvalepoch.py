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
import matplotlib.offsetbox as offsetbox 



parser = OptionParser(option_list=[
    make_option("--training",type='string',dest="training",default='HybridLossRaw'),
    make_option("--inp-dir",type='string',dest="inp_dir",default=os.environ['SCRATCH']+'/bregression/NN_output/'),
    make_option("--inp-file",type='string',dest='inp_file',default='metrics'),
    make_option("--out-dir",type='string',dest="out_dir",default='/users/nchernya//HHbbgg_ETH/bregression/plots/NN_epochs/'),
    make_option("--metrics",type='string',dest="metrics",default='loss,mae0,mse0'),
])

colors=['r','b','g','k','c','y']
## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')
input_metrics = options.metrics.split(',')


#for each metric we plot it for train and validation sample vs epoch 
datas=[]
param_dicts=[]
for idx_nn,nn in enumerate(input_trainings): 
    data = pd.read_csv('%s/%s/%s_kfold1.csv'%(options.inp_dir,nn,options.inp_file))
    j = json.load(open('%s/%s/config.json'%(options.inp_dir,nn)))
    datas.append(data)
    param_dicts.append(dict(lr=j['model_params']['optimizer_params']['lr'],dropout=j['model_params']['dropout'],architecture=j['model_params']['layers'],loss=j['model_params']['loss']))
    #plot results
for idx,met in enumerate(input_metrics):
    for idx_nn,nn in enumerate(input_trainings): 
        data = datas[idx_nn]
        plt.scatter(data['epoch'],data['%s'%met],linestyle='-',label='Training, lr = %.1e'%(param_dicts[idx_nn]['lr']),color=colors[idx_nn])
    axes = plt.gca()
    axes.set_xlim(-1,50)
    ymin,ymax = axes.get_ylim()
    xmin,xmax=axes.get_xlim()
    current_dict = param_dicts[0]
#    plt.text(xmin+abs(xmin)*0.1,ymax*0.95,'%s'%(str(current_dict['architecture'])), fontsize=20)
 #   plt.text(xmin+abs(xmin)*0.1,ymax*0.93,'%s'%(current_dict['loss']), fontsize=20)
#    plt.text(xmin+abs(xmin)*0.1,ymax*0.91,'dropout %s'%(current_dict['dropout']), fontsize=20)
    text0 = str(current_dict['architecture'])
    text1 = str(current_dict['loss'])
    text2= 'dropout %s'%(current_dict['dropout'])
    textbox = text0+'\n'+text1+'\n'+text2
    plt.xlabel('# epochs')
    plt.ylabel('%s'%met)
    leg = plt.legend()
    txt=offsetbox.TextArea("%s"%textbox,textprops=dict(size=20)) 
    box = leg._legend_box 
    box.get_children().append(txt) 
    box.set_figure(box.figure)
    pltsavename = options.out_dir+'/learning_rate_loss_vs_epoch_%s'%(met)
    plt.savefig(pltsavename+'.png')
    plt.savefig(pltsavename+'.pdf')
    plt.clf()
  

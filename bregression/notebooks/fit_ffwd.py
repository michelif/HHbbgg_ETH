import keras.models
import os
import bregnn.io as io
import matplotlib.pyplot as plt
import sys
import json
from optparse import OptionParser, make_option
sys.path.insert(0, '/users/nchernya/HHbbgg_ETH/bregression/python/')
import plotting_utils as plotting

parser = OptionParser(option_list=[
    make_option("--training",type='string',dest="training",default='mse'),
    make_option("--inp-file",type='string',dest='inp_file',default='applied_ttbar_RegressionPerJet_heppy_energyRings3_forTesting.hd5'),
    make_option("--inp-dir",type='string',dest="inp_dir",default='/users/nchernya//HHbbgg_ETH/bregression/output_root/'),
])

## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')

# ## Read test data and model
# load data
base_dir = '/scratch/snx3000/musella/bregression'
data = io.read_data('%s%s'%(options.inp_dir,options.inp_file),columns=None)
data.describe()

#Regions of pt and eta 
file_regions = open('/users/nchernya/HHbbgg_ETH/bregression/scripts/regionsPtEta.json')
regions_summary = json.loads(file_regions.read())
region_names = regions_summary['pt_regions']+regions_summary['eta_region_names']

# Add all results in array to plot and fit to Bukin
regions = regions_summary["pt_regions"]+regions_summary["eta_regions"]
for i_r,region in enumerate(regions):
    X_predictions_compare = []
    data_cut = data.query(region)
    y = (data_cut['Jet_mcPt']/data_cut['Jet_pt']).values.reshape(-1,1)
    y_hbb = (data_cut['Jet_mcPt']/data_cut['Jet_pt_reg']).values.reshape(-1,1)
    X_predictions_compare.append(y[:,0]) 	
    X_predictions_compare.append(y_hbb[:,0]) 	
    for idx,name in enumerate(input_trainings):
        y_pred_cut = (data_cut['Jet_pt_reg_NN_%s'%input_trainings[idx]])
        X_predictions_compare.append(y[:,0]/y_pred_cut)
  

    comparison_tags = ['No regression'] + ['HIG-17-009'] + input_trainings
    style=False 
    if i_r==0 : style=True
    samplename='ttbar'
    outTag = 'Comparison17_01_2018_forTesting' + region_names[i_r]
    plotting.plot_regions(X_predictions_compare,comparison_tags,style,50,outTag,False,region_names[i_r],samplename)

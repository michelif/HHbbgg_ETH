import keras.models
import os
import bregnn.io as io
import bregnn.utils as utils
import sys
import json
from optparse import OptionParser, make_option
sys.path.insert(0, '/users/nchernya/HHbbgg_ETH/bregression/python/')
import plotting_utils as plotting

parser = OptionParser(option_list=[
    make_option("--training",type='string',dest="training",default='HybridLoss'),
    make_option("--inp-file",type='string',dest='inp_file',default='applied_res_ttbar_RegressionPerJet_heppy_energyRings3_forTesting.hd5'),
    make_option("--inp-dir",type='string',dest="inp_dir",default='/users/nchernya//HHbbgg_ETH/bregression/output_root/'),
    make_option("--sample-name",type='string',dest="samplename",default='ttbar'),
])

## parse options
(options, args) = parser.parse_args()
input_trainings = options.training.split(',')

# ## Read test data and model
# load data
data = io.read_data('%s%s'%(options.inp_dir,options.inp_file),columns=None)
data.describe()

#Regions of pt and eta 
file_regions = open('/users/nchernya/HHbbgg_ETH/bregression/scripts/regionsPtEta.json')
regions_summary = json.loads(file_regions.read())
region_names = regions_summary['pt_regions']+regions_summary['eta_region_names']

y = (data['Jet_mcPt']/data['Jet_pt']).values.reshape(-1,1)
X_pt = (data['Jet_pt']).values.reshape(-1,1)
res = (data['Jet_resolution_NN_%s'%input_trainings[0]])
y_pred = (data['Jet_pt_reg_NN_%s'%input_trainings[0]]) #bad name because it is actually a correction
y_corr = (y[:,0]/y_pred).values.reshape(-1,1)
# errors vector
err = y[:,0]-y_pred

bins, y_mean_pt, y_std_pt, y_qt_pt = utils.profile(y,X_pt,range=[30,400],bins=50,uniform=False)
y_median_pt = y_qt_pt[1]
y_iqr2_pt =  y_qt_pt[0],y_qt_pt[2]

_, y_corr_mean_pt, y_corr_std_pt, y_corr_qt_pt = utils.profile(y_corr,X_pt,bins=bins) 
y_corr_median_pt = y_corr_qt_pt[1]
y_corr_iqr2_pt =  y_corr_qt_pt[0],y_corr_qt_pt[2]


binc = 0.5*(bins[1:]+bins[:-1])

plt.plot(binc,y_mean_pt,label='raw (mean)')
plt.fill_between(binc,y_mean_pt-y_std_pt,y_mean_pt+y_std_pt,alpha=0.4,label='raw (RMS)')

plt.plot(binc,y_corr_mean_pt,label='corrected (mean)')
plt.fill_between(binc,y_corr_mean_pt-y_corr_std_pt,y_corr_mean_pt+y_corr_std_pt,alpha=0.4,label='corrected (RMS)')

plt.xlabel('$p_T$')
plt.ylabel('$p_T^{true} / p_T^{reco}$')
plt.legend()
plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/HybridLoss/mean_.pdf')
plt.clf()



plt.plot(binc,y_median_pt,label='raw (median)')
plt.fill_between(binc,*y_iqr2_pt,alpha=0.4,label='raw (IQR)')

plt.plot(binc,y_corr_median_pt,label='corrected (median)')
plt.fill_between(binc,*y_corr_iqr2_pt,alpha=0.4,label='corrected (IQR)')

plt.xlabel('$p_T$')
plt.ylabel('$p_T^{true} / p_T^{reco}$')
plt.legend()
plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/HybridLoss/median_.pdf')
plt.clf()

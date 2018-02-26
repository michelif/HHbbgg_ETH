import keras.models
import os
import bregnn.io as io
import bregnn.utils as utils
import sys
import json
from optparse import OptionParser, make_option
sys.path.insert(0, '/users/nchernya/HHbbgg_ETH/bregression/python/')
import plotting_utils as plotting
from keras.utils import to_categorical

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
X_eta = (data['Jet_eta']).values.reshape(-1,1)
res = (data['Jet_resolution_NN_%s'%input_trainings[0]])
y_pred = (data['Jet_pt_reg_NN_%s'%input_trainings[0]]) #bad name because it is actually a correction
y_corr = (y[:,0]/y_pred).values.reshape(-1,1)

whats = ['p_T','\eta']
ranges = [[30,400],[-2.5,2.5]]
binning =[50,20]





eta_bins=binning[1]
eta_min, eta_max = X_eta.min(),X_eta.max()
eta_bins = np.percentile( X_eta, np.linspace(0,100.,num=eta_bins+1) )
eta_bins[0] = eta_min
eta_bins[-1] = eta_max
eta_ibins = np.digitize(X_eta,eta_bins)-1
eta_categories = to_categorical( eta_ibins )
iqr2_2d = []
iqr2_corr_2d = []
print(eta_categories.shape)
bins=binning[0]
if ('ggHHbbgg' in options.samplename) : bins=int(binning[0]/2.)
for eta_ibin in np.arange(eta_categories.shape[1]-1,dtype=int):
 y_ineta = y[eta_categories[:,eta_ibin].astype(np.bool)]
 y_corr_ineta = y_corr[eta_categories[:,eta_ibin].astype(np.bool)]
 X_pt_ineta = X_pt[eta_categories[:,eta_ibin].astype(np.bool)]


 bins_split,  y_qt_pt = utils.profile(y_ineta,X_pt_ineta,range=ranges[0],bins=bins,uniform=False,moments=False)
 if eta_ibin==0 : bins=bins_split
 err_iqr2 =  0.5*(y_qt_pt[2]-y_qt_pt[0])
 iqr2_2d.append(err_iqr2)
 _,  y_corr_qt_pt = utils.profile(y_corr_ineta,X_pt_ineta,bins=bins,moments=False) 
 err_corr_iqr2 =  0.5*(y_corr_qt_pt[2]-y_corr_qt_pt[0])
 iqr2_corr_2d.append(err_corr_iqr2)

weights=np.array(np.vstack(iqr2_2d[i] for i in range(binning[1])),dtype='float64')
weights_corr=np.array(np.vstack(iqr2_corr_2d[i] for i in range(binning[1])),dtype='float64')

bins_pt_2d = 0.5*(bins[1:]+bins[:-1])
bins_eta_2d = 0.5*(eta_bins[1:]+eta_bins[:-1])

X2d_bins,Y2d_bins=np.meshgrid(bins_eta_2d,bins_pt_2d)
im = plt.pcolormesh(X2d_bins,Y2d_bins,weights.transpose(), cmap='viridis')
plt.xlabel('$\eta$')
plt.ylabel('$p_T$')
ymin, ymax = (plt.gca()).get_ylim()
ymax=300
axes = plt.gca()
axes.set_ylim(ranges[0][0],ymax)
plt.text(-2,ymax*1.1,'IQR/2 Raw', fontsize=15)
plt.text(-2,ymax*1.04,'%s'%options.samplename, fontsize=15)
plt.colorbar(im, orientation='vertical')
savename= '/users/nchernya//HHbbgg_ETH/bregression/plots/HybridLoss/2d_%s'%options.samplename
plt.savefig(savename+'.png')
plt.savefig(savename+'.pdf')
plt.clf()

im = plt.pcolormesh(X2d_bins,Y2d_bins,weights_corr.transpose(), cmap='viridis')
plt.colorbar(im, orientation='vertical')
ymin, ymax = (plt.gca()).get_ylim()
plt.xlabel('$\eta$')
plt.ylabel('$p_T$')
ymax=300
axes = plt.gca()
axes.set_ylim(ranges[0][0],ymax)
plt.text(-2,ymax*1.1,'IQR/2 NN corrected', fontsize=15)
plt.text(-2,ymax*1.05,'%s'%options.samplename, fontsize=15)
savename= '/users/nchernya//HHbbgg_ETH/bregression/plots/HybridLoss/2d_corr_%s'%options.samplename
plt.savefig(savename+'.png')
plt.savefig(savename+'.pdf')
plt.clf()

hist = plt.hist2d(X_eta.ravel(),X_pt.ravel(),bins = [bins_eta_2d,bins_pt_2d],normed=True,cmap='viridis')
plt.colorbar(hist[3], orientation='vertical')
plt.xlabel('$\eta$')
plt.ylabel('$p_T$')
ymax=300
axes = plt.gca()
axes.set_ylim(ranges[0][0],ymax)
plt.text(-2,ymax*1.1,'$\eta$ - $p_T$ correlation', fontsize=15)
plt.text(-2,ymax*1.05,'%s'%options.samplename, fontsize=15)
savename= '/users/nchernya//HHbbgg_ETH/bregression/plots/HybridLoss/correlation2D_%s'%options.samplename
plt.savefig(savename+'.png')
plt.savefig(savename+'.pdf')

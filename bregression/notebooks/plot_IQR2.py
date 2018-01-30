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
X_eta = (data['Jet_eta']).values.reshape(-1,1)
X_rho = (data['rho']).values.reshape(-1,1)
res = (data['Jet_resolution_NN_%s'%input_trainings[0]])
y_pred = (data['Jet_pt_reg_NN_%s'%input_trainings[0]]) #bad name because it is actually a correction
y_hbb = (data['Jet_mcPt']/data['Jet_pt_reg']).values.reshape(-1,1)
y_corr = (y[:,0]/y_pred).values.reshape(-1,1)
# errors vector
err = y[:,0]-y_pred

linestyles = ['-.', '--','-', ':']

whats = ['p_T','\eta','rho']
ranges = [[30,400],[-2.5,2.5],[0,50]]
binning =[50,10,20] #[50,20]
for i in range(0,3):
 if i==0 : X = X_pt
 elif i==1 : X = X_eta
 elif i==2 : X = X_rho
 print(i,X)
 
 bins=binning[i]
 if ('ggHHbbgg' in options.samplename) and ('p_T' in whats[i]) : bins=int(binning[i]/2.)
 if ('ZHbbll' in options.samplename) and ('eta' in whats[i]) : ranges[i]=[-2.45,2.45]
 bins, y_mean_pt, y_std_pt, y_qt_pt = utils.profile(y,X,range=ranges[i],bins=bins,uniform=False,quantiles=np.array([0.25,0.4,0.5,0.75]))
 y_median_pt = y_qt_pt[2]
 y_25_pt,y_40_pt,y_75_pt = y_qt_pt[0],y_qt_pt[1],y_qt_pt[3]
 y_iqr2_pt =  y_qt_pt[0],y_qt_pt[3]
 err_iqr2 =  0.5*(y_qt_pt[3]-y_qt_pt[0])
 
 _, y_corr_mean_pt, y_corr_std_pt, y_corr_qt_pt = utils.profile(y_corr,X,bins=bins,quantiles=np.array([0.25,0.4,0.5,0.75])) 
 y_corr_median_pt = y_corr_qt_pt[2]
 y_corr_25_pt,y_corr_40_pt,y_corr_75_pt = y_corr_qt_pt[0],y_corr_qt_pt[1],y_corr_qt_pt[3]
 y_corr_iqr2_pt =  y_corr_qt_pt[0],y_corr_qt_pt[3]
 err_corr_iqr2 =  0.5*(y_corr_qt_pt[3]-y_corr_qt_pt[0])


 _, y_hbb_mean_pt, y_hbb_std_pt, y_hbb_qt_pt = utils.profile(y_hbb,X,bins=bins,quantiles=np.array([0.25,0.4,0.5,0.75])) 
 y_hbb_iqr2_pt =  y_hbb_qt_pt[0],y_hbb_qt_pt[3]
 err_hbb_iqr2 =  0.5*(y_hbb_qt_pt[3]-y_hbb_qt_pt[0])
 
 binc = 0.5*(bins[1:]+bins[:-1])
 
 ##Plot raw and corrected mean with their stds on one plot
 plt.plot(binc,y_mean_pt,label='raw (mean)')
 plt.fill_between(binc,y_mean_pt-y_std_pt,y_mean_pt+y_std_pt,alpha=0.4,label='raw (RMS)')
 plt.plot(binc,y_corr_mean_pt,label='corrected (mean)')
 plt.fill_between(binc,y_corr_mean_pt-y_corr_std_pt,y_corr_mean_pt+y_corr_std_pt,alpha=0.4,label='corrected (RMS)')
 plt.plot(binc,y_median_pt,label='raw (median)')
 plt.fill_between(binc,*y_iqr2_pt,alpha=0.4,label='raw (IQR)')
 plt.plot(binc,y_corr_median_pt,label='corrected (median)')
 plt.fill_between(binc,*y_corr_iqr2_pt,alpha=0.4,label='corrected (IQR)')
 
# plt.xlabel('$p_T$')
 plt.xlabel('$%s$'%whats[i])
 plt.ylabel('$p_T^{true} / p_T^{reco}$')
 plt.legend()
# plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/mean_median_%s_%s.pdf'%(input_trainings[0],options.samplename,whats[i].replace('\\',''),options.samplename))
# plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/mean_median_%s_%s.png'%(input_trainings[0],options.samplename,whats[i].replace('\\',''),options.samplename))
 plt.clf()
 
 
 ## Draw several quantiles on one plot
# plt.plot(binc,y_25_pt,label='raw (0.25)',linestyle=linestyles[0],color='b')
# plt.plot(binc,y_corr_25_pt,label='corrected (0.25)',linestyle=linestyles[2],color='b')
# plt.plot(binc,y_40_pt,label='raw (0.40)',linestyle=linestyles[0],color='g')
# plt.plot(binc,y_corr_40_pt,label='corrected (0.40)',linestyle=linestyles[2],color='g')
# plt.plot(binc,y_median_pt,label='raw (0.50)',linestyle=linestyles[0],color='r')
# plt.plot(binc,y_corr_median_pt,label='corrected (0.50)',linestyle=linestyles[2],color='r')
# plt.plot(binc,y_75_pt,label='raw (0.75)',linestyle=linestyles[0],color='c')
# plt.plot(binc,y_corr_75_pt,label='corrected (0.75)',linestyle=linestyles[2],color='c')

 plt.plot(binc,y_25_pt,label='raw',linestyle=linestyles[0],color='b')
 plt.plot(binc,y_corr_25_pt,label='corrected',linestyle=linestyles[2],color='r')
 plt.plot(binc,y_40_pt,linestyle=linestyles[0],color='b')
 plt.plot(binc,y_corr_40_pt,linestyle=linestyles[2],color='r')
 plt.plot(binc,y_median_pt,linestyle=linestyles[0],color='b')
 plt.plot(binc,y_corr_median_pt,linestyle=linestyles[2],color='r')
 plt.plot(binc,y_75_pt,linestyle=linestyles[0],color='b')
 plt.plot(binc,y_corr_75_pt,linestyle=linestyles[2],color='r')
 ymin, ymax = (plt.gca()).get_ylim()
 xmin, xmax = (plt.gca()).get_xlim()
 plt.text(xmin+abs(xmin)*0.05,ymax*0.98,'Quantiles : 0.25,0.40,0.50,0.75', fontsize=15)
 plt.text(xmin+abs(xmin)*0.05,ymax*0.96,'%s'%options.samplename, fontsize=15)
 
 plt.xlabel('$%s$'%whats[i])
 plt.ylabel('$p_T^{true} / p_T^{reco}$')
 plt.legend(loc='upper right')
 plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/quantiles_col_%s_%s_%s.pdf'%(input_trainings[0],options.samplename,input_trainings[0],whats[i].replace('\\',''),options.samplename))
 plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/quantiles_col_%s_%s_%s.png'%(input_trainings[0],options.samplename,input_trainings[0],whats[i].replace('\\',''),options.samplename))
 plt.clf()
 
  ## Draw profile of sigma (0.72-0.25)/2 vs eta and pt
 plt.scatter(binc,err_iqr2,color='red',marker='^',label='No Regression')
 plt.scatter(binc,err_hbb_iqr2,color='blue',marker='s',label='HIG-17-009')
 plt.scatter(binc,err_corr_iqr2,color='green',marker='o',label='NN %s'%input_trainings[0])
 plt.grid(alpha=0.2,linestyle='--',markevery=2)
 axes = plt.gca()
 if (i==0) : axes.set_ylim(0.02,0.20)
 if (i==1) : axes.set_ylim(0.02,0.15)
 axes.set_xlim(ranges[i][0],ranges[i][1])
 if (i==0) : axes.set_xlim(0,ranges[i][1])
 ymin, ymax = (plt.gca()).get_ylim()
 plt.text(xmin+abs(xmin)*0.05,ymax*0.95,'%s'%options.samplename, fontsize=20)
 lgd = plt.legend(loc="lower center",numpoints=1,ncol=2,bbox_to_anchor=(0.0,-0.202,1.,-.202),borderaxespad=0.,mode='expand')
 plt.xlabel('$%s$'%whats[i])
 plt.ylabel('IQR / 2')
 plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/IQR_20bins_%s_%s_%s.pdf'%(input_trainings[0],options.samplename,input_trainings[0],whats[i].replace('\\',''),options.samplename),bbox_extra_artists=(lgd,), bbox_inches='tight')
 plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/IQR_20bins_%s_%s_%s.png'%(input_trainings[0],options.samplename,input_trainings[0],whats[i].replace('\\',''),options.samplename),bbox_extra_artists=(lgd,), bbox_inches='tight')
 plt.clf()



##Draw IQR/2 vs resolution estimator
res_bins, err_qt_res = utils.profile(err,res,bins=30,range=[0,0.3],moments=False) 
print(err_qt_res.shape)
err_iqr2 =  0.5*(err_qt_res[2]-err_qt_res[0])

plt.scatter(0.5*(res_bins[1:]+res_bins[:-1]),err_iqr2)
plt.grid(alpha=0.5,linestyle='--',markevery=2)
axes = plt.gca()
ymin, ymax = axes.get_ylim()
plt.text(0.0,ymax*0.95,'%s'%options.samplename, fontsize=20)
plt.xlabel('$\sigma(p_T)/p_T$')
plt.ylabel('IQR / 2')
plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/IQR_sigma_pt_%s_%s.pdf'%(input_trainings[0],options.samplename,input_trainings[0],options.samplename))
plt.savefig('/users/nchernya//HHbbgg_ETH/bregression/plots/%s/%s/IQR_sigma_pt_%s_%s.png'%(input_trainings[0],options.samplename,input_trainings[0],options.samplename))

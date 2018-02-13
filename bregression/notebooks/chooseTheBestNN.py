
import os
#import sys; sys.path.append("~/HHbbgg_ETH_devel/bregression/python") # to load packages
import sys
sys.path.insert(0, '/users/nchernya/HHbbgg_ETH/bregression/python/')
import training_utils as utils
import numpy as np
import preprocessing_utils as preprocessing
import plotting_utils as plotting
import optimization_utils as optimization
import postprocessing_utils as postprocessing
import math
import datetime

testfile = sys.argv[1]
testfile2 = sys.argv[2]

path = '/users/nchernya//HHbbgg_ETH/bregression/fitResults/'
pt_regions_names = '(Jet_mcPt>0),(Jet_mcPt<60),(Jet_mcPt>=60 & Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<150),(Jet_mcPt>=150 & Jet_mcPt<200),(Jet_mcPt>=200 & Jet_mcPt<250),(Jet_mcPt>=250 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<400),(Jet_mcPt>=400 & Jet_mcPt<600),(Jet_mcPt>=600)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
labels_old=['HIG-16-044 JECR','no Regression JECR']
#labels_old=['BDT scikit']
#saveTag_old='FinalHighPt_eta'
saveTag_old='CatnoregMSEquant'
labels=['No Regression','NN id 23']
saveTag='Comparison_NN2_2018-02-06_'
which = saveTag+testfile
which_old = saveTag_old+testfile2
sample = testfile

num_pt=len(pt_regions_names)
num_eta=len(eta_regions_names)
pt_region=[-500,0,60,100,150,200,250,300,400,600,1200]
eta_region=[0.,0.5,1.,1.5,2,2.5]
pt_region = [ pt_region[i]+(pt_region[i+1]-pt_region[i])/2. for i in range(0,len(pt_region)-1)]
eta_region = [ eta_region[i]+(eta_region[i+1]-eta_region[i])/2. for i in range(0,len(eta_region)-1)]

mean_all_pt=[]
fwhm_all_eta=[]
mean_all_eta=[]
fwhm_all_pt=[]
smu_all_eta=[]
smu_all_pt=[]


for i_r,region in enumerate(pt_regions_names+eta_regions_names):
	file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
	mean,fwhm,emean,efwhm = postprocessing.get_mean_width(file_name)
	if labels_old!=None:
	#	file_name_old = path+'FinalHighPt_EtaBins_scikit/fitResultRegions_Bukin'+which_old+region+'.txt'
		file_name_old = path+'JECR/fitResultRegions_Bukin'+which_old+region+'.txt'
		mean_old,fwhm_old,emean_old,efwhm_old = postprocessing.get_mean_width(file_name_old)
		mean_old = mean_old[:2]
		emean_old = emean_old[:2]
		fwhm_old = fwhm_old[:2]
		efwhm_old = efwhm_old[:2]
		mean = mean+mean_old 	
		fwhm = fwhm+fwhm_old	
	if i_r<num_pt : 
		mean_all_pt.append(mean)
		fwhm_all_pt.append(fwhm)
		smu_all_pt.append([fwhm[l]/mean[l] for l in range(len(mean))])
	else:
		mean_all_eta.append(mean)
		fwhm_all_eta.append(fwhm)
		smu_all_eta.append([fwhm[l]/mean[l] for l in range(len(mean))])

print('pt = ',mean_all_pt)
print('eta = ',mean_all_eta)



#direc='money_plots_NN_18_01_2018/comparison_scikit/%s/'%testfile
now = str(datetime.datetime.now()).split(' ')[0]
direc='money_plots_NN_%s_JECR/'%(now)
direc=utils.IO.plotFolder+direc
if not os.path.exists(direc):
	os.mkdir(direc)
direc+='/'+testfile+'/'
if not os.path.exists(direc):
	os.mkdir(direc)

pt_eta=['pt','eta']
sigmamu=['sigmamu','sigma']
for region in pt_eta:
 sigmas=[]
 columns=[]
 if region=='pt':
   sigmas.append(smu_all_pt)
   sigmas.append(fwhm_all_pt)
   columns = pt_regions_names
 if region=='eta':
   sigmas.append(smu_all_eta)
   sigmas.append(fwhm_all_eta)
   columns = eta_regions_names
 for x in range(2):
     what=sigmas[x]
     d=[]
     d.append([round(2*(what[i][0]-what[i][1])/(what[i][1]+what[i][0]),3) for i in range(len(what))])
     data = pd.DataFrame(d, columns=(columns))
     data.to_csv('%s/data_%s_%s.json'%(direc,sigmamu[x],region))

outString='optimizedNN_oldJECR'+saveTag

direc=direc.split('/bregression/plots/')[1]
print(direc)

if labels_old!=None: labels=labels+labels_old
print(labels)
what=['mean Xp','$p_T$']
plotting.plot_mean_fwhm(mean_all_pt,pt_region,what,outString,labels,sample,direc)
what=['mean Xp','$\eta$']
plotting.plot_mean_fwhm(mean_all_eta,eta_region,what,outString,labels,sample,direc)

#what=['FWHM','p_T']
what=['sigma','$p_T$']
plotting.plot_mean_fwhm(fwhm_all_pt,pt_region,what,outString,labels,sample,direc)
what=['sigma','$\eta$']
plotting.plot_mean_fwhm(fwhm_all_eta,eta_region,what,outString,labels,sample,direc)


what=['$\sigma$/Xp','$p_T$']
plotting.plot_mean_fwhm(smu_all_pt,pt_region,what,outString,labels,sample,direc)
what=['$\sigma$/Xp','$\eta$']
plotting.plot_mean_fwhm(smu_all_eta,eta_region,what,outString,labels,sample,direc)

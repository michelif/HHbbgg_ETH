
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

testfile = sys.argv[1]
testfile2 = sys.argv[2]

path = '/users/nchernya//HHbbgg_ETH/bregression/fitResults/'
pt_regions_names = '(Jet_mcPt>0),(Jet_mcPt<60),(Jet_mcPt>=60 & Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<150),(Jet_mcPt>=150 & Jet_mcPt<200),(Jet_mcPt>=200 & Jet_mcPt<250),(Jet_mcPt>=250 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<400),(Jet_mcPt>=400 & Jet_mcPt<600),(Jet_mcPt>=600)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
#labels_old=['x HIG-16-044','x no Regression','x MSE','x high pT']
labels_old=['BDT scikit']
saveTag_old='FinalHighPt_eta'
labels=['No Regression','HIG-17-009','NN HybridLoss']
saveTag='Comparison18_01_2018_'
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


for i_r,region in enumerate(pt_regions_names+eta_regions_names):
	file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
	mean,fwhm,emean,efwhm = postprocessing.get_mean_width(file_name)
	file_name_old = path+'FinalHighPt_EtaBins_scikit/fitResultRegions_Bukin'+which_old+region+'.txt'
	mean_old,fwhm_old,emean_old,efwhm_old = postprocessing.get_mean_width(file_name_old)
	mean = mean+mean_old 	
	fwhm = fwhm+fwhm_old	
	if i_r<num_pt : 
		mean_all_pt.append(mean)
		fwhm_all_pt.append(fwhm)
	else:
		mean_all_eta.append(mean)
		fwhm_all_eta.append(fwhm)

print('pt = ',mean_all_pt)
print('eta = ',mean_all_eta)

#direc='money_plots_NN_18_01_2018/%s/'%testfile
direc='money_plots_NN_18_01_2018/comparison_scikit/%s/'%testfile
outString='NN_scikit_'+saveTag

labels=labels+labels_old
print(labels)
what=['mean Xp','p_T']
plotting.plot_mean_fwhm(mean_all_pt,pt_region,what,outString,labels,sample,direc)
what=['mean Xp','eta']
plotting.plot_mean_fwhm(mean_all_eta,eta_region,what,outString,labels,sample,direc)

#what=['FWHM','p_T']
what=['sigma','p_T']
plotting.plot_mean_fwhm(fwhm_all_pt,pt_region,what,outString,labels,sample,direc)
what=['sigma','eta']
plotting.plot_mean_fwhm(fwhm_all_eta,eta_region,what,outString,labels,sample,direc)


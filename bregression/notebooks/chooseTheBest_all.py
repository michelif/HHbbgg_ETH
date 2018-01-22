
import os
import sys; sys.path.append("~/HHbbgg_ETH_devel/bregression/python") # to load packages
import training_utils as utils
import numpy as np
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import plotting_utils as plotting
reload(plotting)
import optimization_utils as optimization
reload(optimization)
import postprocessing_utils as postprocessing
reload(postprocessing)
import math


path = '/mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/bregression/fitResults/'
pt_regions_names = '(Jet_mcPt>0),(Jet_mcPt<60),(Jet_mcPt>=60 & Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<150),(Jet_mcPt>=150 & Jet_mcPt<200),(Jet_mcPt>=200 & Jet_mcPt<250),(Jet_mcPt>=250 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<400),(Jet_mcPt>=400 & Jet_mcPt<600),(Jet_mcPt>=600)'.split(",")
pt_regions_names2 = '(Jet_mcPt>0)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
labels2=['ttbar','ZHbbll','sm','res500','res700']
labels3=[]
labels=['HIG-16-044','no Regression','MSE','quantile 0.4']
num_pt=len(pt_regions_names)
num_eta=len(eta_regions_names)
#pt_region=[-500,0,100,300,400,600,1200]
pt_region=[-500,0,60,100,150,200,250,300,400,600,1200]
#pt_region2=[0,1]
pt_region2=[0,1,2,3,4,5]
eta_region=[0.,0.5,1.,1.5,2,2.5]
pt_region = [ pt_region[i]+(pt_region[i+1]-pt_region[i])/2. for i in range(0,len(pt_region)-1)]
pt_region2 = [ pt_region2[i]+(pt_region2[i+1]-pt_region2[i])/2. for i in range(0,len(pt_region2)-1)]
eta_region = [ eta_region[i]+(eta_region[i+1]-eta_region[i])/2. for i in range(0,len(eta_region)-1)]

mean_all_pt2=[]
fwhm_all_pt2=[]


#for i_r,region in enumerate(pt_regions_names2):
for i_r,region in enumerate(pt_regions_names):
	mean_all_pt=[]
	fwhm_all_eta=[]
	mean_all_eta=[]
	fwhm_all_pt=[]
	for i in range(len(labels2)):
		testfile= labels2[i]
	#	saveTag='CatnoregMSEquant'
		saveTag='CatnoregMSEonly'
		if testfile=='ZHbbll' : 
			which = saveTag+testfile
			sample = testfile
		elif testfile!='ttbar' : 
			which = saveTag+'DiHiggs'+testfile
			sample = 'DiHiggs '+testfile
		else : 
			which = saveTag+'ttbar'
			sample = 'ttbar'
		if (i_r==0) : labels3.append(sample)
		print which, testfile
		file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
		mean0,fwhm0,emean0,efwhm0 = postprocessing.get_mean_width(file_name)
####		mean,fwhm,emean,efwhm = postprocessing.get_mean_width(file_name) # for inclusive
		mean_all_pt.append(mean0)
		fwhm_all_pt.append(fwhm0)
	mean_all_pt2.append(mean_all_pt)  
	fwhm_all_pt2.append(fwhm_all_pt)  
#	mean_all_pt.append(mean_all_pt)  # for inclusive
#	fwhm_all_pt.append(fwhm_all_pt)   # for inclusive

#fwhm_all_pt = [ [fwhm_all_pt[0][i]] for i in range(4)] 
#print fwhm_all_pt

outString='ComparisonSpectrum'


what=['sigma','p_T']
#plotting.plot_mean_fwhm(fwhm_all_pt,pt_region2,what,outString,labels,'all',[0.1,0.15])
plotting.plot_mean_fwhm(fwhm_all_pt2,pt_region,what,outString,labels3,'MSE',[0.06,0.14])


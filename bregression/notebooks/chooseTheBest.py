
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

testfile = sys.argv[1]

path = '/mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/bregression/fitResults/'
#pt_regions_names = '(Jet_mcPt>0),(Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<700),(Jet_mcPt>700)'.split(",")
pt_regions_names = '(Jet_mcPt>0),(Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<400),(Jet_mcPt>=400 & Jet_mcPt<600),(Jet_mcPt>=600)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
#labels=['Caterina','XGb w weights','XGb wo weights', 'only Cat variables', 'only Cat var, target pt','only Cat var, target pt, old par','quantile 0-4,20-70']
#labels=['Caterina','XGb wo weights', 'only Cat variables','quantile min-max']
#labels=['Caterina','XGb wo weights', 'quantile min-max 02-07','quantile min-max 02-04','quantile linear all']
#labels=['Caterina','XGb wo weights', 'quantile min-max 02-07','quantile min-max 02-04','quantile linear all','quantile_04']
labels=['HIG-16-044','no Regression','XGb wo weights', 'quantile min-max 02-07','quantile_04']
#which = 'QuantileMinMaxLinear04'
if testfile=='ZHbbll' : 
	which = 'Sumsample09_'+testfile
	sample = testfile
elif testfile!='ttbar' : 
	which = 'Sumsample09_DiHiggs'+testfile
	sample = 'DiHiggs '+testfile
else : 
	which = 'Sumsample09_ttbar'
	sample = 'ttbar'
num_pt=len(pt_regions_names)
num_eta=len(eta_regions_names)
pt_region=[-500,0,100,300,400,600,1200]
eta_region=[0.,0.5,1.,1.5,2,2.5]
pt_region = [ pt_region[i]+(pt_region[i+1]-pt_region[i])/2. for i in range(0,len(pt_region)-1)]
eta_region = [ eta_region[i]+(eta_region[i+1]-eta_region[i])/2. for i in range(0,len(eta_region)-1)]

mean_all_pt=[]
fwhm_all_eta=[]
mean_all_eta=[]
fwhm_all_pt=[]


for i_r,region in enumerate(pt_regions_names+eta_regions_names):
	file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
	mean,fwhm = postprocessing.get_mean_width(file_name)
#	fwhm = [float(x)*2*math.sqrt(2*math.log(2)) for x in fwhm]
	fwhm = [float(x) for x in fwhm]
	if i_r<num_pt : 
		mean_all_pt.append(mean)
		fwhm_all_pt.append(fwhm)
	else:
		mean_all_eta.append(mean)
		fwhm_all_eta.append(fwhm)

outString='Comparison'+which

what=['mean Xp','p_T']
plotting.plot_mean_fwhm(mean_all_pt,pt_region,what,outString,labels,sample)
what=['mean Xp','eta']
plotting.plot_mean_fwhm(mean_all_eta,eta_region,what,outString,labels,sample)

#what=['FWHM','p_T']
what=['sigma','p_T']
plotting.plot_mean_fwhm(fwhm_all_pt,pt_region,what,outString,labels,sample)
what=['sigma','eta']
plotting.plot_mean_fwhm(fwhm_all_eta,eta_region,what,outString,labels,sample)


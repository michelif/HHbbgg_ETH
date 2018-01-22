
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
#labels=['quantile min-max 02-07','quantile_04']
#labels=['quantile 0.4']
labels=['ttbar','ZHbbll','sm','res500','res700']
labels2=[]
resolution_array = np.linspace(0., 0.4, num=10)
resolution_array = resolution_array[:-1].copy()
bres_regions = np.array([ 'b_res_20p70>=%0.3f'%resolution_array[i]+'& b_res_20p70<%0.3f'%resolution_array[i+1] for i in range(len(resolution_array)-1)])
num_res=len(bres_regions)
res_region = [ resolution_array[i]+(resolution_array[i+1]-resolution_array[i])/2. for i in range(0,len(resolution_array)-1)]

mean_all_bres=[]
fwhm_all_bres=[]
efwhm_all_bres=[]
emean_all_bres=[]

for i_r,region in enumerate(bres_regions):
	mean = []
	emean = []
	fwhm=[]	
	efwhm=[]
	for i in range(5):
		print labels[i]
		if ('sm' in labels[i] or 'res500' in labels[i] or 'res700' in labels[i]) : 
			which = 'Sumsample09erSingle_DiHiggs'+labels[i]
			sample = 'DiHiggs '+labels[i]
		else : 
			which = 'Sumsample09erSingle_'+labels[i]
  			sample = labels[i]
		if (i_r==0) : labels2.append(sample)
		file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
		mean0,fwhm0,emean0,efwhm0 = postprocessing.get_mean_width(file_name)
		mean.append(mean0)
		emean.append(emean0)
		fwhm.append(fwhm0)
		efwhm.append(efwhm0)
#		fwhm = [float(x) for x in fwhm]
	mean_all_bres.append(mean)
	fwhm_all_bres.append(fwhm)
	efwhm_all_bres.append(efwhm)
	emean_all_bres.append(efwhm)

print fwhm_all_bres

outString='Bresolution_leg_single_all'

what=['mean Xp','b_resolution']
plotting.plot_mean_fwhm(mean_all_bres,res_region,what,outString,labels2,'all',[0.85,1.02],False,emean_all_bres)
what=['sigma Bukin','b_resolution']
plotting.plot_mean_fwhm(fwhm_all_bres,res_region,what,outString,labels2,'all',[0.05,0.35],True,efwhm_all_bres)



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
labels=['quantile min-max 02-07','quantile_04']
if testfile=='sm' or testfile=='res500' or testfile=='res700' : 
	which = 'Sumsample09er_DiHiggs'+testfile
	sample = 'DiHiggs '+testfile
else : 
	which = 'Sumsample09er_'+testfile
	sample = testfile
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
	file_name = path+'fitResultRegions_Bukin'+which+region+'.txt'
	mean,fwhm,emean,efwhm = postprocessing.get_mean_width(file_name)
#	fwhm = [float(x) for x in fwhm]
	mean_all_bres.append(mean)
	fwhm_all_bres.append(fwhm)
	efwhm_all_bres.append(efwhm)
	emean_all_bres.append(efwhm)


outString='Bresolution'+which

what=['mean Xp','b_resolution']
plotting.plot_mean_fwhm(mean_all_bres,res_region,what,outString,labels,sample,[0.85,1.02],False,emean_all_bres)
what=['sigma Bukin','b_resolution']
plotting.plot_mean_fwhm(fwhm_all_bres,res_region,what,outString,labels,sample,[0.0,0.4],True,efwhm_all_bres)



# coding: utf-8

# In[5]:

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


# In[6]:

import math

path = '/mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/bregression/fitResults/'
file_pt = path+'fitResultRegions_BukinAfterReg_ptregion.txt'
file_eta = path+'fitResultRegions_BukinAfterReg_etaregion.txt'
file_pt_cat = path+'fitResultRegions_BukinAfterReg_ptregionCaterina.txt'
file_eta_cat = path+'fitResultRegions_BukinAfterReg_etaregionCaterina.txt'


mean_pt,fwhm_pt = postprocessing.get_mean_width(file_pt)
fwhm_pt = [float(x)*2*math.sqrt(2*math.log(2)) for x in fwhm_pt]

mean_eta,fwhm_eta = postprocessing.get_mean_width(file_eta)
fwhm_eta = [float(x)*2*math.sqrt(2*math.log(2)) for x in fwhm_eta]

mean_pt_cat,fwhm_pt_cat = postprocessing.get_mean_width(file_pt_cat)
fwhm_pt_cat = [float(x)*2*math.sqrt(2*math.log(2)) for x in fwhm_pt_cat]

mean_eta_cat,fwhm_eta_cat = postprocessing.get_mean_width(file_eta_cat)
fwhm_eta_cat = [float(x)*2*math.sqrt(2*math.log(2)) for x in fwhm_eta_cat]

what=['mean Xp','p_T']
pt_region=[0,100,300,700,3000]
eta_region=[0.,0.5,1.,1.5,2,2.5]
pt_region = [ pt_region[i]+(pt_region[i+1]-pt_region[i])/2. for i in range(0,len(pt_region)-1)]
eta_region = [ eta_region[i]+(eta_region[i+1]-eta_region[i])/2. for i in range(0,len(eta_region)-1)]

plotting.plot_mean_fwhm(mean_pt,mean_pt_cat,pt_region,what)
what=['mean Xp','eta']
plotting.plot_mean_fwhm(mean_eta,mean_eta_cat,eta_region,what)

what=['FWHM','p_T']
plotting.plot_mean_fwhm(fwhm_pt,fwhm_pt_cat,pt_region,what)
what=['FWHM','eta']
plotting.plot_mean_fwhm(fwhm_eta,fwhm_eta_cat,eta_region,what)



# In[ ]:




# In[ ]:




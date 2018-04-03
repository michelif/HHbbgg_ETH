import numpy as np
from sklearn.model_selection import ParameterSampler
import json
from sklearn.model_selection import train_test_split
import pandas as pd

file = 'applied_res_2018-03-28_final2016_ttbar_full_RegressionPerJet_heppy_energyRings_testing_morevar.hd5'
training ='2018-03-27_job23_rawJetsJECtarget_us_plus_pisa_final2016'
path = '/scratch/snx3000/nchernya/bregression/output_root/'
sample_name = 'ttbar2016'

data = pd.read_hdf('%s%s'%(path,file))
res = (data['Jet_resolution_NN_%s'%training])

ax2 = plt.hist(data['Jet_resolution_NN_%s'%training],bins=200)
axes = plt.gca()
axes.set_xlim(0,0.3)
savename='resolution_%s'%sample_name
path2='/scratch/snx3000/nchernya/bregression/plots/quantiles/2018-03-29/2018-03-27_job23_rawJetsJECtarget_us_plus_pisa_final2016/%s/'%sample_name
plt.savefig(path2+savename+'.pdf')
plt.savefig(path2+savename+'.png')
plt.show()

import numpy as np
from sklearn.model_selection import ParameterSampler
import json

param_grid = {'dropout':[0.05, 0.1,0.2,0.3], 'optimizer_params':[dict(lr=1.e-03),dict(lr=0.5e-03)], 'layers':[[1024,512,256,128],[1024,512,256]] }
param_list = list(ParameterSampler(param_grid, n_iter=5))
print(param_list)
inp_dir='/users/nchernya/HHbbgg_ETH/bregression/notebooks/json/'
for i,item in enumerate(param_list):
    with open('%s/data_%i.json'%(inp_dir,i), 'w') as f:
        json.dump(item, f)


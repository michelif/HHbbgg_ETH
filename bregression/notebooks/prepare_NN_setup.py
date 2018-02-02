import numpy as np
from sklearn.model_selection import ParameterSampler
import json
import os

#param_grid = {'dropout':[0.05, 0.1,0.2,0.3], 'optimizer_params':[dict(lr=1.e-03),dict(lr=0.5e-03)], 'layers':[[1024,512,256,128],[1024,512,256]] }
param_grid = {'dropout':[0.02], 'optimizer_params':[dict(lr=1.e-03),dict(lr=1.e-04),dict(lr=1.e-05),dict(lr=1.e-06),dict(lr=1.e-07)], 'layers':[[1024,512,256,128]] }
param_list = list(ParameterSampler(param_grid, n_iter=5))
print(param_list)
output_dir=os.environ['SCRATCH']+'/bregression/json/'
if not os.path.exists(output_dir):
    os.mkdir(output_dir)

for i,item in enumerate(param_list):
    with open('%s/hparameters_%i.json'%(output_dir,i), 'w') as f:
        json.dump(item, f)


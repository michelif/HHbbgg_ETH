import numpy as np
from sklearn.model_selection import ParameterSampler
import json
import os
import datetime

#param_grid = {'dropout':[0.1,0.2,0.3], 'optimizer_params':[dict(lr=1.e-03),dict(lr=0.5e-03)], 'layers':[[1024,512,256,128],[1024,512,256]] }
#param_grid = {'dropout':[0.2], 'optimizer_params':[dict(lr=1.e-03),dict(lr=1.e-04),dict(lr=1.e-05),dict(lr=1.e-06),dict(lr=1.e-07)], 'layers':[[1024,512,256,128]] }
#param_grid = {'dropout':[0.2], 'optimizer_params':[dict(lr=0.5e-06)], 'layers':[[1024,512,256,128]] }
param_grid = {'dropout':[0.1,0.2,0.3,0.4], 'optimizer_params':[dict(lr=1.e-02),dict(lr=1.e-03),dict(lr=1.e-04),dict(lr=1.e-05),dict(lr=1.e-06)], 'layers':[[512,256,128],[1024,512,256,128],[1024,1024,1024,512,256,128],[1024,1024,1024,1024,1024,512,256,128]] }
param_list = list(ParameterSampler(param_grid, n_iter=50))
print(param_list)
now = datetime.datetime.now()
now = str(now).split(' ')[0] +'_'+ str(now).split(' ')[1].split('.')[0].replace(':','_')
output_dir=os.environ['SCRATCH']+'/bregression/json/%s/'%now
if not os.path.exists(output_dir):
    os.mkdir(output_dir)

for i,item in enumerate(param_list):
    with open('%s/hparameters_%i.json'%(output_dir,i), 'w') as f:
        json.dump(item, f)


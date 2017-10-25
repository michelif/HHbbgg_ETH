
# coding: utf-8

# In[2]:

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


# In[3]:

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

#ttbar= [s for s in files if "20trees_safe" in s] #large statistics
#ttbar= [s for s in files if "ttbar_RegressionPerJet.root" in s] # only limited statistics
ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_forTraining.root" in s] #large statistics and nPVs is filled properly


utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)

for i in range(len(utils.IO.targetName)):        
    print "using target file n."+str(i)+": "+utils.IO.targetName[i]
for i in range(len(utils.IO.featuresName)):        
    print "using features file n."+str(i)+": "+utils.IO.featuresName[i]


# In[ ]:




# 

# In[39]:

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#noexpand:fabs(CosThetaStar_CS)
branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")

#features = 'Jet_pt,Jet_eta,Jet_corr,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")
#target = 'Jet_mcPt/Jet_pt'.split(",")
#cuts='(Jet_mcPt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_pt > 15) & (Jet_eta<2.4 & Jet_eta>-2.4) & (dR < 0.4)'
###########as Caterina###################
features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",") #same as Caterina
#features = 'Jet_pt,Jet_eta,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",") #same as Caterina
target = 'Jet_mcPt'.split(",")
cuts='(Jet_mcPt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5)'
#cuts='Jet_mcPt > 20 & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & Jet_pt > 15' #same as Caterina
#######cuts='(Jet_mcPtq > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_pt > 15)  & (dR < 0.35)'
#########################################


branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]
target = [c.strip() for c in target]

#print branch_names

import pandas as pd
import root_pandas as rpd


# type pandas DataFrame
X_features = preprocessing.set_features("tree",branch_names,features,cuts)
X_target = preprocessing.set_target("tree",branch_names,target,cuts)
X_features,X_target=preprocessing.randomize_ft(X_features,X_target)

#print max(X_features[:,1])
#print pd.DataFrame(utils.IO.features_df[0],columns=['Jet_eta'])

#now type if np.array
X_train_target = preprocessing.get_training_sample(pd.DataFrame(X_target))
X_train_features = preprocessing.get_training_sample(pd.DataFrame(X_features))

X_test_target = preprocessing.get_test_sample(pd.DataFrame(X_target))
X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features))

#X_target_data =  pd.DataFrame(utils.IO.data_df[0],columns=['Jet_mcPt'])
#X_data_target = utils.IO.data_df[0][['Jet_mcPt']]
#new_jet_mcPt = jet_mcPt.query('Jet_mcPt > 30')

from sklearn.externals import joblib
import xgboost as xgb
import matplotlib.pyplot as plt

#X_all = preprocessing.cut_region("tree",branch_names,branch_names,cuts)

pt_regions = '(Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<700),(Jet_mcPt>700)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
eta_regions = '(Jet_eta<0.5 & Jet_eta>-0.5),((Jet_eta>=0.5 & Jet_eta<1.0) |(Jet_eta<=-0.5 & Jet_eta>-1.0)),(( Jet_eta>=1.0 & Jet_eta<1.5)|(Jet_eta<=-1.0 & Jet_eta>-1.5)),( (Jet_eta>=1.5 & Jet_eta<2.0)|(Jet_eta<=-1.5 & Jet_eta>=-2.0 )),(Jet_eta>=2.0 | Jet_eta<=-2.0)'.split(",")
X_pt_region=[] # list of pandas DataFrame
X_eta_region=[] # list of pandas DataFrame
target_dist = []
target_dist.append('noexpand:Jet_mcPt/Jet_pt')
for region in pt_regions:
    cuts_regions = cuts+'&'+region
    X_pt_region.append(preprocessing.cut_region("tree",branch_names,target_dist,cuts_regions))
for region in eta_regions:
    cuts_regions = cuts+'&'+region
    X_eta_region.append(preprocessing.cut_region("tree",branch_names,target_dist,cuts_regions))

#plotting.plot_regions(X_pt_region,pt_regions,True,50,"ptCrujiff",True)
#plotting.plot_regions(X_eta_region,eta_regions_names,True,50,"eta")
#plt.show()
#log_names='Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
#plotting.plot_input_variables_reg(X_features,features,log_names)
#plotting.plot_input_variables_reg(X_all,branch_names,log_names)
#plt.show()






# In[5]:

########final optimization with all fixed#######

from sklearn.externals import joblib
import xgboost as xgb
from sklearn.metrics import confusion_matrix, mean_squared_error
from sklearn.grid_search import GridSearchCV


#clf = xgb.XGBRegressor(base_score=0.5, colsample_bylevel=1, colsample_bytree=1,
    #   gamma=0, learning_rate=0.1, max_delta_step=0, max_depth=9,
    #   min_child_weight=1e-05, missing=None, n_estimators=1500, nthread=20,
    #   objective='reg:linear', reg_alpha=0, reg_lambda=0.1,
    #   scale_pos_weight=1, seed=0, silent=True, subsample=1)

clf = xgb.XGBRegressor(base_score=1.0,objective='reg:linear', learning_rate=0.1,max_depth=13,min_child_weight=0.002,n_estimators=300,reg_alpha=0,reg_lambda=0)
#param_grid = {'n_estimators': [100,500]}
#grid_scores = optimization.optimize_parameters_gridCV_ref(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid)

#clf = GridSearchCV(xgb_model, {'max_depth': [4,5,6]}, verbose=1,n_jobs==-1)
clf.fit(X_train_features,X_train_target)
#print clf.best_score_
#print clf.best_params_
joblib.dump(clf, os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_mcPt_Cat_pt_eta_nPVs.pkl'), compress=9)
#predictions = clf.predict(X_test_features)
#print predictions, predictions.shape
#actuals = X_test_target
#true = (actuals.as_matrix()).ravel()
#recoPt = (X_test_features[0].as_matrix()).ravel()
##print true, true.shape
#print true[0]/predictions[0]
#ratio = true/predictions
#ratio=1/ratio
#reco_ratio=true/recoPt
#reco_ratio=1./reco_ratio
#print ratio.shape
#print ratio


#print(mean_squared_error(actuals, predictions))
#print type(actuals), type(predictions)



# In[ ]:

import matplotlib.pyplot as plt
import training_utils as utils
import ROOT
from ROOT import gROOT
#import plotting_utils as plotting
#import training_utils as utils
reload(utils)
reload(plotting)

#regressed_pt = predictions*recoPt
#true_pt = true*recoPt

#xgb.plot_importance(clf)
#plt.show()
#plt.savefig(utils.IO.plotFolder+"importance1.pdf")

#style=False
#plotting.plot_rel_pt_diff(predictions,true,recoPt,style,100,)
#plotting.plot_rel_pt_diff(regressed_pt,true_pt,recoPt,style,100,)


# In[11]:






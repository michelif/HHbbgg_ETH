
# coding: utf-8

# In[2]:

import os
import sys; sys.path.append("~/HHbbgg_ETH_devel/bregression/python") # to load packages
import matplotlib as mpl
mpl.use('Agg')
import matplotlib.pyplot as plt
plt.ioff() 
import training_utils as utils
import numpy as np
import ROOT
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import plotting_utils as plotting
reload(plotting)
import optimization_utils as optimization
reload(optimization)
import postprocessing_utils as postprocessing
reload(postprocessing)

import json
import time
start_time = time.time()


alpha_q=sys.argv[1]
print alpha_q

# In[3]:

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings_forTraining.root" in s] #energy rings tiny sample
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_Large0.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_LargeAll2.root" in s] #energy rings large and proper sample with Jet_e
ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTraining_LargeAll.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTraining_Large0.root" in s] #energy rings large and proper sample with Jet_e


utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)


#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,Jet_corr,Jet_mcPt,Jet_mcFlavour,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_e,noexpand:Jet_energyRing_dR0_em/Jet_e,noexpand:Jet_energyRing_dR1_em/Jet_e,noexpand:Jet_energyRing_dR2_em/Jet_e,noexpand:Jet_energyRing_dR3_em/Jet_e,noexpand:Jet_energyRing_dR4_em/Jet_e,noexpand:Jet_energyRing_dR0_neut/Jet_e,noexpand:Jet_energyRing_dR1_neut/Jet_e,noexpand:Jet_energyRing_dR2_neut/Jet_e,noexpand:Jet_energyRing_dR3_neut/Jet_e,noexpand:Jet_energyRing_dR4_neut/Jet_e,noexpand:Jet_energyRing_dR0_ch/Jet_e,noexpand:Jet_energyRing_dR1_ch/Jet_e,noexpand:Jet_energyRing_dR2_ch/Jet_e,noexpand:Jet_energyRing_dR3_ch/Jet_e,noexpand:Jet_energyRing_dR4_ch/Jet_e,noexpand:Jet_energyRing_dR0_mu/Jet_e,noexpand:Jet_energyRing_dR1_mu/Jet_e,noexpand:Jet_energyRing_dR2_mu/Jet_e,noexpand:Jet_energyRing_dR3_mu/Jet_e,noexpand:Jet_energyRing_dR4_mu/Jet_e,Jet_numDaughters_pt03'.split(",")
branch_names = 'Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,noexpand:Jet_mcPt/Jet_pt,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
features = 'Jet_pt,Jet_eta,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina

target = 'Jet_mcPt/Jet_pt'.split(",")
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt>0) & (Jet_mcPt<6000)'


branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]
target = [c.strip() for c in target]

#print branch_names

import pandas as pd
import root_pandas as rpd


root_tfile = ROOT.TFile.Open(utils.IO.targetName[0], "read")
tree = root_tfile.Get("tree")
hist = ROOT.TH1F("hist","hist",100,0,1500)
tree.Draw("Jet_pt>>hist",cuts,"goff")
func_w = ROOT.TF1("func","expo",0,2000)
func_w.FixParameter(0,1.23547e+01)
func_w.FixParameter(1,-0.83230e-02)

data_frame = preprocessing.add_pt_weight_reg(utils.IO.targetName[0],branch_names,cuts,hist,func_w)

X_features,X_weights = preprocessing.set_features_target_weights(data_frame,features)
X_target,X_weights = preprocessing.set_features_target_weights(data_frame, target)
X_features,X_target,X_weights=preprocessing.randomize_w(X_features,X_target,X_weights)


X_train_target = preprocessing.get_training_sample(pd.DataFrame(X_target),0.9)
X_train_features = preprocessing.get_training_sample(pd.DataFrame(X_features),0.9)
#X_train_weights = preprocessing.get_training_sample(pd.DataFrame(X_weights),0.9)

X_test_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.9)
X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.9)
#X_test_weights = preprocessing.get_test_sample(pd.DataFrame(X_weights),0.9)

#now no need to split in test and training because i am not using testing here
#X_train_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.)   #0.8
#X_train_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)


from sklearn.externals import joblib
import xgboost as xgb



print 'ready to train'


########final optimization with all fixed#######

from sklearn.externals import joblib
import xgboost as xgb
from sklearn.metrics import confusion_matrix, mean_squared_error
from sklearn.grid_search import GridSearchCV

######################################
#clf = xgb.XGBRegressor(base_score=0.5, colsample_bylevel=1, colsample_bytree=1,
    #   gamma=0, learning_rate=0.1, max_delta_step=0, max_depth=9,
    #   min_child_weight=1e-05, missing=None, n_estimators=1500, nthread=20,
    #   objective='reg:linear', reg_alpha=0, reg_lambda=0.1,
    #   scale_pos_weight=1, seed=0, silent=True, subsample=1)

#clf = xgb.XGBRegressor(base_score=1.0,objective='reg:linear', learning_rate=0.05,max_depth=7,min_child_weight=0.002,n_estimators=400,reg_alpha=1.0,reg_lambda=1.0, nthread=10 ) 
#clf = xgb.XGBRegressor(base_score=1.0, colsample_bylevel=1, colsample_bytree=1, gamma=0,
#       learning_rate=0.2, max_delta_step=0, max_depth=10,
#      min_child_weight=0.02, missing=None, n_estimators=700, nthread=2,
#       objective='reg:linear', reg_alpha=0, reg_lambda=1.0,
#       scale_pos_weight=1, seed=0, silent=True, subsample=1.0)   #best parameters found for non pt_reweightin

from sklearn.ensemble import GradientBoostingRegressor
clf = GradientBoostingRegressor(loss='quantile',alpha=float(alpha_q), 
       learning_rate=0.2, max_depth=10,
      min_weight_fraction_leaf=0.02,  n_estimators=700, random_state=0,  subsample=0.9)   #best parameters found for non pt_reweightin


##########################################
####
#param_grid = {'n_estimators': [300], 'max_depth':[13], 'min_child_weight':[0.002], 'learning_rate':[0.1], 'objective':['reg:linear'],'reg_lambda':[0],'reg_alpha':[0],'base_score':[1.0], 'nthread':[2] }
##param_grid = {'n_estimators': [100,300,1000], 'max_depth':[6,13,20], 'min_child_weight':[0.0001,0.002,1.]}
#xgb_model = xgb.XGBRegressor()
#param_grid = {'n_estimators': [200,300,400],
#	'base_score':[1.0,1.1],
#	'objective':['reg:linear'],
#	'learning_rate':[0.05,0.1,0.2],
#	'max_depth':[3,5,7],
#	'min_child_weight':[0.0002,0.002,0.02],
#	'reg_alpha':[0,0.2,1.],
#	'reg_lambda':[0,0.2,1.],
#	'nthread':[10]} #4 the same as in the engine scipt smp 4
###register the cluster with setupJoblib(gcc_...)
param_grid = {'n_estimators': [100,500,700,1000],
	'base_score':[1.],
	'objective':['reg:linear'],
	'learning_rate':[0.05,0.1,0.2,0.8],
	'max_depth':[3,5,7,10,15],
	'min_child_weight':[0.0002,0.002,0.02,0.05],
	'reg_alpha':[0,0.5,1.],
	'reg_lambda':[0,0.5,1.],
	'gamma':[0,0.3],
   'subsample':[1.],
	'nthread':[2]} #4 the same as in the engine scipt smp 4
###register the cluster with setupJoblib(gcc_...)

import scoring_function as scoring_function
from sklearn.metrics import r2_score, make_scorer
#my_scorer = make_scorer(scoring_function.scoring_function)
my_scorer = make_scorer(r2_score)

#optimization.setupJoblib("gcc49_5gb_smp4")
#clf = optimization.optimize_parameters_randomizedCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid,my_scorer,40,5,50,True)#nIter=20,cvOpt=5,nJobs=20
#clf = optimization.optimize_parameters_randomizedCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid,my_scorer,15,5,50,True,X_train_weights)#nIter=20,cvOpt=5,nJobs=20
#clf = optimization.optimize_parameters_randomizedCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid,my_scorer,1,2,1,True,X_train_weights)#nIter=20,cvOpt=5,nJobs=20

#clf = optimization.optimize_parameters_randomizedCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid,my_scorer,1,2,4,True)#nIter=20,cvOpt=5,nJobs=20
#clf.fit(X_train_features,X_train_target,sample_weight=X_train_weights)  ### no need because refit by default is true
#clf.fit(X_train_features,X_train_target)  ### no need because refit by default is true



#grid_scores = optimization.optimize_parameters_gridCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid)
####


###register the cluster with setupJoblib(gcc_...)
#optimization.setupJoblib("gcc49_5gb_smp4")
clf.fit(X_train_features.values,X_train_target.values.ravel())
#print clf.best_score_

#save the training 

#end= 'tiny_energyring_fraction_oldparam_wo_mu'
#end= 'full_sample_wo_weights_opt_onwo'
#end= 'full_sample_w_weights_optimization_50jobs_worker'
#end= 'full_quantile_regression_alpha'+str(alpha_q)
end= 'full_subsample09_quantile_regression_alpha'+str(alpha_q)
#end= 'full_energyring_wo_Pt_reweight_local'
################
#joblib.dump(clf.best_estimator_, os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_'+end+'.pkl'), compress=9)
joblib.dump(clf, os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_'+end+'.pkl'), compress=9)

foutput = open(os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/params_regression_heppy_'+end+'.txt'),'w')
foutput.write('features = ')
for x in features:foutput.write(x)
foutput.write(' ; cuts = ')
for x in cuts:foutput.write(x)
foutput.write(' ; Parameters = ')
json.dump(clf.get_params(),foutput)
foutput.close()

#X_pred_data = clf.predict(X_test_features).astype(np.float64)
#path='/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/output_files/'
#np.save(path+'out_pred'+end,X_pred_data)
#np.save(path+'out_true'+end,X_test_target)
#np.save(path+'out_weights'+end,X_test_weights)

#plotting.plot_feature_importance(clf.best_estimator_,features,end)

print 'It took', time.time()-start_time, 'seconds.'




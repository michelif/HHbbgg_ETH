
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

import json
import time
start_time = time.time()


# In[3]:

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTraining.root" in s] #energy rings tiny sample
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_Large0.root" in s] #energy rings large and proper sample with Jet_e
ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTraining_Large0.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_LargeAll2.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_forTraining_Large.root" in s] #very large statistic


utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)

for i in range(len(utils.IO.targetName)):        
    print "using target file n."+str(i)+": "+utils.IO.targetName[i]
for i in range(len(utils.IO.featuresName)):        
    print "using features file n."+str(i)+": "+utils.IO.featuresName[i]


# In[ ]:




# 

# In[39]:

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")
#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")
#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em,Jet_energyRing_dR1_em,Jet_energyRing_dR2_em,Jet_energyRing_dR3_em,Jet_energyRing_dR4_em,Jet_energyRing_dR0_neut,Jet_energyRing_dR1_neut,Jet_energyRing_dR2_neut,Jet_energyRing_dR3_neut,Jet_energyRing_dR4_neut,Jet_energyRing_dR0_ch,Jet_energyRing_dR1_ch,Jet_energyRing_dR2_ch,Jet_energyRing_dR3_ch,Jet_energyRing_dR4_ch,Jet_energyRing_dR0_mu,Jet_energyRing_dR1_mu,Jet_energyRing_dR2_mu,Jet_energyRing_dR3_mu,Jet_energyRing_dR4_mu,Jet_numDaughters_pt03'.split(",")
branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_e,noexpand:Jet_energyRing_dR0_em/Jet_e,noexpand:Jet_energyRing_dR1_em/Jet_e,noexpand:Jet_energyRing_dR2_em/Jet_e,noexpand:Jet_energyRing_dR3_em/Jet_e,noexpand:Jet_energyRing_dR4_em/Jet_e,noexpand:Jet_energyRing_dR0_neut/Jet_e,noexpand:Jet_energyRing_dR1_neut/Jet_e,noexpand:Jet_energyRing_dR2_neut/Jet_e,noexpand:Jet_energyRing_dR3_neut/Jet_e,noexpand:Jet_energyRing_dR4_neut/Jet_e,noexpand:Jet_energyRing_dR0_ch/Jet_e,noexpand:Jet_energyRing_dR1_ch/Jet_e,noexpand:Jet_energyRing_dR2_ch/Jet_e,noexpand:Jet_energyRing_dR3_ch/Jet_e,noexpand:Jet_energyRing_dR4_ch/Jet_e,noexpand:Jet_energyRing_dR0_mu/Jet_e,noexpand:Jet_energyRing_dR1_mu/Jet_e,noexpand:Jet_energyRing_dR2_mu/Jet_e,noexpand:Jet_energyRing_dR3_mu/Jet_e,noexpand:Jet_energyRing_dR4_mu/Jet_e,Jet_numDaughters_pt03'.split(",")
#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_e,noexpand:Jet_energyRing_dR0_em/Jet_e,noexpand:Jet_energyRing_dR1_em/Jet_e,noexpand:Jet_energyRing_dR2_em/Jet_e,noexpand:Jet_energyRing_dR3_em/Jet_e,noexpand:Jet_energyRing_dR4_em/Jet_e,noexpand:Jet_energyRing_dR0_neut/Jet_e,noexpand:Jet_energyRing_dR1_neut/Jet_e,noexpand:Jet_energyRing_dR2_neut/Jet_e,noexpand:Jet_energyRing_dR3_neut/Jet_e,noexpand:Jet_energyRing_dR4_neut/Jet_e,noexpand:Jet_energyRing_dR0_ch/Jet_e,noexpand:Jet_energyRing_dR1_ch/Jet_e,noexpand:Jet_energyRing_dR2_ch/Jet_e,noexpand:Jet_energyRing_dR3_ch/Jet_e,noexpand:Jet_energyRing_dR4_ch/Jet_e,Jet_numDaughters_pt03'.split(",")

#features = 'Jet_pt,Jet_eta,Jet_corr,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")
#features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em,Jet_energyRing_dR1_em,Jet_energyRing_dR2_em,Jet_energyRing_dR3_em,Jet_energyRing_dR4_em,Jet_energyRing_dR0_neut,Jet_energyRing_dR1_neut,Jet_energyRing_dR2_neut,Jet_energyRing_dR3_neut,Jet_energyRing_dR4_neut,Jet_energyRing_dR0_ch,Jet_energyRing_dR1_ch,Jet_energyRing_dR2_ch,Jet_energyRing_dR3_ch,Jet_energyRing_dR4_ch,Jet_energyRing_dR0_mu,Jet_energyRing_dR1_mu,Jet_energyRing_dR2_mu,Jet_energyRing_dR3_mu,Jet_energyRing_dR4_mu,Jet_numDaughters_pt03'.split(",") #same as Caterina
#features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em/Jet_e,Jet_energyRing_dR1_em/Jet_e,Jet_energyRing_dR2_em/Jet_e,Jet_energyRing_dR3_em/Jet_e,Jet_energyRing_dR4_em/Jet_e,Jet_energyRing_dR0_neut/Jet_e,Jet_energyRing_dR1_neut/Jet_e,Jet_energyRing_dR2_neut/Jet_e,Jet_energyRing_dR3_neut/Jet_e,Jet_energyRing_dR4_neut/Jet_e,Jet_energyRing_dR0_ch/Jet_e,Jet_energyRing_dR1_ch/Jet_e,Jet_energyRing_dR2_ch/Jet_e,Jet_energyRing_dR3_ch/Jet_e,Jet_energyRing_dR4_ch/Jet_e,Jet_energyRing_dR0_mu/Jet_e,Jet_energyRing_dR1_mu/Jet_e,Jet_energyRing_dR2_mu/Jet_e,Jet_energyRing_dR3_mu/Jet_e,Jet_energyRing_dR4_mu/Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
#features = 'Jet_pt,Jet_eta,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtx3deL,Jet_energyRing_dR0_em/Jet_e,Jet_energyRing_dR1_em/Jet_e,Jet_energyRing_dR2_em/Jet_e,Jet_energyRing_dR3_em/Jet_e,Jet_energyRing_dR4_em/Jet_e,Jet_energyRing_dR0_neut/Jet_e,Jet_energyRing_dR1_neut/Jet_e,Jet_energyRing_dR2_neut/Jet_e,Jet_energyRing_dR3_neut/Jet_e,Jet_energyRing_dR4_neut/Jet_e,Jet_energyRing_dR0_ch/Jet_e,Jet_energyRing_dR1_ch/Jet_e,Jet_energyRing_dR2_ch/Jet_e,Jet_energyRing_dR3_ch/Jet_e,Jet_energyRing_dR4_ch/Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em/Jet_e,Jet_energyRing_dR1_em/Jet_e,Jet_energyRing_dR2_em/Jet_e,Jet_energyRing_dR3_em/Jet_e,Jet_energyRing_dR4_em/Jet_e,Jet_energyRing_dR0_neut/Jet_e,Jet_energyRing_dR1_neut/Jet_e,Jet_energyRing_dR2_neut/Jet_e,Jet_energyRing_dR3_neut/Jet_e,Jet_energyRing_dR4_neut/Jet_e,Jet_energyRing_dR0_ch/Jet_e,Jet_energyRing_dR1_ch/Jet_e,Jet_energyRing_dR2_ch/Jet_e,Jet_energyRing_dR3_ch/Jet_e,Jet_energyRing_dR4_ch/Jet_e,Jet_energyRing_dR0_mu/Jet_e,Jet_energyRing_dR1_mu/Jet_e,Jet_energyRing_dR2_mu/Jet_e,Jet_energyRing_dR3_mu/Jet_e,Jet_energyRing_dR4_mu/Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
target = 'Jet_mcPt/Jet_pt'.split(",")
#target = 'Jet_mcPt'.split(",")
#cuts='(Jet_mcPt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & dR<0.4'
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) '
#cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) '
#cuts='(Jet_mcPt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_pt > 15) & (Jet_eta<2.4 & Jet_eta>-2.4) & (dR < 0.4)'
#cuts='Jet_mcPt > 20 & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & Jet_pt > 15' #same as Caterina
#######cuts='(Jet_mcPtq > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_pt > 15)  & (dR < 0.35)'

###########as Caterina, exactly the same result###################
#features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",") #same as Caterina
#target = 'Jet_mcPt'.split(",")
####cuts='(Jet_mcPt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5)'
#cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) '
#########################################


branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]
target = [c.strip() for c in target]

#print branch_names

import pandas as pd
import root_pandas as rpd


X_features = preprocessing.set_features("tree",branch_names,features,cuts)
X_target = preprocessing.set_target("tree",branch_names,target,cuts)
X_features,X_target=preprocessing.randomize_ft(X_features,X_target)


X_train_target = preprocessing.get_training_sample(pd.DataFrame(X_target),0.9)
X_train_features = preprocessing.get_training_sample(pd.DataFrame(X_features),0.9)

X_test_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.9)
X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.9)

#now no need to split in test and training because i am not using testing here
#X_train_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.)   #0.8
#X_train_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)



from sklearn.externals import joblib
import xgboost as xgb
import matplotlib.pyplot as plt

#X_all = preprocessing.cut_region("tree",branch_names,branch_names,cuts)

#pt_regions = '(Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<700),(Jet_mcPt>700)'.split(",")
#eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
#eta_regions = '(Jet_eta<0.5 & Jet_eta>-0.5),((Jet_eta>=0.5 & Jet_eta<1.0) |(Jet_eta<=-0.5 & Jet_eta>-1.0)),(( Jet_eta>=1.0 & Jet_eta<1.5)|(Jet_eta<=-1.0 & Jet_eta>-1.5)),( (Jet_eta>=1.5 & Jet_eta<2.0)|(Jet_eta<=-1.5 & Jet_eta>=-2.0 )),(Jet_eta>=2.0 | Jet_eta<=-2.0)'.split(",")
#X_pt_region=[] # list of pandas DataFrame
#X_eta_region=[] # list of pandas DataFrame
#target_dist = []
#target_dist.append('noexpand:Jet_mcPt/Jet_pt')
#for region in pt_regions:
#    cuts_regions = cuts+'&'+region
#    X_pt_region.append(preprocessing.cut_region(utils.IO.featuresName[0],"tree",branch_names,target_dist,cuts_regions))
#for region in eta_regions:
#    cuts_regions = cuts+'&'+region
#    X_eta_region.append(preprocessing.cut_region(utils.IO.featuresName[0],"tree",branch_names,target_dist,cuts_regions))

#plotting.plot_regions(X_pt_region,pt_regions,True,50,"ptCrujiff",True)
#plotting.plot_regions(X_eta_region,eta_regions_names,True,50,"eta")
#plt.show()


#log_names='Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
#plotting.plot_input_variables_reg(X_features,features,log_names,30,'energyRings_fraction')
#plotting.plot_input_variables_reg(X_all,branch_names,log_names)
#plt.show()





print 'ready to train'


# In[5]:

########final optimization with all fixed#######

import xgboost as xgb
from sklearn.metrics import confusion_matrix, mean_squared_error
#from sklearn.grid_search import GridSearchCV

######################################
#clf = xgb.XGBRegressor(base_score=0.5, colsample_bylevel=1, colsample_bytree=1,
    #   gamma=0, learning_rate=0.1, max_delta_step=0, max_depth=9,
    #   min_child_weight=1e-05, missing=None, n_estimators=1500, nthread=20,
    #   objective='reg:linear', reg_alpha=0, reg_lambda=0.1,
    #   scale_pos_weight=1, seed=0, silent=True, subsample=1)

#clf = xgb.XGBRegressor(base_score=1.0,objective='reg:linear', learning_rate=0.1,max_depth=13,min_child_weight=0.002,n_estimators=300,reg_alpha=0,reg_lambda=0)  #caterina
clf = xgb.XGBRegressor(base_score=1.0,objective='reg:linear', learning_rate=0.05,max_depth=7,min_child_weight=0.0002,n_estimators=400,reg_alpha=1.0,reg_lambda=1.0, nthread=10 ) 
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
#param_grid = {'n_estimators': [50,100,500,700,1000],
#	'base_score':[1.],
#	'objective':['reg:linear'],
#	'learning_rate':[0.05,0.1,0.2,0.8],
#	'max_depth':[3,5,7,10],
#	'min_child_weight':[0.0002,0.002,0.02],
#	'reg_alpha':[0,0.5,1.],
#	'reg_lambda':[0,0.5,1.],
#	'gamma':[0,0.3],
#	'nthread':[4]} #4 the same as in the engine scipt smp 4
####register the cluster with setupJoblib(gcc_...)


#optimization.setupJoblib("gcc49_5gb_smp4")
#clf = optimization.optimize_parameters_randomizedCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid,20,5,5,True)#nIter=20,cvOpt=5,nJobs=20
###clf.fit(X_train_features,X_train_target)  - no need because refit by default is true



#grid_scores = optimization.optimize_parameters_gridCV_reg(xgb_model,X_train_features,X_train_target,X_test_features,X_test_target,param_grid)
####


clf.fit(X_train_features,X_train_target)  #when do optimization no need because refit by default is true


###register the cluster with setupJoblib(gcc_...)
#optimization.setupJoblib("gcc49_5gb_smp4")
#clf.fit(X_train_features,X_train_target)
#print clf.best_score_

#save the training 

#end= 'tiny_energyring_fraction_oldparam_wo_mu'
end= 'full_energyRings3_wo_deltaR_large0'
################
#end = 'test_jobs_tiny'
#joblib.dump(clf.best_estimator_, os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_'+end+'.pkl'), compress=9)

#foutput = open(os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/params_regression_heppy_'+end+'.txt'),'w')
#foutput.write('features = ')
#for x in features:foutput.write(x)
#foutput.write(' ; cuts = ')
#for x in cuts:foutput.write(x)
#foutput.write(' ; Parameters = ')
#json.dump(clf.best_params_,foutput)
#foutput.close()



#features_importance =  optimization.feature_importances_(clf.best_estimator_)
features_importance =  optimization.feature_importances_(clf)
features_dict = {features[i]:features_importance[i] for i in range(0,len(features)) }
sorted_features_values = sorted( features_dict.values(),reverse=True)
sorted_features = [key for key,value in sorted(features_dict.items() ,key=lambda x : x[1], reverse=True)]



y_pos = np.arange(0,len(features)*2,2)  # the x locations for the groups
width = 1.2       # the width of the bars
fig,ax = plt.subplots()
ax.barh(y_pos,sorted_features_values,width,color='green',align='center')
for x, y in zip(sorted_features_values, y_pos):
   ax.text(x + 0.01, y+0.1, np.round(x,3), va='center', fontsize=6,fontweight='bold',color='blue')
fig.subplots_adjust(left=0.2) 
####ax.set_yticks(y_pos+width/2.)
ax.set_yticks(y_pos)
ax.set_yticklabels(sorted_features,rotation=0,fontsize=7)
ax.invert_yaxis() 
ax.set_xlabel('F-scores')
ax.set_xlim(0,sorted_features_values[0]*1.1)
ax.set_title("Features importance")
plt.grid()
plt.savefig(utils.IO.plotFolder+"importanceBar_"+end+".pdf")
plt.clf()
#
print 'It took', time.time()-start_time, 'seconds.'




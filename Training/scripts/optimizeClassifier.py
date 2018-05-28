# coding: utf-8

import os
import sys; sys.path.append("~/HHbbgg_ETH_devel/Training/python") # to load packages
import training_utils as utils
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import optimization_utils as optimization
reload(optimization)
import numpy as np
import time
import datetime
start_time = time.time()

now = str(datetime.datetime.now()).split(' ')[0]
outstr = "%s_optimizationWithReg_jobs2"%now
outputFolder = '/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/Training/output_files/%s/'%outstr
if not os.path.exists(outputFolder):
    print outputFolder, "doesn't exist, creating it..."
    os.makedirs(outputFolder)


ntuples = 'ntuples_20180524'
random_seed = 555
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
signal = [s for s in files if "NonRes" in s or "node_SM" in s]
diphotonJets = [s for s in files if "DiPhotonJets" in s]
gJets_lowPt = [s for s in files if "GJet_Pt-20to40" in s]
gJets_highPt = [s for s in files if "GJet_Pt-40" in s]

utils.IO.add_signal(ntuples,signal,1)
utils.IO.add_background(ntuples,diphotonJets,-1)
utils.IO.add_background(ntuples,gJets_lowPt,-1)
utils.IO.add_background(ntuples,gJets_highPt,-1)

for i in range(len(utils.IO.backgroundName)):        
    print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]
for i in range(len(utils.IO.signalName)):    
    print "using signal file n."+str(i)+": "+utils.IO.signalName[i]


# In[10]:

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#branch_names = 'leadingJet_bDis,subleadingJet_bDis,noexpand:fabs(CosThetaStar_CS),noexpand:fabs(CosTheta_bb),noexpand:fabs(CosTheta_gg),noexpand:diphotonCandidate.Pt()/diHiggsCandidate.M(),noexpand:dijetCandidate.Pt()/diHiggsCandidate.M(),customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverMDecorr,DiJetDiPho_DR'.split(",")
#branch_names = 'leadingJet_bDis,subleadingJet_bDis,noexpand:fabs(CosThetaStar_CS),noexpand:fabs(CosTheta_bb),noexpand:fabs(CosTheta_gg),noexpand:diphotonCandidate.Pt()/diHiggsCandidate.M(),noexpand:dijetCandidate.Pt()/diHiggsCandidate.M()'.split(",")
branch_names = 'leadingJetCorr_bDis,subleadingJetCorr_bDis,noexpand:fabs(CosThetaStar_CS),noexpand:fabs(CosTheta_bb),noexpand:fabs(CosTheta_gg),noexpand:diphotonCandidate.Pt()/diHiggsCandidateCorr.M(),noexpand:dijetCandidateCorr.Pt()/diHiggsCandidateCorr.M(),customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverM,PhoJetMinDr'.split(",") #set of variables March 2017 but regressed
b_reg_branches = 'leadingJet_bRegNNResolution,subleadingJet_bRegNNResolution,dijetSigmaMOverM'.split(",")
branch_names = branch_names+b_reg_branches
resolution_weighting = 'ggbb' # None, gg or ggbb
branch_names = [c.strip() for c in branch_names]
print branch_names

import pandas as pd
import root_pandas as rpd

#utils.IO.get_cross_sections('jsons/datasets80X_Moriond.json')
#utils.IO.w_sig.append(utils.IO.get_weight('signal','nrSM',0))
#utils.IO.w_bkg(utils.IO.get_weight('background','DiPhoJets',0))
#utils.IO.w_bkg(utils.IO.get_weight('background','GJets',0))
#utils.IO.w_bkg(utils.IO.get_weight('background','GJets',1))


preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names)
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.set_variables(branch_names)

#relative weighting between components of one class is kept, all classes normalized to the same
#weights_sig=utils.preprocessing.weight_signal_with_resolution(weights_sig,y_sig)
#weights_sig=utils.preprocessing.weight_signal_with_resolution(weights_sig,y_sig)
if 'gg' in resolution_weighting : 
    print 'weighting Signal with gg resolution '
    weights_sig=preprocessing.weight_signal_with_resolution(weights_sig,y_sig)
    if 'bb' in resolution_weighting : 
        print 'weighting Signal with bb resolution '
        weights_sig=preprocessing.weight_signal_with_resolution_bjet(weights_sig,y_sig)

info_file = open(outputFolder+"info_%s.txt"%outstr,"w") 
info_file.write("\n".join(branch_names))
info_file.write("Resolution weighting : %s\n"%resolution_weighting)
info_file.write("Random seed for shuffling before test/traing split = %d"%random_seed)
info_file.close()


weights_bkg,weights_sig=preprocessing.normalize_process_weights(weights_bkg,y_bkg,weights_sig,y_sig)

X_bkg,y_bkg,weights_bkg = preprocessing.randomize(X_bkg,y_bkg,weights_bkg,seed=random_seed)
X_sig,y_sig,weights_sig = preprocessing.randomize(X_sig,y_sig,weights_sig,seed=random_seed)

print X_bkg.shape
print y_bkg.shape
#bbggTrees have by default signal and CR events, let's be sure that we clean it
X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.clean_signal_events(X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig)
print X_bkg.shape
print y_bkg.shape

y_total_train = preprocessing.get_total_training_sample(y_sig,y_bkg).ravel()
X_total_train = preprocessing.get_total_training_sample(X_sig,X_bkg)

y_total_test = preprocessing.get_total_test_sample(y_sig,y_bkg).ravel()
X_total_test = preprocessing.get_total_test_sample(X_sig,X_bkg)

w_total_train = preprocessing.get_total_training_sample(weights_sig,weights_bkg).ravel()
w_total_test = preprocessing.get_total_test_sample(weights_sig,weights_bkg).ravel()


# In[11]:
from sklearn.externals import joblib

import xgboost as xgb
clf = xgb.XGBClassifier(base_score=0.5, colsample_bylevel=1, colsample_bytree=1,
       gamma=0, learning_rate=0.1, max_delta_step=0, max_depth=5,
					min_child_weight=1e-05, missing=None, n_estimators=1500, nthread=1,#4 the same as in the engine scipt smp 4
       objective='binary:logistic', reg_alpha=0, reg_lambda=0.1,
       scale_pos_weight=1, seed=0, silent=True, subsample=1)


# In[27]:

reload(utils)
param_grid = {'n_estimators': [500,1000,1500,2000],
              'max_depth': [3,5, 10,15], 
              'gamma' : [0,0.15,0.3], 
              'learning_rate': [0.01,0.1, 0.2,0.3],    
              'reg_alpha':[0., 0.01, 0.1],
              'reg_lambda':[1e-2, 5e-2, 0.1, 0.3],
              'min_child_weight':[1e-06,1e-05,1e-04]
              }
#for a small test
#param_grid = {'n_estimators': [500],
 #             'max_depth': [3,5],
#}


optimization.setupJoblib("gcc49_5gb_smp1_all") # create all.q (> 6 hours) with  1 cpu core. 50 jobs, but wait for them to run

clf = optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=200,nJobs=50,weights=w_total_train)
#clf = optimization.optimize_parameters_randomizedCV(clf,X_total_train,y_total_train,param_grid,cvOpt=5,nIter=50,nJobs=1,weights=w_total_train) #local
joblib.dump(clf, os.path.expanduser(outputFolder+'optimizedTraining_'+outstr+'.pkl'), compress=9)

writeInFile=outputFolder+'best_parameters_%s.txt'%outstr
if writeInFile!=None:
    print writeInFile
    outFile = open(writeInFile,"w")
    outFile.write("Best parameter set found on development set:\n")
    outFile.write("%s\n"%clf.best_estimator_)
    outFile.write("Grid scores on a subset of the development set:\n")   
    for params, mean_score, scores in clf.grid_scores_:
        print "%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params)
        outFile.write("%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params))   
    outFile.close() 

print 'It took', time.time()-start_time, 'seconds.'




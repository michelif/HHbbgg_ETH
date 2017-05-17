
# coding: utf-8

# In[5]:

import os
import sys; sys.path.append("~/HHbbgg_ETH/Training/python") # to load packages
import training_utils as utils
import numpy as np
reload(utils)


# In[6]:

ntuples = '20170509'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')
signal = [s for s in files if "NonRes" in s]
background = [s for s in files if "DiPhotonJets" in s]

utils.IO.set_signal_and_background(ntuples,signal,background)

print "using background file:"+utils.IO.backgroundName
print "using signal file:"+utils.IO.signalName


# In[7]:

#normal variables: int, float, vectors...
branch_names = 'leadingJet_bDis,subleadingJet_bDis,CosThetaStar_CS,CosTheta_bb,CosTheta_gg'.split(",")
branch_names = [c.strip() for c in branch_names]
branch_names = (b.replace(" ", "_") for b in branch_names)
branch_names = list(b.replace("-", "_") for b in branch_names)
print branch_names


#tlorentz vectors
branch_names_lorentz = 'diphotonCandidate,dijetCandidate,diHiggsCandidate'.split(",")
branch_names_lorentz = [c.strip() for c in branch_names_lorentz]
branch_names_lorentz = (b.replace(" ", "_") for b in branch_names_lorentz)
branch_names_lorentz = list(b.replace("-", "_") for b in branch_names_lorentz)
print branch_names_lorentz

#variables we want to access in tlorenz vector
branch_names_lorentz_var = 'Pt(),M()'.split(",")
branch_names_lorentz_var = [c.strip() for c in branch_names_lorentz_var]
branch_names_lorentz_var = (b.replace(" ", "_") for b in branch_names_lorentz_var)
branch_names_lorentz_var = list(b.replace("-", "_") for b in branch_names_lorentz_var)
print branch_names_lorentz_var


# In[8]:

import pandas as pd
import root_pandas as rpd
reload(pd)
reload(rpd)
print "name"+utils.IO.signalName

signal_df = rpd.read_root_LorentzVector(utils.IO.signalName,"bbggSelectionTree", columns = branch_names, columns_lorentz=branch_names_lorentz,columns_lorentz_var=branch_names_lorentz_var)
background_df = rpd.read_root_LorentzVector(utils.IO.backgroundName,"bbggSelectionTree", columns = branch_names, columns_lorentz=branch_names_lorentz,columns_lorentz_var=branch_names_lorentz_var)
#example for converting files into csv. useful for plotting
#signal_df.to_csv('/tmp/micheli/prova.csv',',',mode='w')




# In[ ]:

#test the method with the best score

from sklearn import ensemble
utils.preprocessing.adjust_and_compress(signal_df).to_hdf('/tmp/micheli/signal.hd5','sig',compression=9,complib='bzip2',mode='w')
utils.preprocessing.adjust_and_compress(background_df).to_hdf('/tmp/micheli/background.hd5','bkg',compression=9,complib='bzip2',mode='w')

utils.preprocessing.define_process_weight(signal_df,1,1)
utils.preprocessing.define_process_weight(background_df,0,1)

y_sig = signal_df[['proc']]
y_bkg = background_df[['proc']]
y_total_train = utils.preprocessing.get_total_training_sample(y_sig,y_bkg).ravel()


X_sig= np.concatenate([signal_df[['leadingJet_bDis','subleadingJet_bDis']],
                             np.divide(signal_df[['diphotonCandidate.Pt()']],signal_df[['diHiggsCandidate.M()']]),
                             np.divide(signal_df[['dijetCandidate.Pt()']],signal_df[['diHiggsCandidate.M()']]),
                             np.absolute(signal_df[['CosThetaStar_CS']]),
                             np.absolute(signal_df[['CosTheta_bb']]),
                             np.absolute(signal_df[['CosTheta_gg']])],
                             axis=1)

X_bkg = np.concatenate([background_df[['leadingJet_bDis','subleadingJet_bDis']],
                             np.divide(background_df[['diphotonCandidate.Pt()']],background_df[['diHiggsCandidate.M()']]),
                             np.divide(background_df[['dijetCandidate.Pt()']],background_df[['diHiggsCandidate.M()']]),
                             np.absolute(background_df[['CosThetaStar_CS']]),
                             np.absolute(background_df[['CosTheta_bb']]),
                             np.absolute(background_df[['CosTheta_gg']])],
                             axis=1)

X_total_train = utils.preprocessing.get_total_training_sample(pd.DataFrame(X_sig),pd.DataFrame(X_bkg))

print X_total_train

clf = ensemble.GradientBoostingClassifier(max_depth=10,learning_rate=0.1,n_estimators=200,verbose=1)
clf.fit(X_total_train,y_total_train)


X_sig_train = utils.preprocessing.get_training_sample(pd.DataFrame(X_sig))
X_bkg_train = utils.preprocessing.get_training_sample(pd.DataFrame(X_bkg))

X_sig_test = utils.preprocessing.get_test_sample(pd.DataFrame(X_sig))
X_bkg_test = utils.preprocessing.get_test_sample(pd.DataFrame(X_bkg))

Y_pred_sig_train = clf.decision_function(X_sig_train).ravel()
Y_pred_bkg_train = clf.decision_function(X_bkg_train).ravel()
Y_pred_sig_test = clf.decision_function(X_sig_test).ravel()
Y_pred_bkg_test = clf.decision_function(X_bkg_test).ravel()

import matplotlib.pyplot as plt

utils.plotting.plot_classifier_output(clf,X_sig_train,X_bkg_train,X_sig_test,X_bkg_test,"gbOptimized")

#plt.show()


# In[ ]:




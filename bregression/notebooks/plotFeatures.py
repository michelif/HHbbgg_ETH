
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

ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTraining.root" in s] #energy rings tiny sample
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_Large0.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_LargeAll2.root" in s] #energy rings large and proper sample with Jet_e


utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)

#use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_mcPt,Jet_mcFlavour,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR0_mu)/Jet_e,noexpand:(Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut+Jet_energyRing_dR1_mu)/Jet_e,noexpand:(Jet_energyRing_dR2_em+Jet_energyRing_dR2_ch+Jet_energyRing_dR2_neut+Jet_energyRing_dR2_mu)/Jet_e,noexpand:(Jet_energyRing_dR3_em+Jet_energyRing_dR3_ch+Jet_energyRing_dR3_neut+Jet_energyRing_dR3_mu)/Jet_e,noexpand:(Jet_energyRing_dR4_em+Jet_energyRing_dR4_ch+Jet_energyRing_dR4_neut+Jet_energyRing_dR4_mu)/Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em)/Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em)/Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em+Jet_energyRing_dR3_em)/Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em+Jet_energyRing_dR3_em+Jet_energyRing_dR4_em)/Jet_e,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch)/Jet_e,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch)/Jet_e,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch+Jet_energyRing_dR3_ch)/Jet_e,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch+Jet_energyRing_dR3_ch+Jet_energyRing_dR4_ch)/Jet_e,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut)/Jet_e,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut)/Jet_e,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut+Jet_energyRing_dR3_neut)/Jet_e,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut+Jet_energyRing_dR3_neut+Jet_energyRing_dR4_neut)/Jet_e,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu)/Jet_e,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu)/Jet_e,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu+Jet_energyRing_dR3_mu)/Jet_e,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu+Jet_energyRing_dR3_mu+Jet_energyRing_dR4_mu)/Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR0_mu+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut+Jet_energyRing_dR1_mu)/Jet_e'.split(",")
branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_mcPt,Jet_mcFlavour,Jet_rawEnergy,Jet_e,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR0_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut+Jet_energyRing_dR1_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR2_em+Jet_energyRing_dR2_ch+Jet_energyRing_dR2_neut+Jet_energyRing_dR2_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR3_em+Jet_energyRing_dR3_ch+Jet_energyRing_dR3_neut+Jet_energyRing_dR3_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR4_em+Jet_energyRing_dR4_ch+Jet_energyRing_dR4_neut+Jet_energyRing_dR4_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em+Jet_energyRing_dR3_em)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR1_em+Jet_energyRing_dR2_em+Jet_energyRing_dR3_em+Jet_energyRing_dR4_em)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch+Jet_energyRing_dR3_ch)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_ch+Jet_energyRing_dR1_ch+Jet_energyRing_dR2_ch+Jet_energyRing_dR3_ch+Jet_energyRing_dR4_ch)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut+Jet_energyRing_dR3_neut)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_neut+Jet_energyRing_dR1_neut+Jet_energyRing_dR2_neut+Jet_energyRing_dR3_neut+Jet_energyRing_dR4_neut)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu+Jet_energyRing_dR3_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_mu+Jet_energyRing_dR1_mu+Jet_energyRing_dR2_mu+Jet_energyRing_dR3_mu+Jet_energyRing_dR4_mu)/Jet_rawEnergy,noexpand:(Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR0_mu+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut+Jet_energyRing_dR1_mu)/Jet_rawEnergy'.split(",")


target = 'Jet_mcPt/Jet_pt'.split(",")
#cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_id>0) & (Jet_puId > 0)'
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5)'

branch_names = [c.strip() for c in branch_names]
features = [x.replace('noexpand:','') for x in branch_names]
target = [c.strip() for c in target]


import pandas as pd
import root_pandas as rpd


X_features = preprocessing.set_features("tree",branch_names,features,cuts)
X_target = preprocessing.set_target("tree",branch_names,target,cuts)

#X_train_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.)   #0.8
#X_train_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)



import matplotlib.pyplot as plt


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


log_names='Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
plotting.plot_input_variables_reg(X_features,features,log_names,30,'energyRings3_rawEnergy')
plt.show()




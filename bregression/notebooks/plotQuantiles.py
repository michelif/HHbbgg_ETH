
# coding: utf-8

# In[3]:

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


# In[4]:

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

#ttbar= [s for s in files if "20trees_safe" in s] #large statistics
ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings2_forTraining_LargeAll2.root" in s] #energy rings large and proper sample with Jet_e


utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)

for i in range(len(utils.IO.targetName)):        
    print "using target file n."+str(i)+": "+utils.IO.targetName[i]
for i in range(len(utils.IO.featuresName)):        
    print "using features file n."+str(i)+": "+utils.IO.featuresName[i]


# In[5]:

branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_mcPt,Jet_mcFlavour'.split(",")
#branch_names = 'Jet_pt,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPtq,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_e,noexpand:Jet_energyRing_dR0_em/Jet_e,noexpand:Jet_energyRing_dR1_em/Jet_e,noexpand:Jet_energyRing_dR2_em/Jet_e,noexpand:Jet_energyRing_dR3_em/Jet_e,noexpand:Jet_energyRing_dR4_em/Jet_e,noexpand:Jet_energyRing_dR0_neut/Jet_e,noexpand:Jet_energyRing_dR1_neut/Jet_e,noexpand:Jet_energyRing_dR2_neut/Jet_e,noexpand:Jet_energyRing_dR3_neut/Jet_e,noexpand:Jet_energyRing_dR4_neut/Jet_e,noexpand:Jet_energyRing_dR0_ch/Jet_e,noexpand:Jet_energyRing_dR1_ch/Jet_e,noexpand:Jet_energyRing_dR2_ch/Jet_e,noexpand:Jet_energyRing_dR3_ch/Jet_e,noexpand:Jet_energyRing_dR4_ch/Jet_e,Jet_numDaughters_pt03'.split(",")
target = 'Jet_mcPt/Jet_pt'.split(",")
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5)'

branch_names = [c.strip() for c in branch_names]
target = [c.strip() for c in target]

#print branch_names

import pandas as pd
import root_pandas as rpd



#now no need to split in test and training because i am not using testing here
#X_train_target = preprocessing.get_test_sample(pd.DataFrame(X_target),0.)   #0.8
#X_train_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)

import matplotlib.pyplot as plt


pt_regions = '(Jet_mcPt<100),(Jet_mcPt>=100 & Jet_mcPt<300),(Jet_mcPt>=300 & Jet_mcPt<700),(Jet_mcPt>700)'.split(",")
eta_regions_names = '|Jet_eta|<0.5,|Jet_eta|>=0.5 & |Jet_eta|<1.0,|Jet_eta|>=1.0 & |Jet_eta|<1.5,|Jet_eta|>=1.5 & |Jet_eta|<2.0,|Jet_eta|>=2.0'.split(",")
eta_regions = '(Jet_eta<0.5 & Jet_eta>-0.5),((Jet_eta>=0.5 & Jet_eta<1.0) |(Jet_eta<=-0.5 & Jet_eta>-1.0)),(( Jet_eta>=1.0 & Jet_eta<1.5)|(Jet_eta<=-1.0 & Jet_eta>-1.5)),( (Jet_eta>=1.5 & Jet_eta<2.0)|(Jet_eta<=-1.5 & Jet_eta>=-2.0 )),(Jet_eta>=2.0 | Jet_eta<=-2.0)'.split(",")
X_pt_region=[] # list of pandas DataFrame
X_eta_region=[] # list of pandas DataFrame
target_dist = []
target_dist.append('noexpand:Jet_mcPt/Jet_pt')
for region in pt_regions:
    cuts_regions = cuts+'&'+region
    X_pt_region.append(preprocessing.cut_region(utils.IO.featuresName[0],"tree",branch_names,target_dist,cuts_regions))
for region in eta_regions:
    cuts_regions = cuts+'&'+region
    X_eta_region.append(preprocessing.cut_region(utils.IO.featuresName[0],"tree",branch_names,target_dist,cuts_regions))


#plotting.fit_quantiles(X_pt_region,pt_regions,True,400,"Pol3","pt_4point_set6_400bins")
plotting.fit_quantiles(X_eta_region,eta_regions_names,True,400,"Pol3","eta_4point_set6_400bins")


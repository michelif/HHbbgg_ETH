
# coding: utf-8

# In[9]:

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
from sklearn.externals import joblib
import pandas as pd
import root_pandas as rpd
import matplotlib.pyplot as plt
import training_utils as utils
import ROOT
from ROOT import gROOT
import sys


testfile = sys.argv[1]

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

#ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTesting.root" in s] #energy rings large and proper sample with Jet_e
#ttbar= ["../../bregression//output_root/treeScaleResolution20p40p70p04_lin_minmax_full_quantile_regression_alpha.root" ] 
#ttbar= ["../../bregression//output_root/applied_full_subsample09_quantile_regression_alphattbar_RegressionPerJet_heppy_energyRings3_forTesting.root" ] 
ttbar= ["../../bregression//output_root/applied_full_subsample09_quantile_regression_alphaggHHbbgg_%s_RegressionPerJet_heppy_energyRings3_forTraining_Large0.root"%(testfile) ] 
#ttbar= ["../../bregression//output_root/applied_full_subsample09_quantile_regression_alpha%s_RegressionPerJet_heppy_energyRings3_forTraining_LargeAll3.root"%(testfile)]

treeName = 'reducedTree'

utils.IO.add_target(ntuples,ttbar,1)
utils.IO.add_features(ntuples,ttbar,1)

for i in range(len(utils.IO.targetName)):        
    print "using target file n."+str(i)+": "+utils.IO.targetName[i]
for i in range(len(utils.IO.featuresName)):        
    print "using features file n."+str(i)+": "+utils.IO.featuresName[i]



branch_names = 'Jet_pt_reg,Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,noexpand:Jet_mcPt/Jet_pt,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03,nPVs,Jet_leptonPt,b_scale_0207,b_scale_0204,b_res_20p70,b_scale_linear_all,b_scale_04'.split(",") #
features = 'Jet_pt,Jet_eta,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03'.split(",") #
features_cat = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",") #same as Caterina

base_cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt>0) & (Jet_mcPt<6000) & (Jet_pt_reg>0)'

resolution_array = np.linspace(0., 0.4, num=10)
bres_regions = np.array([ 'b_res_20p70>=%0.3f'%resolution_array[i]+'& b_res_20p70<%0.3f'%resolution_array[i+1] for i in range(len(resolution_array)-1)])


branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]
features_cat = [c.strip() for c in features_cat]


region_names =bres_regions 

for i_r,region in enumerate(bres_regions):
    cuts = base_cuts+'&'+region
    print cuts

    data_frame = (rpd.read_root(utils.IO.featuresName[0],treeName, columns = branch_names)).query(cuts)
    X_features = preprocessing.set_features(treeName,branch_names,features,cuts)
    X_features_cat = (preprocessing.set_features(treeName,branch_names,features_cat,cuts))
    X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)
    nTot,dictVar = postprocessing.stackFeaturesReg(data_frame,branch_names,5)
    true_pt = nTot[:,dictVar['Jet_mcPt']]
    predictions_pt_caterina = nTot[:,dictVar['Jet_pt_reg']]
    reco_pt = nTot[:,dictVar['Jet_pt']]
    rel_diff_caterina = true_pt/predictions_pt_caterina
    rel_diff_noreg = true_pt/reco_pt


    outTags = ['quantile_minmax_02-07','quantile_04']
    X_predictions_compare = []
    for num in range(len(outTags)):
        outTag = outTags[num]
        if ('02-07') in outTag : X_pred_data = nTot[:,dictVar['b_scale_0207']]
        if ('02-04') in outTag : X_pred_data = nTot[:,dictVar['b_scale_0204']]
        if ('_04') in outTag : X_pred_data = nTot[:,dictVar['b_scale_04']]
        if ('linear_all') in outTag : X_pred_data = nTot[:,dictVar['b_scale_linear_all']]

        predictions_pt = X_pred_data*nTot[:,dictVar['Jet_pt']]
        rel_diff_regressed = true_pt/predictions_pt

        X_predictions_compare.append(rel_diff_regressed)

    comparison_tags = outTags
    if testfile=='ZHbbll' : 
        samplename = testfile
        outTagComparison = 'Sumsample09er_'+testfile + region_names[i_r]
    elif testfile!='ttbar' : 
        samplename = 'DiHiggs '+testfile
        outTagComparison = 'Sumsample09er_DiHiggs'+testfile + region_names[i_r]
    else : 
        samplename = 'ttbar'
        outTagComparison = 'Sumsample09er_ttbar'+ region_names[i_r]
    style=False 
    if i_r==0 : style=True
    plotting.plot_regions(X_predictions_compare,comparison_tags,style,50,outTagComparison,False,region_names[i_r],samplename)


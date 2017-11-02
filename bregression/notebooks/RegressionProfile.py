
# coding: utf-8

# In[1]:

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



# In[2]:

import pandas as pd
import root_pandas as rpd
import ROOT
from ROOT import TH2D, TProfile
from ROOT import gROOT
from ROOT import gStyle

input_file = '~/HHbbgg_ETH_devel/bregression//output_root/output_CaterinaUpd_trainedall_testbttbar_RegressionPerJet_heppy_forTesting_nPVs_caterinaReg.root'

branch_names = 'RegressedFactor,noexpand:Jet_mcPt/RegressedFactor,noexpand:Jet_mcPt/Jet_pt_regNew,Jet_pt,Jet_pt_regNew,Jet_pt_reg,noexpand:Jet_mcPt/Jet_pt,Jet_eta,noexpand:fabs(Jet_eta),Jet_corr,Jet_mcPt,Jet_mcFlavour,dR,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_chMult,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5)'
features = 'Jet_pt,Jet_eta,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL'.split(",")


branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]

data_frame = (rpd.read_root(input_file,"reducedTree", columns = branch_names)).query(cuts)

# fill 2D histograms and profiles with Jet_genpt/Jet_regpt and inputs 
#declare all hists
histograms=[]
profiles=[]
profiles_noReg=[]
profiles_Cat=[]
input_tfile = ROOT.TFile.Open(input_file)
tree = input_tfile.Get("reducedTree")
for num in range(0,len(features)):
    hist_name = "hist_"+features[num]
    profile_name = "profile_"+features[num]
    profile_name_noReg = "profile_noReg_"+features[num]
    profile_name_Cat = "profile_Cat_"+features[num]
    max_x=max(data_frame[features[num]]*0.8)
    min_x=min(data_frame[features[num]])
    histograms.append( TH2D(hist_name,hist_name,100,min_x,max_x,100,0.5,1.5) )
    profiles.append(TProfile(profile_name,profile_name,100,min_x,max_x,0.5,1.5))
    profiles_noReg.append(TProfile(profile_name_noReg,profile_name_noReg,100,min_x,max_x,0.5,1.5))
    profiles_Cat.append(TProfile(profile_name_Cat,profile_name_Cat,100,min_x,max_x,0.5,1.5))
    histograms[num].GetXaxis().SetTitle(features[num])
    profiles[num].GetXaxis().SetTitle(features[num])
    histograms[num].GetYaxis().SetTitle("p_{T}^{gen}/p_{T}^{reco}")
 #   for jet in range(0,len(data_frame[features[num]])):
  #      histograms[num].Fill(data_frame[features[num]],data_frame['Jet_mcPt/RegressedFactor'])
  #      profiles[num].Fill(data_frame[features[num]],data_frame['Jet_mcPt/RegressedFactor'])
    draw_line = 'Jet_mcPt/RegressedFactor:'+features[num]+'>>'+hist_name
    draw_line_profile = 'Jet_mcPt/RegressedFactor:'+features[num]+'>>'+profile_name
    draw_line_profile_noReg = 'Jet_mcPt/Jet_pt:'+features[num]+'>>'+profile_name_noReg
    draw_line_profile_Cat = 'Jet_mcPt/Jet_pt_regNew:'+features[num]+'>>'+profile_name_Cat
    tree.Draw(draw_line,cuts)
    tree.Draw(draw_line_profile,cuts)
    tree.Draw(draw_line_profile_noReg,cuts)
    tree.Draw(draw_line_profile_Cat,cuts)



# In[4]:

import plotting_utils as plotting


reload(plotting)

gROOT.SetBatch(True)
gROOT.ProcessLineSync(".x /mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/scripts/setTDRStyle.C")
gROOT.ForceStyle()
gStyle.SetPadTopMargin(0.06)
gStyle.SetPadRightMargin(0.04)
gStyle.SetPadLeftMargin(0.15)
        
for i in range(0,len(features)):
	plotting.plot_response(histograms[i],profiles[i],profiles_noReg[i],profiles_Cat[i],False)


# In[ ]:





##################################################
##################################################
## Configuration parameters to run MakeStack.py ##
##################################################
##################################################

doBlind = False
doShape = False
doSignalRegion = False
doJetCR = False

useJsonWeighting=False
useJsonWeightingHeppy=True

isPhoCR = False
addHiggs = False
hideData = False
addbbH = False
dyjets = False

#do pile up reweighting
doPUweight = True

year = ""

doSignal = True

hideStat = True

#btagging working poing
# 0.46 - loose
# 0.80 - medium
# 0.935 - tight
BTAG = 0.

#Luminosity to normalize backgrounds
lumi = 35087#pb
#lumi = 0.35870#pb
MCSF = 1.0
#List of datasets to be used (cross section information defined there)
#data_file = open("datasets/datasets80X_Moriond_onlyNRSM.json")
#data_file = open("datasets/datasets80X_Moriond_onlyNRSM_separateGJ.json")
data_file = open("datasets/datasets_Validation.json")

#number of bins in histograms
nbin = 30

#plots will be saved in dirName
prefix = ""
dirSuffix = "bRegValidation_20180124_triggers"
dirPrefix = "/afs/cern.ch/user/n/nchernya/www/HHbbgg/Validation/24_01_18/"
dirName = dirPrefix + dirSuffix

#Location of root files for each invidivual samples. Name of the root files is defined in datasets/datasets(76).json
higgsoLocation="/afs/cern.ch/work/n/nchernya/public/Validation_2018/"
bkgLocation="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/ValidationPlots/root/"
dataLocation="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/ValidationPlots/root/"
signalLocation="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/ValidationPlots/root/"

#plots to be made
plots = []

jet_names=["Leading","Subleading"]
jet_idx=["leadJet_idx","subleadJet_idx"]
#jet_idx=["0","1"]
xmax_rings=1.
for i_jet in range(0,2):  #loop over leading and subleading jets
 for i in range(0,5): #loop over jet energy Rings
   if (i>=3) : xmax_rings=0.5
   plots.append(["%s_Jet_energyRing_dR%d_em"%(jet_names[i_jet],i), "Jet_energyRing_dR%d_em[%s]/Jet_rawEnergy[%s]"%(i,jet_idx[i_jet],jet_idx[i_jet]), "%s Jet energy Ring dR%d em "%(jet_names[i_jet],i), 100, 0, xmax_rings])
   plots.append(["%s_Jet_energyRing_dR%d_ch"%(jet_names[i_jet],i), "Jet_energyRing_dR%d_ch[%s]/Jet_rawEnergy[%s]"%(i,jet_idx[i_jet],jet_idx[i_jet]), "%s Jet energy Ring dR%d ch "%(jet_names[i_jet],i), 100, 0, xmax_rings])
   plots.append(["%s_Jet_energyRing_dR%d_neut"%(jet_names[i_jet],i), "Jet_energyRing_dR%d_neut[%s]/Jet_rawEnergy[%s]"%(i,jet_idx[i_jet],jet_idx[i_jet]), "%s Jet energy Ring dR%d neut "%(jet_names[i_jet],i), 100, 0, xmax_rings])
   plots.append(["%s_Jet_energyRing_dR%d_mu"%(jet_names[i_jet],i), "Jet_energyRing_dR%d_mu[%s]/Jet_rawEnergy[%s]"%(i,jet_idx[i_jet],jet_idx[i_jet]), "%s Jet energy Ring dR%d mu "%(jet_names[i_jet],i), 100, 0, xmax_rings])
 plots.append(["%s_Jet_numDaughters_pt03"%(jet_names[i_jet]), "Jet_numDaughters_pt03[%s]"%(jet_idx[i_jet]), "%s Jet # of Daughters"%(jet_names[i_jet]), 50, 0, 50])
 plots.append(["%s_Jet_pt"%(jet_names[i_jet]), "Jet_pt[%s]"%(jet_idx[i_jet]), "%s Jet p_{T} [GeV]"%jet_names[i_jet], 100, 30, 600])
 plots.append(["%s_Jet_eta"%(jet_names[i_jet]), "Jet_eta[%s]"%(jet_idx[i_jet]), "%s Jet #eta"%jet_names[i_jet], 50, -2.5, 2.5])
# plots.append(["%s_Jet_mt"%(jet_names[i_jet]), "Jet_mt[%s]"%(jet_idx[i_jet]), "%s Jet m_{T} [GeV]"%jet_names[i_jet], 100, 30, 600])
 plots.append(["%s_Jet_leadTrackPt"%(jet_names[i_jet]), "Jet_leadTrackPt[%s]"%(jet_idx[i_jet]), "%s Jet leading track p_{T} [GeV]"%jet_names[i_jet], 20, 0, 100])
 plots.append(["%s_Jet_leptonPtRel"%(jet_names[i_jet]), "Jet_leptonPtRel[%s]"%(jet_idx[i_jet]), "%s Jet lepton relative p_{T} [GeV]"%jet_names[i_jet], 20, 0, 10])
 plots.append(["%s_Jet_leptonDeltaR"%(jet_names[i_jet]), "Jet_leptonDeltaR[%s]"%(jet_idx[i_jet]), "%s Jet lepton dR [GeV]"%jet_names[i_jet], 14, 0,0.14])
 plots.append(["%s_Jet_neHEF"%(jet_names[i_jet]), "Jet_neHEF[%s]"%(jet_idx[i_jet]), "%s Jet neutral HEF p_{T} [GeV]"%jet_names[i_jet], 50, 0,1])
 plots.append(["%s_Jet_neEmEF"%(jet_names[i_jet]), "Jet_neEmEF[%s]"%(jet_idx[i_jet]), "%s Jet neutral EmEF p_{T} [GeV]"%jet_names[i_jet], 50, 0,1])
 plots.append(["%s_Jet_vtxPt"%(jet_names[i_jet]), "Jet_vtxPt[%s]"%(jet_idx[i_jet]), "%s Jet vertex p_{T} [GeV]"%jet_names[i_jet], 50, 0,50])
 plots.append(["%s_Jet_vtxMass"%(jet_names[i_jet]), "Jet_vtxMass[%s]"%(jet_idx[i_jet]), "%s Jet vertex mass [GeV]"%jet_names[i_jet], 20, 0,5])
 plots.append(["%s_Jet_vtx3DVal"%(jet_names[i_jet]), "Jet_vtx3DVal[%s]"%(jet_idx[i_jet]), "%s Jet vertex 3dL "%jet_names[i_jet], 20, 0,1])
 plots.append(["%s_Jet_vtx3DSig"%(jet_names[i_jet]), "Jet_vtx3DSig[%s]"%(jet_idx[i_jet]), "%s Jet vertex 3deL "%jet_names[i_jet], 20, 0,1])
 plots.append(["%s_Jet_vtxNtracks"%(jet_names[i_jet]), "Jet_vtxNtracks[%s]"%(jet_idx[i_jet]), "%s Jet vertex # tracks "%jet_names[i_jet], 20, 0,20])

plots.append(["DiJet_mass", "DiJet_mass", "m(jj) [GeV]", 20, 0, 400])
plots.append(["Zll_mass", "Zll_mass", "m(ll) [GeV]", 20, 0, 400])
plots.append(["rho", "rho", "rho", 40, 0, 40])
plots.append(["nPVs", "nPVs", "nPVs", 40, 0, 40])
plots.append(["met_pt", "met_pt", "MET p_{T} [GeV]", 50, 0, 500])

#cuts to be used to make plots
#Cut = "(Jet_eta[0]<2.5 && Jet_pt[0]>35 && Jet_pt[0]<300 && ((HLT_BIT_HLT_IsoMu24_v==1) || (HLT_BIT_HLT_IsoTkMu24_v==1)))"
Cut = "(met_pt>50 && ((HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v==1) || ( HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v==1) || (HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v==1) || (HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v==1) )) "

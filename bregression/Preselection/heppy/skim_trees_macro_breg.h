//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 22 18:04:14 2018 by ROOT version 5.34/36
// from TChain tree/
//////////////////////////////////////////////////////////

#ifndef skim_trees_macro_breg_h
#define skim_trees_macro_breg_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class skim_trees_macro_breg {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
	TH1F*	Count;
	TH1F*	CountPosWeight;
	TH1F*	CountNegWeight;
	TH1F*	CountWeighted;
	TH1F* CountFullWeighted; 
	TH1F* CountWeightedLHEWeightScale;
	TH1F* CountWeightedLHEWeightPdf;
   Int_t           fCurrent; //!current Tree number in a TChain
	TString file_name;

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   Int_t           isData;
   Float_t         xsec;
   Float_t         puWeight;
   Float_t         nTrueInt;
   Float_t         genWeight;
   Float_t         puWeightUp;
   Float_t         puWeightDown;
   Float_t         json;
   Float_t         json_silver;
   Float_t         nPU0;
   Float_t         nPVs;
   Float_t         Vtype;
   Float_t         VtypeSim;
   Float_t         VMt;
   Float_t         HVdPhi;
   Float_t         fakeMET_sumet;
   Int_t           bx;
   Float_t         caloMetPt;
   Float_t         caloMetPhi;
   Float_t         rho;
   Float_t         rhoN;
   Float_t         rhoCHPU;
   Float_t         rhoCentral;
   Float_t         deltaR_jj;
   Float_t         lheNj;
   Float_t         lheNb;
   Float_t         lheNc;
   Float_t         lheNg;
   Float_t         lheNl;
   Float_t         lheV_pt;
   Float_t         lheHT;
   Int_t           genTTHtoTauTauDecayMode;
   Float_t         ttCls;
   Float_t         heavyFlavourCategory;
   Float_t         mhtJet30;
   Float_t         mhtPhiJet30;
   Float_t         htJet30;
   Float_t         met_sig;
   Float_t         met_covXX;
   Float_t         met_covXY;
   Float_t         met_covYY;
   Float_t         met_rawpt;
   Float_t         metPuppi_pt;
   Float_t         metPuppi_phi;
   Float_t         metPuppi_rawpt;
   Float_t         metType1p2_pt;
   Float_t         tkMet_pt;
   Float_t         tkMet_phi;
   Float_t         isrJetVH;
   Float_t         simPrimaryVertex_z;
   Float_t         genHiggsDecayMode;
   Float_t         triggerEmulationWeight;
   Float_t         btagWeightCSV_down_cferr1;
   Float_t         btagWeightCMVAV2_down_hfstats1;
   Float_t         btagWeightCMVAV2_down_hfstats2;
   Float_t         btagWeightCSV_down_cferr2;
   Float_t         btagWeightCSV_down_jes;
   Float_t         btagWeightCSV_down_lf;
   Float_t         btagWeightCSV_up_lf;
   Float_t         btagWeightCSV_down_lfstats2;
   Float_t         btagWeightCSV_down_lfstats1;
   Float_t         btagWeightCSV_down_hf;
   Float_t         btagWeightCSV_up_lfstats1;
   Float_t         btagWeightCMVAV2_down_lf;
   Float_t         btagWeightCSV_up_lfstats2;
   Float_t         btagWeightCSV;
   Float_t         btagWeightCSV_up_cferr2;
   Float_t         btagWeightCSV_up_cferr1;
   Float_t         btagWeightCSV_up_hf;
   Float_t         btagWeightCMVAV2_down_hf;
   Float_t         btagWeightCMVAV2_up_lfstats2;
   Float_t         btagWeightCMVAV2_up_hfstats2;
   Float_t         btagWeightCMVAV2_up_hfstats1;
   Float_t         btagWeightCMVAV2;
   Float_t         btagWeightCMVAV2_up_lfstats1;
   Float_t         btagWeightCMVAV2_down_cferr2;
   Float_t         btagWeightCMVAV2_up_hf;
   Float_t         btagWeightCMVAV2_down_cferr1;
   Float_t         btagWeightCSV_up_jes;
   Float_t         btagWeightCMVAV2_up_jes;
   Float_t         btagWeightCMVAV2_up_lf;
   Float_t         btagWeightCSV_down_hfstats2;
   Float_t         btagWeightCSV_down_hfstats1;
   Float_t         btagWeightCMVAV2_up_cferr1;
   Float_t         btagWeightCMVAV2_up_cferr2;
   Float_t         btagWeightCMVAV2_down_lfstats1;
   Float_t         btagWeightCMVAV2_down_lfstats2;
   Float_t         btagWeightCSV_up_hfstats1;
   Float_t         btagWeightCMVAV2_down_jes;
   Float_t         btagWeightCSV_up_hfstats2;
   Float_t         ZllKinFit_corrJERUp_mass;
   Int_t           ZllKinFit_status;
   Int_t           ZllKinFit_corrJERDown_status;
   Int_t           ZllKinFit_corrJECDown_status;
   Int_t           ZllKinFit_njet;
   Int_t           ZllKinFit_corrJECDown_njet;
   Int_t           ZllKinFit_corrJERUp_njet;
   Int_t           ZllKinFit_corrJERUp_status;
   Int_t           ZllKinFit_corrJECUp_njet;
   Float_t         ZllKinFit_mass;
   Float_t         ZllKinFit_corrJERDown_mass;
   Float_t         ZllKinFit_corrJECUp_mass;
   Float_t         ZllKinFit_corrJECDown_mass;
   Int_t           ZllKinFit_corrJECUp_status;
   Int_t           ZllKinFit_corrJERDown_njet;
   Int_t           Flag_HBHENoiseIsoFilter;
   Int_t           Flag_EcalDeadCellTriggerPrimitiveFilter;
   Int_t           Flag_trkPOG_manystripclus53X;
   Int_t           Flag_ecalLaserCorrFilter;
   Int_t           Flag_trkPOG_toomanystripclus53X;
   Int_t           Flag_hcalLaserEventFilter;
   Int_t           Flag_muonBadTrackFilter;
   Int_t           Flag_trkPOG_logErrorTooManyClusters;
   Int_t           Flag_trkPOGFilters;
   Int_t           Flag_trackingFailureFilter;
   Int_t           Flag_CSCTightHaloFilter;
   Int_t           Flag_HBHENoiseFilter;
   Int_t           Flag_chargedHadronTrackResolutionFilter;
   Int_t           Flag_GlobalTightHalo2016Filter;
   Int_t           Flag_goodVertices;
   Int_t           Flag_METFilters;
   Int_t           Flag_CSCTightHalo2015Filter;
   Int_t           Flag_eeBadScFilter;
   Int_t           EX_MUON;
   Int_t           HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v;
   Int_t           HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMET170_NoiseCleaned_v;
   Int_t           HLT_BIT_HLT_PFMET170_HBHE_BeamHaloCleaned_v;
   Int_t           HLT_BIT_HLT_PFMET170_HBHECleaned_v;
   Int_t           HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v;
   Int_t           HLT_BIT_HLT_PFHT350_PFMET100_v;
   Int_t           HLT_ZnnHbbAll;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v;
   Int_t           HLT_VBFHbbLowLumi;
   Int_t           HLT_BIT_HLT_PFHT750_4JetPt50_v;
   Int_t           HLT_BIT_HLT_PFHT800_v;
   Int_t           HLT_BIT_HLT_PFHT900_v;
   Int_t           HLT_BIT_HLT_PFJet40_v;
   Int_t           HLT_BIT_HLT_PFJet60_v;
   Int_t           HLT_BIT_HLT_PFJet80_v;
   Int_t           HLT_BIT_HLT_PFJet140_v;
   Int_t           HLT_BIT_HLT_PFJet200_v;
   Int_t           HLT_BIT_HLT_PFJet260_v;
   Int_t           HLT_BIT_HLT_PFJet320_v;
   Int_t           HLT_BIT_HLT_PFJet400_v;
   Int_t           HLT_BIT_HLT_PFJet450_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve40_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve60_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve80_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve140_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve200_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve260_v;
   Int_t           HLT_BIT_HLT_DiPFJetAve320_v;
   Int_t           HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v;
   Int_t           HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v;
   Int_t           HLT_hadronic;
   Int_t           HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v;
   Int_t           HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v;
   Int_t           HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v;
   Int_t           HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v;
   Int_t           HLT_BIT_HLT_AK8PFJet360_TrimMass30_v;
   Int_t           HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v;
   Int_t           HLT_HH4bAll;
   Int_t           HLT_BIT_HLT_Mu24_eta2p1_v;
   Int_t           HLT_BIT_HLT_TkMu24_eta2p1_v;
   Int_t           HLT_BIT_HLT_IsoMu27_v;
   Int_t           HLT_BIT_HLT_IsoTkMu27_v;
   Int_t           HLT_BIT_HLT_IsoTkMu24_v;
   Int_t           HLT_BIT_HLT_TkMu27_v;
   Int_t           HLT_BIT_HLT_Mu27_v;
   Int_t           HLT_BIT_HLT_IsoMu20_v;
   Int_t           HLT_BIT_HLT_Mu20_v;
   Int_t           HLT_BIT_HLT_TkMu20_v;
   Int_t           HLT_BIT_HLT_IsoTkMu20_v;
   Int_t           HLT_BIT_HLT_IsoMu18_v;
   Int_t           HLT_BIT_HLT_IsoTkMu18_v;
   Int_t           HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v;
   Int_t           HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v;
   Int_t           HLT_BIT_HLT_Mu16_eta2p1_MET30_v;
   Int_t           HLT_BIT_HLT_PFMET120_Mu5_v;
   Int_t           HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v;
   Int_t           HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;
   Int_t           HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;
   Int_t           HLT_WmnHbbAll;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_ZeeHbbLowLumi;
   Int_t           HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v;
   Int_t           HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v;
   Int_t           HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v;
   Int_t           HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele27_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v;
   Int_t           HLT_BIT_HLT_Ele25_WPTight_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;
   Int_t           HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v;
   Int_t           HLT_WenHbbAll;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v;
   Int_t           HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v;
   Int_t           HLT_WtaunHbbAll;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v;
   Int_t           HLT_ZeeHbbAll;
   Int_t           HLT_ttH_SL_el;
   Int_t           HLT_WtaunHbbLowLumi;
   Int_t           HLT_WmnHbbLowLumi;
   Int_t           HLT_ZeeHbbHighLumi;
   Int_t           HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v;
   Int_t           HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v;
   Int_t           HLT_ttH_FH;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v;
   Int_t           HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v;
   Int_t           HLT_VBFHbbHighLumi;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;
   Int_t           HLT_ttH_DL_elmu;
   Int_t           HLT_ttH_DL_elel;
   Int_t           HLT_BIT_HLT_IsoMu22_v;
   Int_t           HLT_BIT_HLT_IsoMu22_eta2p1_v;
   Int_t           HLT_BIT_HLT_IsoMu24_v;
   Int_t           HLT_BIT_HLT_IsoTkMu22_v;
   Int_t           HLT_BIT_HLT_IsoTkMu22_eta2p1_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;
   Int_t           HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v;
   Int_t           HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;
   Int_t           HLT_BIT_HLT_TripleMu_12_10_5_v;
   Int_t           HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v;
   Int_t           HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v;
   Int_t           HLT_BIT_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v;
   Int_t           HLT_BIT_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v;
   Int_t           HLT_BIT_HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v;
   Int_t           HLT_BIT_HLT_VLooseIsoPFTau140_eta2p1_v;
   Int_t           HLT_ttH_htt;
   Int_t           HLT_BIT_HLT_PFHT450_SixJet40_v;
   Int_t           HLT_BIT_HLT_PFHT400_SixJet30_v;
   Int_t           HLT_ttH_FH_prescaled;
   Int_t           HLT_ZnnHbb;
   Int_t           HLT_ttH_DL_mumu;
   Int_t           HLT_ZmmHbbLowLumi;
   Int_t           HLT_BIT_HLT_IsoMu24_eta2p1_v;
   Int_t           HLT_WmnHbbHighLumi;
   Int_t           HLT_BIT_HLT_Mu17_TkMu8_DZ_v;
   Int_t           HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v;
   Int_t           HLT_ZmmHbbAll;
   Int_t           HLT_ttH_SL_mu;
   Int_t           HLT_WtaunHbbHighLumi;
   Int_t           HLT_WenHbbHighLumi;
   Int_t           HLT_HH4bLowLumi;
   Int_t           HLT_ZmmHbbHighLumi;
   Int_t           HLT_BIT_HLT_QuadPFJet_VBF_v;
   Int_t           HLT_BIT_HLT_L1_TripleJet_VBF_v;
   Int_t           HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v;
   Int_t           HLT_VBFHbbAll;
   Int_t           HLT_BIT_HLT_Mu3_PFJet40_v;
   Int_t           HLT_BIT_HLT_Mu8_v;
   Int_t           HLT_BIT_HLT_Mu17_v;
   Int_t           HLT_BIT_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v;
   Int_t           HLT_BIT_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v;
   Int_t           HLT_BIT_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v;
   Int_t           HLT_ttH_htt_lepFakeBgr;
   Int_t           HLT_WenHbbLowLumi;
   Int_t           HLT_HH4bHighLumi;
   Float_t         l1MHT_pt;
   Float_t         l1MHT_phi;
   Float_t         HCMVAV2_reg_corrJECDown_pt;
   Float_t         HCMVAV2_reg_corrJECDown_eta;
   Float_t         HCMVAV2_reg_corrJECDown_phi;
   Float_t         HCMVAV2_reg_corrJECDown_mass;
   Float_t         HCMVAV2_reg_corrJERDown_pt;
   Float_t         HCMVAV2_reg_corrJERDown_eta;
   Float_t         HCMVAV2_reg_corrJERDown_phi;
   Float_t         HCMVAV2_reg_corrJERDown_mass;
   Float_t         l1MET_pt;
   Float_t         l1MET_phi;
   Float_t         V_pt;
   Float_t         V_eta;
   Float_t         V_phi;
   Float_t         V_mass;
   Float_t         H_reg_pt;
   Float_t         H_reg_eta;
   Float_t         H_reg_phi;
   Float_t         H_reg_mass;
   Float_t         HCSV_reg_corrJERDown_pt;
   Float_t         HCSV_reg_corrJERDown_eta;
   Float_t         HCSV_reg_corrJERDown_phi;
   Float_t         HCSV_reg_corrJERDown_mass;
   Float_t         HCSV_pt;
   Float_t         HCSV_eta;
   Float_t         HCSV_phi;
   Float_t         HCSV_mass;
   Float_t         l1HT_pt;
   Float_t         l1HT_phi;
   Float_t         fakeMET_pt;
   Float_t         fakeMET_eta;
   Float_t         fakeMET_phi;
   Float_t         fakeMET_mass;
   Float_t         HCSV_reg_corrJERUp_pt;
   Float_t         HCSV_reg_corrJERUp_eta;
   Float_t         HCSV_reg_corrJERUp_phi;
   Float_t         HCSV_reg_corrJERUp_mass;
   Float_t         HCMVAV2_reg_corrJERUp_pt;
   Float_t         HCMVAV2_reg_corrJERUp_eta;
   Float_t         HCMVAV2_reg_corrJERUp_phi;
   Float_t         HCMVAV2_reg_corrJERUp_mass;
   Float_t         HCSV_reg_corrJECUp_pt;
   Float_t         HCSV_reg_corrJECUp_eta;
   Float_t         HCSV_reg_corrJECUp_phi;
   Float_t         HCSV_reg_corrJECUp_mass;
   Float_t         met_shifted_UnclusteredEnUp_pt;
   Float_t         met_shifted_UnclusteredEnUp_phi;
   Float_t         met_shifted_UnclusteredEnUp_sumEt;
   Float_t         met_shifted_UnclusteredEnDown_pt;
   Float_t         met_shifted_UnclusteredEnDown_phi;
   Float_t         met_shifted_UnclusteredEnDown_sumEt;
   Float_t         HCSV_reg_pt;
   Float_t         HCSV_reg_eta;
   Float_t         HCSV_reg_phi;
   Float_t         HCSV_reg_mass;
   Float_t         H_reg_corrJERUp_pt;
   Float_t         H_reg_corrJERUp_eta;
   Float_t         H_reg_corrJERUp_phi;
   Float_t         H_reg_corrJERUp_mass;
   Float_t         H_reg_corrJECUp_pt;
   Float_t         H_reg_corrJECUp_eta;
   Float_t         H_reg_corrJECUp_phi;
   Float_t         H_reg_corrJECUp_mass;
   Float_t         HCMVAV2_reg_pt;
   Float_t         HCMVAV2_reg_eta;
   Float_t         HCMVAV2_reg_phi;
   Float_t         HCMVAV2_reg_mass;
   Float_t         H_pt;
   Float_t         H_eta;
   Float_t         H_phi;
   Float_t         H_mass;
   Int_t           softActivityVH_njets2;
   Int_t           softActivityVH_njets5;
   Int_t           softActivityVH_njets10;
   Float_t         softActivityVH_HT;
   Float_t         met_shifted_JetResUp_pt;
   Float_t         met_shifted_JetResUp_phi;
   Float_t         met_shifted_JetResUp_sumEt;
   Float_t         met_pt;
   Float_t         met_eta;
   Float_t         met_phi;
   Float_t         met_mass;
   Float_t         met_sumEt;
   Float_t         met_rawPt;
   Float_t         met_rawPhi;
   Float_t         met_rawSumEt;
   Float_t         met_genPt;
   Float_t         met_genPhi;
   Float_t         met_genEta;
   Float_t         met_shifted_JetEnUp_pt;
   Float_t         met_shifted_JetEnUp_phi;
   Float_t         met_shifted_JetEnUp_sumEt;
   Float_t         met_shifted_JetEnDown_pt;
   Float_t         met_shifted_JetEnDown_phi;
   Float_t         met_shifted_JetEnDown_sumEt;
   Float_t         met_shifted_MuonEnUp_pt;
   Float_t         met_shifted_MuonEnUp_phi;
   Float_t         met_shifted_MuonEnUp_sumEt;
   Float_t         met_shifted_MuonEnDown_pt;
   Float_t         met_shifted_MuonEnDown_phi;
   Float_t         met_shifted_MuonEnDown_sumEt;
   Float_t         met_shifted_ElectronEnUp_pt;
   Float_t         met_shifted_ElectronEnUp_phi;
   Float_t         met_shifted_ElectronEnUp_sumEt;
   Float_t         met_shifted_ElectronEnDown_pt;
   Float_t         met_shifted_ElectronEnDown_phi;
   Float_t         met_shifted_ElectronEnDown_sumEt;
   Float_t         met_shifted_TauEnUp_pt;
   Float_t         met_shifted_TauEnUp_phi;
   Float_t         met_shifted_TauEnUp_sumEt;
   Float_t         met_shifted_TauEnDown_pt;
   Float_t         met_shifted_TauEnDown_phi;
   Float_t         met_shifted_TauEnDown_sumEt;
   Float_t         l1ET_pt;
   Float_t         l1ET_phi;
   Int_t           softActivityEWK_njets2;
   Int_t           softActivityEWK_njets5;
   Int_t           softActivityEWK_njets10;
   Float_t         softActivityEWK_HT;
   Float_t         met_shifted_JetResDown_pt;
   Float_t         met_shifted_JetResDown_phi;
   Float_t         met_shifted_JetResDown_sumEt;
   Float_t         HaddJetsdR08_pt;
   Float_t         HaddJetsdR08_eta;
   Float_t         HaddJetsdR08_phi;
   Float_t         HaddJetsdR08_mass;
   Float_t         H_reg_corrJERDown_pt;
   Float_t         H_reg_corrJERDown_eta;
   Float_t         H_reg_corrJERDown_phi;
   Float_t         H_reg_corrJERDown_mass;
   Float_t         HCMVAV2_reg_corrJECUp_pt;
   Float_t         HCMVAV2_reg_corrJECUp_eta;
   Float_t         HCMVAV2_reg_corrJECUp_phi;
   Float_t         HCMVAV2_reg_corrJECUp_mass;
   Int_t           softActivity_njets2;
   Int_t           softActivity_njets5;
   Int_t           softActivity_njets10;
   Float_t         softActivity_HT;
   Float_t         HCSV_reg_corrJECDown_pt;
   Float_t         HCSV_reg_corrJECDown_eta;
   Float_t         HCSV_reg_corrJECDown_phi;
   Float_t         HCSV_reg_corrJECDown_mass;
   Float_t         HCMVAV2_pt;
   Float_t         HCMVAV2_eta;
   Float_t         HCMVAV2_phi;
   Float_t         HCMVAV2_mass;
   Float_t         H_reg_corrJECDown_pt;
   Float_t         H_reg_corrJECDown_eta;
   Float_t         H_reg_corrJECDown_phi;
   Float_t         H_reg_corrJECDown_mass;
   Int_t           npileUpVertex_ptHat;
   Float_t         pileUpVertex_ptHat[5];   //[npileUpVertex_ptHat]
   Int_t           ntrgObjects_hltMET70;
   Int_t           ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet;
   Int_t           ntrgObjects_hltBTagPFCSVp11DoubleWithMatching;
   Int_t           nGenLepFromTop;
   Int_t           GenLepFromTop_pdgId[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_pt[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_eta[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_phi[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_mass[2];   //[nGenLepFromTop]
   Float_t         GenLepFromTop_charge[2];   //[nGenLepFromTop]
   Int_t           GenLepFromTop_status[2];   //[nGenLepFromTop]
   Int_t           GenLepFromTop_isPromptHard[2];   //[nGenLepFromTop]
   Int_t           najidxaddJetsdR08;
   Int_t           ajidxaddJetsdR08[8];   //[najidxaddJetsdR08]
   Int_t           nSubjetCA15softdrop;
   Float_t         SubjetCA15softdrop_pt[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_eta[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_phi[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_mass[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_btag[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_jetID[10];   //[nSubjetCA15softdrop]
   Float_t         SubjetCA15softdrop_fromFJ[10];   //[nSubjetCA15softdrop]
   Int_t           ntrgObjects_hltIsoMu20;
   Float_t         trgObjects_hltIsoMu20_pt[2];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_eta[2];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_phi[2];   //[ntrgObjects_hltIsoMu20]
   Float_t         trgObjects_hltIsoMu20_mass[2];   //[ntrgObjects_hltIsoMu20]
   Int_t           naJCMVAV2idx;
   Int_t           aJCMVAV2idx[8];   //[naJCMVAV2idx]
   Int_t           ntrgObjects_hltQuadCentralJet30;
   Int_t           nl1EGammas;
   Float_t         l1EGammas_pt[1];   //[nl1EGammas]
   Float_t         l1EGammas_eta[1];   //[nl1EGammas]
   Float_t         l1EGammas_phi[1];   //[nl1EGammas]
   Float_t         l1EGammas_qual[1];   //[nl1EGammas]
   Float_t         l1EGammas_iso[1];   //[nl1EGammas]
   Int_t           nhJidx_sortcsv;
   Int_t           hJidx_sortcsv[2];   //[nhJidx_sortcsv]
   Int_t           nprimaryVertices;
   Float_t         primaryVertices_x[4];   //[nprimaryVertices]
   Float_t         primaryVertices_y[4];   //[nprimaryVertices]
   Float_t         primaryVertices_z[4];   //[nprimaryVertices]
   Float_t         primaryVertices_isFake[4];   //[nprimaryVertices]
   Float_t         primaryVertices_ndof[4];   //[nprimaryVertices]
   Float_t         primaryVertices_Rho[4];   //[nprimaryVertices]
   Float_t         primaryVertices_score[4];   //[nprimaryVertices]
   Int_t           naJCidx;
   Int_t           aJCidx[8];   //[naJCidx]
   Int_t           nSubjetCA15softdropz2b1;
   Float_t         SubjetCA15softdropz2b1_pt[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_eta[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_phi[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_mass[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_btag[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_jetID[10];   //[nSubjetCA15softdropz2b1]
   Float_t         SubjetCA15softdropz2b1_fromFJ[10];   //[nSubjetCA15softdropz2b1]
   Int_t           nhJCidx;
   Int_t           hJCidx[2];   //[nhJCidx]
   Int_t           nl1Taus;
   Float_t         l1Taus_pt[1];   //[nl1Taus]
   Float_t         l1Taus_eta[1];   //[nl1Taus]
   Float_t         l1Taus_phi[1];   //[nl1Taus]
   Float_t         l1Taus_qual[1];   //[nl1Taus]
   Float_t         l1Taus_iso[1];   //[nl1Taus]
   Int_t           naJidx;
   Int_t           aJidx[8];   //[naJidx]
   Int_t           nGenBQuarkFromTop;
   Int_t           GenBQuarkFromTop_pdgId[3];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_pt[3];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_eta[3];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_phi[3];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_mass[3];   //[nGenBQuarkFromTop]
   Float_t         GenBQuarkFromTop_charge[3];   //[nGenBQuarkFromTop]
   Int_t           GenBQuarkFromTop_status[3];   //[nGenBQuarkFromTop]
   Int_t           GenBQuarkFromTop_isPromptHard[3];   //[nGenBQuarkFromTop]
   Int_t           nGenLepFromTau;
   Int_t           GenLepFromTau_pdgId[2];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_pt[2];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_eta[2];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_phi[2];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_mass[2];   //[nGenLepFromTau]
   Float_t         GenLepFromTau_charge[2];   //[nGenLepFromTau]
   Int_t           GenLepFromTau_status[2];   //[nGenLepFromTau]
   Int_t           GenLepFromTau_isPromptHard[2];   //[nGenLepFromTau]
   Int_t           nGenHiggsBoson;
   Int_t           GenHiggsBoson_pdgId[5];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_pt[5];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_eta[5];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_phi[5];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_mass[5];   //[nGenHiggsBoson]
   Float_t         GenHiggsBoson_charge[5];   //[nGenHiggsBoson]
   Int_t           GenHiggsBoson_status[5];   //[nGenHiggsBoson]
   Int_t           GenHiggsBoson_isPromptHard[5];   //[nGenHiggsBoson]
   Int_t           nGenNuFromTop;
   Int_t           GenNuFromTop_pdgId[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_pt[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_eta[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_phi[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_mass[2];   //[nGenNuFromTop]
   Float_t         GenNuFromTop_charge[2];   //[nGenNuFromTop]
   Int_t           GenNuFromTop_status[2];   //[nGenNuFromTop]
   Int_t           GenNuFromTop_isPromptHard[2];   //[nGenNuFromTop]
   Int_t           nGenBQuarkFromHafterISR;
   Int_t           GenBQuarkFromHafterISR_pdgId[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_pt[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_eta[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_phi[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_mass[1];   //[nGenBQuarkFromHafterISR]
   Float_t         GenBQuarkFromHafterISR_charge[1];   //[nGenBQuarkFromHafterISR]
   Int_t           GenBQuarkFromHafterISR_status[1];   //[nGenBQuarkFromHafterISR]
   Int_t           GenBQuarkFromHafterISR_isPromptHard[1];   //[nGenBQuarkFromHafterISR]
   Int_t           ntrgObjects_hltPFDoubleJetLooseID76;
   Int_t           ntrgObjects_hltBTagPFCSVp016SingleWithMatching;
   Int_t           nsoftActivityEWKJets;
   Float_t         softActivityEWKJets_pt[5];   //[nsoftActivityEWKJets]
   Float_t         softActivityEWKJets_eta[5];   //[nsoftActivityEWKJets]
   Float_t         softActivityEWKJets_phi[5];   //[nsoftActivityEWKJets]
   Float_t         softActivityEWKJets_mass[5];   //[nsoftActivityEWKJets]
   Int_t           nHTXSRivetProducer_cat0;
   Int_t           HTXSRivetProducer_cat0[1];   //[nHTXSRivetProducer_cat0]
   Int_t           nHTXSRivetProducer_cat1;
   Int_t           HTXSRivetProducer_cat1[1];   //[nHTXSRivetProducer_cat1]
   Int_t           nsoftActivityVHJets;
   Float_t         softActivityVHJets_pt[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_eta[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_phi[5];   //[nsoftActivityVHJets]
   Float_t         softActivityVHJets_mass[5];   //[nsoftActivityVHJets]
   Int_t           ntrgObjects_hltQuadPFCentralJetLooseID30;
   Int_t           nGenNu;
   Float_t         GenNu_charge[5];   //[nGenNu]
   Int_t           GenNu_status[5];   //[nGenNu]
   Int_t           GenNu_isPromptHard[5];   //[nGenNu]
   Int_t           GenNu_pdgId[5];   //[nGenNu]
   Float_t         GenNu_pt[5];   //[nGenNu]
   Float_t         GenNu_eta[5];   //[nGenNu]
   Float_t         GenNu_phi[5];   //[nGenNu]
   Float_t         GenNu_mass[5];   //[nGenNu]
   Int_t           GenNu_motherId[5];   //[nGenNu]
   Int_t           GenNu_grandmotherId[5];   //[nGenNu]
   Int_t           GenNu_sourceId[5];   //[nGenNu]
   Int_t           ntrgObjects_hltBTagCaloCSVp087Triple;
   Int_t           ntrgObjects_hltEle25eta2p1WPLoose;
   Float_t         trgObjects_hltEle25eta2p1WPLoose_pt[2];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_eta[2];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_phi[2];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Float_t         trgObjects_hltEle25eta2p1WPLoose_mass[2];   //[ntrgObjects_hltEle25eta2p1WPLoose]
   Int_t           nSubjetAK08softdrop;
   Float_t         SubjetAK08softdrop_pt[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_eta[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_phi[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_mass[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_btag[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_fromFJ[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteStatUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteStatDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteScaleUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteScaleDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteFlavMapUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteFlavMapDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteMPFBiasUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_AbsoluteMPFBiasDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FragmentationUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FragmentationDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SinglePionECALUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SinglePionECALDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SinglePionHCALUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SinglePionHCALDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorQCDUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorQCDDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimePtEtaUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimePtEtaDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJEREC1Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJEREC1Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJEREC2Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJEREC2Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJERHFUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeJERHFDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtBBUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtBBDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtEC1Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtEC1Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtEC2Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtEC2Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtHFUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativePtHFDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeBalUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeBalDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeFSRUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeFSRDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatFSRUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatFSRDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatECUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatECDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatHFUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_RelativeStatHFDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpDataMCUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpDataMCDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtRefUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtRefDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtBBUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtBBDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtEC1Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtEC1Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtEC2Up[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtEC2Down[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtHFUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpPtHFDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpMuZeroUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpMuZeroDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpEnvelopeUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_PileUpEnvelopeDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalPileUpUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalPileUpDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalRelativeUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalRelativeDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalPtUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalPtDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalScaleUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalScaleDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalAbsoluteUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalAbsoluteDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalMCUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_SubTotalMCDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoFlavorUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoFlavorDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoTimeUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoTimeDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoFlavorNoTimeUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TotalNoFlavorNoTimeDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorZJetUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorZJetDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPhotonJetUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPhotonJetDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureGluonUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureGluonDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureQuarkUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureQuarkDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureCharmUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureCharmDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureBottomUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_FlavorPureBottomDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunBCDUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunBCDDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunEFUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunEFDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunGUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunGDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunHUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_TimeRunHDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupMPFInSituUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupMPFInSituDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupbJESUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupbJESDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupFlavorUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupFlavorDown[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedUp[10];   //[nSubjetAK08softdrop]
   Float_t         SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedDown[10];   //[nSubjetAK08softdrop]
   Int_t           nGenLepRecovered;
   Int_t           GenLepRecovered_pdgId[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_pt[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_eta[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_phi[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_mass[1];   //[nGenLepRecovered]
   Float_t         GenLepRecovered_charge[1];   //[nGenLepRecovered]
   Int_t           GenLepRecovered_status[1];   //[nGenLepRecovered]
   Int_t           GenLepRecovered_isPromptHard[1];   //[nGenLepRecovered]
   Int_t           ntrgObjects_caloJets;
   Float_t         trgObjects_caloJets_pt[5];   //[ntrgObjects_caloJets]
   Int_t           nhJCMVAV2idx;
   Int_t           hJCMVAV2idx[2];   //[nhJCMVAV2idx]
   Int_t           ntrgObjects_hltPFSingleJetLooseID92;
   Int_t           nGenHadTaus;
   Float_t         GenHadTaus_charge[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_status[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_isPromptHard[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_pdgId[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_pt[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_eta[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_phi[4];   //[nGenHadTaus]
   Float_t         GenHadTaus_mass[4];   //[nGenHadTaus]
   Int_t           GenHadTaus_decayMode[4];   //[nGenHadTaus]
   Int_t           ntrgObjects_hltDoubleCentralJet90;
   Int_t           ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60;
   Int_t           ntrgObjects_hltEle25WPTight;
   Float_t         trgObjects_hltEle25WPTight_pt[2];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_eta[2];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_phi[2];   //[ntrgObjects_hltEle25WPTight]
   Float_t         trgObjects_hltEle25WPTight_mass[2];   //[ntrgObjects_hltEle25WPTight]
   Int_t           nGenVbosonsRecovered;
   Int_t           GenVbosonsRecovered_pdgId[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_pt[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_eta[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_phi[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_mass[1];   //[nGenVbosonsRecovered]
   Float_t         GenVbosonsRecovered_charge[1];   //[nGenVbosonsRecovered]
   Int_t           GenVbosonsRecovered_status[1];   //[nGenVbosonsRecovered]
   Int_t           GenVbosonsRecovered_isPromptHard[1];   //[nGenVbosonsRecovered]
   Int_t           nSubjetCA15subjetfiltered;
   Float_t         SubjetCA15subjetfiltered_pt[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_eta[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_phi[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_mass[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_btag[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_jetID[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_fromFJ[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteStatUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteStatDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteScaleUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteScaleDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteFlavMapUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteFlavMapDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FragmentationUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FragmentationDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SinglePionECALUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SinglePionECALDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SinglePionHCALUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SinglePionHCALDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorQCDUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorQCDDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimePtEtaUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimePtEtaDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJEREC1Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJEREC1Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJEREC2Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJEREC2Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJERHFUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeJERHFDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtBBUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtBBDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtEC1Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtEC1Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtEC2Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtEC2Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtHFUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativePtHFDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeBalUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeBalDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeFSRUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeFSRDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatFSRUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatFSRDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatECUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatECDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatHFUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_RelativeStatHFDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpDataMCUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpDataMCDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtRefUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtRefDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtBBUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtBBDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtEC1Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtEC1Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtEC2Up[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtEC2Down[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtHFUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpPtHFDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpMuZeroUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpMuZeroDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpEnvelopeUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_PileUpEnvelopeDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalPileUpUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalPileUpDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalRelativeUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalRelativeDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalPtUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalPtDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalScaleUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalScaleDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalAbsoluteUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalAbsoluteDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalMCUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_SubTotalMCDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoFlavorUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoFlavorDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoTimeUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoTimeDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorZJetUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorZJetDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPhotonJetUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPhotonJetDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureGluonUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureGluonDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureQuarkUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureQuarkDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureCharmUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureCharmDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureBottomUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_FlavorPureBottomDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunBCDUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunBCDDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunEFUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunEFDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunGUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunGDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunHUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_TimeRunHDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupbJESUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupbJESDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorDown[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedUp[30];   //[nSubjetCA15subjetfiltered]
   Float_t         SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedDown[30];   //[nSubjetCA15subjetfiltered]
   Int_t           nLHE_weights_pdf_eigen;
   Float_t         LHE_weights_pdf_eigen[60];   //[nLHE_weights_pdf_eigen]
   Int_t           nvLeptons;
   Int_t           vLeptons_charge[2];   //[nvLeptons]
   Int_t           vLeptons_tightId[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdCSA14_25ns_v1[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdCSA14_50ns_v1[2];   //[nvLeptons]
   Int_t           vLeptons_eleCutIdSpring15_25ns_v1[2];   //[nvLeptons]
   Int_t           vLeptons_mediumIdPOG_ICHEP2016[2];   //[nvLeptons]
   Float_t         vLeptons_dxy[2];   //[nvLeptons]
   Float_t         vLeptons_dz[2];   //[nvLeptons]
   Float_t         vLeptons_edxy[2];   //[nvLeptons]
   Float_t         vLeptons_edz[2];   //[nvLeptons]
   Float_t         vLeptons_ip3d[2];   //[nvLeptons]
   Float_t         vLeptons_sip3d[2];   //[nvLeptons]
   Int_t           vLeptons_convVeto[2];   //[nvLeptons]
   Int_t           vLeptons_lostHits[2];   //[nvLeptons]
   Float_t         vLeptons_relIso03[2];   //[nvLeptons]
   Float_t         vLeptons_relIso04[2];   //[nvLeptons]
   Float_t         vLeptons_miniRelIso[2];   //[nvLeptons]
   Float_t         vLeptons_relIsoAn04[2];   //[nvLeptons]
   Int_t           vLeptons_tightCharge[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchId[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchAny[2];   //[nvLeptons]
   Int_t           vLeptons_mcMatchTau[2];   //[nvLeptons]
   Float_t         vLeptons_mcPt[2];   //[nvLeptons]
   Int_t           vLeptons_mediumMuonId[2];   //[nvLeptons]
   Int_t           vLeptons_pdgId[2];   //[nvLeptons]
   Float_t         vLeptons_pt[2];   //[nvLeptons]
   Float_t         vLeptons_eta[2];   //[nvLeptons]
   Float_t         vLeptons_phi[2];   //[nvLeptons]
   Float_t         vLeptons_mass[2];   //[nvLeptons]
   Int_t           vLeptons_looseIdSusy[2];   //[nvLeptons]
   Int_t           vLeptons_looseIdPOG[2];   //[nvLeptons]
   Float_t         vLeptons_chargedHadRelIso03[2];   //[nvLeptons]
   Float_t         vLeptons_chargedHadRelIso04[2];   //[nvLeptons]
   Float_t         vLeptons_eleSieie[2];   //[nvLeptons]
   Float_t         vLeptons_eleDEta[2];   //[nvLeptons]
   Float_t         vLeptons_eleDPhi[2];   //[nvLeptons]
   Float_t         vLeptons_eleHoE[2];   //[nvLeptons]
   Float_t         vLeptons_eleMissingHits[2];   //[nvLeptons]
   Float_t         vLeptons_eleChi2[2];   //[nvLeptons]
   Int_t           vLeptons_convVetoFull[2];   //[nvLeptons]
   Float_t         vLeptons_eleMVArawSpring15Trig[2];   //[nvLeptons]
   Int_t           vLeptons_eleMVAIdSpring15Trig[2];   //[nvLeptons]
   Float_t         vLeptons_eleMVArawSpring15NonTrig[2];   //[nvLeptons]
   Int_t           vLeptons_eleMVAIdSpring15NonTrig[2];   //[nvLeptons]
   Float_t         vLeptons_eleMVArawSpring16GenPurp[2];   //[nvLeptons]
   Int_t           vLeptons_eleMVAIdSppring16GenPurp[2];   //[nvLeptons]
   Float_t         vLeptons_nStations[2];   //[nvLeptons]
   Float_t         vLeptons_trkKink[2];   //[nvLeptons]
   Float_t         vLeptons_segmentCompatibility[2];   //[nvLeptons]
   Float_t         vLeptons_caloCompatibility[2];   //[nvLeptons]
   Float_t         vLeptons_globalTrackChi2[2];   //[nvLeptons]
   Float_t         vLeptons_nChamberHits[2];   //[nvLeptons]
   Float_t         vLeptons_isPFMuon[2];   //[nvLeptons]
   Float_t         vLeptons_isGlobalMuon[2];   //[nvLeptons]
   Float_t         vLeptons_isTrackerMuon[2];   //[nvLeptons]
   Float_t         vLeptons_pixelHits[2];   //[nvLeptons]
   Int_t           vLeptons_trackerLayers[2];   //[nvLeptons]
   Int_t           vLeptons_pixelLayers[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTH[2];   //[nvLeptons]
   Int_t           vLeptons_jetOverlapIdx[2];   //[nvLeptons]
   Float_t         vLeptons_jetPtRatio[2];   //[nvLeptons]
   Float_t         vLeptons_jetBTagCSV[2];   //[nvLeptons]
   Float_t         vLeptons_jetDR[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetPtRatio[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetBTagCSV[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetDR[2];   //[nvLeptons]
   Float_t         vLeptons_pfRelIso03[2];   //[nvLeptons]
   Float_t         vLeptons_pfRelIso04[2];   //[nvLeptons]
   Float_t         vLeptons_etaSc[2];   //[nvLeptons]
   Float_t         vLeptons_eleExpMissingInnerHits[2];   //[nvLeptons]
   Float_t         vLeptons_eleooEmooP[2];   //[nvLeptons]
   Float_t         vLeptons_dr03TkSumPt[2];   //[nvLeptons]
   Float_t         vLeptons_eleEcalClusterIso[2];   //[nvLeptons]
   Float_t         vLeptons_eleHcalClusterIso[2];   //[nvLeptons]
   Float_t         vLeptons_miniIsoCharged[2];   //[nvLeptons]
   Float_t         vLeptons_miniIsoNeutral[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetPtRel[2];   //[nvLeptons]
   Float_t         vLeptons_mvaTTHjetNDauChargedMVASel[2];   //[nvLeptons]
   Float_t         vLeptons_uncalibratedPt[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IsoLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IsoLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IsoTight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IsoTight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdCutLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdCutLoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdCutTight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdCutTight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdMVALoose[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdMVALoose[2];   //[nvLeptons]
   Float_t         vLeptons_SF_IdMVATight[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_IdMVATight[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_SF_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_SF_trk_eta[2];   //[nvLeptons]
   Float_t         vLeptons_SFerr_trk_eta[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunD4p3[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunD4p2[2];   //[nvLeptons]
   Float_t         vLeptons_Eff_HLT_RunC[2];   //[nvLeptons]
   Float_t         vLeptons_Efferr_HLT_RunC[2];   //[nvLeptons]
   Int_t           ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching;
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt[4];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta[4];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi[4];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass[4];   //[ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching]
   Int_t           npileUpVertex_z;
   Float_t         pileUpVertex_z[5];   //[npileUpVertex_z]
   Int_t           ntrgObjects_pfJets;
   Float_t         trgObjects_pfJets_pt[5];   //[ntrgObjects_pfJets]
   Int_t           ntrgObjects_pfMht;
   Float_t         trgObjects_pfMht_pt[1];   //[ntrgObjects_pfMht]
   Int_t           nLHE_weights_scale;
   Int_t           LHE_weights_scale_id[6];   //[nLHE_weights_scale]
   Float_t         LHE_weights_scale_wgt[6];   //[nLHE_weights_scale]
   Int_t           ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT;
   Int_t           nFatjetCA15pruned;
   Float_t         FatjetCA15pruned_pt[6];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_eta[6];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_phi[6];   //[nFatjetCA15pruned]
   Float_t         FatjetCA15pruned_mass[6];   //[nFatjetCA15pruned]
   Int_t           ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5;
   Int_t           ntrgObjects_caloMht;
   Float_t         trgObjects_caloMht_pt[1];   //[ntrgObjects_caloMht]
   Int_t           nFatjetCA15softdropz2b1filt;
   Float_t         FatjetCA15softdropz2b1filt_pt[6];   //[nFatjetCA15softdropz2b1filt]
   Float_t         FatjetCA15softdropz2b1filt_eta[6];   //[nFatjetCA15softdropz2b1filt]
   Float_t         FatjetCA15softdropz2b1filt_phi[6];   //[nFatjetCA15softdropz2b1filt]
   Float_t         FatjetCA15softdropz2b1filt_mass[6];   //[nFatjetCA15softdropz2b1filt]
   Int_t           ntrgObjects_hltDoublePFCentralJetLooseID90;
   Int_t           nGenJet;
   Float_t         GenJet_charge[22];   //[nGenJet]
   Int_t           GenJet_status[22];   //[nGenJet]
   Int_t           GenJet_isPromptHard[22];   //[nGenJet]
   Int_t           GenJet_pdgId[22];   //[nGenJet]
   Float_t         GenJet_pt[22];   //[nGenJet]
   Float_t         GenJet_eta[22];   //[nGenJet]
   Float_t         GenJet_phi[22];   //[nGenJet]
   Float_t         GenJet_mass[22];   //[nGenJet]
   Int_t           GenJet_numBHadrons[22];   //[nGenJet]
   Int_t           GenJet_numCHadrons[22];   //[nGenJet]
   Int_t           GenJet_numBHadronsFromTop[22];   //[nGenJet]
   Int_t           GenJet_numCHadronsFromTop[22];   //[nGenJet]
   Int_t           GenJet_numBHadronsAfterTop[22];   //[nGenJet]
   Int_t           GenJet_numCHadronsAfterTop[22];   //[nGenJet]
   Float_t         GenJet_wNuPt[22];   //[nGenJet]
   Float_t         GenJet_wNuEta[22];   //[nGenJet]
   Float_t         GenJet_wNuPhi[22];   //[nGenJet]
   Float_t         GenJet_wNuM[22];   //[nGenJet]
   Int_t           nGenVbosons;
   Int_t           GenVbosons_pdgId[5];   //[nGenVbosons]
   Float_t         GenVbosons_pt[5];   //[nGenVbosons]
   Float_t         GenVbosons_eta[5];   //[nGenVbosons]
   Float_t         GenVbosons_phi[5];   //[nGenVbosons]
   Float_t         GenVbosons_mass[5];   //[nGenVbosons]
   Float_t         GenVbosons_charge[5];   //[nGenVbosons]
   Int_t           GenVbosons_status[5];   //[nGenVbosons]
   Int_t           GenVbosons_isPromptHard[5];   //[nGenVbosons]
   Int_t           ntrgObjects_hltDoublePFJetsC100;
   Float_t         trgObjects_hltDoublePFJetsC100_pt[5];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_eta[5];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_phi[5];   //[ntrgObjects_hltDoublePFJetsC100]
   Float_t         trgObjects_hltDoublePFJetsC100_mass[5];   //[ntrgObjects_hltDoublePFJetsC100]
   Int_t           nSubjetCA15pruned;
   Float_t         SubjetCA15pruned_pt[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_eta[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_phi[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_mass[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_btag[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_jetID[10];   //[nSubjetCA15pruned]
   Float_t         SubjetCA15pruned_fromFJ[10];   //[nSubjetCA15pruned]
   Int_t           ntrgObjects_caloMet;
   Float_t         trgObjects_caloMet_pt[1];   //[ntrgObjects_caloMet]
   Int_t           nFatjetCA15ungroomed;
   Float_t         FatjetCA15ungroomed_pt[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_eta[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_phi[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_mass[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau1[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau2[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_tau3[4];   //[nFatjetCA15ungroomed]
   Float_t         FatjetCA15ungroomed_bbtag[4];   //[nFatjetCA15ungroomed]
   Int_t           ntrgObjects_pfMet;
   Float_t         trgObjects_pfMet_pt[1];   //[ntrgObjects_pfMet]
   Int_t           ntrgObjects_hltBTagCaloCSVp067Single;
   Int_t           ndRaddJetsdR08;
   Float_t         dRaddJetsdR08[5];   //[ndRaddJetsdR08]
   Int_t           nl1Jets;
   Float_t         l1Jets_pt[1];   //[nl1Jets]
   Float_t         l1Jets_eta[1];   //[nl1Jets]
   Float_t         l1Jets_phi[1];   //[nl1Jets]
   Float_t         l1Jets_qual[1];   //[nl1Jets]
   Float_t         l1Jets_iso[1];   //[nl1Jets]
   Int_t           nSubjetCA15softdropz2b1filt;
   Float_t         SubjetCA15softdropz2b1filt_pt[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_eta[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_phi[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_mass[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_btag[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_jetID[10];   //[nSubjetCA15softdropz2b1filt]
   Float_t         SubjetCA15softdropz2b1filt_fromFJ[10];   //[nSubjetCA15softdropz2b1filt]
   Int_t           nGenBQuarkFromH;
   Int_t           GenBQuarkFromH_pdgId[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_pt[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_eta[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_phi[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_mass[1];   //[nGenBQuarkFromH]
   Float_t         GenBQuarkFromH_charge[1];   //[nGenBQuarkFromH]
   Int_t           GenBQuarkFromH_status[1];   //[nGenBQuarkFromH]
   Int_t           GenBQuarkFromH_isPromptHard[1];   //[nGenBQuarkFromH]
   Int_t           ntrgObjects_hltDoubleJet65;
   Int_t           nFatjetCA15trimmed;
   Float_t         FatjetCA15trimmed_pt[6];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_eta[6];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_phi[6];   //[nFatjetCA15trimmed]
   Float_t         FatjetCA15trimmed_mass[6];   //[nFatjetCA15trimmed]
   Int_t           nSubjetCA15softdropfilt;
   Float_t         SubjetCA15softdropfilt_pt[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_eta[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_phi[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_mass[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_btag[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_jetID[10];   //[nSubjetCA15softdropfilt]
   Float_t         SubjetCA15softdropfilt_fromFJ[10];   //[nSubjetCA15softdropfilt]
   Int_t           ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching;
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt[5];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta[5];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi[5];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Float_t         trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass[5];   //[ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching]
   Int_t           naLeptons;
   Int_t           aLeptons_charge[8];   //[naLeptons]
   Int_t           aLeptons_tightId[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdCSA14_25ns_v1[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdCSA14_50ns_v1[8];   //[naLeptons]
   Int_t           aLeptons_eleCutIdSpring15_25ns_v1[8];   //[naLeptons]
   Int_t           aLeptons_mediumIdPOG_ICHEP2016[8];   //[naLeptons]
   Float_t         aLeptons_dxy[8];   //[naLeptons]
   Float_t         aLeptons_dz[8];   //[naLeptons]
   Float_t         aLeptons_edxy[8];   //[naLeptons]
   Float_t         aLeptons_edz[8];   //[naLeptons]
   Float_t         aLeptons_ip3d[8];   //[naLeptons]
   Float_t         aLeptons_sip3d[8];   //[naLeptons]
   Int_t           aLeptons_convVeto[8];   //[naLeptons]
   Int_t           aLeptons_lostHits[8];   //[naLeptons]
   Float_t         aLeptons_relIso03[8];   //[naLeptons]
   Float_t         aLeptons_relIso04[8];   //[naLeptons]
   Float_t         aLeptons_miniRelIso[8];   //[naLeptons]
   Float_t         aLeptons_relIsoAn04[8];   //[naLeptons]
   Int_t           aLeptons_tightCharge[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchId[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchAny[8];   //[naLeptons]
   Int_t           aLeptons_mcMatchTau[8];   //[naLeptons]
   Float_t         aLeptons_mcPt[8];   //[naLeptons]
   Int_t           aLeptons_mediumMuonId[8];   //[naLeptons]
   Int_t           aLeptons_pdgId[8];   //[naLeptons]
   Float_t         aLeptons_pt[8];   //[naLeptons]
   Float_t         aLeptons_eta[8];   //[naLeptons]
   Float_t         aLeptons_phi[8];   //[naLeptons]
   Float_t         aLeptons_mass[8];   //[naLeptons]
   Int_t           aLeptons_looseIdSusy[8];   //[naLeptons]
   Int_t           aLeptons_looseIdPOG[8];   //[naLeptons]
   Float_t         aLeptons_chargedHadRelIso03[8];   //[naLeptons]
   Float_t         aLeptons_chargedHadRelIso04[8];   //[naLeptons]
   Float_t         aLeptons_eleSieie[8];   //[naLeptons]
   Float_t         aLeptons_eleDEta[8];   //[naLeptons]
   Float_t         aLeptons_eleDPhi[8];   //[naLeptons]
   Float_t         aLeptons_eleHoE[8];   //[naLeptons]
   Float_t         aLeptons_eleMissingHits[8];   //[naLeptons]
   Float_t         aLeptons_eleChi2[8];   //[naLeptons]
   Int_t           aLeptons_convVetoFull[8];   //[naLeptons]
   Float_t         aLeptons_eleMVArawSpring15Trig[8];   //[naLeptons]
   Int_t           aLeptons_eleMVAIdSpring15Trig[8];   //[naLeptons]
   Float_t         aLeptons_eleMVArawSpring15NonTrig[8];   //[naLeptons]
   Int_t           aLeptons_eleMVAIdSpring15NonTrig[8];   //[naLeptons]
   Float_t         aLeptons_eleMVArawSpring16GenPurp[8];   //[naLeptons]
   Int_t           aLeptons_eleMVAIdSppring16GenPurp[8];   //[naLeptons]
   Float_t         aLeptons_nStations[8];   //[naLeptons]
   Float_t         aLeptons_trkKink[8];   //[naLeptons]
   Float_t         aLeptons_segmentCompatibility[8];   //[naLeptons]
   Float_t         aLeptons_caloCompatibility[8];   //[naLeptons]
   Float_t         aLeptons_globalTrackChi2[8];   //[naLeptons]
   Float_t         aLeptons_nChamberHits[8];   //[naLeptons]
   Float_t         aLeptons_isPFMuon[8];   //[naLeptons]
   Float_t         aLeptons_isGlobalMuon[8];   //[naLeptons]
   Float_t         aLeptons_isTrackerMuon[8];   //[naLeptons]
   Float_t         aLeptons_pixelHits[8];   //[naLeptons]
   Int_t           aLeptons_trackerLayers[8];   //[naLeptons]
   Int_t           aLeptons_pixelLayers[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTH[8];   //[naLeptons]
   Int_t           aLeptons_jetOverlapIdx[8];   //[naLeptons]
   Float_t         aLeptons_jetPtRatio[8];   //[naLeptons]
   Float_t         aLeptons_jetBTagCSV[8];   //[naLeptons]
   Float_t         aLeptons_jetDR[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetPtRatio[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetBTagCSV[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetDR[8];   //[naLeptons]
   Float_t         aLeptons_pfRelIso03[8];   //[naLeptons]
   Float_t         aLeptons_pfRelIso04[8];   //[naLeptons]
   Float_t         aLeptons_etaSc[8];   //[naLeptons]
   Float_t         aLeptons_eleExpMissingInnerHits[8];   //[naLeptons]
   Float_t         aLeptons_eleooEmooP[8];   //[naLeptons]
   Float_t         aLeptons_dr03TkSumPt[8];   //[naLeptons]
   Float_t         aLeptons_eleEcalClusterIso[8];   //[naLeptons]
   Float_t         aLeptons_eleHcalClusterIso[8];   //[naLeptons]
   Float_t         aLeptons_miniIsoCharged[8];   //[naLeptons]
   Float_t         aLeptons_miniIsoNeutral[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetPtRel[8];   //[naLeptons]
   Float_t         aLeptons_mvaTTHjetNDauChargedMVASel[8];   //[naLeptons]
   Float_t         aLeptons_uncalibratedPt[8];   //[naLeptons]
   Float_t         aLeptons_SF_IsoLoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IsoLoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IsoTight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IsoTight[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdCutLoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdCutLoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdCutTight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdCutTight[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdMVALoose[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdMVALoose[8];   //[naLeptons]
   Float_t         aLeptons_SF_IdMVATight[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_IdMVATight[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_SF_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_SF_trk_eta[8];   //[naLeptons]
   Float_t         aLeptons_SFerr_trk_eta[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunD4p3[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunD4p2[8];   //[naLeptons]
   Float_t         aLeptons_Eff_HLT_RunC[8];   //[naLeptons]
   Float_t         aLeptons_Efferr_HLT_RunC[8];   //[naLeptons]
   Int_t           ntrgObjects_hltPFQuadJetLooseID15;
   Int_t           ntrgObjects_hltQuadPFCentralJetLooseID45;
   Int_t           nGenHiggsSisters;
   Int_t           GenHiggsSisters_pdgId[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_pt[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_eta[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_phi[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_mass[1];   //[nGenHiggsSisters]
   Float_t         GenHiggsSisters_charge[1];   //[nGenHiggsSisters]
   Int_t           GenHiggsSisters_status[1];   //[nGenHiggsSisters]
   Int_t           GenHiggsSisters_isPromptHard[1];   //[nGenHiggsSisters]
   Int_t           ntrgObjects_pfHt;
   Float_t         trgObjects_pfHt_pt[2];   //[ntrgObjects_pfHt]
   Int_t           ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2;
   Int_t           nhjidxaddJetsdR08;
   Int_t           hjidxaddJetsdR08[5];   //[nhjidxaddJetsdR08]
   Int_t           nFatjetCA15softdropfilt;
   Float_t         FatjetCA15softdropfilt_pt[6];   //[nFatjetCA15softdropfilt]
   Float_t         FatjetCA15softdropfilt_eta[6];   //[nFatjetCA15softdropfilt]
   Float_t         FatjetCA15softdropfilt_phi[6];   //[nFatjetCA15softdropfilt]
   Float_t         FatjetCA15softdropfilt_mass[6];   //[nFatjetCA15softdropfilt]
   Int_t           nl1Muons;
   Float_t         l1Muons_pt[1];   //[nl1Muons]
   Float_t         l1Muons_eta[1];   //[nl1Muons]
   Float_t         l1Muons_phi[1];   //[nl1Muons]
   Float_t         l1Muons_qual[1];   //[nl1Muons]
   Float_t         l1Muons_iso[1];   //[nl1Muons]
   Int_t           ntrgObjects_hltMHTNoPU90;
   Int_t           nFatjetAK08ungroomed;
   Float_t         FatjetAK08ungroomed_pt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_eta[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_phi[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mass[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_tau3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_msoftdrop[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mpruned[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_mprunedcorr[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L2L3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L1L2L3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L2L3Unc[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_JEC_L1L2L3Unc[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_bbtag[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_id_Tight[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_numberOfDaughters[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_neutralEmEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_neutralHadronEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_muonEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedEmEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedHadronEnergyFraction[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_chargedMultiplicity[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_electronMultiplicity[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_muonMultiplicity[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_Flavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_BhadronFlavour[5];   //[nFatjetAK08ungroomed]
   Int_t           FatjetAK08ungroomed_ChadronFlavour[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_GenPt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_pt[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_eta[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_phi[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_mass[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_tau1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_tau2[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_msoftdrop[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_msoftdrop_corrL2L3[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_puppi_msoftdrop_raw[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_PFLepton_ptrel[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_PFLepton_IP2D[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_nSL[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_nVtx[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_VtxMass_1[5];   //[nFatjetAK08ungroomed]
   Float_t         FatjetAK08ungroomed_VtxMass_2[5];   //[nFatjetAK08ungroomed]
   Int_t           nGenWZQuark;
   Int_t           GenWZQuark_pdgId[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_pt[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_eta[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_phi[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_mass[4];   //[nGenWZQuark]
   Float_t         GenWZQuark_charge[4];   //[nGenWZQuark]
   Int_t           GenWZQuark_status[4];   //[nGenWZQuark]
   Int_t           GenWZQuark_isPromptHard[4];   //[nGenWZQuark]
   Int_t           ntrgObjects_hltPFMHTTightID90;
   Int_t           ntrgObjects_hltQuadCentralJet45;
   Int_t           ntrgObjects_hltBTagCaloCSVp022Single;
   Int_t           nselLeptons;
   Int_t           selLeptons_charge[15];   //[nselLeptons]
   Int_t           selLeptons_tightId[15];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdCSA14_25ns_v1[15];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdCSA14_50ns_v1[15];   //[nselLeptons]
   Int_t           selLeptons_eleCutIdSpring15_25ns_v1[15];   //[nselLeptons]
   Int_t           selLeptons_mediumIdPOG_ICHEP2016[15];   //[nselLeptons]
   Float_t         selLeptons_dxy[15];   //[nselLeptons]
   Float_t         selLeptons_dz[15];   //[nselLeptons]
   Float_t         selLeptons_edxy[15];   //[nselLeptons]
   Float_t         selLeptons_edz[15];   //[nselLeptons]
   Float_t         selLeptons_ip3d[15];   //[nselLeptons]
   Float_t         selLeptons_sip3d[15];   //[nselLeptons]
   Int_t           selLeptons_convVeto[15];   //[nselLeptons]
   Int_t           selLeptons_lostHits[15];   //[nselLeptons]
   Float_t         selLeptons_relIso03[15];   //[nselLeptons]
   Float_t         selLeptons_relIso04[15];   //[nselLeptons]
   Float_t         selLeptons_miniRelIso[15];   //[nselLeptons]
   Float_t         selLeptons_relIsoAn04[15];   //[nselLeptons]
   Int_t           selLeptons_tightCharge[15];   //[nselLeptons]
   Int_t           selLeptons_mcMatchId[15];   //[nselLeptons]
   Int_t           selLeptons_mcMatchAny[15];   //[nselLeptons]
   Int_t           selLeptons_mcMatchTau[15];   //[nselLeptons]
   Float_t         selLeptons_mcPt[15];   //[nselLeptons]
   Int_t           selLeptons_mediumMuonId[15];   //[nselLeptons]
   Int_t           selLeptons_pdgId[15];   //[nselLeptons]
   Float_t         selLeptons_pt[15];   //[nselLeptons]
   Float_t         selLeptons_eta[15];   //[nselLeptons]
   Float_t         selLeptons_phi[15];   //[nselLeptons]
   Float_t         selLeptons_mass[15];   //[nselLeptons]
   Int_t           selLeptons_looseIdSusy[15];   //[nselLeptons]
   Int_t           selLeptons_looseIdPOG[15];   //[nselLeptons]
   Float_t         selLeptons_chargedHadRelIso03[15];   //[nselLeptons]
   Float_t         selLeptons_chargedHadRelIso04[15];   //[nselLeptons]
   Float_t         selLeptons_eleSieie[15];   //[nselLeptons]
   Float_t         selLeptons_eleDEta[15];   //[nselLeptons]
   Float_t         selLeptons_eleDPhi[15];   //[nselLeptons]
   Float_t         selLeptons_eleHoE[15];   //[nselLeptons]
   Float_t         selLeptons_eleMissingHits[15];   //[nselLeptons]
   Float_t         selLeptons_eleChi2[15];   //[nselLeptons]
   Int_t           selLeptons_convVetoFull[15];   //[nselLeptons]
   Float_t         selLeptons_eleMVArawSpring15Trig[15];   //[nselLeptons]
   Int_t           selLeptons_eleMVAIdSpring15Trig[15];   //[nselLeptons]
   Float_t         selLeptons_eleMVArawSpring15NonTrig[15];   //[nselLeptons]
   Int_t           selLeptons_eleMVAIdSpring15NonTrig[15];   //[nselLeptons]
   Float_t         selLeptons_eleMVArawSpring16GenPurp[15];   //[nselLeptons]
   Int_t           selLeptons_eleMVAIdSppring16GenPurp[15];   //[nselLeptons]
   Float_t         selLeptons_nStations[15];   //[nselLeptons]
   Float_t         selLeptons_trkKink[15];   //[nselLeptons]
   Float_t         selLeptons_segmentCompatibility[15];   //[nselLeptons]
   Float_t         selLeptons_caloCompatibility[15];   //[nselLeptons]
   Float_t         selLeptons_globalTrackChi2[15];   //[nselLeptons]
   Float_t         selLeptons_nChamberHits[15];   //[nselLeptons]
   Float_t         selLeptons_isPFMuon[15];   //[nselLeptons]
   Float_t         selLeptons_isGlobalMuon[15];   //[nselLeptons]
   Float_t         selLeptons_isTrackerMuon[15];   //[nselLeptons]
   Float_t         selLeptons_pixelHits[15];   //[nselLeptons]
   Int_t           selLeptons_trackerLayers[15];   //[nselLeptons]
   Int_t           selLeptons_pixelLayers[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTH[15];   //[nselLeptons]
   Int_t           selLeptons_jetOverlapIdx[15];   //[nselLeptons]
   Float_t         selLeptons_jetPtRatio[15];   //[nselLeptons]
   Float_t         selLeptons_jetBTagCSV[15];   //[nselLeptons]
   Float_t         selLeptons_jetDR[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetPtRatio[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetBTagCSV[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetDR[15];   //[nselLeptons]
   Float_t         selLeptons_pfRelIso03[15];   //[nselLeptons]
   Float_t         selLeptons_pfRelIso04[15];   //[nselLeptons]
   Float_t         selLeptons_etaSc[15];   //[nselLeptons]
   Float_t         selLeptons_eleExpMissingInnerHits[15];   //[nselLeptons]
   Float_t         selLeptons_eleooEmooP[15];   //[nselLeptons]
   Float_t         selLeptons_dr03TkSumPt[15];   //[nselLeptons]
   Float_t         selLeptons_eleEcalClusterIso[15];   //[nselLeptons]
   Float_t         selLeptons_eleHcalClusterIso[15];   //[nselLeptons]
   Float_t         selLeptons_miniIsoCharged[15];   //[nselLeptons]
   Float_t         selLeptons_miniIsoNeutral[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetPtRel[15];   //[nselLeptons]
   Float_t         selLeptons_mvaTTHjetNDauChargedMVASel[15];   //[nselLeptons]
   Float_t         selLeptons_uncalibratedPt[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IsoLoose[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IsoLoose[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IsoTight[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IsoTight[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IdCutLoose[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdCutLoose[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IdCutTight[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdCutTight[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IdMVALoose[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdMVALoose[15];   //[nselLeptons]
   Float_t         selLeptons_SF_IdMVATight[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_IdMVATight[15];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunD4p3[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunD4p3[15];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunD4p2[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunD4p2[15];   //[nselLeptons]
   Float_t         selLeptons_SF_HLT_RunC[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_HLT_RunC[15];   //[nselLeptons]
   Float_t         selLeptons_SF_trk_eta[15];   //[nselLeptons]
   Float_t         selLeptons_SFerr_trk_eta[15];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunD4p3[15];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunD4p3[15];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunD4p2[15];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunD4p2[15];   //[nselLeptons]
   Float_t         selLeptons_Eff_HLT_RunC[15];   //[nselLeptons]
   Float_t         selLeptons_Efferr_HLT_RunC[15];   //[nselLeptons]
   Int_t           ntrgObjects_hltPFMET90;
   Int_t           ntrgObjects_hltQuadJet15;
   Int_t           nTauGood;
   Int_t           TauGood_charge[12];   //[nTauGood]
   Int_t           TauGood_decayMode[12];   //[nTauGood]
   Int_t           TauGood_idDecayMode[12];   //[nTauGood]
   Int_t           TauGood_idDecayModeNewDMs[12];   //[nTauGood]
   Float_t         TauGood_dxy[12];   //[nTauGood]
   Float_t         TauGood_dz[12];   //[nTauGood]
   Int_t           TauGood_idMVArun2[12];   //[nTauGood]
   Float_t         TauGood_rawMVArun2[12];   //[nTauGood]
   Int_t           TauGood_idMVArun2dR03[12];   //[nTauGood]
   Float_t         TauGood_rawMVArun2dR03[12];   //[nTauGood]
   Int_t           TauGood_idMVArun2NewDM[12];   //[nTauGood]
   Float_t         TauGood_rawMVArun2NewDM[12];   //[nTauGood]
   Int_t           TauGood_idCI3hit[12];   //[nTauGood]
   Int_t           TauGood_idAntiMu[12];   //[nTauGood]
   Int_t           TauGood_idAntiErun2[12];   //[nTauGood]
   Float_t         TauGood_isoCI3hit[12];   //[nTauGood]
   Float_t         TauGood_photonOutsideSigCone[12];   //[nTauGood]
   Int_t           TauGood_mcMatchId[12];   //[nTauGood]
   Int_t           TauGood_pdgId[12];   //[nTauGood]
   Float_t         TauGood_pt[12];   //[nTauGood]
   Float_t         TauGood_eta[12];   //[nTauGood]
   Float_t         TauGood_phi[12];   //[nTauGood]
   Float_t         TauGood_mass[12];   //[nTauGood]
   Int_t           TauGood_idxJetMatch[12];   //[nTauGood]
   Int_t           TauGood_genMatchType[12];   //[nTauGood]
   Int_t           nGenStatus2bHad;
   Int_t           GenStatus2bHad_pdgId[15];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_pt[15];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_eta[15];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_phi[15];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_mass[15];   //[nGenStatus2bHad]
   Float_t         GenStatus2bHad_charge[15];   //[nGenStatus2bHad]
   Int_t           GenStatus2bHad_status[15];   //[nGenStatus2bHad]
   Int_t           GenStatus2bHad_isPromptHard[15];   //[nGenStatus2bHad]
   Int_t           nhJidx;
   Int_t           hJidx[2];   //[nhJidx]
   Int_t           nGenNuFromTau;
   Int_t           GenNuFromTau_pdgId[4];   //[nGenNuFromTau]
   Float_t         GenNuFromTau_pt[4];   //[nGenNuFromTau]
   Float_t         GenNuFromTau_eta[4];   //[nGenNuFromTau]
   Float_t         GenNuFromTau_phi[4];   //[nGenNuFromTau]
   Float_t         GenNuFromTau_mass[4];   //[nGenNuFromTau]
   Float_t         GenNuFromTau_charge[4];   //[nGenNuFromTau]
   Int_t           GenNuFromTau_status[4];   //[nGenNuFromTau]
   Int_t           GenNuFromTau_isPromptHard[4];   //[nGenNuFromTau]
   Int_t           nFatjetCA15softdropz2b1;
   Float_t         FatjetCA15softdropz2b1_pt[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_eta[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_phi[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_mass[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau1[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau2[6];   //[nFatjetCA15softdropz2b1]
   Float_t         FatjetCA15softdropz2b1_tau3[6];   //[nFatjetCA15softdropz2b1]
   Int_t           nGenGluonFromB;
   Int_t           GenGluonFromB_pdgId[4];   //[nGenGluonFromB]
   Float_t         GenGluonFromB_pt[4];   //[nGenGluonFromB]
   Float_t         GenGluonFromB_eta[4];   //[nGenGluonFromB]
   Float_t         GenGluonFromB_phi[4];   //[nGenGluonFromB]
   Float_t         GenGluonFromB_mass[4];   //[nGenGluonFromB]
   Float_t         GenGluonFromB_charge[4];   //[nGenGluonFromB]
   Int_t           GenGluonFromB_status[4];   //[nGenGluonFromB]
   Int_t           GenGluonFromB_isPromptHard[4];   //[nGenGluonFromB]
   Int_t           ntrgObjects_hltTripleJet50;
   Int_t           ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1;
   Int_t           nhttCandidates;
   Float_t         httCandidates_pt[6];   //[nhttCandidates]
   Float_t         httCandidates_eta[6];   //[nhttCandidates]
   Float_t         httCandidates_phi[6];   //[nhttCandidates]
   Float_t         httCandidates_mass[6];   //[nhttCandidates]
   Float_t         httCandidates_ptcal[6];   //[nhttCandidates]
   Float_t         httCandidates_etacal[6];   //[nhttCandidates]
   Float_t         httCandidates_phical[6];   //[nhttCandidates]
   Float_t         httCandidates_masscal[6];   //[nhttCandidates]
   Float_t         httCandidates_fRec[6];   //[nhttCandidates]
   Float_t         httCandidates_Ropt[6];   //[nhttCandidates]
   Float_t         httCandidates_RoptCalc[6];   //[nhttCandidates]
   Float_t         httCandidates_ptForRoptCalc[6];   //[nhttCandidates]
   Float_t         httCandidates_subjetIDPassed[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1ptcal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1pt[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1eta[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1phi[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1masscal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1mass[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1btag[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1corr[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2ptcal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2pt[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2eta[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2phi[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2masscal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2mass[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2btag[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2corr[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWptcal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWpt[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWeta[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWphi[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWmasscal[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWmass[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWbtag[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonWcorr[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteStatUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteStatDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteFlavMapUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteFlavMapDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteMPFBiasUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_AbsoluteMPFBiasDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FragmentationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FragmentationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SinglePionECALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SinglePionECALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SinglePionHCALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SinglePionHCALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorQCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorQCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimePtEtaUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimePtEtaDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJEREC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJEREC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJEREC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJEREC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJERHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeJERHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativePtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeBalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeBalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatECUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatECDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_RelativeStatHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpDataMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpDataMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtRefUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtRefDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpPtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpMuZeroUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpMuZeroDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpEnvelopeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_PileUpEnvelopeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalPileUpUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalPileUpDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalRelativeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalRelativeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalPtUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalPtDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalAbsoluteUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalAbsoluteDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_SubTotalMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoFlavorNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TotalNoFlavorNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorZJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorZJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPhotonJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPhotonJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureGluonUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureGluonDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureQuarkUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureQuarkDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureCharmUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureCharmDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureBottomUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_FlavorPureBottomDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunBCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunBCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunEFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunEFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunGUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunGDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunHUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_TimeRunHDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupMPFInSituUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupMPFInSituDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupIntercalibrationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupIntercalibrationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupbJESUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupbJESDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupUncorrelatedUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW1_corr_CorrelationGroupUncorrelatedDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteStatUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteStatDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteFlavMapUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteFlavMapDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteMPFBiasUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_AbsoluteMPFBiasDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FragmentationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FragmentationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SinglePionECALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SinglePionECALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SinglePionHCALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SinglePionHCALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorQCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorQCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimePtEtaUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimePtEtaDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJEREC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJEREC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJEREC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJEREC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJERHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeJERHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativePtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeBalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeBalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatECUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatECDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_RelativeStatHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpDataMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpDataMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtRefUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtRefDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpPtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpMuZeroUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpMuZeroDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpEnvelopeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_PileUpEnvelopeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalPileUpUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalPileUpDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalRelativeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalRelativeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalPtUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalPtDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalAbsoluteUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalAbsoluteDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_SubTotalMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoFlavorNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TotalNoFlavorNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorZJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorZJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPhotonJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPhotonJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureGluonUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureGluonDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureQuarkUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureQuarkDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureCharmUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureCharmDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureBottomUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_FlavorPureBottomDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunBCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunBCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunEFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunEFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunGUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunGDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunHUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_TimeRunHDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupMPFInSituUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupMPFInSituDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupIntercalibrationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupIntercalibrationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupbJESUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupbJESDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupUncorrelatedUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjW2_corr_CorrelationGroupUncorrelatedDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteStatUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteStatDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteFlavMapUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteFlavMapDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteMPFBiasUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_AbsoluteMPFBiasDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FragmentationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FragmentationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SinglePionECALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SinglePionECALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SinglePionHCALUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SinglePionHCALDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorQCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorQCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimePtEtaUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimePtEtaDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJEREC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJEREC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJEREC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJEREC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJERHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeJERHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativePtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeBalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeBalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatFSRUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatFSRDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatECUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatECDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_RelativeStatHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpDataMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpDataMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtRefUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtRefDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtBBUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtBBDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtEC1Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtEC1Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtEC2Up[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtEC2Down[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtHFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpPtHFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpMuZeroUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpMuZeroDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpEnvelopeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_PileUpEnvelopeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalPileUpUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalPileUpDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalRelativeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalRelativeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalPtUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalPtDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalScaleUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalScaleDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalAbsoluteUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalAbsoluteDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalMCUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_SubTotalMCDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoFlavorNoTimeUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TotalNoFlavorNoTimeDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorZJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorZJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPhotonJetUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPhotonJetDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureGluonUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureGluonDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureQuarkUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureQuarkDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureCharmUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureCharmDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureBottomUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_FlavorPureBottomDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunBCDUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunBCDDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunEFUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunEFDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunGUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunGDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunHUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_TimeRunHDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupMPFInSituUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupMPFInSituDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupbJESUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupbJESDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupFlavorUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupFlavorDown[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedUp[6];   //[nhttCandidates]
   Float_t         httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedDown[6];   //[nhttCandidates]
   Int_t           nGenTop;
   Float_t         GenTop_charge[5];   //[nGenTop]
   Int_t           GenTop_status[5];   //[nGenTop]
   Int_t           GenTop_isPromptHard[5];   //[nGenTop]
   Int_t           GenTop_pdgId[5];   //[nGenTop]
   Float_t         GenTop_pt[5];   //[nGenTop]
   Float_t         GenTop_eta[5];   //[nGenTop]
   Float_t         GenTop_phi[5];   //[nGenTop]
   Float_t         GenTop_mass[5];   //[nGenTop]
   Int_t           GenTop_decayMode[5];   //[nGenTop]
   Int_t           nGenTaus;
   Float_t         GenTaus_charge[2];   //[nGenTaus]
   Int_t           GenTaus_status[2];   //[nGenTaus]
   Int_t           GenTaus_isPromptHard[2];   //[nGenTaus]
   Int_t           GenTaus_pdgId[2];   //[nGenTaus]
   Float_t         GenTaus_pt[2];   //[nGenTaus]
   Float_t         GenTaus_eta[2];   //[nGenTaus]
   Float_t         GenTaus_phi[2];   //[nGenTaus]
   Float_t         GenTaus_mass[2];   //[nGenTaus]
   Int_t           GenTaus_motherId[2];   //[nGenTaus]
   Int_t           GenTaus_grandmotherId[2];   //[nGenTaus]
   Int_t           GenTaus_sourceId[2];   //[nGenTaus]
   Int_t           ntrgObjects_hltMHT70;
   Int_t           nJet;
   Int_t           Jet_id[22];   //[nJet]
   Int_t           Jet_puId[22];   //[nJet]
   Float_t         Jet_btagCSV[22];   //[nJet]
   Float_t         Jet_btagCMVA[22];   //[nJet]
   Float_t         Jet_rawPt[22];   //[nJet]
   Float_t         Jet_mcPt[22];   //[nJet]
   Int_t           Jet_mcFlavour[22];   //[nJet]
   Int_t           Jet_partonFlavour[22];   //[nJet]
   Int_t           Jet_hadronFlavour[22];   //[nJet]
   Int_t           Jet_mcMatchId[22];   //[nJet]
   Float_t         Jet_corr_JECUp[22];   //[nJet]
   Float_t         Jet_corr_JECDown[22];   //[nJet]
   Float_t         Jet_corr[22];   //[nJet]
   Float_t         Jet_corr_JERUp[22];   //[nJet]
   Float_t         Jet_corr_JERDown[22];   //[nJet]
   Float_t         Jet_corr_JER[22];   //[nJet]
   Float_t         Jet_pt[22];   //[nJet]
   Float_t         Jet_eta[22];   //[nJet]
   Float_t         Jet_phi[22];   //[nJet]
   Float_t         Jet_mass[22];   //[nJet]
   Float_t         Jet_rawPtAfterSmearing[22];   //[nJet]
   Int_t           Jet_idxFirstTauMatch[22];   //[nJet]
   Int_t           Jet_heppyFlavour[22];   //[nJet]
   Float_t         Jet_ctagVsL[22];   //[nJet]
   Float_t         Jet_ctagVsB[22];   //[nJet]
   Float_t         Jet_btagBDT[22];   //[nJet]
   Float_t         Jet_btagProb[22];   //[nJet]
   Float_t         Jet_btagBProb[22];   //[nJet]
   Float_t         Jet_btagSoftEl[22];   //[nJet]
   Float_t         Jet_btagSoftMu[22];   //[nJet]
   Float_t         Jet_btagDeepCSVdusg[22];   //[nJet]
   Float_t         Jet_btagDeepCSVb[22];   //[nJet]
   Float_t         Jet_btagDeepCSVc[22];   //[nJet]
   Float_t         Jet_btagDeepCSVbb[22];   //[nJet]
   Float_t         Jet_btagDeepCMVAdusg[22];   //[nJet]
   Float_t         Jet_btagDeepCMVAb[22];   //[nJet]
   Float_t         Jet_btagDeepCMVAc[22];   //[nJet]
   Float_t         Jet_btagDeepCMVAbb[22];   //[nJet]
   Float_t         Jet_btagCSVV0[22];   //[nJet]
   Float_t         Jet_btagCMVAV2[22];   //[nJet]
   Float_t         Jet_chHEF[22];   //[nJet]
   Float_t         Jet_neHEF[22];   //[nJet]
   Float_t         Jet_chEmEF[22];   //[nJet]
   Float_t         Jet_neEmEF[22];   //[nJet]
   Float_t         Jet_muEF[22];   //[nJet]
   Int_t           Jet_chMult[22];   //[nJet]
   Int_t           Jet_nhMult[22];   //[nJet]
   Float_t         Jet_leadTrackPt[22];   //[nJet]
   Float_t         Jet_mcEta[22];   //[nJet]
   Float_t         Jet_mcPhi[22];   //[nJet]
   Float_t         Jet_mcM[22];   //[nJet]
   Float_t         Jet_leptonPdgId[22];   //[nJet]
   Float_t         Jet_leptonPt[22];   //[nJet]
   Float_t         Jet_leptonPtRel[22];   //[nJet]
   Float_t         Jet_leptonPtRelInv[22];   //[nJet]
   Float_t         Jet_leptonDeltaR[22];   //[nJet]
   Float_t         Jet_leptonDeltaPhi[22];   //[nJet]
   Float_t         Jet_leptonDeltaEta[22];   //[nJet]
   Float_t         Jet_vtxMass[22];   //[nJet]
   Float_t         Jet_vtxNtracks[22];   //[nJet]
   Float_t         Jet_vtxPt[22];   //[nJet]
   Float_t         Jet_vtx3DSig[22];   //[nJet]
   Float_t         Jet_vtx3DVal[22];   //[nJet]
   Float_t         Jet_vtxPosX[22];   //[nJet]
   Float_t         Jet_vtxPosY[22];   //[nJet]
   Float_t         Jet_vtxPosZ[22];   //[nJet]
   Float_t         Jet_pullVectorPhi[22];   //[nJet]
   Float_t         Jet_pullVectorMag[22];   //[nJet]
   Float_t         Jet_qgl[22];   //[nJet]
   Float_t         Jet_ptd[22];   //[nJet]
   Float_t         Jet_axis2[22];   //[nJet]
   Int_t           Jet_mult[22];   //[nJet]
   Int_t           Jet_numberOfDaughters[22];   //[nJet]
   Int_t           Jet_btagIdx[22];   //[nJet]
   Int_t           Jet_btagCmvaIdx[22];   //[nJet]
   Int_t           Jet_mcIdx[22];   //[nJet]
   Float_t         Jet_blike_VBF[22];   //[nJet]
   Float_t         Jet_pt_puppi[22];   //[nJet]
   Float_t         Jet_energyRing_dR0_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR1_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR2_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR3_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR4_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR5_em[22];   //[nJet]
   Float_t         Jet_energyRing_dR0_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR1_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR2_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR3_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR4_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR5_mu[22];   //[nJet]
   Float_t         Jet_energyRing_dR0_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR1_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR2_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR3_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR4_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR5_ch[22];   //[nJet]
   Float_t         Jet_energyRing_dR0_neut[22];   //[nJet]
   Float_t         Jet_energyRing_dR1_neut[22];   //[nJet]
   Float_t         Jet_energyRing_dR2_neut[22];   //[nJet]
   Float_t         Jet_energyRing_dR3_neut[22];   //[nJet]
   Float_t         Jet_energyRing_dR4_neut[22];   //[nJet]
   Float_t         Jet_energyRing_dR5_neut[22];   //[nJet]
   Int_t           Jet_numDaughters_pt03[22];   //[nJet]
   Float_t         Jet_rawEnergy[22];   //[nJet]
   Float_t         Jet_pt_reg[22];   //[nJet]
   Float_t         Jet_pt_regVBF[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJECUp[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJECUp[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJECDown[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJECDown[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJERUp[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJERUp[22];   //[nJet]
   Float_t         Jet_pt_reg_corrJERDown[22];   //[nJet]
   Float_t         Jet_pt_regVBF_corrJERDown[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVL_SF_down[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVM_SF_down[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF_up[22];   //[nJet]
   Float_t         Jet_btagCSVT_SF_down[22];   //[nJet]
   Float_t         Jet_btagWeightCSV[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_up_cferr2[22];   //[nJet]
   Float_t         Jet_btagWeightCSV_down_cferr2[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2L_SF_down[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2M_SF_down[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF_up[22];   //[nJet]
   Float_t         Jet_btagCMVAV2T_SF_down[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_jes[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hf[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_hfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lfstats1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_lfstats2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_cferr1[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_up_cferr2[22];   //[nJet]
   Float_t         Jet_btagWeightCMVAV2_down_cferr2[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteStatUp[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteStatDown[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteScaleUp[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteScaleDown[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteFlavMapUp[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteFlavMapDown[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteMPFBiasUp[22];   //[nJet]
   Float_t         Jet_corr_AbsoluteMPFBiasDown[22];   //[nJet]
   Float_t         Jet_corr_FragmentationUp[22];   //[nJet]
   Float_t         Jet_corr_FragmentationDown[22];   //[nJet]
   Float_t         Jet_corr_SinglePionECALUp[22];   //[nJet]
   Float_t         Jet_corr_SinglePionECALDown[22];   //[nJet]
   Float_t         Jet_corr_SinglePionHCALUp[22];   //[nJet]
   Float_t         Jet_corr_SinglePionHCALDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorQCDUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorQCDDown[22];   //[nJet]
   Float_t         Jet_corr_TimePtEtaUp[22];   //[nJet]
   Float_t         Jet_corr_TimePtEtaDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeJEREC1Up[22];   //[nJet]
   Float_t         Jet_corr_RelativeJEREC1Down[22];   //[nJet]
   Float_t         Jet_corr_RelativeJEREC2Up[22];   //[nJet]
   Float_t         Jet_corr_RelativeJEREC2Down[22];   //[nJet]
   Float_t         Jet_corr_RelativeJERHFUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeJERHFDown[22];   //[nJet]
   Float_t         Jet_corr_RelativePtBBUp[22];   //[nJet]
   Float_t         Jet_corr_RelativePtBBDown[22];   //[nJet]
   Float_t         Jet_corr_RelativePtEC1Up[22];   //[nJet]
   Float_t         Jet_corr_RelativePtEC1Down[22];   //[nJet]
   Float_t         Jet_corr_RelativePtEC2Up[22];   //[nJet]
   Float_t         Jet_corr_RelativePtEC2Down[22];   //[nJet]
   Float_t         Jet_corr_RelativePtHFUp[22];   //[nJet]
   Float_t         Jet_corr_RelativePtHFDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeBalUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeBalDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeFSRUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeFSRDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatFSRUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatFSRDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatECUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatECDown[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatHFUp[22];   //[nJet]
   Float_t         Jet_corr_RelativeStatHFDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpDataMCUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpDataMCDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtRefUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtRefDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtBBUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtBBDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtEC1Up[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtEC1Down[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtEC2Up[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtEC2Down[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtHFUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpPtHFDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpMuZeroUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpMuZeroDown[22];   //[nJet]
   Float_t         Jet_corr_PileUpEnvelopeUp[22];   //[nJet]
   Float_t         Jet_corr_PileUpEnvelopeDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalPileUpUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalPileUpDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalRelativeUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalRelativeDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalPtUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalPtDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalScaleUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalScaleDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalAbsoluteUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalAbsoluteDown[22];   //[nJet]
   Float_t         Jet_corr_SubTotalMCUp[22];   //[nJet]
   Float_t         Jet_corr_SubTotalMCDown[22];   //[nJet]
   Float_t         Jet_corr_TotalUp[22];   //[nJet]
   Float_t         Jet_corr_TotalDown[22];   //[nJet]
   Float_t         Jet_corr_TotalNoFlavorUp[22];   //[nJet]
   Float_t         Jet_corr_TotalNoFlavorDown[22];   //[nJet]
   Float_t         Jet_corr_TotalNoTimeUp[22];   //[nJet]
   Float_t         Jet_corr_TotalNoTimeDown[22];   //[nJet]
   Float_t         Jet_corr_TotalNoFlavorNoTimeUp[22];   //[nJet]
   Float_t         Jet_corr_TotalNoFlavorNoTimeDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorZJetUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorZJetDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorPhotonJetUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorPhotonJetDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureGluonUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureGluonDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureQuarkUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureQuarkDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureCharmUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureCharmDown[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureBottomUp[22];   //[nJet]
   Float_t         Jet_corr_FlavorPureBottomDown[22];   //[nJet]
   Float_t         Jet_corr_TimeRunBCDUp[22];   //[nJet]
   Float_t         Jet_corr_TimeRunBCDDown[22];   //[nJet]
   Float_t         Jet_corr_TimeRunEFUp[22];   //[nJet]
   Float_t         Jet_corr_TimeRunEFDown[22];   //[nJet]
   Float_t         Jet_corr_TimeRunGUp[22];   //[nJet]
   Float_t         Jet_corr_TimeRunGDown[22];   //[nJet]
   Float_t         Jet_corr_TimeRunHUp[22];   //[nJet]
   Float_t         Jet_corr_TimeRunHDown[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupMPFInSituUp[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupMPFInSituDown[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupIntercalibrationUp[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupIntercalibrationDown[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupbJESUp[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupbJESDown[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupFlavorUp[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupFlavorDown[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupUncorrelatedUp[22];   //[nJet]
   Float_t         Jet_corr_CorrelationGroupUncorrelatedDown[22];   //[nJet]
   Int_t           nFatjetCA15softdrop;
   Float_t         FatjetCA15softdrop_pt[6];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_eta[6];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_phi[6];   //[nFatjetCA15softdrop]
   Float_t         FatjetCA15softdrop_mass[6];   //[nFatjetCA15softdrop]
   Int_t           ntrgObjects_hltPFTripleJetLooseID64;
   Int_t           nLHE_weights_pdf;
   Int_t           LHE_weights_pdf_id[102];   //[nLHE_weights_pdf]
   Float_t         LHE_weights_pdf_wgt[102];   //[nLHE_weights_pdf]
   Int_t           ntrgObjects_caloMhtNoPU;
   Float_t         trgObjects_caloMhtNoPU_pt[1];   //[ntrgObjects_caloMhtNoPU]
   Int_t           nGenLep;
   Float_t         GenLep_charge[2];   //[nGenLep]
   Int_t           GenLep_status[2];   //[nGenLep]
   Int_t           GenLep_isPromptHard[2];   //[nGenLep]
   Int_t           GenLep_pdgId[2];   //[nGenLep]
   Float_t         GenLep_pt[2];   //[nGenLep]
   Float_t         GenLep_eta[2];   //[nGenLep]
   Float_t         GenLep_phi[2];   //[nGenLep]
   Float_t         GenLep_mass[2];   //[nGenLep]
   Int_t           GenLep_motherId[2];   //[nGenLep]
   Int_t           GenLep_grandmotherId[2];   //[nGenLep]
   Int_t           GenLep_sourceId[2];   //[nGenLep]
   Int_t           nGenGluonFromTop;
   Int_t           GenGluonFromTop_pdgId[4];   //[nGenGluonFromTop]
   Float_t         GenGluonFromTop_pt[4];   //[nGenGluonFromTop]
   Float_t         GenGluonFromTop_eta[4];   //[nGenGluonFromTop]
   Float_t         GenGluonFromTop_phi[4];   //[nGenGluonFromTop]
   Float_t         GenGluonFromTop_mass[4];   //[nGenGluonFromTop]
   Float_t         GenGluonFromTop_charge[4];   //[nGenGluonFromTop]
   Int_t           GenGluonFromTop_status[4];   //[nGenGluonFromTop]
   Int_t           GenGluonFromTop_isPromptHard[4];   //[nGenGluonFromTop]
   Int_t           nsoftActivityJets;
   Float_t         softActivityJets_pt[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_eta[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_phi[5];   //[nsoftActivityJets]
   Float_t         softActivityJets_mass[5];   //[nsoftActivityJets]
   Int_t           nFatjetCA15subjetfiltered;
   Float_t         FatjetCA15subjetfiltered_pt[6];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_eta[6];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_phi[6];   //[nFatjetCA15subjetfiltered]
   Float_t         FatjetCA15subjetfiltered_mass[6];   //[nFatjetCA15subjetfiltered]
   Int_t           ntrgObjects_hltSingleJet80;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_nTrueInt;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_puWeightDown;   //!
   TBranch        *b_json;   //!
   TBranch        *b_json_silver;   //!
   TBranch        *b_nPU0;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_Vtype;   //!
   TBranch        *b_VtypeSim;   //!
   TBranch        *b_VMt;   //!
   TBranch        *b_HVdPhi;   //!
   TBranch        *b_fakeMET_sumet;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_caloMetPt;   //!
   TBranch        *b_caloMetPhi;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoN;   //!
   TBranch        *b_rhoCHPU;   //!
   TBranch        *b_rhoCentral;   //!
   TBranch        *b_deltaR_jj;   //!
   TBranch        *b_lheNj;   //!
   TBranch        *b_lheNb;   //!
   TBranch        *b_lheNc;   //!
   TBranch        *b_lheNg;   //!
   TBranch        *b_lheNl;   //!
   TBranch        *b_lheV_pt;   //!
   TBranch        *b_lheHT;   //!
   TBranch        *b_genTTHtoTauTauDecayMode;   //!
   TBranch        *b_ttCls;   //!
   TBranch        *b_heavyFlavourCategory;   //!
   TBranch        *b_mhtJet30;   //!
   TBranch        *b_mhtPhiJet30;   //!
   TBranch        *b_htJet30;   //!
   TBranch        *b_met_sig;   //!
   TBranch        *b_met_covXX;   //!
   TBranch        *b_met_covXY;   //!
   TBranch        *b_met_covYY;   //!
   TBranch        *b_met_rawpt;   //!
   TBranch        *b_metPuppi_pt;   //!
   TBranch        *b_metPuppi_phi;   //!
   TBranch        *b_metPuppi_rawpt;   //!
   TBranch        *b_metType1p2_pt;   //!
   TBranch        *b_tkMet_pt;   //!
   TBranch        *b_tkMet_phi;   //!
   TBranch        *b_isrJetVH;   //!
   TBranch        *b_simPrimaryVertex_z;   //!
   TBranch        *b_genHiggsDecayMode;   //!
   TBranch        *b_triggerEmulationWeight;   //!
   TBranch        *b_btagWeightCSV_down_cferr1;   //!
   TBranch        *b_btagWeightCMVAV2_down_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_hfstats2;   //!
   TBranch        *b_btagWeightCSV_down_cferr2;   //!
   TBranch        *b_btagWeightCSV_down_jes;   //!
   TBranch        *b_btagWeightCSV_down_lf;   //!
   TBranch        *b_btagWeightCSV_up_lf;   //!
   TBranch        *b_btagWeightCSV_down_lfstats2;   //!
   TBranch        *b_btagWeightCSV_down_lfstats1;   //!
   TBranch        *b_btagWeightCSV_down_hf;   //!
   TBranch        *b_btagWeightCSV_up_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_lf;   //!
   TBranch        *b_btagWeightCSV_up_lfstats2;   //!
   TBranch        *b_btagWeightCSV;   //!
   TBranch        *b_btagWeightCSV_up_cferr2;   //!
   TBranch        *b_btagWeightCSV_up_cferr1;   //!
   TBranch        *b_btagWeightCSV_up_hf;   //!
   TBranch        *b_btagWeightCMVAV2_down_hf;   //!
   TBranch        *b_btagWeightCMVAV2_up_lfstats2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hfstats2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2;   //!
   TBranch        *b_btagWeightCMVAV2_up_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_cferr2;   //!
   TBranch        *b_btagWeightCMVAV2_up_hf;   //!
   TBranch        *b_btagWeightCMVAV2_down_cferr1;   //!
   TBranch        *b_btagWeightCSV_up_jes;   //!
   TBranch        *b_btagWeightCMVAV2_up_jes;   //!
   TBranch        *b_btagWeightCMVAV2_up_lf;   //!
   TBranch        *b_btagWeightCSV_down_hfstats2;   //!
   TBranch        *b_btagWeightCSV_down_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_up_cferr1;   //!
   TBranch        *b_btagWeightCMVAV2_up_cferr2;   //!
   TBranch        *b_btagWeightCMVAV2_down_lfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_lfstats2;   //!
   TBranch        *b_btagWeightCSV_up_hfstats1;   //!
   TBranch        *b_btagWeightCMVAV2_down_jes;   //!
   TBranch        *b_btagWeightCSV_up_hfstats2;   //!
   TBranch        *b_ZllKinFit_corrJERUp_mass;   //!
   TBranch        *b_ZllKinFit_status;   //!
   TBranch        *b_ZllKinFit_corrJERDown_status;   //!
   TBranch        *b_ZllKinFit_corrJECDown_status;   //!
   TBranch        *b_ZllKinFit_njet;   //!
   TBranch        *b_ZllKinFit_corrJECDown_njet;   //!
   TBranch        *b_ZllKinFit_corrJERUp_njet;   //!
   TBranch        *b_ZllKinFit_corrJERUp_status;   //!
   TBranch        *b_ZllKinFit_corrJECUp_njet;   //!
   TBranch        *b_ZllKinFit_mass;   //!
   TBranch        *b_ZllKinFit_corrJERDown_mass;   //!
   TBranch        *b_ZllKinFit_corrJECUp_mass;   //!
   TBranch        *b_ZllKinFit_corrJECDown_mass;   //!
   TBranch        *b_ZllKinFit_corrJECUp_status;   //!
   TBranch        *b_ZllKinFit_corrJERDown_njet;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_trackingFailureFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_GlobalTightHalo2016Filter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_EX_MUON;   //!
   TBranch        *b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v;   //!
   TBranch        *b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET170_HBHE_BeamHaloCleaned_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET170_HBHECleaned_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT350_PFMET100_v;   //!
   TBranch        *b_HLT_ZnnHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v;   //!
   TBranch        *b_HLT_VBFHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT750_4JetPt50_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT800_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT900_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet40_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet60_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet80_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet140_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet200_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet260_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet320_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet400_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFJet450_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve40_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve60_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve80_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve140_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve200_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve260_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiPFJetAve320_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v;   //!
   TBranch        *b_HLT_hadronic;   //!
   TBranch        *b_HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v;   //!
   TBranch        *b_HLT_BIT_HLT_AK8PFJet360_TrimMass30_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v;   //!
   TBranch        *b_HLT_HH4bAll;   //!
   TBranch        *b_HLT_BIT_HLT_Mu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu24_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu24_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu27_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_TkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu20_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu18_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu16_eta2p1_MET30_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMET120_Mu5_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v;   //!
   TBranch        *b_HLT_WmnHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_ZeeHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v;   //!
   TBranch        *b_HLT_WenHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v;   //!
   TBranch        *b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v;   //!
   TBranch        *b_HLT_WtaunHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v;   //!
   TBranch        *b_HLT_ZeeHbbAll;   //!
   TBranch        *b_HLT_ttH_SL_el;   //!
   TBranch        *b_HLT_WtaunHbbLowLumi;   //!
   TBranch        *b_HLT_WmnHbbLowLumi;   //!
   TBranch        *b_HLT_ZeeHbbHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v;   //!
   TBranch        *b_HLT_ttH_FH;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v;   //!
   TBranch        *b_HLT_VBFHbbHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v;   //!
   TBranch        *b_HLT_ttH_DL_elmu;   //!
   TBranch        *b_HLT_ttH_DL_elel;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu22_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu22_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu22_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoTkMu22_eta2p1_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v;   //!
   TBranch        *b_HLT_BIT_HLT_TripleMu_12_10_5_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v;   //!
   TBranch        *b_HLT_BIT_HLT_VLooseIsoPFTau140_eta2p1_v;   //!
   TBranch        *b_HLT_ttH_htt;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT450_SixJet40_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT400_SixJet30_v;   //!
   TBranch        *b_HLT_ttH_FH_prescaled;   //!
   TBranch        *b_HLT_ZnnHbb;   //!
   TBranch        *b_HLT_ttH_DL_mumu;   //!
   TBranch        *b_HLT_ZmmHbbLowLumi;   //!
   TBranch        *b_HLT_BIT_HLT_IsoMu24_eta2p1_v;   //!
   TBranch        *b_HLT_WmnHbbHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_TkMu8_DZ_v;   //!
   TBranch        *b_HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v;   //!
   TBranch        *b_HLT_ZmmHbbAll;   //!
   TBranch        *b_HLT_ttH_SL_mu;   //!
   TBranch        *b_HLT_WtaunHbbHighLumi;   //!
   TBranch        *b_HLT_WenHbbHighLumi;   //!
   TBranch        *b_HLT_HH4bLowLumi;   //!
   TBranch        *b_HLT_ZmmHbbHighLumi;   //!
   TBranch        *b_HLT_BIT_HLT_QuadPFJet_VBF_v;   //!
   TBranch        *b_HLT_BIT_HLT_L1_TripleJet_VBF_v;   //!
   TBranch        *b_HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v;   //!
   TBranch        *b_HLT_VBFHbbAll;   //!
   TBranch        *b_HLT_BIT_HLT_Mu3_PFJet40_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu8_v;   //!
   TBranch        *b_HLT_BIT_HLT_Mu17_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v;   //!
   TBranch        *b_HLT_BIT_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v;   //!
   TBranch        *b_HLT_ttH_htt_lepFakeBgr;   //!
   TBranch        *b_HLT_WenHbbLowLumi;   //!
   TBranch        *b_HLT_HH4bHighLumi;   //!
   TBranch        *b_l1MHT_pt;   //!
   TBranch        *b_l1MHT_phi;   //!
   TBranch        *b_HCMVAV2_reg_corrJECDown_pt;   //!
   TBranch        *b_HCMVAV2_reg_corrJECDown_eta;   //!
   TBranch        *b_HCMVAV2_reg_corrJECDown_phi;   //!
   TBranch        *b_HCMVAV2_reg_corrJECDown_mass;   //!
   TBranch        *b_HCMVAV2_reg_corrJERDown_pt;   //!
   TBranch        *b_HCMVAV2_reg_corrJERDown_eta;   //!
   TBranch        *b_HCMVAV2_reg_corrJERDown_phi;   //!
   TBranch        *b_HCMVAV2_reg_corrJERDown_mass;   //!
   TBranch        *b_l1MET_pt;   //!
   TBranch        *b_l1MET_phi;   //!
   TBranch        *b_V_pt;   //!
   TBranch        *b_V_eta;   //!
   TBranch        *b_V_phi;   //!
   TBranch        *b_V_mass;   //!
   TBranch        *b_H_reg_pt;   //!
   TBranch        *b_H_reg_eta;   //!
   TBranch        *b_H_reg_phi;   //!
   TBranch        *b_H_reg_mass;   //!
   TBranch        *b_HCSV_reg_corrJERDown_pt;   //!
   TBranch        *b_HCSV_reg_corrJERDown_eta;   //!
   TBranch        *b_HCSV_reg_corrJERDown_phi;   //!
   TBranch        *b_HCSV_reg_corrJERDown_mass;   //!
   TBranch        *b_HCSV_pt;   //!
   TBranch        *b_HCSV_eta;   //!
   TBranch        *b_HCSV_phi;   //!
   TBranch        *b_HCSV_mass;   //!
   TBranch        *b_l1HT_pt;   //!
   TBranch        *b_l1HT_phi;   //!
   TBranch        *b_fakeMET_pt;   //!
   TBranch        *b_fakeMET_eta;   //!
   TBranch        *b_fakeMET_phi;   //!
   TBranch        *b_fakeMET_mass;   //!
   TBranch        *b_HCSV_reg_corrJERUp_pt;   //!
   TBranch        *b_HCSV_reg_corrJERUp_eta;   //!
   TBranch        *b_HCSV_reg_corrJERUp_phi;   //!
   TBranch        *b_HCSV_reg_corrJERUp_mass;   //!
   TBranch        *b_HCMVAV2_reg_corrJERUp_pt;   //!
   TBranch        *b_HCMVAV2_reg_corrJERUp_eta;   //!
   TBranch        *b_HCMVAV2_reg_corrJERUp_phi;   //!
   TBranch        *b_HCMVAV2_reg_corrJERUp_mass;   //!
   TBranch        *b_HCSV_reg_corrJECUp_pt;   //!
   TBranch        *b_HCSV_reg_corrJECUp_eta;   //!
   TBranch        *b_HCSV_reg_corrJECUp_phi;   //!
   TBranch        *b_HCSV_reg_corrJECUp_mass;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_pt;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_phi;   //!
   TBranch        *b_met_shifted_UnclusteredEnUp_sumEt;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_pt;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_phi;   //!
   TBranch        *b_met_shifted_UnclusteredEnDown_sumEt;   //!
   TBranch        *b_HCSV_reg_pt;   //!
   TBranch        *b_HCSV_reg_eta;   //!
   TBranch        *b_HCSV_reg_phi;   //!
   TBranch        *b_HCSV_reg_mass;   //!
   TBranch        *b_H_reg_corrJERUp_pt;   //!
   TBranch        *b_H_reg_corrJERUp_eta;   //!
   TBranch        *b_H_reg_corrJERUp_phi;   //!
   TBranch        *b_H_reg_corrJERUp_mass;   //!
   TBranch        *b_H_reg_corrJECUp_pt;   //!
   TBranch        *b_H_reg_corrJECUp_eta;   //!
   TBranch        *b_H_reg_corrJECUp_phi;   //!
   TBranch        *b_H_reg_corrJECUp_mass;   //!
   TBranch        *b_HCMVAV2_reg_pt;   //!
   TBranch        *b_HCMVAV2_reg_eta;   //!
   TBranch        *b_HCMVAV2_reg_phi;   //!
   TBranch        *b_HCMVAV2_reg_mass;   //!
   TBranch        *b_H_pt;   //!
   TBranch        *b_H_eta;   //!
   TBranch        *b_H_phi;   //!
   TBranch        *b_H_mass;   //!
   TBranch        *b_softActivityVH_njets2;   //!
   TBranch        *b_softActivityVH_njets5;   //!
   TBranch        *b_softActivityVH_njets10;   //!
   TBranch        *b_softActivityVH_HT;   //!
   TBranch        *b_met_shifted_JetResUp_pt;   //!
   TBranch        *b_met_shifted_JetResUp_phi;   //!
   TBranch        *b_met_shifted_JetResUp_sumEt;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_eta;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_mass;   //!
   TBranch        *b_met_sumEt;   //!
   TBranch        *b_met_rawPt;   //!
   TBranch        *b_met_rawPhi;   //!
   TBranch        *b_met_rawSumEt;   //!
   TBranch        *b_met_genPt;   //!
   TBranch        *b_met_genPhi;   //!
   TBranch        *b_met_genEta;   //!
   TBranch        *b_met_shifted_JetEnUp_pt;   //!
   TBranch        *b_met_shifted_JetEnUp_phi;   //!
   TBranch        *b_met_shifted_JetEnUp_sumEt;   //!
   TBranch        *b_met_shifted_JetEnDown_pt;   //!
   TBranch        *b_met_shifted_JetEnDown_phi;   //!
   TBranch        *b_met_shifted_JetEnDown_sumEt;   //!
   TBranch        *b_met_shifted_MuonEnUp_pt;   //!
   TBranch        *b_met_shifted_MuonEnUp_phi;   //!
   TBranch        *b_met_shifted_MuonEnUp_sumEt;   //!
   TBranch        *b_met_shifted_MuonEnDown_pt;   //!
   TBranch        *b_met_shifted_MuonEnDown_phi;   //!
   TBranch        *b_met_shifted_MuonEnDown_sumEt;   //!
   TBranch        *b_met_shifted_ElectronEnUp_pt;   //!
   TBranch        *b_met_shifted_ElectronEnUp_phi;   //!
   TBranch        *b_met_shifted_ElectronEnUp_sumEt;   //!
   TBranch        *b_met_shifted_ElectronEnDown_pt;   //!
   TBranch        *b_met_shifted_ElectronEnDown_phi;   //!
   TBranch        *b_met_shifted_ElectronEnDown_sumEt;   //!
   TBranch        *b_met_shifted_TauEnUp_pt;   //!
   TBranch        *b_met_shifted_TauEnUp_phi;   //!
   TBranch        *b_met_shifted_TauEnUp_sumEt;   //!
   TBranch        *b_met_shifted_TauEnDown_pt;   //!
   TBranch        *b_met_shifted_TauEnDown_phi;   //!
   TBranch        *b_met_shifted_TauEnDown_sumEt;   //!
   TBranch        *b_l1ET_pt;   //!
   TBranch        *b_l1ET_phi;   //!
   TBranch        *b_softActivityEWK_njets2;   //!
   TBranch        *b_softActivityEWK_njets5;   //!
   TBranch        *b_softActivityEWK_njets10;   //!
   TBranch        *b_softActivityEWK_HT;   //!
   TBranch        *b_met_shifted_JetResDown_pt;   //!
   TBranch        *b_met_shifted_JetResDown_phi;   //!
   TBranch        *b_met_shifted_JetResDown_sumEt;   //!
   TBranch        *b_HaddJetsdR08_pt;   //!
   TBranch        *b_HaddJetsdR08_eta;   //!
   TBranch        *b_HaddJetsdR08_phi;   //!
   TBranch        *b_HaddJetsdR08_mass;   //!
   TBranch        *b_H_reg_corrJERDown_pt;   //!
   TBranch        *b_H_reg_corrJERDown_eta;   //!
   TBranch        *b_H_reg_corrJERDown_phi;   //!
   TBranch        *b_H_reg_corrJERDown_mass;   //!
   TBranch        *b_HCMVAV2_reg_corrJECUp_pt;   //!
   TBranch        *b_HCMVAV2_reg_corrJECUp_eta;   //!
   TBranch        *b_HCMVAV2_reg_corrJECUp_phi;   //!
   TBranch        *b_HCMVAV2_reg_corrJECUp_mass;   //!
   TBranch        *b_softActivity_njets2;   //!
   TBranch        *b_softActivity_njets5;   //!
   TBranch        *b_softActivity_njets10;   //!
   TBranch        *b_softActivity_HT;   //!
   TBranch        *b_HCSV_reg_corrJECDown_pt;   //!
   TBranch        *b_HCSV_reg_corrJECDown_eta;   //!
   TBranch        *b_HCSV_reg_corrJECDown_phi;   //!
   TBranch        *b_HCSV_reg_corrJECDown_mass;   //!
   TBranch        *b_HCMVAV2_pt;   //!
   TBranch        *b_HCMVAV2_eta;   //!
   TBranch        *b_HCMVAV2_phi;   //!
   TBranch        *b_HCMVAV2_mass;   //!
   TBranch        *b_H_reg_corrJECDown_pt;   //!
   TBranch        *b_H_reg_corrJECDown_eta;   //!
   TBranch        *b_H_reg_corrJECDown_phi;   //!
   TBranch        *b_H_reg_corrJECDown_mass;   //!
   TBranch        *b_npileUpVertex_ptHat;   //!
   TBranch        *b_pileUpVertex_ptHat;   //!
   TBranch        *b_ntrgObjects_hltMET70;   //!
   TBranch        *b_ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet;   //!
   TBranch        *b_ntrgObjects_hltBTagPFCSVp11DoubleWithMatching;   //!
   TBranch        *b_nGenLepFromTop;   //!
   TBranch        *b_GenLepFromTop_pdgId;   //!
   TBranch        *b_GenLepFromTop_pt;   //!
   TBranch        *b_GenLepFromTop_eta;   //!
   TBranch        *b_GenLepFromTop_phi;   //!
   TBranch        *b_GenLepFromTop_mass;   //!
   TBranch        *b_GenLepFromTop_charge;   //!
   TBranch        *b_GenLepFromTop_status;   //!
   TBranch        *b_GenLepFromTop_isPromptHard;   //!
   TBranch        *b_najidxaddJetsdR08;   //!
   TBranch        *b_ajidxaddJetsdR08;   //!
   TBranch        *b_nSubjetCA15softdrop;   //!
   TBranch        *b_SubjetCA15softdrop_pt;   //!
   TBranch        *b_SubjetCA15softdrop_eta;   //!
   TBranch        *b_SubjetCA15softdrop_phi;   //!
   TBranch        *b_SubjetCA15softdrop_mass;   //!
   TBranch        *b_SubjetCA15softdrop_btag;   //!
   TBranch        *b_SubjetCA15softdrop_jetID;   //!
   TBranch        *b_SubjetCA15softdrop_fromFJ;   //!
   TBranch        *b_ntrgObjects_hltIsoMu20;   //!
   TBranch        *b_trgObjects_hltIsoMu20_pt;   //!
   TBranch        *b_trgObjects_hltIsoMu20_eta;   //!
   TBranch        *b_trgObjects_hltIsoMu20_phi;   //!
   TBranch        *b_trgObjects_hltIsoMu20_mass;   //!
   TBranch        *b_naJCMVAV2idx;   //!
   TBranch        *b_aJCMVAV2idx;   //!
   TBranch        *b_ntrgObjects_hltQuadCentralJet30;   //!
   TBranch        *b_nl1EGammas;   //!
   TBranch        *b_l1EGammas_pt;   //!
   TBranch        *b_l1EGammas_eta;   //!
   TBranch        *b_l1EGammas_phi;   //!
   TBranch        *b_l1EGammas_qual;   //!
   TBranch        *b_l1EGammas_iso;   //!
   TBranch        *b_nhJidx_sortcsv;   //!
   TBranch        *b_hJidx_sortcsv;   //!
   TBranch        *b_nprimaryVertices;   //!
   TBranch        *b_primaryVertices_x;   //!
   TBranch        *b_primaryVertices_y;   //!
   TBranch        *b_primaryVertices_z;   //!
   TBranch        *b_primaryVertices_isFake;   //!
   TBranch        *b_primaryVertices_ndof;   //!
   TBranch        *b_primaryVertices_Rho;   //!
   TBranch        *b_primaryVertices_score;   //!
   TBranch        *b_naJCidx;   //!
   TBranch        *b_aJCidx;   //!
   TBranch        *b_nSubjetCA15softdropz2b1;   //!
   TBranch        *b_SubjetCA15softdropz2b1_pt;   //!
   TBranch        *b_SubjetCA15softdropz2b1_eta;   //!
   TBranch        *b_SubjetCA15softdropz2b1_phi;   //!
   TBranch        *b_SubjetCA15softdropz2b1_mass;   //!
   TBranch        *b_SubjetCA15softdropz2b1_btag;   //!
   TBranch        *b_SubjetCA15softdropz2b1_jetID;   //!
   TBranch        *b_SubjetCA15softdropz2b1_fromFJ;   //!
   TBranch        *b_nhJCidx;   //!
   TBranch        *b_hJCidx;   //!
   TBranch        *b_nl1Taus;   //!
   TBranch        *b_l1Taus_pt;   //!
   TBranch        *b_l1Taus_eta;   //!
   TBranch        *b_l1Taus_phi;   //!
   TBranch        *b_l1Taus_qual;   //!
   TBranch        *b_l1Taus_iso;   //!
   TBranch        *b_naJidx;   //!
   TBranch        *b_aJidx;   //!
   TBranch        *b_nGenBQuarkFromTop;   //!
   TBranch        *b_GenBQuarkFromTop_pdgId;   //!
   TBranch        *b_GenBQuarkFromTop_pt;   //!
   TBranch        *b_GenBQuarkFromTop_eta;   //!
   TBranch        *b_GenBQuarkFromTop_phi;   //!
   TBranch        *b_GenBQuarkFromTop_mass;   //!
   TBranch        *b_GenBQuarkFromTop_charge;   //!
   TBranch        *b_GenBQuarkFromTop_status;   //!
   TBranch        *b_GenBQuarkFromTop_isPromptHard;   //!
   TBranch        *b_nGenLepFromTau;   //!
   TBranch        *b_GenLepFromTau_pdgId;   //!
   TBranch        *b_GenLepFromTau_pt;   //!
   TBranch        *b_GenLepFromTau_eta;   //!
   TBranch        *b_GenLepFromTau_phi;   //!
   TBranch        *b_GenLepFromTau_mass;   //!
   TBranch        *b_GenLepFromTau_charge;   //!
   TBranch        *b_GenLepFromTau_status;   //!
   TBranch        *b_GenLepFromTau_isPromptHard;   //!
   TBranch        *b_nGenHiggsBoson;   //!
   TBranch        *b_GenHiggsBoson_pdgId;   //!
   TBranch        *b_GenHiggsBoson_pt;   //!
   TBranch        *b_GenHiggsBoson_eta;   //!
   TBranch        *b_GenHiggsBoson_phi;   //!
   TBranch        *b_GenHiggsBoson_mass;   //!
   TBranch        *b_GenHiggsBoson_charge;   //!
   TBranch        *b_GenHiggsBoson_status;   //!
   TBranch        *b_GenHiggsBoson_isPromptHard;   //!
   TBranch        *b_nGenNuFromTop;   //!
   TBranch        *b_GenNuFromTop_pdgId;   //!
   TBranch        *b_GenNuFromTop_pt;   //!
   TBranch        *b_GenNuFromTop_eta;   //!
   TBranch        *b_GenNuFromTop_phi;   //!
   TBranch        *b_GenNuFromTop_mass;   //!
   TBranch        *b_GenNuFromTop_charge;   //!
   TBranch        *b_GenNuFromTop_status;   //!
   TBranch        *b_GenNuFromTop_isPromptHard;   //!
   TBranch        *b_nGenBQuarkFromHafterISR;   //!
   TBranch        *b_GenBQuarkFromHafterISR_pdgId;   //!
   TBranch        *b_GenBQuarkFromHafterISR_pt;   //!
   TBranch        *b_GenBQuarkFromHafterISR_eta;   //!
   TBranch        *b_GenBQuarkFromHafterISR_phi;   //!
   TBranch        *b_GenBQuarkFromHafterISR_mass;   //!
   TBranch        *b_GenBQuarkFromHafterISR_charge;   //!
   TBranch        *b_GenBQuarkFromHafterISR_status;   //!
   TBranch        *b_GenBQuarkFromHafterISR_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltPFDoubleJetLooseID76;   //!
   TBranch        *b_ntrgObjects_hltBTagPFCSVp016SingleWithMatching;   //!
   TBranch        *b_nsoftActivityEWKJets;   //!
   TBranch        *b_softActivityEWKJets_pt;   //!
   TBranch        *b_softActivityEWKJets_eta;   //!
   TBranch        *b_softActivityEWKJets_phi;   //!
   TBranch        *b_softActivityEWKJets_mass;   //!
   TBranch        *b_nHTXSRivetProducer_cat0;   //!
   TBranch        *b_HTXSRivetProducer_cat0;   //!
   TBranch        *b_nHTXSRivetProducer_cat1;   //!
   TBranch        *b_HTXSRivetProducer_cat1;   //!
   TBranch        *b_nsoftActivityVHJets;   //!
   TBranch        *b_softActivityVHJets_pt;   //!
   TBranch        *b_softActivityVHJets_eta;   //!
   TBranch        *b_softActivityVHJets_phi;   //!
   TBranch        *b_softActivityVHJets_mass;   //!
   TBranch        *b_ntrgObjects_hltQuadPFCentralJetLooseID30;   //!
   TBranch        *b_nGenNu;   //!
   TBranch        *b_GenNu_charge;   //!
   TBranch        *b_GenNu_status;   //!
   TBranch        *b_GenNu_isPromptHard;   //!
   TBranch        *b_GenNu_pdgId;   //!
   TBranch        *b_GenNu_pt;   //!
   TBranch        *b_GenNu_eta;   //!
   TBranch        *b_GenNu_phi;   //!
   TBranch        *b_GenNu_mass;   //!
   TBranch        *b_GenNu_motherId;   //!
   TBranch        *b_GenNu_grandmotherId;   //!
   TBranch        *b_GenNu_sourceId;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp087Triple;   //!
   TBranch        *b_ntrgObjects_hltEle25eta2p1WPLoose;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_pt;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_eta;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_phi;   //!
   TBranch        *b_trgObjects_hltEle25eta2p1WPLoose_mass;   //!
   TBranch        *b_nSubjetAK08softdrop;   //!
   TBranch        *b_SubjetAK08softdrop_pt;   //!
   TBranch        *b_SubjetAK08softdrop_eta;   //!
   TBranch        *b_SubjetAK08softdrop_phi;   //!
   TBranch        *b_SubjetAK08softdrop_mass;   //!
   TBranch        *b_SubjetAK08softdrop_btag;   //!
   TBranch        *b_SubjetAK08softdrop_fromFJ;   //!
   TBranch        *b_SubjetAK08softdrop_corr;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteStatUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteStatDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteScaleUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteScaleDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FragmentationUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FragmentationDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SinglePionECALUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SinglePionECALDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SinglePionHCALUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SinglePionHCALDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorQCDUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorQCDDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimePtEtaUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimePtEtaDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJEREC1Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJEREC1Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJEREC2Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJEREC2Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJERHFUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeJERHFDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtBBUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtBBDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtEC1Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtEC1Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtEC2Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtEC2Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtHFUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativePtHFDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeBalUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeBalDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeFSRUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeFSRDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatFSRUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatFSRDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatECUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatECDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatHFUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_RelativeStatHFDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpDataMCUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpDataMCDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtRefUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtRefDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtBBUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtBBDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtEC1Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtEC1Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtEC2Up;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtEC2Down;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtHFUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpPtHFDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpMuZeroUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpMuZeroDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalPileUpUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalPileUpDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalRelativeUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalRelativeDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalPtUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalPtDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalScaleUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalScaleDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalMCUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_SubTotalMCDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoFlavorUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoFlavorDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoTimeUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoTimeDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorZJetUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorZJetDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureGluonUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureGluonDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureCharmUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureCharmDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureBottomUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_FlavorPureBottomDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunBCDUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunBCDDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunEFUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunEFDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunGUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunGDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunHUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_TimeRunHDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_nGenLepRecovered;   //!
   TBranch        *b_GenLepRecovered_pdgId;   //!
   TBranch        *b_GenLepRecovered_pt;   //!
   TBranch        *b_GenLepRecovered_eta;   //!
   TBranch        *b_GenLepRecovered_phi;   //!
   TBranch        *b_GenLepRecovered_mass;   //!
   TBranch        *b_GenLepRecovered_charge;   //!
   TBranch        *b_GenLepRecovered_status;   //!
   TBranch        *b_GenLepRecovered_isPromptHard;   //!
   TBranch        *b_ntrgObjects_caloJets;   //!
   TBranch        *b_trgObjects_caloJets_pt;   //!
   TBranch        *b_nhJCMVAV2idx;   //!
   TBranch        *b_hJCMVAV2idx;   //!
   TBranch        *b_ntrgObjects_hltPFSingleJetLooseID92;   //!
   TBranch        *b_nGenHadTaus;   //!
   TBranch        *b_GenHadTaus_charge;   //!
   TBranch        *b_GenHadTaus_status;   //!
   TBranch        *b_GenHadTaus_isPromptHard;   //!
   TBranch        *b_GenHadTaus_pdgId;   //!
   TBranch        *b_GenHadTaus_pt;   //!
   TBranch        *b_GenHadTaus_eta;   //!
   TBranch        *b_GenHadTaus_phi;   //!
   TBranch        *b_GenHadTaus_mass;   //!
   TBranch        *b_GenHadTaus_decayMode;   //!
   TBranch        *b_ntrgObjects_hltDoubleCentralJet90;   //!
   TBranch        *b_ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60;   //!
   TBranch        *b_ntrgObjects_hltEle25WPTight;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_pt;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_eta;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_phi;   //!
   TBranch        *b_trgObjects_hltEle25WPTight_mass;   //!
   TBranch        *b_nGenVbosonsRecovered;   //!
   TBranch        *b_GenVbosonsRecovered_pdgId;   //!
   TBranch        *b_GenVbosonsRecovered_pt;   //!
   TBranch        *b_GenVbosonsRecovered_eta;   //!
   TBranch        *b_GenVbosonsRecovered_phi;   //!
   TBranch        *b_GenVbosonsRecovered_mass;   //!
   TBranch        *b_GenVbosonsRecovered_charge;   //!
   TBranch        *b_GenVbosonsRecovered_status;   //!
   TBranch        *b_GenVbosonsRecovered_isPromptHard;   //!
   TBranch        *b_nSubjetCA15subjetfiltered;   //!
   TBranch        *b_SubjetCA15subjetfiltered_pt;   //!
   TBranch        *b_SubjetCA15subjetfiltered_eta;   //!
   TBranch        *b_SubjetCA15subjetfiltered_phi;   //!
   TBranch        *b_SubjetCA15subjetfiltered_mass;   //!
   TBranch        *b_SubjetCA15subjetfiltered_btag;   //!
   TBranch        *b_SubjetCA15subjetfiltered_jetID;   //!
   TBranch        *b_SubjetCA15subjetfiltered_fromFJ;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteStatUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteStatDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteScaleUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteScaleDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FragmentationUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FragmentationDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SinglePionECALUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SinglePionECALDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SinglePionHCALUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SinglePionHCALDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorQCDUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorQCDDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimePtEtaUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimePtEtaDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJEREC1Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJEREC1Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJEREC2Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJEREC2Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJERHFUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeJERHFDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtBBUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtBBDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtEC1Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtEC1Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtEC2Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtEC2Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtHFUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativePtHFDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeBalUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeBalDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeFSRUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeFSRDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatFSRUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatFSRDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatECUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatECDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatHFUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_RelativeStatHFDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpDataMCUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpDataMCDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtRefUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtRefDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtBBUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtBBDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtEC1Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtEC1Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtEC2Up;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtEC2Down;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtHFUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpPtHFDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpMuZeroUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpMuZeroDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalPileUpUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalPileUpDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalRelativeUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalRelativeDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalPtUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalPtDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalScaleUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalScaleDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalMCUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_SubTotalMCDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoFlavorUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoFlavorDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoTimeUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoTimeDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorZJetUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorZJetDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureGluonUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureGluonDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureCharmUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureCharmDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureBottomUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_FlavorPureBottomDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunBCDUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunBCDDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunEFUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunEFDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunGUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunGDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunHUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_TimeRunHDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_nLHE_weights_pdf_eigen;   //!
   TBranch        *b_LHE_weights_pdf_eigen;   //!
   TBranch        *b_nvLeptons;   //!
   TBranch        *b_vLeptons_charge;   //!
   TBranch        *b_vLeptons_tightId;   //!
   TBranch        *b_vLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_vLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_vLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_vLeptons_mediumIdPOG_ICHEP2016;   //!
   TBranch        *b_vLeptons_dxy;   //!
   TBranch        *b_vLeptons_dz;   //!
   TBranch        *b_vLeptons_edxy;   //!
   TBranch        *b_vLeptons_edz;   //!
   TBranch        *b_vLeptons_ip3d;   //!
   TBranch        *b_vLeptons_sip3d;   //!
   TBranch        *b_vLeptons_convVeto;   //!
   TBranch        *b_vLeptons_lostHits;   //!
   TBranch        *b_vLeptons_relIso03;   //!
   TBranch        *b_vLeptons_relIso04;   //!
   TBranch        *b_vLeptons_miniRelIso;   //!
   TBranch        *b_vLeptons_relIsoAn04;   //!
   TBranch        *b_vLeptons_tightCharge;   //!
   TBranch        *b_vLeptons_mcMatchId;   //!
   TBranch        *b_vLeptons_mcMatchAny;   //!
   TBranch        *b_vLeptons_mcMatchTau;   //!
   TBranch        *b_vLeptons_mcPt;   //!
   TBranch        *b_vLeptons_mediumMuonId;   //!
   TBranch        *b_vLeptons_pdgId;   //!
   TBranch        *b_vLeptons_pt;   //!
   TBranch        *b_vLeptons_eta;   //!
   TBranch        *b_vLeptons_phi;   //!
   TBranch        *b_vLeptons_mass;   //!
   TBranch        *b_vLeptons_looseIdSusy;   //!
   TBranch        *b_vLeptons_looseIdPOG;   //!
   TBranch        *b_vLeptons_chargedHadRelIso03;   //!
   TBranch        *b_vLeptons_chargedHadRelIso04;   //!
   TBranch        *b_vLeptons_eleSieie;   //!
   TBranch        *b_vLeptons_eleDEta;   //!
   TBranch        *b_vLeptons_eleDPhi;   //!
   TBranch        *b_vLeptons_eleHoE;   //!
   TBranch        *b_vLeptons_eleMissingHits;   //!
   TBranch        *b_vLeptons_eleChi2;   //!
   TBranch        *b_vLeptons_convVetoFull;   //!
   TBranch        *b_vLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_vLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_vLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_vLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_vLeptons_eleMVArawSpring16GenPurp;   //!
   TBranch        *b_vLeptons_eleMVAIdSppring16GenPurp;   //!
   TBranch        *b_vLeptons_nStations;   //!
   TBranch        *b_vLeptons_trkKink;   //!
   TBranch        *b_vLeptons_segmentCompatibility;   //!
   TBranch        *b_vLeptons_caloCompatibility;   //!
   TBranch        *b_vLeptons_globalTrackChi2;   //!
   TBranch        *b_vLeptons_nChamberHits;   //!
   TBranch        *b_vLeptons_isPFMuon;   //!
   TBranch        *b_vLeptons_isGlobalMuon;   //!
   TBranch        *b_vLeptons_isTrackerMuon;   //!
   TBranch        *b_vLeptons_pixelHits;   //!
   TBranch        *b_vLeptons_trackerLayers;   //!
   TBranch        *b_vLeptons_pixelLayers;   //!
   TBranch        *b_vLeptons_mvaTTH;   //!
   TBranch        *b_vLeptons_jetOverlapIdx;   //!
   TBranch        *b_vLeptons_jetPtRatio;   //!
   TBranch        *b_vLeptons_jetBTagCSV;   //!
   TBranch        *b_vLeptons_jetDR;   //!
   TBranch        *b_vLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_vLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_vLeptons_mvaTTHjetDR;   //!
   TBranch        *b_vLeptons_pfRelIso03;   //!
   TBranch        *b_vLeptons_pfRelIso04;   //!
   TBranch        *b_vLeptons_etaSc;   //!
   TBranch        *b_vLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_vLeptons_eleooEmooP;   //!
   TBranch        *b_vLeptons_dr03TkSumPt;   //!
   TBranch        *b_vLeptons_eleEcalClusterIso;   //!
   TBranch        *b_vLeptons_eleHcalClusterIso;   //!
   TBranch        *b_vLeptons_miniIsoCharged;   //!
   TBranch        *b_vLeptons_miniIsoNeutral;   //!
   TBranch        *b_vLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_vLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_vLeptons_uncalibratedPt;   //!
   TBranch        *b_vLeptons_SF_IsoLoose;   //!
   TBranch        *b_vLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_vLeptons_SF_IsoTight;   //!
   TBranch        *b_vLeptons_SFerr_IsoTight;   //!
   TBranch        *b_vLeptons_SF_IdCutLoose;   //!
   TBranch        *b_vLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_vLeptons_SF_IdCutTight;   //!
   TBranch        *b_vLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_vLeptons_SF_IdMVALoose;   //!
   TBranch        *b_vLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_vLeptons_SF_IdMVATight;   //!
   TBranch        *b_vLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_vLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_SF_HLT_RunC;   //!
   TBranch        *b_vLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_vLeptons_SF_trk_eta;   //!
   TBranch        *b_vLeptons_SFerr_trk_eta;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_vLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_vLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass;   //!
   TBranch        *b_npileUpVertex_z;   //!
   TBranch        *b_pileUpVertex_z;   //!
   TBranch        *b_ntrgObjects_pfJets;   //!
   TBranch        *b_trgObjects_pfJets_pt;   //!
   TBranch        *b_ntrgObjects_pfMht;   //!
   TBranch        *b_trgObjects_pfMht_pt;   //!
   TBranch        *b_nLHE_weights_scale;   //!
   TBranch        *b_LHE_weights_scale_id;   //!
   TBranch        *b_LHE_weights_scale_wgt;   //!
   TBranch        *b_ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT;   //!
   TBranch        *b_nFatjetCA15pruned;   //!
   TBranch        *b_FatjetCA15pruned_pt;   //!
   TBranch        *b_FatjetCA15pruned_eta;   //!
   TBranch        *b_FatjetCA15pruned_phi;   //!
   TBranch        *b_FatjetCA15pruned_mass;   //!
   TBranch        *b_ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5;   //!
   TBranch        *b_ntrgObjects_caloMht;   //!
   TBranch        *b_trgObjects_caloMht_pt;   //!
   TBranch        *b_nFatjetCA15softdropz2b1filt;   //!
   TBranch        *b_FatjetCA15softdropz2b1filt_pt;   //!
   TBranch        *b_FatjetCA15softdropz2b1filt_eta;   //!
   TBranch        *b_FatjetCA15softdropz2b1filt_phi;   //!
   TBranch        *b_FatjetCA15softdropz2b1filt_mass;   //!
   TBranch        *b_ntrgObjects_hltDoublePFCentralJetLooseID90;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_charge;   //!
   TBranch        *b_GenJet_status;   //!
   TBranch        *b_GenJet_isPromptHard;   //!
   TBranch        *b_GenJet_pdgId;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_numBHadrons;   //!
   TBranch        *b_GenJet_numCHadrons;   //!
   TBranch        *b_GenJet_numBHadronsFromTop;   //!
   TBranch        *b_GenJet_numCHadronsFromTop;   //!
   TBranch        *b_GenJet_numBHadronsAfterTop;   //!
   TBranch        *b_GenJet_numCHadronsAfterTop;   //!
   TBranch        *b_GenJet_wNuPt;   //!
   TBranch        *b_GenJet_wNuEta;   //!
   TBranch        *b_GenJet_wNuPhi;   //!
   TBranch        *b_GenJet_wNuM;   //!
   TBranch        *b_nGenVbosons;   //!
   TBranch        *b_GenVbosons_pdgId;   //!
   TBranch        *b_GenVbosons_pt;   //!
   TBranch        *b_GenVbosons_eta;   //!
   TBranch        *b_GenVbosons_phi;   //!
   TBranch        *b_GenVbosons_mass;   //!
   TBranch        *b_GenVbosons_charge;   //!
   TBranch        *b_GenVbosons_status;   //!
   TBranch        *b_GenVbosons_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltDoublePFJetsC100;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_pt;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_eta;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_phi;   //!
   TBranch        *b_trgObjects_hltDoublePFJetsC100_mass;   //!
   TBranch        *b_nSubjetCA15pruned;   //!
   TBranch        *b_SubjetCA15pruned_pt;   //!
   TBranch        *b_SubjetCA15pruned_eta;   //!
   TBranch        *b_SubjetCA15pruned_phi;   //!
   TBranch        *b_SubjetCA15pruned_mass;   //!
   TBranch        *b_SubjetCA15pruned_btag;   //!
   TBranch        *b_SubjetCA15pruned_jetID;   //!
   TBranch        *b_SubjetCA15pruned_fromFJ;   //!
   TBranch        *b_ntrgObjects_caloMet;   //!
   TBranch        *b_trgObjects_caloMet_pt;   //!
   TBranch        *b_nFatjetCA15ungroomed;   //!
   TBranch        *b_FatjetCA15ungroomed_pt;   //!
   TBranch        *b_FatjetCA15ungroomed_eta;   //!
   TBranch        *b_FatjetCA15ungroomed_phi;   //!
   TBranch        *b_FatjetCA15ungroomed_mass;   //!
   TBranch        *b_FatjetCA15ungroomed_tau1;   //!
   TBranch        *b_FatjetCA15ungroomed_tau2;   //!
   TBranch        *b_FatjetCA15ungroomed_tau3;   //!
   TBranch        *b_FatjetCA15ungroomed_bbtag;   //!
   TBranch        *b_ntrgObjects_pfMet;   //!
   TBranch        *b_trgObjects_pfMet_pt;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp067Single;   //!
   TBranch        *b_ndRaddJetsdR08;   //!
   TBranch        *b_dRaddJetsdR08;   //!
   TBranch        *b_nl1Jets;   //!
   TBranch        *b_l1Jets_pt;   //!
   TBranch        *b_l1Jets_eta;   //!
   TBranch        *b_l1Jets_phi;   //!
   TBranch        *b_l1Jets_qual;   //!
   TBranch        *b_l1Jets_iso;   //!
   TBranch        *b_nSubjetCA15softdropz2b1filt;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_pt;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_eta;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_phi;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_mass;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_btag;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_jetID;   //!
   TBranch        *b_SubjetCA15softdropz2b1filt_fromFJ;   //!
   TBranch        *b_nGenBQuarkFromH;   //!
   TBranch        *b_GenBQuarkFromH_pdgId;   //!
   TBranch        *b_GenBQuarkFromH_pt;   //!
   TBranch        *b_GenBQuarkFromH_eta;   //!
   TBranch        *b_GenBQuarkFromH_phi;   //!
   TBranch        *b_GenBQuarkFromH_mass;   //!
   TBranch        *b_GenBQuarkFromH_charge;   //!
   TBranch        *b_GenBQuarkFromH_status;   //!
   TBranch        *b_GenBQuarkFromH_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltDoubleJet65;   //!
   TBranch        *b_nFatjetCA15trimmed;   //!
   TBranch        *b_FatjetCA15trimmed_pt;   //!
   TBranch        *b_FatjetCA15trimmed_eta;   //!
   TBranch        *b_FatjetCA15trimmed_phi;   //!
   TBranch        *b_FatjetCA15trimmed_mass;   //!
   TBranch        *b_nSubjetCA15softdropfilt;   //!
   TBranch        *b_SubjetCA15softdropfilt_pt;   //!
   TBranch        *b_SubjetCA15softdropfilt_eta;   //!
   TBranch        *b_SubjetCA15softdropfilt_phi;   //!
   TBranch        *b_SubjetCA15softdropfilt_mass;   //!
   TBranch        *b_SubjetCA15softdropfilt_btag;   //!
   TBranch        *b_SubjetCA15softdropfilt_jetID;   //!
   TBranch        *b_SubjetCA15softdropfilt_fromFJ;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi;   //!
   TBranch        *b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass;   //!
   TBranch        *b_naLeptons;   //!
   TBranch        *b_aLeptons_charge;   //!
   TBranch        *b_aLeptons_tightId;   //!
   TBranch        *b_aLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_aLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_aLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_aLeptons_mediumIdPOG_ICHEP2016;   //!
   TBranch        *b_aLeptons_dxy;   //!
   TBranch        *b_aLeptons_dz;   //!
   TBranch        *b_aLeptons_edxy;   //!
   TBranch        *b_aLeptons_edz;   //!
   TBranch        *b_aLeptons_ip3d;   //!
   TBranch        *b_aLeptons_sip3d;   //!
   TBranch        *b_aLeptons_convVeto;   //!
   TBranch        *b_aLeptons_lostHits;   //!
   TBranch        *b_aLeptons_relIso03;   //!
   TBranch        *b_aLeptons_relIso04;   //!
   TBranch        *b_aLeptons_miniRelIso;   //!
   TBranch        *b_aLeptons_relIsoAn04;   //!
   TBranch        *b_aLeptons_tightCharge;   //!
   TBranch        *b_aLeptons_mcMatchId;   //!
   TBranch        *b_aLeptons_mcMatchAny;   //!
   TBranch        *b_aLeptons_mcMatchTau;   //!
   TBranch        *b_aLeptons_mcPt;   //!
   TBranch        *b_aLeptons_mediumMuonId;   //!
   TBranch        *b_aLeptons_pdgId;   //!
   TBranch        *b_aLeptons_pt;   //!
   TBranch        *b_aLeptons_eta;   //!
   TBranch        *b_aLeptons_phi;   //!
   TBranch        *b_aLeptons_mass;   //!
   TBranch        *b_aLeptons_looseIdSusy;   //!
   TBranch        *b_aLeptons_looseIdPOG;   //!
   TBranch        *b_aLeptons_chargedHadRelIso03;   //!
   TBranch        *b_aLeptons_chargedHadRelIso04;   //!
   TBranch        *b_aLeptons_eleSieie;   //!
   TBranch        *b_aLeptons_eleDEta;   //!
   TBranch        *b_aLeptons_eleDPhi;   //!
   TBranch        *b_aLeptons_eleHoE;   //!
   TBranch        *b_aLeptons_eleMissingHits;   //!
   TBranch        *b_aLeptons_eleChi2;   //!
   TBranch        *b_aLeptons_convVetoFull;   //!
   TBranch        *b_aLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_aLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_aLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_aLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_aLeptons_eleMVArawSpring16GenPurp;   //!
   TBranch        *b_aLeptons_eleMVAIdSppring16GenPurp;   //!
   TBranch        *b_aLeptons_nStations;   //!
   TBranch        *b_aLeptons_trkKink;   //!
   TBranch        *b_aLeptons_segmentCompatibility;   //!
   TBranch        *b_aLeptons_caloCompatibility;   //!
   TBranch        *b_aLeptons_globalTrackChi2;   //!
   TBranch        *b_aLeptons_nChamberHits;   //!
   TBranch        *b_aLeptons_isPFMuon;   //!
   TBranch        *b_aLeptons_isGlobalMuon;   //!
   TBranch        *b_aLeptons_isTrackerMuon;   //!
   TBranch        *b_aLeptons_pixelHits;   //!
   TBranch        *b_aLeptons_trackerLayers;   //!
   TBranch        *b_aLeptons_pixelLayers;   //!
   TBranch        *b_aLeptons_mvaTTH;   //!
   TBranch        *b_aLeptons_jetOverlapIdx;   //!
   TBranch        *b_aLeptons_jetPtRatio;   //!
   TBranch        *b_aLeptons_jetBTagCSV;   //!
   TBranch        *b_aLeptons_jetDR;   //!
   TBranch        *b_aLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_aLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_aLeptons_mvaTTHjetDR;   //!
   TBranch        *b_aLeptons_pfRelIso03;   //!
   TBranch        *b_aLeptons_pfRelIso04;   //!
   TBranch        *b_aLeptons_etaSc;   //!
   TBranch        *b_aLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_aLeptons_eleooEmooP;   //!
   TBranch        *b_aLeptons_dr03TkSumPt;   //!
   TBranch        *b_aLeptons_eleEcalClusterIso;   //!
   TBranch        *b_aLeptons_eleHcalClusterIso;   //!
   TBranch        *b_aLeptons_miniIsoCharged;   //!
   TBranch        *b_aLeptons_miniIsoNeutral;   //!
   TBranch        *b_aLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_aLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_aLeptons_uncalibratedPt;   //!
   TBranch        *b_aLeptons_SF_IsoLoose;   //!
   TBranch        *b_aLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_aLeptons_SF_IsoTight;   //!
   TBranch        *b_aLeptons_SFerr_IsoTight;   //!
   TBranch        *b_aLeptons_SF_IdCutLoose;   //!
   TBranch        *b_aLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_aLeptons_SF_IdCutTight;   //!
   TBranch        *b_aLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_aLeptons_SF_IdMVALoose;   //!
   TBranch        *b_aLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_aLeptons_SF_IdMVATight;   //!
   TBranch        *b_aLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_aLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_SF_HLT_RunC;   //!
   TBranch        *b_aLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_aLeptons_SF_trk_eta;   //!
   TBranch        *b_aLeptons_SFerr_trk_eta;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_aLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_aLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltPFQuadJetLooseID15;   //!
   TBranch        *b_ntrgObjects_hltQuadPFCentralJetLooseID45;   //!
   TBranch        *b_nGenHiggsSisters;   //!
   TBranch        *b_GenHiggsSisters_pdgId;   //!
   TBranch        *b_GenHiggsSisters_pt;   //!
   TBranch        *b_GenHiggsSisters_eta;   //!
   TBranch        *b_GenHiggsSisters_phi;   //!
   TBranch        *b_GenHiggsSisters_mass;   //!
   TBranch        *b_GenHiggsSisters_charge;   //!
   TBranch        *b_GenHiggsSisters_status;   //!
   TBranch        *b_GenHiggsSisters_isPromptHard;   //!
   TBranch        *b_ntrgObjects_pfHt;   //!
   TBranch        *b_trgObjects_pfHt_pt;   //!
   TBranch        *b_ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2;   //!
   TBranch        *b_nhjidxaddJetsdR08;   //!
   TBranch        *b_hjidxaddJetsdR08;   //!
   TBranch        *b_nFatjetCA15softdropfilt;   //!
   TBranch        *b_FatjetCA15softdropfilt_pt;   //!
   TBranch        *b_FatjetCA15softdropfilt_eta;   //!
   TBranch        *b_FatjetCA15softdropfilt_phi;   //!
   TBranch        *b_FatjetCA15softdropfilt_mass;   //!
   TBranch        *b_nl1Muons;   //!
   TBranch        *b_l1Muons_pt;   //!
   TBranch        *b_l1Muons_eta;   //!
   TBranch        *b_l1Muons_phi;   //!
   TBranch        *b_l1Muons_qual;   //!
   TBranch        *b_l1Muons_iso;   //!
   TBranch        *b_ntrgObjects_hltMHTNoPU90;   //!
   TBranch        *b_nFatjetAK08ungroomed;   //!
   TBranch        *b_FatjetAK08ungroomed_pt;   //!
   TBranch        *b_FatjetAK08ungroomed_eta;   //!
   TBranch        *b_FatjetAK08ungroomed_phi;   //!
   TBranch        *b_FatjetAK08ungroomed_mass;   //!
   TBranch        *b_FatjetAK08ungroomed_tau1;   //!
   TBranch        *b_FatjetAK08ungroomed_tau2;   //!
   TBranch        *b_FatjetAK08ungroomed_tau3;   //!
   TBranch        *b_FatjetAK08ungroomed_msoftdrop;   //!
   TBranch        *b_FatjetAK08ungroomed_mpruned;   //!
   TBranch        *b_FatjetAK08ungroomed_mprunedcorr;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L2L3;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L1L2L3;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L2L3Unc;   //!
   TBranch        *b_FatjetAK08ungroomed_JEC_L1L2L3Unc;   //!
   TBranch        *b_FatjetAK08ungroomed_bbtag;   //!
   TBranch        *b_FatjetAK08ungroomed_id_Tight;   //!
   TBranch        *b_FatjetAK08ungroomed_numberOfDaughters;   //!
   TBranch        *b_FatjetAK08ungroomed_neutralEmEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_neutralHadronEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_muonEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedEmEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedHadronEnergyFraction;   //!
   TBranch        *b_FatjetAK08ungroomed_chargedMultiplicity;   //!
   TBranch        *b_FatjetAK08ungroomed_electronMultiplicity;   //!
   TBranch        *b_FatjetAK08ungroomed_muonMultiplicity;   //!
   TBranch        *b_FatjetAK08ungroomed_Flavour;   //!
   TBranch        *b_FatjetAK08ungroomed_BhadronFlavour;   //!
   TBranch        *b_FatjetAK08ungroomed_ChadronFlavour;   //!
   TBranch        *b_FatjetAK08ungroomed_GenPt;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_pt;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_eta;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_phi;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_mass;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_tau1;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_tau2;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_msoftdrop;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_msoftdrop_corrL2L3;   //!
   TBranch        *b_FatjetAK08ungroomed_puppi_msoftdrop_raw;   //!
   TBranch        *b_FatjetAK08ungroomed_PFLepton_ptrel;   //!
   TBranch        *b_FatjetAK08ungroomed_PFLepton_IP2D;   //!
   TBranch        *b_FatjetAK08ungroomed_nSL;   //!
   TBranch        *b_FatjetAK08ungroomed_nVtx;   //!
   TBranch        *b_FatjetAK08ungroomed_VtxMass_1;   //!
   TBranch        *b_FatjetAK08ungroomed_VtxMass_2;   //!
   TBranch        *b_nGenWZQuark;   //!
   TBranch        *b_GenWZQuark_pdgId;   //!
   TBranch        *b_GenWZQuark_pt;   //!
   TBranch        *b_GenWZQuark_eta;   //!
   TBranch        *b_GenWZQuark_phi;   //!
   TBranch        *b_GenWZQuark_mass;   //!
   TBranch        *b_GenWZQuark_charge;   //!
   TBranch        *b_GenWZQuark_status;   //!
   TBranch        *b_GenWZQuark_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltPFMHTTightID90;   //!
   TBranch        *b_ntrgObjects_hltQuadCentralJet45;   //!
   TBranch        *b_ntrgObjects_hltBTagCaloCSVp022Single;   //!
   TBranch        *b_nselLeptons;   //!
   TBranch        *b_selLeptons_charge;   //!
   TBranch        *b_selLeptons_tightId;   //!
   TBranch        *b_selLeptons_eleCutIdCSA14_25ns_v1;   //!
   TBranch        *b_selLeptons_eleCutIdCSA14_50ns_v1;   //!
   TBranch        *b_selLeptons_eleCutIdSpring15_25ns_v1;   //!
   TBranch        *b_selLeptons_mediumIdPOG_ICHEP2016;   //!
   TBranch        *b_selLeptons_dxy;   //!
   TBranch        *b_selLeptons_dz;   //!
   TBranch        *b_selLeptons_edxy;   //!
   TBranch        *b_selLeptons_edz;   //!
   TBranch        *b_selLeptons_ip3d;   //!
   TBranch        *b_selLeptons_sip3d;   //!
   TBranch        *b_selLeptons_convVeto;   //!
   TBranch        *b_selLeptons_lostHits;   //!
   TBranch        *b_selLeptons_relIso03;   //!
   TBranch        *b_selLeptons_relIso04;   //!
   TBranch        *b_selLeptons_miniRelIso;   //!
   TBranch        *b_selLeptons_relIsoAn04;   //!
   TBranch        *b_selLeptons_tightCharge;   //!
   TBranch        *b_selLeptons_mcMatchId;   //!
   TBranch        *b_selLeptons_mcMatchAny;   //!
   TBranch        *b_selLeptons_mcMatchTau;   //!
   TBranch        *b_selLeptons_mcPt;   //!
   TBranch        *b_selLeptons_mediumMuonId;   //!
   TBranch        *b_selLeptons_pdgId;   //!
   TBranch        *b_selLeptons_pt;   //!
   TBranch        *b_selLeptons_eta;   //!
   TBranch        *b_selLeptons_phi;   //!
   TBranch        *b_selLeptons_mass;   //!
   TBranch        *b_selLeptons_looseIdSusy;   //!
   TBranch        *b_selLeptons_looseIdPOG;   //!
   TBranch        *b_selLeptons_chargedHadRelIso03;   //!
   TBranch        *b_selLeptons_chargedHadRelIso04;   //!
   TBranch        *b_selLeptons_eleSieie;   //!
   TBranch        *b_selLeptons_eleDEta;   //!
   TBranch        *b_selLeptons_eleDPhi;   //!
   TBranch        *b_selLeptons_eleHoE;   //!
   TBranch        *b_selLeptons_eleMissingHits;   //!
   TBranch        *b_selLeptons_eleChi2;   //!
   TBranch        *b_selLeptons_convVetoFull;   //!
   TBranch        *b_selLeptons_eleMVArawSpring15Trig;   //!
   TBranch        *b_selLeptons_eleMVAIdSpring15Trig;   //!
   TBranch        *b_selLeptons_eleMVArawSpring15NonTrig;   //!
   TBranch        *b_selLeptons_eleMVAIdSpring15NonTrig;   //!
   TBranch        *b_selLeptons_eleMVArawSpring16GenPurp;   //!
   TBranch        *b_selLeptons_eleMVAIdSppring16GenPurp;   //!
   TBranch        *b_selLeptons_nStations;   //!
   TBranch        *b_selLeptons_trkKink;   //!
   TBranch        *b_selLeptons_segmentCompatibility;   //!
   TBranch        *b_selLeptons_caloCompatibility;   //!
   TBranch        *b_selLeptons_globalTrackChi2;   //!
   TBranch        *b_selLeptons_nChamberHits;   //!
   TBranch        *b_selLeptons_isPFMuon;   //!
   TBranch        *b_selLeptons_isGlobalMuon;   //!
   TBranch        *b_selLeptons_isTrackerMuon;   //!
   TBranch        *b_selLeptons_pixelHits;   //!
   TBranch        *b_selLeptons_trackerLayers;   //!
   TBranch        *b_selLeptons_pixelLayers;   //!
   TBranch        *b_selLeptons_mvaTTH;   //!
   TBranch        *b_selLeptons_jetOverlapIdx;   //!
   TBranch        *b_selLeptons_jetPtRatio;   //!
   TBranch        *b_selLeptons_jetBTagCSV;   //!
   TBranch        *b_selLeptons_jetDR;   //!
   TBranch        *b_selLeptons_mvaTTHjetPtRatio;   //!
   TBranch        *b_selLeptons_mvaTTHjetBTagCSV;   //!
   TBranch        *b_selLeptons_mvaTTHjetDR;   //!
   TBranch        *b_selLeptons_pfRelIso03;   //!
   TBranch        *b_selLeptons_pfRelIso04;   //!
   TBranch        *b_selLeptons_etaSc;   //!
   TBranch        *b_selLeptons_eleExpMissingInnerHits;   //!
   TBranch        *b_selLeptons_eleooEmooP;   //!
   TBranch        *b_selLeptons_dr03TkSumPt;   //!
   TBranch        *b_selLeptons_eleEcalClusterIso;   //!
   TBranch        *b_selLeptons_eleHcalClusterIso;   //!
   TBranch        *b_selLeptons_miniIsoCharged;   //!
   TBranch        *b_selLeptons_miniIsoNeutral;   //!
   TBranch        *b_selLeptons_mvaTTHjetPtRel;   //!
   TBranch        *b_selLeptons_mvaTTHjetNDauChargedMVASel;   //!
   TBranch        *b_selLeptons_uncalibratedPt;   //!
   TBranch        *b_selLeptons_SF_IsoLoose;   //!
   TBranch        *b_selLeptons_SFerr_IsoLoose;   //!
   TBranch        *b_selLeptons_SF_IsoTight;   //!
   TBranch        *b_selLeptons_SFerr_IsoTight;   //!
   TBranch        *b_selLeptons_SF_IdCutLoose;   //!
   TBranch        *b_selLeptons_SFerr_IdCutLoose;   //!
   TBranch        *b_selLeptons_SF_IdCutTight;   //!
   TBranch        *b_selLeptons_SFerr_IdCutTight;   //!
   TBranch        *b_selLeptons_SF_IdMVALoose;   //!
   TBranch        *b_selLeptons_SFerr_IdMVALoose;   //!
   TBranch        *b_selLeptons_SF_IdMVATight;   //!
   TBranch        *b_selLeptons_SFerr_IdMVATight;   //!
   TBranch        *b_selLeptons_SF_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_SF_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_SF_HLT_RunC;   //!
   TBranch        *b_selLeptons_SFerr_HLT_RunC;   //!
   TBranch        *b_selLeptons_SF_trk_eta;   //!
   TBranch        *b_selLeptons_SFerr_trk_eta;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunD4p3;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunD4p2;   //!
   TBranch        *b_selLeptons_Eff_HLT_RunC;   //!
   TBranch        *b_selLeptons_Efferr_HLT_RunC;   //!
   TBranch        *b_ntrgObjects_hltPFMET90;   //!
   TBranch        *b_ntrgObjects_hltQuadJet15;   //!
   TBranch        *b_nTauGood;   //!
   TBranch        *b_TauGood_charge;   //!
   TBranch        *b_TauGood_decayMode;   //!
   TBranch        *b_TauGood_idDecayMode;   //!
   TBranch        *b_TauGood_idDecayModeNewDMs;   //!
   TBranch        *b_TauGood_dxy;   //!
   TBranch        *b_TauGood_dz;   //!
   TBranch        *b_TauGood_idMVArun2;   //!
   TBranch        *b_TauGood_rawMVArun2;   //!
   TBranch        *b_TauGood_idMVArun2dR03;   //!
   TBranch        *b_TauGood_rawMVArun2dR03;   //!
   TBranch        *b_TauGood_idMVArun2NewDM;   //!
   TBranch        *b_TauGood_rawMVArun2NewDM;   //!
   TBranch        *b_TauGood_idCI3hit;   //!
   TBranch        *b_TauGood_idAntiMu;   //!
   TBranch        *b_TauGood_idAntiErun2;   //!
   TBranch        *b_TauGood_isoCI3hit;   //!
   TBranch        *b_TauGood_photonOutsideSigCone;   //!
   TBranch        *b_TauGood_mcMatchId;   //!
   TBranch        *b_TauGood_pdgId;   //!
   TBranch        *b_TauGood_pt;   //!
   TBranch        *b_TauGood_eta;   //!
   TBranch        *b_TauGood_phi;   //!
   TBranch        *b_TauGood_mass;   //!
   TBranch        *b_TauGood_idxJetMatch;   //!
   TBranch        *b_TauGood_genMatchType;   //!
   TBranch        *b_nGenStatus2bHad;   //!
   TBranch        *b_GenStatus2bHad_pdgId;   //!
   TBranch        *b_GenStatus2bHad_pt;   //!
   TBranch        *b_GenStatus2bHad_eta;   //!
   TBranch        *b_GenStatus2bHad_phi;   //!
   TBranch        *b_GenStatus2bHad_mass;   //!
   TBranch        *b_GenStatus2bHad_charge;   //!
   TBranch        *b_GenStatus2bHad_status;   //!
   TBranch        *b_GenStatus2bHad_isPromptHard;   //!
   TBranch        *b_nhJidx;   //!
   TBranch        *b_hJidx;   //!
   TBranch        *b_nGenNuFromTau;   //!
   TBranch        *b_GenNuFromTau_pdgId;   //!
   TBranch        *b_GenNuFromTau_pt;   //!
   TBranch        *b_GenNuFromTau_eta;   //!
   TBranch        *b_GenNuFromTau_phi;   //!
   TBranch        *b_GenNuFromTau_mass;   //!
   TBranch        *b_GenNuFromTau_charge;   //!
   TBranch        *b_GenNuFromTau_status;   //!
   TBranch        *b_GenNuFromTau_isPromptHard;   //!
   TBranch        *b_nFatjetCA15softdropz2b1;   //!
   TBranch        *b_FatjetCA15softdropz2b1_pt;   //!
   TBranch        *b_FatjetCA15softdropz2b1_eta;   //!
   TBranch        *b_FatjetCA15softdropz2b1_phi;   //!
   TBranch        *b_FatjetCA15softdropz2b1_mass;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau1;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau2;   //!
   TBranch        *b_FatjetCA15softdropz2b1_tau3;   //!
   TBranch        *b_nGenGluonFromB;   //!
   TBranch        *b_GenGluonFromB_pdgId;   //!
   TBranch        *b_GenGluonFromB_pt;   //!
   TBranch        *b_GenGluonFromB_eta;   //!
   TBranch        *b_GenGluonFromB_phi;   //!
   TBranch        *b_GenGluonFromB_mass;   //!
   TBranch        *b_GenGluonFromB_charge;   //!
   TBranch        *b_GenGluonFromB_status;   //!
   TBranch        *b_GenGluonFromB_isPromptHard;   //!
   TBranch        *b_ntrgObjects_hltTripleJet50;   //!
   TBranch        *b_ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1;   //!
   TBranch        *b_nhttCandidates;   //!
   TBranch        *b_httCandidates_pt;   //!
   TBranch        *b_httCandidates_eta;   //!
   TBranch        *b_httCandidates_phi;   //!
   TBranch        *b_httCandidates_mass;   //!
   TBranch        *b_httCandidates_ptcal;   //!
   TBranch        *b_httCandidates_etacal;   //!
   TBranch        *b_httCandidates_phical;   //!
   TBranch        *b_httCandidates_masscal;   //!
   TBranch        *b_httCandidates_fRec;   //!
   TBranch        *b_httCandidates_Ropt;   //!
   TBranch        *b_httCandidates_RoptCalc;   //!
   TBranch        *b_httCandidates_ptForRoptCalc;   //!
   TBranch        *b_httCandidates_subjetIDPassed;   //!
   TBranch        *b_httCandidates_sjW1ptcal;   //!
   TBranch        *b_httCandidates_sjW1pt;   //!
   TBranch        *b_httCandidates_sjW1eta;   //!
   TBranch        *b_httCandidates_sjW1phi;   //!
   TBranch        *b_httCandidates_sjW1masscal;   //!
   TBranch        *b_httCandidates_sjW1mass;   //!
   TBranch        *b_httCandidates_sjW1btag;   //!
   TBranch        *b_httCandidates_sjW1corr;   //!
   TBranch        *b_httCandidates_sjW2ptcal;   //!
   TBranch        *b_httCandidates_sjW2pt;   //!
   TBranch        *b_httCandidates_sjW2eta;   //!
   TBranch        *b_httCandidates_sjW2phi;   //!
   TBranch        *b_httCandidates_sjW2masscal;   //!
   TBranch        *b_httCandidates_sjW2mass;   //!
   TBranch        *b_httCandidates_sjW2btag;   //!
   TBranch        *b_httCandidates_sjW2corr;   //!
   TBranch        *b_httCandidates_sjNonWptcal;   //!
   TBranch        *b_httCandidates_sjNonWpt;   //!
   TBranch        *b_httCandidates_sjNonWeta;   //!
   TBranch        *b_httCandidates_sjNonWphi;   //!
   TBranch        *b_httCandidates_sjNonWmasscal;   //!
   TBranch        *b_httCandidates_sjNonWmass;   //!
   TBranch        *b_httCandidates_sjNonWbtag;   //!
   TBranch        *b_httCandidates_sjNonWcorr;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteStatUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteStatDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteScaleUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteScaleDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FragmentationUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FragmentationDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SinglePionECALUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SinglePionECALDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SinglePionHCALUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SinglePionHCALDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorQCDUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorQCDDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimePtEtaUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimePtEtaDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJEREC1Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJEREC1Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJEREC2Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJEREC2Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJERHFUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeJERHFDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtBBUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtBBDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtEC1Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtEC1Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtEC2Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtEC2Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtHFUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativePtHFDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeBalUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeBalDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeFSRUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeFSRDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatFSRUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatFSRDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatECUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatECDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatHFUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_RelativeStatHFDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpDataMCUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpDataMCDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtRefUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtRefDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtBBUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtBBDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtEC1Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtEC1Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtEC2Up;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtEC2Down;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtHFUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpPtHFDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpMuZeroUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpMuZeroDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalPileUpUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalPileUpDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalRelativeUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalRelativeDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalPtUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalPtDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalScaleUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalScaleDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalMCUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_SubTotalMCDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoFlavorUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoFlavorDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoTimeUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoTimeDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorZJetUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorZJetDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureGluonUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureGluonDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureCharmUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureCharmDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureBottomUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_FlavorPureBottomDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunBCDUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunBCDDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunEFUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunEFDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunGUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunGDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunHUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_TimeRunHDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_httCandidates_sjW1_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteStatUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteStatDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteScaleUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteScaleDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FragmentationUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FragmentationDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SinglePionECALUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SinglePionECALDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SinglePionHCALUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SinglePionHCALDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorQCDUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorQCDDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimePtEtaUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimePtEtaDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJEREC1Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJEREC1Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJEREC2Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJEREC2Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJERHFUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeJERHFDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtBBUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtBBDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtEC1Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtEC1Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtEC2Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtEC2Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtHFUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativePtHFDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeBalUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeBalDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeFSRUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeFSRDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatFSRUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatFSRDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatECUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatECDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatHFUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_RelativeStatHFDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpDataMCUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpDataMCDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtRefUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtRefDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtBBUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtBBDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtEC1Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtEC1Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtEC2Up;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtEC2Down;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtHFUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpPtHFDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpMuZeroUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpMuZeroDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalPileUpUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalPileUpDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalRelativeUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalRelativeDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalPtUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalPtDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalScaleUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalScaleDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalMCUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_SubTotalMCDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoFlavorUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoFlavorDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoTimeUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoTimeDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorZJetUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorZJetDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureGluonUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureGluonDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureCharmUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureCharmDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureBottomUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_FlavorPureBottomDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunBCDUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunBCDDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunEFUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunEFDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunGUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunGDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunHUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_TimeRunHDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_httCandidates_sjW2_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteStatUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteStatDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteScaleUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteScaleDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FragmentationUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FragmentationDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SinglePionECALUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SinglePionECALDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SinglePionHCALUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SinglePionHCALDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorQCDUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorQCDDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimePtEtaUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimePtEtaDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJEREC1Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJEREC1Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJEREC2Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJEREC2Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJERHFUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeJERHFDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtBBUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtBBDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtEC1Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtEC1Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtEC2Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtEC2Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtHFUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativePtHFDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeBalUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeBalDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeFSRUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeFSRDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatFSRUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatFSRDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatECUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatECDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatHFUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_RelativeStatHFDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpDataMCUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpDataMCDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtRefUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtRefDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtBBUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtBBDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtEC1Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtEC1Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtEC2Up;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtEC2Down;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtHFUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpPtHFDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpMuZeroUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpMuZeroDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalPileUpUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalPileUpDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalRelativeUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalRelativeDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalPtUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalPtDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalScaleUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalScaleDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalMCUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_SubTotalMCDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoFlavorUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoFlavorDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoTimeUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoTimeDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorZJetUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorZJetDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureGluonUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureGluonDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureCharmUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureCharmDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureBottomUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_FlavorPureBottomDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunBCDUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunBCDDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunEFUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunEFDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunGUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunGDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunHUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_TimeRunHDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_nGenTop;   //!
   TBranch        *b_GenTop_charge;   //!
   TBranch        *b_GenTop_status;   //!
   TBranch        *b_GenTop_isPromptHard;   //!
   TBranch        *b_GenTop_pdgId;   //!
   TBranch        *b_GenTop_pt;   //!
   TBranch        *b_GenTop_eta;   //!
   TBranch        *b_GenTop_phi;   //!
   TBranch        *b_GenTop_mass;   //!
   TBranch        *b_GenTop_decayMode;   //!
   TBranch        *b_nGenTaus;   //!
   TBranch        *b_GenTaus_charge;   //!
   TBranch        *b_GenTaus_status;   //!
   TBranch        *b_GenTaus_isPromptHard;   //!
   TBranch        *b_GenTaus_pdgId;   //!
   TBranch        *b_GenTaus_pt;   //!
   TBranch        *b_GenTaus_eta;   //!
   TBranch        *b_GenTaus_phi;   //!
   TBranch        *b_GenTaus_mass;   //!
   TBranch        *b_GenTaus_motherId;   //!
   TBranch        *b_GenTaus_grandmotherId;   //!
   TBranch        *b_GenTaus_sourceId;   //!
   TBranch        *b_ntrgObjects_hltMHT70;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_id;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btagCSV;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_rawPt;   //!
   TBranch        *b_Jet_mcPt;   //!
   TBranch        *b_Jet_mcFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_mcMatchId;   //!
   TBranch        *b_Jet_corr_JECUp;   //!
   TBranch        *b_Jet_corr_JECDown;   //!
   TBranch        *b_Jet_corr;   //!
   TBranch        *b_Jet_corr_JERUp;   //!
   TBranch        *b_Jet_corr_JERDown;   //!
   TBranch        *b_Jet_corr_JER;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_rawPtAfterSmearing;   //!
   TBranch        *b_Jet_idxFirstTauMatch;   //!
   TBranch        *b_Jet_heppyFlavour;   //!
   TBranch        *b_Jet_ctagVsL;   //!
   TBranch        *b_Jet_ctagVsB;   //!
   TBranch        *b_Jet_btagBDT;   //!
   TBranch        *b_Jet_btagProb;   //!
   TBranch        *b_Jet_btagBProb;   //!
   TBranch        *b_Jet_btagSoftEl;   //!
   TBranch        *b_Jet_btagSoftMu;   //!
   TBranch        *b_Jet_btagDeepCSVdusg;   //!
   TBranch        *b_Jet_btagDeepCSVb;   //!
   TBranch        *b_Jet_btagDeepCSVc;   //!
   TBranch        *b_Jet_btagDeepCSVbb;   //!
   TBranch        *b_Jet_btagDeepCMVAdusg;   //!
   TBranch        *b_Jet_btagDeepCMVAb;   //!
   TBranch        *b_Jet_btagDeepCMVAc;   //!
   TBranch        *b_Jet_btagDeepCMVAbb;   //!
   TBranch        *b_Jet_btagCSVV0;   //!
   TBranch        *b_Jet_btagCMVAV2;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_chMult;   //!
   TBranch        *b_Jet_nhMult;   //!
   TBranch        *b_Jet_leadTrackPt;   //!
   TBranch        *b_Jet_mcEta;   //!
   TBranch        *b_Jet_mcPhi;   //!
   TBranch        *b_Jet_mcM;   //!
   TBranch        *b_Jet_leptonPdgId;   //!
   TBranch        *b_Jet_leptonPt;   //!
   TBranch        *b_Jet_leptonPtRel;   //!
   TBranch        *b_Jet_leptonPtRelInv;   //!
   TBranch        *b_Jet_leptonDeltaR;   //!
   TBranch        *b_Jet_leptonDeltaPhi;   //!
   TBranch        *b_Jet_leptonDeltaEta;   //!
   TBranch        *b_Jet_vtxMass;   //!
   TBranch        *b_Jet_vtxNtracks;   //!
   TBranch        *b_Jet_vtxPt;   //!
   TBranch        *b_Jet_vtx3DSig;   //!
   TBranch        *b_Jet_vtx3DVal;   //!
   TBranch        *b_Jet_vtxPosX;   //!
   TBranch        *b_Jet_vtxPosY;   //!
   TBranch        *b_Jet_vtxPosZ;   //!
   TBranch        *b_Jet_pullVectorPhi;   //!
   TBranch        *b_Jet_pullVectorMag;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_ptd;   //!
   TBranch        *b_Jet_axis2;   //!
   TBranch        *b_Jet_mult;   //!
   TBranch        *b_Jet_numberOfDaughters;   //!
   TBranch        *b_Jet_btagIdx;   //!
   TBranch        *b_Jet_btagCmvaIdx;   //!
   TBranch        *b_Jet_mcIdx;   //!
   TBranch        *b_Jet_blike_VBF;   //!
   TBranch        *b_Jet_pt_puppi;   //!
   TBranch        *b_Jet_energyRing_dR0_em;   //!
   TBranch        *b_Jet_energyRing_dR1_em;   //!
   TBranch        *b_Jet_energyRing_dR2_em;   //!
   TBranch        *b_Jet_energyRing_dR3_em;   //!
   TBranch        *b_Jet_energyRing_dR4_em;   //!
   TBranch        *b_Jet_energyRing_dR5_em;   //!
   TBranch        *b_Jet_energyRing_dR0_mu;   //!
   TBranch        *b_Jet_energyRing_dR1_mu;   //!
   TBranch        *b_Jet_energyRing_dR2_mu;   //!
   TBranch        *b_Jet_energyRing_dR3_mu;   //!
   TBranch        *b_Jet_energyRing_dR4_mu;   //!
   TBranch        *b_Jet_energyRing_dR5_mu;   //!
   TBranch        *b_Jet_energyRing_dR0_ch;   //!
   TBranch        *b_Jet_energyRing_dR1_ch;   //!
   TBranch        *b_Jet_energyRing_dR2_ch;   //!
   TBranch        *b_Jet_energyRing_dR3_ch;   //!
   TBranch        *b_Jet_energyRing_dR4_ch;   //!
   TBranch        *b_Jet_energyRing_dR5_ch;   //!
   TBranch        *b_Jet_energyRing_dR0_neut;   //!
   TBranch        *b_Jet_energyRing_dR1_neut;   //!
   TBranch        *b_Jet_energyRing_dR2_neut;   //!
   TBranch        *b_Jet_energyRing_dR3_neut;   //!
   TBranch        *b_Jet_energyRing_dR4_neut;   //!
   TBranch        *b_Jet_energyRing_dR5_neut;   //!
   TBranch        *b_Jet_numDaughters_pt03;   //!
   TBranch        *b_Jet_rawEnergy;   //!
   TBranch        *b_Jet_pt_reg;   //!
   TBranch        *b_Jet_pt_regVBF;   //!
   TBranch        *b_Jet_pt_reg_corrJECUp;   //!
   TBranch        *b_Jet_pt_regVBF_corrJECUp;   //!
   TBranch        *b_Jet_pt_reg_corrJECDown;   //!
   TBranch        *b_Jet_pt_regVBF_corrJECDown;   //!
   TBranch        *b_Jet_pt_reg_corrJERUp;   //!
   TBranch        *b_Jet_pt_regVBF_corrJERUp;   //!
   TBranch        *b_Jet_pt_reg_corrJERDown;   //!
   TBranch        *b_Jet_pt_regVBF_corrJERDown;   //!
   TBranch        *b_Jet_btagCSVL_SF;   //!
   TBranch        *b_Jet_btagCSVL_SF_up;   //!
   TBranch        *b_Jet_btagCSVL_SF_down;   //!
   TBranch        *b_Jet_btagCSVM_SF;   //!
   TBranch        *b_Jet_btagCSVM_SF_up;   //!
   TBranch        *b_Jet_btagCSVM_SF_down;   //!
   TBranch        *b_Jet_btagCSVT_SF;   //!
   TBranch        *b_Jet_btagCSVT_SF_up;   //!
   TBranch        *b_Jet_btagCSVT_SF_down;   //!
   TBranch        *b_Jet_btagWeightCSV;   //!
   TBranch        *b_Jet_btagWeightCSV_up_jes;   //!
   TBranch        *b_Jet_btagWeightCSV_down_jes;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lf;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lf;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hf;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hf;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCSV_up_cferr1;   //!
   TBranch        *b_Jet_btagWeightCSV_down_cferr1;   //!
   TBranch        *b_Jet_btagWeightCSV_up_cferr2;   //!
   TBranch        *b_Jet_btagWeightCSV_down_cferr2;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2L_SF_down;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2M_SF_down;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF_up;   //!
   TBranch        *b_Jet_btagCMVAV2T_SF_down;   //!
   TBranch        *b_Jet_btagWeightCMVAV2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_jes;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_jes;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hf;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_hfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lfstats1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_lfstats2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_cferr1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_cferr1;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_up_cferr2;   //!
   TBranch        *b_Jet_btagWeightCMVAV2_down_cferr2;   //!
   TBranch        *b_Jet_corr_AbsoluteStatUp;   //!
   TBranch        *b_Jet_corr_AbsoluteStatDown;   //!
   TBranch        *b_Jet_corr_AbsoluteScaleUp;   //!
   TBranch        *b_Jet_corr_AbsoluteScaleDown;   //!
   TBranch        *b_Jet_corr_AbsoluteFlavMapUp;   //!
   TBranch        *b_Jet_corr_AbsoluteFlavMapDown;   //!
   TBranch        *b_Jet_corr_AbsoluteMPFBiasUp;   //!
   TBranch        *b_Jet_corr_AbsoluteMPFBiasDown;   //!
   TBranch        *b_Jet_corr_FragmentationUp;   //!
   TBranch        *b_Jet_corr_FragmentationDown;   //!
   TBranch        *b_Jet_corr_SinglePionECALUp;   //!
   TBranch        *b_Jet_corr_SinglePionECALDown;   //!
   TBranch        *b_Jet_corr_SinglePionHCALUp;   //!
   TBranch        *b_Jet_corr_SinglePionHCALDown;   //!
   TBranch        *b_Jet_corr_FlavorQCDUp;   //!
   TBranch        *b_Jet_corr_FlavorQCDDown;   //!
   TBranch        *b_Jet_corr_TimePtEtaUp;   //!
   TBranch        *b_Jet_corr_TimePtEtaDown;   //!
   TBranch        *b_Jet_corr_RelativeJEREC1Up;   //!
   TBranch        *b_Jet_corr_RelativeJEREC1Down;   //!
   TBranch        *b_Jet_corr_RelativeJEREC2Up;   //!
   TBranch        *b_Jet_corr_RelativeJEREC2Down;   //!
   TBranch        *b_Jet_corr_RelativeJERHFUp;   //!
   TBranch        *b_Jet_corr_RelativeJERHFDown;   //!
   TBranch        *b_Jet_corr_RelativePtBBUp;   //!
   TBranch        *b_Jet_corr_RelativePtBBDown;   //!
   TBranch        *b_Jet_corr_RelativePtEC1Up;   //!
   TBranch        *b_Jet_corr_RelativePtEC1Down;   //!
   TBranch        *b_Jet_corr_RelativePtEC2Up;   //!
   TBranch        *b_Jet_corr_RelativePtEC2Down;   //!
   TBranch        *b_Jet_corr_RelativePtHFUp;   //!
   TBranch        *b_Jet_corr_RelativePtHFDown;   //!
   TBranch        *b_Jet_corr_RelativeBalUp;   //!
   TBranch        *b_Jet_corr_RelativeBalDown;   //!
   TBranch        *b_Jet_corr_RelativeFSRUp;   //!
   TBranch        *b_Jet_corr_RelativeFSRDown;   //!
   TBranch        *b_Jet_corr_RelativeStatFSRUp;   //!
   TBranch        *b_Jet_corr_RelativeStatFSRDown;   //!
   TBranch        *b_Jet_corr_RelativeStatECUp;   //!
   TBranch        *b_Jet_corr_RelativeStatECDown;   //!
   TBranch        *b_Jet_corr_RelativeStatHFUp;   //!
   TBranch        *b_Jet_corr_RelativeStatHFDown;   //!
   TBranch        *b_Jet_corr_PileUpDataMCUp;   //!
   TBranch        *b_Jet_corr_PileUpDataMCDown;   //!
   TBranch        *b_Jet_corr_PileUpPtRefUp;   //!
   TBranch        *b_Jet_corr_PileUpPtRefDown;   //!
   TBranch        *b_Jet_corr_PileUpPtBBUp;   //!
   TBranch        *b_Jet_corr_PileUpPtBBDown;   //!
   TBranch        *b_Jet_corr_PileUpPtEC1Up;   //!
   TBranch        *b_Jet_corr_PileUpPtEC1Down;   //!
   TBranch        *b_Jet_corr_PileUpPtEC2Up;   //!
   TBranch        *b_Jet_corr_PileUpPtEC2Down;   //!
   TBranch        *b_Jet_corr_PileUpPtHFUp;   //!
   TBranch        *b_Jet_corr_PileUpPtHFDown;   //!
   TBranch        *b_Jet_corr_PileUpMuZeroUp;   //!
   TBranch        *b_Jet_corr_PileUpMuZeroDown;   //!
   TBranch        *b_Jet_corr_PileUpEnvelopeUp;   //!
   TBranch        *b_Jet_corr_PileUpEnvelopeDown;   //!
   TBranch        *b_Jet_corr_SubTotalPileUpUp;   //!
   TBranch        *b_Jet_corr_SubTotalPileUpDown;   //!
   TBranch        *b_Jet_corr_SubTotalRelativeUp;   //!
   TBranch        *b_Jet_corr_SubTotalRelativeDown;   //!
   TBranch        *b_Jet_corr_SubTotalPtUp;   //!
   TBranch        *b_Jet_corr_SubTotalPtDown;   //!
   TBranch        *b_Jet_corr_SubTotalScaleUp;   //!
   TBranch        *b_Jet_corr_SubTotalScaleDown;   //!
   TBranch        *b_Jet_corr_SubTotalAbsoluteUp;   //!
   TBranch        *b_Jet_corr_SubTotalAbsoluteDown;   //!
   TBranch        *b_Jet_corr_SubTotalMCUp;   //!
   TBranch        *b_Jet_corr_SubTotalMCDown;   //!
   TBranch        *b_Jet_corr_TotalUp;   //!
   TBranch        *b_Jet_corr_TotalDown;   //!
   TBranch        *b_Jet_corr_TotalNoFlavorUp;   //!
   TBranch        *b_Jet_corr_TotalNoFlavorDown;   //!
   TBranch        *b_Jet_corr_TotalNoTimeUp;   //!
   TBranch        *b_Jet_corr_TotalNoTimeDown;   //!
   TBranch        *b_Jet_corr_TotalNoFlavorNoTimeUp;   //!
   TBranch        *b_Jet_corr_TotalNoFlavorNoTimeDown;   //!
   TBranch        *b_Jet_corr_FlavorZJetUp;   //!
   TBranch        *b_Jet_corr_FlavorZJetDown;   //!
   TBranch        *b_Jet_corr_FlavorPhotonJetUp;   //!
   TBranch        *b_Jet_corr_FlavorPhotonJetDown;   //!
   TBranch        *b_Jet_corr_FlavorPureGluonUp;   //!
   TBranch        *b_Jet_corr_FlavorPureGluonDown;   //!
   TBranch        *b_Jet_corr_FlavorPureQuarkUp;   //!
   TBranch        *b_Jet_corr_FlavorPureQuarkDown;   //!
   TBranch        *b_Jet_corr_FlavorPureCharmUp;   //!
   TBranch        *b_Jet_corr_FlavorPureCharmDown;   //!
   TBranch        *b_Jet_corr_FlavorPureBottomUp;   //!
   TBranch        *b_Jet_corr_FlavorPureBottomDown;   //!
   TBranch        *b_Jet_corr_TimeRunBCDUp;   //!
   TBranch        *b_Jet_corr_TimeRunBCDDown;   //!
   TBranch        *b_Jet_corr_TimeRunEFUp;   //!
   TBranch        *b_Jet_corr_TimeRunEFDown;   //!
   TBranch        *b_Jet_corr_TimeRunGUp;   //!
   TBranch        *b_Jet_corr_TimeRunGDown;   //!
   TBranch        *b_Jet_corr_TimeRunHUp;   //!
   TBranch        *b_Jet_corr_TimeRunHDown;   //!
   TBranch        *b_Jet_corr_CorrelationGroupMPFInSituUp;   //!
   TBranch        *b_Jet_corr_CorrelationGroupMPFInSituDown;   //!
   TBranch        *b_Jet_corr_CorrelationGroupIntercalibrationUp;   //!
   TBranch        *b_Jet_corr_CorrelationGroupIntercalibrationDown;   //!
   TBranch        *b_Jet_corr_CorrelationGroupbJESUp;   //!
   TBranch        *b_Jet_corr_CorrelationGroupbJESDown;   //!
   TBranch        *b_Jet_corr_CorrelationGroupFlavorUp;   //!
   TBranch        *b_Jet_corr_CorrelationGroupFlavorDown;   //!
   TBranch        *b_Jet_corr_CorrelationGroupUncorrelatedUp;   //!
   TBranch        *b_Jet_corr_CorrelationGroupUncorrelatedDown;   //!
   TBranch        *b_nFatjetCA15softdrop;   //!
   TBranch        *b_FatjetCA15softdrop_pt;   //!
   TBranch        *b_FatjetCA15softdrop_eta;   //!
   TBranch        *b_FatjetCA15softdrop_phi;   //!
   TBranch        *b_FatjetCA15softdrop_mass;   //!
   TBranch        *b_ntrgObjects_hltPFTripleJetLooseID64;   //!
   TBranch        *b_nLHE_weights_pdf;   //!
   TBranch        *b_LHE_weights_pdf_id;   //!
   TBranch        *b_LHE_weights_pdf_wgt;   //!
   TBranch        *b_ntrgObjects_caloMhtNoPU;   //!
   TBranch        *b_trgObjects_caloMhtNoPU_pt;   //!
   TBranch        *b_nGenLep;   //!
   TBranch        *b_GenLep_charge;   //!
   TBranch        *b_GenLep_status;   //!
   TBranch        *b_GenLep_isPromptHard;   //!
   TBranch        *b_GenLep_pdgId;   //!
   TBranch        *b_GenLep_pt;   //!
   TBranch        *b_GenLep_eta;   //!
   TBranch        *b_GenLep_phi;   //!
   TBranch        *b_GenLep_mass;   //!
   TBranch        *b_GenLep_motherId;   //!
   TBranch        *b_GenLep_grandmotherId;   //!
   TBranch        *b_GenLep_sourceId;   //!
   TBranch        *b_nGenGluonFromTop;   //!
   TBranch        *b_GenGluonFromTop_pdgId;   //!
   TBranch        *b_GenGluonFromTop_pt;   //!
   TBranch        *b_GenGluonFromTop_eta;   //!
   TBranch        *b_GenGluonFromTop_phi;   //!
   TBranch        *b_GenGluonFromTop_mass;   //!
   TBranch        *b_GenGluonFromTop_charge;   //!
   TBranch        *b_GenGluonFromTop_status;   //!
   TBranch        *b_GenGluonFromTop_isPromptHard;   //!
   TBranch        *b_nsoftActivityJets;   //!
   TBranch        *b_softActivityJets_pt;   //!
   TBranch        *b_softActivityJets_eta;   //!
   TBranch        *b_softActivityJets_phi;   //!
   TBranch        *b_softActivityJets_mass;   //!
   TBranch        *b_nFatjetCA15subjetfiltered;   //!
   TBranch        *b_FatjetCA15subjetfiltered_pt;   //!
   TBranch        *b_FatjetCA15subjetfiltered_eta;   //!
   TBranch        *b_FatjetCA15subjetfiltered_phi;   //!
   TBranch        *b_FatjetCA15subjetfiltered_mass;   //!
   TBranch        *b_ntrgObjects_hltSingleJet80;   //!

   skim_trees_macro_breg(TString filename="");
   virtual ~skim_trees_macro_breg();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TString filename="");
   virtual void     Loop(TString outputfilename="skimmed_tree.root"); //no need in input_filename anymore
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
	virtual void	  AddFile(TString filename="");
};

#endif

#ifdef skim_trees_macro_breg_cxx
skim_trees_macro_breg::skim_trees_macro_breg(TString filename) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
//   if (tree == 0) {
			file_name = filename;
 //     	TFile *f = TFile::Open(file_name);
  //    	f->GetObject("tree",tree);
//   }
   Init(file_name); //file_name
}
void skim_trees_macro_breg::AddFile(TString filename)
{
	file_name = filename;
	fChain->Add(file_name);
	TFile *add_file = TFile::Open(file_name);
	Count->Add((TH1F*)add_file->Get("Count"));
	CountPosWeight->Add((TH1F*)add_file->Get("CountPosWeight"));
	CountNegWeight->Add((TH1F*)add_file->Get("CountNegWeight"));
	CountWeighted->Add((TH1F*)add_file->Get("CountWeighted"));
	CountFullWeighted->Add((TH1F*)add_file->Get("CountFullWeighted"));
	CountWeightedLHEWeightScale->Add((TH1F*)add_file->Get("CountWeightedLHEWeightScale"));
	CountWeightedLHEWeightPdf->Add((TH1F*)add_file->Get("CountWeightedLHEWeightPdf"));
//	cout<< "File "<<file_name<< "  is successfully added"<<endl;
}

skim_trees_macro_breg::~skim_trees_macro_breg()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t skim_trees_macro_breg::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t skim_trees_macro_breg::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void skim_trees_macro_breg::Init(TString filename)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
	file_name = filename;
	TFile *input_file = TFile::Open(file_name);
   fChain = new TChain("tree");
   fChain->Add(file_name);
	Count = (TH1F*)input_file->Get("Count");
	CountPosWeight = (TH1F*)input_file->Get("CountPosWeight");
	CountNegWeight =(TH1F*)input_file->Get("CountNegWeight");
	CountWeighted =(TH1F*)input_file->Get("CountWeighted");
	CountFullWeighted  = (TH1F*)input_file->Get("CountFullWeighted");
	CountWeightedLHEWeightScale  = (TH1F*)input_file->Get("CountWeightedLHEWeightScale");
	CountWeightedLHEWeightPdf  = (TH1F*)input_file->Get("CountWeightedLHEWeightPdf");
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("nTrueInt", &nTrueInt, &b_nTrueInt);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("puWeightDown", &puWeightDown, &b_puWeightDown);
   fChain->SetBranchAddress("json", &json, &b_json);
   fChain->SetBranchAddress("json_silver", &json_silver, &b_json_silver);
   fChain->SetBranchAddress("nPU0", &nPU0, &b_nPU0);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("Vtype", &Vtype, &b_Vtype);
   fChain->SetBranchAddress("VtypeSim", &VtypeSim, &b_VtypeSim);
   fChain->SetBranchAddress("VMt", &VMt, &b_VMt);
   fChain->SetBranchAddress("HVdPhi", &HVdPhi, &b_HVdPhi);
   fChain->SetBranchAddress("fakeMET_sumet", &fakeMET_sumet, &b_fakeMET_sumet);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("caloMetPt", &caloMetPt, &b_caloMetPt);
   fChain->SetBranchAddress("caloMetPhi", &caloMetPhi, &b_caloMetPhi);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoN", &rhoN, &b_rhoN);
   fChain->SetBranchAddress("rhoCHPU", &rhoCHPU, &b_rhoCHPU);
   fChain->SetBranchAddress("rhoCentral", &rhoCentral, &b_rhoCentral);
   fChain->SetBranchAddress("deltaR_jj", &deltaR_jj, &b_deltaR_jj);
   fChain->SetBranchAddress("lheNj", &lheNj, &b_lheNj);
   fChain->SetBranchAddress("lheNb", &lheNb, &b_lheNb);
   fChain->SetBranchAddress("lheNc", &lheNc, &b_lheNc);
   fChain->SetBranchAddress("lheNg", &lheNg, &b_lheNg);
   fChain->SetBranchAddress("lheNl", &lheNl, &b_lheNl);
   fChain->SetBranchAddress("lheV_pt", &lheV_pt, &b_lheV_pt);
   fChain->SetBranchAddress("lheHT", &lheHT, &b_lheHT);
   fChain->SetBranchAddress("genTTHtoTauTauDecayMode", &genTTHtoTauTauDecayMode, &b_genTTHtoTauTauDecayMode);
   fChain->SetBranchAddress("ttCls", &ttCls, &b_ttCls);
   fChain->SetBranchAddress("heavyFlavourCategory", &heavyFlavourCategory, &b_heavyFlavourCategory);
   fChain->SetBranchAddress("mhtJet30", &mhtJet30, &b_mhtJet30);
   fChain->SetBranchAddress("mhtPhiJet30", &mhtPhiJet30, &b_mhtPhiJet30);
   fChain->SetBranchAddress("htJet30", &htJet30, &b_htJet30);
   fChain->SetBranchAddress("met_sig", &met_sig, &b_met_sig);
   fChain->SetBranchAddress("met_covXX", &met_covXX, &b_met_covXX);
   fChain->SetBranchAddress("met_covXY", &met_covXY, &b_met_covXY);
   fChain->SetBranchAddress("met_covYY", &met_covYY, &b_met_covYY);
   fChain->SetBranchAddress("met_rawpt", &met_rawpt, &b_met_rawpt);
   fChain->SetBranchAddress("metPuppi_pt", &metPuppi_pt, &b_metPuppi_pt);
   fChain->SetBranchAddress("metPuppi_phi", &metPuppi_phi, &b_metPuppi_phi);
   fChain->SetBranchAddress("metPuppi_rawpt", &metPuppi_rawpt, &b_metPuppi_rawpt);
   fChain->SetBranchAddress("metType1p2_pt", &metType1p2_pt, &b_metType1p2_pt);
   fChain->SetBranchAddress("tkMet_pt", &tkMet_pt, &b_tkMet_pt);
   fChain->SetBranchAddress("tkMet_phi", &tkMet_phi, &b_tkMet_phi);
   fChain->SetBranchAddress("isrJetVH", &isrJetVH, &b_isrJetVH);
   fChain->SetBranchAddress("simPrimaryVertex_z", &simPrimaryVertex_z, &b_simPrimaryVertex_z);
   fChain->SetBranchAddress("genHiggsDecayMode", &genHiggsDecayMode, &b_genHiggsDecayMode);
   fChain->SetBranchAddress("triggerEmulationWeight", &triggerEmulationWeight, &b_triggerEmulationWeight);
   fChain->SetBranchAddress("btagWeightCSV_down_cferr1", &btagWeightCSV_down_cferr1, &b_btagWeightCSV_down_cferr1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hfstats1", &btagWeightCMVAV2_down_hfstats1, &b_btagWeightCMVAV2_down_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hfstats2", &btagWeightCMVAV2_down_hfstats2, &b_btagWeightCMVAV2_down_hfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_cferr2", &btagWeightCSV_down_cferr2, &b_btagWeightCSV_down_cferr2);
   fChain->SetBranchAddress("btagWeightCSV_down_jes", &btagWeightCSV_down_jes, &b_btagWeightCSV_down_jes);
   fChain->SetBranchAddress("btagWeightCSV_down_lf", &btagWeightCSV_down_lf, &b_btagWeightCSV_down_lf);
   fChain->SetBranchAddress("btagWeightCSV_up_lf", &btagWeightCSV_up_lf, &b_btagWeightCSV_up_lf);
   fChain->SetBranchAddress("btagWeightCSV_down_lfstats2", &btagWeightCSV_down_lfstats2, &b_btagWeightCSV_down_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_lfstats1", &btagWeightCSV_down_lfstats1, &b_btagWeightCSV_down_lfstats1);
   fChain->SetBranchAddress("btagWeightCSV_down_hf", &btagWeightCSV_down_hf, &b_btagWeightCSV_down_hf);
   fChain->SetBranchAddress("btagWeightCSV_up_lfstats1", &btagWeightCSV_up_lfstats1, &b_btagWeightCSV_up_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lf", &btagWeightCMVAV2_down_lf, &b_btagWeightCMVAV2_down_lf);
   fChain->SetBranchAddress("btagWeightCSV_up_lfstats2", &btagWeightCSV_up_lfstats2, &b_btagWeightCSV_up_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV", &btagWeightCSV, &b_btagWeightCSV);
   fChain->SetBranchAddress("btagWeightCSV_up_cferr2", &btagWeightCSV_up_cferr2, &b_btagWeightCSV_up_cferr2);
   fChain->SetBranchAddress("btagWeightCSV_up_cferr1", &btagWeightCSV_up_cferr1, &b_btagWeightCSV_up_cferr1);
   fChain->SetBranchAddress("btagWeightCSV_up_hf", &btagWeightCSV_up_hf, &b_btagWeightCSV_up_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_hf", &btagWeightCMVAV2_down_hf, &b_btagWeightCMVAV2_down_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lfstats2", &btagWeightCMVAV2_up_lfstats2, &b_btagWeightCMVAV2_up_lfstats2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hfstats2", &btagWeightCMVAV2_up_hfstats2, &b_btagWeightCMVAV2_up_hfstats2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hfstats1", &btagWeightCMVAV2_up_hfstats1, &b_btagWeightCMVAV2_up_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2", &btagWeightCMVAV2, &b_btagWeightCMVAV2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lfstats1", &btagWeightCMVAV2_up_lfstats1, &b_btagWeightCMVAV2_up_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_cferr2", &btagWeightCMVAV2_down_cferr2, &b_btagWeightCMVAV2_down_cferr2);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_hf", &btagWeightCMVAV2_up_hf, &b_btagWeightCMVAV2_up_hf);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_cferr1", &btagWeightCMVAV2_down_cferr1, &b_btagWeightCMVAV2_down_cferr1);
   fChain->SetBranchAddress("btagWeightCSV_up_jes", &btagWeightCSV_up_jes, &b_btagWeightCSV_up_jes);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_jes", &btagWeightCMVAV2_up_jes, &b_btagWeightCMVAV2_up_jes);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_lf", &btagWeightCMVAV2_up_lf, &b_btagWeightCMVAV2_up_lf);
   fChain->SetBranchAddress("btagWeightCSV_down_hfstats2", &btagWeightCSV_down_hfstats2, &b_btagWeightCSV_down_hfstats2);
   fChain->SetBranchAddress("btagWeightCSV_down_hfstats1", &btagWeightCSV_down_hfstats1, &b_btagWeightCSV_down_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_cferr1", &btagWeightCMVAV2_up_cferr1, &b_btagWeightCMVAV2_up_cferr1);
   fChain->SetBranchAddress("btagWeightCMVAV2_up_cferr2", &btagWeightCMVAV2_up_cferr2, &b_btagWeightCMVAV2_up_cferr2);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lfstats1", &btagWeightCMVAV2_down_lfstats1, &b_btagWeightCMVAV2_down_lfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_lfstats2", &btagWeightCMVAV2_down_lfstats2, &b_btagWeightCMVAV2_down_lfstats2);
   fChain->SetBranchAddress("btagWeightCSV_up_hfstats1", &btagWeightCSV_up_hfstats1, &b_btagWeightCSV_up_hfstats1);
   fChain->SetBranchAddress("btagWeightCMVAV2_down_jes", &btagWeightCMVAV2_down_jes, &b_btagWeightCMVAV2_down_jes);
   fChain->SetBranchAddress("btagWeightCSV_up_hfstats2", &btagWeightCSV_up_hfstats2, &b_btagWeightCSV_up_hfstats2);
   fChain->SetBranchAddress("ZllKinFit_corrJERUp_mass", &ZllKinFit_corrJERUp_mass, &b_ZllKinFit_corrJERUp_mass);
   fChain->SetBranchAddress("ZllKinFit_status", &ZllKinFit_status, &b_ZllKinFit_status);
   fChain->SetBranchAddress("ZllKinFit_corrJERDown_status", &ZllKinFit_corrJERDown_status, &b_ZllKinFit_corrJERDown_status);
   fChain->SetBranchAddress("ZllKinFit_corrJECDown_status", &ZllKinFit_corrJECDown_status, &b_ZllKinFit_corrJECDown_status);
   fChain->SetBranchAddress("ZllKinFit_njet", &ZllKinFit_njet, &b_ZllKinFit_njet);
   fChain->SetBranchAddress("ZllKinFit_corrJECDown_njet", &ZllKinFit_corrJECDown_njet, &b_ZllKinFit_corrJECDown_njet);
   fChain->SetBranchAddress("ZllKinFit_corrJERUp_njet", &ZllKinFit_corrJERUp_njet, &b_ZllKinFit_corrJERUp_njet);
   fChain->SetBranchAddress("ZllKinFit_corrJERUp_status", &ZllKinFit_corrJERUp_status, &b_ZllKinFit_corrJERUp_status);
   fChain->SetBranchAddress("ZllKinFit_corrJECUp_njet", &ZllKinFit_corrJECUp_njet, &b_ZllKinFit_corrJECUp_njet);
   fChain->SetBranchAddress("ZllKinFit_mass", &ZllKinFit_mass, &b_ZllKinFit_mass);
   fChain->SetBranchAddress("ZllKinFit_corrJERDown_mass", &ZllKinFit_corrJERDown_mass, &b_ZllKinFit_corrJERDown_mass);
   fChain->SetBranchAddress("ZllKinFit_corrJECUp_mass", &ZllKinFit_corrJECUp_mass, &b_ZllKinFit_corrJECUp_mass);
   fChain->SetBranchAddress("ZllKinFit_corrJECDown_mass", &ZllKinFit_corrJECDown_mass, &b_ZllKinFit_corrJECDown_mass);
   fChain->SetBranchAddress("ZllKinFit_corrJECUp_status", &ZllKinFit_corrJECUp_status, &b_ZllKinFit_corrJECUp_status);
   fChain->SetBranchAddress("ZllKinFit_corrJERDown_njet", &ZllKinFit_corrJERDown_njet, &b_ZllKinFit_corrJERDown_njet);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_trackingFailureFilter", &Flag_trackingFailureFilter, &b_Flag_trackingFailureFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   fChain->SetBranchAddress("Flag_GlobalTightHalo2016Filter", &Flag_GlobalTightHalo2016Filter, &b_Flag_GlobalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("EX_MUON", &EX_MUON, &b_EX_MUON);
   fChain->SetBranchAddress("HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v", &HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v, &b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v", &HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v, &b_HLT_BIT_HLT_PFMET90_PFMHT90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v", &HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v, &b_HLT_BIT_HLT_PFMET100_PFMHT100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v", &HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v, &b_HLT_BIT_HLT_PFMET110_PFMHT110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v", &HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v, &b_HLT_BIT_HLT_PFMET120_PFMHT120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET170_NoiseCleaned_v", &HLT_BIT_HLT_PFMET170_NoiseCleaned_v, &b_HLT_BIT_HLT_PFMET170_NoiseCleaned_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET170_HBHE_BeamHaloCleaned_v", &HLT_BIT_HLT_PFMET170_HBHE_BeamHaloCleaned_v, &b_HLT_BIT_HLT_PFMET170_HBHE_BeamHaloCleaned_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET170_HBHECleaned_v", &HLT_BIT_HLT_PFMET170_HBHECleaned_v, &b_HLT_BIT_HLT_PFMET170_HBHECleaned_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v", &HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v, &b_HLT_BIT_HLT_DiCentralPFJet55_PFMET110_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT350_PFMET100_v", &HLT_BIT_HLT_PFHT350_PFMET100_v, &b_HLT_BIT_HLT_PFHT350_PFMET100_v);
   fChain->SetBranchAddress("HLT_ZnnHbbAll", &HLT_ZnnHbbAll, &b_HLT_ZnnHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v);
   fChain->SetBranchAddress("HLT_VBFHbbLowLumi", &HLT_VBFHbbLowLumi, &b_HLT_VBFHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT750_4JetPt50_v", &HLT_BIT_HLT_PFHT750_4JetPt50_v, &b_HLT_BIT_HLT_PFHT750_4JetPt50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT800_v", &HLT_BIT_HLT_PFHT800_v, &b_HLT_BIT_HLT_PFHT800_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT900_v", &HLT_BIT_HLT_PFHT900_v, &b_HLT_BIT_HLT_PFHT900_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet40_v", &HLT_BIT_HLT_PFJet40_v, &b_HLT_BIT_HLT_PFJet40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet60_v", &HLT_BIT_HLT_PFJet60_v, &b_HLT_BIT_HLT_PFJet60_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet80_v", &HLT_BIT_HLT_PFJet80_v, &b_HLT_BIT_HLT_PFJet80_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet140_v", &HLT_BIT_HLT_PFJet140_v, &b_HLT_BIT_HLT_PFJet140_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet200_v", &HLT_BIT_HLT_PFJet200_v, &b_HLT_BIT_HLT_PFJet200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet260_v", &HLT_BIT_HLT_PFJet260_v, &b_HLT_BIT_HLT_PFJet260_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet320_v", &HLT_BIT_HLT_PFJet320_v, &b_HLT_BIT_HLT_PFJet320_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet400_v", &HLT_BIT_HLT_PFJet400_v, &b_HLT_BIT_HLT_PFJet400_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFJet450_v", &HLT_BIT_HLT_PFJet450_v, &b_HLT_BIT_HLT_PFJet450_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve40_v", &HLT_BIT_HLT_DiPFJetAve40_v, &b_HLT_BIT_HLT_DiPFJetAve40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve60_v", &HLT_BIT_HLT_DiPFJetAve60_v, &b_HLT_BIT_HLT_DiPFJetAve60_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve80_v", &HLT_BIT_HLT_DiPFJetAve80_v, &b_HLT_BIT_HLT_DiPFJetAve80_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve140_v", &HLT_BIT_HLT_DiPFJetAve140_v, &b_HLT_BIT_HLT_DiPFJetAve140_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve200_v", &HLT_BIT_HLT_DiPFJetAve200_v, &b_HLT_BIT_HLT_DiPFJetAve200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve260_v", &HLT_BIT_HLT_DiPFJetAve260_v, &b_HLT_BIT_HLT_DiPFJetAve260_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiPFJetAve320_v", &HLT_BIT_HLT_DiPFJetAve320_v, &b_HLT_BIT_HLT_DiPFJetAve320_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v", &HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v, &b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v", &HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v, &b_HLT_BIT_HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v);
   fChain->SetBranchAddress("HLT_hadronic", &HLT_hadronic, &b_HLT_hadronic);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v", &HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v, &b_HLT_BIT_HLT_QuadJet45_TripleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v", &HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v, &b_HLT_BIT_HLT_QuadJet45_DoubleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v", &HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v, &b_HLT_BIT_HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v", &HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v, &b_HLT_BIT_HLT_DoubleJet90_Double30_DoubleBTagCSV_p087_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v", &HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v", &HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v", &HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v, &b_HLT_BIT_HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v", &HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v, &b_HLT_BIT_HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v", &HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v, &b_HLT_BIT_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_AK8PFJet360_TrimMass30_v", &HLT_BIT_HLT_AK8PFJet360_TrimMass30_v, &b_HLT_BIT_HLT_AK8PFJet360_TrimMass30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v", &HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v, &b_HLT_BIT_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v);
   fChain->SetBranchAddress("HLT_HH4bAll", &HLT_HH4bAll, &b_HLT_HH4bAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu24_eta2p1_v", &HLT_BIT_HLT_Mu24_eta2p1_v, &b_HLT_BIT_HLT_Mu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu24_eta2p1_v", &HLT_BIT_HLT_TkMu24_eta2p1_v, &b_HLT_BIT_HLT_TkMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu27_v", &HLT_BIT_HLT_IsoMu27_v, &b_HLT_BIT_HLT_IsoMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu27_v", &HLT_BIT_HLT_IsoTkMu27_v, &b_HLT_BIT_HLT_IsoTkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu24_v", &HLT_BIT_HLT_IsoTkMu24_v, &b_HLT_BIT_HLT_IsoTkMu24_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu27_v", &HLT_BIT_HLT_TkMu27_v, &b_HLT_BIT_HLT_TkMu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu27_v", &HLT_BIT_HLT_Mu27_v, &b_HLT_BIT_HLT_Mu27_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu20_v", &HLT_BIT_HLT_IsoMu20_v, &b_HLT_BIT_HLT_IsoMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu20_v", &HLT_BIT_HLT_Mu20_v, &b_HLT_BIT_HLT_Mu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TkMu20_v", &HLT_BIT_HLT_TkMu20_v, &b_HLT_BIT_HLT_TkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu20_v", &HLT_BIT_HLT_IsoTkMu20_v, &b_HLT_BIT_HLT_IsoTkMu20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu18_v", &HLT_BIT_HLT_IsoMu18_v, &b_HLT_BIT_HLT_IsoMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu18_v", &HLT_BIT_HLT_IsoTkMu18_v, &b_HLT_BIT_HLT_IsoTkMu18_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v", &HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v, &b_HLT_BIT_HLT_Mu40_eta2p1_PFJet200_PFJet50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v", &HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v, &b_HLT_BIT_HLT_IsoMu16_eta2p1_MET30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu16_eta2p1_MET30_v", &HLT_BIT_HLT_Mu16_eta2p1_MET30_v, &b_HLT_BIT_HLT_Mu16_eta2p1_MET30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMET120_Mu5_v", &HLT_BIT_HLT_PFMET120_Mu5_v, &b_HLT_BIT_HLT_PFMET120_Mu5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v", &HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v", &HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v", &HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v", &HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v, &b_HLT_BIT_HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v);
   fChain->SetBranchAddress("HLT_WmnHbbAll", &HLT_WmnHbbAll, &b_HLT_WmnHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_ZeeHbbLowLumi", &HLT_ZeeHbbLowLumi, &b_HLT_ZeeHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele32_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_HT200_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele27_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v", &HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v, &b_HLT_BIT_HLT_Ele105_CaloIdVT_GsfTrkIdT_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v", &HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v, &b_HLT_BIT_HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_WHbbBoost_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele22_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele27_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele27_WPTight_Gsf_v", &HLT_BIT_HLT_Ele27_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele27_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v", &HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v, &b_HLT_BIT_HLT_Ele23_WPLoose_Gsf_WHbbBoost_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_WPTight_Gsf_v", &HLT_BIT_HLT_Ele25_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele25_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v", &HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v, &b_HLT_BIT_HLT_Ele25_eta2p1_WPLoose_Gsf_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v", &HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v, &b_HLT_BIT_HLT_Ele25_eta2p1_WPTight_Gsf_v);
   fChain->SetBranchAddress("HLT_WenHbbAll", &HLT_WenHbbAll, &b_HLT_WenHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v", &HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v, &b_HLT_BIT_HLT_LooseIsoPFTau50_Trk30_eta2p1_v);
   fChain->SetBranchAddress("HLT_WtaunHbbAll", &HLT_WtaunHbbAll, &b_HLT_WtaunHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v", &HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v, &b_HLT_BIT_HLT_Ele30WP60_Ele8_Mass55_v);
   fChain->SetBranchAddress("HLT_ZeeHbbAll", &HLT_ZeeHbbAll, &b_HLT_ZeeHbbAll);
   fChain->SetBranchAddress("HLT_ttH_SL_el", &HLT_ttH_SL_el, &b_HLT_ttH_SL_el);
   fChain->SetBranchAddress("HLT_WtaunHbbLowLumi", &HLT_WtaunHbbLowLumi, &b_HLT_WtaunHbbLowLumi);
   fChain->SetBranchAddress("HLT_WmnHbbLowLumi", &HLT_WmnHbbLowLumi, &b_HLT_WmnHbbLowLumi);
   fChain->SetBranchAddress("HLT_ZeeHbbHighLumi", &HLT_ZeeHbbHighLumi, &b_HLT_ZeeHbbHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v", &HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v, &b_HLT_BIT_HLT_PFHT450_SixJet40_BTagCSV_p056_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v", &HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v, &b_HLT_BIT_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v);
   fChain->SetBranchAddress("HLT_ttH_FH", &HLT_ttH_FH, &b_HLT_ttH_FH);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v", &HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v, &b_HLT_BIT_HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v);
   fChain->SetBranchAddress("HLT_VBFHbbHighLumi", &HLT_VBFHbbHighLumi, &b_HLT_VBFHbbHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v);
   fChain->SetBranchAddress("HLT_ttH_DL_elmu", &HLT_ttH_DL_elmu, &b_HLT_ttH_DL_elmu);
   fChain->SetBranchAddress("HLT_ttH_DL_elel", &HLT_ttH_DL_elel, &b_HLT_ttH_DL_elel);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu22_v", &HLT_BIT_HLT_IsoMu22_v, &b_HLT_BIT_HLT_IsoMu22_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu22_eta2p1_v", &HLT_BIT_HLT_IsoMu22_eta2p1_v, &b_HLT_BIT_HLT_IsoMu22_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_v", &HLT_BIT_HLT_IsoMu24_v, &b_HLT_BIT_HLT_IsoMu24_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu22_v", &HLT_BIT_HLT_IsoTkMu22_v, &b_HLT_BIT_HLT_IsoTkMu22_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoTkMu22_eta2p1_v", &HLT_BIT_HLT_IsoTkMu22_eta2p1_v, &b_HLT_BIT_HLT_IsoTkMu22_eta2p1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", &HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v, &b_HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", &HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v, &b_HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v", &HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v, &b_HLT_BIT_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_TripleMu_12_10_5_v", &HLT_BIT_HLT_TripleMu_12_10_5_v, &b_HLT_BIT_HLT_TripleMu_12_10_5_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v", &HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v, &b_HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v", &HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v, &b_HLT_BIT_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v", &HLT_BIT_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v, &b_HLT_BIT_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v", &HLT_BIT_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v, &b_HLT_BIT_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v", &HLT_BIT_HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v, &b_HLT_BIT_HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_VLooseIsoPFTau140_eta2p1_v", &HLT_BIT_HLT_VLooseIsoPFTau140_eta2p1_v, &b_HLT_BIT_HLT_VLooseIsoPFTau140_eta2p1_v);
   fChain->SetBranchAddress("HLT_ttH_htt", &HLT_ttH_htt, &b_HLT_ttH_htt);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT450_SixJet40_v", &HLT_BIT_HLT_PFHT450_SixJet40_v, &b_HLT_BIT_HLT_PFHT450_SixJet40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT400_SixJet30_v", &HLT_BIT_HLT_PFHT400_SixJet30_v, &b_HLT_BIT_HLT_PFHT400_SixJet30_v);
   fChain->SetBranchAddress("HLT_ttH_FH_prescaled", &HLT_ttH_FH_prescaled, &b_HLT_ttH_FH_prescaled);
   fChain->SetBranchAddress("HLT_ZnnHbb", &HLT_ZnnHbb, &b_HLT_ZnnHbb);
   fChain->SetBranchAddress("HLT_ttH_DL_mumu", &HLT_ttH_DL_mumu, &b_HLT_ttH_DL_mumu);
   fChain->SetBranchAddress("HLT_ZmmHbbLowLumi", &HLT_ZmmHbbLowLumi, &b_HLT_ZmmHbbLowLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_IsoMu24_eta2p1_v", &HLT_BIT_HLT_IsoMu24_eta2p1_v, &b_HLT_BIT_HLT_IsoMu24_eta2p1_v);
   fChain->SetBranchAddress("HLT_WmnHbbHighLumi", &HLT_WmnHbbHighLumi, &b_HLT_WmnHbbHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_TkMu8_DZ_v", &HLT_BIT_HLT_Mu17_TkMu8_DZ_v, &b_HLT_BIT_HLT_Mu17_TkMu8_DZ_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v", &HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v, &b_HLT_BIT_HLT_DoubleIsoMu17_eta2p1_v);
   fChain->SetBranchAddress("HLT_ZmmHbbAll", &HLT_ZmmHbbAll, &b_HLT_ZmmHbbAll);
   fChain->SetBranchAddress("HLT_ttH_SL_mu", &HLT_ttH_SL_mu, &b_HLT_ttH_SL_mu);
   fChain->SetBranchAddress("HLT_WtaunHbbHighLumi", &HLT_WtaunHbbHighLumi, &b_HLT_WtaunHbbHighLumi);
   fChain->SetBranchAddress("HLT_WenHbbHighLumi", &HLT_WenHbbHighLumi, &b_HLT_WenHbbHighLumi);
   fChain->SetBranchAddress("HLT_HH4bLowLumi", &HLT_HH4bLowLumi, &b_HLT_HH4bLowLumi);
   fChain->SetBranchAddress("HLT_ZmmHbbHighLumi", &HLT_ZmmHbbHighLumi, &b_HLT_ZmmHbbHighLumi);
   fChain->SetBranchAddress("HLT_BIT_HLT_QuadPFJet_VBF_v", &HLT_BIT_HLT_QuadPFJet_VBF_v, &b_HLT_BIT_HLT_QuadPFJet_VBF_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_L1_TripleJet_VBF_v", &HLT_BIT_HLT_L1_TripleJet_VBF_v, &b_HLT_BIT_HLT_L1_TripleJet_VBF_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v", &HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v, &b_HLT_BIT_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v);
   fChain->SetBranchAddress("HLT_VBFHbbAll", &HLT_VBFHbbAll, &b_HLT_VBFHbbAll);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu3_PFJet40_v", &HLT_BIT_HLT_Mu3_PFJet40_v, &b_HLT_BIT_HLT_Mu3_PFJet40_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu8_v", &HLT_BIT_HLT_Mu8_v, &b_HLT_BIT_HLT_Mu8_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Mu17_v", &HLT_BIT_HLT_Mu17_v, &b_HLT_BIT_HLT_Mu17_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v", &HLT_BIT_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_BIT_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v", &HLT_BIT_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_BIT_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v);
   fChain->SetBranchAddress("HLT_BIT_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v", &HLT_BIT_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v, &b_HLT_BIT_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v);
   fChain->SetBranchAddress("HLT_ttH_htt_lepFakeBgr", &HLT_ttH_htt_lepFakeBgr, &b_HLT_ttH_htt_lepFakeBgr);
   fChain->SetBranchAddress("HLT_WenHbbLowLumi", &HLT_WenHbbLowLumi, &b_HLT_WenHbbLowLumi);
   fChain->SetBranchAddress("HLT_HH4bHighLumi", &HLT_HH4bHighLumi, &b_HLT_HH4bHighLumi);
   fChain->SetBranchAddress("l1MHT_pt", &l1MHT_pt, &b_l1MHT_pt);
   fChain->SetBranchAddress("l1MHT_phi", &l1MHT_phi, &b_l1MHT_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECDown_pt", &HCMVAV2_reg_corrJECDown_pt, &b_HCMVAV2_reg_corrJECDown_pt);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECDown_eta", &HCMVAV2_reg_corrJECDown_eta, &b_HCMVAV2_reg_corrJECDown_eta);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECDown_phi", &HCMVAV2_reg_corrJECDown_phi, &b_HCMVAV2_reg_corrJECDown_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECDown_mass", &HCMVAV2_reg_corrJECDown_mass, &b_HCMVAV2_reg_corrJECDown_mass);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERDown_pt", &HCMVAV2_reg_corrJERDown_pt, &b_HCMVAV2_reg_corrJERDown_pt);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERDown_eta", &HCMVAV2_reg_corrJERDown_eta, &b_HCMVAV2_reg_corrJERDown_eta);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERDown_phi", &HCMVAV2_reg_corrJERDown_phi, &b_HCMVAV2_reg_corrJERDown_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERDown_mass", &HCMVAV2_reg_corrJERDown_mass, &b_HCMVAV2_reg_corrJERDown_mass);
   fChain->SetBranchAddress("l1MET_pt", &l1MET_pt, &b_l1MET_pt);
   fChain->SetBranchAddress("l1MET_phi", &l1MET_phi, &b_l1MET_phi);
   fChain->SetBranchAddress("V_pt", &V_pt, &b_V_pt);
   fChain->SetBranchAddress("V_eta", &V_eta, &b_V_eta);
   fChain->SetBranchAddress("V_phi", &V_phi, &b_V_phi);
   fChain->SetBranchAddress("V_mass", &V_mass, &b_V_mass);
   fChain->SetBranchAddress("H_reg_pt", &H_reg_pt, &b_H_reg_pt);
   fChain->SetBranchAddress("H_reg_eta", &H_reg_eta, &b_H_reg_eta);
   fChain->SetBranchAddress("H_reg_phi", &H_reg_phi, &b_H_reg_phi);
   fChain->SetBranchAddress("H_reg_mass", &H_reg_mass, &b_H_reg_mass);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_pt", &HCSV_reg_corrJERDown_pt, &b_HCSV_reg_corrJERDown_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_eta", &HCSV_reg_corrJERDown_eta, &b_HCSV_reg_corrJERDown_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_phi", &HCSV_reg_corrJERDown_phi, &b_HCSV_reg_corrJERDown_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJERDown_mass", &HCSV_reg_corrJERDown_mass, &b_HCSV_reg_corrJERDown_mass);
   fChain->SetBranchAddress("HCSV_pt", &HCSV_pt, &b_HCSV_pt);
   fChain->SetBranchAddress("HCSV_eta", &HCSV_eta, &b_HCSV_eta);
   fChain->SetBranchAddress("HCSV_phi", &HCSV_phi, &b_HCSV_phi);
   fChain->SetBranchAddress("HCSV_mass", &HCSV_mass, &b_HCSV_mass);
   fChain->SetBranchAddress("l1HT_pt", &l1HT_pt, &b_l1HT_pt);
   fChain->SetBranchAddress("l1HT_phi", &l1HT_phi, &b_l1HT_phi);
   fChain->SetBranchAddress("fakeMET_pt", &fakeMET_pt, &b_fakeMET_pt);
   fChain->SetBranchAddress("fakeMET_eta", &fakeMET_eta, &b_fakeMET_eta);
   fChain->SetBranchAddress("fakeMET_phi", &fakeMET_phi, &b_fakeMET_phi);
   fChain->SetBranchAddress("fakeMET_mass", &fakeMET_mass, &b_fakeMET_mass);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_pt", &HCSV_reg_corrJERUp_pt, &b_HCSV_reg_corrJERUp_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_eta", &HCSV_reg_corrJERUp_eta, &b_HCSV_reg_corrJERUp_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_phi", &HCSV_reg_corrJERUp_phi, &b_HCSV_reg_corrJERUp_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJERUp_mass", &HCSV_reg_corrJERUp_mass, &b_HCSV_reg_corrJERUp_mass);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERUp_pt", &HCMVAV2_reg_corrJERUp_pt, &b_HCMVAV2_reg_corrJERUp_pt);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERUp_eta", &HCMVAV2_reg_corrJERUp_eta, &b_HCMVAV2_reg_corrJERUp_eta);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERUp_phi", &HCMVAV2_reg_corrJERUp_phi, &b_HCMVAV2_reg_corrJERUp_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJERUp_mass", &HCMVAV2_reg_corrJERUp_mass, &b_HCMVAV2_reg_corrJERUp_mass);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_pt", &HCSV_reg_corrJECUp_pt, &b_HCSV_reg_corrJECUp_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_eta", &HCSV_reg_corrJECUp_eta, &b_HCSV_reg_corrJECUp_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_phi", &HCSV_reg_corrJECUp_phi, &b_HCSV_reg_corrJECUp_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJECUp_mass", &HCSV_reg_corrJECUp_mass, &b_HCSV_reg_corrJECUp_mass);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_pt", &met_shifted_UnclusteredEnUp_pt, &b_met_shifted_UnclusteredEnUp_pt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_phi", &met_shifted_UnclusteredEnUp_phi, &b_met_shifted_UnclusteredEnUp_phi);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnUp_sumEt", &met_shifted_UnclusteredEnUp_sumEt, &b_met_shifted_UnclusteredEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_pt", &met_shifted_UnclusteredEnDown_pt, &b_met_shifted_UnclusteredEnDown_pt);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_phi", &met_shifted_UnclusteredEnDown_phi, &b_met_shifted_UnclusteredEnDown_phi);
   fChain->SetBranchAddress("met_shifted_UnclusteredEnDown_sumEt", &met_shifted_UnclusteredEnDown_sumEt, &b_met_shifted_UnclusteredEnDown_sumEt);
   fChain->SetBranchAddress("HCSV_reg_pt", &HCSV_reg_pt, &b_HCSV_reg_pt);
   fChain->SetBranchAddress("HCSV_reg_eta", &HCSV_reg_eta, &b_HCSV_reg_eta);
   fChain->SetBranchAddress("HCSV_reg_phi", &HCSV_reg_phi, &b_HCSV_reg_phi);
   fChain->SetBranchAddress("HCSV_reg_mass", &HCSV_reg_mass, &b_HCSV_reg_mass);
   fChain->SetBranchAddress("H_reg_corrJERUp_pt", &H_reg_corrJERUp_pt, &b_H_reg_corrJERUp_pt);
   fChain->SetBranchAddress("H_reg_corrJERUp_eta", &H_reg_corrJERUp_eta, &b_H_reg_corrJERUp_eta);
   fChain->SetBranchAddress("H_reg_corrJERUp_phi", &H_reg_corrJERUp_phi, &b_H_reg_corrJERUp_phi);
   fChain->SetBranchAddress("H_reg_corrJERUp_mass", &H_reg_corrJERUp_mass, &b_H_reg_corrJERUp_mass);
   fChain->SetBranchAddress("H_reg_corrJECUp_pt", &H_reg_corrJECUp_pt, &b_H_reg_corrJECUp_pt);
   fChain->SetBranchAddress("H_reg_corrJECUp_eta", &H_reg_corrJECUp_eta, &b_H_reg_corrJECUp_eta);
   fChain->SetBranchAddress("H_reg_corrJECUp_phi", &H_reg_corrJECUp_phi, &b_H_reg_corrJECUp_phi);
   fChain->SetBranchAddress("H_reg_corrJECUp_mass", &H_reg_corrJECUp_mass, &b_H_reg_corrJECUp_mass);
   fChain->SetBranchAddress("HCMVAV2_reg_pt", &HCMVAV2_reg_pt, &b_HCMVAV2_reg_pt);
   fChain->SetBranchAddress("HCMVAV2_reg_eta", &HCMVAV2_reg_eta, &b_HCMVAV2_reg_eta);
   fChain->SetBranchAddress("HCMVAV2_reg_phi", &HCMVAV2_reg_phi, &b_HCMVAV2_reg_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_mass", &HCMVAV2_reg_mass, &b_HCMVAV2_reg_mass);
   fChain->SetBranchAddress("H_pt", &H_pt, &b_H_pt);
   fChain->SetBranchAddress("H_eta", &H_eta, &b_H_eta);
   fChain->SetBranchAddress("H_phi", &H_phi, &b_H_phi);
   fChain->SetBranchAddress("H_mass", &H_mass, &b_H_mass);
   fChain->SetBranchAddress("softActivityVH_njets2", &softActivityVH_njets2, &b_softActivityVH_njets2);
   fChain->SetBranchAddress("softActivityVH_njets5", &softActivityVH_njets5, &b_softActivityVH_njets5);
   fChain->SetBranchAddress("softActivityVH_njets10", &softActivityVH_njets10, &b_softActivityVH_njets10);
   fChain->SetBranchAddress("softActivityVH_HT", &softActivityVH_HT, &b_softActivityVH_HT);
   fChain->SetBranchAddress("met_shifted_JetResUp_pt", &met_shifted_JetResUp_pt, &b_met_shifted_JetResUp_pt);
   fChain->SetBranchAddress("met_shifted_JetResUp_phi", &met_shifted_JetResUp_phi, &b_met_shifted_JetResUp_phi);
   fChain->SetBranchAddress("met_shifted_JetResUp_sumEt", &met_shifted_JetResUp_sumEt, &b_met_shifted_JetResUp_sumEt);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_eta", &met_eta, &b_met_eta);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_mass", &met_mass, &b_met_mass);
   fChain->SetBranchAddress("met_sumEt", &met_sumEt, &b_met_sumEt);
   fChain->SetBranchAddress("met_rawPt", &met_rawPt, &b_met_rawPt);
   fChain->SetBranchAddress("met_rawPhi", &met_rawPhi, &b_met_rawPhi);
   fChain->SetBranchAddress("met_rawSumEt", &met_rawSumEt, &b_met_rawSumEt);
   fChain->SetBranchAddress("met_genPt", &met_genPt, &b_met_genPt);
   fChain->SetBranchAddress("met_genPhi", &met_genPhi, &b_met_genPhi);
   fChain->SetBranchAddress("met_genEta", &met_genEta, &b_met_genEta);
   fChain->SetBranchAddress("met_shifted_JetEnUp_pt", &met_shifted_JetEnUp_pt, &b_met_shifted_JetEnUp_pt);
   fChain->SetBranchAddress("met_shifted_JetEnUp_phi", &met_shifted_JetEnUp_phi, &b_met_shifted_JetEnUp_phi);
   fChain->SetBranchAddress("met_shifted_JetEnUp_sumEt", &met_shifted_JetEnUp_sumEt, &b_met_shifted_JetEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_JetEnDown_pt", &met_shifted_JetEnDown_pt, &b_met_shifted_JetEnDown_pt);
   fChain->SetBranchAddress("met_shifted_JetEnDown_phi", &met_shifted_JetEnDown_phi, &b_met_shifted_JetEnDown_phi);
   fChain->SetBranchAddress("met_shifted_JetEnDown_sumEt", &met_shifted_JetEnDown_sumEt, &b_met_shifted_JetEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_pt", &met_shifted_MuonEnUp_pt, &b_met_shifted_MuonEnUp_pt);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_phi", &met_shifted_MuonEnUp_phi, &b_met_shifted_MuonEnUp_phi);
   fChain->SetBranchAddress("met_shifted_MuonEnUp_sumEt", &met_shifted_MuonEnUp_sumEt, &b_met_shifted_MuonEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_pt", &met_shifted_MuonEnDown_pt, &b_met_shifted_MuonEnDown_pt);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_phi", &met_shifted_MuonEnDown_phi, &b_met_shifted_MuonEnDown_phi);
   fChain->SetBranchAddress("met_shifted_MuonEnDown_sumEt", &met_shifted_MuonEnDown_sumEt, &b_met_shifted_MuonEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_pt", &met_shifted_ElectronEnUp_pt, &b_met_shifted_ElectronEnUp_pt);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_phi", &met_shifted_ElectronEnUp_phi, &b_met_shifted_ElectronEnUp_phi);
   fChain->SetBranchAddress("met_shifted_ElectronEnUp_sumEt", &met_shifted_ElectronEnUp_sumEt, &b_met_shifted_ElectronEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_pt", &met_shifted_ElectronEnDown_pt, &b_met_shifted_ElectronEnDown_pt);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_phi", &met_shifted_ElectronEnDown_phi, &b_met_shifted_ElectronEnDown_phi);
   fChain->SetBranchAddress("met_shifted_ElectronEnDown_sumEt", &met_shifted_ElectronEnDown_sumEt, &b_met_shifted_ElectronEnDown_sumEt);
   fChain->SetBranchAddress("met_shifted_TauEnUp_pt", &met_shifted_TauEnUp_pt, &b_met_shifted_TauEnUp_pt);
   fChain->SetBranchAddress("met_shifted_TauEnUp_phi", &met_shifted_TauEnUp_phi, &b_met_shifted_TauEnUp_phi);
   fChain->SetBranchAddress("met_shifted_TauEnUp_sumEt", &met_shifted_TauEnUp_sumEt, &b_met_shifted_TauEnUp_sumEt);
   fChain->SetBranchAddress("met_shifted_TauEnDown_pt", &met_shifted_TauEnDown_pt, &b_met_shifted_TauEnDown_pt);
   fChain->SetBranchAddress("met_shifted_TauEnDown_phi", &met_shifted_TauEnDown_phi, &b_met_shifted_TauEnDown_phi);
   fChain->SetBranchAddress("met_shifted_TauEnDown_sumEt", &met_shifted_TauEnDown_sumEt, &b_met_shifted_TauEnDown_sumEt);
   fChain->SetBranchAddress("l1ET_pt", &l1ET_pt, &b_l1ET_pt);
   fChain->SetBranchAddress("l1ET_phi", &l1ET_phi, &b_l1ET_phi);
   fChain->SetBranchAddress("softActivityEWK_njets2", &softActivityEWK_njets2, &b_softActivityEWK_njets2);
   fChain->SetBranchAddress("softActivityEWK_njets5", &softActivityEWK_njets5, &b_softActivityEWK_njets5);
   fChain->SetBranchAddress("softActivityEWK_njets10", &softActivityEWK_njets10, &b_softActivityEWK_njets10);
   fChain->SetBranchAddress("softActivityEWK_HT", &softActivityEWK_HT, &b_softActivityEWK_HT);
   fChain->SetBranchAddress("met_shifted_JetResDown_pt", &met_shifted_JetResDown_pt, &b_met_shifted_JetResDown_pt);
   fChain->SetBranchAddress("met_shifted_JetResDown_phi", &met_shifted_JetResDown_phi, &b_met_shifted_JetResDown_phi);
   fChain->SetBranchAddress("met_shifted_JetResDown_sumEt", &met_shifted_JetResDown_sumEt, &b_met_shifted_JetResDown_sumEt);
   fChain->SetBranchAddress("HaddJetsdR08_pt", &HaddJetsdR08_pt, &b_HaddJetsdR08_pt);
   fChain->SetBranchAddress("HaddJetsdR08_eta", &HaddJetsdR08_eta, &b_HaddJetsdR08_eta);
   fChain->SetBranchAddress("HaddJetsdR08_phi", &HaddJetsdR08_phi, &b_HaddJetsdR08_phi);
   fChain->SetBranchAddress("HaddJetsdR08_mass", &HaddJetsdR08_mass, &b_HaddJetsdR08_mass);
   fChain->SetBranchAddress("H_reg_corrJERDown_pt", &H_reg_corrJERDown_pt, &b_H_reg_corrJERDown_pt);
   fChain->SetBranchAddress("H_reg_corrJERDown_eta", &H_reg_corrJERDown_eta, &b_H_reg_corrJERDown_eta);
   fChain->SetBranchAddress("H_reg_corrJERDown_phi", &H_reg_corrJERDown_phi, &b_H_reg_corrJERDown_phi);
   fChain->SetBranchAddress("H_reg_corrJERDown_mass", &H_reg_corrJERDown_mass, &b_H_reg_corrJERDown_mass);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECUp_pt", &HCMVAV2_reg_corrJECUp_pt, &b_HCMVAV2_reg_corrJECUp_pt);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECUp_eta", &HCMVAV2_reg_corrJECUp_eta, &b_HCMVAV2_reg_corrJECUp_eta);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECUp_phi", &HCMVAV2_reg_corrJECUp_phi, &b_HCMVAV2_reg_corrJECUp_phi);
   fChain->SetBranchAddress("HCMVAV2_reg_corrJECUp_mass", &HCMVAV2_reg_corrJECUp_mass, &b_HCMVAV2_reg_corrJECUp_mass);
   fChain->SetBranchAddress("softActivity_njets2", &softActivity_njets2, &b_softActivity_njets2);
   fChain->SetBranchAddress("softActivity_njets5", &softActivity_njets5, &b_softActivity_njets5);
   fChain->SetBranchAddress("softActivity_njets10", &softActivity_njets10, &b_softActivity_njets10);
   fChain->SetBranchAddress("softActivity_HT", &softActivity_HT, &b_softActivity_HT);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_pt", &HCSV_reg_corrJECDown_pt, &b_HCSV_reg_corrJECDown_pt);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_eta", &HCSV_reg_corrJECDown_eta, &b_HCSV_reg_corrJECDown_eta);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_phi", &HCSV_reg_corrJECDown_phi, &b_HCSV_reg_corrJECDown_phi);
   fChain->SetBranchAddress("HCSV_reg_corrJECDown_mass", &HCSV_reg_corrJECDown_mass, &b_HCSV_reg_corrJECDown_mass);
   fChain->SetBranchAddress("HCMVAV2_pt", &HCMVAV2_pt, &b_HCMVAV2_pt);
   fChain->SetBranchAddress("HCMVAV2_eta", &HCMVAV2_eta, &b_HCMVAV2_eta);
   fChain->SetBranchAddress("HCMVAV2_phi", &HCMVAV2_phi, &b_HCMVAV2_phi);
   fChain->SetBranchAddress("HCMVAV2_mass", &HCMVAV2_mass, &b_HCMVAV2_mass);
   fChain->SetBranchAddress("H_reg_corrJECDown_pt", &H_reg_corrJECDown_pt, &b_H_reg_corrJECDown_pt);
   fChain->SetBranchAddress("H_reg_corrJECDown_eta", &H_reg_corrJECDown_eta, &b_H_reg_corrJECDown_eta);
   fChain->SetBranchAddress("H_reg_corrJECDown_phi", &H_reg_corrJECDown_phi, &b_H_reg_corrJECDown_phi);
   fChain->SetBranchAddress("H_reg_corrJECDown_mass", &H_reg_corrJECDown_mass, &b_H_reg_corrJECDown_mass);
   fChain->SetBranchAddress("npileUpVertex_ptHat", &npileUpVertex_ptHat, &b_npileUpVertex_ptHat);
   fChain->SetBranchAddress("pileUpVertex_ptHat", pileUpVertex_ptHat, &b_pileUpVertex_ptHat);
   fChain->SetBranchAddress("ntrgObjects_hltMET70", &ntrgObjects_hltMET70, &b_ntrgObjects_hltMET70);
   fChain->SetBranchAddress("ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet", &ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet, &b_ntrgObjects_hltL1sTripleJetVBFIorHTTIorDoubleJetCIorSingleJet);
   fChain->SetBranchAddress("ntrgObjects_hltBTagPFCSVp11DoubleWithMatching", &ntrgObjects_hltBTagPFCSVp11DoubleWithMatching, &b_ntrgObjects_hltBTagPFCSVp11DoubleWithMatching);
   fChain->SetBranchAddress("nGenLepFromTop", &nGenLepFromTop, &b_nGenLepFromTop);
   fChain->SetBranchAddress("GenLepFromTop_pdgId", GenLepFromTop_pdgId, &b_GenLepFromTop_pdgId);
   fChain->SetBranchAddress("GenLepFromTop_pt", GenLepFromTop_pt, &b_GenLepFromTop_pt);
   fChain->SetBranchAddress("GenLepFromTop_eta", GenLepFromTop_eta, &b_GenLepFromTop_eta);
   fChain->SetBranchAddress("GenLepFromTop_phi", GenLepFromTop_phi, &b_GenLepFromTop_phi);
   fChain->SetBranchAddress("GenLepFromTop_mass", GenLepFromTop_mass, &b_GenLepFromTop_mass);
   fChain->SetBranchAddress("GenLepFromTop_charge", GenLepFromTop_charge, &b_GenLepFromTop_charge);
   fChain->SetBranchAddress("GenLepFromTop_status", GenLepFromTop_status, &b_GenLepFromTop_status);
   fChain->SetBranchAddress("GenLepFromTop_isPromptHard", GenLepFromTop_isPromptHard, &b_GenLepFromTop_isPromptHard);
   fChain->SetBranchAddress("najidxaddJetsdR08", &najidxaddJetsdR08, &b_najidxaddJetsdR08);
   fChain->SetBranchAddress("ajidxaddJetsdR08", ajidxaddJetsdR08, &b_ajidxaddJetsdR08);
   fChain->SetBranchAddress("nSubjetCA15softdrop", &nSubjetCA15softdrop, &b_nSubjetCA15softdrop);
   fChain->SetBranchAddress("SubjetCA15softdrop_pt", SubjetCA15softdrop_pt, &b_SubjetCA15softdrop_pt);
   fChain->SetBranchAddress("SubjetCA15softdrop_eta", SubjetCA15softdrop_eta, &b_SubjetCA15softdrop_eta);
   fChain->SetBranchAddress("SubjetCA15softdrop_phi", SubjetCA15softdrop_phi, &b_SubjetCA15softdrop_phi);
   fChain->SetBranchAddress("SubjetCA15softdrop_mass", SubjetCA15softdrop_mass, &b_SubjetCA15softdrop_mass);
   fChain->SetBranchAddress("SubjetCA15softdrop_btag", SubjetCA15softdrop_btag, &b_SubjetCA15softdrop_btag);
   fChain->SetBranchAddress("SubjetCA15softdrop_jetID", SubjetCA15softdrop_jetID, &b_SubjetCA15softdrop_jetID);
   fChain->SetBranchAddress("SubjetCA15softdrop_fromFJ", SubjetCA15softdrop_fromFJ, &b_SubjetCA15softdrop_fromFJ);
   fChain->SetBranchAddress("ntrgObjects_hltIsoMu20", &ntrgObjects_hltIsoMu20, &b_ntrgObjects_hltIsoMu20);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_pt", trgObjects_hltIsoMu20_pt, &b_trgObjects_hltIsoMu20_pt);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_eta", trgObjects_hltIsoMu20_eta, &b_trgObjects_hltIsoMu20_eta);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_phi", trgObjects_hltIsoMu20_phi, &b_trgObjects_hltIsoMu20_phi);
   fChain->SetBranchAddress("trgObjects_hltIsoMu20_mass", trgObjects_hltIsoMu20_mass, &b_trgObjects_hltIsoMu20_mass);
   fChain->SetBranchAddress("naJCMVAV2idx", &naJCMVAV2idx, &b_naJCMVAV2idx);
   fChain->SetBranchAddress("aJCMVAV2idx", aJCMVAV2idx, &b_aJCMVAV2idx);
   fChain->SetBranchAddress("ntrgObjects_hltQuadCentralJet30", &ntrgObjects_hltQuadCentralJet30, &b_ntrgObjects_hltQuadCentralJet30);
   fChain->SetBranchAddress("nl1EGammas", &nl1EGammas, &b_nl1EGammas);
   fChain->SetBranchAddress("l1EGammas_pt", &l1EGammas_pt, &b_l1EGammas_pt);
   fChain->SetBranchAddress("l1EGammas_eta", &l1EGammas_eta, &b_l1EGammas_eta);
   fChain->SetBranchAddress("l1EGammas_phi", &l1EGammas_phi, &b_l1EGammas_phi);
   fChain->SetBranchAddress("l1EGammas_qual", &l1EGammas_qual, &b_l1EGammas_qual);
   fChain->SetBranchAddress("l1EGammas_iso", &l1EGammas_iso, &b_l1EGammas_iso);
   fChain->SetBranchAddress("nhJidx_sortcsv", &nhJidx_sortcsv, &b_nhJidx_sortcsv);
   fChain->SetBranchAddress("hJidx_sortcsv", hJidx_sortcsv, &b_hJidx_sortcsv);
   fChain->SetBranchAddress("nprimaryVertices", &nprimaryVertices, &b_nprimaryVertices);
   fChain->SetBranchAddress("primaryVertices_x", primaryVertices_x, &b_primaryVertices_x);
   fChain->SetBranchAddress("primaryVertices_y", primaryVertices_y, &b_primaryVertices_y);
   fChain->SetBranchAddress("primaryVertices_z", primaryVertices_z, &b_primaryVertices_z);
   fChain->SetBranchAddress("primaryVertices_isFake", primaryVertices_isFake, &b_primaryVertices_isFake);
   fChain->SetBranchAddress("primaryVertices_ndof", primaryVertices_ndof, &b_primaryVertices_ndof);
   fChain->SetBranchAddress("primaryVertices_Rho", primaryVertices_Rho, &b_primaryVertices_Rho);
   fChain->SetBranchAddress("primaryVertices_score", primaryVertices_score, &b_primaryVertices_score);
   fChain->SetBranchAddress("naJCidx", &naJCidx, &b_naJCidx);
   fChain->SetBranchAddress("aJCidx", aJCidx, &b_aJCidx);
   fChain->SetBranchAddress("nSubjetCA15softdropz2b1", &nSubjetCA15softdropz2b1, &b_nSubjetCA15softdropz2b1);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_pt", SubjetCA15softdropz2b1_pt, &b_SubjetCA15softdropz2b1_pt);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_eta", SubjetCA15softdropz2b1_eta, &b_SubjetCA15softdropz2b1_eta);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_phi", SubjetCA15softdropz2b1_phi, &b_SubjetCA15softdropz2b1_phi);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_mass", SubjetCA15softdropz2b1_mass, &b_SubjetCA15softdropz2b1_mass);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_btag", SubjetCA15softdropz2b1_btag, &b_SubjetCA15softdropz2b1_btag);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_jetID", SubjetCA15softdropz2b1_jetID, &b_SubjetCA15softdropz2b1_jetID);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1_fromFJ", SubjetCA15softdropz2b1_fromFJ, &b_SubjetCA15softdropz2b1_fromFJ);
   fChain->SetBranchAddress("nhJCidx", &nhJCidx, &b_nhJCidx);
   fChain->SetBranchAddress("hJCidx", hJCidx, &b_hJCidx);
   fChain->SetBranchAddress("nl1Taus", &nl1Taus, &b_nl1Taus);
   fChain->SetBranchAddress("l1Taus_pt", &l1Taus_pt, &b_l1Taus_pt);
   fChain->SetBranchAddress("l1Taus_eta", &l1Taus_eta, &b_l1Taus_eta);
   fChain->SetBranchAddress("l1Taus_phi", &l1Taus_phi, &b_l1Taus_phi);
   fChain->SetBranchAddress("l1Taus_qual", &l1Taus_qual, &b_l1Taus_qual);
   fChain->SetBranchAddress("l1Taus_iso", &l1Taus_iso, &b_l1Taus_iso);
   fChain->SetBranchAddress("naJidx", &naJidx, &b_naJidx);
   fChain->SetBranchAddress("aJidx", aJidx, &b_aJidx);
   fChain->SetBranchAddress("nGenBQuarkFromTop", &nGenBQuarkFromTop, &b_nGenBQuarkFromTop);
   fChain->SetBranchAddress("GenBQuarkFromTop_pdgId", GenBQuarkFromTop_pdgId, &b_GenBQuarkFromTop_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromTop_pt", GenBQuarkFromTop_pt, &b_GenBQuarkFromTop_pt);
   fChain->SetBranchAddress("GenBQuarkFromTop_eta", GenBQuarkFromTop_eta, &b_GenBQuarkFromTop_eta);
   fChain->SetBranchAddress("GenBQuarkFromTop_phi", GenBQuarkFromTop_phi, &b_GenBQuarkFromTop_phi);
   fChain->SetBranchAddress("GenBQuarkFromTop_mass", GenBQuarkFromTop_mass, &b_GenBQuarkFromTop_mass);
   fChain->SetBranchAddress("GenBQuarkFromTop_charge", GenBQuarkFromTop_charge, &b_GenBQuarkFromTop_charge);
   fChain->SetBranchAddress("GenBQuarkFromTop_status", GenBQuarkFromTop_status, &b_GenBQuarkFromTop_status);
   fChain->SetBranchAddress("GenBQuarkFromTop_isPromptHard", GenBQuarkFromTop_isPromptHard, &b_GenBQuarkFromTop_isPromptHard);
   fChain->SetBranchAddress("nGenLepFromTau", &nGenLepFromTau, &b_nGenLepFromTau);
   fChain->SetBranchAddress("GenLepFromTau_pdgId", GenLepFromTau_pdgId, &b_GenLepFromTau_pdgId);
   fChain->SetBranchAddress("GenLepFromTau_pt", GenLepFromTau_pt, &b_GenLepFromTau_pt);
   fChain->SetBranchAddress("GenLepFromTau_eta", GenLepFromTau_eta, &b_GenLepFromTau_eta);
   fChain->SetBranchAddress("GenLepFromTau_phi", GenLepFromTau_phi, &b_GenLepFromTau_phi);
   fChain->SetBranchAddress("GenLepFromTau_mass", GenLepFromTau_mass, &b_GenLepFromTau_mass);
   fChain->SetBranchAddress("GenLepFromTau_charge", GenLepFromTau_charge, &b_GenLepFromTau_charge);
   fChain->SetBranchAddress("GenLepFromTau_status", GenLepFromTau_status, &b_GenLepFromTau_status);
   fChain->SetBranchAddress("GenLepFromTau_isPromptHard", GenLepFromTau_isPromptHard, &b_GenLepFromTau_isPromptHard);
   fChain->SetBranchAddress("nGenHiggsBoson", &nGenHiggsBoson, &b_nGenHiggsBoson);
   fChain->SetBranchAddress("GenHiggsBoson_pdgId", &GenHiggsBoson_pdgId, &b_GenHiggsBoson_pdgId);
   fChain->SetBranchAddress("GenHiggsBoson_pt", &GenHiggsBoson_pt, &b_GenHiggsBoson_pt);
   fChain->SetBranchAddress("GenHiggsBoson_eta", &GenHiggsBoson_eta, &b_GenHiggsBoson_eta);
   fChain->SetBranchAddress("GenHiggsBoson_phi", &GenHiggsBoson_phi, &b_GenHiggsBoson_phi);
   fChain->SetBranchAddress("GenHiggsBoson_mass", &GenHiggsBoson_mass, &b_GenHiggsBoson_mass);
   fChain->SetBranchAddress("GenHiggsBoson_charge", &GenHiggsBoson_charge, &b_GenHiggsBoson_charge);
   fChain->SetBranchAddress("GenHiggsBoson_status", &GenHiggsBoson_status, &b_GenHiggsBoson_status);
   fChain->SetBranchAddress("GenHiggsBoson_isPromptHard", &GenHiggsBoson_isPromptHard, &b_GenHiggsBoson_isPromptHard);
   fChain->SetBranchAddress("nGenNuFromTop", &nGenNuFromTop, &b_nGenNuFromTop);
   fChain->SetBranchAddress("GenNuFromTop_pdgId", GenNuFromTop_pdgId, &b_GenNuFromTop_pdgId);
   fChain->SetBranchAddress("GenNuFromTop_pt", GenNuFromTop_pt, &b_GenNuFromTop_pt);
   fChain->SetBranchAddress("GenNuFromTop_eta", GenNuFromTop_eta, &b_GenNuFromTop_eta);
   fChain->SetBranchAddress("GenNuFromTop_phi", GenNuFromTop_phi, &b_GenNuFromTop_phi);
   fChain->SetBranchAddress("GenNuFromTop_mass", GenNuFromTop_mass, &b_GenNuFromTop_mass);
   fChain->SetBranchAddress("GenNuFromTop_charge", GenNuFromTop_charge, &b_GenNuFromTop_charge);
   fChain->SetBranchAddress("GenNuFromTop_status", GenNuFromTop_status, &b_GenNuFromTop_status);
   fChain->SetBranchAddress("GenNuFromTop_isPromptHard", GenNuFromTop_isPromptHard, &b_GenNuFromTop_isPromptHard);
   fChain->SetBranchAddress("nGenBQuarkFromHafterISR", &nGenBQuarkFromHafterISR, &b_nGenBQuarkFromHafterISR);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_pdgId", &GenBQuarkFromHafterISR_pdgId, &b_GenBQuarkFromHafterISR_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_pt", &GenBQuarkFromHafterISR_pt, &b_GenBQuarkFromHafterISR_pt);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_eta", &GenBQuarkFromHafterISR_eta, &b_GenBQuarkFromHafterISR_eta);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_phi", &GenBQuarkFromHafterISR_phi, &b_GenBQuarkFromHafterISR_phi);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_mass", &GenBQuarkFromHafterISR_mass, &b_GenBQuarkFromHafterISR_mass);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_charge", &GenBQuarkFromHafterISR_charge, &b_GenBQuarkFromHafterISR_charge);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_status", &GenBQuarkFromHafterISR_status, &b_GenBQuarkFromHafterISR_status);
   fChain->SetBranchAddress("GenBQuarkFromHafterISR_isPromptHard", &GenBQuarkFromHafterISR_isPromptHard, &b_GenBQuarkFromHafterISR_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltPFDoubleJetLooseID76", &ntrgObjects_hltPFDoubleJetLooseID76, &b_ntrgObjects_hltPFDoubleJetLooseID76);
   fChain->SetBranchAddress("ntrgObjects_hltBTagPFCSVp016SingleWithMatching", &ntrgObjects_hltBTagPFCSVp016SingleWithMatching, &b_ntrgObjects_hltBTagPFCSVp016SingleWithMatching);
   fChain->SetBranchAddress("nsoftActivityEWKJets", &nsoftActivityEWKJets, &b_nsoftActivityEWKJets);
   fChain->SetBranchAddress("softActivityEWKJets_pt", softActivityEWKJets_pt, &b_softActivityEWKJets_pt);
   fChain->SetBranchAddress("softActivityEWKJets_eta", softActivityEWKJets_eta, &b_softActivityEWKJets_eta);
   fChain->SetBranchAddress("softActivityEWKJets_phi", softActivityEWKJets_phi, &b_softActivityEWKJets_phi);
   fChain->SetBranchAddress("softActivityEWKJets_mass", softActivityEWKJets_mass, &b_softActivityEWKJets_mass);
   fChain->SetBranchAddress("nHTXSRivetProducer_cat0", &nHTXSRivetProducer_cat0, &b_nHTXSRivetProducer_cat0);
   fChain->SetBranchAddress("HTXSRivetProducer_cat0", HTXSRivetProducer_cat0, &b_HTXSRivetProducer_cat0);
   fChain->SetBranchAddress("nHTXSRivetProducer_cat1", &nHTXSRivetProducer_cat1, &b_nHTXSRivetProducer_cat1);
   fChain->SetBranchAddress("HTXSRivetProducer_cat1", HTXSRivetProducer_cat1, &b_HTXSRivetProducer_cat1);
   fChain->SetBranchAddress("nsoftActivityVHJets", &nsoftActivityVHJets, &b_nsoftActivityVHJets);
   fChain->SetBranchAddress("softActivityVHJets_pt", softActivityVHJets_pt, &b_softActivityVHJets_pt);
   fChain->SetBranchAddress("softActivityVHJets_eta", softActivityVHJets_eta, &b_softActivityVHJets_eta);
   fChain->SetBranchAddress("softActivityVHJets_phi", softActivityVHJets_phi, &b_softActivityVHJets_phi);
   fChain->SetBranchAddress("softActivityVHJets_mass", softActivityVHJets_mass, &b_softActivityVHJets_mass);
   fChain->SetBranchAddress("ntrgObjects_hltQuadPFCentralJetLooseID30", &ntrgObjects_hltQuadPFCentralJetLooseID30, &b_ntrgObjects_hltQuadPFCentralJetLooseID30);
   fChain->SetBranchAddress("nGenNu", &nGenNu, &b_nGenNu);
   fChain->SetBranchAddress("GenNu_charge", GenNu_charge, &b_GenNu_charge);
   fChain->SetBranchAddress("GenNu_status", GenNu_status, &b_GenNu_status);
   fChain->SetBranchAddress("GenNu_isPromptHard", GenNu_isPromptHard, &b_GenNu_isPromptHard);
   fChain->SetBranchAddress("GenNu_pdgId", GenNu_pdgId, &b_GenNu_pdgId);
   fChain->SetBranchAddress("GenNu_pt", GenNu_pt, &b_GenNu_pt);
   fChain->SetBranchAddress("GenNu_eta", GenNu_eta, &b_GenNu_eta);
   fChain->SetBranchAddress("GenNu_phi", GenNu_phi, &b_GenNu_phi);
   fChain->SetBranchAddress("GenNu_mass", GenNu_mass, &b_GenNu_mass);
   fChain->SetBranchAddress("GenNu_motherId", GenNu_motherId, &b_GenNu_motherId);
   fChain->SetBranchAddress("GenNu_grandmotherId", GenNu_grandmotherId, &b_GenNu_grandmotherId);
   fChain->SetBranchAddress("GenNu_sourceId", GenNu_sourceId, &b_GenNu_sourceId);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp087Triple", &ntrgObjects_hltBTagCaloCSVp087Triple, &b_ntrgObjects_hltBTagCaloCSVp087Triple);
   fChain->SetBranchAddress("ntrgObjects_hltEle25eta2p1WPLoose", &ntrgObjects_hltEle25eta2p1WPLoose, &b_ntrgObjects_hltEle25eta2p1WPLoose);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_pt", trgObjects_hltEle25eta2p1WPLoose_pt, &b_trgObjects_hltEle25eta2p1WPLoose_pt);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_eta", trgObjects_hltEle25eta2p1WPLoose_eta, &b_trgObjects_hltEle25eta2p1WPLoose_eta);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_phi", trgObjects_hltEle25eta2p1WPLoose_phi, &b_trgObjects_hltEle25eta2p1WPLoose_phi);
   fChain->SetBranchAddress("trgObjects_hltEle25eta2p1WPLoose_mass", trgObjects_hltEle25eta2p1WPLoose_mass, &b_trgObjects_hltEle25eta2p1WPLoose_mass);
   fChain->SetBranchAddress("nSubjetAK08softdrop", &nSubjetAK08softdrop, &b_nSubjetAK08softdrop);
   fChain->SetBranchAddress("SubjetAK08softdrop_pt", SubjetAK08softdrop_pt, &b_SubjetAK08softdrop_pt);
   fChain->SetBranchAddress("SubjetAK08softdrop_eta", SubjetAK08softdrop_eta, &b_SubjetAK08softdrop_eta);
   fChain->SetBranchAddress("SubjetAK08softdrop_phi", SubjetAK08softdrop_phi, &b_SubjetAK08softdrop_phi);
   fChain->SetBranchAddress("SubjetAK08softdrop_mass", SubjetAK08softdrop_mass, &b_SubjetAK08softdrop_mass);
   fChain->SetBranchAddress("SubjetAK08softdrop_btag", SubjetAK08softdrop_btag, &b_SubjetAK08softdrop_btag);
   fChain->SetBranchAddress("SubjetAK08softdrop_fromFJ", SubjetAK08softdrop_fromFJ, &b_SubjetAK08softdrop_fromFJ);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr", SubjetAK08softdrop_corr, &b_SubjetAK08softdrop_corr);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteStatUp", SubjetAK08softdrop_corr_AbsoluteStatUp, &b_SubjetAK08softdrop_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteStatDown", SubjetAK08softdrop_corr_AbsoluteStatDown, &b_SubjetAK08softdrop_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteScaleUp", SubjetAK08softdrop_corr_AbsoluteScaleUp, &b_SubjetAK08softdrop_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteScaleDown", SubjetAK08softdrop_corr_AbsoluteScaleDown, &b_SubjetAK08softdrop_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteFlavMapUp", SubjetAK08softdrop_corr_AbsoluteFlavMapUp, &b_SubjetAK08softdrop_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteFlavMapDown", SubjetAK08softdrop_corr_AbsoluteFlavMapDown, &b_SubjetAK08softdrop_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteMPFBiasUp", SubjetAK08softdrop_corr_AbsoluteMPFBiasUp, &b_SubjetAK08softdrop_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_AbsoluteMPFBiasDown", SubjetAK08softdrop_corr_AbsoluteMPFBiasDown, &b_SubjetAK08softdrop_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FragmentationUp", SubjetAK08softdrop_corr_FragmentationUp, &b_SubjetAK08softdrop_corr_FragmentationUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FragmentationDown", SubjetAK08softdrop_corr_FragmentationDown, &b_SubjetAK08softdrop_corr_FragmentationDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SinglePionECALUp", SubjetAK08softdrop_corr_SinglePionECALUp, &b_SubjetAK08softdrop_corr_SinglePionECALUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SinglePionECALDown", SubjetAK08softdrop_corr_SinglePionECALDown, &b_SubjetAK08softdrop_corr_SinglePionECALDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SinglePionHCALUp", SubjetAK08softdrop_corr_SinglePionHCALUp, &b_SubjetAK08softdrop_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SinglePionHCALDown", SubjetAK08softdrop_corr_SinglePionHCALDown, &b_SubjetAK08softdrop_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorQCDUp", SubjetAK08softdrop_corr_FlavorQCDUp, &b_SubjetAK08softdrop_corr_FlavorQCDUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorQCDDown", SubjetAK08softdrop_corr_FlavorQCDDown, &b_SubjetAK08softdrop_corr_FlavorQCDDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimePtEtaUp", SubjetAK08softdrop_corr_TimePtEtaUp, &b_SubjetAK08softdrop_corr_TimePtEtaUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimePtEtaDown", SubjetAK08softdrop_corr_TimePtEtaDown, &b_SubjetAK08softdrop_corr_TimePtEtaDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJEREC1Up", SubjetAK08softdrop_corr_RelativeJEREC1Up, &b_SubjetAK08softdrop_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJEREC1Down", SubjetAK08softdrop_corr_RelativeJEREC1Down, &b_SubjetAK08softdrop_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJEREC2Up", SubjetAK08softdrop_corr_RelativeJEREC2Up, &b_SubjetAK08softdrop_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJEREC2Down", SubjetAK08softdrop_corr_RelativeJEREC2Down, &b_SubjetAK08softdrop_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJERHFUp", SubjetAK08softdrop_corr_RelativeJERHFUp, &b_SubjetAK08softdrop_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeJERHFDown", SubjetAK08softdrop_corr_RelativeJERHFDown, &b_SubjetAK08softdrop_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtBBUp", SubjetAK08softdrop_corr_RelativePtBBUp, &b_SubjetAK08softdrop_corr_RelativePtBBUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtBBDown", SubjetAK08softdrop_corr_RelativePtBBDown, &b_SubjetAK08softdrop_corr_RelativePtBBDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtEC1Up", SubjetAK08softdrop_corr_RelativePtEC1Up, &b_SubjetAK08softdrop_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtEC1Down", SubjetAK08softdrop_corr_RelativePtEC1Down, &b_SubjetAK08softdrop_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtEC2Up", SubjetAK08softdrop_corr_RelativePtEC2Up, &b_SubjetAK08softdrop_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtEC2Down", SubjetAK08softdrop_corr_RelativePtEC2Down, &b_SubjetAK08softdrop_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtHFUp", SubjetAK08softdrop_corr_RelativePtHFUp, &b_SubjetAK08softdrop_corr_RelativePtHFUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativePtHFDown", SubjetAK08softdrop_corr_RelativePtHFDown, &b_SubjetAK08softdrop_corr_RelativePtHFDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeBalUp", SubjetAK08softdrop_corr_RelativeBalUp, &b_SubjetAK08softdrop_corr_RelativeBalUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeBalDown", SubjetAK08softdrop_corr_RelativeBalDown, &b_SubjetAK08softdrop_corr_RelativeBalDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeFSRUp", SubjetAK08softdrop_corr_RelativeFSRUp, &b_SubjetAK08softdrop_corr_RelativeFSRUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeFSRDown", SubjetAK08softdrop_corr_RelativeFSRDown, &b_SubjetAK08softdrop_corr_RelativeFSRDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatFSRUp", SubjetAK08softdrop_corr_RelativeStatFSRUp, &b_SubjetAK08softdrop_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatFSRDown", SubjetAK08softdrop_corr_RelativeStatFSRDown, &b_SubjetAK08softdrop_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatECUp", SubjetAK08softdrop_corr_RelativeStatECUp, &b_SubjetAK08softdrop_corr_RelativeStatECUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatECDown", SubjetAK08softdrop_corr_RelativeStatECDown, &b_SubjetAK08softdrop_corr_RelativeStatECDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatHFUp", SubjetAK08softdrop_corr_RelativeStatHFUp, &b_SubjetAK08softdrop_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_RelativeStatHFDown", SubjetAK08softdrop_corr_RelativeStatHFDown, &b_SubjetAK08softdrop_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpDataMCUp", SubjetAK08softdrop_corr_PileUpDataMCUp, &b_SubjetAK08softdrop_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpDataMCDown", SubjetAK08softdrop_corr_PileUpDataMCDown, &b_SubjetAK08softdrop_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtRefUp", SubjetAK08softdrop_corr_PileUpPtRefUp, &b_SubjetAK08softdrop_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtRefDown", SubjetAK08softdrop_corr_PileUpPtRefDown, &b_SubjetAK08softdrop_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtBBUp", SubjetAK08softdrop_corr_PileUpPtBBUp, &b_SubjetAK08softdrop_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtBBDown", SubjetAK08softdrop_corr_PileUpPtBBDown, &b_SubjetAK08softdrop_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtEC1Up", SubjetAK08softdrop_corr_PileUpPtEC1Up, &b_SubjetAK08softdrop_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtEC1Down", SubjetAK08softdrop_corr_PileUpPtEC1Down, &b_SubjetAK08softdrop_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtEC2Up", SubjetAK08softdrop_corr_PileUpPtEC2Up, &b_SubjetAK08softdrop_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtEC2Down", SubjetAK08softdrop_corr_PileUpPtEC2Down, &b_SubjetAK08softdrop_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtHFUp", SubjetAK08softdrop_corr_PileUpPtHFUp, &b_SubjetAK08softdrop_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpPtHFDown", SubjetAK08softdrop_corr_PileUpPtHFDown, &b_SubjetAK08softdrop_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpMuZeroUp", SubjetAK08softdrop_corr_PileUpMuZeroUp, &b_SubjetAK08softdrop_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpMuZeroDown", SubjetAK08softdrop_corr_PileUpMuZeroDown, &b_SubjetAK08softdrop_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpEnvelopeUp", SubjetAK08softdrop_corr_PileUpEnvelopeUp, &b_SubjetAK08softdrop_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_PileUpEnvelopeDown", SubjetAK08softdrop_corr_PileUpEnvelopeDown, &b_SubjetAK08softdrop_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalPileUpUp", SubjetAK08softdrop_corr_SubTotalPileUpUp, &b_SubjetAK08softdrop_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalPileUpDown", SubjetAK08softdrop_corr_SubTotalPileUpDown, &b_SubjetAK08softdrop_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalRelativeUp", SubjetAK08softdrop_corr_SubTotalRelativeUp, &b_SubjetAK08softdrop_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalRelativeDown", SubjetAK08softdrop_corr_SubTotalRelativeDown, &b_SubjetAK08softdrop_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalPtUp", SubjetAK08softdrop_corr_SubTotalPtUp, &b_SubjetAK08softdrop_corr_SubTotalPtUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalPtDown", SubjetAK08softdrop_corr_SubTotalPtDown, &b_SubjetAK08softdrop_corr_SubTotalPtDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalScaleUp", SubjetAK08softdrop_corr_SubTotalScaleUp, &b_SubjetAK08softdrop_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalScaleDown", SubjetAK08softdrop_corr_SubTotalScaleDown, &b_SubjetAK08softdrop_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalAbsoluteUp", SubjetAK08softdrop_corr_SubTotalAbsoluteUp, &b_SubjetAK08softdrop_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalAbsoluteDown", SubjetAK08softdrop_corr_SubTotalAbsoluteDown, &b_SubjetAK08softdrop_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalMCUp", SubjetAK08softdrop_corr_SubTotalMCUp, &b_SubjetAK08softdrop_corr_SubTotalMCUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_SubTotalMCDown", SubjetAK08softdrop_corr_SubTotalMCDown, &b_SubjetAK08softdrop_corr_SubTotalMCDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalUp", SubjetAK08softdrop_corr_TotalUp, &b_SubjetAK08softdrop_corr_TotalUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalDown", SubjetAK08softdrop_corr_TotalDown, &b_SubjetAK08softdrop_corr_TotalDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoFlavorUp", SubjetAK08softdrop_corr_TotalNoFlavorUp, &b_SubjetAK08softdrop_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoFlavorDown", SubjetAK08softdrop_corr_TotalNoFlavorDown, &b_SubjetAK08softdrop_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoTimeUp", SubjetAK08softdrop_corr_TotalNoTimeUp, &b_SubjetAK08softdrop_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoTimeDown", SubjetAK08softdrop_corr_TotalNoTimeDown, &b_SubjetAK08softdrop_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoFlavorNoTimeUp", SubjetAK08softdrop_corr_TotalNoFlavorNoTimeUp, &b_SubjetAK08softdrop_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TotalNoFlavorNoTimeDown", SubjetAK08softdrop_corr_TotalNoFlavorNoTimeDown, &b_SubjetAK08softdrop_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorZJetUp", SubjetAK08softdrop_corr_FlavorZJetUp, &b_SubjetAK08softdrop_corr_FlavorZJetUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorZJetDown", SubjetAK08softdrop_corr_FlavorZJetDown, &b_SubjetAK08softdrop_corr_FlavorZJetDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPhotonJetUp", SubjetAK08softdrop_corr_FlavorPhotonJetUp, &b_SubjetAK08softdrop_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPhotonJetDown", SubjetAK08softdrop_corr_FlavorPhotonJetDown, &b_SubjetAK08softdrop_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureGluonUp", SubjetAK08softdrop_corr_FlavorPureGluonUp, &b_SubjetAK08softdrop_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureGluonDown", SubjetAK08softdrop_corr_FlavorPureGluonDown, &b_SubjetAK08softdrop_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureQuarkUp", SubjetAK08softdrop_corr_FlavorPureQuarkUp, &b_SubjetAK08softdrop_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureQuarkDown", SubjetAK08softdrop_corr_FlavorPureQuarkDown, &b_SubjetAK08softdrop_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureCharmUp", SubjetAK08softdrop_corr_FlavorPureCharmUp, &b_SubjetAK08softdrop_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureCharmDown", SubjetAK08softdrop_corr_FlavorPureCharmDown, &b_SubjetAK08softdrop_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureBottomUp", SubjetAK08softdrop_corr_FlavorPureBottomUp, &b_SubjetAK08softdrop_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_FlavorPureBottomDown", SubjetAK08softdrop_corr_FlavorPureBottomDown, &b_SubjetAK08softdrop_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunBCDUp", SubjetAK08softdrop_corr_TimeRunBCDUp, &b_SubjetAK08softdrop_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunBCDDown", SubjetAK08softdrop_corr_TimeRunBCDDown, &b_SubjetAK08softdrop_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunEFUp", SubjetAK08softdrop_corr_TimeRunEFUp, &b_SubjetAK08softdrop_corr_TimeRunEFUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunEFDown", SubjetAK08softdrop_corr_TimeRunEFDown, &b_SubjetAK08softdrop_corr_TimeRunEFDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunGUp", SubjetAK08softdrop_corr_TimeRunGUp, &b_SubjetAK08softdrop_corr_TimeRunGUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunGDown", SubjetAK08softdrop_corr_TimeRunGDown, &b_SubjetAK08softdrop_corr_TimeRunGDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunHUp", SubjetAK08softdrop_corr_TimeRunHUp, &b_SubjetAK08softdrop_corr_TimeRunHUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_TimeRunHDown", SubjetAK08softdrop_corr_TimeRunHDown, &b_SubjetAK08softdrop_corr_TimeRunHDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupMPFInSituUp", SubjetAK08softdrop_corr_CorrelationGroupMPFInSituUp, &b_SubjetAK08softdrop_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupMPFInSituDown", SubjetAK08softdrop_corr_CorrelationGroupMPFInSituDown, &b_SubjetAK08softdrop_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationUp", SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationUp, &b_SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationDown", SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationDown, &b_SubjetAK08softdrop_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupbJESUp", SubjetAK08softdrop_corr_CorrelationGroupbJESUp, &b_SubjetAK08softdrop_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupbJESDown", SubjetAK08softdrop_corr_CorrelationGroupbJESDown, &b_SubjetAK08softdrop_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupFlavorUp", SubjetAK08softdrop_corr_CorrelationGroupFlavorUp, &b_SubjetAK08softdrop_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupFlavorDown", SubjetAK08softdrop_corr_CorrelationGroupFlavorDown, &b_SubjetAK08softdrop_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedUp", SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedUp, &b_SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedDown", SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedDown, &b_SubjetAK08softdrop_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("nGenLepRecovered", &nGenLepRecovered, &b_nGenLepRecovered);
   fChain->SetBranchAddress("GenLepRecovered_pdgId", &GenLepRecovered_pdgId, &b_GenLepRecovered_pdgId);
   fChain->SetBranchAddress("GenLepRecovered_pt", &GenLepRecovered_pt, &b_GenLepRecovered_pt);
   fChain->SetBranchAddress("GenLepRecovered_eta", &GenLepRecovered_eta, &b_GenLepRecovered_eta);
   fChain->SetBranchAddress("GenLepRecovered_phi", &GenLepRecovered_phi, &b_GenLepRecovered_phi);
   fChain->SetBranchAddress("GenLepRecovered_mass", &GenLepRecovered_mass, &b_GenLepRecovered_mass);
   fChain->SetBranchAddress("GenLepRecovered_charge", &GenLepRecovered_charge, &b_GenLepRecovered_charge);
   fChain->SetBranchAddress("GenLepRecovered_status", &GenLepRecovered_status, &b_GenLepRecovered_status);
   fChain->SetBranchAddress("GenLepRecovered_isPromptHard", &GenLepRecovered_isPromptHard, &b_GenLepRecovered_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_caloJets", &ntrgObjects_caloJets, &b_ntrgObjects_caloJets);
   fChain->SetBranchAddress("trgObjects_caloJets_pt", trgObjects_caloJets_pt, &b_trgObjects_caloJets_pt);
   fChain->SetBranchAddress("nhJCMVAV2idx", &nhJCMVAV2idx, &b_nhJCMVAV2idx);
   fChain->SetBranchAddress("hJCMVAV2idx", hJCMVAV2idx, &b_hJCMVAV2idx);
   fChain->SetBranchAddress("ntrgObjects_hltPFSingleJetLooseID92", &ntrgObjects_hltPFSingleJetLooseID92, &b_ntrgObjects_hltPFSingleJetLooseID92);
   fChain->SetBranchAddress("nGenHadTaus", &nGenHadTaus, &b_nGenHadTaus);
   fChain->SetBranchAddress("GenHadTaus_charge", GenHadTaus_charge, &b_GenHadTaus_charge);
   fChain->SetBranchAddress("GenHadTaus_status", GenHadTaus_status, &b_GenHadTaus_status);
   fChain->SetBranchAddress("GenHadTaus_isPromptHard", GenHadTaus_isPromptHard, &b_GenHadTaus_isPromptHard);
   fChain->SetBranchAddress("GenHadTaus_pdgId", GenHadTaus_pdgId, &b_GenHadTaus_pdgId);
   fChain->SetBranchAddress("GenHadTaus_pt", GenHadTaus_pt, &b_GenHadTaus_pt);
   fChain->SetBranchAddress("GenHadTaus_eta", GenHadTaus_eta, &b_GenHadTaus_eta);
   fChain->SetBranchAddress("GenHadTaus_phi", GenHadTaus_phi, &b_GenHadTaus_phi);
   fChain->SetBranchAddress("GenHadTaus_mass", GenHadTaus_mass, &b_GenHadTaus_mass);
   fChain->SetBranchAddress("GenHadTaus_decayMode", GenHadTaus_decayMode, &b_GenHadTaus_decayMode);
   fChain->SetBranchAddress("ntrgObjects_hltDoubleCentralJet90", &ntrgObjects_hltDoubleCentralJet90, &b_ntrgObjects_hltDoubleCentralJet90);
   fChain->SetBranchAddress("ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60", &ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60, &b_ntrgObjects_hltL1sETM50ToETM100IorETM60Jet60dPhiMin0p4IorDoubleJetC60ETM60);
   fChain->SetBranchAddress("ntrgObjects_hltEle25WPTight", &ntrgObjects_hltEle25WPTight, &b_ntrgObjects_hltEle25WPTight);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_pt", trgObjects_hltEle25WPTight_pt, &b_trgObjects_hltEle25WPTight_pt);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_eta", trgObjects_hltEle25WPTight_eta, &b_trgObjects_hltEle25WPTight_eta);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_phi", trgObjects_hltEle25WPTight_phi, &b_trgObjects_hltEle25WPTight_phi);
   fChain->SetBranchAddress("trgObjects_hltEle25WPTight_mass", trgObjects_hltEle25WPTight_mass, &b_trgObjects_hltEle25WPTight_mass);
   fChain->SetBranchAddress("nGenVbosonsRecovered", &nGenVbosonsRecovered, &b_nGenVbosonsRecovered);
   fChain->SetBranchAddress("GenVbosonsRecovered_pdgId", &GenVbosonsRecovered_pdgId, &b_GenVbosonsRecovered_pdgId);
   fChain->SetBranchAddress("GenVbosonsRecovered_pt", &GenVbosonsRecovered_pt, &b_GenVbosonsRecovered_pt);
   fChain->SetBranchAddress("GenVbosonsRecovered_eta", &GenVbosonsRecovered_eta, &b_GenVbosonsRecovered_eta);
   fChain->SetBranchAddress("GenVbosonsRecovered_phi", &GenVbosonsRecovered_phi, &b_GenVbosonsRecovered_phi);
   fChain->SetBranchAddress("GenVbosonsRecovered_mass", &GenVbosonsRecovered_mass, &b_GenVbosonsRecovered_mass);
   fChain->SetBranchAddress("GenVbosonsRecovered_charge", &GenVbosonsRecovered_charge, &b_GenVbosonsRecovered_charge);
   fChain->SetBranchAddress("GenVbosonsRecovered_status", &GenVbosonsRecovered_status, &b_GenVbosonsRecovered_status);
   fChain->SetBranchAddress("GenVbosonsRecovered_isPromptHard", &GenVbosonsRecovered_isPromptHard, &b_GenVbosonsRecovered_isPromptHard);
   fChain->SetBranchAddress("nSubjetCA15subjetfiltered", &nSubjetCA15subjetfiltered, &b_nSubjetCA15subjetfiltered);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_pt", SubjetCA15subjetfiltered_pt, &b_SubjetCA15subjetfiltered_pt);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_eta", SubjetCA15subjetfiltered_eta, &b_SubjetCA15subjetfiltered_eta);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_phi", SubjetCA15subjetfiltered_phi, &b_SubjetCA15subjetfiltered_phi);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_mass", SubjetCA15subjetfiltered_mass, &b_SubjetCA15subjetfiltered_mass);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_btag", SubjetCA15subjetfiltered_btag, &b_SubjetCA15subjetfiltered_btag);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_jetID", SubjetCA15subjetfiltered_jetID, &b_SubjetCA15subjetfiltered_jetID);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_fromFJ", SubjetCA15subjetfiltered_fromFJ, &b_SubjetCA15subjetfiltered_fromFJ);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr", SubjetCA15subjetfiltered_corr, &b_SubjetCA15subjetfiltered_corr);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteStatUp", SubjetCA15subjetfiltered_corr_AbsoluteStatUp, &b_SubjetCA15subjetfiltered_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteStatDown", SubjetCA15subjetfiltered_corr_AbsoluteStatDown, &b_SubjetCA15subjetfiltered_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteScaleUp", SubjetCA15subjetfiltered_corr_AbsoluteScaleUp, &b_SubjetCA15subjetfiltered_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteScaleDown", SubjetCA15subjetfiltered_corr_AbsoluteScaleDown, &b_SubjetCA15subjetfiltered_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteFlavMapUp", SubjetCA15subjetfiltered_corr_AbsoluteFlavMapUp, &b_SubjetCA15subjetfiltered_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteFlavMapDown", SubjetCA15subjetfiltered_corr_AbsoluteFlavMapDown, &b_SubjetCA15subjetfiltered_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasUp", SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasUp, &b_SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasDown", SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasDown, &b_SubjetCA15subjetfiltered_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FragmentationUp", SubjetCA15subjetfiltered_corr_FragmentationUp, &b_SubjetCA15subjetfiltered_corr_FragmentationUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FragmentationDown", SubjetCA15subjetfiltered_corr_FragmentationDown, &b_SubjetCA15subjetfiltered_corr_FragmentationDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SinglePionECALUp", SubjetCA15subjetfiltered_corr_SinglePionECALUp, &b_SubjetCA15subjetfiltered_corr_SinglePionECALUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SinglePionECALDown", SubjetCA15subjetfiltered_corr_SinglePionECALDown, &b_SubjetCA15subjetfiltered_corr_SinglePionECALDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SinglePionHCALUp", SubjetCA15subjetfiltered_corr_SinglePionHCALUp, &b_SubjetCA15subjetfiltered_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SinglePionHCALDown", SubjetCA15subjetfiltered_corr_SinglePionHCALDown, &b_SubjetCA15subjetfiltered_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorQCDUp", SubjetCA15subjetfiltered_corr_FlavorQCDUp, &b_SubjetCA15subjetfiltered_corr_FlavorQCDUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorQCDDown", SubjetCA15subjetfiltered_corr_FlavorQCDDown, &b_SubjetCA15subjetfiltered_corr_FlavorQCDDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimePtEtaUp", SubjetCA15subjetfiltered_corr_TimePtEtaUp, &b_SubjetCA15subjetfiltered_corr_TimePtEtaUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimePtEtaDown", SubjetCA15subjetfiltered_corr_TimePtEtaDown, &b_SubjetCA15subjetfiltered_corr_TimePtEtaDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJEREC1Up", SubjetCA15subjetfiltered_corr_RelativeJEREC1Up, &b_SubjetCA15subjetfiltered_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJEREC1Down", SubjetCA15subjetfiltered_corr_RelativeJEREC1Down, &b_SubjetCA15subjetfiltered_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJEREC2Up", SubjetCA15subjetfiltered_corr_RelativeJEREC2Up, &b_SubjetCA15subjetfiltered_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJEREC2Down", SubjetCA15subjetfiltered_corr_RelativeJEREC2Down, &b_SubjetCA15subjetfiltered_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJERHFUp", SubjetCA15subjetfiltered_corr_RelativeJERHFUp, &b_SubjetCA15subjetfiltered_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeJERHFDown", SubjetCA15subjetfiltered_corr_RelativeJERHFDown, &b_SubjetCA15subjetfiltered_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtBBUp", SubjetCA15subjetfiltered_corr_RelativePtBBUp, &b_SubjetCA15subjetfiltered_corr_RelativePtBBUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtBBDown", SubjetCA15subjetfiltered_corr_RelativePtBBDown, &b_SubjetCA15subjetfiltered_corr_RelativePtBBDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtEC1Up", SubjetCA15subjetfiltered_corr_RelativePtEC1Up, &b_SubjetCA15subjetfiltered_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtEC1Down", SubjetCA15subjetfiltered_corr_RelativePtEC1Down, &b_SubjetCA15subjetfiltered_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtEC2Up", SubjetCA15subjetfiltered_corr_RelativePtEC2Up, &b_SubjetCA15subjetfiltered_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtEC2Down", SubjetCA15subjetfiltered_corr_RelativePtEC2Down, &b_SubjetCA15subjetfiltered_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtHFUp", SubjetCA15subjetfiltered_corr_RelativePtHFUp, &b_SubjetCA15subjetfiltered_corr_RelativePtHFUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativePtHFDown", SubjetCA15subjetfiltered_corr_RelativePtHFDown, &b_SubjetCA15subjetfiltered_corr_RelativePtHFDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeBalUp", SubjetCA15subjetfiltered_corr_RelativeBalUp, &b_SubjetCA15subjetfiltered_corr_RelativeBalUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeBalDown", SubjetCA15subjetfiltered_corr_RelativeBalDown, &b_SubjetCA15subjetfiltered_corr_RelativeBalDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeFSRUp", SubjetCA15subjetfiltered_corr_RelativeFSRUp, &b_SubjetCA15subjetfiltered_corr_RelativeFSRUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeFSRDown", SubjetCA15subjetfiltered_corr_RelativeFSRDown, &b_SubjetCA15subjetfiltered_corr_RelativeFSRDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatFSRUp", SubjetCA15subjetfiltered_corr_RelativeStatFSRUp, &b_SubjetCA15subjetfiltered_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatFSRDown", SubjetCA15subjetfiltered_corr_RelativeStatFSRDown, &b_SubjetCA15subjetfiltered_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatECUp", SubjetCA15subjetfiltered_corr_RelativeStatECUp, &b_SubjetCA15subjetfiltered_corr_RelativeStatECUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatECDown", SubjetCA15subjetfiltered_corr_RelativeStatECDown, &b_SubjetCA15subjetfiltered_corr_RelativeStatECDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatHFUp", SubjetCA15subjetfiltered_corr_RelativeStatHFUp, &b_SubjetCA15subjetfiltered_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_RelativeStatHFDown", SubjetCA15subjetfiltered_corr_RelativeStatHFDown, &b_SubjetCA15subjetfiltered_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpDataMCUp", SubjetCA15subjetfiltered_corr_PileUpDataMCUp, &b_SubjetCA15subjetfiltered_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpDataMCDown", SubjetCA15subjetfiltered_corr_PileUpDataMCDown, &b_SubjetCA15subjetfiltered_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtRefUp", SubjetCA15subjetfiltered_corr_PileUpPtRefUp, &b_SubjetCA15subjetfiltered_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtRefDown", SubjetCA15subjetfiltered_corr_PileUpPtRefDown, &b_SubjetCA15subjetfiltered_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtBBUp", SubjetCA15subjetfiltered_corr_PileUpPtBBUp, &b_SubjetCA15subjetfiltered_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtBBDown", SubjetCA15subjetfiltered_corr_PileUpPtBBDown, &b_SubjetCA15subjetfiltered_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtEC1Up", SubjetCA15subjetfiltered_corr_PileUpPtEC1Up, &b_SubjetCA15subjetfiltered_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtEC1Down", SubjetCA15subjetfiltered_corr_PileUpPtEC1Down, &b_SubjetCA15subjetfiltered_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtEC2Up", SubjetCA15subjetfiltered_corr_PileUpPtEC2Up, &b_SubjetCA15subjetfiltered_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtEC2Down", SubjetCA15subjetfiltered_corr_PileUpPtEC2Down, &b_SubjetCA15subjetfiltered_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtHFUp", SubjetCA15subjetfiltered_corr_PileUpPtHFUp, &b_SubjetCA15subjetfiltered_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpPtHFDown", SubjetCA15subjetfiltered_corr_PileUpPtHFDown, &b_SubjetCA15subjetfiltered_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpMuZeroUp", SubjetCA15subjetfiltered_corr_PileUpMuZeroUp, &b_SubjetCA15subjetfiltered_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpMuZeroDown", SubjetCA15subjetfiltered_corr_PileUpMuZeroDown, &b_SubjetCA15subjetfiltered_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpEnvelopeUp", SubjetCA15subjetfiltered_corr_PileUpEnvelopeUp, &b_SubjetCA15subjetfiltered_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_PileUpEnvelopeDown", SubjetCA15subjetfiltered_corr_PileUpEnvelopeDown, &b_SubjetCA15subjetfiltered_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalPileUpUp", SubjetCA15subjetfiltered_corr_SubTotalPileUpUp, &b_SubjetCA15subjetfiltered_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalPileUpDown", SubjetCA15subjetfiltered_corr_SubTotalPileUpDown, &b_SubjetCA15subjetfiltered_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalRelativeUp", SubjetCA15subjetfiltered_corr_SubTotalRelativeUp, &b_SubjetCA15subjetfiltered_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalRelativeDown", SubjetCA15subjetfiltered_corr_SubTotalRelativeDown, &b_SubjetCA15subjetfiltered_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalPtUp", SubjetCA15subjetfiltered_corr_SubTotalPtUp, &b_SubjetCA15subjetfiltered_corr_SubTotalPtUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalPtDown", SubjetCA15subjetfiltered_corr_SubTotalPtDown, &b_SubjetCA15subjetfiltered_corr_SubTotalPtDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalScaleUp", SubjetCA15subjetfiltered_corr_SubTotalScaleUp, &b_SubjetCA15subjetfiltered_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalScaleDown", SubjetCA15subjetfiltered_corr_SubTotalScaleDown, &b_SubjetCA15subjetfiltered_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalAbsoluteUp", SubjetCA15subjetfiltered_corr_SubTotalAbsoluteUp, &b_SubjetCA15subjetfiltered_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalAbsoluteDown", SubjetCA15subjetfiltered_corr_SubTotalAbsoluteDown, &b_SubjetCA15subjetfiltered_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalMCUp", SubjetCA15subjetfiltered_corr_SubTotalMCUp, &b_SubjetCA15subjetfiltered_corr_SubTotalMCUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_SubTotalMCDown", SubjetCA15subjetfiltered_corr_SubTotalMCDown, &b_SubjetCA15subjetfiltered_corr_SubTotalMCDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalUp", SubjetCA15subjetfiltered_corr_TotalUp, &b_SubjetCA15subjetfiltered_corr_TotalUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalDown", SubjetCA15subjetfiltered_corr_TotalDown, &b_SubjetCA15subjetfiltered_corr_TotalDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoFlavorUp", SubjetCA15subjetfiltered_corr_TotalNoFlavorUp, &b_SubjetCA15subjetfiltered_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoFlavorDown", SubjetCA15subjetfiltered_corr_TotalNoFlavorDown, &b_SubjetCA15subjetfiltered_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoTimeUp", SubjetCA15subjetfiltered_corr_TotalNoTimeUp, &b_SubjetCA15subjetfiltered_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoTimeDown", SubjetCA15subjetfiltered_corr_TotalNoTimeDown, &b_SubjetCA15subjetfiltered_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeUp", SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeUp, &b_SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeDown", SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeDown, &b_SubjetCA15subjetfiltered_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorZJetUp", SubjetCA15subjetfiltered_corr_FlavorZJetUp, &b_SubjetCA15subjetfiltered_corr_FlavorZJetUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorZJetDown", SubjetCA15subjetfiltered_corr_FlavorZJetDown, &b_SubjetCA15subjetfiltered_corr_FlavorZJetDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPhotonJetUp", SubjetCA15subjetfiltered_corr_FlavorPhotonJetUp, &b_SubjetCA15subjetfiltered_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPhotonJetDown", SubjetCA15subjetfiltered_corr_FlavorPhotonJetDown, &b_SubjetCA15subjetfiltered_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureGluonUp", SubjetCA15subjetfiltered_corr_FlavorPureGluonUp, &b_SubjetCA15subjetfiltered_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureGluonDown", SubjetCA15subjetfiltered_corr_FlavorPureGluonDown, &b_SubjetCA15subjetfiltered_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureQuarkUp", SubjetCA15subjetfiltered_corr_FlavorPureQuarkUp, &b_SubjetCA15subjetfiltered_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureQuarkDown", SubjetCA15subjetfiltered_corr_FlavorPureQuarkDown, &b_SubjetCA15subjetfiltered_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureCharmUp", SubjetCA15subjetfiltered_corr_FlavorPureCharmUp, &b_SubjetCA15subjetfiltered_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureCharmDown", SubjetCA15subjetfiltered_corr_FlavorPureCharmDown, &b_SubjetCA15subjetfiltered_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureBottomUp", SubjetCA15subjetfiltered_corr_FlavorPureBottomUp, &b_SubjetCA15subjetfiltered_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_FlavorPureBottomDown", SubjetCA15subjetfiltered_corr_FlavorPureBottomDown, &b_SubjetCA15subjetfiltered_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunBCDUp", SubjetCA15subjetfiltered_corr_TimeRunBCDUp, &b_SubjetCA15subjetfiltered_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunBCDDown", SubjetCA15subjetfiltered_corr_TimeRunBCDDown, &b_SubjetCA15subjetfiltered_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunEFUp", SubjetCA15subjetfiltered_corr_TimeRunEFUp, &b_SubjetCA15subjetfiltered_corr_TimeRunEFUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunEFDown", SubjetCA15subjetfiltered_corr_TimeRunEFDown, &b_SubjetCA15subjetfiltered_corr_TimeRunEFDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunGUp", SubjetCA15subjetfiltered_corr_TimeRunGUp, &b_SubjetCA15subjetfiltered_corr_TimeRunGUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunGDown", SubjetCA15subjetfiltered_corr_TimeRunGDown, &b_SubjetCA15subjetfiltered_corr_TimeRunGDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunHUp", SubjetCA15subjetfiltered_corr_TimeRunHUp, &b_SubjetCA15subjetfiltered_corr_TimeRunHUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_TimeRunHDown", SubjetCA15subjetfiltered_corr_TimeRunHDown, &b_SubjetCA15subjetfiltered_corr_TimeRunHDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituUp", SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituUp, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituDown", SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituDown, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationUp", SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationUp, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationDown", SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationDown, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupbJESUp", SubjetCA15subjetfiltered_corr_CorrelationGroupbJESUp, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupbJESDown", SubjetCA15subjetfiltered_corr_CorrelationGroupbJESDown, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorUp", SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorUp, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorDown", SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorDown, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedUp", SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedUp, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedDown", SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedDown, &b_SubjetCA15subjetfiltered_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("nLHE_weights_pdf_eigen", &nLHE_weights_pdf_eigen, &b_nLHE_weights_pdf_eigen);
   fChain->SetBranchAddress("LHE_weights_pdf_eigen", LHE_weights_pdf_eigen, &b_LHE_weights_pdf_eigen);
   fChain->SetBranchAddress("nvLeptons", &nvLeptons, &b_nvLeptons);
   fChain->SetBranchAddress("vLeptons_charge", vLeptons_charge, &b_vLeptons_charge);
   fChain->SetBranchAddress("vLeptons_tightId", vLeptons_tightId, &b_vLeptons_tightId);
   fChain->SetBranchAddress("vLeptons_eleCutIdCSA14_25ns_v1", vLeptons_eleCutIdCSA14_25ns_v1, &b_vLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("vLeptons_eleCutIdCSA14_50ns_v1", vLeptons_eleCutIdCSA14_50ns_v1, &b_vLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("vLeptons_eleCutIdSpring15_25ns_v1", vLeptons_eleCutIdSpring15_25ns_v1, &b_vLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("vLeptons_mediumIdPOG_ICHEP2016", vLeptons_mediumIdPOG_ICHEP2016, &b_vLeptons_mediumIdPOG_ICHEP2016);
   fChain->SetBranchAddress("vLeptons_dxy", vLeptons_dxy, &b_vLeptons_dxy);
   fChain->SetBranchAddress("vLeptons_dz", vLeptons_dz, &b_vLeptons_dz);
   fChain->SetBranchAddress("vLeptons_edxy", vLeptons_edxy, &b_vLeptons_edxy);
   fChain->SetBranchAddress("vLeptons_edz", vLeptons_edz, &b_vLeptons_edz);
   fChain->SetBranchAddress("vLeptons_ip3d", vLeptons_ip3d, &b_vLeptons_ip3d);
   fChain->SetBranchAddress("vLeptons_sip3d", vLeptons_sip3d, &b_vLeptons_sip3d);
   fChain->SetBranchAddress("vLeptons_convVeto", vLeptons_convVeto, &b_vLeptons_convVeto);
   fChain->SetBranchAddress("vLeptons_lostHits", vLeptons_lostHits, &b_vLeptons_lostHits);
   fChain->SetBranchAddress("vLeptons_relIso03", vLeptons_relIso03, &b_vLeptons_relIso03);
   fChain->SetBranchAddress("vLeptons_relIso04", vLeptons_relIso04, &b_vLeptons_relIso04);
   fChain->SetBranchAddress("vLeptons_miniRelIso", vLeptons_miniRelIso, &b_vLeptons_miniRelIso);
   fChain->SetBranchAddress("vLeptons_relIsoAn04", vLeptons_relIsoAn04, &b_vLeptons_relIsoAn04);
   fChain->SetBranchAddress("vLeptons_tightCharge", vLeptons_tightCharge, &b_vLeptons_tightCharge);
   fChain->SetBranchAddress("vLeptons_mcMatchId", vLeptons_mcMatchId, &b_vLeptons_mcMatchId);
   fChain->SetBranchAddress("vLeptons_mcMatchAny", vLeptons_mcMatchAny, &b_vLeptons_mcMatchAny);
   fChain->SetBranchAddress("vLeptons_mcMatchTau", vLeptons_mcMatchTau, &b_vLeptons_mcMatchTau);
   fChain->SetBranchAddress("vLeptons_mcPt", vLeptons_mcPt, &b_vLeptons_mcPt);
   fChain->SetBranchAddress("vLeptons_mediumMuonId", vLeptons_mediumMuonId, &b_vLeptons_mediumMuonId);
   fChain->SetBranchAddress("vLeptons_pdgId", vLeptons_pdgId, &b_vLeptons_pdgId);
   fChain->SetBranchAddress("vLeptons_pt", vLeptons_pt, &b_vLeptons_pt);
   fChain->SetBranchAddress("vLeptons_eta", vLeptons_eta, &b_vLeptons_eta);
   fChain->SetBranchAddress("vLeptons_phi", vLeptons_phi, &b_vLeptons_phi);
   fChain->SetBranchAddress("vLeptons_mass", vLeptons_mass, &b_vLeptons_mass);
   fChain->SetBranchAddress("vLeptons_looseIdSusy", vLeptons_looseIdSusy, &b_vLeptons_looseIdSusy);
   fChain->SetBranchAddress("vLeptons_looseIdPOG", vLeptons_looseIdPOG, &b_vLeptons_looseIdPOG);
   fChain->SetBranchAddress("vLeptons_chargedHadRelIso03", vLeptons_chargedHadRelIso03, &b_vLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("vLeptons_chargedHadRelIso04", vLeptons_chargedHadRelIso04, &b_vLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("vLeptons_eleSieie", vLeptons_eleSieie, &b_vLeptons_eleSieie);
   fChain->SetBranchAddress("vLeptons_eleDEta", vLeptons_eleDEta, &b_vLeptons_eleDEta);
   fChain->SetBranchAddress("vLeptons_eleDPhi", vLeptons_eleDPhi, &b_vLeptons_eleDPhi);
   fChain->SetBranchAddress("vLeptons_eleHoE", vLeptons_eleHoE, &b_vLeptons_eleHoE);
   fChain->SetBranchAddress("vLeptons_eleMissingHits", vLeptons_eleMissingHits, &b_vLeptons_eleMissingHits);
   fChain->SetBranchAddress("vLeptons_eleChi2", vLeptons_eleChi2, &b_vLeptons_eleChi2);
   fChain->SetBranchAddress("vLeptons_convVetoFull", vLeptons_convVetoFull, &b_vLeptons_convVetoFull);
   fChain->SetBranchAddress("vLeptons_eleMVArawSpring15Trig", vLeptons_eleMVArawSpring15Trig, &b_vLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("vLeptons_eleMVAIdSpring15Trig", vLeptons_eleMVAIdSpring15Trig, &b_vLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("vLeptons_eleMVArawSpring15NonTrig", vLeptons_eleMVArawSpring15NonTrig, &b_vLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("vLeptons_eleMVAIdSpring15NonTrig", vLeptons_eleMVAIdSpring15NonTrig, &b_vLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("vLeptons_eleMVArawSpring16GenPurp", vLeptons_eleMVArawSpring16GenPurp, &b_vLeptons_eleMVArawSpring16GenPurp);
   fChain->SetBranchAddress("vLeptons_eleMVAIdSppring16GenPurp", vLeptons_eleMVAIdSppring16GenPurp, &b_vLeptons_eleMVAIdSppring16GenPurp);
   fChain->SetBranchAddress("vLeptons_nStations", vLeptons_nStations, &b_vLeptons_nStations);
   fChain->SetBranchAddress("vLeptons_trkKink", vLeptons_trkKink, &b_vLeptons_trkKink);
   fChain->SetBranchAddress("vLeptons_segmentCompatibility", vLeptons_segmentCompatibility, &b_vLeptons_segmentCompatibility);
   fChain->SetBranchAddress("vLeptons_caloCompatibility", vLeptons_caloCompatibility, &b_vLeptons_caloCompatibility);
   fChain->SetBranchAddress("vLeptons_globalTrackChi2", vLeptons_globalTrackChi2, &b_vLeptons_globalTrackChi2);
   fChain->SetBranchAddress("vLeptons_nChamberHits", vLeptons_nChamberHits, &b_vLeptons_nChamberHits);
   fChain->SetBranchAddress("vLeptons_isPFMuon", vLeptons_isPFMuon, &b_vLeptons_isPFMuon);
   fChain->SetBranchAddress("vLeptons_isGlobalMuon", vLeptons_isGlobalMuon, &b_vLeptons_isGlobalMuon);
   fChain->SetBranchAddress("vLeptons_isTrackerMuon", vLeptons_isTrackerMuon, &b_vLeptons_isTrackerMuon);
   fChain->SetBranchAddress("vLeptons_pixelHits", vLeptons_pixelHits, &b_vLeptons_pixelHits);
   fChain->SetBranchAddress("vLeptons_trackerLayers", vLeptons_trackerLayers, &b_vLeptons_trackerLayers);
   fChain->SetBranchAddress("vLeptons_pixelLayers", vLeptons_pixelLayers, &b_vLeptons_pixelLayers);
   fChain->SetBranchAddress("vLeptons_mvaTTH", vLeptons_mvaTTH, &b_vLeptons_mvaTTH);
   fChain->SetBranchAddress("vLeptons_jetOverlapIdx", vLeptons_jetOverlapIdx, &b_vLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("vLeptons_jetPtRatio", vLeptons_jetPtRatio, &b_vLeptons_jetPtRatio);
   fChain->SetBranchAddress("vLeptons_jetBTagCSV", vLeptons_jetBTagCSV, &b_vLeptons_jetBTagCSV);
   fChain->SetBranchAddress("vLeptons_jetDR", vLeptons_jetDR, &b_vLeptons_jetDR);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetPtRatio", vLeptons_mvaTTHjetPtRatio, &b_vLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetBTagCSV", vLeptons_mvaTTHjetBTagCSV, &b_vLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetDR", vLeptons_mvaTTHjetDR, &b_vLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("vLeptons_pfRelIso03", vLeptons_pfRelIso03, &b_vLeptons_pfRelIso03);
   fChain->SetBranchAddress("vLeptons_pfRelIso04", vLeptons_pfRelIso04, &b_vLeptons_pfRelIso04);
   fChain->SetBranchAddress("vLeptons_etaSc", vLeptons_etaSc, &b_vLeptons_etaSc);
   fChain->SetBranchAddress("vLeptons_eleExpMissingInnerHits", vLeptons_eleExpMissingInnerHits, &b_vLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("vLeptons_eleooEmooP", vLeptons_eleooEmooP, &b_vLeptons_eleooEmooP);
   fChain->SetBranchAddress("vLeptons_dr03TkSumPt", vLeptons_dr03TkSumPt, &b_vLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("vLeptons_eleEcalClusterIso", vLeptons_eleEcalClusterIso, &b_vLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("vLeptons_eleHcalClusterIso", vLeptons_eleHcalClusterIso, &b_vLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("vLeptons_miniIsoCharged", vLeptons_miniIsoCharged, &b_vLeptons_miniIsoCharged);
   fChain->SetBranchAddress("vLeptons_miniIsoNeutral", vLeptons_miniIsoNeutral, &b_vLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetPtRel", vLeptons_mvaTTHjetPtRel, &b_vLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("vLeptons_mvaTTHjetNDauChargedMVASel", vLeptons_mvaTTHjetNDauChargedMVASel, &b_vLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("vLeptons_uncalibratedPt", vLeptons_uncalibratedPt, &b_vLeptons_uncalibratedPt);
   fChain->SetBranchAddress("vLeptons_SF_IsoLoose", vLeptons_SF_IsoLoose, &b_vLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IsoLoose", vLeptons_SFerr_IsoLoose, &b_vLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("vLeptons_SF_IsoTight", vLeptons_SF_IsoTight, &b_vLeptons_SF_IsoTight);
   fChain->SetBranchAddress("vLeptons_SFerr_IsoTight", vLeptons_SFerr_IsoTight, &b_vLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("vLeptons_SF_IdCutLoose", vLeptons_SF_IdCutLoose, &b_vLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IdCutLoose", vLeptons_SFerr_IdCutLoose, &b_vLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("vLeptons_SF_IdCutTight", vLeptons_SF_IdCutTight, &b_vLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("vLeptons_SFerr_IdCutTight", vLeptons_SFerr_IdCutTight, &b_vLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("vLeptons_SF_IdMVALoose", vLeptons_SF_IdMVALoose, &b_vLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("vLeptons_SFerr_IdMVALoose", vLeptons_SFerr_IdMVALoose, &b_vLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("vLeptons_SF_IdMVATight", vLeptons_SF_IdMVATight, &b_vLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("vLeptons_SFerr_IdMVATight", vLeptons_SFerr_IdMVATight, &b_vLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunD4p3", vLeptons_SF_HLT_RunD4p3, &b_vLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunD4p3", vLeptons_SFerr_HLT_RunD4p3, &b_vLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunD4p2", vLeptons_SF_HLT_RunD4p2, &b_vLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunD4p2", vLeptons_SFerr_HLT_RunD4p2, &b_vLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_SF_HLT_RunC", vLeptons_SF_HLT_RunC, &b_vLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_SFerr_HLT_RunC", vLeptons_SFerr_HLT_RunC, &b_vLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_SF_trk_eta", vLeptons_SF_trk_eta, &b_vLeptons_SF_trk_eta);
   fChain->SetBranchAddress("vLeptons_SFerr_trk_eta", vLeptons_SFerr_trk_eta, &b_vLeptons_SFerr_trk_eta);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunD4p3", vLeptons_Eff_HLT_RunD4p3, &b_vLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunD4p3", vLeptons_Efferr_HLT_RunD4p3, &b_vLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunD4p2", vLeptons_Eff_HLT_RunD4p2, &b_vLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunD4p2", vLeptons_Efferr_HLT_RunD4p2, &b_vLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("vLeptons_Eff_HLT_RunC", vLeptons_Eff_HLT_RunC, &b_vLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("vLeptons_Efferr_HLT_RunC", vLeptons_Efferr_HLT_RunC, &b_vLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching", &ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching, &b_ntrgObjects_hltBTagCaloCSVp014DoubleWithMatching);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt", trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_pt);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta", trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_eta);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi", trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_phi);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass", trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass, &b_trgObjects_hltBTagCaloCSVp014DoubleWithMatching_mass);
   fChain->SetBranchAddress("npileUpVertex_z", &npileUpVertex_z, &b_npileUpVertex_z);
   fChain->SetBranchAddress("pileUpVertex_z", pileUpVertex_z, &b_pileUpVertex_z);
   fChain->SetBranchAddress("ntrgObjects_pfJets", &ntrgObjects_pfJets, &b_ntrgObjects_pfJets);
   fChain->SetBranchAddress("trgObjects_pfJets_pt", trgObjects_pfJets_pt, &b_trgObjects_pfJets_pt);
   fChain->SetBranchAddress("ntrgObjects_pfMht", &ntrgObjects_pfMht, &b_ntrgObjects_pfMht);
   fChain->SetBranchAddress("trgObjects_pfMht_pt", trgObjects_pfMht_pt, &b_trgObjects_pfMht_pt);
   fChain->SetBranchAddress("nLHE_weights_scale", &nLHE_weights_scale, &b_nLHE_weights_scale);
   fChain->SetBranchAddress("LHE_weights_scale_id", LHE_weights_scale_id, &b_LHE_weights_scale_id);
   fChain->SetBranchAddress("LHE_weights_scale_wgt", LHE_weights_scale_wgt, &b_LHE_weights_scale_wgt);
   fChain->SetBranchAddress("ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT", &ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT, &b_ntrgObjects_hltL1sQuadJetCIorTripleJetVBFIorHTT);
   fChain->SetBranchAddress("nFatjetCA15pruned", &nFatjetCA15pruned, &b_nFatjetCA15pruned);
   fChain->SetBranchAddress("FatjetCA15pruned_pt", FatjetCA15pruned_pt, &b_FatjetCA15pruned_pt);
   fChain->SetBranchAddress("FatjetCA15pruned_eta", FatjetCA15pruned_eta, &b_FatjetCA15pruned_eta);
   fChain->SetBranchAddress("FatjetCA15pruned_phi", FatjetCA15pruned_phi, &b_FatjetCA15pruned_phi);
   fChain->SetBranchAddress("FatjetCA15pruned_mass", FatjetCA15pruned_mass, &b_FatjetCA15pruned_mass);
   fChain->SetBranchAddress("ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5", &ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5, &b_ntrgObjects_hltVBFCaloJetEtaSortedMqq150Deta1p5);
   fChain->SetBranchAddress("ntrgObjects_caloMht", &ntrgObjects_caloMht, &b_ntrgObjects_caloMht);
   fChain->SetBranchAddress("trgObjects_caloMht_pt", trgObjects_caloMht_pt, &b_trgObjects_caloMht_pt);
   fChain->SetBranchAddress("nFatjetCA15softdropz2b1filt", &nFatjetCA15softdropz2b1filt, &b_nFatjetCA15softdropz2b1filt);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1filt_pt", FatjetCA15softdropz2b1filt_pt, &b_FatjetCA15softdropz2b1filt_pt);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1filt_eta", FatjetCA15softdropz2b1filt_eta, &b_FatjetCA15softdropz2b1filt_eta);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1filt_phi", FatjetCA15softdropz2b1filt_phi, &b_FatjetCA15softdropz2b1filt_phi);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1filt_mass", FatjetCA15softdropz2b1filt_mass, &b_FatjetCA15softdropz2b1filt_mass);
   fChain->SetBranchAddress("ntrgObjects_hltDoublePFCentralJetLooseID90", &ntrgObjects_hltDoublePFCentralJetLooseID90, &b_ntrgObjects_hltDoublePFCentralJetLooseID90);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("GenJet_charge", GenJet_charge, &b_GenJet_charge);
   fChain->SetBranchAddress("GenJet_status", GenJet_status, &b_GenJet_status);
   fChain->SetBranchAddress("GenJet_isPromptHard", GenJet_isPromptHard, &b_GenJet_isPromptHard);
   fChain->SetBranchAddress("GenJet_pdgId", GenJet_pdgId, &b_GenJet_pdgId);
   fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   fChain->SetBranchAddress("GenJet_numBHadrons", GenJet_numBHadrons, &b_GenJet_numBHadrons);
   fChain->SetBranchAddress("GenJet_numCHadrons", GenJet_numCHadrons, &b_GenJet_numCHadrons);
   fChain->SetBranchAddress("GenJet_numBHadronsFromTop", GenJet_numBHadronsFromTop, &b_GenJet_numBHadronsFromTop);
   fChain->SetBranchAddress("GenJet_numCHadronsFromTop", GenJet_numCHadronsFromTop, &b_GenJet_numCHadronsFromTop);
   fChain->SetBranchAddress("GenJet_numBHadronsAfterTop", GenJet_numBHadronsAfterTop, &b_GenJet_numBHadronsAfterTop);
   fChain->SetBranchAddress("GenJet_numCHadronsAfterTop", GenJet_numCHadronsAfterTop, &b_GenJet_numCHadronsAfterTop);
   fChain->SetBranchAddress("GenJet_wNuPt", GenJet_wNuPt, &b_GenJet_wNuPt);
   fChain->SetBranchAddress("GenJet_wNuEta", GenJet_wNuEta, &b_GenJet_wNuEta);
   fChain->SetBranchAddress("GenJet_wNuPhi", GenJet_wNuPhi, &b_GenJet_wNuPhi);
   fChain->SetBranchAddress("GenJet_wNuM", GenJet_wNuM, &b_GenJet_wNuM);
   fChain->SetBranchAddress("nGenVbosons", &nGenVbosons, &b_nGenVbosons);
   fChain->SetBranchAddress("GenVbosons_pdgId", GenVbosons_pdgId, &b_GenVbosons_pdgId);
   fChain->SetBranchAddress("GenVbosons_pt", GenVbosons_pt, &b_GenVbosons_pt);
   fChain->SetBranchAddress("GenVbosons_eta", GenVbosons_eta, &b_GenVbosons_eta);
   fChain->SetBranchAddress("GenVbosons_phi", GenVbosons_phi, &b_GenVbosons_phi);
   fChain->SetBranchAddress("GenVbosons_mass", GenVbosons_mass, &b_GenVbosons_mass);
   fChain->SetBranchAddress("GenVbosons_charge", GenVbosons_charge, &b_GenVbosons_charge);
   fChain->SetBranchAddress("GenVbosons_status", GenVbosons_status, &b_GenVbosons_status);
   fChain->SetBranchAddress("GenVbosons_isPromptHard", GenVbosons_isPromptHard, &b_GenVbosons_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltDoublePFJetsC100", &ntrgObjects_hltDoublePFJetsC100, &b_ntrgObjects_hltDoublePFJetsC100);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_pt", trgObjects_hltDoublePFJetsC100_pt, &b_trgObjects_hltDoublePFJetsC100_pt);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_eta", trgObjects_hltDoublePFJetsC100_eta, &b_trgObjects_hltDoublePFJetsC100_eta);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_phi", trgObjects_hltDoublePFJetsC100_phi, &b_trgObjects_hltDoublePFJetsC100_phi);
   fChain->SetBranchAddress("trgObjects_hltDoublePFJetsC100_mass", trgObjects_hltDoublePFJetsC100_mass, &b_trgObjects_hltDoublePFJetsC100_mass);
   fChain->SetBranchAddress("nSubjetCA15pruned", &nSubjetCA15pruned, &b_nSubjetCA15pruned);
   fChain->SetBranchAddress("SubjetCA15pruned_pt", SubjetCA15pruned_pt, &b_SubjetCA15pruned_pt);
   fChain->SetBranchAddress("SubjetCA15pruned_eta", SubjetCA15pruned_eta, &b_SubjetCA15pruned_eta);
   fChain->SetBranchAddress("SubjetCA15pruned_phi", SubjetCA15pruned_phi, &b_SubjetCA15pruned_phi);
   fChain->SetBranchAddress("SubjetCA15pruned_mass", SubjetCA15pruned_mass, &b_SubjetCA15pruned_mass);
   fChain->SetBranchAddress("SubjetCA15pruned_btag", SubjetCA15pruned_btag, &b_SubjetCA15pruned_btag);
   fChain->SetBranchAddress("SubjetCA15pruned_jetID", SubjetCA15pruned_jetID, &b_SubjetCA15pruned_jetID);
   fChain->SetBranchAddress("SubjetCA15pruned_fromFJ", SubjetCA15pruned_fromFJ, &b_SubjetCA15pruned_fromFJ);
   fChain->SetBranchAddress("ntrgObjects_caloMet", &ntrgObjects_caloMet, &b_ntrgObjects_caloMet);
   fChain->SetBranchAddress("trgObjects_caloMet_pt", trgObjects_caloMet_pt, &b_trgObjects_caloMet_pt);
   fChain->SetBranchAddress("nFatjetCA15ungroomed", &nFatjetCA15ungroomed, &b_nFatjetCA15ungroomed);
   fChain->SetBranchAddress("FatjetCA15ungroomed_pt", FatjetCA15ungroomed_pt, &b_FatjetCA15ungroomed_pt);
   fChain->SetBranchAddress("FatjetCA15ungroomed_eta", FatjetCA15ungroomed_eta, &b_FatjetCA15ungroomed_eta);
   fChain->SetBranchAddress("FatjetCA15ungroomed_phi", FatjetCA15ungroomed_phi, &b_FatjetCA15ungroomed_phi);
   fChain->SetBranchAddress("FatjetCA15ungroomed_mass", FatjetCA15ungroomed_mass, &b_FatjetCA15ungroomed_mass);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau1", FatjetCA15ungroomed_tau1, &b_FatjetCA15ungroomed_tau1);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau2", FatjetCA15ungroomed_tau2, &b_FatjetCA15ungroomed_tau2);
   fChain->SetBranchAddress("FatjetCA15ungroomed_tau3", FatjetCA15ungroomed_tau3, &b_FatjetCA15ungroomed_tau3);
   fChain->SetBranchAddress("FatjetCA15ungroomed_bbtag", FatjetCA15ungroomed_bbtag, &b_FatjetCA15ungroomed_bbtag);
   fChain->SetBranchAddress("ntrgObjects_pfMet", &ntrgObjects_pfMet, &b_ntrgObjects_pfMet);
   fChain->SetBranchAddress("trgObjects_pfMet_pt", trgObjects_pfMet_pt, &b_trgObjects_pfMet_pt);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp067Single", &ntrgObjects_hltBTagCaloCSVp067Single, &b_ntrgObjects_hltBTagCaloCSVp067Single);
   fChain->SetBranchAddress("ndRaddJetsdR08", &ndRaddJetsdR08, &b_ndRaddJetsdR08);
   fChain->SetBranchAddress("dRaddJetsdR08", dRaddJetsdR08, &b_dRaddJetsdR08);
   fChain->SetBranchAddress("nl1Jets", &nl1Jets, &b_nl1Jets);
   fChain->SetBranchAddress("l1Jets_pt", &l1Jets_pt, &b_l1Jets_pt);
   fChain->SetBranchAddress("l1Jets_eta", &l1Jets_eta, &b_l1Jets_eta);
   fChain->SetBranchAddress("l1Jets_phi", &l1Jets_phi, &b_l1Jets_phi);
   fChain->SetBranchAddress("l1Jets_qual", &l1Jets_qual, &b_l1Jets_qual);
   fChain->SetBranchAddress("l1Jets_iso", &l1Jets_iso, &b_l1Jets_iso);
   fChain->SetBranchAddress("nSubjetCA15softdropz2b1filt", &nSubjetCA15softdropz2b1filt, &b_nSubjetCA15softdropz2b1filt);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_pt", SubjetCA15softdropz2b1filt_pt, &b_SubjetCA15softdropz2b1filt_pt);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_eta", SubjetCA15softdropz2b1filt_eta, &b_SubjetCA15softdropz2b1filt_eta);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_phi", SubjetCA15softdropz2b1filt_phi, &b_SubjetCA15softdropz2b1filt_phi);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_mass", SubjetCA15softdropz2b1filt_mass, &b_SubjetCA15softdropz2b1filt_mass);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_btag", SubjetCA15softdropz2b1filt_btag, &b_SubjetCA15softdropz2b1filt_btag);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_jetID", SubjetCA15softdropz2b1filt_jetID, &b_SubjetCA15softdropz2b1filt_jetID);
   fChain->SetBranchAddress("SubjetCA15softdropz2b1filt_fromFJ", SubjetCA15softdropz2b1filt_fromFJ, &b_SubjetCA15softdropz2b1filt_fromFJ);
   fChain->SetBranchAddress("nGenBQuarkFromH", &nGenBQuarkFromH, &b_nGenBQuarkFromH);
   fChain->SetBranchAddress("GenBQuarkFromH_pdgId", &GenBQuarkFromH_pdgId, &b_GenBQuarkFromH_pdgId);
   fChain->SetBranchAddress("GenBQuarkFromH_pt", &GenBQuarkFromH_pt, &b_GenBQuarkFromH_pt);
   fChain->SetBranchAddress("GenBQuarkFromH_eta", &GenBQuarkFromH_eta, &b_GenBQuarkFromH_eta);
   fChain->SetBranchAddress("GenBQuarkFromH_phi", &GenBQuarkFromH_phi, &b_GenBQuarkFromH_phi);
   fChain->SetBranchAddress("GenBQuarkFromH_mass", &GenBQuarkFromH_mass, &b_GenBQuarkFromH_mass);
   fChain->SetBranchAddress("GenBQuarkFromH_charge", &GenBQuarkFromH_charge, &b_GenBQuarkFromH_charge);
   fChain->SetBranchAddress("GenBQuarkFromH_status", &GenBQuarkFromH_status, &b_GenBQuarkFromH_status);
   fChain->SetBranchAddress("GenBQuarkFromH_isPromptHard", &GenBQuarkFromH_isPromptHard, &b_GenBQuarkFromH_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltDoubleJet65", &ntrgObjects_hltDoubleJet65, &b_ntrgObjects_hltDoubleJet65);
   fChain->SetBranchAddress("nFatjetCA15trimmed", &nFatjetCA15trimmed, &b_nFatjetCA15trimmed);
   fChain->SetBranchAddress("FatjetCA15trimmed_pt", FatjetCA15trimmed_pt, &b_FatjetCA15trimmed_pt);
   fChain->SetBranchAddress("FatjetCA15trimmed_eta", FatjetCA15trimmed_eta, &b_FatjetCA15trimmed_eta);
   fChain->SetBranchAddress("FatjetCA15trimmed_phi", FatjetCA15trimmed_phi, &b_FatjetCA15trimmed_phi);
   fChain->SetBranchAddress("FatjetCA15trimmed_mass", FatjetCA15trimmed_mass, &b_FatjetCA15trimmed_mass);
   fChain->SetBranchAddress("nSubjetCA15softdropfilt", &nSubjetCA15softdropfilt, &b_nSubjetCA15softdropfilt);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_pt", SubjetCA15softdropfilt_pt, &b_SubjetCA15softdropfilt_pt);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_eta", SubjetCA15softdropfilt_eta, &b_SubjetCA15softdropfilt_eta);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_phi", SubjetCA15softdropfilt_phi, &b_SubjetCA15softdropfilt_phi);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_mass", SubjetCA15softdropfilt_mass, &b_SubjetCA15softdropfilt_mass);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_btag", SubjetCA15softdropfilt_btag, &b_SubjetCA15softdropfilt_btag);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_jetID", SubjetCA15softdropfilt_jetID, &b_SubjetCA15softdropfilt_jetID);
   fChain->SetBranchAddress("SubjetCA15softdropfilt_fromFJ", SubjetCA15softdropfilt_fromFJ, &b_SubjetCA15softdropfilt_fromFJ);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching", &ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching, &b_ntrgObjects_hltBTagCaloCSVp026DoubleWithMatching);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt", trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_pt);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta", trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_eta);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi", trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_phi);
   fChain->SetBranchAddress("trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass", trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass, &b_trgObjects_hltBTagCaloCSVp026DoubleWithMatching_mass);
   fChain->SetBranchAddress("naLeptons", &naLeptons, &b_naLeptons);
   fChain->SetBranchAddress("aLeptons_charge", aLeptons_charge, &b_aLeptons_charge);
   fChain->SetBranchAddress("aLeptons_tightId", aLeptons_tightId, &b_aLeptons_tightId);
   fChain->SetBranchAddress("aLeptons_eleCutIdCSA14_25ns_v1", aLeptons_eleCutIdCSA14_25ns_v1, &b_aLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("aLeptons_eleCutIdCSA14_50ns_v1", aLeptons_eleCutIdCSA14_50ns_v1, &b_aLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("aLeptons_eleCutIdSpring15_25ns_v1", aLeptons_eleCutIdSpring15_25ns_v1, &b_aLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("aLeptons_mediumIdPOG_ICHEP2016", aLeptons_mediumIdPOG_ICHEP2016, &b_aLeptons_mediumIdPOG_ICHEP2016);
   fChain->SetBranchAddress("aLeptons_dxy", aLeptons_dxy, &b_aLeptons_dxy);
   fChain->SetBranchAddress("aLeptons_dz", aLeptons_dz, &b_aLeptons_dz);
   fChain->SetBranchAddress("aLeptons_edxy", aLeptons_edxy, &b_aLeptons_edxy);
   fChain->SetBranchAddress("aLeptons_edz", aLeptons_edz, &b_aLeptons_edz);
   fChain->SetBranchAddress("aLeptons_ip3d", aLeptons_ip3d, &b_aLeptons_ip3d);
   fChain->SetBranchAddress("aLeptons_sip3d", aLeptons_sip3d, &b_aLeptons_sip3d);
   fChain->SetBranchAddress("aLeptons_convVeto", aLeptons_convVeto, &b_aLeptons_convVeto);
   fChain->SetBranchAddress("aLeptons_lostHits", aLeptons_lostHits, &b_aLeptons_lostHits);
   fChain->SetBranchAddress("aLeptons_relIso03", aLeptons_relIso03, &b_aLeptons_relIso03);
   fChain->SetBranchAddress("aLeptons_relIso04", aLeptons_relIso04, &b_aLeptons_relIso04);
   fChain->SetBranchAddress("aLeptons_miniRelIso", aLeptons_miniRelIso, &b_aLeptons_miniRelIso);
   fChain->SetBranchAddress("aLeptons_relIsoAn04", aLeptons_relIsoAn04, &b_aLeptons_relIsoAn04);
   fChain->SetBranchAddress("aLeptons_tightCharge", aLeptons_tightCharge, &b_aLeptons_tightCharge);
   fChain->SetBranchAddress("aLeptons_mcMatchId", aLeptons_mcMatchId, &b_aLeptons_mcMatchId);
   fChain->SetBranchAddress("aLeptons_mcMatchAny", aLeptons_mcMatchAny, &b_aLeptons_mcMatchAny);
   fChain->SetBranchAddress("aLeptons_mcMatchTau", aLeptons_mcMatchTau, &b_aLeptons_mcMatchTau);
   fChain->SetBranchAddress("aLeptons_mcPt", aLeptons_mcPt, &b_aLeptons_mcPt);
   fChain->SetBranchAddress("aLeptons_mediumMuonId", aLeptons_mediumMuonId, &b_aLeptons_mediumMuonId);
   fChain->SetBranchAddress("aLeptons_pdgId", aLeptons_pdgId, &b_aLeptons_pdgId);
   fChain->SetBranchAddress("aLeptons_pt", aLeptons_pt, &b_aLeptons_pt);
   fChain->SetBranchAddress("aLeptons_eta", aLeptons_eta, &b_aLeptons_eta);
   fChain->SetBranchAddress("aLeptons_phi", aLeptons_phi, &b_aLeptons_phi);
   fChain->SetBranchAddress("aLeptons_mass", aLeptons_mass, &b_aLeptons_mass);
   fChain->SetBranchAddress("aLeptons_looseIdSusy", aLeptons_looseIdSusy, &b_aLeptons_looseIdSusy);
   fChain->SetBranchAddress("aLeptons_looseIdPOG", aLeptons_looseIdPOG, &b_aLeptons_looseIdPOG);
   fChain->SetBranchAddress("aLeptons_chargedHadRelIso03", aLeptons_chargedHadRelIso03, &b_aLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("aLeptons_chargedHadRelIso04", aLeptons_chargedHadRelIso04, &b_aLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("aLeptons_eleSieie", aLeptons_eleSieie, &b_aLeptons_eleSieie);
   fChain->SetBranchAddress("aLeptons_eleDEta", aLeptons_eleDEta, &b_aLeptons_eleDEta);
   fChain->SetBranchAddress("aLeptons_eleDPhi", aLeptons_eleDPhi, &b_aLeptons_eleDPhi);
   fChain->SetBranchAddress("aLeptons_eleHoE", aLeptons_eleHoE, &b_aLeptons_eleHoE);
   fChain->SetBranchAddress("aLeptons_eleMissingHits", aLeptons_eleMissingHits, &b_aLeptons_eleMissingHits);
   fChain->SetBranchAddress("aLeptons_eleChi2", aLeptons_eleChi2, &b_aLeptons_eleChi2);
   fChain->SetBranchAddress("aLeptons_convVetoFull", aLeptons_convVetoFull, &b_aLeptons_convVetoFull);
   fChain->SetBranchAddress("aLeptons_eleMVArawSpring15Trig", aLeptons_eleMVArawSpring15Trig, &b_aLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("aLeptons_eleMVAIdSpring15Trig", aLeptons_eleMVAIdSpring15Trig, &b_aLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("aLeptons_eleMVArawSpring15NonTrig", aLeptons_eleMVArawSpring15NonTrig, &b_aLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("aLeptons_eleMVAIdSpring15NonTrig", aLeptons_eleMVAIdSpring15NonTrig, &b_aLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("aLeptons_eleMVArawSpring16GenPurp", aLeptons_eleMVArawSpring16GenPurp, &b_aLeptons_eleMVArawSpring16GenPurp);
   fChain->SetBranchAddress("aLeptons_eleMVAIdSppring16GenPurp", aLeptons_eleMVAIdSppring16GenPurp, &b_aLeptons_eleMVAIdSppring16GenPurp);
   fChain->SetBranchAddress("aLeptons_nStations", aLeptons_nStations, &b_aLeptons_nStations);
   fChain->SetBranchAddress("aLeptons_trkKink", aLeptons_trkKink, &b_aLeptons_trkKink);
   fChain->SetBranchAddress("aLeptons_segmentCompatibility", aLeptons_segmentCompatibility, &b_aLeptons_segmentCompatibility);
   fChain->SetBranchAddress("aLeptons_caloCompatibility", aLeptons_caloCompatibility, &b_aLeptons_caloCompatibility);
   fChain->SetBranchAddress("aLeptons_globalTrackChi2", aLeptons_globalTrackChi2, &b_aLeptons_globalTrackChi2);
   fChain->SetBranchAddress("aLeptons_nChamberHits", aLeptons_nChamberHits, &b_aLeptons_nChamberHits);
   fChain->SetBranchAddress("aLeptons_isPFMuon", aLeptons_isPFMuon, &b_aLeptons_isPFMuon);
   fChain->SetBranchAddress("aLeptons_isGlobalMuon", aLeptons_isGlobalMuon, &b_aLeptons_isGlobalMuon);
   fChain->SetBranchAddress("aLeptons_isTrackerMuon", aLeptons_isTrackerMuon, &b_aLeptons_isTrackerMuon);
   fChain->SetBranchAddress("aLeptons_pixelHits", aLeptons_pixelHits, &b_aLeptons_pixelHits);
   fChain->SetBranchAddress("aLeptons_trackerLayers", aLeptons_trackerLayers, &b_aLeptons_trackerLayers);
   fChain->SetBranchAddress("aLeptons_pixelLayers", aLeptons_pixelLayers, &b_aLeptons_pixelLayers);
   fChain->SetBranchAddress("aLeptons_mvaTTH", aLeptons_mvaTTH, &b_aLeptons_mvaTTH);
   fChain->SetBranchAddress("aLeptons_jetOverlapIdx", aLeptons_jetOverlapIdx, &b_aLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("aLeptons_jetPtRatio", aLeptons_jetPtRatio, &b_aLeptons_jetPtRatio);
   fChain->SetBranchAddress("aLeptons_jetBTagCSV", aLeptons_jetBTagCSV, &b_aLeptons_jetBTagCSV);
   fChain->SetBranchAddress("aLeptons_jetDR", aLeptons_jetDR, &b_aLeptons_jetDR);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetPtRatio", aLeptons_mvaTTHjetPtRatio, &b_aLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetBTagCSV", aLeptons_mvaTTHjetBTagCSV, &b_aLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetDR", aLeptons_mvaTTHjetDR, &b_aLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("aLeptons_pfRelIso03", aLeptons_pfRelIso03, &b_aLeptons_pfRelIso03);
   fChain->SetBranchAddress("aLeptons_pfRelIso04", aLeptons_pfRelIso04, &b_aLeptons_pfRelIso04);
   fChain->SetBranchAddress("aLeptons_etaSc", aLeptons_etaSc, &b_aLeptons_etaSc);
   fChain->SetBranchAddress("aLeptons_eleExpMissingInnerHits", aLeptons_eleExpMissingInnerHits, &b_aLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("aLeptons_eleooEmooP", aLeptons_eleooEmooP, &b_aLeptons_eleooEmooP);
   fChain->SetBranchAddress("aLeptons_dr03TkSumPt", aLeptons_dr03TkSumPt, &b_aLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("aLeptons_eleEcalClusterIso", aLeptons_eleEcalClusterIso, &b_aLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("aLeptons_eleHcalClusterIso", aLeptons_eleHcalClusterIso, &b_aLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("aLeptons_miniIsoCharged", aLeptons_miniIsoCharged, &b_aLeptons_miniIsoCharged);
   fChain->SetBranchAddress("aLeptons_miniIsoNeutral", aLeptons_miniIsoNeutral, &b_aLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetPtRel", aLeptons_mvaTTHjetPtRel, &b_aLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("aLeptons_mvaTTHjetNDauChargedMVASel", aLeptons_mvaTTHjetNDauChargedMVASel, &b_aLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("aLeptons_uncalibratedPt", aLeptons_uncalibratedPt, &b_aLeptons_uncalibratedPt);
   fChain->SetBranchAddress("aLeptons_SF_IsoLoose", aLeptons_SF_IsoLoose, &b_aLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IsoLoose", aLeptons_SFerr_IsoLoose, &b_aLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("aLeptons_SF_IsoTight", aLeptons_SF_IsoTight, &b_aLeptons_SF_IsoTight);
   fChain->SetBranchAddress("aLeptons_SFerr_IsoTight", aLeptons_SFerr_IsoTight, &b_aLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("aLeptons_SF_IdCutLoose", aLeptons_SF_IdCutLoose, &b_aLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IdCutLoose", aLeptons_SFerr_IdCutLoose, &b_aLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("aLeptons_SF_IdCutTight", aLeptons_SF_IdCutTight, &b_aLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("aLeptons_SFerr_IdCutTight", aLeptons_SFerr_IdCutTight, &b_aLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("aLeptons_SF_IdMVALoose", aLeptons_SF_IdMVALoose, &b_aLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("aLeptons_SFerr_IdMVALoose", aLeptons_SFerr_IdMVALoose, &b_aLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("aLeptons_SF_IdMVATight", aLeptons_SF_IdMVATight, &b_aLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("aLeptons_SFerr_IdMVATight", aLeptons_SFerr_IdMVATight, &b_aLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunD4p3", aLeptons_SF_HLT_RunD4p3, &b_aLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunD4p3", aLeptons_SFerr_HLT_RunD4p3, &b_aLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunD4p2", aLeptons_SF_HLT_RunD4p2, &b_aLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunD4p2", aLeptons_SFerr_HLT_RunD4p2, &b_aLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_SF_HLT_RunC", aLeptons_SF_HLT_RunC, &b_aLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_SFerr_HLT_RunC", aLeptons_SFerr_HLT_RunC, &b_aLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_SF_trk_eta", aLeptons_SF_trk_eta, &b_aLeptons_SF_trk_eta);
   fChain->SetBranchAddress("aLeptons_SFerr_trk_eta", aLeptons_SFerr_trk_eta, &b_aLeptons_SFerr_trk_eta);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunD4p3", aLeptons_Eff_HLT_RunD4p3, &b_aLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunD4p3", aLeptons_Efferr_HLT_RunD4p3, &b_aLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunD4p2", aLeptons_Eff_HLT_RunD4p2, &b_aLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunD4p2", aLeptons_Efferr_HLT_RunD4p2, &b_aLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("aLeptons_Eff_HLT_RunC", aLeptons_Eff_HLT_RunC, &b_aLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("aLeptons_Efferr_HLT_RunC", aLeptons_Efferr_HLT_RunC, &b_aLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltPFQuadJetLooseID15", &ntrgObjects_hltPFQuadJetLooseID15, &b_ntrgObjects_hltPFQuadJetLooseID15);
   fChain->SetBranchAddress("ntrgObjects_hltQuadPFCentralJetLooseID45", &ntrgObjects_hltQuadPFCentralJetLooseID45, &b_ntrgObjects_hltQuadPFCentralJetLooseID45);
   fChain->SetBranchAddress("nGenHiggsSisters", &nGenHiggsSisters, &b_nGenHiggsSisters);
   fChain->SetBranchAddress("GenHiggsSisters_pdgId", &GenHiggsSisters_pdgId, &b_GenHiggsSisters_pdgId);
   fChain->SetBranchAddress("GenHiggsSisters_pt", &GenHiggsSisters_pt, &b_GenHiggsSisters_pt);
   fChain->SetBranchAddress("GenHiggsSisters_eta", &GenHiggsSisters_eta, &b_GenHiggsSisters_eta);
   fChain->SetBranchAddress("GenHiggsSisters_phi", &GenHiggsSisters_phi, &b_GenHiggsSisters_phi);
   fChain->SetBranchAddress("GenHiggsSisters_mass", &GenHiggsSisters_mass, &b_GenHiggsSisters_mass);
   fChain->SetBranchAddress("GenHiggsSisters_charge", &GenHiggsSisters_charge, &b_GenHiggsSisters_charge);
   fChain->SetBranchAddress("GenHiggsSisters_status", &GenHiggsSisters_status, &b_GenHiggsSisters_status);
   fChain->SetBranchAddress("GenHiggsSisters_isPromptHard", &GenHiggsSisters_isPromptHard, &b_GenHiggsSisters_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_pfHt", &ntrgObjects_pfHt, &b_ntrgObjects_pfHt);
   fChain->SetBranchAddress("trgObjects_pfHt_pt", trgObjects_pfHt_pt, &b_trgObjects_pfHt_pt);
   fChain->SetBranchAddress("ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2", &ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2, &b_ntrgObjects_hltVBFPFJetCSVSortedMqq200Detaqq1p2);
   fChain->SetBranchAddress("nhjidxaddJetsdR08", &nhjidxaddJetsdR08, &b_nhjidxaddJetsdR08);
   fChain->SetBranchAddress("hjidxaddJetsdR08", hjidxaddJetsdR08, &b_hjidxaddJetsdR08);
   fChain->SetBranchAddress("nFatjetCA15softdropfilt", &nFatjetCA15softdropfilt, &b_nFatjetCA15softdropfilt);
   fChain->SetBranchAddress("FatjetCA15softdropfilt_pt", FatjetCA15softdropfilt_pt, &b_FatjetCA15softdropfilt_pt);
   fChain->SetBranchAddress("FatjetCA15softdropfilt_eta", FatjetCA15softdropfilt_eta, &b_FatjetCA15softdropfilt_eta);
   fChain->SetBranchAddress("FatjetCA15softdropfilt_phi", FatjetCA15softdropfilt_phi, &b_FatjetCA15softdropfilt_phi);
   fChain->SetBranchAddress("FatjetCA15softdropfilt_mass", FatjetCA15softdropfilt_mass, &b_FatjetCA15softdropfilt_mass);
   fChain->SetBranchAddress("nl1Muons", &nl1Muons, &b_nl1Muons);
   fChain->SetBranchAddress("l1Muons_pt", &l1Muons_pt, &b_l1Muons_pt);
   fChain->SetBranchAddress("l1Muons_eta", &l1Muons_eta, &b_l1Muons_eta);
   fChain->SetBranchAddress("l1Muons_phi", &l1Muons_phi, &b_l1Muons_phi);
   fChain->SetBranchAddress("l1Muons_qual", &l1Muons_qual, &b_l1Muons_qual);
   fChain->SetBranchAddress("l1Muons_iso", &l1Muons_iso, &b_l1Muons_iso);
   fChain->SetBranchAddress("ntrgObjects_hltMHTNoPU90", &ntrgObjects_hltMHTNoPU90, &b_ntrgObjects_hltMHTNoPU90);
   fChain->SetBranchAddress("nFatjetAK08ungroomed", &nFatjetAK08ungroomed, &b_nFatjetAK08ungroomed);
   fChain->SetBranchAddress("FatjetAK08ungroomed_pt", FatjetAK08ungroomed_pt, &b_FatjetAK08ungroomed_pt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_eta", FatjetAK08ungroomed_eta, &b_FatjetAK08ungroomed_eta);
   fChain->SetBranchAddress("FatjetAK08ungroomed_phi", FatjetAK08ungroomed_phi, &b_FatjetAK08ungroomed_phi);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mass", FatjetAK08ungroomed_mass, &b_FatjetAK08ungroomed_mass);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau1", FatjetAK08ungroomed_tau1, &b_FatjetAK08ungroomed_tau1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau2", FatjetAK08ungroomed_tau2, &b_FatjetAK08ungroomed_tau2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_tau3", FatjetAK08ungroomed_tau3, &b_FatjetAK08ungroomed_tau3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_msoftdrop", FatjetAK08ungroomed_msoftdrop, &b_FatjetAK08ungroomed_msoftdrop);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mpruned", FatjetAK08ungroomed_mpruned, &b_FatjetAK08ungroomed_mpruned);
   fChain->SetBranchAddress("FatjetAK08ungroomed_mprunedcorr", FatjetAK08ungroomed_mprunedcorr, &b_FatjetAK08ungroomed_mprunedcorr);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L2L3", FatjetAK08ungroomed_JEC_L2L3, &b_FatjetAK08ungroomed_JEC_L2L3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L1L2L3", FatjetAK08ungroomed_JEC_L1L2L3, &b_FatjetAK08ungroomed_JEC_L1L2L3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L2L3Unc", FatjetAK08ungroomed_JEC_L2L3Unc, &b_FatjetAK08ungroomed_JEC_L2L3Unc);
   fChain->SetBranchAddress("FatjetAK08ungroomed_JEC_L1L2L3Unc", FatjetAK08ungroomed_JEC_L1L2L3Unc, &b_FatjetAK08ungroomed_JEC_L1L2L3Unc);
   fChain->SetBranchAddress("FatjetAK08ungroomed_bbtag", FatjetAK08ungroomed_bbtag, &b_FatjetAK08ungroomed_bbtag);
   fChain->SetBranchAddress("FatjetAK08ungroomed_id_Tight", FatjetAK08ungroomed_id_Tight, &b_FatjetAK08ungroomed_id_Tight);
   fChain->SetBranchAddress("FatjetAK08ungroomed_numberOfDaughters", FatjetAK08ungroomed_numberOfDaughters, &b_FatjetAK08ungroomed_numberOfDaughters);
   fChain->SetBranchAddress("FatjetAK08ungroomed_neutralEmEnergyFraction", FatjetAK08ungroomed_neutralEmEnergyFraction, &b_FatjetAK08ungroomed_neutralEmEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_neutralHadronEnergyFraction", FatjetAK08ungroomed_neutralHadronEnergyFraction, &b_FatjetAK08ungroomed_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_muonEnergyFraction", FatjetAK08ungroomed_muonEnergyFraction, &b_FatjetAK08ungroomed_muonEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedEmEnergyFraction", FatjetAK08ungroomed_chargedEmEnergyFraction, &b_FatjetAK08ungroomed_chargedEmEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedHadronEnergyFraction", FatjetAK08ungroomed_chargedHadronEnergyFraction, &b_FatjetAK08ungroomed_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("FatjetAK08ungroomed_chargedMultiplicity", FatjetAK08ungroomed_chargedMultiplicity, &b_FatjetAK08ungroomed_chargedMultiplicity);
   fChain->SetBranchAddress("FatjetAK08ungroomed_electronMultiplicity", FatjetAK08ungroomed_electronMultiplicity, &b_FatjetAK08ungroomed_electronMultiplicity);
   fChain->SetBranchAddress("FatjetAK08ungroomed_muonMultiplicity", FatjetAK08ungroomed_muonMultiplicity, &b_FatjetAK08ungroomed_muonMultiplicity);
   fChain->SetBranchAddress("FatjetAK08ungroomed_Flavour", FatjetAK08ungroomed_Flavour, &b_FatjetAK08ungroomed_Flavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_BhadronFlavour", FatjetAK08ungroomed_BhadronFlavour, &b_FatjetAK08ungroomed_BhadronFlavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_ChadronFlavour", FatjetAK08ungroomed_ChadronFlavour, &b_FatjetAK08ungroomed_ChadronFlavour);
   fChain->SetBranchAddress("FatjetAK08ungroomed_GenPt", FatjetAK08ungroomed_GenPt, &b_FatjetAK08ungroomed_GenPt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_pt", FatjetAK08ungroomed_puppi_pt, &b_FatjetAK08ungroomed_puppi_pt);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_eta", FatjetAK08ungroomed_puppi_eta, &b_FatjetAK08ungroomed_puppi_eta);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_phi", FatjetAK08ungroomed_puppi_phi, &b_FatjetAK08ungroomed_puppi_phi);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_mass", FatjetAK08ungroomed_puppi_mass, &b_FatjetAK08ungroomed_puppi_mass);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_tau1", FatjetAK08ungroomed_puppi_tau1, &b_FatjetAK08ungroomed_puppi_tau1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_tau2", FatjetAK08ungroomed_puppi_tau2, &b_FatjetAK08ungroomed_puppi_tau2);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_msoftdrop", FatjetAK08ungroomed_puppi_msoftdrop, &b_FatjetAK08ungroomed_puppi_msoftdrop);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_msoftdrop_corrL2L3", FatjetAK08ungroomed_puppi_msoftdrop_corrL2L3, &b_FatjetAK08ungroomed_puppi_msoftdrop_corrL2L3);
   fChain->SetBranchAddress("FatjetAK08ungroomed_puppi_msoftdrop_raw", FatjetAK08ungroomed_puppi_msoftdrop_raw, &b_FatjetAK08ungroomed_puppi_msoftdrop_raw);
   fChain->SetBranchAddress("FatjetAK08ungroomed_PFLepton_ptrel", FatjetAK08ungroomed_PFLepton_ptrel, &b_FatjetAK08ungroomed_PFLepton_ptrel);
   fChain->SetBranchAddress("FatjetAK08ungroomed_PFLepton_IP2D", FatjetAK08ungroomed_PFLepton_IP2D, &b_FatjetAK08ungroomed_PFLepton_IP2D);
   fChain->SetBranchAddress("FatjetAK08ungroomed_nSL", FatjetAK08ungroomed_nSL, &b_FatjetAK08ungroomed_nSL);
   fChain->SetBranchAddress("FatjetAK08ungroomed_nVtx", FatjetAK08ungroomed_nVtx, &b_FatjetAK08ungroomed_nVtx);
   fChain->SetBranchAddress("FatjetAK08ungroomed_VtxMass_1", FatjetAK08ungroomed_VtxMass_1, &b_FatjetAK08ungroomed_VtxMass_1);
   fChain->SetBranchAddress("FatjetAK08ungroomed_VtxMass_2", FatjetAK08ungroomed_VtxMass_2, &b_FatjetAK08ungroomed_VtxMass_2);
   fChain->SetBranchAddress("nGenWZQuark", &nGenWZQuark, &b_nGenWZQuark);
   fChain->SetBranchAddress("GenWZQuark_pdgId", GenWZQuark_pdgId, &b_GenWZQuark_pdgId);
   fChain->SetBranchAddress("GenWZQuark_pt", GenWZQuark_pt, &b_GenWZQuark_pt);
   fChain->SetBranchAddress("GenWZQuark_eta", GenWZQuark_eta, &b_GenWZQuark_eta);
   fChain->SetBranchAddress("GenWZQuark_phi", GenWZQuark_phi, &b_GenWZQuark_phi);
   fChain->SetBranchAddress("GenWZQuark_mass", GenWZQuark_mass, &b_GenWZQuark_mass);
   fChain->SetBranchAddress("GenWZQuark_charge", GenWZQuark_charge, &b_GenWZQuark_charge);
   fChain->SetBranchAddress("GenWZQuark_status", GenWZQuark_status, &b_GenWZQuark_status);
   fChain->SetBranchAddress("GenWZQuark_isPromptHard", GenWZQuark_isPromptHard, &b_GenWZQuark_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltPFMHTTightID90", &ntrgObjects_hltPFMHTTightID90, &b_ntrgObjects_hltPFMHTTightID90);
   fChain->SetBranchAddress("ntrgObjects_hltQuadCentralJet45", &ntrgObjects_hltQuadCentralJet45, &b_ntrgObjects_hltQuadCentralJet45);
   fChain->SetBranchAddress("ntrgObjects_hltBTagCaloCSVp022Single", &ntrgObjects_hltBTagCaloCSVp022Single, &b_ntrgObjects_hltBTagCaloCSVp022Single);
   fChain->SetBranchAddress("nselLeptons", &nselLeptons, &b_nselLeptons);
   fChain->SetBranchAddress("selLeptons_charge", selLeptons_charge, &b_selLeptons_charge);
   fChain->SetBranchAddress("selLeptons_tightId", selLeptons_tightId, &b_selLeptons_tightId);
   fChain->SetBranchAddress("selLeptons_eleCutIdCSA14_25ns_v1", selLeptons_eleCutIdCSA14_25ns_v1, &b_selLeptons_eleCutIdCSA14_25ns_v1);
   fChain->SetBranchAddress("selLeptons_eleCutIdCSA14_50ns_v1", selLeptons_eleCutIdCSA14_50ns_v1, &b_selLeptons_eleCutIdCSA14_50ns_v1);
   fChain->SetBranchAddress("selLeptons_eleCutIdSpring15_25ns_v1", selLeptons_eleCutIdSpring15_25ns_v1, &b_selLeptons_eleCutIdSpring15_25ns_v1);
   fChain->SetBranchAddress("selLeptons_mediumIdPOG_ICHEP2016", selLeptons_mediumIdPOG_ICHEP2016, &b_selLeptons_mediumIdPOG_ICHEP2016);
   fChain->SetBranchAddress("selLeptons_dxy", selLeptons_dxy, &b_selLeptons_dxy);
   fChain->SetBranchAddress("selLeptons_dz", selLeptons_dz, &b_selLeptons_dz);
   fChain->SetBranchAddress("selLeptons_edxy", selLeptons_edxy, &b_selLeptons_edxy);
   fChain->SetBranchAddress("selLeptons_edz", selLeptons_edz, &b_selLeptons_edz);
   fChain->SetBranchAddress("selLeptons_ip3d", selLeptons_ip3d, &b_selLeptons_ip3d);
   fChain->SetBranchAddress("selLeptons_sip3d", selLeptons_sip3d, &b_selLeptons_sip3d);
   fChain->SetBranchAddress("selLeptons_convVeto", selLeptons_convVeto, &b_selLeptons_convVeto);
   fChain->SetBranchAddress("selLeptons_lostHits", selLeptons_lostHits, &b_selLeptons_lostHits);
   fChain->SetBranchAddress("selLeptons_relIso03", selLeptons_relIso03, &b_selLeptons_relIso03);
   fChain->SetBranchAddress("selLeptons_relIso04", selLeptons_relIso04, &b_selLeptons_relIso04);
   fChain->SetBranchAddress("selLeptons_miniRelIso", selLeptons_miniRelIso, &b_selLeptons_miniRelIso);
   fChain->SetBranchAddress("selLeptons_relIsoAn04", selLeptons_relIsoAn04, &b_selLeptons_relIsoAn04);
   fChain->SetBranchAddress("selLeptons_tightCharge", selLeptons_tightCharge, &b_selLeptons_tightCharge);
   fChain->SetBranchAddress("selLeptons_mcMatchId", selLeptons_mcMatchId, &b_selLeptons_mcMatchId);
   fChain->SetBranchAddress("selLeptons_mcMatchAny", selLeptons_mcMatchAny, &b_selLeptons_mcMatchAny);
   fChain->SetBranchAddress("selLeptons_mcMatchTau", selLeptons_mcMatchTau, &b_selLeptons_mcMatchTau);
   fChain->SetBranchAddress("selLeptons_mcPt", selLeptons_mcPt, &b_selLeptons_mcPt);
   fChain->SetBranchAddress("selLeptons_mediumMuonId", selLeptons_mediumMuonId, &b_selLeptons_mediumMuonId);
   fChain->SetBranchAddress("selLeptons_pdgId", selLeptons_pdgId, &b_selLeptons_pdgId);
   fChain->SetBranchAddress("selLeptons_pt", selLeptons_pt, &b_selLeptons_pt);
   fChain->SetBranchAddress("selLeptons_eta", selLeptons_eta, &b_selLeptons_eta);
   fChain->SetBranchAddress("selLeptons_phi", selLeptons_phi, &b_selLeptons_phi);
   fChain->SetBranchAddress("selLeptons_mass", selLeptons_mass, &b_selLeptons_mass);
   fChain->SetBranchAddress("selLeptons_looseIdSusy", selLeptons_looseIdSusy, &b_selLeptons_looseIdSusy);
   fChain->SetBranchAddress("selLeptons_looseIdPOG", selLeptons_looseIdPOG, &b_selLeptons_looseIdPOG);
   fChain->SetBranchAddress("selLeptons_chargedHadRelIso03", selLeptons_chargedHadRelIso03, &b_selLeptons_chargedHadRelIso03);
   fChain->SetBranchAddress("selLeptons_chargedHadRelIso04", selLeptons_chargedHadRelIso04, &b_selLeptons_chargedHadRelIso04);
   fChain->SetBranchAddress("selLeptons_eleSieie", selLeptons_eleSieie, &b_selLeptons_eleSieie);
   fChain->SetBranchAddress("selLeptons_eleDEta", selLeptons_eleDEta, &b_selLeptons_eleDEta);
   fChain->SetBranchAddress("selLeptons_eleDPhi", selLeptons_eleDPhi, &b_selLeptons_eleDPhi);
   fChain->SetBranchAddress("selLeptons_eleHoE", selLeptons_eleHoE, &b_selLeptons_eleHoE);
   fChain->SetBranchAddress("selLeptons_eleMissingHits", selLeptons_eleMissingHits, &b_selLeptons_eleMissingHits);
   fChain->SetBranchAddress("selLeptons_eleChi2", selLeptons_eleChi2, &b_selLeptons_eleChi2);
   fChain->SetBranchAddress("selLeptons_convVetoFull", selLeptons_convVetoFull, &b_selLeptons_convVetoFull);
   fChain->SetBranchAddress("selLeptons_eleMVArawSpring15Trig", selLeptons_eleMVArawSpring15Trig, &b_selLeptons_eleMVArawSpring15Trig);
   fChain->SetBranchAddress("selLeptons_eleMVAIdSpring15Trig", selLeptons_eleMVAIdSpring15Trig, &b_selLeptons_eleMVAIdSpring15Trig);
   fChain->SetBranchAddress("selLeptons_eleMVArawSpring15NonTrig", selLeptons_eleMVArawSpring15NonTrig, &b_selLeptons_eleMVArawSpring15NonTrig);
   fChain->SetBranchAddress("selLeptons_eleMVAIdSpring15NonTrig", selLeptons_eleMVAIdSpring15NonTrig, &b_selLeptons_eleMVAIdSpring15NonTrig);
   fChain->SetBranchAddress("selLeptons_eleMVArawSpring16GenPurp", selLeptons_eleMVArawSpring16GenPurp, &b_selLeptons_eleMVArawSpring16GenPurp);
   fChain->SetBranchAddress("selLeptons_eleMVAIdSppring16GenPurp", selLeptons_eleMVAIdSppring16GenPurp, &b_selLeptons_eleMVAIdSppring16GenPurp);
   fChain->SetBranchAddress("selLeptons_nStations", selLeptons_nStations, &b_selLeptons_nStations);
   fChain->SetBranchAddress("selLeptons_trkKink", selLeptons_trkKink, &b_selLeptons_trkKink);
   fChain->SetBranchAddress("selLeptons_segmentCompatibility", selLeptons_segmentCompatibility, &b_selLeptons_segmentCompatibility);
   fChain->SetBranchAddress("selLeptons_caloCompatibility", selLeptons_caloCompatibility, &b_selLeptons_caloCompatibility);
   fChain->SetBranchAddress("selLeptons_globalTrackChi2", selLeptons_globalTrackChi2, &b_selLeptons_globalTrackChi2);
   fChain->SetBranchAddress("selLeptons_nChamberHits", selLeptons_nChamberHits, &b_selLeptons_nChamberHits);
   fChain->SetBranchAddress("selLeptons_isPFMuon", selLeptons_isPFMuon, &b_selLeptons_isPFMuon);
   fChain->SetBranchAddress("selLeptons_isGlobalMuon", selLeptons_isGlobalMuon, &b_selLeptons_isGlobalMuon);
   fChain->SetBranchAddress("selLeptons_isTrackerMuon", selLeptons_isTrackerMuon, &b_selLeptons_isTrackerMuon);
   fChain->SetBranchAddress("selLeptons_pixelHits", selLeptons_pixelHits, &b_selLeptons_pixelHits);
   fChain->SetBranchAddress("selLeptons_trackerLayers", selLeptons_trackerLayers, &b_selLeptons_trackerLayers);
   fChain->SetBranchAddress("selLeptons_pixelLayers", selLeptons_pixelLayers, &b_selLeptons_pixelLayers);
   fChain->SetBranchAddress("selLeptons_mvaTTH", selLeptons_mvaTTH, &b_selLeptons_mvaTTH);
   fChain->SetBranchAddress("selLeptons_jetOverlapIdx", selLeptons_jetOverlapIdx, &b_selLeptons_jetOverlapIdx);
   fChain->SetBranchAddress("selLeptons_jetPtRatio", selLeptons_jetPtRatio, &b_selLeptons_jetPtRatio);
   fChain->SetBranchAddress("selLeptons_jetBTagCSV", selLeptons_jetBTagCSV, &b_selLeptons_jetBTagCSV);
   fChain->SetBranchAddress("selLeptons_jetDR", selLeptons_jetDR, &b_selLeptons_jetDR);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetPtRatio", selLeptons_mvaTTHjetPtRatio, &b_selLeptons_mvaTTHjetPtRatio);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetBTagCSV", selLeptons_mvaTTHjetBTagCSV, &b_selLeptons_mvaTTHjetBTagCSV);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetDR", selLeptons_mvaTTHjetDR, &b_selLeptons_mvaTTHjetDR);
   fChain->SetBranchAddress("selLeptons_pfRelIso03", selLeptons_pfRelIso03, &b_selLeptons_pfRelIso03);
   fChain->SetBranchAddress("selLeptons_pfRelIso04", selLeptons_pfRelIso04, &b_selLeptons_pfRelIso04);
   fChain->SetBranchAddress("selLeptons_etaSc", selLeptons_etaSc, &b_selLeptons_etaSc);
   fChain->SetBranchAddress("selLeptons_eleExpMissingInnerHits", selLeptons_eleExpMissingInnerHits, &b_selLeptons_eleExpMissingInnerHits);
   fChain->SetBranchAddress("selLeptons_eleooEmooP", selLeptons_eleooEmooP, &b_selLeptons_eleooEmooP);
   fChain->SetBranchAddress("selLeptons_dr03TkSumPt", selLeptons_dr03TkSumPt, &b_selLeptons_dr03TkSumPt);
   fChain->SetBranchAddress("selLeptons_eleEcalClusterIso", selLeptons_eleEcalClusterIso, &b_selLeptons_eleEcalClusterIso);
   fChain->SetBranchAddress("selLeptons_eleHcalClusterIso", selLeptons_eleHcalClusterIso, &b_selLeptons_eleHcalClusterIso);
   fChain->SetBranchAddress("selLeptons_miniIsoCharged", selLeptons_miniIsoCharged, &b_selLeptons_miniIsoCharged);
   fChain->SetBranchAddress("selLeptons_miniIsoNeutral", selLeptons_miniIsoNeutral, &b_selLeptons_miniIsoNeutral);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetPtRel", selLeptons_mvaTTHjetPtRel, &b_selLeptons_mvaTTHjetPtRel);
   fChain->SetBranchAddress("selLeptons_mvaTTHjetNDauChargedMVASel", selLeptons_mvaTTHjetNDauChargedMVASel, &b_selLeptons_mvaTTHjetNDauChargedMVASel);
   fChain->SetBranchAddress("selLeptons_uncalibratedPt", selLeptons_uncalibratedPt, &b_selLeptons_uncalibratedPt);
   fChain->SetBranchAddress("selLeptons_SF_IsoLoose", selLeptons_SF_IsoLoose, &b_selLeptons_SF_IsoLoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IsoLoose", selLeptons_SFerr_IsoLoose, &b_selLeptons_SFerr_IsoLoose);
   fChain->SetBranchAddress("selLeptons_SF_IsoTight", selLeptons_SF_IsoTight, &b_selLeptons_SF_IsoTight);
   fChain->SetBranchAddress("selLeptons_SFerr_IsoTight", selLeptons_SFerr_IsoTight, &b_selLeptons_SFerr_IsoTight);
   fChain->SetBranchAddress("selLeptons_SF_IdCutLoose", selLeptons_SF_IdCutLoose, &b_selLeptons_SF_IdCutLoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IdCutLoose", selLeptons_SFerr_IdCutLoose, &b_selLeptons_SFerr_IdCutLoose);
   fChain->SetBranchAddress("selLeptons_SF_IdCutTight", selLeptons_SF_IdCutTight, &b_selLeptons_SF_IdCutTight);
   fChain->SetBranchAddress("selLeptons_SFerr_IdCutTight", selLeptons_SFerr_IdCutTight, &b_selLeptons_SFerr_IdCutTight);
   fChain->SetBranchAddress("selLeptons_SF_IdMVALoose", selLeptons_SF_IdMVALoose, &b_selLeptons_SF_IdMVALoose);
   fChain->SetBranchAddress("selLeptons_SFerr_IdMVALoose", selLeptons_SFerr_IdMVALoose, &b_selLeptons_SFerr_IdMVALoose);
   fChain->SetBranchAddress("selLeptons_SF_IdMVATight", selLeptons_SF_IdMVATight, &b_selLeptons_SF_IdMVATight);
   fChain->SetBranchAddress("selLeptons_SFerr_IdMVATight", selLeptons_SFerr_IdMVATight, &b_selLeptons_SFerr_IdMVATight);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunD4p3", selLeptons_SF_HLT_RunD4p3, &b_selLeptons_SF_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunD4p3", selLeptons_SFerr_HLT_RunD4p3, &b_selLeptons_SFerr_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunD4p2", selLeptons_SF_HLT_RunD4p2, &b_selLeptons_SF_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunD4p2", selLeptons_SFerr_HLT_RunD4p2, &b_selLeptons_SFerr_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_SF_HLT_RunC", selLeptons_SF_HLT_RunC, &b_selLeptons_SF_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_SFerr_HLT_RunC", selLeptons_SFerr_HLT_RunC, &b_selLeptons_SFerr_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_SF_trk_eta", selLeptons_SF_trk_eta, &b_selLeptons_SF_trk_eta);
   fChain->SetBranchAddress("selLeptons_SFerr_trk_eta", selLeptons_SFerr_trk_eta, &b_selLeptons_SFerr_trk_eta);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunD4p3", selLeptons_Eff_HLT_RunD4p3, &b_selLeptons_Eff_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunD4p3", selLeptons_Efferr_HLT_RunD4p3, &b_selLeptons_Efferr_HLT_RunD4p3);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunD4p2", selLeptons_Eff_HLT_RunD4p2, &b_selLeptons_Eff_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunD4p2", selLeptons_Efferr_HLT_RunD4p2, &b_selLeptons_Efferr_HLT_RunD4p2);
   fChain->SetBranchAddress("selLeptons_Eff_HLT_RunC", selLeptons_Eff_HLT_RunC, &b_selLeptons_Eff_HLT_RunC);
   fChain->SetBranchAddress("selLeptons_Efferr_HLT_RunC", selLeptons_Efferr_HLT_RunC, &b_selLeptons_Efferr_HLT_RunC);
   fChain->SetBranchAddress("ntrgObjects_hltPFMET90", &ntrgObjects_hltPFMET90, &b_ntrgObjects_hltPFMET90);
   fChain->SetBranchAddress("ntrgObjects_hltQuadJet15", &ntrgObjects_hltQuadJet15, &b_ntrgObjects_hltQuadJet15);
   fChain->SetBranchAddress("nTauGood", &nTauGood, &b_nTauGood);
   fChain->SetBranchAddress("TauGood_charge", TauGood_charge, &b_TauGood_charge);
   fChain->SetBranchAddress("TauGood_decayMode", TauGood_decayMode, &b_TauGood_decayMode);
   fChain->SetBranchAddress("TauGood_idDecayMode", TauGood_idDecayMode, &b_TauGood_idDecayMode);
   fChain->SetBranchAddress("TauGood_idDecayModeNewDMs", TauGood_idDecayModeNewDMs, &b_TauGood_idDecayModeNewDMs);
   fChain->SetBranchAddress("TauGood_dxy", TauGood_dxy, &b_TauGood_dxy);
   fChain->SetBranchAddress("TauGood_dz", TauGood_dz, &b_TauGood_dz);
   fChain->SetBranchAddress("TauGood_idMVArun2", TauGood_idMVArun2, &b_TauGood_idMVArun2);
   fChain->SetBranchAddress("TauGood_rawMVArun2", TauGood_rawMVArun2, &b_TauGood_rawMVArun2);
   fChain->SetBranchAddress("TauGood_idMVArun2dR03", TauGood_idMVArun2dR03, &b_TauGood_idMVArun2dR03);
   fChain->SetBranchAddress("TauGood_rawMVArun2dR03", TauGood_rawMVArun2dR03, &b_TauGood_rawMVArun2dR03);
   fChain->SetBranchAddress("TauGood_idMVArun2NewDM", TauGood_idMVArun2NewDM, &b_TauGood_idMVArun2NewDM);
   fChain->SetBranchAddress("TauGood_rawMVArun2NewDM", TauGood_rawMVArun2NewDM, &b_TauGood_rawMVArun2NewDM);
   fChain->SetBranchAddress("TauGood_idCI3hit", TauGood_idCI3hit, &b_TauGood_idCI3hit);
   fChain->SetBranchAddress("TauGood_idAntiMu", TauGood_idAntiMu, &b_TauGood_idAntiMu);
   fChain->SetBranchAddress("TauGood_idAntiErun2", TauGood_idAntiErun2, &b_TauGood_idAntiErun2);
   fChain->SetBranchAddress("TauGood_isoCI3hit", TauGood_isoCI3hit, &b_TauGood_isoCI3hit);
   fChain->SetBranchAddress("TauGood_photonOutsideSigCone", TauGood_photonOutsideSigCone, &b_TauGood_photonOutsideSigCone);
   fChain->SetBranchAddress("TauGood_mcMatchId", TauGood_mcMatchId, &b_TauGood_mcMatchId);
   fChain->SetBranchAddress("TauGood_pdgId", TauGood_pdgId, &b_TauGood_pdgId);
   fChain->SetBranchAddress("TauGood_pt", TauGood_pt, &b_TauGood_pt);
   fChain->SetBranchAddress("TauGood_eta", TauGood_eta, &b_TauGood_eta);
   fChain->SetBranchAddress("TauGood_phi", TauGood_phi, &b_TauGood_phi);
   fChain->SetBranchAddress("TauGood_mass", TauGood_mass, &b_TauGood_mass);
   fChain->SetBranchAddress("TauGood_idxJetMatch", TauGood_idxJetMatch, &b_TauGood_idxJetMatch);
   fChain->SetBranchAddress("TauGood_genMatchType", TauGood_genMatchType, &b_TauGood_genMatchType);
   fChain->SetBranchAddress("nGenStatus2bHad", &nGenStatus2bHad, &b_nGenStatus2bHad);
   fChain->SetBranchAddress("GenStatus2bHad_pdgId", GenStatus2bHad_pdgId, &b_GenStatus2bHad_pdgId);
   fChain->SetBranchAddress("GenStatus2bHad_pt", GenStatus2bHad_pt, &b_GenStatus2bHad_pt);
   fChain->SetBranchAddress("GenStatus2bHad_eta", GenStatus2bHad_eta, &b_GenStatus2bHad_eta);
   fChain->SetBranchAddress("GenStatus2bHad_phi", GenStatus2bHad_phi, &b_GenStatus2bHad_phi);
   fChain->SetBranchAddress("GenStatus2bHad_mass", GenStatus2bHad_mass, &b_GenStatus2bHad_mass);
   fChain->SetBranchAddress("GenStatus2bHad_charge", GenStatus2bHad_charge, &b_GenStatus2bHad_charge);
   fChain->SetBranchAddress("GenStatus2bHad_status", GenStatus2bHad_status, &b_GenStatus2bHad_status);
   fChain->SetBranchAddress("GenStatus2bHad_isPromptHard", GenStatus2bHad_isPromptHard, &b_GenStatus2bHad_isPromptHard);
   fChain->SetBranchAddress("nhJidx", &nhJidx, &b_nhJidx);
   fChain->SetBranchAddress("hJidx", hJidx, &b_hJidx);
   fChain->SetBranchAddress("nGenNuFromTau", &nGenNuFromTau, &b_nGenNuFromTau);
   fChain->SetBranchAddress("GenNuFromTau_pdgId", GenNuFromTau_pdgId, &b_GenNuFromTau_pdgId);
   fChain->SetBranchAddress("GenNuFromTau_pt", GenNuFromTau_pt, &b_GenNuFromTau_pt);
   fChain->SetBranchAddress("GenNuFromTau_eta", GenNuFromTau_eta, &b_GenNuFromTau_eta);
   fChain->SetBranchAddress("GenNuFromTau_phi", GenNuFromTau_phi, &b_GenNuFromTau_phi);
   fChain->SetBranchAddress("GenNuFromTau_mass", GenNuFromTau_mass, &b_GenNuFromTau_mass);
   fChain->SetBranchAddress("GenNuFromTau_charge", GenNuFromTau_charge, &b_GenNuFromTau_charge);
   fChain->SetBranchAddress("GenNuFromTau_status", GenNuFromTau_status, &b_GenNuFromTau_status);
   fChain->SetBranchAddress("GenNuFromTau_isPromptHard", GenNuFromTau_isPromptHard, &b_GenNuFromTau_isPromptHard);
   fChain->SetBranchAddress("nFatjetCA15softdropz2b1", &nFatjetCA15softdropz2b1, &b_nFatjetCA15softdropz2b1);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_pt", FatjetCA15softdropz2b1_pt, &b_FatjetCA15softdropz2b1_pt);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_eta", FatjetCA15softdropz2b1_eta, &b_FatjetCA15softdropz2b1_eta);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_phi", FatjetCA15softdropz2b1_phi, &b_FatjetCA15softdropz2b1_phi);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_mass", FatjetCA15softdropz2b1_mass, &b_FatjetCA15softdropz2b1_mass);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau1", FatjetCA15softdropz2b1_tau1, &b_FatjetCA15softdropz2b1_tau1);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau2", FatjetCA15softdropz2b1_tau2, &b_FatjetCA15softdropz2b1_tau2);
   fChain->SetBranchAddress("FatjetCA15softdropz2b1_tau3", FatjetCA15softdropz2b1_tau3, &b_FatjetCA15softdropz2b1_tau3);
   fChain->SetBranchAddress("nGenGluonFromB", &nGenGluonFromB, &b_nGenGluonFromB);
   fChain->SetBranchAddress("GenGluonFromB_pdgId", GenGluonFromB_pdgId, &b_GenGluonFromB_pdgId);
   fChain->SetBranchAddress("GenGluonFromB_pt", GenGluonFromB_pt, &b_GenGluonFromB_pt);
   fChain->SetBranchAddress("GenGluonFromB_eta", GenGluonFromB_eta, &b_GenGluonFromB_eta);
   fChain->SetBranchAddress("GenGluonFromB_phi", GenGluonFromB_phi, &b_GenGluonFromB_phi);
   fChain->SetBranchAddress("GenGluonFromB_mass", GenGluonFromB_mass, &b_GenGluonFromB_mass);
   fChain->SetBranchAddress("GenGluonFromB_charge", GenGluonFromB_charge, &b_GenGluonFromB_charge);
   fChain->SetBranchAddress("GenGluonFromB_status", GenGluonFromB_status, &b_GenGluonFromB_status);
   fChain->SetBranchAddress("GenGluonFromB_isPromptHard", GenGluonFromB_isPromptHard, &b_GenGluonFromB_isPromptHard);
   fChain->SetBranchAddress("ntrgObjects_hltTripleJet50", &ntrgObjects_hltTripleJet50, &b_ntrgObjects_hltTripleJet50);
   fChain->SetBranchAddress("ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1", &ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1, &b_ntrgObjects_hltVBFPFJetCSVSortedMqq460Detaqq4p1);
   fChain->SetBranchAddress("nhttCandidates", &nhttCandidates, &b_nhttCandidates);
   fChain->SetBranchAddress("httCandidates_pt", httCandidates_pt, &b_httCandidates_pt);
   fChain->SetBranchAddress("httCandidates_eta", httCandidates_eta, &b_httCandidates_eta);
   fChain->SetBranchAddress("httCandidates_phi", httCandidates_phi, &b_httCandidates_phi);
   fChain->SetBranchAddress("httCandidates_mass", httCandidates_mass, &b_httCandidates_mass);
   fChain->SetBranchAddress("httCandidates_ptcal", httCandidates_ptcal, &b_httCandidates_ptcal);
   fChain->SetBranchAddress("httCandidates_etacal", httCandidates_etacal, &b_httCandidates_etacal);
   fChain->SetBranchAddress("httCandidates_phical", httCandidates_phical, &b_httCandidates_phical);
   fChain->SetBranchAddress("httCandidates_masscal", httCandidates_masscal, &b_httCandidates_masscal);
   fChain->SetBranchAddress("httCandidates_fRec", httCandidates_fRec, &b_httCandidates_fRec);
   fChain->SetBranchAddress("httCandidates_Ropt", httCandidates_Ropt, &b_httCandidates_Ropt);
   fChain->SetBranchAddress("httCandidates_RoptCalc", httCandidates_RoptCalc, &b_httCandidates_RoptCalc);
   fChain->SetBranchAddress("httCandidates_ptForRoptCalc", httCandidates_ptForRoptCalc, &b_httCandidates_ptForRoptCalc);
   fChain->SetBranchAddress("httCandidates_subjetIDPassed", httCandidates_subjetIDPassed, &b_httCandidates_subjetIDPassed);
   fChain->SetBranchAddress("httCandidates_sjW1ptcal", httCandidates_sjW1ptcal, &b_httCandidates_sjW1ptcal);
   fChain->SetBranchAddress("httCandidates_sjW1pt", httCandidates_sjW1pt, &b_httCandidates_sjW1pt);
   fChain->SetBranchAddress("httCandidates_sjW1eta", httCandidates_sjW1eta, &b_httCandidates_sjW1eta);
   fChain->SetBranchAddress("httCandidates_sjW1phi", httCandidates_sjW1phi, &b_httCandidates_sjW1phi);
   fChain->SetBranchAddress("httCandidates_sjW1masscal", httCandidates_sjW1masscal, &b_httCandidates_sjW1masscal);
   fChain->SetBranchAddress("httCandidates_sjW1mass", httCandidates_sjW1mass, &b_httCandidates_sjW1mass);
   fChain->SetBranchAddress("httCandidates_sjW1btag", httCandidates_sjW1btag, &b_httCandidates_sjW1btag);
   fChain->SetBranchAddress("httCandidates_sjW1corr", httCandidates_sjW1corr, &b_httCandidates_sjW1corr);
   fChain->SetBranchAddress("httCandidates_sjW2ptcal", httCandidates_sjW2ptcal, &b_httCandidates_sjW2ptcal);
   fChain->SetBranchAddress("httCandidates_sjW2pt", httCandidates_sjW2pt, &b_httCandidates_sjW2pt);
   fChain->SetBranchAddress("httCandidates_sjW2eta", httCandidates_sjW2eta, &b_httCandidates_sjW2eta);
   fChain->SetBranchAddress("httCandidates_sjW2phi", httCandidates_sjW2phi, &b_httCandidates_sjW2phi);
   fChain->SetBranchAddress("httCandidates_sjW2masscal", httCandidates_sjW2masscal, &b_httCandidates_sjW2masscal);
   fChain->SetBranchAddress("httCandidates_sjW2mass", httCandidates_sjW2mass, &b_httCandidates_sjW2mass);
   fChain->SetBranchAddress("httCandidates_sjW2btag", httCandidates_sjW2btag, &b_httCandidates_sjW2btag);
   fChain->SetBranchAddress("httCandidates_sjW2corr", httCandidates_sjW2corr, &b_httCandidates_sjW2corr);
   fChain->SetBranchAddress("httCandidates_sjNonWptcal", httCandidates_sjNonWptcal, &b_httCandidates_sjNonWptcal);
   fChain->SetBranchAddress("httCandidates_sjNonWpt", httCandidates_sjNonWpt, &b_httCandidates_sjNonWpt);
   fChain->SetBranchAddress("httCandidates_sjNonWeta", httCandidates_sjNonWeta, &b_httCandidates_sjNonWeta);
   fChain->SetBranchAddress("httCandidates_sjNonWphi", httCandidates_sjNonWphi, &b_httCandidates_sjNonWphi);
   fChain->SetBranchAddress("httCandidates_sjNonWmasscal", httCandidates_sjNonWmasscal, &b_httCandidates_sjNonWmasscal);
   fChain->SetBranchAddress("httCandidates_sjNonWmass", httCandidates_sjNonWmass, &b_httCandidates_sjNonWmass);
   fChain->SetBranchAddress("httCandidates_sjNonWbtag", httCandidates_sjNonWbtag, &b_httCandidates_sjNonWbtag);
   fChain->SetBranchAddress("httCandidates_sjNonWcorr", httCandidates_sjNonWcorr, &b_httCandidates_sjNonWcorr);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteStatUp", httCandidates_sjW1_corr_AbsoluteStatUp, &b_httCandidates_sjW1_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteStatDown", httCandidates_sjW1_corr_AbsoluteStatDown, &b_httCandidates_sjW1_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteScaleUp", httCandidates_sjW1_corr_AbsoluteScaleUp, &b_httCandidates_sjW1_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteScaleDown", httCandidates_sjW1_corr_AbsoluteScaleDown, &b_httCandidates_sjW1_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteFlavMapUp", httCandidates_sjW1_corr_AbsoluteFlavMapUp, &b_httCandidates_sjW1_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteFlavMapDown", httCandidates_sjW1_corr_AbsoluteFlavMapDown, &b_httCandidates_sjW1_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteMPFBiasUp", httCandidates_sjW1_corr_AbsoluteMPFBiasUp, &b_httCandidates_sjW1_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_AbsoluteMPFBiasDown", httCandidates_sjW1_corr_AbsoluteMPFBiasDown, &b_httCandidates_sjW1_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FragmentationUp", httCandidates_sjW1_corr_FragmentationUp, &b_httCandidates_sjW1_corr_FragmentationUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FragmentationDown", httCandidates_sjW1_corr_FragmentationDown, &b_httCandidates_sjW1_corr_FragmentationDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SinglePionECALUp", httCandidates_sjW1_corr_SinglePionECALUp, &b_httCandidates_sjW1_corr_SinglePionECALUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SinglePionECALDown", httCandidates_sjW1_corr_SinglePionECALDown, &b_httCandidates_sjW1_corr_SinglePionECALDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SinglePionHCALUp", httCandidates_sjW1_corr_SinglePionHCALUp, &b_httCandidates_sjW1_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SinglePionHCALDown", httCandidates_sjW1_corr_SinglePionHCALDown, &b_httCandidates_sjW1_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorQCDUp", httCandidates_sjW1_corr_FlavorQCDUp, &b_httCandidates_sjW1_corr_FlavorQCDUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorQCDDown", httCandidates_sjW1_corr_FlavorQCDDown, &b_httCandidates_sjW1_corr_FlavorQCDDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimePtEtaUp", httCandidates_sjW1_corr_TimePtEtaUp, &b_httCandidates_sjW1_corr_TimePtEtaUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimePtEtaDown", httCandidates_sjW1_corr_TimePtEtaDown, &b_httCandidates_sjW1_corr_TimePtEtaDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJEREC1Up", httCandidates_sjW1_corr_RelativeJEREC1Up, &b_httCandidates_sjW1_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJEREC1Down", httCandidates_sjW1_corr_RelativeJEREC1Down, &b_httCandidates_sjW1_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJEREC2Up", httCandidates_sjW1_corr_RelativeJEREC2Up, &b_httCandidates_sjW1_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJEREC2Down", httCandidates_sjW1_corr_RelativeJEREC2Down, &b_httCandidates_sjW1_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJERHFUp", httCandidates_sjW1_corr_RelativeJERHFUp, &b_httCandidates_sjW1_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeJERHFDown", httCandidates_sjW1_corr_RelativeJERHFDown, &b_httCandidates_sjW1_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtBBUp", httCandidates_sjW1_corr_RelativePtBBUp, &b_httCandidates_sjW1_corr_RelativePtBBUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtBBDown", httCandidates_sjW1_corr_RelativePtBBDown, &b_httCandidates_sjW1_corr_RelativePtBBDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtEC1Up", httCandidates_sjW1_corr_RelativePtEC1Up, &b_httCandidates_sjW1_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtEC1Down", httCandidates_sjW1_corr_RelativePtEC1Down, &b_httCandidates_sjW1_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtEC2Up", httCandidates_sjW1_corr_RelativePtEC2Up, &b_httCandidates_sjW1_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtEC2Down", httCandidates_sjW1_corr_RelativePtEC2Down, &b_httCandidates_sjW1_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtHFUp", httCandidates_sjW1_corr_RelativePtHFUp, &b_httCandidates_sjW1_corr_RelativePtHFUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativePtHFDown", httCandidates_sjW1_corr_RelativePtHFDown, &b_httCandidates_sjW1_corr_RelativePtHFDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeBalUp", httCandidates_sjW1_corr_RelativeBalUp, &b_httCandidates_sjW1_corr_RelativeBalUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeBalDown", httCandidates_sjW1_corr_RelativeBalDown, &b_httCandidates_sjW1_corr_RelativeBalDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeFSRUp", httCandidates_sjW1_corr_RelativeFSRUp, &b_httCandidates_sjW1_corr_RelativeFSRUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeFSRDown", httCandidates_sjW1_corr_RelativeFSRDown, &b_httCandidates_sjW1_corr_RelativeFSRDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatFSRUp", httCandidates_sjW1_corr_RelativeStatFSRUp, &b_httCandidates_sjW1_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatFSRDown", httCandidates_sjW1_corr_RelativeStatFSRDown, &b_httCandidates_sjW1_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatECUp", httCandidates_sjW1_corr_RelativeStatECUp, &b_httCandidates_sjW1_corr_RelativeStatECUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatECDown", httCandidates_sjW1_corr_RelativeStatECDown, &b_httCandidates_sjW1_corr_RelativeStatECDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatHFUp", httCandidates_sjW1_corr_RelativeStatHFUp, &b_httCandidates_sjW1_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_RelativeStatHFDown", httCandidates_sjW1_corr_RelativeStatHFDown, &b_httCandidates_sjW1_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpDataMCUp", httCandidates_sjW1_corr_PileUpDataMCUp, &b_httCandidates_sjW1_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpDataMCDown", httCandidates_sjW1_corr_PileUpDataMCDown, &b_httCandidates_sjW1_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtRefUp", httCandidates_sjW1_corr_PileUpPtRefUp, &b_httCandidates_sjW1_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtRefDown", httCandidates_sjW1_corr_PileUpPtRefDown, &b_httCandidates_sjW1_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtBBUp", httCandidates_sjW1_corr_PileUpPtBBUp, &b_httCandidates_sjW1_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtBBDown", httCandidates_sjW1_corr_PileUpPtBBDown, &b_httCandidates_sjW1_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtEC1Up", httCandidates_sjW1_corr_PileUpPtEC1Up, &b_httCandidates_sjW1_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtEC1Down", httCandidates_sjW1_corr_PileUpPtEC1Down, &b_httCandidates_sjW1_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtEC2Up", httCandidates_sjW1_corr_PileUpPtEC2Up, &b_httCandidates_sjW1_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtEC2Down", httCandidates_sjW1_corr_PileUpPtEC2Down, &b_httCandidates_sjW1_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtHFUp", httCandidates_sjW1_corr_PileUpPtHFUp, &b_httCandidates_sjW1_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpPtHFDown", httCandidates_sjW1_corr_PileUpPtHFDown, &b_httCandidates_sjW1_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpMuZeroUp", httCandidates_sjW1_corr_PileUpMuZeroUp, &b_httCandidates_sjW1_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpMuZeroDown", httCandidates_sjW1_corr_PileUpMuZeroDown, &b_httCandidates_sjW1_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpEnvelopeUp", httCandidates_sjW1_corr_PileUpEnvelopeUp, &b_httCandidates_sjW1_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_PileUpEnvelopeDown", httCandidates_sjW1_corr_PileUpEnvelopeDown, &b_httCandidates_sjW1_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalPileUpUp", httCandidates_sjW1_corr_SubTotalPileUpUp, &b_httCandidates_sjW1_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalPileUpDown", httCandidates_sjW1_corr_SubTotalPileUpDown, &b_httCandidates_sjW1_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalRelativeUp", httCandidates_sjW1_corr_SubTotalRelativeUp, &b_httCandidates_sjW1_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalRelativeDown", httCandidates_sjW1_corr_SubTotalRelativeDown, &b_httCandidates_sjW1_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalPtUp", httCandidates_sjW1_corr_SubTotalPtUp, &b_httCandidates_sjW1_corr_SubTotalPtUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalPtDown", httCandidates_sjW1_corr_SubTotalPtDown, &b_httCandidates_sjW1_corr_SubTotalPtDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalScaleUp", httCandidates_sjW1_corr_SubTotalScaleUp, &b_httCandidates_sjW1_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalScaleDown", httCandidates_sjW1_corr_SubTotalScaleDown, &b_httCandidates_sjW1_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalAbsoluteUp", httCandidates_sjW1_corr_SubTotalAbsoluteUp, &b_httCandidates_sjW1_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalAbsoluteDown", httCandidates_sjW1_corr_SubTotalAbsoluteDown, &b_httCandidates_sjW1_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalMCUp", httCandidates_sjW1_corr_SubTotalMCUp, &b_httCandidates_sjW1_corr_SubTotalMCUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_SubTotalMCDown", httCandidates_sjW1_corr_SubTotalMCDown, &b_httCandidates_sjW1_corr_SubTotalMCDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalUp", httCandidates_sjW1_corr_TotalUp, &b_httCandidates_sjW1_corr_TotalUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalDown", httCandidates_sjW1_corr_TotalDown, &b_httCandidates_sjW1_corr_TotalDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoFlavorUp", httCandidates_sjW1_corr_TotalNoFlavorUp, &b_httCandidates_sjW1_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoFlavorDown", httCandidates_sjW1_corr_TotalNoFlavorDown, &b_httCandidates_sjW1_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoTimeUp", httCandidates_sjW1_corr_TotalNoTimeUp, &b_httCandidates_sjW1_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoTimeDown", httCandidates_sjW1_corr_TotalNoTimeDown, &b_httCandidates_sjW1_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoFlavorNoTimeUp", httCandidates_sjW1_corr_TotalNoFlavorNoTimeUp, &b_httCandidates_sjW1_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TotalNoFlavorNoTimeDown", httCandidates_sjW1_corr_TotalNoFlavorNoTimeDown, &b_httCandidates_sjW1_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorZJetUp", httCandidates_sjW1_corr_FlavorZJetUp, &b_httCandidates_sjW1_corr_FlavorZJetUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorZJetDown", httCandidates_sjW1_corr_FlavorZJetDown, &b_httCandidates_sjW1_corr_FlavorZJetDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPhotonJetUp", httCandidates_sjW1_corr_FlavorPhotonJetUp, &b_httCandidates_sjW1_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPhotonJetDown", httCandidates_sjW1_corr_FlavorPhotonJetDown, &b_httCandidates_sjW1_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureGluonUp", httCandidates_sjW1_corr_FlavorPureGluonUp, &b_httCandidates_sjW1_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureGluonDown", httCandidates_sjW1_corr_FlavorPureGluonDown, &b_httCandidates_sjW1_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureQuarkUp", httCandidates_sjW1_corr_FlavorPureQuarkUp, &b_httCandidates_sjW1_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureQuarkDown", httCandidates_sjW1_corr_FlavorPureQuarkDown, &b_httCandidates_sjW1_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureCharmUp", httCandidates_sjW1_corr_FlavorPureCharmUp, &b_httCandidates_sjW1_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureCharmDown", httCandidates_sjW1_corr_FlavorPureCharmDown, &b_httCandidates_sjW1_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureBottomUp", httCandidates_sjW1_corr_FlavorPureBottomUp, &b_httCandidates_sjW1_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_FlavorPureBottomDown", httCandidates_sjW1_corr_FlavorPureBottomDown, &b_httCandidates_sjW1_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunBCDUp", httCandidates_sjW1_corr_TimeRunBCDUp, &b_httCandidates_sjW1_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunBCDDown", httCandidates_sjW1_corr_TimeRunBCDDown, &b_httCandidates_sjW1_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunEFUp", httCandidates_sjW1_corr_TimeRunEFUp, &b_httCandidates_sjW1_corr_TimeRunEFUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunEFDown", httCandidates_sjW1_corr_TimeRunEFDown, &b_httCandidates_sjW1_corr_TimeRunEFDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunGUp", httCandidates_sjW1_corr_TimeRunGUp, &b_httCandidates_sjW1_corr_TimeRunGUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunGDown", httCandidates_sjW1_corr_TimeRunGDown, &b_httCandidates_sjW1_corr_TimeRunGDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunHUp", httCandidates_sjW1_corr_TimeRunHUp, &b_httCandidates_sjW1_corr_TimeRunHUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_TimeRunHDown", httCandidates_sjW1_corr_TimeRunHDown, &b_httCandidates_sjW1_corr_TimeRunHDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupMPFInSituUp", httCandidates_sjW1_corr_CorrelationGroupMPFInSituUp, &b_httCandidates_sjW1_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupMPFInSituDown", httCandidates_sjW1_corr_CorrelationGroupMPFInSituDown, &b_httCandidates_sjW1_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupIntercalibrationUp", httCandidates_sjW1_corr_CorrelationGroupIntercalibrationUp, &b_httCandidates_sjW1_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupIntercalibrationDown", httCandidates_sjW1_corr_CorrelationGroupIntercalibrationDown, &b_httCandidates_sjW1_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupbJESUp", httCandidates_sjW1_corr_CorrelationGroupbJESUp, &b_httCandidates_sjW1_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupbJESDown", httCandidates_sjW1_corr_CorrelationGroupbJESDown, &b_httCandidates_sjW1_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupFlavorUp", httCandidates_sjW1_corr_CorrelationGroupFlavorUp, &b_httCandidates_sjW1_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupFlavorDown", httCandidates_sjW1_corr_CorrelationGroupFlavorDown, &b_httCandidates_sjW1_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupUncorrelatedUp", httCandidates_sjW1_corr_CorrelationGroupUncorrelatedUp, &b_httCandidates_sjW1_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("httCandidates_sjW1_corr_CorrelationGroupUncorrelatedDown", httCandidates_sjW1_corr_CorrelationGroupUncorrelatedDown, &b_httCandidates_sjW1_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteStatUp", httCandidates_sjW2_corr_AbsoluteStatUp, &b_httCandidates_sjW2_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteStatDown", httCandidates_sjW2_corr_AbsoluteStatDown, &b_httCandidates_sjW2_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteScaleUp", httCandidates_sjW2_corr_AbsoluteScaleUp, &b_httCandidates_sjW2_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteScaleDown", httCandidates_sjW2_corr_AbsoluteScaleDown, &b_httCandidates_sjW2_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteFlavMapUp", httCandidates_sjW2_corr_AbsoluteFlavMapUp, &b_httCandidates_sjW2_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteFlavMapDown", httCandidates_sjW2_corr_AbsoluteFlavMapDown, &b_httCandidates_sjW2_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteMPFBiasUp", httCandidates_sjW2_corr_AbsoluteMPFBiasUp, &b_httCandidates_sjW2_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_AbsoluteMPFBiasDown", httCandidates_sjW2_corr_AbsoluteMPFBiasDown, &b_httCandidates_sjW2_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FragmentationUp", httCandidates_sjW2_corr_FragmentationUp, &b_httCandidates_sjW2_corr_FragmentationUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FragmentationDown", httCandidates_sjW2_corr_FragmentationDown, &b_httCandidates_sjW2_corr_FragmentationDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SinglePionECALUp", httCandidates_sjW2_corr_SinglePionECALUp, &b_httCandidates_sjW2_corr_SinglePionECALUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SinglePionECALDown", httCandidates_sjW2_corr_SinglePionECALDown, &b_httCandidates_sjW2_corr_SinglePionECALDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SinglePionHCALUp", httCandidates_sjW2_corr_SinglePionHCALUp, &b_httCandidates_sjW2_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SinglePionHCALDown", httCandidates_sjW2_corr_SinglePionHCALDown, &b_httCandidates_sjW2_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorQCDUp", httCandidates_sjW2_corr_FlavorQCDUp, &b_httCandidates_sjW2_corr_FlavorQCDUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorQCDDown", httCandidates_sjW2_corr_FlavorQCDDown, &b_httCandidates_sjW2_corr_FlavorQCDDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimePtEtaUp", httCandidates_sjW2_corr_TimePtEtaUp, &b_httCandidates_sjW2_corr_TimePtEtaUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimePtEtaDown", httCandidates_sjW2_corr_TimePtEtaDown, &b_httCandidates_sjW2_corr_TimePtEtaDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJEREC1Up", httCandidates_sjW2_corr_RelativeJEREC1Up, &b_httCandidates_sjW2_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJEREC1Down", httCandidates_sjW2_corr_RelativeJEREC1Down, &b_httCandidates_sjW2_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJEREC2Up", httCandidates_sjW2_corr_RelativeJEREC2Up, &b_httCandidates_sjW2_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJEREC2Down", httCandidates_sjW2_corr_RelativeJEREC2Down, &b_httCandidates_sjW2_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJERHFUp", httCandidates_sjW2_corr_RelativeJERHFUp, &b_httCandidates_sjW2_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeJERHFDown", httCandidates_sjW2_corr_RelativeJERHFDown, &b_httCandidates_sjW2_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtBBUp", httCandidates_sjW2_corr_RelativePtBBUp, &b_httCandidates_sjW2_corr_RelativePtBBUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtBBDown", httCandidates_sjW2_corr_RelativePtBBDown, &b_httCandidates_sjW2_corr_RelativePtBBDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtEC1Up", httCandidates_sjW2_corr_RelativePtEC1Up, &b_httCandidates_sjW2_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtEC1Down", httCandidates_sjW2_corr_RelativePtEC1Down, &b_httCandidates_sjW2_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtEC2Up", httCandidates_sjW2_corr_RelativePtEC2Up, &b_httCandidates_sjW2_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtEC2Down", httCandidates_sjW2_corr_RelativePtEC2Down, &b_httCandidates_sjW2_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtHFUp", httCandidates_sjW2_corr_RelativePtHFUp, &b_httCandidates_sjW2_corr_RelativePtHFUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativePtHFDown", httCandidates_sjW2_corr_RelativePtHFDown, &b_httCandidates_sjW2_corr_RelativePtHFDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeBalUp", httCandidates_sjW2_corr_RelativeBalUp, &b_httCandidates_sjW2_corr_RelativeBalUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeBalDown", httCandidates_sjW2_corr_RelativeBalDown, &b_httCandidates_sjW2_corr_RelativeBalDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeFSRUp", httCandidates_sjW2_corr_RelativeFSRUp, &b_httCandidates_sjW2_corr_RelativeFSRUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeFSRDown", httCandidates_sjW2_corr_RelativeFSRDown, &b_httCandidates_sjW2_corr_RelativeFSRDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatFSRUp", httCandidates_sjW2_corr_RelativeStatFSRUp, &b_httCandidates_sjW2_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatFSRDown", httCandidates_sjW2_corr_RelativeStatFSRDown, &b_httCandidates_sjW2_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatECUp", httCandidates_sjW2_corr_RelativeStatECUp, &b_httCandidates_sjW2_corr_RelativeStatECUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatECDown", httCandidates_sjW2_corr_RelativeStatECDown, &b_httCandidates_sjW2_corr_RelativeStatECDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatHFUp", httCandidates_sjW2_corr_RelativeStatHFUp, &b_httCandidates_sjW2_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_RelativeStatHFDown", httCandidates_sjW2_corr_RelativeStatHFDown, &b_httCandidates_sjW2_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpDataMCUp", httCandidates_sjW2_corr_PileUpDataMCUp, &b_httCandidates_sjW2_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpDataMCDown", httCandidates_sjW2_corr_PileUpDataMCDown, &b_httCandidates_sjW2_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtRefUp", httCandidates_sjW2_corr_PileUpPtRefUp, &b_httCandidates_sjW2_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtRefDown", httCandidates_sjW2_corr_PileUpPtRefDown, &b_httCandidates_sjW2_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtBBUp", httCandidates_sjW2_corr_PileUpPtBBUp, &b_httCandidates_sjW2_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtBBDown", httCandidates_sjW2_corr_PileUpPtBBDown, &b_httCandidates_sjW2_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtEC1Up", httCandidates_sjW2_corr_PileUpPtEC1Up, &b_httCandidates_sjW2_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtEC1Down", httCandidates_sjW2_corr_PileUpPtEC1Down, &b_httCandidates_sjW2_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtEC2Up", httCandidates_sjW2_corr_PileUpPtEC2Up, &b_httCandidates_sjW2_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtEC2Down", httCandidates_sjW2_corr_PileUpPtEC2Down, &b_httCandidates_sjW2_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtHFUp", httCandidates_sjW2_corr_PileUpPtHFUp, &b_httCandidates_sjW2_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpPtHFDown", httCandidates_sjW2_corr_PileUpPtHFDown, &b_httCandidates_sjW2_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpMuZeroUp", httCandidates_sjW2_corr_PileUpMuZeroUp, &b_httCandidates_sjW2_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpMuZeroDown", httCandidates_sjW2_corr_PileUpMuZeroDown, &b_httCandidates_sjW2_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpEnvelopeUp", httCandidates_sjW2_corr_PileUpEnvelopeUp, &b_httCandidates_sjW2_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_PileUpEnvelopeDown", httCandidates_sjW2_corr_PileUpEnvelopeDown, &b_httCandidates_sjW2_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalPileUpUp", httCandidates_sjW2_corr_SubTotalPileUpUp, &b_httCandidates_sjW2_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalPileUpDown", httCandidates_sjW2_corr_SubTotalPileUpDown, &b_httCandidates_sjW2_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalRelativeUp", httCandidates_sjW2_corr_SubTotalRelativeUp, &b_httCandidates_sjW2_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalRelativeDown", httCandidates_sjW2_corr_SubTotalRelativeDown, &b_httCandidates_sjW2_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalPtUp", httCandidates_sjW2_corr_SubTotalPtUp, &b_httCandidates_sjW2_corr_SubTotalPtUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalPtDown", httCandidates_sjW2_corr_SubTotalPtDown, &b_httCandidates_sjW2_corr_SubTotalPtDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalScaleUp", httCandidates_sjW2_corr_SubTotalScaleUp, &b_httCandidates_sjW2_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalScaleDown", httCandidates_sjW2_corr_SubTotalScaleDown, &b_httCandidates_sjW2_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalAbsoluteUp", httCandidates_sjW2_corr_SubTotalAbsoluteUp, &b_httCandidates_sjW2_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalAbsoluteDown", httCandidates_sjW2_corr_SubTotalAbsoluteDown, &b_httCandidates_sjW2_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalMCUp", httCandidates_sjW2_corr_SubTotalMCUp, &b_httCandidates_sjW2_corr_SubTotalMCUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_SubTotalMCDown", httCandidates_sjW2_corr_SubTotalMCDown, &b_httCandidates_sjW2_corr_SubTotalMCDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalUp", httCandidates_sjW2_corr_TotalUp, &b_httCandidates_sjW2_corr_TotalUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalDown", httCandidates_sjW2_corr_TotalDown, &b_httCandidates_sjW2_corr_TotalDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoFlavorUp", httCandidates_sjW2_corr_TotalNoFlavorUp, &b_httCandidates_sjW2_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoFlavorDown", httCandidates_sjW2_corr_TotalNoFlavorDown, &b_httCandidates_sjW2_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoTimeUp", httCandidates_sjW2_corr_TotalNoTimeUp, &b_httCandidates_sjW2_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoTimeDown", httCandidates_sjW2_corr_TotalNoTimeDown, &b_httCandidates_sjW2_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoFlavorNoTimeUp", httCandidates_sjW2_corr_TotalNoFlavorNoTimeUp, &b_httCandidates_sjW2_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TotalNoFlavorNoTimeDown", httCandidates_sjW2_corr_TotalNoFlavorNoTimeDown, &b_httCandidates_sjW2_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorZJetUp", httCandidates_sjW2_corr_FlavorZJetUp, &b_httCandidates_sjW2_corr_FlavorZJetUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorZJetDown", httCandidates_sjW2_corr_FlavorZJetDown, &b_httCandidates_sjW2_corr_FlavorZJetDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPhotonJetUp", httCandidates_sjW2_corr_FlavorPhotonJetUp, &b_httCandidates_sjW2_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPhotonJetDown", httCandidates_sjW2_corr_FlavorPhotonJetDown, &b_httCandidates_sjW2_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureGluonUp", httCandidates_sjW2_corr_FlavorPureGluonUp, &b_httCandidates_sjW2_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureGluonDown", httCandidates_sjW2_corr_FlavorPureGluonDown, &b_httCandidates_sjW2_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureQuarkUp", httCandidates_sjW2_corr_FlavorPureQuarkUp, &b_httCandidates_sjW2_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureQuarkDown", httCandidates_sjW2_corr_FlavorPureQuarkDown, &b_httCandidates_sjW2_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureCharmUp", httCandidates_sjW2_corr_FlavorPureCharmUp, &b_httCandidates_sjW2_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureCharmDown", httCandidates_sjW2_corr_FlavorPureCharmDown, &b_httCandidates_sjW2_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureBottomUp", httCandidates_sjW2_corr_FlavorPureBottomUp, &b_httCandidates_sjW2_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_FlavorPureBottomDown", httCandidates_sjW2_corr_FlavorPureBottomDown, &b_httCandidates_sjW2_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunBCDUp", httCandidates_sjW2_corr_TimeRunBCDUp, &b_httCandidates_sjW2_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunBCDDown", httCandidates_sjW2_corr_TimeRunBCDDown, &b_httCandidates_sjW2_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunEFUp", httCandidates_sjW2_corr_TimeRunEFUp, &b_httCandidates_sjW2_corr_TimeRunEFUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunEFDown", httCandidates_sjW2_corr_TimeRunEFDown, &b_httCandidates_sjW2_corr_TimeRunEFDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunGUp", httCandidates_sjW2_corr_TimeRunGUp, &b_httCandidates_sjW2_corr_TimeRunGUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunGDown", httCandidates_sjW2_corr_TimeRunGDown, &b_httCandidates_sjW2_corr_TimeRunGDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunHUp", httCandidates_sjW2_corr_TimeRunHUp, &b_httCandidates_sjW2_corr_TimeRunHUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_TimeRunHDown", httCandidates_sjW2_corr_TimeRunHDown, &b_httCandidates_sjW2_corr_TimeRunHDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupMPFInSituUp", httCandidates_sjW2_corr_CorrelationGroupMPFInSituUp, &b_httCandidates_sjW2_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupMPFInSituDown", httCandidates_sjW2_corr_CorrelationGroupMPFInSituDown, &b_httCandidates_sjW2_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupIntercalibrationUp", httCandidates_sjW2_corr_CorrelationGroupIntercalibrationUp, &b_httCandidates_sjW2_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupIntercalibrationDown", httCandidates_sjW2_corr_CorrelationGroupIntercalibrationDown, &b_httCandidates_sjW2_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupbJESUp", httCandidates_sjW2_corr_CorrelationGroupbJESUp, &b_httCandidates_sjW2_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupbJESDown", httCandidates_sjW2_corr_CorrelationGroupbJESDown, &b_httCandidates_sjW2_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupFlavorUp", httCandidates_sjW2_corr_CorrelationGroupFlavorUp, &b_httCandidates_sjW2_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupFlavorDown", httCandidates_sjW2_corr_CorrelationGroupFlavorDown, &b_httCandidates_sjW2_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupUncorrelatedUp", httCandidates_sjW2_corr_CorrelationGroupUncorrelatedUp, &b_httCandidates_sjW2_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("httCandidates_sjW2_corr_CorrelationGroupUncorrelatedDown", httCandidates_sjW2_corr_CorrelationGroupUncorrelatedDown, &b_httCandidates_sjW2_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteStatUp", httCandidates_sjNonW_corr_AbsoluteStatUp, &b_httCandidates_sjNonW_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteStatDown", httCandidates_sjNonW_corr_AbsoluteStatDown, &b_httCandidates_sjNonW_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteScaleUp", httCandidates_sjNonW_corr_AbsoluteScaleUp, &b_httCandidates_sjNonW_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteScaleDown", httCandidates_sjNonW_corr_AbsoluteScaleDown, &b_httCandidates_sjNonW_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteFlavMapUp", httCandidates_sjNonW_corr_AbsoluteFlavMapUp, &b_httCandidates_sjNonW_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteFlavMapDown", httCandidates_sjNonW_corr_AbsoluteFlavMapDown, &b_httCandidates_sjNonW_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteMPFBiasUp", httCandidates_sjNonW_corr_AbsoluteMPFBiasUp, &b_httCandidates_sjNonW_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_AbsoluteMPFBiasDown", httCandidates_sjNonW_corr_AbsoluteMPFBiasDown, &b_httCandidates_sjNonW_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FragmentationUp", httCandidates_sjNonW_corr_FragmentationUp, &b_httCandidates_sjNonW_corr_FragmentationUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FragmentationDown", httCandidates_sjNonW_corr_FragmentationDown, &b_httCandidates_sjNonW_corr_FragmentationDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SinglePionECALUp", httCandidates_sjNonW_corr_SinglePionECALUp, &b_httCandidates_sjNonW_corr_SinglePionECALUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SinglePionECALDown", httCandidates_sjNonW_corr_SinglePionECALDown, &b_httCandidates_sjNonW_corr_SinglePionECALDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SinglePionHCALUp", httCandidates_sjNonW_corr_SinglePionHCALUp, &b_httCandidates_sjNonW_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SinglePionHCALDown", httCandidates_sjNonW_corr_SinglePionHCALDown, &b_httCandidates_sjNonW_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorQCDUp", httCandidates_sjNonW_corr_FlavorQCDUp, &b_httCandidates_sjNonW_corr_FlavorQCDUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorQCDDown", httCandidates_sjNonW_corr_FlavorQCDDown, &b_httCandidates_sjNonW_corr_FlavorQCDDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimePtEtaUp", httCandidates_sjNonW_corr_TimePtEtaUp, &b_httCandidates_sjNonW_corr_TimePtEtaUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimePtEtaDown", httCandidates_sjNonW_corr_TimePtEtaDown, &b_httCandidates_sjNonW_corr_TimePtEtaDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJEREC1Up", httCandidates_sjNonW_corr_RelativeJEREC1Up, &b_httCandidates_sjNonW_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJEREC1Down", httCandidates_sjNonW_corr_RelativeJEREC1Down, &b_httCandidates_sjNonW_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJEREC2Up", httCandidates_sjNonW_corr_RelativeJEREC2Up, &b_httCandidates_sjNonW_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJEREC2Down", httCandidates_sjNonW_corr_RelativeJEREC2Down, &b_httCandidates_sjNonW_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJERHFUp", httCandidates_sjNonW_corr_RelativeJERHFUp, &b_httCandidates_sjNonW_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeJERHFDown", httCandidates_sjNonW_corr_RelativeJERHFDown, &b_httCandidates_sjNonW_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtBBUp", httCandidates_sjNonW_corr_RelativePtBBUp, &b_httCandidates_sjNonW_corr_RelativePtBBUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtBBDown", httCandidates_sjNonW_corr_RelativePtBBDown, &b_httCandidates_sjNonW_corr_RelativePtBBDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtEC1Up", httCandidates_sjNonW_corr_RelativePtEC1Up, &b_httCandidates_sjNonW_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtEC1Down", httCandidates_sjNonW_corr_RelativePtEC1Down, &b_httCandidates_sjNonW_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtEC2Up", httCandidates_sjNonW_corr_RelativePtEC2Up, &b_httCandidates_sjNonW_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtEC2Down", httCandidates_sjNonW_corr_RelativePtEC2Down, &b_httCandidates_sjNonW_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtHFUp", httCandidates_sjNonW_corr_RelativePtHFUp, &b_httCandidates_sjNonW_corr_RelativePtHFUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativePtHFDown", httCandidates_sjNonW_corr_RelativePtHFDown, &b_httCandidates_sjNonW_corr_RelativePtHFDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeBalUp", httCandidates_sjNonW_corr_RelativeBalUp, &b_httCandidates_sjNonW_corr_RelativeBalUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeBalDown", httCandidates_sjNonW_corr_RelativeBalDown, &b_httCandidates_sjNonW_corr_RelativeBalDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeFSRUp", httCandidates_sjNonW_corr_RelativeFSRUp, &b_httCandidates_sjNonW_corr_RelativeFSRUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeFSRDown", httCandidates_sjNonW_corr_RelativeFSRDown, &b_httCandidates_sjNonW_corr_RelativeFSRDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatFSRUp", httCandidates_sjNonW_corr_RelativeStatFSRUp, &b_httCandidates_sjNonW_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatFSRDown", httCandidates_sjNonW_corr_RelativeStatFSRDown, &b_httCandidates_sjNonW_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatECUp", httCandidates_sjNonW_corr_RelativeStatECUp, &b_httCandidates_sjNonW_corr_RelativeStatECUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatECDown", httCandidates_sjNonW_corr_RelativeStatECDown, &b_httCandidates_sjNonW_corr_RelativeStatECDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatHFUp", httCandidates_sjNonW_corr_RelativeStatHFUp, &b_httCandidates_sjNonW_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_RelativeStatHFDown", httCandidates_sjNonW_corr_RelativeStatHFDown, &b_httCandidates_sjNonW_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpDataMCUp", httCandidates_sjNonW_corr_PileUpDataMCUp, &b_httCandidates_sjNonW_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpDataMCDown", httCandidates_sjNonW_corr_PileUpDataMCDown, &b_httCandidates_sjNonW_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtRefUp", httCandidates_sjNonW_corr_PileUpPtRefUp, &b_httCandidates_sjNonW_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtRefDown", httCandidates_sjNonW_corr_PileUpPtRefDown, &b_httCandidates_sjNonW_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtBBUp", httCandidates_sjNonW_corr_PileUpPtBBUp, &b_httCandidates_sjNonW_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtBBDown", httCandidates_sjNonW_corr_PileUpPtBBDown, &b_httCandidates_sjNonW_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtEC1Up", httCandidates_sjNonW_corr_PileUpPtEC1Up, &b_httCandidates_sjNonW_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtEC1Down", httCandidates_sjNonW_corr_PileUpPtEC1Down, &b_httCandidates_sjNonW_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtEC2Up", httCandidates_sjNonW_corr_PileUpPtEC2Up, &b_httCandidates_sjNonW_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtEC2Down", httCandidates_sjNonW_corr_PileUpPtEC2Down, &b_httCandidates_sjNonW_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtHFUp", httCandidates_sjNonW_corr_PileUpPtHFUp, &b_httCandidates_sjNonW_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpPtHFDown", httCandidates_sjNonW_corr_PileUpPtHFDown, &b_httCandidates_sjNonW_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpMuZeroUp", httCandidates_sjNonW_corr_PileUpMuZeroUp, &b_httCandidates_sjNonW_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpMuZeroDown", httCandidates_sjNonW_corr_PileUpMuZeroDown, &b_httCandidates_sjNonW_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpEnvelopeUp", httCandidates_sjNonW_corr_PileUpEnvelopeUp, &b_httCandidates_sjNonW_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_PileUpEnvelopeDown", httCandidates_sjNonW_corr_PileUpEnvelopeDown, &b_httCandidates_sjNonW_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalPileUpUp", httCandidates_sjNonW_corr_SubTotalPileUpUp, &b_httCandidates_sjNonW_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalPileUpDown", httCandidates_sjNonW_corr_SubTotalPileUpDown, &b_httCandidates_sjNonW_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalRelativeUp", httCandidates_sjNonW_corr_SubTotalRelativeUp, &b_httCandidates_sjNonW_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalRelativeDown", httCandidates_sjNonW_corr_SubTotalRelativeDown, &b_httCandidates_sjNonW_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalPtUp", httCandidates_sjNonW_corr_SubTotalPtUp, &b_httCandidates_sjNonW_corr_SubTotalPtUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalPtDown", httCandidates_sjNonW_corr_SubTotalPtDown, &b_httCandidates_sjNonW_corr_SubTotalPtDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalScaleUp", httCandidates_sjNonW_corr_SubTotalScaleUp, &b_httCandidates_sjNonW_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalScaleDown", httCandidates_sjNonW_corr_SubTotalScaleDown, &b_httCandidates_sjNonW_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalAbsoluteUp", httCandidates_sjNonW_corr_SubTotalAbsoluteUp, &b_httCandidates_sjNonW_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalAbsoluteDown", httCandidates_sjNonW_corr_SubTotalAbsoluteDown, &b_httCandidates_sjNonW_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalMCUp", httCandidates_sjNonW_corr_SubTotalMCUp, &b_httCandidates_sjNonW_corr_SubTotalMCUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_SubTotalMCDown", httCandidates_sjNonW_corr_SubTotalMCDown, &b_httCandidates_sjNonW_corr_SubTotalMCDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalUp", httCandidates_sjNonW_corr_TotalUp, &b_httCandidates_sjNonW_corr_TotalUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalDown", httCandidates_sjNonW_corr_TotalDown, &b_httCandidates_sjNonW_corr_TotalDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoFlavorUp", httCandidates_sjNonW_corr_TotalNoFlavorUp, &b_httCandidates_sjNonW_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoFlavorDown", httCandidates_sjNonW_corr_TotalNoFlavorDown, &b_httCandidates_sjNonW_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoTimeUp", httCandidates_sjNonW_corr_TotalNoTimeUp, &b_httCandidates_sjNonW_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoTimeDown", httCandidates_sjNonW_corr_TotalNoTimeDown, &b_httCandidates_sjNonW_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoFlavorNoTimeUp", httCandidates_sjNonW_corr_TotalNoFlavorNoTimeUp, &b_httCandidates_sjNonW_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TotalNoFlavorNoTimeDown", httCandidates_sjNonW_corr_TotalNoFlavorNoTimeDown, &b_httCandidates_sjNonW_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorZJetUp", httCandidates_sjNonW_corr_FlavorZJetUp, &b_httCandidates_sjNonW_corr_FlavorZJetUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorZJetDown", httCandidates_sjNonW_corr_FlavorZJetDown, &b_httCandidates_sjNonW_corr_FlavorZJetDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPhotonJetUp", httCandidates_sjNonW_corr_FlavorPhotonJetUp, &b_httCandidates_sjNonW_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPhotonJetDown", httCandidates_sjNonW_corr_FlavorPhotonJetDown, &b_httCandidates_sjNonW_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureGluonUp", httCandidates_sjNonW_corr_FlavorPureGluonUp, &b_httCandidates_sjNonW_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureGluonDown", httCandidates_sjNonW_corr_FlavorPureGluonDown, &b_httCandidates_sjNonW_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureQuarkUp", httCandidates_sjNonW_corr_FlavorPureQuarkUp, &b_httCandidates_sjNonW_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureQuarkDown", httCandidates_sjNonW_corr_FlavorPureQuarkDown, &b_httCandidates_sjNonW_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureCharmUp", httCandidates_sjNonW_corr_FlavorPureCharmUp, &b_httCandidates_sjNonW_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureCharmDown", httCandidates_sjNonW_corr_FlavorPureCharmDown, &b_httCandidates_sjNonW_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureBottomUp", httCandidates_sjNonW_corr_FlavorPureBottomUp, &b_httCandidates_sjNonW_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_FlavorPureBottomDown", httCandidates_sjNonW_corr_FlavorPureBottomDown, &b_httCandidates_sjNonW_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunBCDUp", httCandidates_sjNonW_corr_TimeRunBCDUp, &b_httCandidates_sjNonW_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunBCDDown", httCandidates_sjNonW_corr_TimeRunBCDDown, &b_httCandidates_sjNonW_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunEFUp", httCandidates_sjNonW_corr_TimeRunEFUp, &b_httCandidates_sjNonW_corr_TimeRunEFUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunEFDown", httCandidates_sjNonW_corr_TimeRunEFDown, &b_httCandidates_sjNonW_corr_TimeRunEFDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunGUp", httCandidates_sjNonW_corr_TimeRunGUp, &b_httCandidates_sjNonW_corr_TimeRunGUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunGDown", httCandidates_sjNonW_corr_TimeRunGDown, &b_httCandidates_sjNonW_corr_TimeRunGDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunHUp", httCandidates_sjNonW_corr_TimeRunHUp, &b_httCandidates_sjNonW_corr_TimeRunHUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_TimeRunHDown", httCandidates_sjNonW_corr_TimeRunHDown, &b_httCandidates_sjNonW_corr_TimeRunHDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupMPFInSituUp", httCandidates_sjNonW_corr_CorrelationGroupMPFInSituUp, &b_httCandidates_sjNonW_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupMPFInSituDown", httCandidates_sjNonW_corr_CorrelationGroupMPFInSituDown, &b_httCandidates_sjNonW_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationUp", httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationUp, &b_httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationDown", httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationDown, &b_httCandidates_sjNonW_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupbJESUp", httCandidates_sjNonW_corr_CorrelationGroupbJESUp, &b_httCandidates_sjNonW_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupbJESDown", httCandidates_sjNonW_corr_CorrelationGroupbJESDown, &b_httCandidates_sjNonW_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupFlavorUp", httCandidates_sjNonW_corr_CorrelationGroupFlavorUp, &b_httCandidates_sjNonW_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupFlavorDown", httCandidates_sjNonW_corr_CorrelationGroupFlavorDown, &b_httCandidates_sjNonW_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedUp", httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedUp, &b_httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedDown", httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedDown, &b_httCandidates_sjNonW_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("nGenTop", &nGenTop, &b_nGenTop);
   fChain->SetBranchAddress("GenTop_charge", GenTop_charge, &b_GenTop_charge);
   fChain->SetBranchAddress("GenTop_status", GenTop_status, &b_GenTop_status);
   fChain->SetBranchAddress("GenTop_isPromptHard", GenTop_isPromptHard, &b_GenTop_isPromptHard);
   fChain->SetBranchAddress("GenTop_pdgId", GenTop_pdgId, &b_GenTop_pdgId);
   fChain->SetBranchAddress("GenTop_pt", GenTop_pt, &b_GenTop_pt);
   fChain->SetBranchAddress("GenTop_eta", GenTop_eta, &b_GenTop_eta);
   fChain->SetBranchAddress("GenTop_phi", GenTop_phi, &b_GenTop_phi);
   fChain->SetBranchAddress("GenTop_mass", GenTop_mass, &b_GenTop_mass);
   fChain->SetBranchAddress("GenTop_decayMode", GenTop_decayMode, &b_GenTop_decayMode);
   fChain->SetBranchAddress("nGenTaus", &nGenTaus, &b_nGenTaus);
   fChain->SetBranchAddress("GenTaus_charge", GenTaus_charge, &b_GenTaus_charge);
   fChain->SetBranchAddress("GenTaus_status", GenTaus_status, &b_GenTaus_status);
   fChain->SetBranchAddress("GenTaus_isPromptHard", GenTaus_isPromptHard, &b_GenTaus_isPromptHard);
   fChain->SetBranchAddress("GenTaus_pdgId", GenTaus_pdgId, &b_GenTaus_pdgId);
   fChain->SetBranchAddress("GenTaus_pt", GenTaus_pt, &b_GenTaus_pt);
   fChain->SetBranchAddress("GenTaus_eta", GenTaus_eta, &b_GenTaus_eta);
   fChain->SetBranchAddress("GenTaus_phi", GenTaus_phi, &b_GenTaus_phi);
   fChain->SetBranchAddress("GenTaus_mass", GenTaus_mass, &b_GenTaus_mass);
   fChain->SetBranchAddress("GenTaus_motherId", GenTaus_motherId, &b_GenTaus_motherId);
   fChain->SetBranchAddress("GenTaus_grandmotherId", GenTaus_grandmotherId, &b_GenTaus_grandmotherId);
   fChain->SetBranchAddress("GenTaus_sourceId", GenTaus_sourceId, &b_GenTaus_sourceId);
   fChain->SetBranchAddress("ntrgObjects_hltMHT70", &ntrgObjects_hltMHT70, &b_ntrgObjects_hltMHT70);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_id", Jet_id, &b_Jet_id);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btagCSV", Jet_btagCSV, &b_Jet_btagCSV);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_rawPt", Jet_rawPt, &b_Jet_rawPt);
   fChain->SetBranchAddress("Jet_mcPt", Jet_mcPt, &b_Jet_mcPt);
   fChain->SetBranchAddress("Jet_mcFlavour", Jet_mcFlavour, &b_Jet_mcFlavour);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_mcMatchId", Jet_mcMatchId, &b_Jet_mcMatchId);
   fChain->SetBranchAddress("Jet_corr_JECUp", Jet_corr_JECUp, &b_Jet_corr_JECUp);
   fChain->SetBranchAddress("Jet_corr_JECDown", Jet_corr_JECDown, &b_Jet_corr_JECDown);
   fChain->SetBranchAddress("Jet_corr", Jet_corr, &b_Jet_corr);
   fChain->SetBranchAddress("Jet_corr_JERUp", Jet_corr_JERUp, &b_Jet_corr_JERUp);
   fChain->SetBranchAddress("Jet_corr_JERDown", Jet_corr_JERDown, &b_Jet_corr_JERDown);
   fChain->SetBranchAddress("Jet_corr_JER", Jet_corr_JER, &b_Jet_corr_JER);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_rawPtAfterSmearing", Jet_rawPtAfterSmearing, &b_Jet_rawPtAfterSmearing);
   fChain->SetBranchAddress("Jet_idxFirstTauMatch", Jet_idxFirstTauMatch, &b_Jet_idxFirstTauMatch);
   fChain->SetBranchAddress("Jet_heppyFlavour", Jet_heppyFlavour, &b_Jet_heppyFlavour);
   fChain->SetBranchAddress("Jet_ctagVsL", Jet_ctagVsL, &b_Jet_ctagVsL);
   fChain->SetBranchAddress("Jet_ctagVsB", Jet_ctagVsB, &b_Jet_ctagVsB);
   fChain->SetBranchAddress("Jet_btagBDT", Jet_btagBDT, &b_Jet_btagBDT);
   fChain->SetBranchAddress("Jet_btagProb", Jet_btagProb, &b_Jet_btagProb);
   fChain->SetBranchAddress("Jet_btagBProb", Jet_btagBProb, &b_Jet_btagBProb);
   fChain->SetBranchAddress("Jet_btagSoftEl", Jet_btagSoftEl, &b_Jet_btagSoftEl);
   fChain->SetBranchAddress("Jet_btagSoftMu", Jet_btagSoftMu, &b_Jet_btagSoftMu);
   fChain->SetBranchAddress("Jet_btagDeepCSVdusg", Jet_btagDeepCSVdusg, &b_Jet_btagDeepCSVdusg);
   fChain->SetBranchAddress("Jet_btagDeepCSVb", Jet_btagDeepCSVb, &b_Jet_btagDeepCSVb);
   fChain->SetBranchAddress("Jet_btagDeepCSVc", Jet_btagDeepCSVc, &b_Jet_btagDeepCSVc);
   fChain->SetBranchAddress("Jet_btagDeepCSVbb", Jet_btagDeepCSVbb, &b_Jet_btagDeepCSVbb);
   fChain->SetBranchAddress("Jet_btagDeepCMVAdusg", Jet_btagDeepCMVAdusg, &b_Jet_btagDeepCMVAdusg);
   fChain->SetBranchAddress("Jet_btagDeepCMVAb", Jet_btagDeepCMVAb, &b_Jet_btagDeepCMVAb);
   fChain->SetBranchAddress("Jet_btagDeepCMVAc", Jet_btagDeepCMVAc, &b_Jet_btagDeepCMVAc);
   fChain->SetBranchAddress("Jet_btagDeepCMVAbb", Jet_btagDeepCMVAbb, &b_Jet_btagDeepCMVAbb);
   fChain->SetBranchAddress("Jet_btagCSVV0", Jet_btagCSVV0, &b_Jet_btagCSVV0);
   fChain->SetBranchAddress("Jet_btagCMVAV2", Jet_btagCMVAV2, &b_Jet_btagCMVAV2);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   fChain->SetBranchAddress("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_chMult", Jet_chMult, &b_Jet_chMult);
   fChain->SetBranchAddress("Jet_nhMult", Jet_nhMult, &b_Jet_nhMult);
   fChain->SetBranchAddress("Jet_leadTrackPt", Jet_leadTrackPt, &b_Jet_leadTrackPt);
   fChain->SetBranchAddress("Jet_mcEta", Jet_mcEta, &b_Jet_mcEta);
   fChain->SetBranchAddress("Jet_mcPhi", Jet_mcPhi, &b_Jet_mcPhi);
   fChain->SetBranchAddress("Jet_mcM", Jet_mcM, &b_Jet_mcM);
   fChain->SetBranchAddress("Jet_leptonPdgId", Jet_leptonPdgId, &b_Jet_leptonPdgId);
   fChain->SetBranchAddress("Jet_leptonPt", Jet_leptonPt, &b_Jet_leptonPt);
   fChain->SetBranchAddress("Jet_leptonPtRel", Jet_leptonPtRel, &b_Jet_leptonPtRel);
   fChain->SetBranchAddress("Jet_leptonPtRelInv", Jet_leptonPtRelInv, &b_Jet_leptonPtRelInv);
   fChain->SetBranchAddress("Jet_leptonDeltaR", Jet_leptonDeltaR, &b_Jet_leptonDeltaR);
   fChain->SetBranchAddress("Jet_leptonDeltaPhi", Jet_leptonDeltaPhi, &b_Jet_leptonDeltaPhi);
   fChain->SetBranchAddress("Jet_leptonDeltaEta", Jet_leptonDeltaEta, &b_Jet_leptonDeltaEta);
   fChain->SetBranchAddress("Jet_vtxMass", Jet_vtxMass, &b_Jet_vtxMass);
   fChain->SetBranchAddress("Jet_vtxNtracks", Jet_vtxNtracks, &b_Jet_vtxNtracks);
   fChain->SetBranchAddress("Jet_vtxPt", Jet_vtxPt, &b_Jet_vtxPt);
   fChain->SetBranchAddress("Jet_vtx3DSig", Jet_vtx3DSig, &b_Jet_vtx3DSig);
   fChain->SetBranchAddress("Jet_vtx3DVal", Jet_vtx3DVal, &b_Jet_vtx3DVal);
   fChain->SetBranchAddress("Jet_vtxPosX", Jet_vtxPosX, &b_Jet_vtxPosX);
   fChain->SetBranchAddress("Jet_vtxPosY", Jet_vtxPosY, &b_Jet_vtxPosY);
   fChain->SetBranchAddress("Jet_vtxPosZ", Jet_vtxPosZ, &b_Jet_vtxPosZ);
   fChain->SetBranchAddress("Jet_pullVectorPhi", Jet_pullVectorPhi, &b_Jet_pullVectorPhi);
   fChain->SetBranchAddress("Jet_pullVectorMag", Jet_pullVectorMag, &b_Jet_pullVectorMag);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_ptd", Jet_ptd, &b_Jet_ptd);
   fChain->SetBranchAddress("Jet_axis2", Jet_axis2, &b_Jet_axis2);
   fChain->SetBranchAddress("Jet_mult", Jet_mult, &b_Jet_mult);
   fChain->SetBranchAddress("Jet_numberOfDaughters", Jet_numberOfDaughters, &b_Jet_numberOfDaughters);
   fChain->SetBranchAddress("Jet_btagIdx", Jet_btagIdx, &b_Jet_btagIdx);
   fChain->SetBranchAddress("Jet_btagCmvaIdx", Jet_btagCmvaIdx, &b_Jet_btagCmvaIdx);
   fChain->SetBranchAddress("Jet_mcIdx", Jet_mcIdx, &b_Jet_mcIdx);
   fChain->SetBranchAddress("Jet_blike_VBF", Jet_blike_VBF, &b_Jet_blike_VBF);
   fChain->SetBranchAddress("Jet_pt_puppi", Jet_pt_puppi, &b_Jet_pt_puppi);
   fChain->SetBranchAddress("Jet_energyRing_dR0_em", Jet_energyRing_dR0_em, &b_Jet_energyRing_dR0_em);
   fChain->SetBranchAddress("Jet_energyRing_dR1_em", Jet_energyRing_dR1_em, &b_Jet_energyRing_dR1_em);
   fChain->SetBranchAddress("Jet_energyRing_dR2_em", Jet_energyRing_dR2_em, &b_Jet_energyRing_dR2_em);
   fChain->SetBranchAddress("Jet_energyRing_dR3_em", Jet_energyRing_dR3_em, &b_Jet_energyRing_dR3_em);
   fChain->SetBranchAddress("Jet_energyRing_dR4_em", Jet_energyRing_dR4_em, &b_Jet_energyRing_dR4_em);
   fChain->SetBranchAddress("Jet_energyRing_dR5_em", Jet_energyRing_dR5_em, &b_Jet_energyRing_dR5_em);
   fChain->SetBranchAddress("Jet_energyRing_dR0_mu", Jet_energyRing_dR0_mu, &b_Jet_energyRing_dR0_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR1_mu", Jet_energyRing_dR1_mu, &b_Jet_energyRing_dR1_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR2_mu", Jet_energyRing_dR2_mu, &b_Jet_energyRing_dR2_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR3_mu", Jet_energyRing_dR3_mu, &b_Jet_energyRing_dR3_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR4_mu", Jet_energyRing_dR4_mu, &b_Jet_energyRing_dR4_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR5_mu", Jet_energyRing_dR5_mu, &b_Jet_energyRing_dR5_mu);
   fChain->SetBranchAddress("Jet_energyRing_dR0_ch", Jet_energyRing_dR0_ch, &b_Jet_energyRing_dR0_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR1_ch", Jet_energyRing_dR1_ch, &b_Jet_energyRing_dR1_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR2_ch", Jet_energyRing_dR2_ch, &b_Jet_energyRing_dR2_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR3_ch", Jet_energyRing_dR3_ch, &b_Jet_energyRing_dR3_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR4_ch", Jet_energyRing_dR4_ch, &b_Jet_energyRing_dR4_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR5_ch", Jet_energyRing_dR5_ch, &b_Jet_energyRing_dR5_ch);
   fChain->SetBranchAddress("Jet_energyRing_dR0_neut", Jet_energyRing_dR0_neut, &b_Jet_energyRing_dR0_neut);
   fChain->SetBranchAddress("Jet_energyRing_dR1_neut", Jet_energyRing_dR1_neut, &b_Jet_energyRing_dR1_neut);
   fChain->SetBranchAddress("Jet_energyRing_dR2_neut", Jet_energyRing_dR2_neut, &b_Jet_energyRing_dR2_neut);
   fChain->SetBranchAddress("Jet_energyRing_dR3_neut", Jet_energyRing_dR3_neut, &b_Jet_energyRing_dR3_neut);
   fChain->SetBranchAddress("Jet_energyRing_dR4_neut", Jet_energyRing_dR4_neut, &b_Jet_energyRing_dR4_neut);
   fChain->SetBranchAddress("Jet_energyRing_dR5_neut", Jet_energyRing_dR5_neut, &b_Jet_energyRing_dR5_neut);
   fChain->SetBranchAddress("Jet_numDaughters_pt03", Jet_numDaughters_pt03, &b_Jet_numDaughters_pt03);
   fChain->SetBranchAddress("Jet_rawEnergy", Jet_rawEnergy, &b_Jet_rawEnergy);
   fChain->SetBranchAddress("Jet_pt_reg", Jet_pt_reg, &b_Jet_pt_reg);
   fChain->SetBranchAddress("Jet_pt_regVBF", Jet_pt_regVBF, &b_Jet_pt_regVBF);
   fChain->SetBranchAddress("Jet_pt_reg_corrJECUp", Jet_pt_reg_corrJECUp, &b_Jet_pt_reg_corrJECUp);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJECUp", Jet_pt_regVBF_corrJECUp, &b_Jet_pt_regVBF_corrJECUp);
   fChain->SetBranchAddress("Jet_pt_reg_corrJECDown", Jet_pt_reg_corrJECDown, &b_Jet_pt_reg_corrJECDown);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJECDown", Jet_pt_regVBF_corrJECDown, &b_Jet_pt_regVBF_corrJECDown);
   fChain->SetBranchAddress("Jet_pt_reg_corrJERUp", Jet_pt_reg_corrJERUp, &b_Jet_pt_reg_corrJERUp);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJERUp", Jet_pt_regVBF_corrJERUp, &b_Jet_pt_regVBF_corrJERUp);
   fChain->SetBranchAddress("Jet_pt_reg_corrJERDown", Jet_pt_reg_corrJERDown, &b_Jet_pt_reg_corrJERDown);
   fChain->SetBranchAddress("Jet_pt_regVBF_corrJERDown", Jet_pt_regVBF_corrJERDown, &b_Jet_pt_regVBF_corrJERDown);
   fChain->SetBranchAddress("Jet_btagCSVL_SF", Jet_btagCSVL_SF, &b_Jet_btagCSVL_SF);
   fChain->SetBranchAddress("Jet_btagCSVL_SF_up", Jet_btagCSVL_SF_up, &b_Jet_btagCSVL_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVL_SF_down", Jet_btagCSVL_SF_down, &b_Jet_btagCSVL_SF_down);
   fChain->SetBranchAddress("Jet_btagCSVM_SF", Jet_btagCSVM_SF, &b_Jet_btagCSVM_SF);
   fChain->SetBranchAddress("Jet_btagCSVM_SF_up", Jet_btagCSVM_SF_up, &b_Jet_btagCSVM_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVM_SF_down", Jet_btagCSVM_SF_down, &b_Jet_btagCSVM_SF_down);
   fChain->SetBranchAddress("Jet_btagCSVT_SF", Jet_btagCSVT_SF, &b_Jet_btagCSVT_SF);
   fChain->SetBranchAddress("Jet_btagCSVT_SF_up", Jet_btagCSVT_SF_up, &b_Jet_btagCSVT_SF_up);
   fChain->SetBranchAddress("Jet_btagCSVT_SF_down", Jet_btagCSVT_SF_down, &b_Jet_btagCSVT_SF_down);
   fChain->SetBranchAddress("Jet_btagWeightCSV", Jet_btagWeightCSV, &b_Jet_btagWeightCSV);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_jes", Jet_btagWeightCSV_up_jes, &b_Jet_btagWeightCSV_up_jes);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_jes", Jet_btagWeightCSV_down_jes, &b_Jet_btagWeightCSV_down_jes);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lf", Jet_btagWeightCSV_up_lf, &b_Jet_btagWeightCSV_up_lf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lf", Jet_btagWeightCSV_down_lf, &b_Jet_btagWeightCSV_down_lf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hf", Jet_btagWeightCSV_up_hf, &b_Jet_btagWeightCSV_up_hf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hf", Jet_btagWeightCSV_down_hf, &b_Jet_btagWeightCSV_down_hf);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hfstats1", Jet_btagWeightCSV_up_hfstats1, &b_Jet_btagWeightCSV_up_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hfstats1", Jet_btagWeightCSV_down_hfstats1, &b_Jet_btagWeightCSV_down_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_hfstats2", Jet_btagWeightCSV_up_hfstats2, &b_Jet_btagWeightCSV_up_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_hfstats2", Jet_btagWeightCSV_down_hfstats2, &b_Jet_btagWeightCSV_down_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lfstats1", Jet_btagWeightCSV_up_lfstats1, &b_Jet_btagWeightCSV_up_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lfstats1", Jet_btagWeightCSV_down_lfstats1, &b_Jet_btagWeightCSV_down_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_lfstats2", Jet_btagWeightCSV_up_lfstats2, &b_Jet_btagWeightCSV_up_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_lfstats2", Jet_btagWeightCSV_down_lfstats2, &b_Jet_btagWeightCSV_down_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_cferr1", Jet_btagWeightCSV_up_cferr1, &b_Jet_btagWeightCSV_up_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_cferr1", Jet_btagWeightCSV_down_cferr1, &b_Jet_btagWeightCSV_down_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCSV_up_cferr2", Jet_btagWeightCSV_up_cferr2, &b_Jet_btagWeightCSV_up_cferr2);
   fChain->SetBranchAddress("Jet_btagWeightCSV_down_cferr2", Jet_btagWeightCSV_down_cferr2, &b_Jet_btagWeightCSV_down_cferr2);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF", Jet_btagCMVAV2L_SF, &b_Jet_btagCMVAV2L_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF_up", Jet_btagCMVAV2L_SF_up, &b_Jet_btagCMVAV2L_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2L_SF_down", Jet_btagCMVAV2L_SF_down, &b_Jet_btagCMVAV2L_SF_down);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF", Jet_btagCMVAV2M_SF, &b_Jet_btagCMVAV2M_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF_up", Jet_btagCMVAV2M_SF_up, &b_Jet_btagCMVAV2M_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2M_SF_down", Jet_btagCMVAV2M_SF_down, &b_Jet_btagCMVAV2M_SF_down);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF", Jet_btagCMVAV2T_SF, &b_Jet_btagCMVAV2T_SF);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF_up", Jet_btagCMVAV2T_SF_up, &b_Jet_btagCMVAV2T_SF_up);
   fChain->SetBranchAddress("Jet_btagCMVAV2T_SF_down", Jet_btagCMVAV2T_SF_down, &b_Jet_btagCMVAV2T_SF_down);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2", Jet_btagWeightCMVAV2, &b_Jet_btagWeightCMVAV2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_jes", Jet_btagWeightCMVAV2_up_jes, &b_Jet_btagWeightCMVAV2_up_jes);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_jes", Jet_btagWeightCMVAV2_down_jes, &b_Jet_btagWeightCMVAV2_down_jes);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lf", Jet_btagWeightCMVAV2_up_lf, &b_Jet_btagWeightCMVAV2_up_lf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lf", Jet_btagWeightCMVAV2_down_lf, &b_Jet_btagWeightCMVAV2_down_lf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hf", Jet_btagWeightCMVAV2_up_hf, &b_Jet_btagWeightCMVAV2_up_hf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hf", Jet_btagWeightCMVAV2_down_hf, &b_Jet_btagWeightCMVAV2_down_hf);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hfstats1", Jet_btagWeightCMVAV2_up_hfstats1, &b_Jet_btagWeightCMVAV2_up_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hfstats1", Jet_btagWeightCMVAV2_down_hfstats1, &b_Jet_btagWeightCMVAV2_down_hfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_hfstats2", Jet_btagWeightCMVAV2_up_hfstats2, &b_Jet_btagWeightCMVAV2_up_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_hfstats2", Jet_btagWeightCMVAV2_down_hfstats2, &b_Jet_btagWeightCMVAV2_down_hfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lfstats1", Jet_btagWeightCMVAV2_up_lfstats1, &b_Jet_btagWeightCMVAV2_up_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lfstats1", Jet_btagWeightCMVAV2_down_lfstats1, &b_Jet_btagWeightCMVAV2_down_lfstats1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_lfstats2", Jet_btagWeightCMVAV2_up_lfstats2, &b_Jet_btagWeightCMVAV2_up_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_lfstats2", Jet_btagWeightCMVAV2_down_lfstats2, &b_Jet_btagWeightCMVAV2_down_lfstats2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_cferr1", Jet_btagWeightCMVAV2_up_cferr1, &b_Jet_btagWeightCMVAV2_up_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_cferr1", Jet_btagWeightCMVAV2_down_cferr1, &b_Jet_btagWeightCMVAV2_down_cferr1);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_up_cferr2", Jet_btagWeightCMVAV2_up_cferr2, &b_Jet_btagWeightCMVAV2_up_cferr2);
   fChain->SetBranchAddress("Jet_btagWeightCMVAV2_down_cferr2", Jet_btagWeightCMVAV2_down_cferr2, &b_Jet_btagWeightCMVAV2_down_cferr2);
   fChain->SetBranchAddress("Jet_corr_AbsoluteStatUp", Jet_corr_AbsoluteStatUp, &b_Jet_corr_AbsoluteStatUp);
   fChain->SetBranchAddress("Jet_corr_AbsoluteStatDown", Jet_corr_AbsoluteStatDown, &b_Jet_corr_AbsoluteStatDown);
   fChain->SetBranchAddress("Jet_corr_AbsoluteScaleUp", Jet_corr_AbsoluteScaleUp, &b_Jet_corr_AbsoluteScaleUp);
   fChain->SetBranchAddress("Jet_corr_AbsoluteScaleDown", Jet_corr_AbsoluteScaleDown, &b_Jet_corr_AbsoluteScaleDown);
   fChain->SetBranchAddress("Jet_corr_AbsoluteFlavMapUp", Jet_corr_AbsoluteFlavMapUp, &b_Jet_corr_AbsoluteFlavMapUp);
   fChain->SetBranchAddress("Jet_corr_AbsoluteFlavMapDown", Jet_corr_AbsoluteFlavMapDown, &b_Jet_corr_AbsoluteFlavMapDown);
   fChain->SetBranchAddress("Jet_corr_AbsoluteMPFBiasUp", Jet_corr_AbsoluteMPFBiasUp, &b_Jet_corr_AbsoluteMPFBiasUp);
   fChain->SetBranchAddress("Jet_corr_AbsoluteMPFBiasDown", Jet_corr_AbsoluteMPFBiasDown, &b_Jet_corr_AbsoluteMPFBiasDown);
   fChain->SetBranchAddress("Jet_corr_FragmentationUp", Jet_corr_FragmentationUp, &b_Jet_corr_FragmentationUp);
   fChain->SetBranchAddress("Jet_corr_FragmentationDown", Jet_corr_FragmentationDown, &b_Jet_corr_FragmentationDown);
   fChain->SetBranchAddress("Jet_corr_SinglePionECALUp", Jet_corr_SinglePionECALUp, &b_Jet_corr_SinglePionECALUp);
   fChain->SetBranchAddress("Jet_corr_SinglePionECALDown", Jet_corr_SinglePionECALDown, &b_Jet_corr_SinglePionECALDown);
   fChain->SetBranchAddress("Jet_corr_SinglePionHCALUp", Jet_corr_SinglePionHCALUp, &b_Jet_corr_SinglePionHCALUp);
   fChain->SetBranchAddress("Jet_corr_SinglePionHCALDown", Jet_corr_SinglePionHCALDown, &b_Jet_corr_SinglePionHCALDown);
   fChain->SetBranchAddress("Jet_corr_FlavorQCDUp", Jet_corr_FlavorQCDUp, &b_Jet_corr_FlavorQCDUp);
   fChain->SetBranchAddress("Jet_corr_FlavorQCDDown", Jet_corr_FlavorQCDDown, &b_Jet_corr_FlavorQCDDown);
   fChain->SetBranchAddress("Jet_corr_TimePtEtaUp", Jet_corr_TimePtEtaUp, &b_Jet_corr_TimePtEtaUp);
   fChain->SetBranchAddress("Jet_corr_TimePtEtaDown", Jet_corr_TimePtEtaDown, &b_Jet_corr_TimePtEtaDown);
   fChain->SetBranchAddress("Jet_corr_RelativeJEREC1Up", Jet_corr_RelativeJEREC1Up, &b_Jet_corr_RelativeJEREC1Up);
   fChain->SetBranchAddress("Jet_corr_RelativeJEREC1Down", Jet_corr_RelativeJEREC1Down, &b_Jet_corr_RelativeJEREC1Down);
   fChain->SetBranchAddress("Jet_corr_RelativeJEREC2Up", Jet_corr_RelativeJEREC2Up, &b_Jet_corr_RelativeJEREC2Up);
   fChain->SetBranchAddress("Jet_corr_RelativeJEREC2Down", Jet_corr_RelativeJEREC2Down, &b_Jet_corr_RelativeJEREC2Down);
   fChain->SetBranchAddress("Jet_corr_RelativeJERHFUp", Jet_corr_RelativeJERHFUp, &b_Jet_corr_RelativeJERHFUp);
   fChain->SetBranchAddress("Jet_corr_RelativeJERHFDown", Jet_corr_RelativeJERHFDown, &b_Jet_corr_RelativeJERHFDown);
   fChain->SetBranchAddress("Jet_corr_RelativePtBBUp", Jet_corr_RelativePtBBUp, &b_Jet_corr_RelativePtBBUp);
   fChain->SetBranchAddress("Jet_corr_RelativePtBBDown", Jet_corr_RelativePtBBDown, &b_Jet_corr_RelativePtBBDown);
   fChain->SetBranchAddress("Jet_corr_RelativePtEC1Up", Jet_corr_RelativePtEC1Up, &b_Jet_corr_RelativePtEC1Up);
   fChain->SetBranchAddress("Jet_corr_RelativePtEC1Down", Jet_corr_RelativePtEC1Down, &b_Jet_corr_RelativePtEC1Down);
   fChain->SetBranchAddress("Jet_corr_RelativePtEC2Up", Jet_corr_RelativePtEC2Up, &b_Jet_corr_RelativePtEC2Up);
   fChain->SetBranchAddress("Jet_corr_RelativePtEC2Down", Jet_corr_RelativePtEC2Down, &b_Jet_corr_RelativePtEC2Down);
   fChain->SetBranchAddress("Jet_corr_RelativePtHFUp", Jet_corr_RelativePtHFUp, &b_Jet_corr_RelativePtHFUp);
   fChain->SetBranchAddress("Jet_corr_RelativePtHFDown", Jet_corr_RelativePtHFDown, &b_Jet_corr_RelativePtHFDown);
   fChain->SetBranchAddress("Jet_corr_RelativeBalUp", Jet_corr_RelativeBalUp, &b_Jet_corr_RelativeBalUp);
   fChain->SetBranchAddress("Jet_corr_RelativeBalDown", Jet_corr_RelativeBalDown, &b_Jet_corr_RelativeBalDown);
   fChain->SetBranchAddress("Jet_corr_RelativeFSRUp", Jet_corr_RelativeFSRUp, &b_Jet_corr_RelativeFSRUp);
   fChain->SetBranchAddress("Jet_corr_RelativeFSRDown", Jet_corr_RelativeFSRDown, &b_Jet_corr_RelativeFSRDown);
   fChain->SetBranchAddress("Jet_corr_RelativeStatFSRUp", Jet_corr_RelativeStatFSRUp, &b_Jet_corr_RelativeStatFSRUp);
   fChain->SetBranchAddress("Jet_corr_RelativeStatFSRDown", Jet_corr_RelativeStatFSRDown, &b_Jet_corr_RelativeStatFSRDown);
   fChain->SetBranchAddress("Jet_corr_RelativeStatECUp", Jet_corr_RelativeStatECUp, &b_Jet_corr_RelativeStatECUp);
   fChain->SetBranchAddress("Jet_corr_RelativeStatECDown", Jet_corr_RelativeStatECDown, &b_Jet_corr_RelativeStatECDown);
   fChain->SetBranchAddress("Jet_corr_RelativeStatHFUp", Jet_corr_RelativeStatHFUp, &b_Jet_corr_RelativeStatHFUp);
   fChain->SetBranchAddress("Jet_corr_RelativeStatHFDown", Jet_corr_RelativeStatHFDown, &b_Jet_corr_RelativeStatHFDown);
   fChain->SetBranchAddress("Jet_corr_PileUpDataMCUp", Jet_corr_PileUpDataMCUp, &b_Jet_corr_PileUpDataMCUp);
   fChain->SetBranchAddress("Jet_corr_PileUpDataMCDown", Jet_corr_PileUpDataMCDown, &b_Jet_corr_PileUpDataMCDown);
   fChain->SetBranchAddress("Jet_corr_PileUpPtRefUp", Jet_corr_PileUpPtRefUp, &b_Jet_corr_PileUpPtRefUp);
   fChain->SetBranchAddress("Jet_corr_PileUpPtRefDown", Jet_corr_PileUpPtRefDown, &b_Jet_corr_PileUpPtRefDown);
   fChain->SetBranchAddress("Jet_corr_PileUpPtBBUp", Jet_corr_PileUpPtBBUp, &b_Jet_corr_PileUpPtBBUp);
   fChain->SetBranchAddress("Jet_corr_PileUpPtBBDown", Jet_corr_PileUpPtBBDown, &b_Jet_corr_PileUpPtBBDown);
   fChain->SetBranchAddress("Jet_corr_PileUpPtEC1Up", Jet_corr_PileUpPtEC1Up, &b_Jet_corr_PileUpPtEC1Up);
   fChain->SetBranchAddress("Jet_corr_PileUpPtEC1Down", Jet_corr_PileUpPtEC1Down, &b_Jet_corr_PileUpPtEC1Down);
   fChain->SetBranchAddress("Jet_corr_PileUpPtEC2Up", Jet_corr_PileUpPtEC2Up, &b_Jet_corr_PileUpPtEC2Up);
   fChain->SetBranchAddress("Jet_corr_PileUpPtEC2Down", Jet_corr_PileUpPtEC2Down, &b_Jet_corr_PileUpPtEC2Down);
   fChain->SetBranchAddress("Jet_corr_PileUpPtHFUp", Jet_corr_PileUpPtHFUp, &b_Jet_corr_PileUpPtHFUp);
   fChain->SetBranchAddress("Jet_corr_PileUpPtHFDown", Jet_corr_PileUpPtHFDown, &b_Jet_corr_PileUpPtHFDown);
   fChain->SetBranchAddress("Jet_corr_PileUpMuZeroUp", Jet_corr_PileUpMuZeroUp, &b_Jet_corr_PileUpMuZeroUp);
   fChain->SetBranchAddress("Jet_corr_PileUpMuZeroDown", Jet_corr_PileUpMuZeroDown, &b_Jet_corr_PileUpMuZeroDown);
   fChain->SetBranchAddress("Jet_corr_PileUpEnvelopeUp", Jet_corr_PileUpEnvelopeUp, &b_Jet_corr_PileUpEnvelopeUp);
   fChain->SetBranchAddress("Jet_corr_PileUpEnvelopeDown", Jet_corr_PileUpEnvelopeDown, &b_Jet_corr_PileUpEnvelopeDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalPileUpUp", Jet_corr_SubTotalPileUpUp, &b_Jet_corr_SubTotalPileUpUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalPileUpDown", Jet_corr_SubTotalPileUpDown, &b_Jet_corr_SubTotalPileUpDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalRelativeUp", Jet_corr_SubTotalRelativeUp, &b_Jet_corr_SubTotalRelativeUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalRelativeDown", Jet_corr_SubTotalRelativeDown, &b_Jet_corr_SubTotalRelativeDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalPtUp", Jet_corr_SubTotalPtUp, &b_Jet_corr_SubTotalPtUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalPtDown", Jet_corr_SubTotalPtDown, &b_Jet_corr_SubTotalPtDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalScaleUp", Jet_corr_SubTotalScaleUp, &b_Jet_corr_SubTotalScaleUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalScaleDown", Jet_corr_SubTotalScaleDown, &b_Jet_corr_SubTotalScaleDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalAbsoluteUp", Jet_corr_SubTotalAbsoluteUp, &b_Jet_corr_SubTotalAbsoluteUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalAbsoluteDown", Jet_corr_SubTotalAbsoluteDown, &b_Jet_corr_SubTotalAbsoluteDown);
   fChain->SetBranchAddress("Jet_corr_SubTotalMCUp", Jet_corr_SubTotalMCUp, &b_Jet_corr_SubTotalMCUp);
   fChain->SetBranchAddress("Jet_corr_SubTotalMCDown", Jet_corr_SubTotalMCDown, &b_Jet_corr_SubTotalMCDown);
   fChain->SetBranchAddress("Jet_corr_TotalUp", Jet_corr_TotalUp, &b_Jet_corr_TotalUp);
   fChain->SetBranchAddress("Jet_corr_TotalDown", Jet_corr_TotalDown, &b_Jet_corr_TotalDown);
   fChain->SetBranchAddress("Jet_corr_TotalNoFlavorUp", Jet_corr_TotalNoFlavorUp, &b_Jet_corr_TotalNoFlavorUp);
   fChain->SetBranchAddress("Jet_corr_TotalNoFlavorDown", Jet_corr_TotalNoFlavorDown, &b_Jet_corr_TotalNoFlavorDown);
   fChain->SetBranchAddress("Jet_corr_TotalNoTimeUp", Jet_corr_TotalNoTimeUp, &b_Jet_corr_TotalNoTimeUp);
   fChain->SetBranchAddress("Jet_corr_TotalNoTimeDown", Jet_corr_TotalNoTimeDown, &b_Jet_corr_TotalNoTimeDown);
   fChain->SetBranchAddress("Jet_corr_TotalNoFlavorNoTimeUp", Jet_corr_TotalNoFlavorNoTimeUp, &b_Jet_corr_TotalNoFlavorNoTimeUp);
   fChain->SetBranchAddress("Jet_corr_TotalNoFlavorNoTimeDown", Jet_corr_TotalNoFlavorNoTimeDown, &b_Jet_corr_TotalNoFlavorNoTimeDown);
   fChain->SetBranchAddress("Jet_corr_FlavorZJetUp", Jet_corr_FlavorZJetUp, &b_Jet_corr_FlavorZJetUp);
   fChain->SetBranchAddress("Jet_corr_FlavorZJetDown", Jet_corr_FlavorZJetDown, &b_Jet_corr_FlavorZJetDown);
   fChain->SetBranchAddress("Jet_corr_FlavorPhotonJetUp", Jet_corr_FlavorPhotonJetUp, &b_Jet_corr_FlavorPhotonJetUp);
   fChain->SetBranchAddress("Jet_corr_FlavorPhotonJetDown", Jet_corr_FlavorPhotonJetDown, &b_Jet_corr_FlavorPhotonJetDown);
   fChain->SetBranchAddress("Jet_corr_FlavorPureGluonUp", Jet_corr_FlavorPureGluonUp, &b_Jet_corr_FlavorPureGluonUp);
   fChain->SetBranchAddress("Jet_corr_FlavorPureGluonDown", Jet_corr_FlavorPureGluonDown, &b_Jet_corr_FlavorPureGluonDown);
   fChain->SetBranchAddress("Jet_corr_FlavorPureQuarkUp", Jet_corr_FlavorPureQuarkUp, &b_Jet_corr_FlavorPureQuarkUp);
   fChain->SetBranchAddress("Jet_corr_FlavorPureQuarkDown", Jet_corr_FlavorPureQuarkDown, &b_Jet_corr_FlavorPureQuarkDown);
   fChain->SetBranchAddress("Jet_corr_FlavorPureCharmUp", Jet_corr_FlavorPureCharmUp, &b_Jet_corr_FlavorPureCharmUp);
   fChain->SetBranchAddress("Jet_corr_FlavorPureCharmDown", Jet_corr_FlavorPureCharmDown, &b_Jet_corr_FlavorPureCharmDown);
   fChain->SetBranchAddress("Jet_corr_FlavorPureBottomUp", Jet_corr_FlavorPureBottomUp, &b_Jet_corr_FlavorPureBottomUp);
   fChain->SetBranchAddress("Jet_corr_FlavorPureBottomDown", Jet_corr_FlavorPureBottomDown, &b_Jet_corr_FlavorPureBottomDown);
   fChain->SetBranchAddress("Jet_corr_TimeRunBCDUp", Jet_corr_TimeRunBCDUp, &b_Jet_corr_TimeRunBCDUp);
   fChain->SetBranchAddress("Jet_corr_TimeRunBCDDown", Jet_corr_TimeRunBCDDown, &b_Jet_corr_TimeRunBCDDown);
   fChain->SetBranchAddress("Jet_corr_TimeRunEFUp", Jet_corr_TimeRunEFUp, &b_Jet_corr_TimeRunEFUp);
   fChain->SetBranchAddress("Jet_corr_TimeRunEFDown", Jet_corr_TimeRunEFDown, &b_Jet_corr_TimeRunEFDown);
   fChain->SetBranchAddress("Jet_corr_TimeRunGUp", Jet_corr_TimeRunGUp, &b_Jet_corr_TimeRunGUp);
   fChain->SetBranchAddress("Jet_corr_TimeRunGDown", Jet_corr_TimeRunGDown, &b_Jet_corr_TimeRunGDown);
   fChain->SetBranchAddress("Jet_corr_TimeRunHUp", Jet_corr_TimeRunHUp, &b_Jet_corr_TimeRunHUp);
   fChain->SetBranchAddress("Jet_corr_TimeRunHDown", Jet_corr_TimeRunHDown, &b_Jet_corr_TimeRunHDown);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupMPFInSituUp", Jet_corr_CorrelationGroupMPFInSituUp, &b_Jet_corr_CorrelationGroupMPFInSituUp);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupMPFInSituDown", Jet_corr_CorrelationGroupMPFInSituDown, &b_Jet_corr_CorrelationGroupMPFInSituDown);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupIntercalibrationUp", Jet_corr_CorrelationGroupIntercalibrationUp, &b_Jet_corr_CorrelationGroupIntercalibrationUp);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupIntercalibrationDown", Jet_corr_CorrelationGroupIntercalibrationDown, &b_Jet_corr_CorrelationGroupIntercalibrationDown);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupbJESUp", Jet_corr_CorrelationGroupbJESUp, &b_Jet_corr_CorrelationGroupbJESUp);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupbJESDown", Jet_corr_CorrelationGroupbJESDown, &b_Jet_corr_CorrelationGroupbJESDown);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupFlavorUp", Jet_corr_CorrelationGroupFlavorUp, &b_Jet_corr_CorrelationGroupFlavorUp);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupFlavorDown", Jet_corr_CorrelationGroupFlavorDown, &b_Jet_corr_CorrelationGroupFlavorDown);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupUncorrelatedUp", Jet_corr_CorrelationGroupUncorrelatedUp, &b_Jet_corr_CorrelationGroupUncorrelatedUp);
   fChain->SetBranchAddress("Jet_corr_CorrelationGroupUncorrelatedDown", Jet_corr_CorrelationGroupUncorrelatedDown, &b_Jet_corr_CorrelationGroupUncorrelatedDown);
   fChain->SetBranchAddress("nFatjetCA15softdrop", &nFatjetCA15softdrop, &b_nFatjetCA15softdrop);
   fChain->SetBranchAddress("FatjetCA15softdrop_pt", FatjetCA15softdrop_pt, &b_FatjetCA15softdrop_pt);
   fChain->SetBranchAddress("FatjetCA15softdrop_eta", FatjetCA15softdrop_eta, &b_FatjetCA15softdrop_eta);
   fChain->SetBranchAddress("FatjetCA15softdrop_phi", FatjetCA15softdrop_phi, &b_FatjetCA15softdrop_phi);
   fChain->SetBranchAddress("FatjetCA15softdrop_mass", FatjetCA15softdrop_mass, &b_FatjetCA15softdrop_mass);
   fChain->SetBranchAddress("ntrgObjects_hltPFTripleJetLooseID64", &ntrgObjects_hltPFTripleJetLooseID64, &b_ntrgObjects_hltPFTripleJetLooseID64);
   fChain->SetBranchAddress("nLHE_weights_pdf", &nLHE_weights_pdf, &b_nLHE_weights_pdf);
   fChain->SetBranchAddress("LHE_weights_pdf_id", LHE_weights_pdf_id, &b_LHE_weights_pdf_id);
   fChain->SetBranchAddress("LHE_weights_pdf_wgt", LHE_weights_pdf_wgt, &b_LHE_weights_pdf_wgt);
   fChain->SetBranchAddress("ntrgObjects_caloMhtNoPU", &ntrgObjects_caloMhtNoPU, &b_ntrgObjects_caloMhtNoPU);
   fChain->SetBranchAddress("trgObjects_caloMhtNoPU_pt", trgObjects_caloMhtNoPU_pt, &b_trgObjects_caloMhtNoPU_pt);
   fChain->SetBranchAddress("nGenLep", &nGenLep, &b_nGenLep);
   fChain->SetBranchAddress("GenLep_charge", GenLep_charge, &b_GenLep_charge);
   fChain->SetBranchAddress("GenLep_status", GenLep_status, &b_GenLep_status);
   fChain->SetBranchAddress("GenLep_isPromptHard", GenLep_isPromptHard, &b_GenLep_isPromptHard);
   fChain->SetBranchAddress("GenLep_pdgId", GenLep_pdgId, &b_GenLep_pdgId);
   fChain->SetBranchAddress("GenLep_pt", GenLep_pt, &b_GenLep_pt);
   fChain->SetBranchAddress("GenLep_eta", GenLep_eta, &b_GenLep_eta);
   fChain->SetBranchAddress("GenLep_phi", GenLep_phi, &b_GenLep_phi);
   fChain->SetBranchAddress("GenLep_mass", GenLep_mass, &b_GenLep_mass);
   fChain->SetBranchAddress("GenLep_motherId", GenLep_motherId, &b_GenLep_motherId);
   fChain->SetBranchAddress("GenLep_grandmotherId", GenLep_grandmotherId, &b_GenLep_grandmotherId);
   fChain->SetBranchAddress("GenLep_sourceId", GenLep_sourceId, &b_GenLep_sourceId);
   fChain->SetBranchAddress("nGenGluonFromTop", &nGenGluonFromTop, &b_nGenGluonFromTop);
   fChain->SetBranchAddress("GenGluonFromTop_pdgId", GenGluonFromTop_pdgId, &b_GenGluonFromTop_pdgId);
   fChain->SetBranchAddress("GenGluonFromTop_pt", GenGluonFromTop_pt, &b_GenGluonFromTop_pt);
   fChain->SetBranchAddress("GenGluonFromTop_eta", GenGluonFromTop_eta, &b_GenGluonFromTop_eta);
   fChain->SetBranchAddress("GenGluonFromTop_phi", GenGluonFromTop_phi, &b_GenGluonFromTop_phi);
   fChain->SetBranchAddress("GenGluonFromTop_mass", GenGluonFromTop_mass, &b_GenGluonFromTop_mass);
   fChain->SetBranchAddress("GenGluonFromTop_charge", GenGluonFromTop_charge, &b_GenGluonFromTop_charge);
   fChain->SetBranchAddress("GenGluonFromTop_status", GenGluonFromTop_status, &b_GenGluonFromTop_status);
   fChain->SetBranchAddress("GenGluonFromTop_isPromptHard", GenGluonFromTop_isPromptHard, &b_GenGluonFromTop_isPromptHard);
   fChain->SetBranchAddress("nsoftActivityJets", &nsoftActivityJets, &b_nsoftActivityJets);
   fChain->SetBranchAddress("softActivityJets_pt", softActivityJets_pt, &b_softActivityJets_pt);
   fChain->SetBranchAddress("softActivityJets_eta", softActivityJets_eta, &b_softActivityJets_eta);
   fChain->SetBranchAddress("softActivityJets_phi", softActivityJets_phi, &b_softActivityJets_phi);
   fChain->SetBranchAddress("softActivityJets_mass", softActivityJets_mass, &b_softActivityJets_mass);
   fChain->SetBranchAddress("nFatjetCA15subjetfiltered", &nFatjetCA15subjetfiltered, &b_nFatjetCA15subjetfiltered);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_pt", FatjetCA15subjetfiltered_pt, &b_FatjetCA15subjetfiltered_pt);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_eta", FatjetCA15subjetfiltered_eta, &b_FatjetCA15subjetfiltered_eta);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_phi", FatjetCA15subjetfiltered_phi, &b_FatjetCA15subjetfiltered_phi);
   fChain->SetBranchAddress("FatjetCA15subjetfiltered_mass", FatjetCA15subjetfiltered_mass, &b_FatjetCA15subjetfiltered_mass);
   fChain->SetBranchAddress("ntrgObjects_hltSingleJet80", &ntrgObjects_hltSingleJet80, &b_ntrgObjects_hltSingleJet80);
   Notify();
}

Bool_t skim_trees_macro_breg::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void skim_trees_macro_breg::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t skim_trees_macro_breg::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef skim_trees_macro_breg_cxx

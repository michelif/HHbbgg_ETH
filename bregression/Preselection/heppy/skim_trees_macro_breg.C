#define skim_trees_macro_breg_cxx
#include "skim_trees_macro_breg.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void skim_trees_macro_breg::Loop(TString filename)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
	std::cout<<nentries<<endl;

   Long64_t nbytes = 0, nb = 0;



	fChain->SetBranchStatus("*",0);



	fChain->SetBranchStatus("nJet",1);
   fChain->SetBranchStatus("genWeight",1.);
	fChain->SetBranchStatus("nTrueInt",1);
	fChain->SetBranchStatus("nPU0",1);
	fChain->SetBranchStatus("nPVs",1);
	fChain->SetBranchStatus("isData",1);
	fChain->SetBranchStatus("xsec",1);
   fChain->SetBranchStatus("Jet_pt",1.);
   fChain->SetBranchStatus("Jet_eta",1.);
   fChain->SetBranchStatus("Jet_phi",1.);
	fChain->SetBranchStatus("Jet_mass",1.);
	fChain->SetBranchStatus("Jet_btagCMVAV2*",1.);
	fChain->SetBranchStatus("Jet_id",1.);
	fChain->SetBranchStatus("Jet_puId",1.);
   fChain->SetBranchStatus("Jet_qgl",1.);
	fChain->SetBranchStatus("json",1.);
	fChain->SetBranchStatus("EX_MUON",1.);

	fChain->SetBranchStatus("HLT_BIT_HLT_IsoMu22*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoMu22_eta2p1*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoTkMu22*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoMu24*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoTkMu24*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoMu27*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_IsoTkMu27*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_Mu24_eta2p1*",1.);
	fChain->SetBranchStatus("HLT_BIT_HLT_TkMu24_eta2p1*",1.);
 	fChain->SetBranchStatus("HLT_BIT_HLT_*Mu*Mu*",1);

///////////////////for normal workflow////////////////not trigger////
   //fChain->SetBranchStatus("*",1.);

	fChain->SetBranchStatus("V_*",1.);
	fChain->SetBranchStatus("nGenVbosons",1.);
	fChain->SetBranchStatus("GenVbosons_pt",1.);
	fChain->SetBranchStatus("GenVbosons_eta",1.);
	fChain->SetBranchStatus("GenVbosons_phi",1.);
	fChain->SetBranchStatus("GenVbosons_mass",1.);
	fChain->SetBranchStatus("GenVbosons_pdgId",1.);
	fChain->SetBranchStatus("*selLeptons*",1.);
   fChain->SetBranchStatus("Jet_corr",1.);
   fChain->SetBranchStatus("Jet_corr_JECUp",1.);
   fChain->SetBranchStatus("Jet_corr_JECDown",1.);
   fChain->SetBranchStatus("Jet_corr_JER",1.);
   fChain->SetBranchStatus("Jet_corr_JERUp",1.);
   fChain->SetBranchStatus("Jet_corr_JERDown",1.);
   fChain->SetBranchStatus("Jet_leadTrackPt",1.);
   fChain->SetBranchStatus("Jet_leptonPtRel",1.);
   fChain->SetBranchStatus("Jet_leptonPt",1.);
   fChain->SetBranchStatus("Jet_leptonDeltaR",1.);
   fChain->SetBranchStatus("Jet_neHEF",1.);
   fChain->SetBranchStatus("Jet_neEmEF",1.);
   fChain->SetBranchStatus("Jet_chHEF",1.);
   fChain->SetBranchStatus("Jet_chEmEF",1.);
   fChain->SetBranchStatus("Jet_muEF",1.);
   fChain->SetBranchStatus("Jet_vtxPt",1.);
   fChain->SetBranchStatus("Jet_vtxMass",1.);
   fChain->SetBranchStatus("Jet_vtx3DVal",1.);
   fChain->SetBranchStatus("Jet_vtxNtracks",1.);
   fChain->SetBranchStatus("Jet_vtx3DSig",1.);
   fChain->SetBranchStatus("Jet_pt*",1.);
   fChain->SetBranchStatus("btagWeightCMVAV2*",1.);
   fChain->SetBranchStatus("Jet_ptd",1.);
   fChain->SetBranchStatus("Jet_axis2",1.);
   fChain->SetBranchStatus("Jet_mult",1.);
   fChain->SetBranchStatus("met*",1.);
   fChain->SetBranchStatus("met_pt",1.);
   fChain->SetBranchStatus("met_phi",1.);
   fChain->SetBranchStatus("met_sumEt",1.);
   fChain->SetBranchStatus("met_shifted_JetEnUp_pt",1.);
   fChain->SetBranchStatus("met_shifted_JetEnDown_pt",1.);
   fChain->SetBranchStatus("lumi",1.);
   fChain->SetBranchStatus("xsec",1.);
   fChain->SetBranchStatus("evt*",1.);
   fChain->SetBranchStatus("run*",1.);
   fChain->SetBranchStatus("puWeight*",1.);
   fChain->SetBranchStatus("json_silver",1.);
   fChain->SetBranchStatus("Vtype",1.);
   fChain->SetBranchStatus("VtypeSim",1.);
	fChain->SetBranchStatus("rho*",1.);
	fChain->SetBranchStatus("*GenBQuarkFromH*",1.);
	fChain->SetBranchStatus("*GenBQuarkFromTop*",1.);
	fChain->SetBranchStatus("Jet_*Flavour",1.);
	fChain->SetBranchStatus("Jet_mcMatchId",1.);
	fChain->SetBranchStatus("Jet_mc*",1.);
	fChain->SetBranchStatus("Jet_rawPt",1.);
	fChain->SetBranchStatus("LHE*",1.);
	fChain->SetBranchStatus("lhe*",1.);
	fChain->SetBranchStatus("nLHE*",1.);
	fChain->SetBranchStatus("nGenNu",1.);
	fChain->SetBranchStatus("GenNu*",1.);
	fChain->SetBranchStatus("nGenJet",1.);
	fChain->SetBranchStatus("GenJet_pt",1.);
	fChain->SetBranchStatus("GenJet_eta",1.);
	fChain->SetBranchStatus("GenJet_phi",1.);
	fChain->SetBranchStatus("GenJet_mass",1.);
	fChain->SetBranchStatus("GenJet_pdgId",1.);
	fChain->SetBranchStatus("GenJet_numBHadrons",1.);
	fChain->SetBranchStatus("GenJet_numCHadrons",1.);
	fChain->SetBranchStatus("GenJet_isPromptHard",1.);
	fChain->SetBranchStatus("nGenTop",1.);
	fChain->SetBranchStatus("GenTop_pt",1.);
	fChain->SetBranchStatus("GenTop_eta",1.);
	fChain->SetBranchStatus("GenTop_phi",1.);
	fChain->SetBranchStatus("GenTop_mass",1.);
	fChain->SetBranchStatus("GenTop_decayMode",1.);
	fChain->SetBranchStatus("nGenHiggsBoson",1.);
	fChain->SetBranchStatus("GenHiggsBoson_pt",1.);
	fChain->SetBranchStatus("GenHiggsBoson_phi",1.);
	fChain->SetBranchStatus("GenHiggsBoson_eta",1.);
	fChain->SetBranchStatus("GenHiggsBoson_mass",1.);
	fChain->SetBranchStatus("GenHiggsBoson_isPromptHard",1.);
	fChain->SetBranchStatus("Jet_numDaughters_pt03",1.);
	fChain->SetBranchStatus("Jet_energyRing*",1.);
	fChain->SetBranchStatus("Jet_rawEnergy*",1.);
	fChain->SetBranchStatus("Jet_numberOfDaughters",1.);
	fChain->SetBranchStatus("GenJet_wNu*",1.);
	fChain->SetBranchStatus("Jet_mcIdx",1.);

//	fChain->SetBranchStatus(,1.);
//	fChain->SetBranchStatus(,1.);


/////////////////////////////////////////


	std::cout<<filename<<endl;
	TFile *output = TFile::Open(filename,"recreate");
	TTree *tree = fChain->CloneTree(0);
	
	Float_t looser_cuts_coef = 0.9;	

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
  // for (Long64_t jentry=0; jentry<10;jentry++) {
	   Long64_t ientry = LoadTree(jentry);
	 //  if (ientry < 0) break;
	   nb = fChain->GetEntry(jentry);   nbytes += nb;


	if (nJet<1) continue;
	int count =0;	
	TLorentzVector jet1, jet2;
   for (int i=0;i<nJet;i++){
		if (!((Jet_id[i]>2) && (Jet_puId[i]>0) && (TMath::Abs(Jet_eta[i]) < 2.5) )) continue;
		count++;
		if (count>=1)  break;
	}
	if (count<1) continue;
	if (nselLeptons<2) continue;
	int count_leptons=0;
	for (int i=0; i<nselLeptons;i++ ){
		if (!((TMath::Abs(selLeptons_pdgId[i])==13) && (TMath::Abs(selLeptons_eta[i])<2.5) )) continue;
		count_leptons++;
		if (count_leptons>=2)  break;
	}
	if (count_leptons<2) continue;
//////////////////////////////////////////////////////

		tree->Fill();		

	}  
	output->cd();
	tree->AutoSave();
	Count->Write();
	CountPosWeight->Write();
	CountNegWeight->Write();
	CountWeighted->Write();
	CountFullWeighted->Write();
	CountWeightedLHEWeightScale->Write();
	CountWeightedLHEWeightPdf->Write();
	output->Close();
	delete output;
	
}


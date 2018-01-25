#define macro_breg_cxx
#include "macro_breg.h"
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

void macro_breg::Loop(TString filename)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
	std::cout<<nentries<<endl;

   Long64_t nbytes = 0, nb = 0;

/////////////////////////////////////////

	std::cout<<filename<<endl;
	TFile *output = TFile::Open(filename,"recreate");
	TTree *tree = fChain->CloneTree(0);
	////new Branches//////
	TBranch *branchLeadingJet_idx;
	TBranch *branchSubLeadingJet_idx;
	TBranch *branchLeadingLep_idx;
	TBranch *branchSubLeadingLep_idx;
	TBranch *branchZll_mass;
	TBranch *branchZll_pt;
	TBranch *branchDiJet_mass;
	TBranch *branchDiJet_pt;
	int leadJet_idx=0;
	int subleadJet_idx=0;
	int leadLep_idx=0;
	int subleadLep_idx=0;
	Float_t Zll_pt = 0;
	Float_t Zll_mass = 0;
	Float_t DiJet_pt = 0;
	Float_t DiJet_mass = 0;
	branchLeadingJet_idx = tree->Branch("leadJet_idx",&leadJet_idx,"leadJet_idx/I");
	branchSubLeadingJet_idx = tree->Branch("subleadJet_idx",&subleadJet_idx,"subleadJet_idx/I");
	branchLeadingLep_idx = tree->Branch("leadLep_idx",&leadLep_idx,"leadLep_idx/I");
	branchSubLeadingLep_idx = tree->Branch("subleadLep_idx",&subleadLep_idx,"subleadLep_idx/I");
	branchZll_mass = tree->Branch("Zll_mass",&Zll_mass,"Zll_mass/F");
	branchZll_pt = tree->Branch("Zll_pt",&Zll_pt,"Zll_pt/F");
	branchDiJet_mass = tree->Branch("DiJet_mass",&DiJet_mass,"DiJet_mass/F");
	branchDiJet_pt = tree->Branch("DiJet_pt",&DiJet_pt,"DiJet_pt/F");
	
	Float_t looser_cuts_coef = 0.9;	

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
  // for (Long64_t jentry=0; jentry<10;jentry++) {
	   Long64_t ientry = LoadTree(jentry);
	 //  if (ientry < 0) break;
	   nb = fChain->GetEntry(jentry);   nbytes += nb;
	
	if (nselLeptons<2) continue;
		if (met_pt<30) continue;
		int idx_1stLepton = 0;
		int idx_2ndLepton = 0;
		TLorentzVector lepton1;
		TLorentzVector lepton2;
		TLorentzVector Zll;
		int count_l=0;
		for (int i=0; i<nselLeptons;i++ ){
			if (!((selLeptons_looseIdPOG[i]>0) && (selLeptons_relIso04[i]<0.25) && (TMath::Abs(selLeptons_pdgId[i])==13 ) && (TMath::Abs(selLeptons_eta[i])<2.4) ) ) continue;
	//		if ((count_l==1) && (selLeptons_charge[idx_1stLepton]*selLeptons_charge[i] > 0)) continue;
			if (count_l==1) {
				idx_2ndLepton=i;
				lepton2.SetPtEtaPhiM(selLeptons_pt[idx_2ndLepton], selLeptons_eta[idx_2ndLepton], selLeptons_phi[idx_2ndLepton], selLeptons_mass[idx_2ndLepton]);
				count_l++;
				break;
			}
			if (count_l==0) {
				idx_1stLepton=i;
				lepton1.SetPtEtaPhiM(selLeptons_pt[idx_1stLepton], selLeptons_eta[idx_1stLepton], selLeptons_phi[idx_1stLepton], selLeptons_mass[idx_1stLepton]);
				count_l++;
			}
		}	
		if (count_l<2)  continue;
		if ((selLeptons_charge[idx_1stLepton]*selLeptons_charge[idx_2ndLepton])>0) continue;
		leadLep_idx=idx_1stLepton;
		subleadLep_idx=idx_2ndLepton;
	//	if (TMath::Abs(selLeptons_eta[leadLep_idx])>2.4) continue;	
	//	if (TMath::Abs(selLeptons_eta[subleadLep_idx])>2.4) continue;
		if (selLeptons_pt[leadLep_idx] < 20) continue;	
		if (selLeptons_pt[subleadLep_idx] < 20) continue;
		Zll = lepton1+lepton2;	
		Zll_pt = Zll.Pt();
		Zll_mass = Zll.M();
		if (Zll_mass < 10 ) continue;
		if ((Zll_mass < 120 ) && (Zll_mass >75)) continue;

///////////////Jet//////////////////
	if (nJet<2) continue;
	int good_jets = 0;
	vector<TLorentzVector> jets_pv;
	vector<int> jets_indices;
	for (int i=0;i<nJet;i++){
		TLorentzVector jet0;
		if (!((Jet_id[i]>2)&&(Jet_puId[i]>0))) continue;
		jet0.SetPtEtaPhiM(Jet_pt[i],Jet_eta[i],Jet_phi[i],Jet_mass[i]);
		jets_pv.push_back(jet0);
		jets_indices.push_back(i);
		good_jets++;
	}
	if (good_jets<2) continue;
	leadJet_idx = jets_indices[0];
	subleadJet_idx=jets_indices[1];
	if (jets_pv[0].Pt() < 30) continue;
	if (jets_pv[1].Pt() < 30) continue;
	if (TMath::Abs(jets_pv[0].Eta()) > 2.5) continue;
	if (TMath::Abs(jets_pv[1].Eta()) > 2.5) continue;
	if (Jet_btagCMVAV2[leadJet_idx] < -0.5884) continue;
	if (Jet_btagCMVAV2[subleadJet_idx] < -0.5884) continue;
	TLorentzVector qq = jets_pv[0]+jets_pv[1];
	DiJet_mass = qq.M();
	DiJet_pt = qq.Pt();
	

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


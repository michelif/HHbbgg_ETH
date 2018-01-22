import ROOT
from ROOT import TFile, TTree, gStyle, TF1, gROOT
import plotting_utils as plotting
reload(plotting)
import pandas as pd
import root_pandas as rpd
import numpy as np

gROOT.SetBatch(True)
gROOT.ProcessLineSync(".x /afs/cern.ch/work/n/nchernya/Hbb/setTDRStyle.C")
gROOT.ForceStyle()
gStyle.SetPadTopMargin(0.06)
gStyle.SetPadRightMargin(0.04)
gStyle.SetPadLeftMargin(0.15)

name="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/root_files/heppy_05_10_2017/ttbar_RegressionPerJet_heppy_energyRings3_forTraining_LargeAll.root"
f = TFile.Open(name, "read")

t = f.Get("tree")
hist = ROOT.TH1F("hist","hist",100,0,1500)
hist_ratio = ROOT.TH1F("hist_ratio","hist_ratio",100,0,1500)
c = ROOT.TCanvas("c","c",600,600)
c.SetLogy()
c.SetBottomMargin(0.3)
cuts='(Jet_pt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcPt>0) & (Jet_mcPt<6000)'
t.Draw("Jet_pt>>hist",cuts)
xmin=0
xmax=1500
frame = ROOT.TH1F("hframe", "hframe", 1000, xmin,xmax)
frame.SetStats(0)
frame.GetXaxis().SetLabelSize(0)
frame.GetXaxis().SetTitleOffset(0.91);
frame.GetYaxis().SetTitle("Events")
frame.GetYaxis().SetLabelSize(0.04)
frame.GetYaxis().SetRangeUser(1e-01,hist.GetMaximum()*1.2)
frame.Draw()
hist.Draw("same")
func_w = TF1("func","expo",0,2000)
func_w.FixParameter(0,1.23547e+01)
func_w.FixParameter(1,-0.83230e-02)

pad2 = ROOT.TPad("pad2", "pad2", 0., 0., 1., 1.)
pad2.SetTopMargin(0.73)
pad2.SetFillColor(0)
pad2.SetFillStyle(0)
pad2.Draw()
pad2.cd()
frame2 = ROOT.TH1F("frame2","",1,xmin,xmax)
frame2.SetMinimum(-10)	
frame2.SetMaximum(20) 
frame2.GetYaxis().SetLabelSize(0.02)
frame2.GetXaxis().SetLabelSize(0.04)
frame2.GetYaxis().SetTitleSize(0.04)
frame2.GetXaxis().SetTitle("p_{T}")
frame2.SetStats(0)
frame2.GetYaxis().SetTitle("Jet_pt/func")	
frame2.Draw()

for i in range(1,hist.GetNbinsX()+1):
	hist_ratio.SetBinContent(i,hist.GetBinContent(i)/func_w.Eval(hist.GetBinCenter(i)))

hist_ratio.Draw("same")

c.SaveAs("../plots/fit_exp_pt_final.png")



#branch_names = 'Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,rho,nPVs,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_numDaughters_pt03,noexpand:Jet_energyRing_dR0_em/Jet_e,noexpand:Jet_energyRing_dR1_em/Jet_e,noexpand:Jet_energyRing_dR2_em/Jet_e,noexpand:Jet_energyRing_dR3_em/Jet_e,noexpand:Jet_energyRing_dR4_em/Jet_e,noexpand:Jet_energyRing_dR0_neut/Jet_e,noexpand:Jet_energyRing_dR1_neut/Jet_e,noexpand:Jet_energyRing_dR2_neut/Jet_e,noexpand:Jet_energyRing_dR3_neut/Jet_e,noexpand:Jet_energyRing_dR4_neut/Jet_e,noexpand:Jet_energyRing_dR0_ch/Jet_e,noexpand:Jet_energyRing_dR1_ch/Jet_e,noexpand:Jet_energyRing_dR2_ch/Jet_e,noexpand:Jet_energyRing_dR3_ch/Jet_e,noexpand:Jet_energyRing_dR4_ch/Jet_e,noexpand:Jet_energyRing_dR0_mu/Jet_e,noexpand:Jet_energyRing_dR1_mu/Jet_e,noexpand:Jet_energyRing_dR2_mu/Jet_e,noexpand:Jet_energyRing_dR3_mu/Jet_e,noexpand:Jet_energyRing_dR4_mu/Jet_e'.split(",")
branch_names = 'noexpand:Jet_mcPt/Jet_pt,Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
branch_names = [c.strip() for c in branch_names]
data_frame = (rpd.read_root(name,"tree", columns = branch_names)) .query(cuts)
data_frame['weight'] = ( np.ones_like(data_frame.index)).astype(np.float32)
data_frame['weight'] = [func_w.Eval(row['Jet_pt'])/hist.GetBinContent(hist.FindBin(row['Jet_pt'])) for i, row in data_frame.iterrows()]
X_weights = data_frame['weight']	
for j in range(len(branch_names)):
#for j in range(0,1):
	if j == 0:
		X_features = data_frame[[branch_names[j].replace('noexpand:','')]]	
	else:
		X_features = np.concatenate([X_features,data_frame[[branch_names[j].replace('noexpand:','')]]],axis=1)

log_names='noexpand:Jet_mcPt/Jet_pt,Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
plotting.plot_input_variables_reg(X_features,branch_names,log_names,30,'weightedPt',X_weights)

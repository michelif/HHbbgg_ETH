import ROOT
from ROOT import TFile, TTree, gStyle
import plotting_utils as plotting
reload(plotting)
import pandas as pd
import root_pandas as rpd
import numpy as np

f = TFile.Open("/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/root_files/heppy_05_10_2017/ttbar_RegressionPerJet_heppy_energyRings3_forTraining_Large0.root", "read")
#f=TFile.Open(utils.IO.targetName[0])
name="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/root_files/heppy_05_10_2017/ttbar_RegressionPerJet_heppy_energyRings3_forTraining_Large0.root"

t = f.Get("tree")
hist = ROOT.TH1F("hist","hist",50,0,1000)
c = ROOT.TCanvas("c","c",600,600)
c.SetLogy()
cuts='(Jet_pt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_eta<2.4 & Jet_eta>-2.4) & (Jet_mcPt>0)& (Jet_mcPt<6000)'
t.Draw("Jet_pt>>hist",cuts)
frame = ROOT.TH1F("hframe", "hframe", 1000, 0, 1500)
frame.SetStats(0)
frame.GetXaxis().SetTitleOffset(0.91);
frame.GetYaxis().SetTitle("Events")
frame.GetXaxis().SetTitle("p_{T}")
frame.GetYaxis().SetLabelSize(0.04)
frame.GetYaxis().SetRangeUser(1e-01,hist.GetMaximum()*1.2)
frame.Draw()
hist.Draw("same")
#htmp = plotting.draw_overflow(hist,10)
#htmp.SetLineColor(ROOT.kRed)
#htmp.Draw("HISTsame")
#c.Draw()


c2 = ROOT.TCanvas("c2","c2",600,600)
hist2 = ROOT.TH1F("hist2","hist2",50,0,1000)
t.Draw("Jet_pt>>hist",cuts)
        
branch_names = 'Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt'.split(",")
branch_names = [c.strip() for c in branch_names]

print 'here'
data_frame = (rpd.read_root(name,"tree", columns = branch_names)) .query(cuts)
data_frame['weight'] = ( np.ones_like(data_frame.index)).astype(np.float32)
data_frame['weight'] = [1./hist.GetBinContent(hist.FindBin(row['Jet_pt'])) for i, row in data_frame.iterrows()]
#	if hist.GetBinContent(hist.FindBin(row['Jet_pt'])) == 0:
#		print hist.GetBinContent(hist.FindBin(row['Jet_pt']))
#		print hist.FindBin(row['Jet_pt'])
#		print row['Jet_pt']
X_weights = data_frame['weight']	
for j in range(len(branch_names)):
	if j == 0:
		X_features = data_frame[[branch_names[j].replace('noexpand:','')]]	
	else:
		X_features = np.concatenate([X_features,data_frame[[branch_names[j].replace('noexpand:','')]]],axis=1)

log_names='Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
plotting.plot_input_variables_reg(X_features,branch_names,log_names,30,'flatPt',X_weights)




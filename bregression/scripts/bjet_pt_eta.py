import ROOT
from ROOT import TFile, TTree, gStyle, TF1, gROOT

gROOT.SetBatch(True)
gROOT.ProcessLineSync(".x /afs/cern.ch/work/n/nchernya/Hbb/setTDRStyle.C")
gROOT.ForceStyle()
gStyle.SetPadTopMargin(0.06)
gStyle.SetPadRightMargin(0.04)
gStyle.SetPadLeftMargin(0.15)

what ='target'
what_name=''
if what=='Jet_pt' :  
	bins=100
	xmin=0
	xmax=1500
	what_name = 'p_{T} (GeV)'
if what=='Jet_eta' :
	bins=50
	xmin=-5
	xmax=5
	what_name = '#eta'
if what=='target' :
	what='Jet_mcPt/(Jet_pt*Jet_rawEnergy/Jet_e*Jet_corr)'
	bins=50
	xmin=0
	xmax=2
	what_name = 'target'


name="/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/root_files/heppy_05_10_2017/ttbar_RegressionPerJet_heppy_energyRings3_forTraining_LargeAll.root"
f = TFile.Open(name, "read")

t = f.Get("tree")
hist = ROOT.TH1F("hist","hist",bins,xmin,xmax)
hist.SetLineWidth(2)
c = ROOT.TCanvas("c","c",600,600)
#c.SetLogy()
#c.SetBottomMargin(0.3)
#cuts='(Jet_pt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcPt>0) & (Jet_mcPt<6000)'
cuts='(Jet_pt > 20) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt>0) & (Jet_mcPt<6000)'
t.Draw("%s>>hist"%what,cuts)
frame = ROOT.TH1F("hframe", "hframe", 1000, xmin,xmax)
frame.SetStats(0)
frame.GetXaxis().SetLabelSize(0.04)
frame.GetXaxis().SetTitle("%s"%what_name)
#frame.GetXaxis().SetTitleOffset(0.91);
frame.GetYaxis().SetTitle("Events")
frame.GetYaxis().SetLabelSize(0.04)
#frame.GetYaxis().SetRangeUser(1e-01,hist.GetMaximum()*10)
frame.GetYaxis().SetRangeUser(1e-01,hist.GetMaximum()*1.05)
frame.Draw()
hist.Draw("same")
c.SaveAs("../plots/bjet_spectrum_%s_v2.pdf"%what_name)


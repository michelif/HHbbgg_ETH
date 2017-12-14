import ROOT
from ROOT import TFile, TTree, gStyle, TF1, gROOT
import plotting_utils as plotting
reload(plotting)
import pandas as pd
import root_pandas as rpd

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
#func = TF1("func","expo",440,1500)
#func = TF1("func","expo",280,680)
func_w = TF1("func","expo",0,2000)
func_w.FixParameter(0,1.23547e+01)
func_w.FixParameter(1,-0.83230e-02)
func_w.Draw("same")
#func_w = TF1("func","expo",0,4000)
#func_w.FixParameter(0,func.GetParameter(0))
#func_w.FixParameter(1,func.GetParameter(1))
paveText2 = ROOT.TPaveText(0.6,0.75,0.9,.9,"NDC")
paveText2.SetTextFont(42)
paveText2.SetTextSize(0.04)
paveText2.SetFillStyle(-1)
paveText2.SetBorderSize(0)
paveText2.AddText("Exp fit")
paveText2.AddText("Const = %.5f"%func_w.GetParameter(0))
paveText2.AddText("Slope = %.5f"%func_w.GetParameter(1))
paveText2.Draw("same")

pad2 = ROOT.TPad("pad2", "pad2", 0., 0., 1., 1.)
pad2.SetTopMargin(0.73)
pad2.SetFillColor(0)
pad2.SetFillStyle(0)
pad2.SetLogy()
pad2.Draw()
pad2.cd()
frame2 = ROOT.TH1F("frame2","",1,xmin,xmax)
#frame2.SetMinimum(5e-02)	
#frame2.SetMaximum(20) 
frame2.SetMinimum(5e-03)	
frame2.SetMaximum(5) 
frame2.GetYaxis().SetLabelSize(0.02)
frame2.GetXaxis().SetLabelSize(0.04)
frame2.GetYaxis().SetTitleSize(0.04)
frame2.GetXaxis().SetTitle("p_{T}")
frame2.SetStats(0)
#frame2.GetYaxis().SetTitle("Jet_pt/func")	
frame2.GetYaxis().SetTitle("func/Jet_pt")	
frame2.Draw()

for i in range(1,hist.GetNbinsX()+1):
#	hist_ratio.SetBinContent(i,hist.GetBinContent(i)/func_w.Eval(hist.GetBinCenter(i)))
	res=1
	if	hist.GetBinContent(i)!=0:
		res = func_w.Eval(hist.GetBinCenter(i))/hist.GetBinContent(i)
		div = func_w.Eval(hist.GetBinCenter(hist.FindBin(400)))/hist.GetBinContent(hist.FindBin(400))
		if hist.GetBinCenter(i)>400 : 
			res =  func_w.Eval(hist.GetBinCenter(hist.FindBin(400)))/hist.GetBinContent(hist.FindBin(400))
	#	print i,res,func_w.Eval(hist.GetBinCenter(hist.FindBin(400)))/hist.GetBinContent(hist.FindBin(400))
#		print i,res
#		if hist.GetBinCenter(i)<50 : 
#			res = func_w.Eval(hist.GetBinCenter(hist.FindBin(50)))/hist.GetBinContent(hist.FindBin(50))
		res = res/div
	hist_ratio.SetBinContent(i,res)

hist_ratio.Draw("same")

fout = TFile.Open('../output_root/unweighting_hist_up.root', "recreate")
hist_ratio.Write()
fout.Close()

c.SaveAs("../plots/fit_exp_inverse_smooth.png")

import ROOT
from ROOT import TFile, TH1F, TCanvas, gROOT

cuts_0 = "(((Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut)/Jet_e)==0)&(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt<6000) & (Jet_mcPt>0)"
cuts_n0 = "(((Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut)/Jet_e)>0)&(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt<6000) & (Jet_mcPt>0)"
cuts_3 = "(((Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut)/Jet_e)>=0)&(Jet_pt > 20) & (Jet_eta<1.4 & Jet_eta>-1.4) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt<6000) & (Jet_mcPt>0)"
cuts_4 = "(((Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut)/Jet_e)>=0)&(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt<6000) & (Jet_mcPt>0)"


names = '(Jet_energyRing_dR0_em+Jet_energyRing_dR0_ch+Jet_energyRing_dR0_neut+Jet_energyRing_dR1_em+Jet_energyRing_dR1_ch+Jet_energyRing_dR1_neut)/Jet_e,Jet_pt,Jet_mcPt,Jet_eta,Jet_numberOfDaughters,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtx3deL,Jet_numDaughters_pt03'.split(",")
names = [c.strip() for c in names]
print names
n = len(names)
min_x = [0]*n
min_x[3] = -2.5
max_x = [1.,1500,1500,2.5,40,10,1000,300,40,0.15,200,8,12,250,40]
n_binx= [100]*n
n_binx[0] = 10000
all_hists_0=[]
all_hists_n0=[]
all_hists_0.append(TH1F("h0sum","h0sum",n_binx[0],min_x[0],max_x[0]))
all_hists_n0.append(TH1F("hsum","hsum",n_binx[0],min_x[0],max_x[0]))
for i in range(1,n):
	all_hists_0.append(TH1F("h0"+names[i],"h0"+names[i],n_binx[i],min_x[i],max_x[i]))
	all_hists_n0.append(TH1F("h"+names[i],"h"+names[i],n_binx[i],min_x[i],max_x[i]))


ifile = TFile("/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/root_files/heppy_05_10_2017/ttbar_RegressionPerJet_heppy_energyRings3_forTraining_LargeAll.root")
tree=ifile.Get("tree")

log_names='Jet_pt,Jet_mcPt,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonPt,Jet_leptonDeltaR'.split(",")
for i in range(0,len(names)):
	if i==0 : tree.Draw("%s>>%s"%(names[i],all_hists_0[i].GetName()),cuts_3)
	else : tree.Draw("%s>>%s"%(names[i],all_hists_0[i].GetName()),cuts_0)
	int_0 =  gROOT.FindObject(all_hists_0[i].GetName()).Integral()
#	if (i==2) : 
#		print int_0
#		print gROOT.FindObject(all_hists_0[i].GetName()).Integral(gROOT.FindObject(all_hists_0[i].GetName()).FindBin(-1.48),gROOT.FindObject(all_hists_0[i].GetName()).FindBin(1.48))
	gROOT.FindObject(all_hists_0[i].GetName()).SetLineColor(ROOT.kRed)	
	gROOT.FindObject(all_hists_0[i].GetName()).SetLineWidth(2)	
	gROOT.FindObject(all_hists_0[i].GetName()).Scale(1./int_0)
	gROOT.FindObject(all_hists_0[i].GetName()).GetXaxis().SetTitle(names[i])
	if i==0 : tree.Draw("%s>>%s"%(names[i],all_hists_n0[i].GetName()),cuts_4)
	else : tree.Draw("%s>>%s"%(names[i],all_hists_n0[i].GetName()),cuts_n0)
	int_n0 =  gROOT.FindObject(all_hists_n0[i].GetName()).Integral()
	gROOT.FindObject(all_hists_n0[i].GetName()).SetLineColor(ROOT.kBlue)	
	gROOT.FindObject(all_hists_n0[i].GetName()).SetLineStyle(2)	
	gROOT.FindObject(all_hists_n0[i].GetName()).SetLineWidth(2)	
	gROOT.FindObject(all_hists_n0[i].GetName()).Scale(1./int_n0)

	c = TCanvas("c"+str(i),"c"+str(i),600,600)
	if names[i] in log_names: c.SetLogy()
	gROOT.FindObject(all_hists_0[i].GetName()).Draw("HIST")
	gROOT.FindObject(all_hists_n0[i].GetName()).Draw("HISTsame")
	c.SaveAs("../plots/plot_%s.png"%(all_hists_n0[i].GetName()))	

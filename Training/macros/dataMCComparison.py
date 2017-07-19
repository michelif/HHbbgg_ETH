from ROOT import *

gROOT.ProcessLine(".L ~/setTDRStyle.C");
setTDRStyle()
gStyle.SetOptStat(0)

#Cut = "weight*(MVAOutput>0.40 && (Mgg<115 || Mgg>135) && (Mjj<100 || Mjj>140))"
Cut = "weight*((Mgg<115 || Mgg>135) )"
cut = TCut(Cut)

path="/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/outfiles/20170711/"

_file0 = TFile.Open(path+"DoubleEG_preselection.root");
_file1 = TFile.Open(path+"GJet_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8_preselection.root");
_file2 = TFile.Open(path+"DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa_preselection.root");

data_tree =  _file0.Get("reducedTree");
bkg_1_tree =  _file1.Get("reducedTree");
bkg_2_tree =  _file2.Get("reducedTree");
 

data_tree.Draw("Mgg>>h_data(80,100,180)",cut);
bkg_1_tree.Draw("Mgg>>h_bkg_1(80,100,180)",cut);
bkg_2_tree.Draw("Mgg>>h_bkg_2(80,100,180)",cut);

h_data.SetMarkerStyle(20)
h_data.GetXaxis().SetTitle("M(#gamma#gamma) [GeV]")
h_data.SetMarkerSize(0.8)
h_data.SetMarkerColor(1)
h_data.SetLineColor(1)
h_data.SetLineWidth(2)


h_bkg_1.SetFillColor(kRed);
h_bkg_1.SetLineColor(kRed);

h_bkg_2.SetFillColor(kBlue);
h_bkg_2.SetLineColor(kBlue);


hs = THStack("hs","");
hs.Add(h_bkg_1);
hs.Add(h_bkg_2);

gJetInt=h_bkg_1.Integral()
diphoInt=h_bkg_2.Integral()
dataInt=h_data.Integral()

print "gJet integral: "+str(gJetInt)
print "diphoton integral: "+str(diphoInt)
print "data integral: "+str(dataInt)

print "ratio data/MC: "+str(dataInt/(gJetInt+diphoInt)) 

legend = TLegend(0.6,0.7,0.9,0.9);
textFont = 43
textSize = 16
legend.SetFillStyle(0)
legend.SetLineWidth(0)
legend.SetBorderSize(0)
legend.SetTextFont(textFont)
legend.SetTextSize(textSize)
legend.AddEntry(h_bkg_1,"j#gamma+jets","f")
legend.AddEntry(h_bkg_2,"#gamma#gamma+jets","f")
legend.AddEntry(h_data,"Data","ep")


#h_bkg_1.Print();

h_data.GetYaxis().SetRangeUser(0.1,6100)

h_data.Draw("p");
hs.Draw("samehist");
h_data.Draw("epsame");
gPad.RedrawAxis();
legend.Draw("same")

c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg.pdf")
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg.png")

Cut_MVA=Cut+"*(MVAOutput>0.40 && (Mjj<100 || Mjj>140))"
cut = TCut(Cut_MVA)

print cut

data_tree.Draw("Mgg>>h_data_Cut(80,100,180)",cut);
bkg_1_tree.Draw("Mgg>>h_bkg_1_Cut(80,100,180)",cut);
bkg_2_tree.Draw("Mgg>>h_bkg_2_Cut(80,100,180)",cut);

h_data_Cut.SetMarkerStyle(20)
h_data_Cut.GetXaxis().SetTitle("M(#gamma#gamma) [GeV]")
h_data_Cut.SetMarkerSize(0.8)
h_data_Cut.SetMarkerColor(1)
h_data_Cut.SetLineColor(1)
h_data_Cut.SetLineWidth(2)


h_bkg_1_Cut.SetFillColor(kRed);
h_bkg_1_Cut.SetLineColor(kRed);
       
h_bkg_2_Cut.SetFillColor(kBlue);
h_bkg_2_Cut.SetLineColor(kBlue);

hs = THStack("hs","");
hs.Add(h_bkg_1_Cut);
hs.Add(h_bkg_2_Cut);


gJetInt=h_bkg_1_Cut.Integral()
diphoInt=h_bkg_2_Cut.Integral()
dataInt=h_data_Cut.Integral()

print "####with MVA Cut####"
print "gJet integral: "+str(gJetInt)
print "diphoton integral: "+str(diphoInt)
print "data integral: "+str(dataInt)

print "ratio data/MC: "+str(dataInt/(gJetInt+diphoInt)) 

h_data_Cut.Draw("p");
hs.Draw("samehist");
h_data_Cut.Draw("epsame");

gPad.RedrawAxis();
legend.Draw("same")


c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA.pdf")
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA.png")

#scale factor to match data
h_bkg_1_Cut.Scale(1.3)
h_bkg_2_Cut.Scale(1.3)


#hs.Fit("expo")
f1 = TF1("f1","expo")
f1.SetLineColor(kBlack)
h_data_Cut.Fit(f1)
h_bkg_1_Cut.Add(h_bkg_2_Cut)
f2 = TF1("f2","expo")
f2.SetLineColor(kRed)
h_bkg_1_Cut.Fit(f2)


h_data_Cut.Draw("p");
h_bkg_1_Cut.Draw("samehist")
h_bkg_1_Cut.Draw("sameep")

f2.Draw("same")
h_data_Cut.Draw("epsame");

c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA_rescaled_fit.pdf")
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA_rescaled_fit.png")

print "not blinded Mjj"
Cut_MVA_notBlinded="weight*1.3*(MVAOutput>0.40 && (Mjj>100 && Mjj<140) && (Mgg<115 || Mgg>135))"
cut = TCut(Cut_MVA_notBlinded)

data_tree.Draw("Mgg>>h_data_fullSel(480,100,180)",cut)

f3 = TF1("f3","expo")
f3.SetLineColor(kRed)
h_data_fullSel.Fit(f3)

h_data_fullSel.Draw("ep")
f3.Draw("same")


c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA_rescaled_fit_fullSel.pdf")
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/dataMC_Mgg_MVA_rescaled_fit_fullSel.png")



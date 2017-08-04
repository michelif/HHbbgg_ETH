import ROOT

ROOT.gROOT.ProcessLine(".L ~/setTDRStyle.C");
ROOT.setTDRStyle()
ROOT.gStyle.SetOptStat(0)


#fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/outfiles/20170727_CR/")
fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/outfiles/")
tagDir=ROOT.TString("20170711_highMassCut")
#tagDir=ROOT.TString("20170727_CR_MXCut")
fileDir+=tagDir



processes = [
"GluGluToHHTo2B2G_node_SM_13TeV-madgraph_preselection.root",
"GluGluHToGG_M-125_13TeV_powheg_pythia8_preselection.root",
"VBFHToGG_M-125_13TeV_powheg_pythia8_preselection.root",
"VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_preselection.root",
"bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo_preselection.root",
"ttHToGG_M125_13TeV_powheg_pythia8_v2_preselection.root",
]

for proc in processes:
    _file0 = ROOT.TFile.Open(str(fileDir+ROOT.TString("/")+ROOT.TString(proc)))
    print str(fileDir+ROOT.TString("/")+ROOT.TString(proc))
    tree = _file0.Get("reducedTree")
    h_highMass = ROOT.TH1F("h_highMass","h_highMass",80,100,180)
    tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.92 && Mgg>123.5 && Mgg<126.5 && Mjj>100 && Mjj<140 && MX>350)")
#    tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.80 && Mgg>123.5 && Mgg<126.5 && Mjj>100 && Mjj<140 && MX<350)")
    print "#################################################"
    print proc
    print h_highMass.Integral()
    print "#################################################"

_file0 = ROOT.TFile.Open(str(fileDir+ROOT.TString("/DoubleEG_preselection.root")))
tree = _file0.Get("reducedTree")
h_highMass = ROOT.TH1F("h_highMass","h_highMass",32,100,180)
tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.92 && (Mgg<115 || Mgg>135) && Mjj>100 && Mjj<140 && MX>350)")
print "#################################################"
#h_highMass.Fit("expo")

reject = True
def fline(x, par):
    if reject and x[0] > 115 and x[0] < 135:
        ROOT.TF1.RejectPoint();
        return 0;

    return par[0] + par[1]*x[0] + par[2]*x[0]*x[0]


#f1 = ROOT.TF1("f1",ROOT.Math.ChebyshevPol(2),100,180,3)
f1 = ROOT.TF1("f1",fline,100,180,3)
h_highMass.Fit(f1)

c1=ROOT.TCanvas()
c1.cd()
h_highMass.Draw()
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/"+str(tagDir)+"_dataFit.pdf")
c1.SaveAs("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/plots/"+str(tagDir)+"_dataFit.png")

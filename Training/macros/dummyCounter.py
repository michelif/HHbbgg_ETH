import ROOT

fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH/outfiles/20170711/")

processes = [
"GluGluToHHTo2B2G_node_SM_13TeV-madgraph_preselection.root",
"GluGluHToGG_M-125_13TeV_powheg_pythia8_preselection.root",
"VBFHToGG_M-125_13TeV_powheg_pythia8_preselection.root",
"VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_preselection.root",
"bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo_preselection.root",
"ttHToGG_M125_13TeV_powheg_pythia8_v2_preselection.root",
"DoubleEG_preselection.root"
]

for proc in processes:
    _file0 = ROOT.TFile.Open(str(fileDir+ROOT.TString(proc)))
    tree = _file0.Get("reducedTree")
    h_highMass = ROOT.TH1F("h_highMass","h_highMass",80,100,180)
    tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.92 && Mgg>123.5 && Mgg<126.5 && Mjj>100 && Mjj<140 && MX>350)")
    print "#################################################"
    print proc
    print h_highMass.Integral()
    print "#################################################"

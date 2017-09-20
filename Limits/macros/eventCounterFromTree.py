import ROOT

#fileDir= ROOT.TString("files/20170828_optimizedCuts/Total_preselection_diffNaming.root")

fileDir= ROOT.TString("files/20170828_optimizedCuts_withDR_dijetMass/Total_preselection_diffNaming.root")

trees = [
"reducedTree_sig",
]
for i in range(2,14):
    trees.append("reducedTree_sig_node_"+str(i))

for i in range(0,8):
    if i == 1:
        continue
    trees.append("reducedTree_bkg_"+str(i))

_file0 = ROOT.TFile.Open(str(fileDir))


for tree in trees:
    tree = _file0.Get(tree)
    h_highMass = ROOT.TH1F("h_highMass","h_highMass",80,100,180)
#    tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.97 && Mgg>123.5 && Mgg<126.5 && Mjj>90 && Mjj<155 && MX>340)")
    tree.Project("h_highMass","Mgg","weight*(MVAOutput>0.984 && Mgg>123.5 && Mgg<126.5 && MX>340 && Mjj>75)")
    print "#################################################"
    print tree.GetName()+str(" ")+str(h_highMass.Integral())
    h_highMass.Delete()

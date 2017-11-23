import ROOT

#fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20170828_optimizedCuts/Total_preselection_diffNaming.root")
#fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20171002_BJetsSamples/Total_preselection_diffNaming.root")
#fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20171002_resH/Total_preselection_diffNaming.root")
#fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20171002_ttH/Total_preselection_diffNaming.root")
fileDir= ROOT.TString("/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20170828_optimizedCuts_ggH_ttH_reweight/Total_preselection_diffNaming.root")

processes = {}
trees = [
"reducedTree_sig",
]
processes["reducedTree_sig"] = str("SM")
for i in range(2,14):
    trees.append("reducedTree_sig_node_"+str(i))
    processes["reducedTree_sig_node_"+str(i)]=str("Sig_node_"+str(i))

for i in range(0,8):
    if i == 1:
        continue
    trees.append("reducedTree_bkg_"+str(i))
    
processes["reducedTree_bkg_0"]= str("Diphoton")
processes["reducedTree_bkg_2"]= str("GJets")
processes["reducedTree_bkg_3"]= str("ggH")
processes["reducedTree_bkg_4"]= str("VH")
processes["reducedTree_bkg_5"]= str("VBF")
processes["reducedTree_bkg_6"]= str("bbH")
processes["reducedTree_bkg_7"]= str("ttH")
processes["reducedTree_bkg_8"]= str("Data")

MXCat = [250,340,480,100000]
MVACat = [0.88,0.97,0.99,1.05]



_file0 = ROOT.TFile.Open(str(fileDir))

table = open(str(fileDir).replace("root","txt"),"w+")
for iMVA in range(0,len(MVACat)-1):
    table.write("-------------------\n")
    table.write("MVAOutput>"+str(MVACat[iMVA])+" && MVAOutput<"+str(MVACat[iMVA+1])+"\n")
    table.write("-------------------\n")
    for iMX in range(0,len(MXCat)-1):
        table.write("MX>"+ str(MXCat[iMX])+ " && MX<"+str(MXCat[iMX+1])+"\n")
        for tree in trees:
            Tree = _file0.Get(tree)
            h_highMass = ROOT.TH1F("h_highMass","h_highMass",80,100,180)
            print "weight*(MVAOutput>"+str(MVACat[iMVA])+" && MVAOutput<"+str(MVACat[iMVA+1])+" && Mgg>123.5 && Mgg<126.5 && Mjj>90 && Mjj<155 && MX>"+ str(MXCat[iMX])+ " && MX<"+str(MXCat[iMX+1])+str(")")
            Tree.Project("h_highMass","Mgg","weight*(MVAOutput>"+str(MVACat[iMVA])+" && MVAOutput<"+str(MVACat[iMVA+1])+" && Mgg>123.5 && Mgg<126.5 && Mjj>90 && Mjj<155 && MX>"+ str(MXCat[iMX])+ " && MX<"+str(MXCat[iMX+1])+str(")"))
            print "#################################################"
            print Tree.GetName()+str(" ")+str(h_highMass.Integral())
            integ = (h_highMass.Integral())
            if h_highMass.GetEntries() !=0:
                integ_err = ROOT.TMath.Sqrt(integ/h_highMass.GetEntries())
            else:
                integ_err = 0.
            h_highMass.Delete()
            table.write(processes[str(tree)]+": "+str(integ)+" +- "+str(integ_err)+"\n")
            
        table.write("-------------------\n")





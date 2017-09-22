import ROOT

fileDir= ROOT.TString("/eos/cms/store/group/phys_higgs/resonant_HH/RunII/LimitTrees/ForApproval_2016/LT_350_HMHPC_970_HMMPC_600_LMHPC_985_LMMPC_600_HighMass/")


processes = [
"LT_output_GluGluToHHTo2B2G_node_SM_13TeV-madgraph.root",
"LT_output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root",
"LT_output_VBFHToGG_M-125_13TeV_powheg_pythia8.root",
"LT_output_VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root",
"LT_output_bbHToGG_M-125_4FS_ybyt_13TeV_amcatnlo.root",
"LT_output_ttHToGG_M125_13TeV_powheg_pythia8_v2.root",
"LT_DoubleEG.root"
]



p=1
for proc in processes:
    _file0 = ROOT.TFile.Open(str(fileDir+ROOT.TString(proc)))
    oldtree = _file0.Get("TCVARS")
#    nentries = oldtree.GetEntries()
#    ROOT.Event *event   = 0
#    oldtree.SetBranchAddress("event",event)

    chain = ROOT.TChain(oldtree.GetName())

    
    newfile = ROOT.TFile(str("files/oldAnalysis_optimized_Mjj/WS/"+proc),"recreate")
    chain.Add(str(fileDir+ROOT.TString(proc)))
    
#    the_cut =ROOT.TString("mjj>100 && mjj<140 && HHTagger>0.6 && isSignal")
    the_cut =ROOT.TString("mjj>95 && mjj<155 && HHTagger>0.6 && isSignal")

    newtree = chain.CopyTree(the_cut.Data())
    print "Processed: "
    print proc
    if "SM" not in proc and "DoubleEG" not in proc:
        newtree.SetName("reducedTree_bkg_"+str(p+2))
        newtree.SetTitle("reducedTree_bkg_"+str(p+2))
        p+=1
    elif "DoubleEG" not in proc:
        newtree.SetName("reducedTree_sig")
        newtree.SetTitle("reducedTree_sig")
    else:   
        newtree.SetName("reducedTree_bkg")
        newtree.SetTitle("reducedTree_bkg")

    
#    newtree.Print()
    newtree.AutoSave()


import sys, types, os
from optparse import OptionParser, make_option
from  pprint import pprint
from array import array

# -----------------------------------------------------------------------------------------------------------
def main(options,args):

    ## setTDRStyle()
    ROOT.gStyle.SetOptStat(0)
        
    fin = ROOT.TFile.Open(options.file)
    tree = fin.Get("reducedTree_sig")


    for nameTagPos,s in enumerate(options.file.split("/")):
        print nameTagPos, s
        if "outfil" in s:
            nameTagPos += 1 
            break

    print nameTagPos
    name = options.file.split("/")[nameTagPos]



    fout = ROOT.TFile.Open("./plots/cumulatives/cumulativeTransformation_"+name+".root","recreate")

    nbins = 10000
    xlow = 0.
    xup = 1.
    histoMVA = ROOT.TH1F("histoMVA","histoMVA",nbins,xlow,xup)
    tree.Draw("MVAOutput>>histoMVA",ROOT.TCut("weight"))
#    histoMVA.FillRandom("gaus",1000000)

    cumulativeHisto = histoMVA.GetCumulative()
    cumulativeHisto.Scale(1./histoMVA.Integral())
    cumulativeGraph = ROOT.TGraph(cumulativeHisto)
    cumulativeGraph.SetTitle("cumulativeGraph")
    cumulativeGraph.SetName("cumulativeGraph")

    evalCumulatives = ROOT.TH1F("eval","eval",nbins/10,0,1)

    x , y = array( 'd' ), array( 'd' )
    step = (xup-xlow)/nbins
    for i in range(1,10000):
#        xvalue = ROOT.gRandom.Gaus()
        xvalue = ROOT.TH1.GetRandom(histoMVA)
        evalCumulatives.Fill(cumulativeGraph.Eval(xvalue))
    evalCumulatives.Sumw2()
    evalCumulatives.Scale(1./evalCumulatives.Integral())
    evalCumulatives.GetYaxis().SetRangeUser(0,2./evalCumulatives.GetNbinsX())

    c = ROOT.TCanvas()
    histoMVA.SetLineColor(ROOT.kRed)
    histoMVA.Draw()


    print name

    formats = [".png",".pdf"]

    for format in formats:
        c.SaveAs("./plots/cumulatives/"+name+"_func"+format)

    cumulativeGraph.Draw("AP")
    for format in formats:
        c.SaveAs("./plots/cumulatives/"+name+"_cum"+format)

    evalCumulatives.Draw("EP")
    for format in formats:
        c.SaveAs("./plots/cumulatives/"+name+"_evalx"+format)
    

    cumulativeGraph.Write()
    fout.Write()
    fout.Close()


    fin.cd()

    processes = [
        "reducedTree_sig",
        "reducedTree_bkg"
        ]

    for i in range(2,14):
        processes.append("reducedTree_sig_node_"+str(i))

    for i in range(0,8):
        if i == 1: continue
        processes.append("reducedTree_bkg_"+str(i))



    fin = ROOT.TFile.Open(options.file)

    fTransformed = ROOT.TFile.Open(options.file.replace(".root","")+"_transformedMVA.root","recreate")


    for proc in processes:
        print proc
        tree = fin.Get(proc)
        chain = ROOT.TChain(tree.GetName())
    
        chain.Add(options.file)
        copyTree = chain.CopyTree("")
        copyTree.SetName(proc)
        copyTree.SetTitle(proc)

        transfMVA = array( 'f', [ 0. ] )
        transfBranch = copyTree.Branch("MVAOutputTransformed",transfMVA,"MVAOutputTransformed/F");
        dummyList = []
        
        for i,event in enumerate(copyTree):
            if i>tree.GetEntries():break
            mva = event.MVAOutput
            transfMVA[0] = cumulativeGraph.Eval(mva)
            transfBranch.Fill()
    
    
    fTransformed.Write()
    fTransformed.Close()

        
if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-i", "--infile",
                        action="store", type="string", dest="file",
                        default="",
                        help="input file",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT
    
    main(options,args)
        

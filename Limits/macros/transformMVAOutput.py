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
    print evalCumulatives.Integral()
    evalCumulatives.Scale(1./evalCumulatives.Integral())
    print evalCumulatives.Integral()
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



    fin = ROOT.TFile.Open(options.file)
    tree = fin.Get("reducedTree_sig")
    chain = ROOT.TChain(tree.GetName())

    fTransformed = ROOT.TFile.Open(options.file.replace(".root","")+"transf.root","recreate")
    chain.Add(options.file)
    copyTree = chain.CopyTree("")

    transfMVA = array( 'f', [ 0. ] )
    transfBranch = copyTree.Branch("MVAOutputTransformed",transfMVA,"MVAOutputTransformed/F");
    dummyList = []
 
    copyTree.Print()
    for i,event in enumerate(copyTree):
        if i>tree.GetEntries():break
        mva = event.MVAOutput
        transfMVA[0] = cumulativeGraph.Eval(mva)
#        print mva,transfMVA
#        dummyList.append(transfMVA[0])
#        if len(dummyList)>1000:
#            break
        transfBranch.Fill()

    copyTree.Write()
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
        

#!/bin/env python

import sys, types, os
import json
import shutil

json.encoder.FLOAT_REPR = lambda o: format(o, '.3f')


from optparse import OptionParser, make_option
from  pprint import pprint
from array import array
from numpy import mean

# -----------------------------------------------------------------------------------------------------------
def main(options,args):

    ## setTDRStyle()
    ROOT.gStyle.SetOptStat(0)
    outDir = options.datacard.replace(".txt","")
    if not os.path.exists(outDir):
        os.mkdir(outDir)
    shutil.copy2(options.datacard,outDir)

    datacard = open(options.datacard,"r")
    linelist =  datacard.readlines()
    datacard.close()
    
    if options.doDatacards:
        for node in range(2,14):
            outDatacard = open(outDir+"/"+outDir+str("_node_"+str(node)+".txt"),"w+")
            for line in linelist:
                line = line.replace("cms_hgg:sig_","cms_hgg:sig_node_"+str(node)+"_")
                outDatacard.write(line)
    
            outDatacard.close()

    if options.doCombine:
        os.chdir(outDir)
        nameFile=str(options.datacard)
        outDirLimits = "./Limits/"
        if not os.path.exists(outDirLimits):
            os.mkdir(outDirLimits)
        os.system("combine -M Asymptotic "+nameFile+" -S 0 |grep \"Expected 50.0\"| awk '{print $5}' >"+outDirLimits+"lim_"+str(nameFile))  
        for node in range(2,14):
            nameFile = outDir+str("_node_"+str(node)+".txt")
            os.system("combine -M Asymptotic "+nameFile+" -S 0 |grep \"Expected 50.0\"| awk '{print $5}' >"+outDirLimits+"lim_"+str(nameFile))              

    if options.doPlots:
        limits = array('f')
        nodeIndex = array('f')
        if not options.doCombine:
            os.chdir(outDir)  
        outDirLimits = "./Limits/"
        outDirPlots = "./Plots"
        if not os.path.exists(outDirPlots):
            os.mkdir(outDirPlots)

        nameFile = outDirLimits+"lim_"+str(options.datacard)
        inFile = open(nameFile,"r")
        linelist =  inFile.readlines()
        inFile.close()
        limits.append(float(linelist[0]))
        nodeIndex.append(1)
        for node in range(2,14):
            nameFile = outDirLimits+"lim_"+outDir+str("_node_"+str(node)+".txt")
            inFile = open(nameFile,"r")
            linelist =  inFile.readlines()
            inFile.close()
            limits.append(float(linelist[0]))
            nodeIndex.append(node)

            
        outFile = ROOT.TFile.Open(outDirPlots+"/limitPlots.root","recreate")
        c1 = ROOT.TCanvas("c1");
        gr = ROOT.TGraph(len(limits),nodeIndex,limits)
        gr.SetName("Limit")
        gr.SetTitle("Limit")
        gr.GetXaxis().SetTitle( 'Node' )
        gr.GetYaxis().SetTitle( 'Limit' )
        gr.Draw()
        gr.GetXaxis().SetRangeUser(nodeIndex[0]-0.5,nodeIndex[len(nodeIndex)-1]+0.5)
        gr.GetYaxis().SetRangeUser(0.5,2.5)
        line = ROOT.TLine(nodeIndex[0]-0.5,mean(limits),nodeIndex[len(nodeIndex)-1]+0.5,mean(limits));
        line.SetLineColor(ROOT.kRed)
        line.Draw()
        print "x:"+str(nodeIndex[len(nodeIndex)-1]-1)
        print "y:"+str(mean(limits)+0.1)
        pt = ROOT.TText(nodeIndex[len(nodeIndex)-1]-1.6,mean(limits)+0.05,"Avg Limit: "+str("%.2f" % mean(limits)))
        pt.SetTextColor(ROOT.kRed)
#        pt.SetName("AvgLimit")
#        pt.SetTitle("AvgLimit")
        pt.SetTextSize(0.030);
        pt.SetTextFont(62);
#        pt.SetTextSize(0.04)
#        pt.SetTextFont(60)
        pt.Draw("same")
        pt.Write()
        gr.Write()
        line.Draw()
        c1.Write()
        c1.SaveAs(outDirPlots+"/limitVsNode.pdf")
        line.Write()
        outFile.Write()
        outFile.Close()
        
    

# -----------------------------------------------------------------------------------------------------------
if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-d", "--datacard",
                        action="store", type="string", dest="datacard",
                        default="",
                        help="input datacard",
                        ),
            make_option("-D", "--doDatacards",
                        action="store",type="int", dest="doDatacards",
                        default=True,
                        help="create datacards",
                        ),
            
            make_option("-c", "--doCombine",
                        action="store_true", dest="doCombine",
                        default=False,
                        help="compute limits with combine"
                        ),
            make_option("-p", "--doPlots",
                        action="store_true", dest="doPlots",
                        default=False,
                        help="do Limit Plots"
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    ## sys.argv.append("-b")

    pprint(options.__dict__)

    import ROOT
    
    main(options,args)


from ROOT import *
from array import array

import argparse
parser =  argparse.ArgumentParser(description='Add Classification BDT weights')
parser.add_argument('-f1', '--file1', dest='file1', required=True, type=str)
parser.add_argument('-f2', '--file2', dest='file2', required=True, type=str)
parser.add_argument('-o', '--output', dest='out', required=True, type=str)

opt = parser.parse_args()

_file1 = TFile.Open(opt.file1)
_file2 = TFile.Open(opt.file2)

roc1= _file1.Get("myROCTF1")
roc2= _file2.Get("myROCTF1")

roc2.SetLineColor(kBlue)

c1 = TCanvas()
roc1.Draw()
roc2.Draw("same")

outfile = TFile("plots/rocCurves/"+opt.out, "RECREATE")
c1.Write()
outfile.Close()

c1.SaveAs("plots/rocCurves/"+opt.out.replace(".root","")+"_rocComparison.png")

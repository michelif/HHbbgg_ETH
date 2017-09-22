#!/usr/bin/env python

# Standard python import
from optparse import OptionParser, make_option
import fnmatch, glob, os, sys, json, itertools, array
from pprint import pprint
#sys.argv.append( '-b' )
from ROOT import *
gROOT.SetBatch(True)
gROOT.ProcessLine(".L ~/setTDRStyle.C");
setTDRStyle()
gStyle.SetOptStat(0)

BDTbins=[]
weight = 'weight'
variables={}
savefmts=['.png','.root','.pdf','.jpg']

variables['Mgg']        = dict(name='mass',nbins=160,xmin=100.,xmax=180., xaxis="m_{#gamma #gamma}", line='', logy=0, logx=0)

# Main routine
def main(o,args):
    if 0 and options.files.startswith("/store"):
        filepath = "root://eoscms/"+str(options.files)
    else:
        filepath = options.files
    print 'filepath is '+str(filepath)
    infile = TFile.Open(filepath)
    defineBDTBins(infile)
    print BDTbins
    if not os.path.exists(options.outdir):
        os.mkdir(options.outdir)
    outfile = TFile(options.outdir+'/'+options.outfile, 'RECREATE')
    histos={}
    histos= getPlots(infile)
    #draw and save plots
    outfile.cd()
    for histo in histos:
        histo.Write()
        c = TCanvas('c','',1)
        histo.Draw('ehist')
        c.SetLogy(variables[str(histo.GetName()).split('_')[1]]['logy'])
        c.SetLogx(variables[str(histo.GetName()).split('_')[1]]['logx'])
        for fmt in savefmts:
            c.SaveAs(str(options.outdir)+'/'+str(histo.GetName())+str(fmt))

    outfile.Write()
    outfile.Close()



def defineBDTBins(infile):
    t=infile.Get(str(options.treename))
    hist = TH1D('h_bdt','h_bdt', 600, -1., 1.)
    hist.Sumw2()
    t.Project(hist.GetName(), options.quantileVar,str(weight))
    quant_x = [0., 0.20, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 0.95, 1.]
    quant_x_array = array.array('d', quant_x)
    quantiles_array = array.array('d',[0.0]*len(quant_x_array))
    nn = hist.GetQuantiles(len(quant_x_array), quantiles_array, quant_x_array)
    for i in range(len(quantiles_array)-1):
        couple = [quantiles_array[i],quantiles_array[i+1]]
        BDTbins.append(couple)


def getPlots(infile):
    plots=[]
    categories={}
    categories['sig']='classID==0'
    t=infile.Get(str(options.treename))
    #        t.Print()
    for variable in variables.keys():
        for bin in BDTbins:
            for cat in categories.keys():
                hist = TH1D('hist_'+str(variable)+'_'+str(cat)+'_BDT'+str(bin[0]).replace('.','').replace('-','m')+'to'+str(bin[1]).replace('.','').replace('-','m'),'hist_'+str(variable)+'_'+str(cat)+'_BDT'+str(bin[0]).replace('.','').replace('-','m')+'to'+str(bin[1]).replace('.','').replace('-','m'), variables[str(variable)]['nbins'], variables[str(variable)]['xmin'],variables[str(variable)]['xmax'])
                hist.Sumw2()
#            htemp = TH1D('htemp','htemp', variables[str(variable)]['nbins'], variables[str(variable)]['xmin'],variables[str(variable)]['xmax'])
                cut = str(weight)+'*('+options.quantileVar+' >'+str(bin[0])+' && '+options.quantileVar+'<= '+str(bin[1])+')'
                print cut
                t.Project(hist.GetName(), str(variable), str(cut))
                hist.GetXaxis().SetTitle(str(variables[str(variable)]['xaxis']))
                print hist.GetEntries()
            #TLatex
                plots.append(hist)
    return plots



## ------------------------------------------------------------------------------------------------------------------------------------------------------    
if __name__ == "__main__":
    parser = OptionParser(option_list=[
            make_option("-f", "--files",
                        action="store", type="string", dest="files",
                        default="tmvadiPho_Moriond17.root",
                        help="pattern of files to be read", metavar="PATTERN"
                        ), 
            make_option("-t", "--treeName",
                        action="store", type="string", dest="treename",
                        default="reducedTree_sig",
                        help="TTree name", metavar="TREENAME"
                        ),
            make_option("-o", "--outfile",
                        action="store", type="string", dest="outfile",
                        default="tmvaPlots_Moriond17_noQCD.root",
                        help="outputfile", metavar="FILE"
                        ),
            make_option("-D", "--outputdir",
                        action="store_true", dest="outdir",
                        default="plots",
                        ),
            make_option("-q", "--quantileVar",
                        action="store", type="string", dest="quantileVar",
                        default="MVAOutput",
                        help="Variable to define quantile",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()

#    sys.argv.append("-b")
    pprint(options.__dict__)

#    import ROOT
    sys.argv.append("-b")
    main(options, args)




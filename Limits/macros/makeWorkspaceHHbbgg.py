#!/bin/env python

import sys, types, os
sys.path.append("~/HHbbgg_ETH_devel/Training/python") # to load packages
#import numpy
from math import sqrt, log
import json
json.encoder.FLOAT_REPR = lambda o: format(o, '.3f')

## from plotVbfVar import *

from optparse import OptionParser, make_option
from  pprint import pprint

objs = []
pdfName = []
pdfNorm = {}

##
def mkcheb(ord,cat,label,ws,var="CMS_hgg_mass"):
    norms = []
    pdfs = []
    for i in range(ord):
        norm = ws.factory("cheb%d_coeff%d_%scat%d[1,-1,10.]" % (ord,i,label,cat) )
        norm.setVal(1./float(i+1))
        objs.append(norm)
        norms.append(norm)

    names = {
        "label" : label,
        "cat" : cat,
        "ord" : ord,
        "var" : var
        }
    pdf = ROOT.RooChebychev("cheb%(label)s%(cat)d_%(ord)d" % names,  "cheb%(label)s%(cat)d_%(ord)d" % names,
                            ws.var(var), ROOT.RooArgList(*norms) )
    pdfs.append(pdf)
    objs.append( [pdf, norms] )
    return [ROOT.RooFit.RooConst(1.)], pdfs 

##
def mkpol(ord,cat,label,ws,var="CMS_hgg_mass"):
    norms = []
    pdfs = []
    for i in range(ord+1):
        norm = ws.factory("pol%d_coeff%d_%scat%d[0.1,-1,1]" % (ord,i,label,cat) )
        ## if i > 2 or ord-i < 1:
        ##     norm.setVal(0.01)
        objs.append(norm)
        norm2 = ROOT.RooFormulaVar("pol%d_sqcoeff%d_%scat%d" % (ord,i,label,cat),"pol%d_sqcoeff%d_%scat%d" % (ord,i,label,cat),
                                   "@0*@0", ROOT.RooArgList(norm) )
        norms.append(norm2)
        ## norms.append(norm)

    names = {
        "label" : label,
        "cat" : cat,
        "ord" : ord,
        "var" : var
        }
    pdf = ROOT.RooBernstein("pol%(label)s%(cat)d_%(ord)d" % names,  "pol%(label)s%(cat)d_%(ord)d" % names,
                            ws.var(var), ROOT.RooArgList(*norms) )
    pdfs.append(pdf)
    objs.append( [pdf, norms] )
    return [ROOT.RooFit.RooConst(1.)], pdfs 

##
def mkPdf(name,ord,cat,label,ws):
    if label != "":
        label += "_"
    norms, pdfs = globals()["mk%s" % name](ord,cat,label,ws)

    try:
        norms[0].setVal(1.)
        norms[0].setConstant(True)
    except:
        pass
    
    pdf = ROOT.RooAddPdf("%s%d_%scat%d_pdf" % (name,ord,label,cat), "%s%d_%scat%d_pdf" % (name,ord,label,cat), ROOT.RooArgList(*pdfs), ROOT.RooArgList(*norms) )
    pdfName.append("%s%d_%scat%d_pdf" % (name,ord,label,cat))

        
    norm = ws.factory("model_%scat%d_norm[0,1.e+6]" % (label,cat))

    ## extpdf = ROOT.RooExtendPdf("%s%d_cat%d_extpdf" % (name,ord,cat), "%s%d_cat%d_extpdf" % (name,ord,cat), pdf, norm)
    extpdf = ROOT.RooExtendPdf("model_%scat%d" % (label,cat), "model_%scat%d" % (label,cat), pdf, norm)
    getattr(ws,"import")(pdf, ROOT.RooFit.RecycleConflictNodes())
    getattr(ws,"import")(extpdf, ROOT.RooFit.RecycleConflictNodes())
    
    objs.append( [pdf, extpdf] )

    ## extpdf = pdf
    ## getattr(ws,"import")(pdf, ROOT.RooFit.RecycleConflictNodes())
    
    objs.append( [pdf, extpdf] )

    return extpdf

# -----------------------------------------------------------------------------------------------------------
def main(options,args):

    ## setTDRStyle()
    ROOT.gStyle.SetOptStat(0)
        
    fin = ROOT.TFile.Open(options.file)

#    samples = { "sig" : ["sigRv","sigWv"] , "bkg" : ["bkg"] }
  #  samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_0","reducedTree_bkg_2"], "higgs" : ["reducedTree_bkg_3","reducedTree_bkg_4","reducedTree_bkg_5","reducedTree_bkg_6","reducedTree_bkg_7","reducedTree_bkg_8"] }
 #   samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_0","reducedTree_bkg_2"] }
    #samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_0"] }
 #   samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_3","reducedTree_bkg_4"] }# diphoton plus bjets
   # samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_0","reducedTree_bkg_2"], "higgs" : ["reducedTree_bkg_5","reducedTree_bkg_6","reducedTree_bkg_7","reducedTree_bkg_8"] } #diphoton and single higgs 
   # samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_0"], "higgs" : ["reducedTree_bkg_5","reducedTree_bkg_6","reducedTree_bkg_7","reducedTree_bkg_8"] } #diphotonOnly and single higgs 
   # samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_bkg_3","reducedTree_bkg_4"], "higgs" : ["reducedTree_bkg_5","reducedTree_bkg_6","reducedTree_bkg_7","reducedTree_bkg_8"] } #diphoton+2 bjets and single higgs 
    samples = { "sig" : ["reducedTree_sig"] , "bkg" : ["reducedTree_data"] }# estimation with data
    trees = {}

    catdef = open(options.catdef)
    summary = json.loads(catdef.read())

    obsname,obsmin,obsmax = options.observable
    nbins = options.nbins
    binsize = (obsmax - obsmin) / float(nbins)
    varnames = options.variables

    cats = summary[options.ncat]["boundaries"]
    ncat = int(options.ncat)
    
   # poly = [ 0, 60, 500, 10000, 20000, 40000 ]
    poly = [ 0, 20, 500, 10000, 20000, 40000 ]
  #  poly = [ 0, 100, 500, 10000, 20000, 40000 ]
    
    nvars = len(varnames)
    bounds = [ [ float(cats[ivar*(ncat+1)+icat]) for ivar in range(nvars) ]  for icat in range(ncat+1) ]

    #add bsm nodes
    if  "addBSMNodes" in options.__dict__.keys():
       # for i in range(2,14):
        for i in range(2,15):   #box is #14
            samples["sig_node_"+str(i)]=["reducedTree_sig_node_"+str(i)]
        
    print "var and boundaries"
    print cats
    print bounds
    print varnames
    
    cuts = []
    cats = []
    catvar = "0"
    prev = None
    for icat in range(ncat):
        cut = ROOT.TCut("1")
        cat = ROOT.TCut("cut%d" % icat)
        if prev:
            cat *= prev
        prev = ROOT.TCut("0")
        for ivar,var in enumerate(varnames):
            cut  = ROOT.TCut( cut.GetTitle() + " && ( %s > %g )" % (var,bounds[icat+1][ivar]) )
            prev = prev.GetTitle() + " || ( %s <= %g )" % (var,bounds[icat+1][ivar])
            print "-----------cut------------------"
            print cut

        cuts.append( ("cut%d"%icat,cut) )
        cats.append( ("cat%d"%icat,cat) )
            

        catvar += "+%d * (cat%d) " % ( icat, icat )

    catvar = ROOT.TCut(catvar)
    selcuts = summary[options.ncat]["selections"]
    selection = ROOT.TCut("cut%d" % (ncat-1) )
    for isel,sel in enumerate(options.selections):
        selection *= ROOT.TCut("%s > %g" % (sel,selcuts[isel]))
    for ivar,var in enumerate(varnames):
        selection *= ROOT.TCut("%s <= %g" % (var,bounds[0][ivar]))

    #adding additional cuts for different selections
    if "additionalCuts" in summary[options.ncat]:
        additcuts = summary[options.ncat]["additionalCuts"]
        print additcuts
        for ivar, var in enumerate(summary[options.ncat]["additionalCuts"]):
            selection*= ROOT.TCut("%s > %g" % (var,additcuts[var][0]))
            selection*= ROOT.TCut("%s < %g" % (var,additcuts[var][1]))
            print "----------------------additionalCuts-----------------"  

    print selection
    lumi = 1.
    if "lumi" in summary[options.ncat]:
        lumi = summary[options.ncat]["lumi"]
        print 'Normalizing to Luminosity : ',lumi

    for name,sel in cuts+cats+[("cat",catvar),("selection",selection)]:
        print name, sel.GetTitle()
        
    tmp = ROOT.TFile.Open("/tmp/$USER/tmp.root","recreate")
    for sname,samp in samples.iteritems():
        print "Reading ", sname, samp
        tlist = ROOT.TList()
        for name in samp:
            print name
            tree = fin.Get(name)
            tlist.Add(tree)
        tout=ROOT.TTree.MergeTrees(tlist)
        tout.SetName(sname)
        trees[sname] = tout
            
    models = {}
    allcats = []
    if getattr(options,"subcategories",None):
        todos = options.subcategories
    else:
        todos = [ ("","") ]
    for icat in range(ncat):
        for tname,tsel in todos:
            cname = "cat%d" % icat
            if tname != "": cname = "%s_%s" % ( tname, cname )
            allcats.append(cname)
    print allcats
    
    subCatCuts = {} 
    if "subCategoryCuts" in summary[options.ncat]:
        subCategoryCuts = summary[options.ncat]["subCategoryCuts"]
 
        print "subcategory cuts", subCategoryCuts
        for icat,cat in enumerate(subCategoryCuts):
#            subCategoryCuts[cat] = ROOT.TCut("%s > %g && %s < %g " % (subCategoryCuts[cat][0],subCategoryCuts[cat][1],subCategoryCuts[cat][0],subCategoryCuts[cat][2]))   
            subCategoryCuts[cat] =  ROOT.TCut("%s >( %s * %s + %s * %s + %s * %s) && %s <( %s * %s + %s * %s + %s * %s)" % (subCategoryCuts[cat][0],subCategoryCuts[cat][1],subCategoryCuts[cat][2],subCategoryCuts[cat][3],subCategoryCuts[cat][4],subCategoryCuts[cat][5],subCategoryCuts[cat][6],subCategoryCuts[cat][0],subCategoryCuts[cat][7],subCategoryCuts[cat][8],subCategoryCuts[cat][9],subCategoryCuts[cat][10],subCategoryCuts[cat][11],subCategoryCuts[cat][12]))


    procs = []
    first = True

    for name,tree in trees.iteritems():
        for an,ad in cuts+cats:
            tree.SetAlias(an,ad.GetTitle())
        tree.SetAlias("cat",catvar.GetTitle())
        if not "bkg" in name:
            procs.append(name)
        iCat = 0
        for tname, tsel in todos:
            mname = name
            if tname != "": mname += "_%s" % tname
            print mname
           # sel = ROOT.TCut("2*weight") * selection  #FIXME temporary times two when considered half events (testing set) only
            if options.dodata ==0 : sel = ROOT.TCut("weight*%.2f"%lumi) * selection 
            else : 
               if 'sig' in name or 'bkg_' in name :  sel = ROOT.TCut("weight*%.2f"%lumi) * selection 
               else : sel = ROOT.TCut("weight")*selection
             

            if tsel != "":
                sel *= ROOT.TCut(tsel)            
            model = ROOT.TH2F("model_%s" % mname, "model_%s" % mname, nbins, obsmin, obsmax, ncat, 0, ncat )
            renorm = ROOT.TH2F("model_renorm_%s" % mname, "model_%s" % mname, nbins, obsmin, obsmax, ncat, 0, ncat )
            if options.maxw > 0.:
#                tree.Draw("cat:%s>>model_renorm_%s" % (obsname,mname), sel * ROOT.TCut("_weight >= %g" % options.maxw), "goff")
                tree.Draw("cat:%s>>model_renorm_%s" % (obsname,mname), sel * ROOT.TCut("weight >= %g" % options.maxw), "goff")
                sel *= ROOT.TCut("_weight < %g" % options.maxw)
            if "subCategoryCuts" in summary[options.ncat]:

                sel *= subCategoryCuts[allcats[iCat]]
                iCat += 1

            tree.Draw("cat:%s>>model_%s" % (obsname,mname), sel, "goff")
            models[mname] = (model,renorm)
            objs.append( (model,renorm) )
            ## model.Draw()
        
    ### bounds.sort()
    ### ybins = numpy.array(bounds)
    ### xbins = numpy.arange(obsmin,obsmax+binsize,binsize)
    ### for name,tree in trees.iteritems():
    ###     model = ROOT.TH2F("model_%s" % name, "model_%s" % name, len(xbins)-1, xbins, len(ybins)-1, ybins )
    ###     tree.Draw("diphoMVA:mass>>model_%s" % name, "_weight", "goff")
    ###     models[name] = model
    ###     objs.append(model)
    ###     ## model.Draw()

    ws = ROOT.RooWorkspace("cms_hgg","cms_hgg")
    mgg = ws.factory("CMS_hgg_mass[%g,%g]" % (obsmin,obsmax) )
    mgg.setBins(nbins)

    for name,models in models.iteritems():
        model, renorm = models
        for icat in range(ncat):
            slice = model.ProjectionX("%s_cat%d" % (name, icat), icat+1, icat+1 )
            missing = renorm.ProjectionX("%s_cat%d_missing" % (name, icat), icat+1, icat+1 )
            print slice.Integral(), missing.Integral()
            slice.Scale( 1. + missing.Integral() / slice.Integral()  )
            print slice.Integral()
            data = ROOT.RooDataHist(slice.GetName(),slice.GetName(),ROOT.RooArgList(mgg),slice)
            print data.sumEntries()
            getattr(ws,"import")(data)
            if "bkg" in name:
                norm = slice.Integral()
                order = 0
                while norm > poly[order]:
                    print "norm-------"
                    print norm
                    print order
                    if order >= len(poly)-1:
                        break
                    order += 1
                ## pdf = mkPdf("pol",order+2,icat,name.replace("model_",""),ws)
                pdf = mkPdf("cheb",order,icat,name.replace("model_",""),ws)
                mgg.setRange("blind1",100,115)
                mgg.setRange("blind2",135,180)
#                pdf.fitTo(data,ROOT.RooFit.Strategy(1),ROOT.RooFit.PrintEvalErrors(-1),ROOT.RooFit.Range("blind1,blind2"))
                pdf.fitTo(data,ROOT.RooFit.Strategy(1),ROOT.RooFit.PrintEvalErrors(-1))
                pdf.fitTo(data,ROOT.RooFit.Strategy(2),ROOT.RooFit.Range("blind1,blind2"))

#                pdfNorm.append(pdf.expectedEvents(ROOT.RooArgSet(mgg)))
                catName=("%s_cat%d" % (name, icat)).replace("bkg_","")
                pdfNorm[catName]=pdf.expectedEvents(ROOT.RooArgSet(mgg)) # the fit is done on the blinded region but expected events is in 100-180, checked with the code below
#                if options.reweight == True:
#                    if catName == 'subcat0_cat0':
#                        print "dajeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
#                        print pdfNorm[catName],pdf.getNormIntegral(ROOT.RooArgSet(mgg))
#                        hist = pdf.createHistogram("prova",mgg)
#                        c1 = ROOT.TCanvas()
#                        hist.Draw()
#                        c1.SaveAs("dummy.png")
#                        print "int total", hist.Integral(hist.FindBin(100),hist.FindBin(180),"width")
#                        print "int blinded", hist.Integral(hist.FindBin(100),hist.FindBin(115),"width")+hist.Integral(hist.FindBin(135),hist.FindBin(180),"width")


    ws.writeToFile(options.out)

    datacard = open(options.out.replace("root","txt"),"w+")
    datacard.write("""
----------------------------------------------------------------------------------------------------------------------------------
imax * number of bins
jmax * number of processes minus 1
kmax * number of nuisance parameters
----------------------------------------------------------------------------------------------------------------------------------\n""")

    datacard.write("shapes data_obs * %s cms_hgg:bkg_$CHANNEL\n" % str(os.getcwd()+str("/")+options.out))
#    for icat in range(ncat):
#        datacard.write("shapes bkg cat%d" % (icat) )
#        datacard.write(" %s cms_hgg:" % options.out)
#        datacard.write(pdfName[icat].replace("cat0","$CHANNEL")+"\n")

    for icat in range(0,len(allcats)):
#        datacard.write("shapes bkg %s" % allcats[icat] )
        datacard.write("shapes bkg %s" % (pdfName[icat].split('_bkg_')[-1]).replace('_pdf',''))
        datacard.write(" %s cms_hgg:" % str(os.getcwd()+str("/")+options.out))
        datacard.write(pdfName[icat]+"\n")

    for proc in procs:
        #no bsm nodes in datacard
        if "node" in proc:
            continue
        datacard.write("shapes %s *   %s cms_hgg:%s_$CHANNEL\n" % (proc,str(os.getcwd()+str("/")+options.out),proc))
    
    datacard.write("----------------------------------------------------------------------------------------------------------------------------------\n")
    datacard.write("bin".ljust(20))
    for cat in allcats:
        datacard.write((" %s" % cat).ljust(5) )
    datacard.write("\n")

    datacard.write("observation".ljust(20))
    for cat in allcats:
        datacard.write(" -1".ljust(5) )
    datacard.write("\n")
        

    datacard.write("----------------------------------------------------------------------------------------------------------------------------------\n")
    
    datacard.write("bin".ljust(20))
    for cat in allcats:
        for proc in range(len(procs)+1):
            if proc < len(procs) and 'node' in procs[proc]:
                continue
            datacard.write((" %s" % cat).ljust(5) )
    datacard.write("\n")


    datacard.write("process".ljust(20))
    for cat in allcats:
        for proc in procs:
            if "node" in proc:
                continue
            datacard.write((" %s" % proc).ljust(5) )
        datacard.write(" bkg".ljust(5) )
    datacard.write("\n")
    
    datacard.write("process".ljust(20))
    for cat in allcats:
        for proc in range(len(procs)):
            if "node" in procs[proc]:
                continue
            if 'sig' in procs[proc]:
                datacard.write((" %d" % -(proc+1)).ljust(5) )
            else:    
#                datacard.write(" 1".ljust(5) )
                datacard.write((" %d" % (proc+1)).ljust(5) )
        datacard.write(" 1".ljust(5) )
    datacard.write("\n")
        
    datacard.write("rate".ljust(20))
    for icat in range(0,len(pdfNorm)):
        for proc in range(len(procs)):
            if "node" in procs[proc]:
                continue
            datacard.write(" -1".ljust(5) )
        datacard.write(("%f" % pdfNorm[allcats[icat]]).ljust(5) )
    datacard.write("\n")

    datacard.write("----------------------------------------------------------------------------------------------------------------------------------\n\n")
        
    
if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-i", "--infile",
                        action="store", type="string", dest="file",
                        default="",
                        help="input file",
                        ),
            make_option("-o", "--out",
                        action="store", type="string", dest="out",
                        default="",
                        help="",
                        ),
            make_option("-d", "--cat-def",
                        action="store", type="string", dest="catdef",
                        default="",
                        help="categories definition file",
                        ),
            make_option("-s", "--settings",
                        action="append", type="string", dest="settings",
                        default=[],
                        help="json file with additional settings",
                        ),
            make_option("-N", "--nbins",
                        action="store", type="int", dest="nbins",
                        default=320,
                        help="number of categories",
                        ),
            make_option("-m", "--maxw",
                        action="store", type="float", dest="maxw",
                        default=50.,
                        help="number of categories",
                        ),
            make_option("-n", "--ncat",
                        action="store", type="string", dest="ncat",
                        default="",
                        help="number of categories",
                        ),
            make_option("--dodata",
                        action="store", type="int", dest="dodata",
                        default=0,
                        help="do expect limit with data or without",
                        ),

            ]
                          )

    (options, args) = parser.parse_args()
    ## sys.argv.append("-b")

    for st in options.settings:
        with open(st) as settings:
            options.__dict__.update(json.loads(settings.read()))
            settings.close()
    
    pprint(options.__dict__)

    import ROOT
    
    main(options,args)
        

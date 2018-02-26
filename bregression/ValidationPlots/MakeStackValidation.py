from pullClass import *
from ROOT import *
import json, os
import shutil
from configsStackValidation import *
import resource

#SetMemoryPolicy( kMemoryStrict )

gStyle.SetOptStat(0)
dummyTFile = TFile("dummy.root", "RECREATE")

if not os.path.exists(dirName):
        print dirName, "doesn't exist, creating it..."
        os.makedirs(dirName)
        shutil.copy2(dirPrefix + "index.php", dirName+"/index.php")
        if os.path.exists(dirName):
                print dirName, "now exists!"

datasets = json.load(data_file)

Trees = {}

CutSignal = Cut
if doBlind == True:
	Cut += " && !((diphotonCandidate.M() > 115 && diphotonCandidate.M() < 135))"
if isPhoCR == True:
	Cut += " && (isPhotonCR == 1)"
	CutSignal += " && (isPhotonCR == 1)"
#if isPhoCR == False:
#	Cut += " && (isSignal == 1)"
#	CutSignal += " && (isSignal == 1)"
if doSignalRegion == True:
	CutSignal += " && ( leadingJet_bDis > "+ str(BTAG) + " || subleadingJet_bDis > "+str(BTAG)+" ) "
	Cut += " && ( leadingJet_bDis > "+ str(BTAG) + " || subleadingJet_bDis > "+ str(BTAG) + " ) "
if doJetCR == True:
	Cut += " && leadingJet_bDis < "+ str(BTAG) + " && subleadingJet_bDis < "+ str(BTAG) + " "
weightedcut = ""
weightedcut += "genWeight*puWeight*"
weightedcut +=Cut
weightedCut = TCut(weightedcut)
cut_data = TCut(Cut)
#cut_signal = TCut(weightedcut.replace("!((diphotonCandidate.M() > 115 && diphotonCandidate.M() < 135))", "(1>0)"))

for plot in plots:
    Histos = []
    variable = plot[1]
    varName = plot[2]
    thisStack = 0
    thisHist = 0
    thisStack = myStack('test'+plot[0], varName, varName, dirName, lumi)
    if hideData == True:
        thisStack.hideData()
    if hideStat == True:
        thisStack.hideStat()
    if isPhoCR == 1:
        thisStack.makePhoCR()
    if doJetCR == 1:
        thisStack.makeJetCR()
    if doShape == True:
        thisStack.doShape()
    if useJsonWeighting == True:
        thisStack.useJsonWeighting()



    thisStack.setYear(year)

    modelHist = TH1F(plot[0]+"_hist", "", plot[3], plot[4], plot[5])

    backgroundHists = []
    for background in datasets["background"]:
        if not addbbH and 'bbH' in background: continue
	if not addHiggs and 'VH' in background: continue
	if not addHiggs and 'VBF' in background: continue
	if not addHiggs and 'ggH' in background: continue
	if not addHiggs and 'ttH' in background: continue
        if not dyjets and "DYJ" in background: continue
        if "QCD" in background: continue
        print background
        thisName = plot[0]+"_hist"+"_"+background
        thisHist = modelHist.Clone(thisName)
#        thisHist.Clear()
#        thisHist.Sumw2()
        thisHist.SetLineColor(TColor.GetColor(datasets["background"][background]["color"]))
        thisHist.SetFillColor(TColor.GetColor(datasets["background"][background]["color"]))
        for i,fi in enumerate(datasets["background"][background]["files"]):
            print fi
            thisTreeLoc = fi["file"]
	    skipEmptyFile = False
            if thisTreeLoc not in Trees:
                Trees[thisTreeLoc] = TChain("tree")
                Trees[thisTreeLoc].AddFile(bkgLocation+thisTreeLoc)
                SetOwnership( Trees[thisTreeLoc], True )
            locName = thisName+str(i)
            locHist = thisHist.Clone(locName)
            thisWeightedCut = weightedCut
#            if "QCD" in thisTreeLoc:
#		    thisWeightedCut = TCut(weightedcut.replace("isSignal == 1", "isSignal == 0"))
	    print "doing plot for TT, the selection is: "
	    print thisWeightedCut
            Trees[thisTreeLoc].Draw(plot[1]+">>"+locName, thisWeightedCut)
	    
	    if useJsonWeightingHeppy:
		    locHist.Scale(fi["xsec"]*fi["lumi"]/fi["eventsGenerated"]*fi["sfactor"])
		    print fi["xsec"]*fi["lumi"]/fi["eventsGenerated"]*fi["sfactor"]


	    elif doShape:
		    if not locHist.Integral() == 0:
			    locHist.Scale(1./locHist.Integral())
		    print locHist.Integral()

	    		    
	    if not skipEmptyFile: #fixme! needs to be implemented
		    thisHist.Add(locHist)
		    Histos.append(locHist)


#            thisFile = TFile(plot[0]+"_"+fi["file"], "RECREATE")
#            thisFile.cd()
#            thisHist.Write()
#            thisFile.Close()
#            dummyTFile.cd()
            
        backgroundHists.append([thisHist, datasets["background"][background]["legend"], datasets["background"][background]["position"]])

    OrderedBackgrounds = sorted(backgroundHists, key=lambda x: x[2], reverse=True)
    print OrderedBackgrounds
    if doShape:
	    for background in OrderedBackgrounds: 
		    background[0].Scale(1./background[0].Integral())
		    background[0].SetFillStyle(3004)
		    background[0].SetLineWidth(2)
		    thisStack.addBackground(background[0], background[1], 1.)
    del thisHist
    for background in OrderedBackgrounds: thisStack.addHist(background[0], background[1], background[2])
    
    for signal in datasets["signal"]:
        continue ##FIX MEEEEEEEEEEE!!!
        thisName = plot[0]+"_Signal_"+"_"+signal['name']
#        modelHist.Clear()
#        thisHist = 0
 #       thisHist = modelHist
#        thisHist.SetName(thisName)
#        thisHist.Sumw2()
        thisHist = modelHist.Clone(thisName)
        thisHist.SetLineColor(signal["color"])
        thisHist.SetLineWidth(2)
        thisTreeLoc = signal["file"]
        if thisTreeLoc not in Trees:
            Trees[thisTreeLoc] = TChain("tree")
            Trees[thisTreeLoc].AddFile(signalLocation+thisTreeLoc)
            SetOwnership( Trees[thisTreeLoc], True )
        Trees[thisTreeLoc].Draw(plot[1]+">>"+thisName, cut_signal)
	if not doShape  and useJsonWeighting:
		thisHist.Scale(lumi*signal["xsec"]*signal["sfactor"]/signal["weight"])
	elif doShape:
		thisHist.Scale(1./thisHist.Integral())
	else:
		thisHist.Scale(signal["sfactor"])
		
        Histos.append(thisHist)
	if not doShape and useJsonWeighting:
		thisStack.addSignal(thisHist, signal["legend"], lumi*signal["xsec"]*signal["sfactor"]/signal["weight"])
	elif doShape:
		thisStack.addSignal(thisHist, signal["legend"], 1.)
	else:
		thisStack.addSignal(thisHist, signal["legend"], signal["sfactor"])

        del thisHist
    
    
    print datasets['data']
    dataName = plot[0]+"_hist"+"_data"
    modelHist.Clear()
    dataHist = 0
#    dataHist = modelHist
    dataHist = modelHist.Clone(dataName)
#    dataHist.Sumw2()
    if datasets['data'] not in Trees:
        Trees[datasets['data']] = TChain("tree")
        Trees[datasets['data']].AddFile(dataLocation+datasets['data'])
        SetOwnership( Trees[datasets['data']], True )
    Trees[datasets['data']].Draw(plot[1]+">>"+dataName, cut_data)
    print "applying for data following selection:"   
    print cut_data


    dataHist.SetMarkerStyle(20)
    dataHist.SetMarkerSize(0.8)
    dataHist.SetMarkerColor(1)
    dataHist.SetLineColor(1)
    dataHist.SetLineWidth(2)
    thisStack.addData(dataHist, "Data")
#    thisFile = TFile(plot[0]+"_data.root", "RECREATE")
#    thisFile.cd()
#    dataHist.Write()
#    thisFile.Close()
#    dummyTFile.cd()

    thisStack.drawStack(prefix + plot[0])
    
    del thisStack 


dummyTFile.Close()
os.system("rm dummy.root")

#for tt in Trees:
#    Trees[tt].IsA().Destructor( Trees[tt] )

#    gROOT.GetListOfCanvases().Delete()
#    print Trees
#    print 'Memory usage: %s (kb)' % resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
#    gROOT.GetListOfCleanups().Delete()
    


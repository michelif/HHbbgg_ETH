from optparse import OptionParser, make_option
from  pprint import pprint

import os
import sys; sys.path.append("~/HHbbgg_ETH_devel/Training/python") # to load packages
import training_utils as utils
import numpy as np
import preprocessing_utils as preprocessing
import plotting_utils as plotting
import optimization_utils as optimization
import postprocessing_utils as postprocessing

import pandas as pd
import root_pandas as rpd



def addSamples():#define here the samples you want to process
    ntuples = options.ntup
    samples = ["GluGluToHHTo2B2G_node_SM","DiPhotonJetsBox_","GJet_Pt-20to40","GJet_Pt-40","GluGluHToGG","VBFHToGG","VHToGG","bbHToGG_M-125_4FS_yb2","ttHToGG"]#is bbH correct?

    files= os.listdir(utils.IO.ldata+ntuples)

    for iSample in samples:
        process  = [s for s in files if iSample in s]
        if iSample == "GluGluToHHTo2B2G_node_SM":
            utils.IO.add_signal(ntuples,process,1)
        elif not "GJet" in str(iSample):
            utils.IO.add_background(ntuples,process,-(samples.index(iSample)-(samples.index(iSample)>2)))
        else:
            utils.IO.add_background(ntuples,process,-2)

    

    nBkg = len(utils.IO.backgroundName)
    
    Data= [s for s in files if "DoubleEG" in s]
    utils.IO.add_data(ntuples,Data,-10)
    
    #add all nodes
    nodes = []
    for i in range(2,14):
        nodes.append([s for s in files if "GluGluToHHTo2B2G_node_"+str(i) in s])
    for i in range(len(utils.IO.backgroundName),len(utils.IO.backgroundName)+len(nodes)):
        utils.IO.add_background(ntuples,nodes[i-nBkg],-i)
        
    for i in range(len(utils.IO.backgroundName)):        
        print "using background file n."+str(i)+": "+utils.IO.backgroundName[i]
    for i in range(len(utils.IO.signalName)):    
        print "using signal file n."+str(i)+": "+utils.IO.signalName[i]
    print "using data file: "+ utils.IO.dataName[0]
    


def main(options,args):

    addSamples()
    
    #mva variables, use noexpand for root expressions, it needs this file https://github.com/ibab/root_pandas/blob/master/root_pandas/readwrite.py
    branch_names = 'leadingJet_bDis,subleadingJet_bDis,noexpand:fabs(CosThetaStar_CS),noexpand:fabs(CosTheta_bb),noexpand:fabs(CosTheta_gg)'.split(",")
    branch_names += 'noexpand:diphotonCandidate.Pt()/diHiggsCandidate.M(),noexpand:dijetCandidate.Pt()/diHiggsCandidate.M()'.split(",")
    branch_names += 'customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverMDecorr,PhoJetMinDr'.split(",")
    branch_names = [c.strip() for c in branch_names]
    print "using following variables for MVA: " 
    print branch_names
    
    
    # no need to shuffle here, we just count events
    preprocessing.set_signals_and_backgrounds("bbggSelectionTree",branch_names,shuffle=False)
    X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.set_variables(branch_names)
    
    X_data,y_data,weights_data = preprocessing.set_data("bbggSelectionTree",branch_names)
    X_data,y_data,weights_data = preprocessing.clean_signal_events_single_dataset(X_data,y_data,weights_data)
    
    #bbggTrees have by default signal and CR events, let's be sure that we clean it
    X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig=preprocessing.clean_signal_events(X_bkg,y_bkg,weights_bkg,X_sig,y_sig,weights_sig)
    
    
    # load the model from disk
    from sklearn.externals import joblib
    loaded_model = joblib.load(os.path.expanduser('~/HHbbgg_ETH_devel/Training/output_files/'+options.trainingVersion+'.pkl'))
    
    bkg = []
    for i in range(0,len(utils.IO.backgroundName)-1): 
        bkg.append(X_bkg[y_bkg ==-i-1])
    
        
    #compute the MVA
    if not options.addHHTagger:
        Y_pred_sig = loaded_model.predict_proba(X_sig)[:,loaded_model.n_classes_-1].astype(np.float64)
        Y_pred_bkg = []
        for i in range(0,len(utils.IO.backgroundName)-1):  
            print str(i)
            Y_pred_bkg.append(loaded_model.predict_proba(bkg[i])[:,loaded_model.n_classes_-1].astype(np.float64))
    
        Y_pred_data = loaded_model.predict_proba(X_data)[:,loaded_model.n_classes_-1].astype(np.float64)
        print Y_pred_data 
    
    
    
    #define MVA cut and additional variables needed
    additionalCut_names = 'noexpand:diphotonCandidate.M(),noexpand:dijetCandidate.M(),MX,isSignal'.split(",")
    #mva output
    if options.addHHTagger:
        additionalCut_names += 'HHTagger2017'.split(",")
    outTag = options.outTag
    outDir=os.path.expanduser("~/HHbbgg_ETH_devel/outfiles/"+outTag)
    if not os.path.exists(outDir):
        os.mkdir(outDir)
    
    
    sig_count_df = rpd.read_root(utils.IO.signalName[0],"bbggSelectionTree", columns = branch_names+additionalCut_names)
    preprocessing.define_process_weight(sig_count_df,utils.IO.sigProc[0],utils.IO.signalName[0])
    
    #nTot is a multidim vector with all additional variables, dictVar is a dictionary associating a name of the variable
    #to a position in the vector
    nTot,dictVar = postprocessing.stackFeatures(sig_count_df,branch_names+additionalCut_names)
    #apply isSignal cleaning
    nCleaned = nTot[np.where(nTot[:,dictVar['weight']]!=0),:][0]
    
    processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.signalName[0].split("/")[len(utils.IO.signalName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"

    if not options.addHHTagger:
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_sig)
    else:
        postprocessing.saveTree(processPath,dictVar,nCleaned)        
    
    processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.signalName[0].split("/")[len(utils.IO.signalName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"

    if not options.addHHTagger:
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_sig,nameTree="reducedTree_sig")
    else:    
        postprocessing.saveTree(processPath,dictVar,nCleaned,nameTree="reducedTree_sig")
    
    ## do gJets not in the loop since they have two samples for one process, to be fixed
    bkg_1_count_df = rpd.read_root(utils.IO.backgroundName[1],"bbggSelectionTree", columns = branch_names+additionalCut_names)
    preprocessing.define_process_weight(bkg_1_count_df,utils.IO.bkgProc[1],utils.IO.backgroundName[1])
    
    crazySF_20=25
    nTot,dictVar = postprocessing.stackFeatures(bkg_1_count_df,branch_names+additionalCut_names,SF=crazySF_20)
    
    print nTot.shape
    
    bkg_2_count_df = rpd.read_root(utils.IO.backgroundName[2],"bbggSelectionTree", columns = branch_names+additionalCut_names)
    preprocessing.define_process_weight(bkg_2_count_df,utils.IO.bkgProc[2],utils.IO.backgroundName[2])
    
    crazySF_40=3
    nTot_2,dictVar = postprocessing.stackFeatures(bkg_2_count_df,branch_names+additionalCut_names,SF=crazySF_40)
    
    
    nTot_3 = np.concatenate((nTot,nTot_2))
    
    print nTot_3.shape
    nCleaned = nTot_3[np.where(nTot_3[:,dictVar['weight']]!=0),:][0]
    print "nCleaned"
    print nCleaned.shape
    
    processPath=(os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.backgroundName[1].split("/")[len(utils.IO.backgroundName[1].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root").replace("_Pt-20to40","")
    if not options.addHHTagger:
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_bkg[1])
    else:
        postprocessing.saveTree(processPath,dictVar,nCleaned) 
   
    processPath=(os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.backgroundName[1].split("/")[len(utils.IO.backgroundName[1].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root").replace("_Pt-20to40","")

    if not options.addHHTagger:
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_bkg[1],nameTree="reducedTree_bkg_2")
    else:
        postprocessing.saveTree(processPath,dictVar,nCleaned,nameTree="reducedTree_bkg_2")    
    
    
    
    for iProcess in range(0,len(utils.IO.backgroundName)):
        ##gJets which are two samples for one process are skipped
        iSample=iProcess
        if iProcess == 1 or iProcess ==2:
                continue
        if iProcess > 2:
            iSample = iProcess-1
        
        print "Processing sample: "+str(iProcess)
        bkg_count_df = rpd.read_root(utils.IO.backgroundName[iProcess],"bbggSelectionTree", columns = branch_names+additionalCut_names)
        preprocessing.define_process_weight(bkg_count_df,utils.IO.bkgProc[iProcess],utils.IO.backgroundName[iProcess])
    
        crazySF=1
        ##scale diphoton + jets
        if iProcess == 0:
            crazySF=1.45
        nTot,dictVar = postprocessing.stackFeatures(bkg_count_df,branch_names+additionalCut_names,SF=crazySF)
    
    
        nCleaned = nTot[np.where(nTot[:,dictVar['weight']]!=0),:][0]
        print "nCleaned"
        print nCleaned.shape
    
        processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.backgroundName[iProcess].split("/")[len(utils.IO.backgroundName[7].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
        if not options.addHHTagger:
            postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_bkg[iSample])
        else:
            postprocessing.saveTree(processPath,dictVar,nCleaned)
        
        processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.backgroundName[iProcess].split("/")[len(utils.IO.backgroundName[7].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
        if "GluGluToHHTo2B2G_node_"in processPath:
            treeName = "reducedTree_sig_node_"+str(iProcess-6)
        else:
            treeName = "reducedTree_bkg_"+str(iProcess)
        if not options.addHHTagger:        
            postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_bkg[iSample],nameTree=treeName)
        else:
            postprocessing.saveTree(processPath,dictVar,nCleaned,nameTree=treeName)    
    
    ##data    
    data_count_df = rpd.read_root(utils.IO.dataName[0],"bbggSelectionTree", columns = branch_names+additionalCut_names)
    
    nTot,dictVar = postprocessing.stackFeatures(data_count_df,branch_names+additionalCut_names,isData=1)
    
    
    #apply isSignal cleaning
    nCleaned = nTot[np.where(nTot[:,dictVar['weight']]!=0),:][0]
    print "nCleaned"
    print nCleaned.shape
    
    #save preselection data
    processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.dataName[0].split("/")[len(utils.IO.dataName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection"+".root"
    if not options.addHHTagger:        
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_data)
    else:
        postprocessing.saveTree(processPath,dictVar,nCleaned)
    
    processPath=os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+utils.IO.dataName[0].split("/")[len(utils.IO.dataName[0].split("/"))-1].replace("output_","").replace(".root","")+"_preselection_diffNaming"+".root"
    if not options.addHHTagger:        
        postprocessing.saveTree(processPath,dictVar,nCleaned,Y_pred_data,nameTree="reducedTree_bkg")
    else:
        postprocessing.saveTree(processPath,dictVar,nCleaned,nameTree="reducedTree_bkg")
    
    os.system('hadd '+ os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+'Total_preselection_diffNaming.root '+ os.path.expanduser('~/HHbbgg_ETH_devel/outfiles/')+outTag+'/'+'*diffNaming.root')
    


if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-n", "--ntuples",
                        action="store", type="string", dest="ntup",
                        default="20170620",
                        help="ntuples location",
                        ),
            make_option("-a","--addMVAOutput",
                        action="store_true",dest="addHHTagger",default=False,
                        help="add MVAOutput to outTree",
                        ),
            make_option("-t","--training",
                        action="store", type="string",dest="trainingVersion",
                        default="allMC_resWeighting_F_noDR_minDRGJet",
                        help="MVA version to apply",
                        ),

            make_option("-o", "--out",
                        action="store", type="string", dest="outTag",
                        default="20180108_test",
                        help="output folder name",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT
    
    main(options,args)
        

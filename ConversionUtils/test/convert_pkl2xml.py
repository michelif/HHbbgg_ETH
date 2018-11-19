#import FWCore.ParameterSet.Config as cms
from time import time,ctime
import sys,os
from tree_convert_pkl2xml import tree_to_tmva, BDTxgboost, BDTsklearn
import sklearn
from collections import OrderedDict
from sklearn.externals import joblib
#print('The scikit-learn version is {}.'.format(sklearn.__version__))
import pandas
#print('The pandas version is {}.'.format(pandas.__version__))
import cPickle as pickle
#print('The pickle version is {}.'.format(pickle.__version__))
import numpy as np
#print('The numpy version is {}.'.format(np.__version__))
sys.path.insert(0, '/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/py2-pippkgs_depscipy/3.0-njopjo7/lib/python2.7/site-packages')
import xgboost as xgb
#print('The xgb version is {}.'.format(xgb.__version__))
import subprocess
from sklearn.externals import joblib
from itertools import izip
from optparse import OptionParser, make_option
from  pprint import pprint

#features = ['leadingJet_bDis', 'subleadingJet_bDis', 'leadingPhotonSigOverE', 'subleadingPhotonSigOverE', 'sigmaMOverMDecorr', 'PhoJetMinDr']
#features = ['leadingJet_bDis','subleadingJet_bDis','noexpand:fabs(CosThetaStar_CS)','noexpand:fabs(CosTheta_bb)','noexpand:fabs(CosTheta_gg)','noexpand:diphotonCandidate.Pt()/diHiggsCandidate.M()','noexpand:dijetCandidate.Pt()/diHiggsCandidate.M()','customLeadingPhotonIDMVA','customSubLeadingPhotonIDMVA','leadingPhotonSigOverE','subleadingPhotonSigOverE','sigmaMOverMDecorr','PhoJetMinDr']
#features = 'leadingJet_bDis,subleadingJet_bDis,absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverMDecorr,PhoJetMinDr,noexpand:(leadingJet_bRegNNResolution*1.4826),noexpand:(subleadingJet_bRegNNResolution*1.4826),noexpand:(sigmaMJets*1.4826)'.split(',')
features = 'leadingJet_DeepCSV,subleadingJet_DeepCSV,absCosThetaStar_CS,absCosTheta_bb,absCosTheta_gg,diphotonCandidatePtOverdiHiggsM,dijetCandidatePtOverdiHiggsM,customLeadingPhotonIDMVA,customSubLeadingPhotonIDMVA,leadingPhotonSigOverE,subleadingPhotonSigOverE,sigmaMOverMDecorr,PhoJetMinDr,rho,noexpand:(leadingJet_bRegNNResolution*1.4826),noexpand:(subleadingJet_bRegNNResolution*1.4826),noexpand:(sigmaMJets*1.4826),year'.split(',')

#this is just for testing if you want to check on one event, be careful, you have to put the correct variables
new_dict = OrderedDict([('leadingJet_bDis',0.9889938831329346),('subleadingJet_bDis',0.0648464784026146),('leadingPhotonSigOverE',0.005494383163750172),('subleadingPhotonSigOverE',0.0067262412048876286),('sigmaMOverMDecorr',0.006000000052154064),('PhoJetMinDr',1.1405941247940063)])

def main(options,args):

    inputFile = options.inFile
    outputFile = inputFile.split('/')[-1].replace('.pkl','.weights.xml')

    result=-20
    fileOpen = None
    try:
        fileOpen = open(inputFile, 'rb')
    except IOError as e:
        print('Couldnt open or write to file (%s).' % e)
    else:
        print ('file opened')
        try:
#            pkldata = pickle.load(fileOpen)
            pkldata = joblib.load(fileOpen)
            print pkldata
        except :
            print('Oops!',sys.exc_info()[0],'occured.')
        else:
            print ('pkl loaded')

            bdt = BDTxgboost(pkldata, features, ["Background","Background2", "Signal"])
            bdt.to_tmva(outputFile)
            print "xml file is created with name : ", outputFile

            if options.test:#this is just for testing if you want to check on one event uncomment here
                proba = pkldata.predict_proba([[ new_dict[feature] for feature in features]])
                print "proba= ",proba
                result = proba[:,1][0]
                print ('predict BDT to one event',result)
                

                test_eval = bdt.eval([ new_dict[feature] for feature in features])
                print "test_eval = ", test_eval

            fileOpen.close()
    return result

if __name__ == "__main__":
    parser = OptionParser(option_list=[
            make_option("-i", "--infile",
                        action="store", type="string", dest="inFile",
                        default="",
                        help="input file",
                        ),
            make_option("-t", "--test",
                        action="store_true", dest="test",
                        default=False,
                        help="test on one event",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT

    main(options,args)


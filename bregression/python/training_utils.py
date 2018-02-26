import sys; sys.path.append("~/HHbbgg_ETH_devel/bregression/python")
import matplotlib.pyplot as plt
import os


import random as rnd

from sklearn.utils.extmath import cartesian
import scipy.stats as stats

import random



# ---------------------------------------------------------------------------------------------------
class IO:
    ldata = os.path.expanduser("~/HHbbgg_ETH_devel/root_files/") ### instead of HHbbgg_ETH_devel ->HHbbgg_EHT
    xdata = "~/HHbbgg_ETH_devel/bregression/output_files/"
    plotFolder = os.path.expanduser("~/HHbbgg_ETH/bregression/plots/")
    plotStyle = os.path.expanduser("~/HHbbgg_ETH_devel/scripts/")
    signalName = []
    backgroundName = []
    dataName = []
    targetName = []
    featuresName = []
    targetProc =[]
    featuresProc = []
    sigProc = []
    bkgProc = []
    dataProc = []
    nSig=0
    nBkg=0
    nData=0
    nFeatures=0
    nTarget=0
    signal_df = []
    background_df = []
    data_df= []
    features_df = []
    target_df = []
    
    cross_sections = {}

    @staticmethod
    def add_signal(ntuples,sig, proc):
        IO.signalName.append(IO.ldata+ntuples+"/"+''.join(sig))
        IO.sigProc.append(proc)
        IO.nSig+=1

    @staticmethod
    def add_background(ntuples,bkg,proc):
        IO.backgroundName.append(IO.ldata+ntuples+"/"+''.join(bkg))
        IO.bkgProc.append(proc)
        IO.nBkg+=1
    
    @staticmethod
    def add_data(ntuples,data,proc):
        IO.dataName.append(IO.ldata+ntuples+"/"+''.join(data))
        IO.dataProc.append(proc)
        IO.nData+=1
        
    @staticmethod
    def add_target(ntuples,target_data,proc):
        IO.targetName.append(IO.ldata+ntuples+"/"+''.join(target_data))
        IO.targetProc.append(proc)
        IO.nTarget+=1
        
    @staticmethod
    def add_features(ntuples,features_data,proc):
        IO.featuresName.append(IO.ldata+ntuples+"/"+''.join(features_data))
        IO.featuresProc.append(proc)
        IO.nFeatures+=1





    



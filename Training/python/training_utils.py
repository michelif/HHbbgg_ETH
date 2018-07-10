import sys; sys.path.append("~/HHbbgg_ETH_devel/Training/python")
import matplotlib.pyplot as plt
import os


import random as rnd

from sklearn.utils.extmath import cartesian
import scipy.stats as stats

import random



# ---------------------------------------------------------------------------------------------------
class IO:
    ldata = os.path.expanduser("~/HHbbgg_ETH_devel/root_files/")
    xdata = "~/HHbbgg_ETH_devel/Training/output_files/"
    plotFolder = os.path.expanduser("~/HHbbgg_ETH_devel/Training/plots/")
    signalName = []
    signalTreeName = []
    backgroundName = []
    bkgTreeName = []
    dataName = []
    dataTreeName = []
    sigProc = []
    bkgProc = []
    dataProc = []
    nSig=0
    nBkg=0
    nData=0
    signal_df = []
    background_df = []
    data_df= []
    
    cross_sections = {}

    @staticmethod
    def add_signal(ntuples,sig, proc,treeName):
        IO.signalName.append(IO.ldata+ntuples+"/"+''.join(sig))
        IO.sigProc.append(proc)
        IO.nSig+=1
        IO.signalTreeName.append(treeName)

    @staticmethod
    def add_background(ntuples,bkg,proc,treeName):
        IO.backgroundName.append(IO.ldata+ntuples+"/"+''.join(bkg))
        IO.bkgProc.append(proc)
        IO.nBkg+=1
        IO.bkgTreeName.append(treeName)

    
    @staticmethod
    def add_data(ntuples,data,proc,treeName):
        IO.dataName.append(IO.ldata+ntuples+"/"+''.join(data))
        IO.dataProc.append(proc)
        IO.nData+=1
        IO.dataTreeName.append(treeName)




    



import root_pandas as rpd

from glob import glob
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import json
import os

import ROOT as RT

import random as rnd

from gzip import open as gopen
import cPickle as pickle

from sklearn.utils.extmath import cartesian
import scipy.stats as stats

import random

# ---------------------------------------------------------------------------------------------------
class IO:
    ldata = os.path.expanduser("~/HHbbgg_ETH/root_files/")
    xdata = "~/HHbbgg_ETH/Training/output_files/"
    signalName=" "
    backgroundName = " "
    
    @staticmethod
    def set_signal_and_background(ntuples,sig,bkg):
        IO.signalName=IO.ldata+ntuples+"/"+''.join(sig)
        IO.backgroundName=IO.ldata+ntuples+"/"+''.join(bkg)


    @staticmethod
    def list_files(folder,pattern):

        for x in glob(os.path.join(IO.ldata,folder,pattern)):
            yield os.path.join(IO.xdata,os.path.relpath(x,IO.ldata))

    @staticmethod
    def get_num_events(ifil):
        if IO.catalog == None:
            try:
                with open("catalog.json") as fin:
                    IO.catalog = json.reads(fin.read())
                    fin.close()
            except:
                IO.catalog = {}
        if not ifil in IO.catalog:
            fin = RT.TFile.Open(ifil)
            nevts = fin.Get("allEvents/hEventCount").GetEntries()
            fin.Close()
            IO.catalog[ ifil ] = nevts
            with open("catalog.json","w+") as fout:
                fout.write(json.dumps(IO.catalog))
                fout.close()
                
        return IO.catalog[ifil]
    
    @staticmethod
    def get_cross_section(folder):
        if IO.cross_sections == None:
            with open("cross_sections.json") as fin:
                IO.cross_sections = json.loads(fin.read())
                fin.close()
                
        return IO.cross_sections.get(os.path.basename(folder),-1.)
        
    @staticmethod
    def load_input_ntuples(folder,key="rflavourNtuplizer/tree",nfiles=None,nevents=None,shuffle=None,**kwargs):

        files = list( IO.list_files(folder,"*/*/*/*.root") )
        if shuffle:
            files = rnd.shuffle(files)
        if nfiles != None:
            files = files[:nfiles]

        
        # num_events = reduce(lambda x,y: x+y, map(lambda z: IO.get_num_events(z), files))
        num_events = 0.
        for ifil,fil in enumerate(files):
            num_events += IO.get_num_events(fil)
            if nevents and num_events >= nevents:
                files = files[:ifil+1]
                break
            
        xs = IO.get_cross_section(folder)["xs"]
        print(num_events, xs)
        weight = xs/float(num_events)

        df = None
        for ifil,fil in enumerate(files):            
            try:
                fdf = rpd.read_root(fil,key,**kwargs)
                df = fdf if ifil == 0 else df.append(fdf)
            except Exception, e:
                print("Failed to read file %s: %s" % (fil, e) )
        
        return weight,df
    

    @staticmethod
    def to_pickle(fname,obj):
        with gopen(fname,'w+') as fout:
            pickle.dump(obj,fout)
            fout.close()

    @staticmethod
    def read_pickle(fname):
        obj = None
        with gopen(fname,'r') as fin:
            obj = pickle.load(fin)
            fin.close()
        return obj
    
    
# ---------------------------------------------------------------------------------------------------
class preprocessing:
    
    
        @staticmethod
        def adjust_and_compress(df,doNhits=True,doFloat16=True):
            for col in df.columns:
                # print col,df[col].dtype,len(np.unique(df[col].dropna().values))
                if doNhits and col.startswith('Track_nHit'):
                    df[col] = df[col].fillna(0.).astype(np.int8)
                elif doFloat16 and df[col].dtype == np.float32:
                    df[col] = df[col].astype(np.float16)
                elif "index" in col:
                    df[col] = df[col].fillna(-1).astype(np.int8)
            return df
        
        @staticmethod
        def define_process_weight(df,proc,weight):
            df['proc'] = ( np.ones_like(df.index)*proc ).astype(np.int8)
            df['weight'] = ( np.ones_like(df.index)*weight ).astype(np.float32)
           
        @staticmethod
        def define_process_weight_bkg(df,proc,weight):
            df['proc'] = ( np.zeros_like(df.index)*proc ).astype(np.int8)
            df['weight'] = ( np.ones_like(df.index)*weight ).astype(np.float32)
        
        @staticmethod
        def get_training_sample(x,splitting=0.5):
            halfSample = int((x.size/len(x.columns))*splitting)
            return np.split(x,[halfSample])[0]
        
        @staticmethod
        def get_test_sample(x,splitting=0.5):
            halfSample = int((x.size/len(x.columns))*splitting)
            return np.split(x,[halfSample])[1]
        
        #fare unico metodo che ti ritorna i due usando questi sotto            
        @staticmethod    
        def get_total_training_sample(x_sig,x_bkg,splitting=0.5):
            halfSample_sig = int((x_sig.size/len(x_sig.columns))*splitting)
            halfSample_bkg = int((x_bkg.size/len(x_bkg.columns))*splitting)
            return np.concatenate([np.split(x_sig,[halfSample_sig])[0],np.split(x_bkg,[halfSample_bkg])[0]])
        
        @staticmethod    
        def get_total_test_sample(x_sig,x_bkg,splitting=0.5):
            halfSample_sig = int((x_sig.size/len(x_sig.columns))*splitting)
            halfSample_bkg = int((x_bkg.size/len(x_bkg.columns))*splitting)
            return np.concatenate([np.split(x_sig,[halfSample_sig])[1],np.split(x_bkg,[halfSample_bkg])[1]])


# ---------------------------------------------------------------------------------------------------
class plotting:
    @staticmethod
    def plot_classifier_output(clf,X_sig_train,X_bkg_train,X_sig_test,X_bkg_test):
        Y_pred_sig_train = clf.decision_function(X_sig_train).ravel()
        Y_pred_bkg_train = clf.decision_function(X_bkg_train).ravel()
        Y_pred_sig_test = clf.decision_function(X_sig_test).ravel()
        Y_pred_bkg_test = clf.decision_function(X_bkg_test).ravel()


        
        # This will be the min/max of our plots
        c_max = max(np.max(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))
        c_min = min(np.min(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))

        # Get histograms of the classifiers
        Histo_training_S = np.histogram(Y_pred_sig_train,bins=40,range=(c_min,c_max),normed=True)
        Histo_training_B = np.histogram(Y_pred_bkg_train,bins=40,range=(c_min,c_max),normed=True)
        Histo_testing_S = np.histogram(Y_pred_sig_test,bins=40,range=(c_min,c_max),normed=True)
        Histo_testing_B = np.histogram(Y_pred_bkg_test,bins=40,range=(c_min,c_max),normed=True)
        
        # Lets get the min/max of the Histograms
        AllHistos= [Histo_training_S,Histo_training_B,Histo_testing_S,Histo_testing_B]
        h_max = max([histo[0].max() for histo in AllHistos])*1.2
        h_min = min([histo[0].min() for histo in AllHistos])
        
        # Get the histogram properties (binning, widths, centers)
        bin_edges = Histo_training_S[1]
        bin_centers = ( bin_edges[:-1] + bin_edges[1:]  ) /2.
        bin_widths = (bin_edges[1:] - bin_edges[:-1])
        
        # To make error bar plots for the data, take the Poisson uncertainty sqrt(N)
        ErrorBar_testing_S = np.sqrt(Histo_testing_S[0]/Y_pred_sig_test.size)
        ErrorBar_testing_B = np.sqrt(Histo_testing_B[0]/Y_pred_bkg_test.size)
        
        # Draw objects
        ax1 = plt.subplot(111)
        
        # Draw solid histograms for the training data
        ax1.bar(bin_centers-bin_widths/2.,Histo_training_S[0],facecolor='blue',linewidth=0,width=bin_widths,label='S (Train)',alpha=0.5)
        ax1.bar(bin_centers-bin_widths/2.,Histo_training_B[0],facecolor='red',linewidth=0,width=bin_widths,label='B (Train)',alpha=0.5)
        
        # # Draw error-bar histograms for the testing data
        ax1.errorbar(bin_centers, Histo_testing_S[0], yerr=ErrorBar_testing_S, xerr=None, ecolor='blue',c='blue',fmt='o',label='S (Test)')
        ax1.errorbar(bin_centers, Histo_testing_B[0], yerr=ErrorBar_testing_B, xerr=None, ecolor='red',c='red',fmt='o',label='B (Test)')
        
        # Make a colorful backdrop to show the clasification regions in red and blue
        ax1.axvspan(0.0, c_max, color='blue',alpha=0.08)
        ax1.axvspan(c_min,0.0, color='red',alpha=0.08)
 
        # Adjust the axis boundaries (just cosmetic)
        ax1.axis([c_min, c_max, h_min, h_max])
 
        # Make labels and title
        plt.title("Classification with scikit-learn")
        plt.xlabel("Classifier output")
        plt.ylabel("Counts/Bin")
        
        # Make legend with smalll font
        legend = ax1.legend(loc='upper center', shadow=True,ncol=2)
        for alabel in legend.get_texts():
            alabel.set_fontsize('small')
 
        # Save the result to png
        plt.savefig("Sklearn_example.png")


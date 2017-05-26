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

from sklearn import model_selection
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.model_selection import train_test_split
from sklearn import grid_search
from sklearn.metrics import roc_curve, auc

import json
from pprint import pprint

# ---------------------------------------------------------------------------------------------------
class IO:
    ldata = os.path.expanduser("~/HHbbgg_ETH/root_files/")
    xdata = "~/HHbbgg_ETH/Training/output_files/"
    plotFolder = os.path.expanduser("~/HHbbgg_ETH/Training/plots/")
    signalName = []
    backgroundName = []
    nSig=0
    nBkg=0
    signal_df = []
    background_df = []
    weights_sig = []
    weights_bkg = []
    
    w_sig = []
    w_bkg = []

    cross_sections = {}

    @staticmethod
    def add_signal(ntuples,sig):
        IO.signalName.append(IO.ldata+ntuples+"/"+''.join(sig))
        IO.nSig+=1

    @staticmethod
    def add_background(ntuples,bkg):
        IO.backgroundName.append(IO.ldata+ntuples+"/"+''.join(bkg))
        IO.nBkg+=1
    
    @staticmethod
    def set_signal_and_background(ntuples,sig,bkg):
        IO.add_signal(ntuples,sig)
        IO.add_background(ntuples,bkg)


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
    def get_cross_sections(file):
        with open(IO.ldata+"../Training/"+file) as fin:
            IO.cross_sections = json.load(fin)
            fin.close()
#        pprint(IO.cross_sections)        
        return IO.cross_sections

    @staticmethod
    def get_xs(sigBkg,proc,nFile):   
        return   IO.cross_sections[sigBkg][proc]['files'][nFile]['xsec']*IO.cross_sections[sigBkg][proc]['files'][nFile]['br']*IO.cross_sections[sigBkg][proc]['files'][nFile]['sfactor']
        
    @staticmethod
    def get_nevents(sigBkg,proc,nFile):   
        return   IO.cross_sections[sigBkg][proc]['files'][nFile]['nevents']


    @staticmethod
    def get_weight(sigBkg,proc, nFile):   
        return IO.get_xs(sigBkg,proc,nFile)/IO.get_nevents(sigBkg,proc,nFile)



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
            x_s=pd.DataFrame(x_sig)
            x_b=pd.DataFrame(x_bkg)
            halfSample_s = int((x_s.size/len(x_s.columns))*splitting)
            halfSample_b = int((x_b.size/len(x_b.columns))*splitting)
            return np.concatenate([np.split(x_s,[halfSample_s])[0],np.split(x_b,[halfSample_b])[0]])
        
        @staticmethod    
        def get_total_test_sample(x_sig,x_bkg,splitting=0.5):
            x_s=pd.DataFrame(x_sig)
            x_b=pd.DataFrame(x_bkg)
            halfSample_s = int((x_s.size/len(x_s.columns))*splitting)
            halfSample_b = int((x_b.size/len(x_b.columns))*splitting)
            return np.concatenate([np.split(x_s,[halfSample_s])[1],np.split(x_b,[halfSample_b])[1]])

        @staticmethod
        def set_signals(treeName,branch_names,shuffle=True):
            for i in range(IO.nSig):
                IO.signal_df.append(rpd.read_root(IO.signalName[i],"bbggSelectionTree", columns = branch_names))
                if shuffle:
                    IO.signal_df[i]['random_index'] = np.random.permutation(range(IO.signal_df[i].index.size))
                    IO.signal_df[i].sort_values(by='random_index',inplace=True)
                    
#                preprocessing.adjust_and_compress(IO.signal_df[i]).to_hdf('/tmp/micheli/signal.hd5','sig',compression=9,complib='bzip2',mode='a')
                preprocessing.define_process_weight(IO.signal_df[i],i+1,IO.w_sig[i])
            
        @staticmethod
        def set_backgrounds(treeName,branch_names,shuffle=True):
            for i in range(IO.nBkg):
                IO.background_df.append(rpd.read_root(IO.backgroundName[i],"bbggSelectionTree", columns = branch_names))
                if shuffle:
                    IO.background_df[i]['random_index'] = np.random.permutation(range(IO.background_df[i].index.size))
                    IO.background_df[i].sort_values(by='random_index',inplace=True)

#                preprocessing.adjust_and_compress(IO.background_df[i]).to_hdf('/tmp/micheli/background.hd5','bkg',compression=9,complib='bzip2',mode='a')                                                                                       
                preprocessing.define_process_weight(IO.background_df[i],-(i+1),IO.w_bkg[i])

        @staticmethod
        def set_signals_and_backgrounds(treeName,branch_names,shuffle=True):
            #signals will have positive process number while bkg negative ones
            preprocessing.set_signals(treeName,branch_names,shuffle=True)
            preprocessing.set_backgrounds(treeName,branch_names,shuffle=True)

        @staticmethod
        def randomize(X,y,w):
            randomize=np.arange(len(X))
            np.random.shuffle(randomize)
            X = X[randomize]
            y = np.asarray(y)[randomize]
            w = np.asarray(w)[randomize]

            return X,y,w

        @staticmethod 
        def set_variables(branch_names):
            for i in range(IO.nSig):
                if i ==0:
                    y_sig = IO.signal_df[i][['proc']]
                    IO.weights_sig = IO.signal_df[i][['weight']]
                    for j in range(len(branch_names)):
                        if j == 0:
                            X_sig = IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                        else:
                            X_sig = np.concatenate([X_sig,IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
                else:
                    y_sig = np.concatenate((y_sig,IO.signal_df[i][['proc']]))
                    IO.weights_sig = np.concatenate((IO.weights_sig,IO.signal_df[i][['weight']]))
                    for j in range(len(branch_names)):
                        if j == 0:
                            X_sig_2 = IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                        else:
                            X_sig_2 = np.concatenate([X_sig_2,IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
                    X_sig=np.concatenate((X_sig,X_sig_2))

            for i in range(IO.nBkg):
                if i ==0:
                    y_bkg = IO.background_df[i][['proc']]
                    IO.weights_bkg = IO.background_df[i][['weight']]
                    for j in range(len(branch_names)):
                        if j == 0:
                            X_bkg = IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                        else:
                            X_bkg = np.concatenate([X_bkg,IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
                else:
                    y_bkg = np.concatenate((y_bkg,IO.background_df[i][['proc']]))
                    IO.weights_bkg = np.concatenate((IO.weights_bkg,IO.background_df[i][['weight']]))
                    for j in range(len(branch_names)):
                        if j == 0:
                            X_bkg_2 = IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                        else:
                            X_bkg_2 = np.concatenate([X_bkg_2,IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
                    X_bkg=np.concatenate((X_bkg,X_bkg_2))

            return X_bkg,y_bkg,X_sig,y_sig

# ---------------------------------------------------------------------------------------------------
class plotting:
    @staticmethod
    def plot_classifier_output(clf,X_total_train,X_total_test,y_total_train,y_total_test,outString=None):
        

        sig_train = X_total_train[y_total_train > 0]
        bkg_train = X_total_train[y_total_train == -2]
        sig_test = X_total_test[y_total_test > 0]
        bkg_test = X_total_test[y_total_test == -2]

        #if n_classses > 2 sig proba is the last one (in the way the code is written) 
        Y_pred_sig_train = clf.predict_proba(sig_train)[:,clf.n_classes_-1]
        Y_pred_bkg_train = clf.predict_proba(bkg_train)[:,clf.n_classes_-1]
        Y_pred_sig_test = clf.predict_proba(sig_test)[:,clf.n_classes_-1]
        Y_pred_bkg_test = clf.predict_proba(bkg_test)[:,clf.n_classes_-1]




        weights_sig_train = (np.ones_like(sig_train)/float(len(sig_train)))[:,1]
        weights_bkg_train = (np.ones_like(bkg_train)/float(len(bkg_train)))[:,1]
        weights_sig_test = (np.ones_like(sig_test)/float(len(sig_test)))[:,1]
        weights_bkg_test = (np.ones_like(bkg_test)/float(len(bkg_test)))[:,1]



        # This will be the min/max of our plots
        c_max = max(np.max(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))
        c_min = min(np.min(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))

        # Get histograms of the classifiers
        Histo_training_S = np.histogram(Y_pred_sig_train,bins=40,range=(c_min,c_max),weights=weights_sig_train)
        Histo_training_B = np.histogram(Y_pred_bkg_train,bins=40,range=(c_min,c_max),weights=weights_bkg_train)
        Histo_testing_S = np.histogram(Y_pred_sig_test,bins=40,range=(c_min,c_max),weights=weights_sig_test)
        Histo_testing_B = np.histogram(Y_pred_bkg_test,bins=40,range=(c_min,c_max),weights=weights_bkg_test)


        
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
        ax1.axvspan(0.5, c_max, color='blue',alpha=0.08)
        ax1.axvspan(c_min,0.5, color='red',alpha=0.08)
 
        # Adjust the axis boundaries (just cosmetic)
        ax1.axis([c_min, c_max, h_min, h_max])
 
        # Make labels and title
#        plt.title("Classification with scikit-learn")
        plt.xlabel("Classifier output")
        plt.ylabel("Normalized Yields")
        
        # Make legend with smalll font
        legend = ax1.legend(loc='upper center', shadow=True,ncol=2)
        for alabel in legend.get_texts():
            alabel.set_fontsize('small')
 
        # Save the result to png
        plt.savefig(IO.plotFolder+"classifierOutputPlot_"+str(outString)+".png")
        plt.savefig(IO.plotFolder+"classifierOutputPlot_"+str(outString)+".pdf")

    @staticmethod
    def plot_input_variables(X_sig,X_bkg,y_bkg=None,n_bins=30,outString=None,plotProcess=None):

        ncolumns = X_sig.size/len(X_sig)
        if plotProcess != None:
            X_bkg_2 = X_bkg[np.where(y_bkg==plotProcess),:][0] #this is to plot only one type of process
        else:
            X_bkg_2 = X_bkg

        for i in range(ncolumns):

            sig = X_sig[:,i]
            bkg = X_bkg_2[:,i]



            #trick to normalize
            weights_sig = np.ones_like(sig)/float(len(sig)) 
            weights_bkg = np.ones_like(bkg)/float(len(bkg)) 
            
            plt.hist(sig,color='b', alpha=0.5, bins=n_bins, range =[0,1],
                      label='Sig', weights=weights_sig)
            plt.hist(bkg,color='r',  alpha=0.5, bins=n_bins, range =[0,1],
                     label='Bkg', weights=weights_bkg )

            plt.savefig(IO.plotFolder+"variableDist"+str(i)+"_"+str(outString)+".png")
            plt.savefig(IO.plotFolder+"variableDist"+str(i)+"_"+str(outString)+".pdf")


            plt.show()

    @staticmethod
    def plot_roc_curve(x,y,clf,outString=None):
        decisions = clf.predict_proba(x)[:,1]
        # Compute ROC curve and area under the curve
        fpr, tpr, thresholds = roc_curve(y, decisions)
        roc_auc = auc(fpr, tpr)
        import matplotlib.pyplot as plt
        
        plt.plot(fpr, tpr, lw=1, label='ROC (area = %0.2f)'%(roc_auc))
        
        plt.xlim([-0.05, 1.05])
        plt.ylim([-0.05, 1.05])
        plt.xlabel('False Positive Rate')
        plt.ylabel('True Positive Rate')
        plt.title('ROC Curve')
        plt.legend(loc="lower right")
        plt.grid()

        plt.savefig(IO.plotFolder+"rocCurve"+"_"+str(outString)+".png")
        plt.savefig(IO.plotFolder+"rocCurve"+"_"+str(outString)+".pdf")

        
# ---------------------------------------------------------------------------------------------------
class optimization:
    @staticmethod
    def optimize_parameters_gridCV(classifier,X_total_train,y_total_train,param_grid,testSize=0.4,randomState=42):
        print "=====Optimization with grid search cv====="
        scores = model_selection.cross_val_score(classifier,
                                          X_total_train, y_total_train,
                                          scoring="roc_auc",
                                          n_jobs=6,
                                          cv=3)
        print "-Initial Accuracy-"
        print "Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std())

        
#param_grid = {"n_estimators": [50,200,400,1000],
#              "max_depth": [1, 3, 8],
#              'learning_rate': [0.1, 0.2, 1.]}
        
        X_train, X_test, y_train, y_test = train_test_split(X_total_train, y_total_train, test_size=testSize, random_state=randomState)
        
        
        clf = grid_search.GridSearchCV(classifier,
                                       param_grid,
                                       cv=3,
                                       scoring='roc_auc',
                                       n_jobs=8, verbose=1)
        clf.fit(X_train, y_train)
        
        print "Best parameter set found on development set:"
        print
        print clf.best_estimator_
        print
        print "Grid scores on a subset of the development set:"
        print
        for params, mean_score, scores in clf.grid_scores_:
            print "%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params)
        
        return clf.grid_scores_

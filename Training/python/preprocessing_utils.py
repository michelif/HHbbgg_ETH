import training_utils as utils
import os
import numpy as np
import pandas as pd
import root_pandas as rpd


def define_process_weight(df,proc,name,treename='bbggSelectionTree',cleanSignal=True):
    df['proc'] = ( np.ones_like(df.index)*proc ).astype(np.int8)
    if treename=='bbggSelectionTree':
        df['weight'] = ( np.ones_like(df.index)).astype(np.float32)
        input_df=rpd.read_root(name,treename, columns = ['genTotalWeight', 'lumiFactor','isSignal','puweight'])
        w = np.multiply(input_df[['lumiFactor']],input_df[['genTotalWeight']])
        w = np.multiply(w,input_df[['puweight']])
        df['lumiFactor'] = input_df[['lumiFactor']]
        df['genTotalWeight'] = input_df[['genTotalWeight']]
        df['isSignal'] = input_df[['isSignal']]
        if cleanSignal:#some trees include also the control region,select only good events
            df['weight']= np.multiply(w,input_df[['isSignal']])
        else:
            df['weight']=w



def define_process_weight_CR(df,proc,name,treename='bbggSelectionTree'):
    df['proc'] = ( np.ones_like(df.index)*proc ).astype(np.int8)
    df['weight'] = ( np.ones_like(df.index)).astype(np.float32)
    input_df=rpd.read_root(name,treename, columns = ['isPhotonCR'])
    w = input_df[['isPhotonCR']]
    df['weight']=w

 
def clean_signal_events(x_b, y_b, w_b,x_s,y_s,w_s,event_num_bkg = None, event_num_sig = None):#some trees include also the control region,select only good events
    if (event_num_bkg is None and event_num_sig is None) : return x_b[np.where(w_b!=0),:][0],y_b[np.where(w_b!=0)],w_b[np.where(w_b!=0)], x_s[np.where(w_s!=0),:][0], np.asarray(y_s)[np.where(w_s!=0)],np.asarray(w_s)[np.where(w_s!=0)]
    else : 
        return x_b[np.where(w_b!=0),:][0],y_b[np.where(w_b!=0)],w_b[np.where(w_b!=0)],event_num_bkg[np.where(w_b!=0)], x_s[np.where(w_s!=0),:][0], y_s[np.where(w_s!=0)],w_s[np.where(w_s!=0)],event_num_sig[np.where(w_s!=0)]

 
def clean_signal_events_single_dataset(x_b, y_b, w_b):#some trees include also the control region,select only good events
    return x_b[np.where(w_b!=0),:][0],np.asarray(y_b)[np.where(w_b!=0)],np.asarray(w_b)[np.where(w_b!=0)]

    
                       
def normalize_process_weights(w_b,y_b,w_s,y_s):
    proc=999
    sum_weights = 1
    w_bkg = []
    for i in range(utils.IO.nBkg):
        if utils.IO.bkgProc[i] != proc:
#            w_proc = np.asarray(np.absolute(w_b[np.asarray(y_b) == utils.IO.bkgProc[i]]))#absolute is important to normalize in case of negative weights
            w_proc = np.asarray(w_b[np.asarray(y_b) == utils.IO.bkgProc[i]])#absolute is important to normalize in case of negative weights
            sum_weights = float(np.sum(w_proc))
            proc = utils.IO.bkgProc[i]
            if i==0:
                w_bkg = np.divide(w_proc,sum_weights)
            else:
                w_bkg = np.concatenate((w_bkg, np.divide(w_proc,sum_weights)))
            utils.IO.background_df[i][['weight']] = np.divide(utils.IO.background_df[i][['weight']],sum_weights)


    proc=999
    sum_weights = 1
    w_sig = []
    for i in range(utils.IO.nSig):
        if utils.IO.sigProc[i] != proc:
            w_proc = np.asarray(w_s[np.asarray(y_s) == utils.IO.sigProc[i]])
            sum_weights = np.sum(w_proc)
            proc = utils.IO.sigProc[i]
            print sum_weights
        if i==0:
            w_sig = np.divide(w_proc,sum_weights)
        else:
            w_sig = np.concatenate((w_sig, np.divide(w_proc,sum_weights)))
        utils.IO.signal_df[i][['weight']] = np.divide(utils.IO.signal_df[i][['weight']],sum_weights)



    return w_bkg,w_sig


def scale_process_weight(w_b,y_b,proc,sf):
    w_bkg = []
    process=999
    for i in range(utils.IO.nBkg):
        if utils.IO.bkgProc[i] == proc:
            utils.IO.background_df[i][['weight']] = np.multiply(utils.IO.background_df[i][['weight']],sf)
            w_proc = np.asarray(utils.IO.background_df[i][['weight']])
        else:
            if process == utils.IO.bkgProc[i]: #don't do twice multiple samples of same process, like GJet
                continue
            process =  utils.IO.bkgProc[i]
            w_b = np.reshape(w_b,(len(w_b),1))


            w_proc = np.asarray(w_b[np.asarray(y_b) == utils.IO.bkgProc[i]])
            w_proc = np.reshape(w_proc,(len(w_proc),1))
            
        if i == 0:
            w_bkg = w_proc
        else:
            w_bkg =  np.concatenate((w_bkg,w_proc))

    return w_bkg.reshape(len(w_bkg),1) 

def weight_signal_with_resolution(w_s,y_s,branch='sigmaMOverMDecorr'):
    proc=999
    for i in range(utils.IO.nSig):
        w_sig = np.asarray(w_s[np.asarray(y_s) == utils.IO.sigProc[i]])
        proc = utils.IO.sigProc[i]
        utils.IO.signal_df[i][['weight']] = np.divide(utils.IO.signal_df[i][['weight']],utils.IO.signal_df[i][[branch]])

    return utils.IO.signal_df[i][['weight']]

def weight_signal_with_resolution_bjet(w_s,y_s,branch='(sigmaMJets*1.4826)'):
    proc=999
    for i in range(utils.IO.nSig):
        w_sig = np.asarray(w_s[np.asarray(y_s) == utils.IO.sigProc[i]])
        proc = utils.IO.sigProc[i]
        utils.IO.signal_df[i][['weight']] = np.divide(utils.IO.signal_df[i][['weight']],utils.IO.signal_df[i][[branch]])

    return utils.IO.signal_df[i][['weight']]



def weight_background_with_resolution(w_b,y_b,proc,branch='sigmaMOverMDecorr'):
    w_bkg = []
    process=999
    for i in range(utils.IO.nBkg):
        if utils.IO.bkgProc[i] == proc:
            
            utils.IO.background_df[i][['weight']] = np.divide(utils.IO.background_df[i][['weight']],utils.IO.background_df[i][[branch]])
            w_proc = np.asarray(utils.IO.background_df[i][['weight']])
            np.reshape(w_proc,(len(utils.IO.background_df[i][['weight']]),))
        else:
            if process == utils.IO.bkgProc[i]: #don't do twice multiple samples of same process, like GJet
                continue
            process =  utils.IO.bkgProc[i]
            w_proc = np.asarray(w_b[np.asarray(y_b) == utils.IO.bkgProc[i]])

        if i == 0:
            w_bkg = w_proc
        else:
            w_bkg =  np.concatenate((w_bkg,np.asarray(w_proc.ravel())))
        
            
    return w_bkg.reshape(len(w_bkg),1)




def get_training_sample(x,splitting=0.5):
    halfSample = int((x.size/len(x.columns))*splitting)
    return np.split(x,[halfSample])[0]


def get_test_sample(x,splitting=0.5):
    halfSample = int((x.size/len(x.columns))*splitting)
    return np.split(x,[halfSample])[1]

    
def get_total_training_sample(x_sig,x_bkg,splitting=0.5):
    x_s=pd.DataFrame(x_sig)
    x_b=pd.DataFrame(x_bkg)
    halfSample_s = int((x_s.size/len(x_s.columns))*splitting)
    halfSample_b = int((x_b.size/len(x_b.columns))*splitting)
    return np.concatenate([np.split(x_s,[halfSample_s])[0],np.split(x_b,[halfSample_b])[0]])

    
def get_total_test_sample(x_sig,x_bkg,splitting=0.5):
    x_s=pd.DataFrame(x_sig)
    x_b=pd.DataFrame(x_bkg)
    halfSample_s = int((x_s.size/len(x_s.columns))*splitting)
    halfSample_b = int((x_b.size/len(x_b.columns))*splitting)
    return np.concatenate([np.split(x_s,[halfSample_s])[1],np.split(x_b,[halfSample_b])[1]])

def get_total_test_sample_event_num(x_sig,x_bkg,event_sig,event_bkg):
    x_s = x_sig[np.where(event_sig%2==0)]
    x_b = x_bkg[np.where(event_bkg%5==0)]
    return np.concatenate((x_s,x_b))

def get_total_training_sample_event_num(x_sig,x_bkg,event_sig,event_bkg):
    x_s = x_sig[np.where(event_sig%2!=0)]
    x_b = x_bkg[np.where(event_bkg%5!=0)]
    return np.concatenate((x_s,x_b))



def set_signals(branch_names,shuffle,cuts='event>=0'):
    for i in range(utils.IO.nSig):
        treeName = utils.IO.signalTreeName[i]
        print "using tree:"+treeName
        utils.IO.signal_df.append((rpd.read_root(utils.IO.signalName[i],treeName, columns = branch_names)).query(cuts))
        define_process_weight(utils.IO.signal_df[i],utils.IO.sigProc[i],utils.IO.signalName[i],treeName)
        if shuffle:
            utils.IO.signal_df[i]['random_index'] = np.random.permutation(range(utils.IO.signal_df[i].index.size))
            utils.IO.signal_df[i].sort_values(by='random_index',inplace=True)
            
#         adjust_and_compress(utils.IO.signal_df[i]).to_hdf('/tmp/micheli/signal.hd5','sig',compression=9,complib='bzip2',mode='a')

    
    
def set_signals_drop(branch_names,shuffle,cuts='event>=0'):
    for i in range(utils.IO.nSig):
        treeName = utils.IO.signalTreeName[i]
        print "using tree:"+treeName
        df = (rpd.read_root(utils.IO.signalName[i],treeName, columns = branch_names)).query(cuts)
     #   index = [21365, 37561, 45119, 140896, 169444, 178771]
      #  df = drop_from_df(df,index)
        df = drop_nan(df)
        utils.IO.signal_df.append(df)
        define_process_weight(utils.IO.signal_df[i],utils.IO.sigProc[i],utils.IO.signalName[i],treeName)
        if shuffle:
            utils.IO.signal_df[i]['random_index'] = np.random.permutation(range(utils.IO.signal_df[i].index.size))
            utils.IO.signal_df[i].sort_values(by='random_index',inplace=True)
            
#         adjust_and_compress(utils.IO.signal_df[i]).to_hdf('/tmp/micheli/signal.hd5','sig',compression=9,complib='bzip2',mode='a')
    
    
    
    

def set_backgrounds(branch_names,shuffle,cuts='event>=0'):
    for i in range(utils.IO.nBkg):
        treeName = utils.IO.bkgTreeName[i]
        print "using tree:"+treeName
        utils.IO.background_df.append((rpd.read_root(utils.IO.backgroundName[i],treeName, columns = branch_names)).query(cuts))
        define_process_weight(utils.IO.background_df[i],utils.IO.bkgProc[i],utils.IO.backgroundName[i],treeName)
        if shuffle:
            utils.IO.background_df[i]['random_index'] = np.random.permutation(range(utils.IO.background_df[i].index.size))
            utils.IO.background_df[i].sort_values(by='random_index',inplace=True)

#         adjust_and_compress(utils.IO.background_df[i]).to_hdf('/tmp/micheli/background.hd5','bkg',compression=9,complib='bzip2',mode='a')



def set_data(branch_names,cuts='event>=0'):
    treeName = utils.IO.dataTreeName[0]
    utils.IO.data_df.append((rpd.read_root(utils.IO.dataName[0],treeName, columns = branch_names)).query(cuts))
    utils.IO.data_df[0]['proc'] =  ( np.ones_like(utils.IO.data_df[0].index)*utils.IO.dataProc[0] ).astype(np.int8)
    if treeName=='bbggSelectionTree':
       input_df=rpd.read_root(utils.IO.dataName[0],treeName, columns = ['isSignal'])
       w = (np.ones_like(utils.IO.data_df[0].index)).astype(np.int8)
       utils.IO.data_df[0]['weight'] = np.multiply(w,input_df['isSignal'])


def set_variables_data(branch_names):
    y_data = utils.IO.data_df[0][['proc']]
    w_data = utils.IO.data_df[0][['weight']]
    for j in range(len(branch_names)):
        if j == 0:
            X_data = utils.IO.data_df[0][[branch_names[j].replace('noexpand:','')]]
        else:
            X_data = np.concatenate([X_data,utils.IO.data_df[0][[branch_names[j].replace('noexpand:','')]]],axis=1)
    
    return np.round(X_data,5),y_data,w_data
    
    

def set_signals_and_backgrounds(branch_names,shuffle=True,cuts='event>=0'):
    #signals will have positive process number while bkg negative ones
    set_signals(branch_names,shuffle,cuts)
    set_backgrounds(branch_names,shuffle,cuts)

    
def set_signals_and_backgrounds_drop(branch_names,shuffle=True,cuts='event>=0'):
    #signals will have positive process number while bkg negative ones
    set_signals_drop(branch_names,shuffle,cuts)
    set_backgrounds(branch_names,shuffle,cuts)
    
    

def randomize(X,y,w,event_num=None,seed=0):
    randomize=np.arange(len(X))
    np.random.seed(seed)
    np.random.shuffle(randomize)
    X = X[randomize]
    y = np.asarray(y)[randomize]
    w = np.asarray(w)[randomize]
    if event_num is None :
        event_num = np.asarray(event_num)[randomize]
        return X,y,w
    else : 
        return X,y,w,event_num


 
def set_variables(branch_names,use_event_num=False):
    for i in range(utils.IO.nSig):
        if i ==0:
            y_sig = utils.IO.signal_df[i][['proc']]
            w_sig = utils.IO.signal_df[i][['weight']]
            if use_event_num :  event_sig = utils.IO.signal_df[i][['event']]
            for j in range(len(branch_names)):
                if j == 0:
                    X_sig = utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_sig = np.concatenate([X_sig,utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
        else:
            y_sig = np.concatenate((y_sig,utils.IO.signal_df[i][['proc']]))
            w_sig = np.concatenate((w_sig,utils.IO.signal_df[i][['weight']]))
            if use_event_num : event_sig = np.concatenate((event_sig,utils.IO.signal_df[i][['event']]))
            for j in range(len(branch_names)):
                if j == 0:
                    X_sig_2 = utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_sig_2 = np.concatenate([X_sig_2,utils.IO.signal_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
            X_sig=np.concatenate((X_sig,X_sig_2))

    for i in range(utils.IO.nBkg):
        if i ==0:
            y_bkg = utils.IO.background_df[i][['proc']]
            w_bkg = utils.IO.background_df[i][['weight']]
            if use_event_num : event_bkg = utils.IO.background_df[i][['event']]
            for j in range(len(branch_names)):
                if j == 0:
                    X_bkg = utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_bkg = np.concatenate([X_bkg,utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
        else:
            y_bkg = np.concatenate((y_bkg,utils.IO.background_df[i][['proc']]))
            w_bkg = np.concatenate((w_bkg,utils.IO.background_df[i][['weight']]))
            if use_event_num : event_bkg = np.concatenate((event_bkg,utils.IO.background_df[i][['event']]))
            for j in range(len(branch_names)):
                if j == 0:
                    X_bkg_2 = utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]
                else:
                    X_bkg_2 = np.concatenate([X_bkg_2,utils.IO.background_df[i][[branch_names[j].replace('noexpand:','')]]],axis=1)
            X_bkg=np.concatenate((X_bkg,X_bkg_2))

    if not use_event_num :  return np.round(X_bkg,5),y_bkg,w_bkg,np.round(X_sig,5),y_sig,w_sig
    else :   return np.round(X_bkg,5),y_bkg,w_bkg,event_bkg,np.round(X_sig,5),y_sig,w_sig,event_sig

   

def check_for_nan(df,branch_name='event'):
    print df.isnull().sum()
    index = df[branch_name].index[df[branch_name].apply(np.isnan)]
    print 'event numbers for nan events : ', df['event'][index]
    new_df = df.drop(df.index[index])
    return new_df


    
def drop_from_df(df,index):
    return df.drop(df.index[index])

def drop_nan(df):
    return df.dropna()

def profile(target,xvar,bins=10,range=None,uniform=False,moments=True,
            quantiles=np.array([0.25,0.5,0.75])):

    if range is None:
        if type(bins) is not int:
            xmin, xmax = bins.min(), bins.max()
        else:
            xmin, xmax = xvar.min(),xvar.max()
    else:
        xmin, xmax = range
    mask = ( xvar >= xmin ) & ( xvar <= xmax )
    xvar = xvar[mask]
    target = target[mask]
    if type(bins) == int:
        if uniform:
            bins = np.linspace(xmin,xmax,num=bins+1)
        else:
            ## print(xmin,xmax)
            ## xvar = np.clip( xvar, xmin, xmax )
            bins = np.percentile( xvar, np.linspace(0,100.,num=bins+1) )
            bins[0] = xmin
            bins[-1] = xmax
    print bins.shape 
    ibins = np.digitize(xvar,bins)-1
    categories = np.eye(np.max( ibins ) + 1)[ibins]

    ret = [bins]
    if moments:
        mtarget = target.reshape(-1,1) * categories
        weights = categories
        mean = np.average(mtarget,weights=categories,axis=0)
        mean2 = np.average(mtarget**2,weights=categories,axis=0)
        ret.extend( [mean, np.sqrt( mean2 - mean**2)] )
    if quantiles is not None:
        values = []
        print(categories.shape[1])
        for ibin in np.arange(categories.shape[1],dtype=int):
            values.append( np.percentile(target[categories[:,ibin].astype(np.bool)],quantiles*100.,axis=0).reshape(-1,1) )
            ## print(values)
        ret.append( np.concatenate(values,axis=-1) )
    return tuple(ret)

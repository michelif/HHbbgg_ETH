import training_utils as utils

import numpy as np

# ---------------------------------------------------------------------------------------------------
def stackFeatures(df,additionalCut_names,rounding=6,SF=1,isData=0):
    vec = []
    dictVar = {}
    i = 0
    for featCounter in additionalCut_names:
        feat= featCounter.replace("noexpand:","")
        vec.append(np.round(np.asarray(df[feat]),rounding))
        dictVar [feat] = i
        i+=1

    if not isData:
        vec.append(np.multiply(np.asarray(df['weight']),SF))  
    else:
        w = (np.ones_like(utils.IO.data_df[0].index)).astype(np.int8)
        vec.append(np.multiply(w,df['isSignal']))
    dictVar['weight'] = i
        


    totalVec = []
    for i in range(len(vec)):
        if i == 0:
            totalVec = vec[i]
        else:
            totalVec = np.column_stack((totalVec,vec[i]))


    return totalVec,dictVar



def stackFeaturesReg(df,additionalCut_names,rounding=5):
    vec = []
    dictVar = {}
    i = 0
    for featCounter in additionalCut_names:
        feat= featCounter.replace("noexpand:","")
        vec.append(np.round(np.asarray(df[feat]),rounding))
        dictVar [feat] = i
        i+=1
        
    totalVec = []
    for i in range(len(vec)):
        if i == 0:
            totalVec = vec[i]
        else:
            totalVec = np.column_stack((totalVec,vec[i]))

    return totalVec,dictVar



def stackAddFeaturesReg(df,additionalCut_names,addDictionary,rounding=5):
    vec = []
    dictVar = {}
    i = 0
    for featCounter in additionalCut_names:
        feat= featCounter.replace("noexpand:","")
        vec.append(np.round(np.asarray(df[feat]),rounding))
        dictVar [feat] = i
        i+=1

    for featCounter,value in addDictionary.items():
        feat= featCounter.replace("noexpand:","")
        vec.append(np.round(value,rounding))
        dictVar [feat] = i
        i+=1
        
    totalVec = []
    for i in range(len(vec)):
        if i == 0:
            totalVec = vec[i]
        else:
            totalVec = np.column_stack((totalVec,vec[i]))

    return totalVec,dictVar




def applyCut(vec,varNum,cut,option='greater'):
    if option == 'greater':
        return vec[np.where(vec[:,varNum]>cut)]
    elif option == 'smaller':
        return vec[np.where(vec[:,varNum]<cut)]
    elif option == 'different':
        return vec[np.where(vec[:,varNum]!=cut)]



def cutInvariantMass(vec,varNum,xLow,xUp):
    nCleaned_massWindowDown = applyCut(vec,varNum,xLow)
    nCleaned_massWindow = applyCut(nCleaned_massWindowDown,varNum,xUp,'smaller')
    return nCleaned_massWindow


def saveTreeReg(processPath,dictVar,vector,MVAVector=None,SF=1,nameTree="reducedTree"):
    from root_numpy import array2root
    i=0
    for key in list(dictVar.keys()):
         if i == 0:
             writeMode='recreate'
             i=1
         else:
             writeMode='update'

         v=(np.asarray(vector[:,dictVar[key]]))
         name = key

         v.dtype = [(name.replace(".","").replace("(","").replace(")","").replace("/","_Over_").replace("Candidate",""), np.float64)]


         array2root(v, processPath, nameTree, mode = writeMode)

    if MVAVector != None:

            v=(np.asarray(MVAVector.ravel()))
            v.dtype = [('RegressedFactor', np.float64)]
            array2root(v, processPath, nameTree, mode ='update')




def saveTree(processPath,dictVar,vector,MVAVector=None,SF=1,nameTree="reducedTree"):
    from root_numpy import array2root
    i=0
    for key in list(dictVar.keys()):
         if i == 0:
             writeMode='recreate'
             i=1
         else:
             writeMode='update'

         v=(np.asarray(vector[:,dictVar[key]]))
         name = key
         if key == 'diphotonCandidate.M()':
             name = 'Mgg'
         elif key == 'dijetCandidate.M()':
             name = 'Mjj'

         if SF != 1:
             if key == 'weight':
                 v = (np.multiply(np.asarray(v),SF))

         v.dtype = [(name.replace(".","").replace("(","").replace(")","").replace("/","_Over_").replace("_","").replace("Candidate",""), np.float64)]


         array2root(v, processPath, nameTree, mode = writeMode)

    if MVAVector != None:

            v=(np.asarray(MVAVector.ravel()))
            v.dtype = [('MVAOutput', np.float64)]
            array2root(v, processPath, nameTree, mode ='update')

            
            
            
def get_mean_width(file_pt):
    open_pt = open(file_pt, 'r') 
    data = open_pt.readlines()
    data_pt=[]
    data_er=[]
    for item,line in enumerate(data):
        words = line.split()
        if '+/-' in words:
            data_pt.append(float(words[0]))
            data_er.append(float(words[2]))
    open_pt.close() 
    return data_pt[:int(len(data_pt)/2)], data_pt[int(len(data_pt)/2):],data_er[:int(len(data_er)/2)], data_er[int(len(data_er)/2):]

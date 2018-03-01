import os
import pandas as pd
import numpy as np
import sys

start = int(sys.argv[1])
end = int(sys.argv[2])

targetdir='/scratch/nchernya/HHbbgg/ttbar_morevariables/'
#list the files
file_list=[0,1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,55,56,57,58,59,61,62,64,65,66,67,68,69,73,75,78,79,80,81,82,83,84,85,86,87,88,90,91,92,93,94,95,96,97,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,154]
filelist = [targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_%d_full.hd5'%num for num in file_list]
##read them into pandas
df_list = [pd.read_hdf(file,columns=None) for file in filelist[start:end]]
#print 'list done'
###concatenate them together
big_df = pd.concat([df_list[i] for i in range(0,len(df_list))],ignore_index=True)
big_df['isEle'] = np.zeros( (big_df.shape[0],1) )
big_df['isMu'] = np.zeros( (big_df.shape[0],1) )
big_df['isOther'] = np.zeros( (big_df.shape[0],1) )
big_df['Jet_withPtd'] = big_df['Jet_ptd']
big_df.loc[abs(big_df.Jet_leptonPdgId) == 11,'isEle'] = 1
big_df.loc[abs(big_df.Jet_leptonPdgId) == 13,'isMu'] = 1
big_df.loc[big_df.Jet_leptonPdgId == -99,'isOther'] = 1
big_df.loc[big_df.Jet_ptd < 0 ,'Jet_withPtd' ] = big_df[ big_df['Jet_ptd'] > 0 ]['Jet_ptd'].median()
big_df.loc[big_df.Jet_leptonPtRelInv < 0 ,'Jet_leptonPtRelInv' ] = 0
big_df.to_hdf(targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_con%d%d_morevar.hd5'%(start,end)  ,'w')

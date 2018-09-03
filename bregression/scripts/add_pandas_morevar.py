import os
import pandas as pd
import numpy as np
import sys

start = int(sys.argv[1])
end = int(sys.argv[2])

#targetdir='/scratch/nchernya/HHbbgg/ttbar_morevariables/'
#targetdir = '/scratch/nchernya/HHbbgg/ttbar_2017_v2/'
#targetdir = '/scratch/nchernya/HHbbgg/othersamples_morevar/'
#targetdir = '/scratch/nchernya/HHbbgg/ttbar_2017_v3_newJEC/'
targetdir = '/scratch/nchernya/HHbbgg/ttbar_2016_legacy_JECv11/'
#targetdir = '/scratch/nchernya/HHbbgg/'
#list the files
#filelist = [targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_%d_full.hd5'%num for num in file_list]
file_list  = [94 , 18 , 2 , 55 , 16 , 40 , 97 , 35 , 37 , 98 , 7 , 31 , 51 , 45 , 8 , 65 , 41 , 56 , 83 , 89 , 69 , 99 , 88 , 79 , 21 , 12 , 17 , 3 , 30 , 32 , 26 , 27 , 70 , 73 , 13 , 92 , 59 , 93 , 64 , 100 , 22 , 46 , 50 , 78 , 84 , 54 , 60 , 20 , 36 , 11 , 75 , 74 , 149 , 124 , 129 , 142 , 114 , 147 , 148 , 109 , 138 , 115 , 120 , 144 , 106 , 133 , 104 , 110 , 152 , 153 , 101 , 125 , 105 , 134 , 119 , 128 , 139 , 143 , 123 , 25 , 113 , 44 , 132 , 63 , 151 , 118 , 82 , 49 , 137 , 68 , 87 , 1 , 6 , 10 , 15 , 103 , 34 , 122 , 53 , 141 , 108 , 72 , 39 , 127 , 91 , 58 , 146 , 77 , 96 , 24 , 112 , 43 , 131 , 62 , 150 , 29 , 117 , 81 , 48 , 136 , 67 , 155 , 86 , 5 , 14 , 102 , 33 , 121 , 52 , 140 , 19 , 107 , 71 , 38 , 126 , 90 , 57 , 145 , 76 , 95 , 23 , 111 , 42 , 130 , 61 , 28 , 116 , 80 , 47 , 135 , 66 , 154 , 85 , 4 , 9 ] 
#name='TTbar_2ptds_RegressionPerJet_heppy_energyRings_forTraining_10_full_2ptd'
#filelist=[targetdir+'%s.hd5'%name]
filelist = [targetdir+'/TTbar_legacy2016_JECv11_RegressionPerJet_heppy_energyRings_forTraining_%d_legacy_2ptds.hd5'%num for num in file_list]
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
big_df.loc[abs(big_df.Jet_leptonPdgId) == 13,'isMu'] = 1#big_df.loc[big_df.Jet_leptonPdgId == -99,'isOther'] = 1  #2016
big_df.loc[big_df.Jet_leptonPdgId == -99,'isOther'] = 1  #2016
#big_df.loc[big_df.Jet_leptonPdgId == 0,'isOther'] = 1  #2017
big_df.loc[big_df.Jet_ptd < 0 ,'Jet_withPtd' ] = big_df[ big_df['Jet_ptd'] > 0 ]['Jet_ptd'].median()  #2016
big_df.loc[big_df.Jet_leptonPtRelInv < 0 ,'Jet_leptonPtRelInv' ] = 0  #2016
#big_df.to_hdf(targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_con%d%d_morevar.hd5'%(start,end)  ,'w')
#big_df.to_hdf(targetdir+'/ZHbbll_RegressionPerJet_heppy_energyRings_forTesting_morevar.hd5','w')big_df.to_hdf(targetdir+'/TTbar_nanoAOD_RegressionPerJet_nanoAOD_2017_v3_newJEC_con%d%d_allvar.hd5'%(start,end)  ,'w')
big_df.to_hdf(targetdir+'/TTbar_legacy2016_JECv11_RegressionPerJet_heppy_energyRings_forTraining_legacy_2ptds_con%d%d_allvar.hd5'%(start,end)  ,'w')
#big_df.to_hdf(targetdir+'/%s_morevar.hd5'%(name)  ,'w')

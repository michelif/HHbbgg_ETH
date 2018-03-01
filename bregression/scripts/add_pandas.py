import os
import pandas as pd
import numpy as np


targetdir='/scratch/nchernya/HHbbgg/ttbar_full_hd5/'
#list the files
filelist = os.listdir(targetdir) 
#print filelist[136]
filelist = [targetdir+file for file in filelist]
#print filelist
##read them into pandas
df_list = [pd.read_hdf(file,columns=None) for file in filelist[0:136]]
#print 'list done'
#list_concat=[]
###concatenate them together
big_df = pd.concat([df_list[i] for i in range(130,133)],ignore_index=True)
big_df.to_hdf(targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_con130133_full.hd5'  ,'w')

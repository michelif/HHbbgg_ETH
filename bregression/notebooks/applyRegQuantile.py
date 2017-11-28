
# coding: utf-8

# In[9]:

import os
import sys; sys.path.append("~/HHbbgg_ETH_devel/bregression/python") # to load packages
import training_utils as utils
import numpy as np
reload(utils)
import preprocessing_utils as preprocessing
reload(preprocessing)
import plotting_utils as plotting
reload(plotting)
import optimization_utils as optimization
reload(optimization)
import postprocessing_utils as postprocessing
reload(postprocessing)
import matplotlib.pyplot as plt


# In[10]:

ntuples = 'heppy_05_10_2017'
# "%" sign allows to interpret the rest as a system command
get_ipython().magic(u'env data=$utils.IO.ldata$ntuples')
files = get_ipython().getoutput(u'ls $data | sort -t_ -k 3 -n')

ttbar= [s for s in files if "ttbar_RegressionPerJet_heppy_energyRings3_forTesting.root" in s] #energy rings large and proper sample with Jet_e


utils.IO.add_features(ntuples,ttbar,1)

for i in range(len(utils.IO.featuresName)):        
    print "using features file n."+str(i)+": "+utils.IO.featuresName[i]


# In[11]:

import pandas as pd
import root_pandas as rpd

branch_names = 'Jet_pt_reg,Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,noexpand:Jet_mcPt/Jet_pt,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03,nPVs,Jet_leptonPt'.split(",") #same as Caterina
features = 'Jet_pt,Jet_eta,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em_Jet_e,Jet_energyRing_dR1_em_Jet_e,Jet_energyRing_dR2_em_Jet_e,Jet_energyRing_dR3_em_Jet_e,Jet_energyRing_dR4_em_Jet_e,Jet_energyRing_dR0_neut_Jet_e,Jet_energyRing_dR1_neut_Jet_e,Jet_energyRing_dR2_neut_Jet_e,Jet_energyRing_dR3_neut_Jet_e,Jet_energyRing_dR4_neut_Jet_e,Jet_energyRing_dR0_ch_Jet_e,Jet_energyRing_dR1_ch_Jet_e,Jet_energyRing_dR2_ch_Jet_e,Jet_energyRing_dR3_ch_Jet_e,Jet_energyRing_dR4_ch_Jet_e,Jet_energyRing_dR0_mu_Jet_e,Jet_energyRing_dR1_mu_Jet_e,Jet_energyRing_dR2_mu_Jet_e,Jet_energyRing_dR3_mu_Jet_e,Jet_energyRing_dR4_mu_Jet_e,Jet_numDaughters_pt03'.split(",") #same as Caterina
cuts='(Jet_pt > 20) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt>0) & (Jet_mcPt<6000)'




branch_names = [c.strip() for c in branch_names]
features = [c.strip() for c in features]




# In[12]:

from sklearn.externals import joblib
import pandas as pd
import root_pandas as rpd

data_frame = (rpd.read_root(utils.IO.featuresName[0],"tree", columns = branch_names)).query(cuts)
for j in range(len(features)):
	if j == 0:
		X_features = data_frame[[features[j].replace('noexpand:','')]]
	else:
 		X_features = np.concatenate([X_features,data_frame[[features[j].replace('noexpand:','')]]],axis=1)

X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)
#X_test_features=X_features
print len(X_test_features)

alpha_q_nom=np.array([0.1,0.2,0.4,0.7])
alpha_q=alpha_q_nom-alpha_q_nom[0]

X_predicted_all=[]
outTag_name = 'full_quantile_regression_alpha'
for num,q in enumerate(alpha_q_nom):
	outTag =outTag_name+str(q)
	loaded_model = joblib.load(os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_'+outTag+'.pkl'))   
	X_pred_data = loaded_model.predict(X_test_features).astype(np.float64)
	X_predicted_all.append(X_pred_data)

n_evt = len(X_predicted_all[0])
#n_evt=100

X_predictions_for_fit = np.column_stack([x for x in X_predicted_all])
np.save("predictions_array_reverse",X_predictions_for_fit)
fit_quantile = np.array([np.polyfit(X_predictions_for_fit[i], alpha_q, deg=3) for i in range(n_evt)])

mpvs = np.array([ -1*fit_quantile[i,1]/3/fit_quantile[i,0] for i in range(n_evt)])

final_mpvs=[]
linear_mpvs=[]
tau_peak = 0.295
for i in range(n_evt):
	if mpvs[i]<X_predictions_for_fit[i][3] and mpvs[i]>X_predictions_for_fit[i][1] : final_mpvs.append(mpvs[i])
	else:
		fit_i = np.polyfit([X_predictions_for_fit[i][1],X_predictions_for_fit[i][2]], [alpha_q[1],alpha_q[2]], deg=1)
		final_mpvs.append(np.array( (tau_peak-fit_i[1])/fit_i[0] ))
		linear_mpvs.append(np.array( (tau_peak-fit_i[1])/fit_i[0] ))


print 'linear num = ', len(linear_mpvs)
print 'normal fit num = ', len(final_mpvs)

resolution = np.array([ (X_predictions_for_fit[i][3] - X_predictions_for_fit[i][1])/2. for i in range(n_evt)] )

#mpvs_tau = np.array([ np.polyval(fit_quantile[num,:],i) for num,i in enumerate(mpvs) if (i>=0)&(i<=4)   ])
#mpvs_tau = np.array([ i for i in mpvs_tau if (i>=0)&(i<=1)])
#mpvs = np.array([ i for i in mpvs if (i>=0)&(i<=4)])

#count = [i for i in mpvs if not( (i>=0)&(i<=10)) ]
#print count

#print mpvs
#funcs=[]
#xp = np.linspace(0.6, 1.4, 100)
#for i in range(n_evt):
#	funcs.append(np.poly1d(fit_quantile[i,:] ))
#	plt.plot(X_predictions_for_fit[i], alpha_q, 'o')
#	plt.plot(xp, funcs[i](xp), label="fit")
#plt.show()
#plt.savefig(utils.IO.plotFolder+"plotFit_quantile_polyfit.png")
#plt.clf()

#np.save("predictions_mpvs_array_reverse",mpvs)

addDictionary ={}
addDictionary['b_scale'] = final_mpvs
addDictionary['b_res_20p70'] = resolution


nTot,dictVar = postprocessing.stackAddFeaturesReg(data_frame,branch_names,addDictionary,5)
processPath=os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_root/treeScaleResolution20p70_minmax_')+outTag_name+'.root'
postprocessing.saveTreeReg(processPath,dictVar,nTot)


##funcs=[]
#for i in range(len(X_predicted_all[0])):
#	funcs.append(np.poly1d(fit_quantile[:,i] ))

saveName = 'quantileReg_distr_'
plotting.plot_hist([linear_mpvs],saveName+'LinearMpvs_minmax',True)
plotting.plot_hist([final_mpvs],saveName+'FinalMpvs_minmax',True)
plotting.plot_hist([resolution],saveName+'Resoution_minmax',True)


#for i in range(len(alpha_q_nom)):
#	n, bins, patches = plt.hist(X_predicted_all[i], 50, facecolor='green', alpha=0.75)
#	plt.xlabel('MPVS')
#	plt.ylabel('Events')
#	plt.title('Quantile = %s'%(str(alpha_q_nom[i])))
#	#plt.xlim(0, 2)
#	plt.grid(True)
##	plt.savefig(utils.IO.plotFolder+"quantileReg_distr_"+str(alpha_q[i])+".png")
#	plt.clf()

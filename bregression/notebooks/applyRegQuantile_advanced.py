# coding: utf-8

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
import lmfit  
from lmfit import Model,minimize, Minimizer, Parameters, Parameter, report_fit
import time
start_time = time.time()


def poly_bound(x,par_p0,par_f,par_p2,par_p3):
    model = par_p0*(-1./3*x*x*x + par_f*x*x + par_p2*x + par_p3)
    return model

def fcn2min(params, x, data):
    par_p0 = params['par_p0']
    par_p1 = params['par_p1']
    par_p2 = params['par_p2']
    par_p3 = params['par_p3']
    polx = par_p0*x*x*x+par_p1*x*x+par_p2*x+par_p3
    par_f= -1*par_p1/3/par_p0
    model = pow((data - polx ),2) + 1*pow((par_f - 1),2)
    return model 



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

#X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.)
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

X_predictions_for_fit = np.column_stack([x for x in X_predicted_all])

params = Parameters()
params.add('par_p0',   value= 1)
#params.add('par_f', value= 1.0, min=0.7, max=1.3)
params.add('par_p1', value= 1.0)
params.add('par_p2', value= 1.)
params.add('par_p3', value= 1.)


#gmodel = Model(poly_bound)
mpvs=[]

print 'here'
#fit_quantile = np.array( [gmodel.fit(alpha_q,params,x=X_predictions_for_fit[i]) for i in range(n_evt)  ]  )
fit_quantile=[]
for i in range(n_evt):
	minner = Minimizer(fcn2min, params, fcn_args=(X_predictions_for_fit[i], alpha_q))
	result = minner.minimize()
	fit_quantile.append(result)
	f = -1*result.params['par_p1'].value/3./result.params['par_p0'].value
#	print i,f
	mpvs.append(f)

fit_quantile = np.array(fit_quantile) 
mpvs = np.array(mpvs)
print 'here2'
#mpvs = np.array([ fit_quantile[i].params['par_f'].value for i in range(n_evt) ])

#print mpvs



np.save("minimizer_fitquant",fit_quantile)
np.save("minimizer_mpvs",mpvs)
#mpvs_tau = [ -1*fit_quantile[1,i]/3/fit_quantile[0,i] for i in range(n_evt)]
#mpvs=[np.polyval(fit_quantile[:,i],mpvs_tau[i]) for i in range(n_evt)]
#mpvs_up=[np.polyval(fit_quantile[:,i],mpvs_tau[i]+0.25) for i in range(n_evt)]
#mpvs_low=[np.polyval(fit_quantile[:,i],mpvs_tau[i]-0.25) for i in range(n_evt)]
#resolution = np.array(mpvs_up)-np.array(mpvs_low)
#
#mpvs_up_20=[np.polyval(fit_quantile[:,i],mpvs_tau[i]+0.2) for i in range(n_evt)]
#mpvs_low_20=[np.polyval(fit_quantile[:,i],mpvs_tau[i]-0.2) for i in range(n_evt)]

#derivative_coeff = [ [3*fit_quantile[0,i],2*fit_quantile[1,i],mpvs(fit_quantile[2,i] - )]  for i in range(n_evt)])
#roots_der = [np.roots(derivative_coeff[i]) for i in range(n_evt)] 

#np.save("predictions_mpvs_array_reverse",mpvs)

#addDictionary ={}
#addDictionary['b_scale'] = mpvs
#addDictionary['b_res_0p25'] = resolution
#addDictionary['b_res_0p20'] = np.array(mpvs_up_20)-np.array(mpvs_low_20)


#nTot,dictVar = postprocessing.stackAddFeaturesReg(data_frame,branch_names,addDictionary,5)
#processPath=os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_root/treeScaleResolution_')+outTag_name+'.root'
#postprocessing.saveTreeReg(processPath,dictVar,nTot)

#n, bins, patches = plt.hist(resolution, 100, range=[0,1],facecolor='green', alpha=0.75)
#plt.xlabel('resolution')
#plt.ylabel('Events')
#plt.grid(True)
#plt.savefig(utils.IO.plotFolder+"quantileReg_distr_resolution.png")
#plt.clf()

##funcs=[]
#for i in range(len(X_predicted_all[0])):
#	funcs.append(np.poly1d(fit_quantile[:,i] ))


#n, bins, patches = plt.hist(mpvs, 50, range=[0,2],facecolor='green', alpha=0.75)
#plt.xlabel('MPVS')
#plt.ylabel('Events')
#plt.grid(True)
#plt.savefig(utils.IO.plotFolder+"quantileReg_distr_reverse_mpvs.png")
#plt.clf()

#for i in range(len(alpha_q_nom)):
#	n, bins, patches = plt.hist(X_predicted_all[i], 50, facecolor='green', alpha=0.75)
#	plt.xlabel('MPVS')
#	plt.ylabel('Events')
#	plt.title('Quantile = %s'%(str(alpha_q_nom[i])))
#	#plt.xlim(0, 2)
#	plt.grid(True)
#	plt.savefig(utils.IO.plotFolder+"quantileReg_distr_"+str(alpha_q[i])+".png")
#	plt.clf()
print 'It took', time.time()-start_time, 'seconds.'

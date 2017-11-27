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
import time
start_time = time.time()
from ROOT import TMinuit, Double, Long

x_obs = np.array( 4*[1] )
y_obs = np.array( 4*[1] )
ncount = 0
arglist = np.array( 10*[0.] )

def changeme(new_val):
    global x_obs
    x_obs = new_val

def poly(x_obs,par):
    polx = par[0]*x_obs*x_obs*x_obs+par[1]*x_obs*x_obs+par[2]*x_obs+par[3]
    return polx 


def fcn(npar, gin, f, par, iflag):
    global ncount
    nbins = 4
    chisq, delta = 0., 0.
    par_f = -1*par[1]/3/par[0]
    for i in range(nbins):
       delta  = pow((y_obs[i]-poly(x_obs[i],par)),2) + 1*pow((par_f - 1),2)
       chisq += delta

    f[0] = chisq
    ncount += 1


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
X_test_features = preprocessing.get_test_sample(pd.DataFrame(X_features),0.9)
#X_test_features=X_features
print len(X_test_features)

alpha_q_nom=np.array([0.1,0.2,0.4,0.7])
alpha_q=alpha_q_nom-alpha_q_nom[0]
y_obs = alpha_q

X_predicted_all=[]
outTag_name = 'full_quantile_regression_alpha'
for num,q in enumerate(alpha_q_nom):
	outTag =outTag_name+str(q)
	loaded_model = joblib.load(os.path.expanduser('~/HHbbgg_ETH_devel/bregression/output_files/regression_heppy_'+outTag+'.pkl'))   
	X_pred_data = loaded_model.predict(X_test_features).astype(np.float64)
	X_predicted_all.append(X_pred_data)

n_evt = len(X_predicted_all[0])

X_predictions_for_fit = np.column_stack([x for x in X_predicted_all])



mpvs=[]

print 'here'
fit_quantile=[]
gMinuit = TMinuit(4)
gMinuit.SetPrintLevel(-1)
gMinuit.SetFCN( fcn )
arglist = np.array( 10*[0.] )
ierflg = 0 
arglist[0] = 1
gMinuit.mnexcm( "SET ERR", arglist, 1, Long(ierflg) )
arglist[0] = 0
gMinuit.mnexcm("SET PRINT", arglist ,0,Long(ierflg));
vstart = np.array( [  -2 , 4,-1, 0.5] )
step   = np.array(  [ 0.001, 0.001, 0.01, 0.01 ] )
gMinuit.mnparm( 0, "a1", vstart[0], step[0], 0, 0, Long(ierflg) )
gMinuit.mnparm( 1, "a2", vstart[1], step[1], 0, 0, Long(ierflg) )
gMinuit.mnparm( 2, "a3", vstart[2], step[2], 0, 0, Long(ierflg) )
gMinuit.mnparm( 3, "a4", vstart[3], step[3], 0, 0, Long(ierflg) )
arglist[0] = 500
arglist[1] = 1.
fParamVal = Double(0.)
fParamErr = Double(0.)
for i in range(5):
	changeme(X_predictions_for_fit[i])
	gMinuit.mnexcm( "MIGRAD", arglist, 2, Long(ierflg) )
#	gMinuit.mnexcm( "SIMPLEX", arglist, 2, Long(ierflg) )
	par_list=[]
	gMinuit.GetParameter(0,fParamVal,fParamErr)
	par_list.append(float(fParamVal))
	gMinuit.GetParameter(1,fParamVal,fParamErr)
	par_list.append(float(fParamVal))
	gMinuit.GetParameter(2,fParamVal,fParamErr)
	par_list.append(float(fParamVal))
	gMinuit.GetParameter(3,fParamVal,fParamErr)
	par_list.append(float(fParamVal))
	fit_quantile.append(par_list)
	mpvs.append(-1*par_list[1]/par_list[0]/3.)
print fit_quantile
print mpvs

fit_quantile = np.array(fit_quantile) 
mpvs = np.array(mpvs)

funcs=[]
xp = np.linspace(0.8, 1.4, 100)
for i in range(5):
	funcs.append(np.poly1d(fit_quantile[i] ))
	plt.plot(X_predictions_for_fit[i], y_obs, 'o')
	plt.plot(xp, funcs[i](xp), label="fit")
plt.show()
plt.savefig(utils.IO.plotFolder+"plotFit_quantilemi.png")
plt.clf()


#np.save("minimizer_fitquant",fit_quantile)
#np.save("minimizer_mpvs",mpvs)
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

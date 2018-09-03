import plotting_utils as plotting
reload(plotting)
import pandas as pd
import root_pandas as rpd
import sys

#start = int(sys.argv[1])
#end = int(sys.argv[2])
#file_name='ttbar_RegressionPerJet_heppy_energyRings3_forTesting.root'

#inout_dir = '/users/nchernya/HHbbgg_ETH/root_files/'
#out_dir = '/scratch/nchernya/HHbbgg/ttbar_full_hd5/'
#out_dir = '/scratch/nchernya/HHbbgg/ttbar_morevariables/'
##out_dir = '/scratch/nchernya/HHbbgg/ttbar_2017/'
#in_dir = 'root://t3dcachedb.psi.ch:1094//pnfs/psi.ch/cms/trivcat/store/user/nchernya/HHbbgg/b_regression/ttbar_full/'
#in_dir='/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/submit_jobs/'
##in_dir = 'root://t3dcachedb.psi.ch:1094//pnfs/psi.ch/cms/trivcat/store/user/nchernya/HHbbgg/b_regression/ttbar_2017_nanoAOD/'

#out_dir = '/scratch/nchernya/HHbbgg/othersamples_morevar/'
#in_dir = '/scratch/nchernya/HHbbgg/othersamples_morevar/'
in_dir = 'root://t3dcachedb.psi.ch:1094//pnfs/psi.ch/cms/trivcat/store/user/nchernya/HHbbgg/b_regression/ttbar_2016_legacy_JECv11/'
#in_dir = '/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/submit_jobs/'
#out_dir = '/scratch/nchernya/HHbbgg/ttbar_2017_v2/'
#in_dir = '/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/submit_jobs/2017/'
#out_dir = '/scratch/nchernya/HHbbgg/ttbar_2017_v3_newJEC/'
out_dir = '/scratch/nchernya/HHbbgg/ttbar_2016_legacy_JECv11/'
rings=[
                    'Jet_energyRing_dR0_em',
                    'Jet_energyRing_dR1_em',
                    'Jet_energyRing_dR2_em',
                    'Jet_energyRing_dR3_em',
                    'Jet_energyRing_dR4_em',
                    'Jet_energyRing_dR0_neut',
                    'Jet_energyRing_dR1_neut',
                    'Jet_energyRing_dR2_neut',
                    'Jet_energyRing_dR3_neut',
                    'Jet_energyRing_dR4_neut',
                    'Jet_energyRing_dR0_ch',
                    'Jet_energyRing_dR1_ch',
                    'Jet_energyRing_dR2_ch',
                    'Jet_energyRing_dR3_ch',
                    'Jet_energyRing_dR4_ch',
                    'Jet_energyRing_dR0_mu',
                    'Jet_energyRing_dR1_mu',
                    'Jet_energyRing_dR2_mu',
                    'Jet_energyRing_dR3_mu',
                    'Jet_energyRing_dR4_mu']

branch_names = 'Jet_pt,Jet_eta,Jet_mcFlavour,Jet_mcPt,rho,Jet_mt,Jet_leadTrackPt,Jet_leptonPt,Jet_leptonPtRel,Jet_leptonDeltaR,Jet_neHEF,Jet_neEmEF,Jet_vtxPt,Jet_vtxMass,Jet_vtx3dL,Jet_vtxNtrk,Jet_vtx3deL,Jet_energyRing_dR0_em,Jet_energyRing_dR1_em,Jet_energyRing_dR2_em,Jet_energyRing_dR3_em,Jet_energyRing_dR4_em,Jet_energyRing_dR0_neut,Jet_energyRing_dR1_neut,Jet_energyRing_dR2_neut,Jet_energyRing_dR3_neut,Jet_energyRing_dR4_neut,Jet_energyRing_dR0_ch,Jet_energyRing_dR1_ch,Jet_energyRing_dR2_ch,Jet_energyRing_dR3_ch,Jet_energyRing_dR4_ch,Jet_energyRing_dR0_mu,Jet_energyRing_dR1_mu,Jet_energyRing_dR2_mu,Jet_energyRing_dR3_mu,Jet_energyRing_dR4_mu,Jet_numDaughters_pt03,Jet_pt_reg,Jet_e,Jet_rawEnergy,Jet_energyRing_dR0_em,Jet_energyRing_dR1_em,Jet_energyRing_dR2_em,Jet_energyRing_dR3_em,Jet_energyRing_dR4_em,Jet_energyRing_dR0_neut,Jet_energyRing_dR1_neut,Jet_energyRing_dR2_neut,Jet_energyRing_dR3_neut,Jet_energyRing_dR4_neut,Jet_energyRing_dR0_ch,Jet_energyRing_dR1_ch,Jet_energyRing_dR2_ch,Jet_energyRing_dR3_ch,Jet_energyRing_dR4_ch,Jet_energyRing_dR0_mu,Jet_energyRing_dR1_mu,Jet_energyRing_dR2_mu,Jet_energyRing_dR3_mu,Jet_energyRing_dR4_mu,Jet_corr_JEC,Jet_corr_JER,Jet_rawPtAfterSmearing,Jet_ptd,Jet_axis2,Jet_leptonPdgId,Jet_leptonPtRelInv,nPVs,Jet_mass,Jet_chHEF,Jet_chEmEF,Jet_chMult'
branch_names = branch_names.split(',')
for ring in rings:
    branch_names.append('%s_Jet_rawEnergy'%ring)
cuts='(Jet_pt > 15) & (Jet_eta<2.5 & Jet_eta>-2.5) & (Jet_mcFlavour==5 | Jet_mcFlavour==-5) & (Jet_mcPt>1.) & (Jet_mcPt<6000)' #all for presentaion on 23 Jan was done with pT cut at 20 GeV

file_list  = [94 , 18 , 2 , 55 , 16 , 40 , 97 , 35 , 37 , 98 , 7 , 31 , 51 , 45 , 8 , 65 , 41 , 56 , 83 , 89 , 69 , 99 , 88 , 79 , 21 , 12 , 17 , 3 , 30 , 32 , 26 , 27 , 70 , 73 , 13 , 92 , 59 , 93 , 64 , 100 , 22 , 46 , 50 , 78 , 84 , 54 , 60 , 20 , 36 , 11 , 75 , 74 , 149 , 124 , 129 , 142 , 114 , 147 , 148 , 109 , 138 , 115 , 120 , 144 , 106 , 133 , 104 , 110 , 152 , 153 , 101 , 125 , 105 , 134 , 119 , 128 , 139 , 143 , 123 , 25 , 113 , 44 , 132 , 63 , 151 , 118 , 82 , 49 , 137 , 68 , 87 , 1 , 6 , 10 , 15 , 103 , 34 , 122 , 53 , 141 , 108 , 72 , 39 , 127 , 91 , 58 , 146 , 77 , 96 , 24 , 112 , 43 , 131 , 62 , 150 , 29 , 117 , 81 , 48 , 136 , 67 , 155 , 86 , 5 , 14 , 102 , 33 , 121 , 52 , 140 , 19 , 107 , 71 , 38 , 126 , 90 , 57 , 145 , 76 , 95 , 23 , 111 , 42 , 130 , 61 , 28 , 116 , 80 , 47 , 135 , 66 , 154 , 85 , 4 , 9 ] 
#filelist=['ZHbbll_RegressionPerJet_heppy_energyRings_forTesting']
#filelist=['HHsm','HHres500','HHres700','ZHbbll']
for i in range(35,len(file_list)):
#for i in range(start,end):
  num = file_list[i]
  filename='TTbar_legacy2016_JECv11_RegressionPerJet_heppy_energyRings_forTraining_%s_legacy_2ptds'%num
#  filename=filelist[i]
#  filename='TTbar_nanoAOD_RegressionPerJet_nanoAOD_2017_%d'%num
#  filename='TTbar_2ptds_RegressionPerJet_heppy_energyRings_forTraining_10_full_2ptd'
#  filename='nano_variables3_RegressionPerJet_nanoAOD_2017_5'
#  filename='TT2lep_RegressionPerJet_nanoAOD_2017_2'
#  tmp_data_frame = (rpd.read_root(in_dir+filename+'.root','tree', columns = branch_names))
  tmp_data_frame = (rpd.read_root(in_dir+filename+'.root','tree'))
#  for ring in rings:
 #     tmp_data_frame['%s_Jet_rawEnergy'%ring]=tmp_data_frame['%s'%ring]/tmp_data_frame['Jet_rawEnergy']
  tmp_data_frame_cut = tmp_data_frame.query(cuts)
  #tmp_data_frame_cut['Jet_corr'] = tmp_data_frame_cut['Jet_corr_JEC']
  tmp_data_frame_cut.to_hdf(out_dir+filename+'.hd5'  ,'w')

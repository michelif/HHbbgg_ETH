import plotting_utils as plotting
reload(plotting)
import pandas as pd
import root_pandas as rpd
import sys

start = int(sys.argv[1])
end = int(sys.argv[2])
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
in_dir = 'root://t3dcachedb.psi.ch:1094//pnfs/psi.ch/cms/trivcat/store/user/nchernya/HHbbgg/b_regression/ttbar_2017_nanoAOD_v3_newJEC/'
#out_dir = '/scratch/nchernya/HHbbgg/ttbar_2017_v2/'
#in_dir = '/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/submit_jobs/2017/'
out_dir = '/scratch/nchernya/HHbbgg/ttbar_2017_v3_newJEC/'
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

file_list  = [81 , 4 , 5 , 0 , 7 , 6 , 2 , 8 , 9 , 3 , 31 , 46 , 44 , 24 , 32 , 1 , 42 , 34 , 38 , 39 , 33 , 26 , 40 , 35 , 36 , 27 , 41 , 47 , 37 , 30 , 29 , 43 , 45 , 74 , 49 , 71 , 70 , 88 , 79 , 73 , 82 , 84 , 83 , 77 , 85 , 80 , 90 , 91 , 72 , 89 , 78 , 99 , 76 , 94 , 97 , 92 , 98 , 93 , 96 , 119 , 110 , 86 , 127 , 114 , 121 , 116 , 131 , 132 , 118 , 126 , 161 , 115 , 170 , 123 , 113 , 111 , 117 , 122 , 124 , 179 , 128 , 210 , 201 , 133 , 129 , 169 , 171 , 174 , 162 , 164 , 160 , 205 , 204 , 173 , 165 , 178 , 172 , 203 , 211 , 213 , 167 , 175 , 177 , 200 , 214 , 207 , 212 , 208 , 215 , 248 , 243 , 245 , 241 , 247 , 244 , 240 , 242 , 250 , 246 , 333 , 257 , 254 , 258 , 256 , 255 , 252 , 259 , 249 , 381 , 292 , 290 , 291 , 294 , 326 , 298 , 322 , 320 , 297 , 331 , 299 , 293 , 339 , 336 , 330 , 341 , 329 , 323 , 325 , 295 , 328 , 340 , 327 , 370 , 385 , 374 , 332 , 376 , 321 , 413 , 338 , 389 , 402 , 420 , 373 , 382 , 371 , 410 , 416 , 388 , 422 , 400 , 401 , 403 , 380 , 421 , 404 , 411 , 406 , 324 , 251 , 423 , 261 , 180 , 135 , 424 , 343 , 262 , 217 , 181 , 136 , 425 , 344 , 263 , 218 , 137 , 390 , 264 , 183 , 138 , 265 , 184 , 139 , 266 , 348 , 267 , 187 , 395 , 269 , 188 , 396 , 189 , 397 , 398 , 50 , 51 , 52 , 53 , 54 , 55 , 57 , 58 , 59 , 301 , 220 , 302 , 222 , 141 , 304 , 223 , 142 , 350 , 143 , 306 , 270 , 225 , 144 , 352 , 307 , 271 , 190 , 145 , 353 , 308 , 227 , 191 , 146 , 354 , 309 , 273 , 228 , 192 , 147 , 356 , 194 , 149 , 357 , 276 , 195 , 358 , 277 , 196 , 278 , 197 , 279 , 198 , 10 , 199 , 11 , 12 , 13 , 14 , 60 , 15 , 61 , 16 , 62 , 17 , 63 , 18 , 19 , 65 , 66 , 67 , 100 , 68 , 101 , 69 , 102 , 310 , 103 , 311 , 230 , 104 , 312 , 231 , 150 , 105 , 313 , 232 , 151 , 106 , 314 , 152 , 315 , 153 , 108 , 316 , 280 , 235 , 154 , 109 , 362 , 317 , 281 , 236 , 155 , 363 , 318 , 282 , 156 , 319 , 283 , 238 , 365 , 284 , 239 , 158 , 366 , 285 , 159 , 367 , 286 , 368 , 287 , 369 , 288 , 289 , 20 , 21 , 22] 
#filelist=['ZHbbll_RegressionPerJet_heppy_energyRings_forTesting']
#filelist=['HHsm','HHres500','HHres700','ZHbbll']
#for i in range(0,len(file_list)):
for i in range(start,end):
  num = file_list[i]
 # filename='ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_%d_full'%num
#  filename=filelist[i]
  filename='TTbar_nanoAOD_RegressionPerJet_nanoAOD_2017_%d'%num
#  filename='nano_variables3_RegressionPerJet_nanoAOD_2017_5'
#  filename='TT2lep_RegressionPerJet_nanoAOD_2017_2'
#  tmp_data_frame = (rpd.read_root(in_dir+filename+'.root','tree', columns = branch_names))
  tmp_data_frame = (rpd.read_root(in_dir+filename+'.root','tree'))
#  for ring in rings:
 #     tmp_data_frame['%s_Jet_rawEnergy'%ring]=tmp_data_frame['%s'%ring]/tmp_data_frame['Jet_rawEnergy']
  tmp_data_frame_cut = tmp_data_frame.query(cuts)
  #tmp_data_frame_cut['Jet_corr'] = tmp_data_frame_cut['Jet_corr_JEC']
  tmp_data_frame_cut.to_hdf(out_dir+filename+'.hd5'  ,'w')

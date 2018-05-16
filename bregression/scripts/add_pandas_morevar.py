import os
import pandas as pd
import numpy as np
import sys

start = int(sys.argv[1])
end = int(sys.argv[2])

#targetdir='/scratch/nchernya/HHbbgg/ttbar_morevariables/'
#targetdir = '/scratch/nchernya/HHbbgg/ttbar_2017_v2/'
#targetdir = '/scratch/nchernya/HHbbgg/othersamples_morevar/'
targetdir = '/scratch/nchernya/HHbbgg/ttbar_2017_v3_newJEC/'
#targetdir = '/scratch/nchernya/HHbbgg/'
#list the files
#filelist = [targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_%d_full.hd5'%num for num in file_list]
file_list  = [81 , 4 , 5 , 0 , 7 , 6 , 2 , 8 , 9 , 3 , 31 , 46 , 44 , 24 , 32 , 1 , 42 , 34 , 38 , 39 , 33 , 26 , 40 , 35 , 36 , 27 , 41 , 47 , 37 , 30 , 29 , 43 , 45 , 74 , 49 , 71 , 70 , 88 , 79 , 73 , 82 , 84 , 83 , 77 , 85 , 80 , 90 , 91 , 72 , 89 , 78 , 99 , 76 , 94 , 97 , 92 , 98 , 93 , 96 , 119 , 110 , 86 , 127 , 114 , 121 , 116 , 131 , 132 , 118 , 126 , 161 , 115 , 170 , 123 , 113 , 111 , 117 , 122 , 124 , 179 , 128 , 210 , 201 , 133 , 129 , 169 , 171 , 174 , 162 , 164 , 160 , 205 , 204 , 173 , 165 , 178 , 172 , 203 , 211 , 213 , 167 , 175 , 177 , 200 , 214 , 207 , 212 , 208 , 215 , 248 , 243 , 245 , 241 , 247 , 244 , 240 , 242 , 250 , 246 , 333 , 257 , 254 , 258 , 256 , 255 , 252 , 259 , 249 , 381 , 292 , 290 , 291 , 294 , 326 , 298 , 322 , 320 , 297 , 331 , 299 , 293 , 339 , 336 , 330 , 341 , 329 , 323 , 325 , 295 , 328 , 340 , 327 , 370 , 385 , 374 , 332 , 376 , 321 , 413 , 338 , 389 , 402 , 420 , 373 , 382 , 371 , 410 , 416 , 388 , 422 , 400 , 401 , 403 , 380 , 421 , 404 , 411 , 406 , 324 , 251 , 423 , 261 , 180 , 135 , 424 , 343 , 262 , 217 , 181 , 136 , 425 , 344 , 263 , 218 , 137 , 390 , 264 , 183 , 138 , 265 , 184 , 139 , 266 , 348 , 267 , 187 , 395 , 269 , 188 , 396 , 189 , 397 , 398 , 50 , 51 , 52 , 53 , 54 , 55 , 57 , 58 , 59 , 301 , 220 , 302 , 222 , 141 , 304 , 223 , 142 , 350 , 143 , 306 , 270 , 225 , 144 , 352 , 307 , 271 , 190 , 145 , 353 , 308 , 227 , 191 , 146 , 354 , 309 , 273 , 228 , 192 , 147 , 356 , 194 , 149 , 357 , 276 , 195 , 358 , 277 , 196 , 278 , 197 , 279 , 198 , 10 , 199 , 11 , 12 , 13 , 14 , 60 , 15 , 61 , 16 , 62 , 17 , 63 , 18 , 19 , 65 , 66 , 67 , 100 , 68 , 101 , 69 , 102 , 310 , 103 , 311 , 230 , 104 , 312 , 231 , 150 , 105 , 313 , 232 , 151 , 106 , 314 , 152 , 315 , 153 , 108 , 316 , 280 , 235 , 154 , 109 , 362 , 317 , 281 , 236 , 155 , 363 , 318 , 282 , 156 , 319 , 283 , 238 , 365 , 284 , 239 , 158 , 366 , 285 , 159 , 367 , 286 , 368 , 287 , 369 , 288 , 289 , 20 , 21 , 22] 
#name='ZHbbll'i
#name='nano_variables3_RegressionPerJet_nanoAOD_2017_5'
#name='HHbbggSM_flashgg_test'
#name='TT2lep_RegressionPerJet_nanoAOD_2017_2'
#filelist=[targetdir+'%s.hd5'%name]
filelist = [targetdir+'/TTbar_nanoAOD_RegressionPerJet_nanoAOD_2017_%d.hd5'%num for num in file_list]
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
#big_df.loc[big_df.Jet_leptonPdgId == -99,'isOther'] = 1  #2016
big_df.loc[big_df.Jet_leptonPdgId == 0,'isOther'] = 1  #2017
#big_df.loc[big_df.Jet_ptd < 0 ,'Jet_withPtd' ] = big_df[ big_df['Jet_ptd'] > 0 ]['Jet_ptd'].median()  #2016
#big_df.loc[big_df.Jet_leptonPtRelInv < 0 ,'Jet_leptonPtRelInv' ] = 0  #2016
#big_df.to_hdf(targetdir+'/ttbar_full_jobs_RegressionPerJet_heppy_energyRings_forTraining_con%d%d_morevar.hd5'%(start,end)  ,'w')
#big_df.to_hdf(targetdir+'/ZHbbll_RegressionPerJet_heppy_energyRings_forTesting_morevar.hd5','w')
big_df.to_hdf(targetdir+'/TTbar_nanoAOD_RegressionPerJet_nanoAOD_2017_v3_newJEC_con%d%d_allvar.hd5'%(start,end)  ,'w')
#big_df.to_hdf(targetdir+'/%s_morevar.hd5'%(name)  ,'w')

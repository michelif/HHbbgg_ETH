from sklearn.metrics import r2_score, make_scorer
import numpy as np

def scoring_function(y_true, y_pred):  
	r2 = r2_score(y_true, y_pred)
	path='/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/output_files/'
	np.save(path+'out_pred',y_pred)
	np.save(path+'out_true',y_true)
	np.save(path+'out_score',r2)
	return r2

import keras.backend as K
import keras.losses
import keras.utils.generic_utils

import numpy as np

# ---------------------------------------------------------------------------------------------------
class RegularizedGaussNll(object):

    def __init__(self,reg_sigma=0.01):
        self.reg_sigma = reg_sigma
        self.n_params = 2
        
    def __call__(self,y_true,y_pred):
        mean   = y_pred[:,0]
        sigma2 = K.square(y_pred[:,0]) + self.reg_sigma**2
        z2 = K.square( y_true[:,0] - mean) / sigma2
        return 0.5*K.mean( z2 + 0.5*K.log(sigma2), axis=-1 )

# ---------------------------------------------------------------------------------------------------
def gauss_nll(y_true,y_pred):
    mean   = y_pred[:,0]
    sigma2 = K.square(y_pred[:,0]) + 0.01**2
    z2 = K.square( y_true[:,0] - mean) / sigma2
    return 0.5*K.mean( z2 + 0.5*K.log(sigma2), axis=-1 )
    ## return K.mean(K.square(y_true-y_pred))

# ---------------------------------------------------------------------------------------------------
## keras.losses.gauss_nll = gauss_nll

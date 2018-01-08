import numpy as np

from keras.layers import Input, Dense, Add, Multiply
from keras.layers import Reshape, UpSampling1D, Flatten, concatenate, Cropping1D
from keras.layers import Activation, LeakyReLU, PReLU, Lambda
from keras.layers import BatchNormalization, Dropout
from keras.models import Model, Sequential
from keras.layers import Layer

import keras.optimizers

from keras.regularizers import l1,l2

from keras import backend as K


from . import losses 

# --------------------------------------------------------------------------------------------------
class ConstOffsetLayer(Layer):

    def __init__(self, values, **kwargs):
        self.values = values
        super(ConstOffsetLayer, self).__init__(**kwargs)

    def get_config(self):
        return { 'values' : self.values }
        
    def call(self, x):
        return x+K.constant(self.values)


# --------------------------------------------------------------------------------------------------
class FFWDRegression(object):

    def __init__(self,name,input_shape,output_shape=None,
                 dropout=0.5,batch_norm=True,activations="lrelu",layers=[256]*5+[128,64],
                 do_bn0=True,
                 const_output_biases=None, 
                 optimizer="Adam", optimizer_params=dict(lr=1.e-4),
                 loss="RegularizedGaussNll",
                 loss_params=dict(reg_sigma=1.e-2),
    ):
        self.name = name
        self.input_shape = input_shape
        self.output_shape = output_shape
        self.const_output_biases = const_output_biases
        
        self.dropout = dropout
        self.batch_norm = batch_norm
        self.layers = layers
        if type(activations) == str:
            self.activations = [activations]*len(layers)
        elif len(activations) < len(layers):
            rat = len(layers) // len(activations)
            remind = len(layers) % len(activations)
            self.activations = activations*rat
            if remind > 0:
                self.activations += activations[:remind]
        else:
            self.activations = activations
        self.do_bn0 = do_bn0
        self.use_bias = not do_bn0
        
        self.optimizer = optimizer
        self.optimizer_params = optimizer_params
        self.loss = loss
        self.loss_params = loss_params

        self.model = None


    
    # ----------------------------------------------------------------------------------------------
    def __call__(self,docompile=False):
        
        if hasattr(losses,self.loss):
            loss = getattr(losses,self.loss)
            print(loss,isinstance(loss,object))
            if isinstance(loss,object):
                loss = loss(**self.loss_params)
            print(loss)

        output_shape = self.output_shape
        if output_shape is None:
            output_shape = (getattr(loss,"n_params",1),)
            
        if self.model is None:
            inputs = Input(shape=self.input_shape,name="%s_inp" % self.name)
            
            if len(self.input_shape)>1:
                L = Flatten(name="%s_flt" % self.name)(inputs)
            else:
                L = inputs
            if self.do_bn0:
                L = BatchNormalization(name="%s_bn0" % self.name)(L)
                
            for ilayer,(isize,iact) in enumerate(zip(self.layers,self.activations)):
                il = ilayer + 1
                L = Dense(isize,use_bias=self.use_bias,name="%s_dense%d" % (self.name,il))(L)
                if self.batch_norm:
                    L = BatchNormalization(name="%s_bn%d" % (self.name,il))(L)
                if self.dropout is not None:
                    L = Dropout(self.dropout, name="%s_do%d" % (self.name,il))(L)
                if iact == "lrelu" or "lrelu_" in iact:
                    nslope = 0.2
                    if "_" in iact:
                        nslope = float(iact.rsplit("_",1))
                        L = LeakyReLU(nslope,name="%s_act%d" % (self.name,il))(L)
                elif iact == "prelu":
                    L = PReLU(name="%s_act%d" % (self.name,il))(L)
                else:
                    L = Activation(iact,name="%s_act%d" % (self.name,il))(L)
            
            reshape = False
            out_size = output_shape[0]
            if len(output_shape) > 1:
                reshape = True
                for idim in output_shape[1:]:
                    out_size *= output_shape[idim]
            output = Dense(out_size,use_bias=self.const_output_biases is None,
                           name="%s_out" % self.name)(L)
            if reshape:
                output = Reshape(output_shape,name="%s_rshp" % self.name)(output)
            if self.const_output_biases is not None:
                ## output = Lambda(lambda x: x+K.constant(self.const_output_biases))(output)
                output = ConstOffsetLayer(self.const_output_biases,name="%s_outb" % self.name)(output)
                
            self.model = Model( inputs=inputs, outputs=output )
            
        if docompile:
            optimizer = getattr(keras.optimizers,self.optimizer)(**self.optimizer_params)

            self.model.compile(optimizer=optimizer,loss=loss)
        return self.model


    # ----------------------------------------------------------------------------------------------
    def fit(self,X,y,epochs=100):

        model = self(True)

        model.fit(X,y,epochs=epochs)
        
    

#!/usr/bin/env python

from optparse import OptionParser, make_option

import bregnn.io as io
import os

from sklearn.model_selection import train_test_split

## command_line options
parser = OptionParser(option_list=[
    make_option("--inp-dir",type='string',dest="inp_dir",default=os.environ['SCRATCH']+'/bregression'),
    make_option("--out-dir",type='string',dest="out_dir",default=None),
    make_option("--inp-file",type='string',dest='inp_file',default='ttbar_unweighted_full80M_selected.hd5'),
    make_option("--seed",type='int',dest='seed',default=87532),
    make_option("--test-frac",type='float',dest='test_frac',default=0.05),
    ])

## parse options
(options, args) = parser.parse_args()

if os.path.exists(options.inp_file):
    inp_file = options.inp_file
else:
    inp_file = options.inp_dir+'/'+options.inp_file

if options.out_dir is None:
    options.out_dir = os.path.dirname(inp_file)

data = io.read_data(inp_file, columns = None) #, stop = 100000 )

# split data
train,test = train_test_split(data,test_size=options.test_frac,random_state=options.seed)

fname = options.out_dir+'/'+os.path.basename(inp_file).rsplit(".",1)[0]

print(fname)

train.to_hdf(fname+"_train.hd5",key='train',mode='w',format='t')
test.to_hdf(fname+"_test.hd5",key='test',mode='w',format='t')

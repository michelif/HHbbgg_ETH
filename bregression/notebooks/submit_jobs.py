import datetime
import os
from optparse import OptionParser, make_option

parser = OptionParser(option_list=[
    make_option("--njobs",type='int',dest='njobs',default=0),
    make_option("--jdir",type='str',dest='jdir',default=''),
])
## parse options
(options, args) = parser.parse_args()

now = datetime.datetime.now()
now = str(now).split(' ')[0] +'_'+ str(now).split(' ')[1].split('.')[0].replace(':','_')
output_dir=os.environ['SCRATCH']+'/bregression/NN_output/%s'%now
json_dir=os.environ['SCRATCH']+'/bregression/json/%s/'%options.jdir

for i in range(options.njobs):
    out_dir = output_dir+'_job'+str(i)
    json = json_dir+'hparameters_%i.json'%i
   # submit_job='sbatch my_job.sh -J  jobid%i  train_ffwd.py --out-dir %s --hparams %s'%(i,out_dir,json)
   # submit_job='sbatch my_job.sh -J  jobid%i  train_ffwd.py --out-dir %s --hparams %s --x-val True --epochs 40'%(i,out_dir,json)
    submit_job='sbatch my_job.sh -J  jobid%i  train_ffwd.py --out-dir %s --hparams %s --epochs 40'%(i,out_dir,json)
    print(submit_job)

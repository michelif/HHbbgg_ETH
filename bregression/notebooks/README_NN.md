# Training NN on CSCS cluster in Lugano

### Setting up the environment 
Connecting to CSCS
```
ssh username@ela.cscs.ch
ssh daint
```
Copy /users/musella/env.sh ---> specify i have to copy /users/musella/env.sh
in ~/env.sh. Moreover in the copied file "~" has to be changed into "~musella"
to source pasquale's enviroement
Source Pasquale's file :
```
source /users/musella/my-env/bin/activate
```
Close daint. To check out the repo first generate the key by 'ssh-keygen' and add it to github. Then checko-out repo
```
git clone -b ETH_regression git@github.com:chernyavskaya/HHbbgg_ETH.git
```
Create jupyter folder and link it notebooks(or python maybe better) to bregression project inside
```
mkdir jupyter
cd jupyter ------------------>Added
ln -s ../HHbbgg_ETH/bregression/notebooks/ bregression
```
Inside ~/bin/ create bin/start_jupyter 
```
#!/bin/bash 
source ~/env.sh
cd ~/jupyter 
jupyter notebook --port 9900 --no-browser ----->this port here has to be the
same as the one below. maybe also specify to choose a port that is not taken
 ```
 Make start_jupyter executable
 ```
 chmod 755 bin/start_jupyter
 ```
 
 
 Create .ssh/config
 ```
Host daint*
LocalForward 9999 localhost:9999 --->see above
LocalForward 6666 localhost:6666

Host *
ControlMaster auto
ControlPath ~/.ssh/master-%r@%h:%p
```

On your own laptop create .ssh/config
```
Host cscs
LocalForward 9999 localhost:9999 ----->see above
LocalForward 6666 localhost:6666
User username
HostName ela.cscs.ch
```
Run cscs to be able to access the jupyter notebook later.--> what does it mean????

Now back to cscs:
Adding basic python config ~/.ipython/profile_default/startup/00-basics.ipy :
---->before this i should do mkdir -p ~/.ipython/profile_default/startup/
```
cat ~/.ipython/profile_default/startup/00-basics.ipy
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib

try:
    reload  # Python 2.7
except NameError:
    try:
        from importlib import reload  # Python 3.4+
    except ImportError:
        from imp import reload  # Python 3.0 - 3.3


try:
    %matplotlib inline
except:
    pass
matplotlib.style.use('seaborn-poster')
plt.rcParams['image.cmap'] = 'bwr'
plt.rcParams['figure.figsize'] = '10,10'
```
Nice screen set up to see the tabs inside
```
~musella/.screenrc
```
Start jupyter in screen :
```
start_jupyter
```
Open the notebook in the browser with the printed by jupyter token.

Add config file to run jobs 'my_jobs.sh in the bregression directory(where you
run the training)': -----> Is it ~/jupyter/bregression?
```
cat my_job.sh
#!/bin/bash -l
#SBATCH --job-name=job_name
#SBATCH --mail-type=ALL
#SBATCH --mail-user=pasquale.musella@cern.ch --->this has to be edited, write
otherwise we flood pasquale's email
#SBATCH --time=24:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-core=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=6
#SBATCH --partition=normal
#SBATCH --constraint=gpu
#SBATCH -A d78

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
export CRAY_CUDA_MPS=1

source $HOME/env.sh

cd $HOME/jupyter/GanjaPy --->this has to be edited  $HOME/jupyter/bregression

srun $@
```


## Training NN
Training file :
./train_ffwd.py --help

To train locally : 
train_ffwd.py --inp-dir=/scratch/snx3000/musella/bregression --out-dir test --loss mse

To submit a job and run interactively on the resources allocated by the job:
```
salloc -C gpu 
srun ./train_ffwd.py --inp-dir=/scratch/snx3000/musella/bregression --out-dir
test --loss mse --->I had to do source ~/env.sh even if I had the jupyter
running. check if that is the case and then add it to the instructions
```
To stop the interactive process ctr+C ctrl+C twice
To exit the job : exit

To submit a proper batch job:
```
sbatch my_job.sh -J <name> <command> <options>
```
e.g
```
sbatch my_job.sh -J  test_job  train_ffwd.py --inp-dir=/scratch/snx3000/musella/bregression --out-dir test2 --loss mse 
```
To check allocated job resources:
```
sacct 
```
The log file is writen in the same directory unless it is changed by giving the option -o 'where_to_write_log'

```
tail -f slurm-5610450.out
```
After the job is done (or during the job) all the hdf5 files and metrics.csv and config.json with all hyper parameters of the NN are written to the output directory specified in the command option
 

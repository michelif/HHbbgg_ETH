# HHbbgg_ETH
## Getting the code
Fork to your directory the code here: https://github.com/michelif/HHbbgg_ETH <br />
Clone it locally:<br />
git clone git@github.com:[YOURNAME]/HHbbgg_ETH.git HHbbgg_ETH_devel <br />
You should create your own branch, then do pull requests when you are done. <br />

## Training, optimization of MVAs and ntuple production
In order to run the notebooks on the browser you need an ssh tunnel on a machine where jupyter is running.
Opening it in a screen session allows you to detach it and not redoing it every time
(you will only need to ssh). <br/>

One-time initialization of Jupyter: <br />
- Start jupyter on t3: <br />
ssh -L 8002:localhost:8002 t3ui02.psi.ch;  //this first line has to be done every time<br />
screen; <br />
cd HHbbgg_ETH_devel; <br />
jupyter notebook --port 8002 --no-browser; <br />
ctrl-a-d //detaches screen session <br/>
In your browser open: http://localhost:8002 <br />

The code is organized in notebooks, the programs you execute directly in the browser. They
are in the "notebooks" folder. <br />

- Training/notebooks <br />
This folder contains all the notebooks needed <br />
-- trainMVAHHbbgg.ipynb  <br />
Trains a Gradient Boost Classifier to separate signal/backgrounds. All re-weighting implemented, output saved. <br />
-- createTrees.ipynb <br />
It runs on ntuples, applies a given MVA and saves a reduced ntuples which includes the MVA scores <br />
-- optimizeClassifier.ipynb <br />
Optimize parameters of the classifier. In Training/scropts/optimizeClassifier.py there is a (probably not-updated) version
of this optimization code wich runs without using notebooks. 


- Training/python/<br />
This folder contains all the tools needed by the notebooks:
data format, train/test splitting, plotting...
These classes have to be loaded at the beginning of your notebook.


## Workspaces and datacards production
The instructions for this part of the analysis are in the README in folder Limits/macros

## Combine
The instructions for this part of the analysis are in the README in folder Limits/combine_macros
---- test branch micheli_devel_20170913

# HHbbgg_ETH
-------Instructions to run the code: <br/>
In order to run the notebooks on the browser you need an ssh tunnel on a machine where jupyter is running.
Opening it in a screen session allows you to detach it and not redoing it every time
(you will only need to ssh). <br/>

One-time initialization of Jupyter: <br />
- Start jupyter on t3: <br />
ssh -L 8002:localhost:8002 t3ui02.psi.ch;  //this first line has to be done every time<br />
screen; <br />
cd HHbbgg_ETH; <br />
jupyter notebook --port 8002 --no-browser; <br />
ctrl-a-d //detaches screen session <br/>
In your browser open: http://localhost:8002 <br />

The code is organized in notebooks, the programs you execute directly in the browser. They
are in the "notebooks" folder. <br />

- Training/notebooks
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





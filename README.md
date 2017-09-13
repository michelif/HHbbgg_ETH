---- test branch micheli_devel_20170913

# HHbbgg_ETH
-------Instructions to run the code:

- Start jupyter on t3: <br />
ssh -L 8002:localhost:8002 t3ui02.psi.ch; <br />
screen; <br />
cd HHbbgg_ETH; <br />
jupyter notebook --port 8002 --no-browser; <br />
In your browser go to: http://localhost:8002

- Training/python/training_utils.py <br />
This file contains all the tools needed by the notebooks:
data format, train/test splitting, plotting...

- Training/notebooks
This folder contains all the notebooks needed <br />
-- CountEvents <br />
It counts signal/background/data events after applying a selection (MVA, mgg/mjj window...) <br />
-- trainMVAHHbbgg_allMC_resWeighting_optimized.ipynb  <br />
Trains a Gradient Boost Classifier to separate signal/backgrounds. All weighting implemented, output saved. <br />
-- optimizeClassifier.ipynb <br />
Optimize parameters of the classifier. In Training/scropts/optimizeClassifier.py there is a version
of this optimization code wich runs without using notebooks.




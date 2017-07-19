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
It counts signal/background/data events after applying a selection (MVA, mgg/mjj window...)

--

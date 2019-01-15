### Training a classification BDT for HHbbgg

Right now the classification BDT is trained for 2016 and for 2017 years independetly,
rho variable is included in the list of variables and generatir-level M(HH) is reweighted between two years to match 
but keeping relative normalization (2017 reweighted to match 2016).

__Main training notebook__ :
```
Training/notebooks/trainMVAHHbbgg_bjetSamples.ipynb
```
__In the past__ we have tried to do only one training for both years, but given some differences between
several input variables this idea was discarded. The old notebook for this is : `trainMVAHHbbgg_common.ipynb`
We also have a very first version of the training notebook still available, 
but it is note updated and should be used only as a light example : `trainMVAHHbbgg.ipynb`

__Before training is done the benchmark nodes have to be added together__,a notebook is available. 
This notebook is quite heavy and not very self explanatory due to often changing recepies for everything, in case of questions - 
ask Nadya . The notebook : `Training/notebooks/addingNodes.ipynb`

A notebook to reweight benchmarks and make plots : `Training/notebooks/reweighted_benchmarks.ipynb`
__Not used anymore for reweighting__ because the reweighting is done on the fly in training notebook to avoid bugs.

__To compare different classifiers__ several example notebooks are available, but they are always needed to be adjusted for the needs :
`Training/notebooks/comparison_deepCSV_CSV.ipynb, Training/notebooks/compareClassifiers.ipynb`

__Hyperparameters optimizaion__ : after running on a large grid of hyperparameters, 
a notebook is avaible to help choosing the best hyperparameters combination : `Training/notebooks/choosingBestHyperparameters.ipynb`

__Creating trees with the training__
Some scripts are available : `createTrees.ipynb, createReducedTrees.ipynb` , but right now this is done in the `Limits` section

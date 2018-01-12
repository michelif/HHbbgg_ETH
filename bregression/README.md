# b-jet energy regression

* Reconstruction of the X-> bb decay is fundamental for many Higgs and BSM analyses
* Improve the calorimetric response 
* Correct for (semi)leptonic b decays that lead to mismeasurement of pT due to escaping neutrino
* The goal then is to correct b-jet energy scale using a multidimensional calibration and information at gen level
* Jet resolution per event can significantly improve sensitivity of such analyses 

## Getting started
Regression is trained using modern machine learning software : Scikit-learn and XGBoost 
Running code is in the directory 'notebooks' and python functions are written in 'python'
Directory scripts is used for little scripts for weighting, unweighintg jet pT spectra and aso to test little things.

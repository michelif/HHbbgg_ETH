## Improving performance for high pT jets
* performance is worse at high pT jets because jet pt spectra spans over 6 orders of magnitude, leaving limited statistics for the training at high pT
* This situation of course would have happen if we would have had b-jet gun
* We want to increase the training statistics at high pT, but without increasing the size of the training sample (for computational reasons)
* To improve the performance at high jet pT we can do unweighting by hand: leave all jets at high pT and throw away some of the jets with low pT
* This way we can avoid very large weights which tend to be problematic in trainings

1. Leave all jets with high pT, e.g. 400 GeV
2. Throw away some with lower jet pT
3. Get unweighting function
4. func = 1 for jet pT > 400 GeV and <1 for jet pT < 400 GeV
5. Throw random number [0,1]
6. If it falls below the function value in pT  bin, leave the jet, if above throw away
* Only 5% of events left -> need to submit jobs otherwise it will run for very long time

### Submitting jobs
Reading heppy file and creating root file with only branches we need and also using unweighting based on jet pT
```
treeForRegression_unweight.C
```
Submit jobs. To it in screen , because it takes a little time
```
source submit.sh
```
To hadd all files at t2
```
source merge.sh
```
to create a txt file with the list of all files needed to be hadd on scratch
```
hadd ... txt
```
to the print out of the previous step

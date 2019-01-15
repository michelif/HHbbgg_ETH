## Preparing trees for by-hand approximate Limit extraction

#### This section also explains how to add MVA output to the trees and do a cumulative transformation on the MVA output

### Creating tree with MVA output 
The scipt `Limits/python/createReducedTrees.py` evaluates MVA output on the trees and adds it to the trees.
```
source runAllAnalysis.sh
```

__In the past__ to do the transformation of the MVA output, you could use one script only : `Limits/macros/transformMVAOutput.py` 
__Now__ to do a cumulative tranformation of the MVA output, two steps are needed because 2016 and 2017 should be reweighted accordingly to 
match S/B efficiencies between the two years. Because cumulative is done on the sum of the years.
```
transformMVAOutputCommon.py  #first step, evaluation of the transformation on both years
applyTransformMVAOutput.py   #second step, application on each year individually
```
__Beware__, that reweighting factor S/B right now is calculated for 2017/2016 and applied on 2017 only, while 2016 is untouched. 
When we add 2018, we will change this and each year will have a factor. This factor is calculated in the `Training` section.
Right now, it is hardcoded in the code for the application [here](https://github.com/chernyavskaya/HHbbgg_ETH/blob/common_trainng/Limits/macros/transformMVAOutputCommon.py#L36)

### Run pseudo-limits :
Prepare the workspaces from the trees:
```
Limits/macros/makeWorkspaceHHbbgg.py
```
Run the limits as explained here :
```
Limits/combine_macros
```

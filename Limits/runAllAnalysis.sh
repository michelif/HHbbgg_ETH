#!/bin/bash

# A POSIX variable
OPTIND=1         # Reset in case getopts has been used previously in the shell.

# Initialize our own variables:
ntup="20170620"
addHHTagger=0
training="allMC_resWeighting_F_noDR_minDRGJet"
outTag="20180108_test" 

while getopts ":n:at:o:" opt; do
    case "${opt}" in
    n)  ntup=${OPTARG}
        ;;
    a)  addHHTagger=1
        ;;
    t)  training=${OPTARG}
        ;;
    o)  outTag=${OPTARG}
        ;;
    
    esac
done

shift $((OPTIND-1))


####create Trees
if ((addHHTagger)); then
    python $HOME/HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag -a
else
    python $HOME/HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag 
fi
    
####transform MVA output
python $HOME/HHbbgg_ETH_devel/Limits/macros/transformMVAOutput.py -i '/mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/'$outTag'/Total_preselection_diffNaming.root'


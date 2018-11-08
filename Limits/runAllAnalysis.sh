#!/bin/bash

# A POSIX variable
OPTIND=1         # Reset in case getopts has been used previously in the shell.

# Initialize our own variables:
#ntup="deepCSV_01_10_2018"
ntup="ntuples_2017data_20181023"
addHHTagger=0  #0 if you want to add it, 1 if it is already present
#training="training_with_27_06_2018_newcode_v2"  #new code with fixed selection of jets
#training="training_with_01_10_2018_deepCSV" #deep CSV
training="training_with_28_10_2018_common2017" #deep CSV

outTag="2016_2017_20181107_common"
year=1 #0 for 2016, 1 for 2017

while getopts ":n:at:o:" opt; do
    case "${opt}" in
    n)  ntup=${OPTARG}
        ;;
    a)  addHHTagger=0
        ;;
    t)  training=${OPTARG}
        ;;
    o)  outTag=${OPTARG}
        ;;
    
    esac
done

shift $((OPTIND-1))

####create Trees
#if ((addHHTagger)); then
#    python /mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag -a -y $year
#else
#    python /mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag -y $year -k 0
#fi
    
####transform MVA output
python /mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/Limits/macros/transformMVAOutput.py -i '/mnt/t3nfs01/data01/shome/nchernya//HHbbgg_ETH_devel/outfiles/'$outTag'/Total_preselection_diffNaming_2016_2017.root'


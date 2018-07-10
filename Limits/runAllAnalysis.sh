#!/bin/bash

# A POSIX variable
OPTIND=1         # Reset in case getopts has been used previously in the shell.

# Initialize our own variables:
ntup="ntuples_newcode_20180627"
addHHTagger=0  #0 if you want to add it, 1 if it is already present
#training="allMC_resWeighting_F_noDR_minDRGJet"   #latest Francesco
#training="training_with_2017variablesReg_opt28_05_2018_gaussian" #trained on 1SM node only, bregression included and resolution for b-jets is normalized to 1 gaussian sigma
#training="training_with_2017variablesReg_opt28_05_2018_gaussian_SM_nodes" #trained on all nodes, bregression included and resolution for b-jets is normalized to 1 gaussian sigma
#training="training_with_2017variablesNoReg_opt28_05_2018_gaussian_SM_nodes" #trained on all nodes, no bregression included
#training="training_with_2017variablesReg_opt28_05_2018_gaussian_SM_nodes_TrainedOddEvents" #trained on all nodes 
#training="training_with_2017variablesNoReg_opt28_05_2018_gaussian_SM_nodes_TrainedOddEvents"
#training="training_with_18_06_2018_newcode_cuts20" #new code 
training="training_with_27_06_2018_newcode_v2"  #new code with fixed selection of jets

outTag="20180628_newcode_data" 

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
#if ((addHHTagger)); then
#    python $HOME/HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag -a
#else
#    python $HOME/HHbbgg_ETH_devel/Limits/python/createReducedTrees.py -n $ntup -t $training  -o $outTag #fi
#fi
    
####transform MVA output
python $HOME/HHbbgg_ETH_devel/Limits/macros/transformMVAOutput.py -i $HOME'/HHbbgg_ETH_devel/outfiles/'$outTag'/Total_preselection_diffNaming.root'


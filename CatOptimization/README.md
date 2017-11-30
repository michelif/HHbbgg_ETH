# Clustering of boundaries for optimization

The notebooks here run on the output files obtained with the optimization code https://github.com/michelif/diphotons/blob/opt_hh/Utils/macro/run_all_nodes.sh <br />

They all run on the json files produced at the different optimization steps <br />

- optimal_categories.ipynb <br /> 

It runs the clustering of MVA boundaries, doing a simple average on the different nodes. <br />

- optimal_binning.ipynb <br />

It runs the clustering of MX boundaries. A clusterization algorithm is used for averaging the different nodes <br />

- optimal_mjj_per_cat.ipynb <br />

It clusterizes the mjj cut for each category. For each category a weighted average, using the significance as weight, is done on the different nodes.

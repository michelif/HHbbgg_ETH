# Workspaces and datacards production

All that it's needed to create workspace and datacards for combine:<br />
- makeWorkspaceHHbbgg.py<br /> 

It creates the workspace and the datacard. It needs a json file with
the definition of categories (or sub_categories) and creates both the .root and .txt file. <br />
Example:<br />

python makeWorkspaceHHbbgg.py -d jsons/HHbbgg_20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj.json -n 3 --nbins 320 -s jsons/HHbbgg_20170727_settings_optimizedCuts_withDR_dijetMass.json -m 0 -o HHbbgg_20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj_2.root <br />

- plotDatasets.py <br />

It plots the Mgg distribution for different categories using the root file created in the previous step. <br />
Example: <br />

python plotDatasets.py -i HHbbgg_20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj_2.root -o plots/20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj_2/9cat HHbbgg_20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj_2.root -s jsons/HHbbgg_20170727_settings_optimizedCuts_withDR_dijetMass.json -n 3 --nbins 3

##Utilities
- copyTree.py <br />
It copies the trees from the old format of the analysis, renaming them (useful to check improvements). <br />

- eventCounterFromTree.py <br />
Counts number of signal and background events for a given selection directly from trees. <br />

- generateRoc.py, compareRoc.py <br />
The first one creates Roc Curve of sig vs data sidebands, with a given selection: <br />

Example: <br />

python generateRoc.py -f /mnt/t3nfs01/data01/shome/micheli/HHbbgg_ETH_devel/outfiles/20170828_optimizedCuts/Total_preselection_diffNaming.root -v MVAOutput,100,0,1 -c  'Mjj>90 && Mjj<155' -o NOBJets.root --BSR <br />

The second one compares Roc for two different trainings: <br />

python compareRoc.py -f1 NOBjets.root -f2 BJets_2.root -o NOBJetsVSBJets_2.root <br />
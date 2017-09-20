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
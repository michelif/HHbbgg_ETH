#Limits with combine

Script to run combine, compute limits for all nodes and do plot of limit vs node. <br />
It takes as input the datacard produced by makeWorkspaceHHbbgg.py <br />

In order to run it you need first to setup combine. https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit <br />

Usage: <br />

python doLimitsAllNodes.py -d HHbbgg_20170727_optimizedCuts_dijetMass_reOptMVACut_Mjj_2.txt --doPlots --doCombine 
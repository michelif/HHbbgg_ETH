#source $VO_CMS_SW_DIR/cmsset_default.sh
# shopt -s expand_aliases is needed if you want to use the alias 'cmsenv' created by $VO_CMS_SW_DIR/cmsset_default.sh instead of the less mnemonic eval `scramv1 runtime -sh`

source $VO_CMS_SW_DIR/cmsset_default.sh
source /swshare/psit3/etc/profile.d/cms_ui_env.sh  # for bash

export MYCMSENVDIR=/mnt/t3nfs01/data01/shome/nchernya/CMSSW_8_0_25/src/
cd $MYCMSENVDIR
eval `scramv1 runtime -sh`
shopt -s expand_aliases 
cmsenv
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib64/dcap 

export MYBATCHDIR=/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/submit_jobs/
cd $MYBATCHDIR

./test_root $1 $2 $3 $TMPDIR/$4 

xrdfs t3se01.psi.ch rm  /store/user/nchernya/HHbbgg/b_regression/ttbar_unweighted/${4}_RegressionPerJet_heppy_energyRings3_forTraining_Large${3}_unweighted.root

xrdcp -f $TMPDIR/${4}_RegressionPerJet_heppy_energyRings3_forTraining_Large${3}_unweighted.root  root://t3dcachedb.psi.ch:1094//pnfs/psi.ch/cms/trivcat//store/user/nchernya/HHbbgg/b_regression/ttbar_unweighted/

#$ -o /mnt/t3nfs01/data01/shome/nchernya/batch_logs/
#$ -e /mnt/t3nfs01/data01/shome/nchernya/batch_logs/

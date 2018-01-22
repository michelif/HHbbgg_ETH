export WORKDIR=`pwd`
echo "Working on a machine:" `uname -a`
cd $WORKDIR

output_dir=(
ttbar_unweighted_full80M
)



max_samples=1 
current_sample=0 
while [ $current_sample -lt $max_samples ]
do
#	echo ${output_dir[current_sample]}
#	rm list${output_dir[current_sample]}_single.txt
#	rm list${output_dir[current_sample]}_single2.txt
#	path=root://t3dcachedb.psi.ch:1094///pnfs/psi.ch/cms/trivcat/
#	path2=/store/user/nchernya/HHbbgg/b_regression/ttbar_unweighted/
#	xrdfs t3se01.psi.ch ls $path2 > list${output_dir[current_sample]}.txt
#	awk -v path="$path" '{print path $0}' list${output_dir[current_sample]}.txt > list${output_dir[current_sample]}2.txt
#	rm list${output_dir[current_sample]}.txt


#	rm list${output_dir[current_sample]}.txt
##	rm list${output_dir[current_sample]}2.txt	
#	path=root://t3dcachedb.psi.ch:1094///pnfs/psi.ch/cms/trivcat/
#	path2=/store/user/nchernya/HHbbgg/b_regression/ttbar_unweighted//${output_dir[current_sample]}/
#	awk -v path="$path" '{print path $0}' list${output_dir[current_sample]}.txt > list${output_dir[current_sample]}2.txt
#	rm list${output_dir[current_sample]}.txt		


#lit=\`
#	echo hadd -f -k -v 99  /scratch/$USER/${output_dir[current_sample]}_v21.root    cat list${output_dir[current_sample]}2.txt | xargs 


	echo hadd  -k /scratch/$USER/${output_dir[current_sample]}.root    "\`"cat list${output_dir[current_sample]}2.txt"\`"   # used

	current_sample=$((current_sample + 1))
	##############xrdfs t3se01.psi.ch rm $path2${output_dir[current_sample]}_single_v21.root
done

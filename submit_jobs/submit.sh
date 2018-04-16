export WORKDIR=`pwd`
echo "Working on a machine:" `uname -a`
cd $WORKDIR

#g++ test_root.C -g -o test_root  `root-config --cflags --glibs`
g++ treeForRegression_unweight.C -g -o a_root `root-config --cflags --glibs` -lMLP -lXMLIO

num=1
#max=120
max=52 
name=HHbbgg_SM_full_jobs

counter=1
while [ $num -lt $max ]
do

#	num2=$(( $num + 10 ))
	num2=$(( $num + 1 ))
	qsub -q all.q batch.sh $num $num2 $counter $name 
#	qsub -q short.q batch.sh $num $num2 $counter $name
	sleep 5 

	echo $num
#	num=$(( $num + 10 ))
	num=$(( $num + 1 ))
	counter=$(( $counter + 1 ))
done


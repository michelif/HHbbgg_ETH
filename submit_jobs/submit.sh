export WORKDIR=`pwd`
echo "Working on a machine:" `uname -a`
cd $WORKDIR

#g++ test_root.C -g -o test_root  `root-config --cflags --glibs`

num=1000
#max=120
max=1550 
name=ttbar_unweighted_jobs

counter=200
while [ $num -lt $max ]
do

	num2=$(( $num + 10 ))
#	num2=$(( $num + 1 ))
	qsub -q all.q batch.sh $num $num2 $counter $name 
#	qsub -q short.q batch.sh $num $num2 $counter $name
	sleep 30 

	echo $num
	num=$(( $num + 10 ))
	counter=$(( $counter + 1 ))
done


export WORKDIR=`pwd`
echo "Working on a machine:" `uname -a`
cd $WORKDIR

###run the line below once to compile directly the excutable file 
#g++ treeForRegression_unweight.C -g -o a_root `root-config --cflags --glibs` -lMLP -lXMLIO

num=1000
#max=120
max=1543 
name=TTbar_legacy2016_JECv11

counter=101
while [ $num -lt $max ]
do

	num2=$(( $num + 10 ))
#	num2=$(( $num + 1 ))
	qsub -q all.q batch.sh $num $num2 $counter $name 
	sleep 1 

	echo $num
	num=$(( $num + 10 ))
#	num=$(( $num + 1 ))
	counter=$(( $counter + 1 ))
done


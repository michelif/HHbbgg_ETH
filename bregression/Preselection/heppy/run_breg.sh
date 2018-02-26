g++ run_macro_breg.C -g -o breg `root-config --cflags --glibs`
qsub -q all.q batch_python_breg_presel.sh $1 $2 $3
echo $1 $2 $3


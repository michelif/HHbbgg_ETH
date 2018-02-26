g++ run_skim_macro_breg.C -g -o run `root-config --cflags --glibs`
qsub -q all.q batch_python_breg.sh $1 $2 $3
echo $1 $2 $3

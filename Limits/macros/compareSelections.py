from ROOT import *
from array import array
import os 
import argparse

parser =  argparse.ArgumentParser(description='Compare txt files with number of events')
parser.add_argument('-f1', '--file1', dest='file1', required=True, type=str)
parser.add_argument('-f2', '--file2', dest='file2', required=True, type=str)

opt = parser.parse_args()


f1 = open(opt.file1,"r")
f2 = open(opt.file2,"r")

list1 = f1.readlines()
list2 = f2.readlines()

table = open("evtNumberComparison.txt","w+")
table.write("-----------------------------"+"\n")
table.write("file1: "+opt.file1+"\n")
table.write("file2: "+opt.file2+"\n")
table.write("-----------------------------"+"\n")


for i in range(0,len(list1)):
    lineList1 = list1[i].split()
    lineList2 = list2[i].split()
    if "MVAOutput" in list1[i]:
        table.write("--------------------------------\n")
        table.write(list1[i])
    if "MX" in list1[i]:
        table.write(list1[i])
        table.write("--------------------------------\n")
    if len(lineList1)<4: continue
    diff = float(lineList1[1])-float(lineList2[1])
    if "Sig" in lineList1[0] or "SM" in lineList1[0]:
        if (diff+1.5*float(lineList1[3]))<0:
            table.write(">>>>>>>>>>>>>>>>>>")
    else:
        if (diff-1.5*float(lineList1[3]))>0:
            table.write(">>>>>>>>>>>>>>>>>>")
        
    table.write(lineList1[0])
    if float(lineList1[3])>0:
        table.write(str(diff*100/float(lineList1[1]))+"% \n")



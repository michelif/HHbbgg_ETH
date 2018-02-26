import sys
import ROOT
import json
from numpy import array
from ROOT import TH2F
import subprocess
import shlex

debug=1



def ReadTextFile(filename):
	textfile=open(filename, 'r')
	filelines=textfile.readlines()
	filelines=CleanLines(filelines)
	if debug > 1000:
		print filelines
	samples=MakeSampleMap(filelines)
	for name in samples:
		sample=samples[name]
#		print sample["name"], len(sample["files"])
#		continue
#		print "Reading",sample["name"],"with",len(sample["files"]),"files"
		##for every sample submit skimming jobs, 50 files in one job
		inc = 20 #20 #50
		current_slice_num = 0
		tree_num = 0
		while current_slice_num < len(sample["files"]):
			slice_up_num = current_slice_num + inc
			if slice_up_num > len(sample["files"]) :
				slice_up_num = len(sample["files"])
		#	print current_slice_num, slice_up_num
		#	print sample["files"][current_slice_num:slice_up_num]
			## make string with list of files separated only by comma
			returnList = ""
			for i in range(current_slice_num,slice_up_num):
				returnList += sample["files"][i] + ","
			returnList = returnList[:-1]
			print returnList
			pass_arg=[]
			pass_arg.append("sh")
		#	pass_arg.append("run_python_skim_breg.sh")  #for b-reg
			pass_arg.append("run_breg.sh")  #for b-reg preselection
	#		pass_arg.append("run_python_skim.sh")  #for EWK Z+2jets
	#		pass_arg.append("run_python_skim_vbfhbb.sh")  #for VBF Hbb
			pass_arg.append(str(tree_num))
			pass_arg.append(sample["name"])
			pass_arg.append(returnList)
			print pass_arg[2],' ',pass_arg[3],' ',pass_arg[4]   #to resubmit data
			subprocess.check_call(pass_arg) #comment only for test, but it is the main call function
			current_slice_num+=inc
			tree_num+=1
	#		break
#		break
	return samples


def CleanLines(lines):
    cleanedLines=[]
    for line in lines:
        # skip if it is 100% whitespace
        if line.isspace():
            continue
        # remove comments
        if line.find("#") is -1 :        # no comment
            cleanedLines.append(line.split("\n")[0])
        elif line.find("#") is not 0:   # there is an inline comment
            cleanedLines.append(line[:line.find("#")])
        else:                           # whole line is commented
            if debug > 1000:
                print "this line is commented and will be removed"
                print line
    return cleanedLines


def MakeSampleMap(lines):
    if debug > 100: print "Reading samples"
    samples={}

    for line in lines:
        #print line
        samplename=""
        samplepaths=[]
        samplesite=''
        sample={}

        for item in line.split():
            name,value=item.split("=")
            if name.find("name") is 0:
                sample["name"]=str(value)
            if name.find("site") is 0:
                sample["site"]=str(value) 
            #    print sample["site"]    
            if name.find("dir") is 0:
                if value.find(',') is not 0:
                    for dirname in value.split(','):
                        samplepaths.extend(findAllRootFiles(dirname,sample["site"]))
                else:
                    samplepaths = findAllRootFiles(value,sample["site"])
 
        sample["files"]=samplepaths 
        if sample.has_key("name"):
            samples[sample["name"]]=sample
        else:
            print "sample name is empty",samplename,"not filling"
    
    return samples







def findAllRootFiles(value,site):
    samplepaths = []
   # if value.find("SingleMuon")!=-1 and (value.find('170220_152217') != -1 or value.find('170221_152129') != -1 ): return samplepaths
    if value.find("DoubleMuon")!=-1 and (value.find('171224_204118') != -1 or value.find('171230_175458') != -1  or value.find('171223_164727') != -1 ): return samplepaths
    if value.find("/store") is 0 or value.find("/pnfs") is 0:
        import subprocess
     #   site = 'root://stormgf1.pi.infn.it:1094/'
        onlyFiles = subprocess.check_output(["/usr/bin/xrdfs", site, "ls", value]).split('\n')
        for filepath in onlyFiles:
            if (filepath == ""): continue
            if filepath.find(".root") != -1:
                filepath = site + filepath
                samplepaths.append(filepath)
            elif (filepath.find("/log/")==-1 and filepath.find("/failed/")==-1):
                samplepaths.extend(findAllRootFiles(filepath,site))
    else:
        from os import listdir
        from os.path import isfile, join
        onlyfiles = [ f for f in listdir(str(value)) if isfile(join(str(value),f)) ]
        for rootfile in onlyfiles:
            if rootfile.find(".root") != -1:
                print rootfile
                samplepaths.append(str(value)+"/"+str(rootfile))
            else:
                samplepaths.extend(findAllRootFiles(str(value)+"/"+str(rootfile),site))
    return samplepaths

def main():
 ##   samplepaths = findAllRootFiles('/store/user/arizzi/VHBBHeppyV25/SingleMuon/','root://stormgf1.pi.infn.it:1094/')
 ##   print  samplepaths
	samples = ReadTextFile('samples_breg_preselection.txt') # for breg
#	samples = ReadTextFile('samples.txt') # for EWK Z+2jets
#	samples = ReadTextFile('samples_vbfhbb.txt') #for VBF Hbb
#	print samples["SingleMuon"]

if __name__ == "__main__":
    main()


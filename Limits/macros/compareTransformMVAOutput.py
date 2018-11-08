import sys, types, os
from optparse import OptionParser, make_option
from  pprint import pprint
from array import array

# -----------------------------------------------------------------------------------------------------------
def main(options,args):

    ## setTDRStyle()
    ROOT.gStyle.SetOptStat(0)
        

    processes = [
        "reducedTree_sig" #,
       # "reducedTree_data"
        ]

  #  for i in range(0,8):
    for i in range(0,3):
        if i == 1: continue #gJets are combined in one, i==2
        processes.append("reducedTree_bkg_"+str(i))


    files = options.files.split(',')
    colors=[1,2]
    plot_dir = '/shome/nchernya/HHbbgg_ETH_devel/Limits/macros/plots/transformedMVA/'
    what_list=['MVAOutputTransformed','MVAOutput']
    what=what_list[1]	

    for i,proc in enumerate(processes):
       print proc
       hist_list=[]
       c = ROOT.TCanvas("c_%s"%i,"c_%s"%i,600,600)
       c.cd()
       c.SetLogy()
       fins=[]
       fins.append(ROOT.TFile(files[0]))
       fins.append(ROOT.TFile(files[1]))
       for num,file in enumerate(files):
          print file
          tree = fins[num].Get(proc)
          hist = ROOT.TH1F("hist_%s_%s"%(i,num),"hist_%s_%s"%(i,num),100,0,1)
          hist.SetLineColor(colors[num])
          hist.SetLineWidth(2)
          ROOT.gStyle.SetOptTitle(1)
          ROOT.gStyle.SetOptStat(0)
         # tree.Draw("%s>>hist_%s_%s"%(what,i,num))
          tree.Draw("%s>>hist_%s_%s"%(what,i,num),"weight")
          hist.Scale(1./hist.Integral())
          hist.SetTitle(proc)
          hist.Draw("APsame")
          hist_list.append(hist)
         # print 'integral = ',hist.Integral(),' ',hist_list[num].Integral()
          if num==1 : hist_list[0].Draw("same")
       leg = ROOT.TLegend(0.7,0.75,0.9,0.9)
       leg.AddEntry(hist_list[0],"2016" ,"L")
       leg.AddEntry(hist_list[1],"2017" ,"L")
       leg.SetFillStyle(-1)
       leg.SetBorderSize(0)
       leg.SetTextFont(42)
       leg.SetTextSize(0.03)
       leg.Draw()
       c.Draw()
       c.SaveAs(plot_dir+what+'_'+proc+'.pdf')	

			
        
if __name__ == "__main__":

    parser = OptionParser(option_list=[
            make_option("-i", "--infiles",
                        action="store", type="string", dest="files",
                        default="",
                        help="input files",
                        ),
            ]
                          )

    (options, args) = parser.parse_args()
    sys.argv.append("-b")

    
    pprint(options.__dict__)

    import ROOT
    
    main(options,args)
        

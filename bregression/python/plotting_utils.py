import training_utils as utils
import optimization_utils as optimization

import numpy as np
from sklearn.metrics import roc_curve, auc
from sklearn.preprocessing import label_binarize
import matplotlib.pyplot as plt
import ROOT
import math
from array import array
from ROOT import std
from ROOT import gROOT
from ROOT import gStyle
from ROOT import TH1F, TGraph, TF1
from ROOT import TCanvas
from ROOT import RooRealVar, RooDataHist, RooFormulaVar, RooVoigtian, RooChebychev, RooArgList, \
                 RooArgSet, RooAddPdf, RooDataSet, RooCategory, RooSimultaneous, \
                 RooBreitWigner, RooCBShape, RooFFTConvPdf, RooBukinPdf, RooBifurGauss, RooGenericPdf, RooChi2Var
        
# ---------------------------------------------------------------------------------------------------
def plot_classifier_output(clf,X_total_train,X_total_test,y_total_train,y_total_test,outString=None):
    

    sig_train = X_total_train[y_total_train > 0]
    bkg_train = X_total_train[y_total_train < 0]
    sig_test = X_total_test[y_total_test > 0]
    bkg_test = X_total_test[y_total_test < 0]

    #if n_classses > 2 sig proba is the last one (in the way the code is written) 
    Y_pred_sig_train = clf.predict_proba(sig_train)[:,clf.n_classes_-1]
    Y_pred_bkg_train = clf.predict_proba(bkg_train)[:,clf.n_classes_-1]
    Y_pred_sig_test = clf.predict_proba(sig_test)[:,clf.n_classes_-1]
    Y_pred_bkg_test = clf.predict_proba(bkg_test)[:,clf.n_classes_-1]




    weights_sig_train = (np.ones_like(sig_train)/float(len(sig_train)))[:,1]
    weights_bkg_train = (np.ones_like(bkg_train)/float(len(bkg_train)))[:,1]
    weights_sig_test = (np.ones_like(sig_test)/float(len(sig_test)))[:,1]
    weights_bkg_test = (np.ones_like(bkg_test)/float(len(bkg_test)))[:,1]



    # This will be the min/max of our plots
    c_max = max(np.max(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))
    c_min = min(np.min(d) for d in np.concatenate([Y_pred_sig_train,Y_pred_bkg_train,Y_pred_sig_test,Y_pred_bkg_test]))

    # Get histograms of the classifiers
    Histo_training_S = np.histogram(Y_pred_sig_train,bins=40,range=(c_min,c_max),weights=weights_sig_train)
    Histo_training_B = np.histogram(Y_pred_bkg_train,bins=40,range=(c_min,c_max),weights=weights_bkg_train)
    Histo_testing_S = np.histogram(Y_pred_sig_test,bins=40,range=(c_min,c_max),weights=weights_sig_test)
    Histo_testing_B = np.histogram(Y_pred_bkg_test,bins=40,range=(c_min,c_max),weights=weights_bkg_test)


    
    # Lets get the min/max of the Histograms
    AllHistos= [Histo_training_S,Histo_training_B,Histo_testing_S,Histo_testing_B]
    h_max = max([histo[0].max() for histo in AllHistos])*1.2
    h_min = min([histo[0].min() for histo in AllHistos])
    
    # Get the histogram properties (binning, widths, centers)
    bin_edges = Histo_training_S[1]
    bin_centers = ( bin_edges[:-1] + bin_edges[1:]  ) /2.
    bin_widths = (bin_edges[1:] - bin_edges[:-1])
    
    # To make error bar plots for the data, take the Poisson uncertainty sqrt(N)
    ErrorBar_testing_S = np.sqrt(Histo_testing_S[0]/Y_pred_sig_test.size)
    ErrorBar_testing_B = np.sqrt(Histo_testing_B[0]/Y_pred_bkg_test.size)
    

    # Draw objects
    ax1 = plt.subplot(111)
    
    # Draw solid histograms for the training data
    ax1.bar(bin_centers-bin_widths/2.,Histo_training_S[0],facecolor='blue',linewidth=0,width=bin_widths,label='S (Train)',alpha=0.5)
    ax1.bar(bin_centers-bin_widths/2.,Histo_training_B[0],facecolor='red',linewidth=0,width=bin_widths,label='B (Train)',alpha=0.5)
    
    # # Draw error-bar histograms for the testing data
    ax1.errorbar(bin_centers, Histo_testing_S[0], yerr=ErrorBar_testing_S, xerr=None, ecolor='blue',c='blue',fmt='o',label='S (Test)')
    ax1.errorbar(bin_centers, Histo_testing_B[0], yerr=ErrorBar_testing_B, xerr=None, ecolor='red',c='red',fmt='o',label='B (Test)')
    
    # Make a colorful backdrop to show the clasification regions in red and blue
    ax1.axvspan(0.5, c_max, color='blue',alpha=0.08)
    ax1.axvspan(c_min,0.5, color='red',alpha=0.08)

    # Adjust the axis boundaries (just cosmetic)
    ax1.axis([c_min, c_max, h_min, h_max])

    # Make labels and title
    plt.title("Classification with scikit-learn")
    plt.xlabel("Classifier output")
    plt.ylabel("Normalized Yields")
    
    # Make legend with smalll font
    legend = ax1.legend(loc='upper center', shadow=True,ncol=2)
    for alabel in legend.get_texts():
        alabel.set_fontsize('small')

    # Save the result to png
    plt.savefig(utils.IO.plotFolder+"classifierOutputPlot_"+str(outString)+".png")
    plt.savefig(utils.IO.plotFolder+"classifierOutputPlot_"+str(outString)+".pdf")

    
    

#def plot_rel_pt_diff(predictions,true,recoPt,style=False,n_bins=50,outString=None):  
def plot_rel_pt_diff(rel_diff_regressed,rel_diff,style=False,n_bins=50,outString=None,option='caterina'):  

    if style==True:
        gROOT.SetBatch(True)
        gROOT.ProcessLineSync(".x /mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/scripts/setTDRStyle.C")
        gROOT.ForceStyle()
        gStyle.SetPadTopMargin(0.06)
        gStyle.SetPadRightMargin(0.04)
        gStyle.SetPadLeftMargin(0.15)
    
    
   #### rel_diff_regressed = (predictions - true)/true
   #### rel_diff = (recoPt - true)/true
#    rel_diff_regressed = true/predictions
 #   rel_diff = true/recoPt
    
    c_min = min(min(rel_diff_regressed),min(rel_diff))
    c_max = max(max(rel_diff_regressed),max(rel_diff))
    c_min=0
    c_max=2.
    
    Histo_rel_diff = np.histogram(rel_diff,bins=n_bins,range=(c_min,c_max))
    Histo_rel_diff_reg = np.histogram(rel_diff_regressed,bins=n_bins,range=(c_min,c_max))
    
    h_rel_diff = TH1F("hrel_diff", "hrel_diff", n_bins, c_min, c_max)
    for i in xrange(len(rel_diff)): 
        h_rel_diff.Fill(rel_diff[i])
    h_rel_diff_reg = TH1F("hrel_diff_reg", "hrel_diff_reg", n_bins, c_min, c_max)
    for i in xrange(len(rel_diff_regressed)): 
        h_rel_diff_reg.Fill(rel_diff_regressed[i])
    h_rel_diff.SetLineColor(ROOT.kBlue)
    h_rel_diff.SetMarkerColor(ROOT.kBlue)
    h_rel_diff.SetLineWidth(2)
    h_rel_diff_reg.SetLineColor(ROOT.kRed)
    h_rel_diff_reg.SetMarkerColor(ROOT.kRed)
    h_rel_diff_reg.SetLineWidth(2)
   

    
    AllHistos= [Histo_rel_diff, Histo_rel_diff_reg]
    h_max = max([histo[0].max() for histo in AllHistos])*1.2
    h_min = min([histo[0].min() for histo in AllHistos])
    
    c = ROOT.TCanvas("c","c",900,900)
    c.cd()
    frame = TH1F("hframe", "hframe", n_bins, c_min, c_max)
    frame.SetStats(0)
    frame.GetXaxis().SetTitleOffset(0.91);
    frame.GetYaxis().SetTitle("Events")
  #  frame.GetXaxis().SetTitle("(p_{T}^{Reco}-p_{T}^{gen})/p_{T}^{gen}")
    frame.GetXaxis().SetTitle("p_{T}^{gen}/p_{T}^{reco}")
    frame.GetYaxis().SetLabelSize(0.04)
    frame.GetYaxis().SetRangeUser(h_min,h_max)
    
    frame.Draw()
    h_rel_diff.Draw("samePE")
    h_rel_diff_reg.Draw("samePE")
    print 'Nominal : mean, RMS :',h_rel_diff.GetMean(), h_rel_diff.GetRMS()
    print 'Regresesd : mean, RMS : ',h_rel_diff_reg.GetMean(), h_rel_diff_reg.GetRMS()

  

    
    
    
    leg = ROOT.TLegend(0.55,0.75,0.9,0.9)
    leg.SetFillStyle(-1)
    leg.SetBorderSize(0)
    leg.SetTextFont(42)
    leg.SetTextSize(0.03)
  #  leg.Draw()
    

    h_names = ['nom','reg']
    datahists = [h_rel_diff,h_rel_diff_reg]
    x=[]
    datahist=[]
    m=[]
    m_initial=[1.0103e+00,9.5381e-01]
    s=[]
    s_initial=[ 1.3210e-01,1.3967e-01]
    a=[]
    a_initial=[-7.7802e-01,-1.1260e+00]
    n=[]
    n_initial=[ 6.0149e+00,5.5622e+00]
    
    Ap,Xp,sigp,xi,rho1,rho2 = [],[],[],[],[],[]
    Xp_initial,sigp_initial,xi_initial,rho1_initial,rho2_initial =  9.8545e-01, 1.3118e-01,2.2695e-01, 6.4189e-02,  9.0282e-02 
    meanr, sigmaL, sigmaR, alphaL, alphaR = [],[],[],[],[]   
 
    fsig=[]
    sig=[]
    model=[]
    res=[]
    integral=[]
    formula=[]
    scale_factors=[]
    scaled_cb=[]
    func=[]
    colors=[ROOT.kBlue,ROOT.kRed]
    chi_squares=[]
    fwhm_bukin=[]
    fwhm=[]
    fwhm.append( -1 *(h_rel_diff.GetBinCenter( h_rel_diff.FindFirstBinAbove(h_rel_diff.GetMaximum()/2.)  )  - h_rel_diff.GetBinCenter( h_rel_diff.FindLastBinAbove(h_rel_diff.GetMaximum()/2.) ) )  )
    fwhm.append( -1 *(h_rel_diff_reg.GetBinCenter( h_rel_diff_reg.FindFirstBinAbove(h_rel_diff_reg.GetMaximum()/2.)  )  - h_rel_diff_reg.GetBinCenter( h_rel_diff_reg.FindLastBinAbove(h_rel_diff_reg.GetMaximum()/2.) ) )  )

    for num,h in enumerate(h_names):
        x.append(RooRealVar("x_%s"%h,"x_%s"%h,c_min,c_max))
        datahist.append(RooDataHist("roohist_%s"%h,"roohist_%s"%h,RooArgList(x[num]),datahists[num]))
       #######################Crystal ball################ 
        m.append(RooRealVar("mean_%s"%h,"mean_%s"%h,m_initial[num],0.5,1.5))
        s.append(RooRealVar("sigma_%s"%h,"sigma_%s"%h,s_initial[num],0.01,0.3))
        a.append(RooRealVar("alpha_%s"%h,"alpha_%s"%h,a_initial[num],-10,0.))
        n.append(RooRealVar("exp_%s"%h,"exp_%s"%h,n_initial[num],1.,100.))
      #  sig.append(RooCBShape("signal_gauss_%s"%h,"signal_gauss_%s"%h,x[num],m[num],s[num],a[num],n[num]))

      #######################Bukin function ################## 
    
        Xp.append(RooRealVar("Xp_%s"%h,"Xp_%s"%h,Xp_initial,0.,3.))
        sigp.append(RooRealVar("sigp_%s"%h,"sigp_%s"%h,sigp_initial,0.01,0.3))
        xi.append(RooRealVar("xi_%s"%h,"xi_%s"%h,xi_initial,-1,1))
        rho1.append(RooRealVar("rho1_%s"%h,"rho1_%s"%h,rho1_initial,-1,1)) #left
        rho2.append(RooRealVar("rho2_%s"%h,"rho2_%s"%h,rho2_initial,-1,1)) #right
        sig.append(RooBukinPdf("signal_bukin_%s"%h,"signal_bukin_%s"%h,x[num],Xp[num],sigp[num],xi[num],rho1[num],rho2[num]))

###########################RooCruijff##################

        meanr.append(RooRealVar("meanr_%s"%h,"meanr_%s"%h,m_initial[num],0.5,1.5))
        sigmaL.append(RooRealVar("sigmaL_%s"%h,"sigmaL_%s"%h,s_initial[num],0.01,0.3))
        sigmaR.append(RooRealVar("sigmaR_%s"%h,"sigmaR_%s"%h,s_initial[num],0.01,0.3))
        alphaL.append(RooRealVar("alphaL_%s"%h,"alphaL_%s"%h,0.01,0,2.))
        alphaR.append(RooRealVar("alphaR_%s"%h,"alphaR_%s"%h,0.1,0.,2.))
#  RooGenericPdf genpdf("genpdf","genpdf","(1+0.1*abs(x)+sin(sqrt(abs(x*alpha+0.1))))",RooArgSet(x,alpha)) ;
        formula_rooCruijff = "( ( (x_%s-meanr_%s)<0) ? (exp( -1*pow((x_%s-meanr_%s),2)/(2*pow(sigmaL_%s,2)+alphaL_%s*pow((x_%s-meanr_%s),2) ))) : (exp( -1*pow((x_%s-meanr_%s),2)/(2*pow(sigmaR_%s,2)+alphaR_%s*pow((x_%s-meanr_%s),2) )))  )"%(h,h,h,h,h,h,h,h,h,h,h,h,h,h) 
    #    sig.append(RooGenericPdf("signal_cruijff_%s"%h,"signal_cruijjff_%s"%h,formula_rooCruijff,RooArgList(x[num],meanr[num],sigmaL[num],sigmaR[num],alphaL[num],alphaR[num])))
    #    sig.append(RooBifurGauss("signal_cruijff_%s"%h,"signal_cruijjff_%s"%h,x[num],meanr[num],sigmaL[num],sigmaR[num]))

     #   fit_range_min = h_rel_diff.GetMean()-fwhm[num]
     #   fit_range_max = h_rel_diff.GetMean()+fwhm[num]
     #   print 'range of the fit : ', fit_range_min, fit_range_max
     #   res.append(sig[num].fitTo(datahist[num],ROOT.RooFit.Save(ROOT.kTRUE),ROOT.RooFit.Range(fit_range_min,fit_range_max))) # take Mean of each histogram and add 1/2 of the RMS  ? -> try that

        res.append(sig[num].fitTo(datahist[num],ROOT.RooFit.Save(ROOT.kTRUE)))
        res[num].Print()

       # chi_squares.append((x[num].frame()).chiSquare())
        x[num].setRange("integralRange%s"%h, c_min,c_max)  
        integral.append(sig[num].createIntegral(RooArgSet(x[num]), ROOT.RooFit.Range("integralRange%s"%h)))

        scale_factors.append(datahists[num].Integral()*datahists[num].GetBinWidth(1)/integral[num].getVal())
        scale_factors.append(datahists[num].Integral()*datahists[num].GetBinWidth(1)/integral[num].getVal())
      #  formula.append("%f *signal_gauss_%s"%(scale_factors[num],h))
        formula.append("%f *signal_bukin_%s"%(scale_factors[num],h))
     #   formula.append("%f *signal_cruijff_%s"%(scale_factors[num],h))
       # create a scaled  function = scale * function
        scaled_cb.append(RooFormulaVar("scaled_cb_%s"%h,formula[num],RooArgList(sig[num])))
        func.append(scaled_cb[num].asTF(RooArgList(x[num])))
        func[num].SetLineColor(colors[num])
        datahists[num].SetMarkerColor(colors[num])
        fwhm_bukin.append(sigp[num].getVal()*2*math.sqrt(2*math.log(2)))
      
      #  chi_squares.append(RooChi2Var("chi2_%s"%h,"chi2_%s"%h,sig[num],datahist[num]))

    
    fitfunc='Bukin'
  #  fitfunc='Bifurgaus'
    fit_result_file = std.ofstream(utils.IO.plotFolder+"../fitResults/fitResult_%s"%(fitfunc)+str(outString)+'.txt')
    res[0].floatParsFinal().printMultiline(fit_result_file, 1111, True)
    res[1].floatParsFinal().printMultiline(fit_result_file, 1111, True)
    fit_result_file.close()

    
    if option=='caterina' :
        leg.AddEntry(h_rel_diff,"Caterina, FWHM=%.3f"%fwhm[0] ,"P")
        leg.AddEntry(h_rel_diff,"FWHM Bukin =%.3f"%fwhm_bukin[0] ,"P")
        leg.AddEntry(h_rel_diff_reg,"XGboost, FWHM=%.3f"%fwhm[1],"P")
        leg.AddEntry(h_rel_diff_reg,"FWHM Bukin =%.3f"%fwhm_bukin[1],"P")
    else : 
        leg.AddEntry(h_rel_diff,"Nominal" ,"P")
        leg.AddEntry(h_rel_diff_reg,"Regressed" ,"P")

	
    c2 = ROOT.TCanvas("c2","c2",900,900)
    c2.cd()
    frame.Draw()
    func[0].Draw("same")
    func[1].Draw("same")
    h_rel_diff.Draw("PEHISTsame")
    h_rel_diff_reg.Draw("PEHISTsame")    
    leg.Draw()
  
   # c2.SaveAs(utils.IO.plotFolder+"pt_rel_fitCruijff_"+str(outString)+'.png')
  #  c2.SaveAs(utils.IO.plotFolder+"pt_rel_noFit_"+str(outString)+'.png')
    c2.SaveAs(utils.IO.plotFolder+"pt_rel_fit%s_"%(fitfunc)+str(outString)+'.png')
    c2.Draw()
 
    
    
def plot_regions(X_region,names,style=True,n_bins=50,outString=None,log=False,title=''):  
    if style==True:
        gROOT.SetBatch(True)
        gROOT.ProcessLineSync(".x /mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/scripts/setTDRStyle.C")
        gROOT.ForceStyle()
        gStyle.SetPadTopMargin(0.06)
        gStyle.SetPadRightMargin(0.04)
        gStyle.SetPadLeftMargin(0.15)
    

    h_names = [ 'region'+str(t) for t in range(0,len(X_region))]

    c_min=0
  #  c_max=2.
    c_max=4.
    c = TCanvas("canv","canv",900,900)
    c.cd()
    frame = TH1F("hframe", "hframe", n_bins, c_min, c_max)
    frame.SetStats(0)
    frame.GetXaxis().SetTitleOffset(0.91);
    frame.GetYaxis().SetTitle("Events")
    frame.GetXaxis().SetTitle("p_{T}^{gen}/p_{T}^{reco}")
    frame.GetYaxis().SetLabelSize(0.04)
    leg = ROOT.TLegend(0.12,0.75,0.6,0.9)
    leg.SetFillStyle(-1)
    leg.SetBorderSize(0)
    leg.SetTextFont(42)
    leg.SetTextSize(0.025)
    if title!='' :  leg.AddEntry(frame,title,"")

    hist_list=[]
    func_list=[]
    max_list=[]
    x=[]
    datahist=[]
    datahists=[]
    meanr, sigmaL, sigmaR, alphaL, alphaR = [],[],[],[],[]   
    Ap,Xp,sigp,xi,rho1,rho2 = [],[],[],[],[],[]
    meanv, widthv, sigmav = [] , [] , []
    Xp_initial,sigp_initial,xi_initial,rho1_initial,rho2_initial =  9.8545e-01, 1.3118e-01,2.2695e-01, 6.4189e-02,  9.0282e-02 
    fsig=[]
    sig=[]
    model=[]
    res=[]
    integral=[]
    formula=[]
    scale_factors=[]
    scaled=[]
    func=[]
    colors=[ROOT.kBlue+1,ROOT.kAzure+5,ROOT.kCyan-1, ROOT.kGreen, ROOT.kSpring+8, ROOT.kOrange, ROOT.kPink+10]
 
 
    for j in range(len(X_region)):
        if isinstance(X_region[j], np.ndarray) : data = X_region[j]
        else : data =((X_region[j]).as_matrix()).ravel()
        print len(data)
        h_rel_diff = TH1F("hrel_diff_%s"%h_names[j], "hrel_diff_%s"%h_names[j], n_bins, c_min, c_max)
        h_rel_diff.Sumw2(True)
        for i in xrange(len(data)): 
            h_rel_diff.Fill(data[i])
        h_rel_diff.Scale(1./h_rel_diff.Integral())
        h_rel_diff.SetLineColor(colors[j])
        h_rel_diff.SetMarkerColor(colors[j])
        h_rel_diff.SetLineWidth(2)
        h_rel_diff.SetLineStyle(1+j)
    
    #    if (log==True) : max_list.append(h_rel_diff.GetMaximum()*1.3)
        max_list.append(h_rel_diff.GetMaximum()*1.4)
        datahists.append(h_rel_diff)


        num=j
        h = h_names[j]
        x.append(RooRealVar("x_%s"%h,"x_%s"%h,c_min,c_max))
        datahist.append(RooDataHist("roohist_%s"%h,"roohist_%s"%h,RooArgList(x[num]),datahists[num]))
        #######################Bukin function ################## 
        Xp.append(RooRealVar("Xp_%s"%h,"Xp_%s"%h,Xp_initial,0.,3.))
        sigp.append(RooRealVar("sigp_%s"%h,"sigp_%s"%h,sigp_initial,0.01,0.3))
        xi.append(RooRealVar("xi_%s"%h,"xi_%s"%h,xi_initial,-1,1))
        rho1.append(RooRealVar("rho1_%s"%h,"rho1_%s"%h,rho1_initial,-1,1)) #left
        rho2.append(RooRealVar("rho2_%s"%h,"rho2_%s"%h,rho2_initial,-1,1)) #right
        sig.append(RooBukinPdf("signal_bukin_%s"%h,"signal_bukin_%s"%h,x[num],Xp[num],sigp[num],xi[num],rho1[num],rho2[num]))
###########################RooCruijff##################
        meanr.append(RooRealVar("meanr_%s"%h,"meanr_%s"%h,Xp_initial,0.5,1.5))
        sigmaL.append(RooRealVar("sigmaL_%s"%h,"sigmaL_%s"%h,sigp_initial,0.01,0.3))
        sigmaR.append(RooRealVar("sigmaR_%s"%h,"sigmaR_%s"%h,sigp_initial,0.01,0.3))
        alphaL.append(RooRealVar("alphaL_%s"%h,"alphaL_%s"%h,0.01,0,2.))
        alphaR.append(RooRealVar("alphaR_%s"%h,"alphaR_%s"%h,0.1,0.,2.))
        formula_rooCruijff = "( ( (x_%s-meanr_%s)<0) ? (exp( -1*pow((x_%s-meanr_%s),2)/(2*pow(sigmaL_%s,2)+alphaL_%s*pow((x_%s-meanr_%s),2) ))) : (exp( -1*pow((x_%s-meanr_%s),2)/(2*pow(sigmaR_%s,2)+alphaR_%s*pow((x_%s-meanr_%s),2) )))  )"%(h,h,h,h,h,h,h,h,h,h,h,h,h,h) 
     #   sig.append(RooGenericPdf("signal_cruijff_%s"%h,"signal_cruijff_%s"%h,formula_rooCruijff,RooArgList(x[num],meanr[num],sigmaL[num],sigmaR[num],alphaL[num],alphaR[num])))
      #  sig.append(RooBifurGauss("signal_bifurgaus_%s"%h,"signal_bifurgaus_%s"%h,x[num],meanr[num],sigmaL[num],sigmaR[num]))
############################VOigt##########################
        meanv.append(RooRealVar("meanv_%s"%h,"meanv_%s"%h,Xp_initial,0.5,1.5))
        widthv.append(RooRealVar("widthv_%s"%h,"widthv_%s"%h,sigp_initial,0.01,0.7))
        sigmav.append(RooRealVar("sigmav_%s"%h,"sigmav_%s"%h,sigp_initial,0.01,0.7))
   #     sig.append(RooVoigtian("signal_voigt_%s"%h,"signal_voigt_%s"%h,x[num],meanv[num],widthv[num],sigmav[num]))

###########################################################


        res.append(sig[num].fitTo(datahist[num],ROOT.RooFit.Save(ROOT.kTRUE)))
        fit_range_min = h_rel_diff.GetMean()-h_rel_diff.GetRMS()/2
        fit_range_max = h_rel_diff.GetMean()+h_rel_diff.GetRMS()/2
        print 'range of the fit : ', fit_range_min, fit_range_max
   #     res.append(sig[num].fitTo(datahist[num],ROOT.RooFit.Save(ROOT.kTRUE),ROOT.RooFit.Range(fit_range_min,fit_range_max))) # take Mean of each histogram and add 1/2 of the RMS  ? -> try that
        res[num].Print()
        x[num].setRange("integralRange%s"%h, c_min,c_max)  
        integral.append(sig[num].createIntegral(RooArgSet(x[num]), ROOT.RooFit.Range("integralRange%s"%h)))

        scale_factors.append(datahists[num].Integral()*datahists[num].GetBinWidth(1)/integral[num].getVal())
        formula.append("%f *signal_bukin_%s"%(scale_factors[num],h))
       # formula.append("%f *signal_bifurgaus_%s"%(scale_factors[num],h))
      #  formula.append("%f *signal_voigt_%s"%(scale_factors[num],h))
      #  formula.append("%f *signal_cruijff_%s"%(scale_factors[num],h))
       # create a scaled  function = scale * function
        scaled.append(RooFormulaVar("scaled_%s"%h,formula[num],RooArgList(sig[num])))
        func_list.append(scaled[num].asTF(RooArgList(x[num])))
        func_list[num].SetLineColor(colors[num])
        hist_list.append(h_rel_diff)
   

    fitfunc='Bukin'
    fit_result_file = std.ofstream(utils.IO.plotFolder+"../fitResults/fitResultRegions_%s"%(fitfunc)+str(outString)+'.txt')
    fit_result_file.write('mean Xp\n',8)
    for fitnum in range(len(X_region)):
       Xp[fitnum].writeToStream(fit_result_file,False)
       fit_result_file.write('\n',1)
    fit_result_file.write('sigp\n',5)
    for fitnum in range(len(X_region)):
       sigp[fitnum].writeToStream(fit_result_file,False)
       fit_result_file.write('\n',1)
    fit_result_file.close()

    c.cd()
    frame.GetYaxis().SetRangeUser(1e-06,max(max_list))
 #   frame.GetYaxis().SetRangeUser(1e-06,0.28)
    log_name=''
    if log==True : 
        c.SetLogy()
        log_name='log'
    frame.Draw()
    for j in range(len(X_region)):
        func_list[j].Draw("same")
        hist_list[j].Draw("PEsame")
        leg.AddEntry(hist_list[j],names[j]+',Xp=%.2f,sigp=%.2f'%(Xp[j].getVal(),sigp[j].getVal()) ,"PE")
    leg.Draw('same')
  #  save_name=utils.IO.plotFolder+"pt_regions_fitBukin_"+str(outString)+'.png'
  #  c.SaveAs("pt_region.png")
    outString = outString.replace('/','_').replace(':','_').replace('(','_').replace(')','_').replace('+','_').replace('>=','_').replace('<','_').replace('>','_')
    c.SaveAs(utils.IO.plotFolder+"fitBukin_regions_"+str(outString)+log_name+'.png')
   # c.SaveAs(utils.IO.plotFolder+"fitCruijff_regions_"+str(outString)+log_name+'.png')
  #  c.SaveAs(utils.IO.plotFolder+"fitBifurgaus_regions_"+str(outString)+log_name+'.png')
 #   c.SaveAs(utils.IO.plotFolder+"fitVoigt_regions_"+str(outString)+log_name+'.png')
  #  c.Draw()
    
def myCDF(x,p):
    x0 = p[0]
    q1 = p[1]
    q3 = p[2]
    const = p[3]
    xmax = x0+const*(q3-x0)
    xmin = x0-const*(x0-q1)
    if (x[0]>xmax) :return (const*(xmax-q1) + (q1-x0)/3. -  ( pow((xmax-x0),3)/3./pow((q3-x0),2) )  )
    elif (x[0] > x0) : return (const*(x[0]-q1) + (q1-x0)/3. -  ( pow((x[0]-x0),3)/3./pow((q3-x0),2) )  )
    elif (x[0] <= x0) : return ( const*(x[0]-q1) + (-1.)*pow((x[0]-x0),3)/3./pow((x0-q1),2) + (q1-x0)/3. )  
    elif (x[0]<xmin) :return -0.25

 

def myErFuncCdf(x,p):
    x0 = p[0]
    la= p[1]
    a1 = p[2]
    a2 = p[3]
    erF = 1./(1.+np.exp(-1*(x[0]-x0)*la))
    if (x[0] >= x0)  : return erF*a1*x[0] 
    if (x[0] < x0)  : return erF*a2*x[0] 

 
def fit_quantiles(X_region,names,style=True,n_bins=100,pol='Pol',outString=None):  
    if style==True:
        gROOT.SetBatch(True)
        gROOT.ProcessLineSync(".x /mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/scripts/setTDRStyle.C")
        gROOT.ForceStyle()
        gStyle.SetPadTopMargin(0.06)
        gStyle.SetPadRightMargin(0.04)
        gStyle.SetPadLeftMargin(0.15)
    

    h_names = [ 'region'+str(t) for t in range(0,len(X_region))]

    c_min=0
    c_max=2.

    hist_list=[]
    func_list=[]
    max_list=[]
    datahists=[]
    graphs=[]
    func=[]
    colors=[ROOT.kBlue+1,ROOT.kAzure+5,ROOT.kCyan-1, ROOT.kGreen, ROOT.kSpring+8, ROOT.kOrange]
   # nqx=3
  #  taus = array('d',[0.25, 0.5, 0.75])
  #  nqx=5
  #  taus = array('d',[0.5-0.68/2,0.3, 0.5, 0.7, 0.5+0.68/2.])
 #   nqx=4
  #  taus = array('d',[0.5-0.68/2,0.3, 0.5, 0.8])
  #  nqx=4
  #  taus = array('d',[0.5-0.68/2,0.4, 0.5, 0.8])
 #   nqx=4
  #  taus = array('d',[0.10,0.16, 0.2, 0.7])
 #   nqx=4
  #  taus = array('d',[0.10,0.16, 0.4, 0.7])   
  #  nqx=5
   # taus = array('d',[0.10,0.16, 0.4, 0.6, 0.8])   
   # nqx=5
   # taus = array('d',[0.10,0.20, 0.4, 0.6, 0.8])   
    nqx=4
    taus = array('d',[0.10,0.20, 0.4, 0.7])    # the best
    taus_fit = array('d',[x-taus[0] for x in taus ])
    quantiles_pos=[]
    x0_hist=[]
    x0_CDFfit=[]
 
 
    for j in range(len(X_region)):
        h=h_names[j]
        data =((X_region[j]).as_matrix()).ravel()
        print len(data)
        h_rel_diff = TH1F("hrel_diff_%s"%h_names[j], "hrel_diff_%s"%h_names[j], n_bins, c_min, c_max)
        h_rel_diff.Sumw2(True)
        for i in xrange(len(data)): 
            h_rel_diff.Fill(data[i])
        h_rel_diff.Scale(1./h_rel_diff.Integral())
        h_rel_diff.SetLineColor(colors[j])
        h_rel_diff.SetMarkerColor(colors[j])
        h_rel_diff.SetLineWidth(2)
        h_rel_diff.SetLineStyle(1+j)
        h_rel_diff.SetMarkerStyle(20+j)
        datahists.append(h_rel_diff)
        quantiles_x = array('d', [0 for x in range(0, nqx)])
        h_rel_diff.GetQuantiles( nqx,quantiles_x, taus )
        quantiles_pos.append(quantiles_x)
        max_list.append(h_rel_diff.GetMaximum()*1.3)
        x0_hist.append(h_rel_diff.GetBinCenter(h_rel_diff.GetMaximumBin()))

        gr = TGraph(nqx,quantiles_x,taus_fit);
        gr.SetLineColor(colors[j])
        gr.SetMarkerColor(colors[j])
        gr.SetMarkerStyle(20+j)
        graphs.append(gr)

   #     fit_cdf = TF1("fit_%s"%h, myCDF, 0., 2., 4)   
       # fit_cdf = TF1("fit_%s"%h, myCDF,quantiles_x[0]*0.98,quantiles_x[4]*1.02,4) 
     #   fit_cdf = TF1("fit_%s"%h, myErFuncCdf,quantiles_x[0]*0.98,quantiles_x[3]*1.02,4) 
    #    fit_cdf = TF1("fit_%s"%h,"pol3",quantiles_x[0]*0.98,quantiles_x[nqx-1]*1.02)   #final with pol3
        fit_cdf = TF1("fit_%s"%h,"pol3",quantiles_x[0]*0.98,quantiles_x[nqx-1]*1.02)   #final with pol3
  #      fit_cdf.FixParameter(1,quantiles_x[0] )  #q1   
  #      fit_cdf.FixParameter(2,quantiles_x[2] )  #q3   
  #      fit_cdf.SetParameter(0,1. )  #x0   
  #      fit_cdf.SetParameter(4,3. )  #const 
  #      fit_cdf.SetParLimits(4,0.,10 )  #const 
  #      fit_cdf.SetParLimits(0, 0.5, 1.5)    
        fit_cdf.SetLineColor(colors[j])
        gr.Fit("fit_%s"%h,"R")
        func.append(fit_cdf)
        
   #     pol_coeff = [6*fit_cdf.GetParameter(4), 3*fit_cdf.GetParameter(3),fit_cdf.GetParameter(2)]  # for pol4 only
   #     pol_roots = np.roots(pol_coeff)
   #     pol_roots_diff = [x - x0_hist[j] for x in pol_roots]
    #    x0_CDFfit.append(pol_roots[min(xrange(len(pol_roots_diff)), key=pol_roots_diff.__getitem__)])

    #    x0_CDFfit.append(-1*fit_cdf.GetParameter(2)/3/fit_cdf.GetParameter(3))  #for pol3 only
        x0_CDFfit.append(fit_cdf.GetParameter(0))  #for erFunc

    c = TCanvas("canv","canv",1600,800)
    c.Divide(2,1)
    c.cd(1)
    frame = TH1F("hframe", "", n_bins, c_min, c_max)
    frame.SetStats(0)
    frame.GetXaxis().SetTitleOffset(0.91);
    frame.GetYaxis().SetTitle("Events")
    frame.GetXaxis().SetTitle("p_{T}^{gen}/p_{T}^{reco}")
    frame.GetYaxis().SetLabelSize(0.04)
    leg = ROOT.TLegend(0.12,0.75,0.6,0.9)
    leg.SetFillStyle(-1)
    leg.SetBorderSize(0)
    leg.SetTextFont(42)
    leg.SetTextSize(0.025)
    frame.GetYaxis().SetRangeUser(0.,max(max_list))
    frame.Draw()
    for j in range(len(X_region)):
        datahists[j].Draw("PEsame")
        leg.AddEntry(datahists[j],names[j] ,"PE")
    leg.Draw('same')

    c.cd(2)
    right,top   = gStyle.GetPadRightMargin(),gStyle.GetPadTopMargin()
    left,bottom = gStyle.GetPadLeftMargin(),gStyle.GetPadBottomMargin()
    ci = ROOT.TColor.GetColor("#ffffff")
 #   frame2 = TH1F("hframe2", "", n_bins, 0.9, 1.25)
    frame2 = TH1F("hframe2", "", n_bins, 0.7, 1.4)
    frame2.SetStats(0)
    frame2.GetXaxis().SetTitleOffset(0.91);
    frame2.GetYaxis().SetTitle("#tau - #tau_{1}")
    frame2.GetXaxis().SetTitle("Quantiles positions")
    frame2.GetYaxis().SetLabelSize(0.04)
    frame2.GetYaxis().SetRangeUser(-0.05,max(taus_fit)*1.1)
    frame2.Draw()
    paveText2 = ROOT.TPaveText(0.6,0.25,0.9,.4,"NDC")
    paveText2.SetTextFont(42)
    paveText2.SetTextSize(top*0.43)
    paveText2.SetFillStyle(-1)
    paveText2.SetBorderSize(0)
    for j in range(len(X_region)):
        graphs[j].Draw("PEsame")
        func[j].Draw("sameR")
        t = paveText2.AddText("x0 hist/fit : %.2f/%.2f"%(x0_hist[j],x0_CDFfit[j]))
        print "%.2f"%x0_CDFfit[j]
        t.SetTextColor(colors[j]);
    leg.Draw('same')

   # paveText = ROOT.TPaveText(0.7,0.85,0.9,.9,"NDC")
    paveText = ROOT.TPaveText(0.75,0.65,0.95,.9,"NDC")
    paveText.SetTextFont(42)
    paveText.SetTextColor(ROOT.kBlue)
    paveText.SetTextSize(top*0.43)
    paveText.SetFillStyle(-1)
    paveText.SetBorderSize(0)
    paveText.AddText("%s Fit"%pol)
    paveText.AddText("Quantiles : ")
    for x in taus :  paveText.AddText("%.2f"%x)
    paveText.Draw("same")
   
    paveText2.Draw("same")
    print x0_hist, x0_CDFfit
   
 
    line = ROOT.TLine(x0_hist[0],frame2.GetMinimum() ,x0_hist[0],frame2.GetMaximum())
    line.SetLineStyle(9)
    line.SetLineWidth(2)
    line.SetLineColor(ROOT.kRed+1)
    line.Draw("Lsame")

    c.SaveAs(utils.IO.plotFolder+"quantiles_"+str(outString)+str(pol)+'.png')

 

    
    
    
    
    
def plot_input_variables_reg(X_data,branch_names,log_names='',n_bins=30,outString=None,weights=None):

    ncolumns = X_data.size/len(X_data)

    for i in range(ncolumns):

        data = X_data[:,i]

        c_min=min(np.min(d) for d in np.concatenate([X_data[:,i]]))
        c_max=max(np.max(d) for d in np.concatenate([X_data[:,i]]))

    
        Histo_data = np.histogram(data,bins=30,range=(c_min,c_max),weights=weights)
        
        bin_edges = Histo_data[1]
        bin_centers = ( bin_edges[:-1] + bin_edges[1:]  ) /2.
        bin_widths = (bin_edges[1:] - bin_edges[:-1])

        # Lets get the min/max of the Histograms
        AllHistos= [Histo_data]
        h_max = max([histo[0].max() for histo in AllHistos])*1.2
        h_min = min([histo[0].min() for histo in AllHistos])

    
        if branch_names[i] in log_names or 'energyRing' in branch_names[i] : plt.yscale('log')
        ax1 = plt.subplot(111)

        ax1.bar(bin_centers-bin_widths/2.,Histo_data[0],facecolor='blue',linewidth=0,width=bin_widths,label='ttbar ',alpha=0.5)

        # Adjust the axis boundaries (just cosmetic)
        ax1.axis([c_min, c_max, h_min, h_max])
        plt.xlabel(branch_names[i].replace('noexpand:',''))
        plt.ylabel("Normalized Yields")


        if '/' in branch_names[i]: 
            branch_names[i] = branch_names[i].replace('/','_').replace(':','_').replace('(','').replace(')','').replace('+','_')
        
        plt.savefig(utils.IO.plotFolder+"variableDist"+str(branch_names[i])+"_"+str(outString)+".png")
    #    plt.savefig(utils.IO.plotFolder+"variableDist"+str(branch_names[i])+"_"+str(outString)+".pdf")


  #      plt.show()
        plt.clf()
    
    
    
def plot_input_variables(X_sig,X_bkg,branch_names,y_bkg=None,n_bins=30,outString=None,plotProcess=None):

    ncolumns = X_sig.size/len(X_sig)
    if plotProcess != None:
        X_bkg_2 = X_bkg[np.where(y_bkg==plotProcess),:][0] #this is to plot only one type of process
    else:
        X_bkg_2 = X_bkg

    for i in range(ncolumns):

        sig = X_sig[:,i]
        bkg = X_bkg_2[:,i]

        c_min=min(np.min(d) for d in np.concatenate([X_sig[:,i],X_bkg_2[:,i]]))
        c_max=max(np.max(d) for d in np.concatenate([X_sig[:,i],X_bkg_2[:,i]]))

        #trick to normalize
        weights_sig = np.ones_like(sig)/float(len(sig)) 
        weights_bkg = np.ones_like(bkg)/float(len(bkg)) 

        Histo_S = np.histogram(sig,bins=30,range=(c_min,c_max),weights=weights_sig)
        Histo_B = np.histogram(bkg,bins=30,range=(c_min,c_max),weights=weights_bkg)
        
        bin_edges = Histo_B[1]
        bin_centers = ( bin_edges[:-1] + bin_edges[1:]  ) /2.
        bin_widths = (bin_edges[1:] - bin_edges[:-1])

        # Lets get the min/max of the Histograms
        AllHistos= [Histo_S,Histo_B]
        h_max = max([histo[0].max() for histo in AllHistos])*1.2
        h_min = min([histo[0].min() for histo in AllHistos])

    

        ax1 = plt.subplot(111)

        ax1.bar(bin_centers-bin_widths/2.,Histo_S[0],facecolor='blue',linewidth=0,width=bin_widths,label='S ',alpha=0.5)
        ax1.bar(bin_centers-bin_widths/2.,Histo_B[0],facecolor='red',linewidth=0,width=bin_widths,label='B ',alpha=0.5)

        # Adjust the axis boundaries (just cosmetic)
        ax1.axis([c_min, c_max, h_min, h_max])
        plt.xlabel(branch_names[i].replace('noexpand:',''))
        plt.ylabel("Normalized Yields")


        plt.savefig(utils.IO.plotFolder+"variableDist"+str(i)+"_"+str(outString)+".png")
        plt.savefig(utils.IO.plotFolder+"variableDist"+str(i)+"_"+str(outString)+".pdf")


        plt.show()


def plot_roc_curve(x,y,clf,outString=None):
    decisions = clf.predict_proba(x)[:,clf.n_classes_-1]
    # Compute ROC curve and area under the curve
    fpr, tpr, thresholds = roc_curve(y, decisions)
    roc_auc = auc(fpr, tpr)
    
    plt.plot(fpr, tpr, lw=1, label='ROC (area = %0.2f)'%(roc_auc))
    
    plt.xlim([-0.05, 1.05])
    plt.ylim([-0.05, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('ROC Curve')
    plt.legend(loc="lower right")
    plt.grid()

    plt.savefig(utils.IO.plotFolder+"rocCurve"+"_"+str(outString)+".png")
    plt.savefig(utils.IO.plotFolder+"rocCurve"+"_"+str(outString)+".pdf")



def plot_roc_curve_multiclass(x,y,clf,classesSchema=[-2,-1,1],classNumber=2,outString=None):#roc curve signal vs all bkg, each one normalized to one
    y=label_binarize(y,classes=classesSchema)
    decisions = clf.predict_proba(x)[:,classNumber]
    # Compute ROC curve and area under the curve
    fpr, tpr, thresholds = roc_curve(y[:,classNumber].ravel(), decisions.ravel())
    roc_auc = auc(fpr, tpr)
    plt.plot(fpr, tpr, lw=1, label='ROC (area = %0.2f)'%(roc_auc))
    
    plt.xlim([-0.05, 1.05])
    plt.ylim([-0.05, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('ROC Curve')
    plt.legend(loc="lower right")
    plt.grid()

    plt.savefig(utils.IO.plotFolder+"rocCurve"+"_"+str(outString)+".png")
    plt.savefig(utils.IO.plotFolder+"rocCurve"+"_"+str(outString)+".pdf")
    return fpr,tpr

#roc curve signal vs one bkg
def plot_roc_curve_multiclass_singleBkg(x,y,clf,backgroundClassOutput,signalClassOutput=1,outString=None,weights=None):
    x_bkg=np.asarray(x)[np.where(np.asarray(y)==backgroundClassOutput)]
    x_sig=np.asarray(x)[np.where(np.asarray(y)==signalClassOutput)]
    x_tot=np.concatenate((x_bkg,x_sig))

    if weights != None:
        w_bkg = np.asarray(weights)[np.where(np.asarray(y)==backgroundClassOutput)]
        w_sig=np.asarray(weights)[np.where(np.asarray(y)==signalClassOutput)]
        w_tot=np.concatenate((w_bkg,w_sig))
        
    y_bkg=np.asarray(y)[np.where(np.asarray(y)==backgroundClassOutput)]
    y_sig=np.asarray(y)[np.where(np.asarray(y)==signalClassOutput)]
    y_tot=np.concatenate((y_bkg,y_sig))
    
    decisions = clf.predict_proba(x_tot)[:,clf.n_classes_-1]
    # Compute ROC curve and area under the curve
    if weights == None:
        fpr, tpr, thresholds = roc_curve(y_tot.ravel(), decisions,signalClassOutput)
    else:
        fpr, tpr, thresholds = roc_curve(y_tot.ravel(), decisions,signalClassOutput,sample_weight=w_tot.ravel())
        
    roc_auc = auc(fpr, tpr,reorder=True)
        
    plt.plot(fpr, tpr, lw=1, label='ROC (area = %0.2f)'%(roc_auc))
    
    plt.xlim([-0.05, 1.05])
    plt.ylim([-0.05, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('ROC Curve')
    plt.legend(loc="lower right")
    plt.grid()
    return fpr,tpr



 
def print_roc_report(fpr,tpr,step=0.05):
     print "======== ROC report ========"
     for i in range(int(1/step)):
         print i
         if fpr[np.where((tpr>step*i) & (tpr<step*i+0.005))].size>0:
             print "True positive rate: "+str(step*i)
             print "False positive rate:"+str(fpr[np.where((tpr>step*i) & (tpr<step*i+0.005))][0])
     print "============================"



def print_roc_report(fpr,tpr,step=0.05):
    print "======== ROC report ========"
    for i in range(int(1/step)):
        print i
        index = plotting.bisection(tpr,step*i)
        print "True positive rate: "+str(step*i)
        print "False positive rate:"+str(fpr[index])
        

def bisection(array,value):#be careful, works with sorted arrays
    '''Given an ``array`` , and given a ``value`` , returns an index j such that ``value`` is between array[j]
    and array[j+1]. ``array`` must be monotonic increasing. j=-1 or j=len(array) is returned
    to indicate that ``value`` is out of range below and above respectively.'''
    n = len(array)
    if (value < array[0]):
        return -1
    elif (value > array[n-1]):
        return n
    jl = 0# Initialize lower
    ju = n-1# and upper limits.
    while (ju-jl > 1):# If we are not yet done,
        jm=(ju+jl) >> 1# compute a midpoint with a bitshift
        if (value >= array[jm]):
            jl=jm# and replace either the lower limit
        else:
            ju=jm# or the upper limit, as appropriate.
        # Repeat until the test condition is satisfied.
    if (value == array[0]):# edge cases at bottom
        return 0
    elif (value == array[n-1]):# and top
        return n-1
    else:
        return jl
    
    
    
    
def plot_mean_fwhm(y,regions,what,outString=None,labels=['1','2']):
    styles=['r^','bs','go','xk','xm','xy','hc']
    for i,s in enumerate(styles):
       y_prime = [y[k][i] for k in range(len(y))]
       plt.plot(regions,y_prime,s, label=labels[i])

    plt.xlabel(what[1])
    plt.ylabel(what[0])
    plt.legend(loc="lower right",numpoints=1)
    x_text,y_text = float(regions[len(regions)-1])-100,float(y_prime[len(y_prime)-1])+0.05
    x_text0,y_text0 = float(regions[0])-100,float(y_prime[0])+0.05
    if 'p_T' in what[1] : 
        plt.annotate('low stat', xy=(regions[len(regions)-1],y_prime[len(y_prime)-1]), xytext=(x_text,y_text))
        plt.annotate('all pT', xy=(regions[0],y_prime[0]), xytext=(x_text0,y_text0))
            
    axes = plt.gca()
    if 'mean' in what[0] :axes.set_ylim([0.8,1.1])
    if 'FWHM' in what[0] :axes.set_ylim([-0.1,0.45])
    plt.grid()
   # plt.show()
    plt.savefig(utils.IO.plotFolder+what[0].replace(' ','_')+"_"+what[1]+"_"+str(outString)+".png")
    plt.clf()


def plot_response(histos,profiles,profiles_noReg,profiles_Cat,style=False,outString=None):
    if style==True:
        gROOT.SetBatch(True)
        gROOT.ProcessLineSync(".x /mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/scripts/setTDRStyle.C")
        gROOT.ForceStyle()
        gStyle.SetPadTopMargin(0.06)
        gStyle.SetPadRightMargin(0.04)
        gStyle.SetPadLeftMargin(0.15)
        
    c = ROOT.TCanvas("c","c",900,900)
    c.cd()
    histos.Draw("HISTBOX")
    colors=[ROOT.kRed,ROOT.kOrange-3,ROOT.kAzure+10]
    profiles.SetLineColor(colors[0])
    profiles.SetLineWidth(3)
    profiles.SetMarkerColor(colors[0])
    profiles.SetStats(0)
    profiles.Draw("PLsame")
    profiles_noReg.SetLineColor(colors[1])
    profiles_noReg.SetLineWidth(3)
    profiles_noReg.SetMarkerColor(colors[1])
    profiles_noReg.SetStats(0)
    profiles_noReg.Draw("PLsame")
    profiles_Cat.SetLineColor(colors[2])
    profiles_Cat.SetLineWidth(3)
    profiles_Cat.SetMarkerColor(colors[2])
    profiles_Cat.SetStats(0)
    profiles_Cat.Draw("PLsame")
    line = ROOT.TLine(histos.GetXaxis().GetBinCenter(0),1,histos.GetXaxis().GetBinCenter(histos.GetXaxis().GetNbins()),1)
    line.SetLineStyle(9)
    line.SetLineWidth(3)
    line.SetLineColor(ROOT.kGreen+1)
    line.Draw("Lsame")
    leg = ROOT.TLegend(0.72,0.75,0.95,0.9)
    leg.SetFillStyle(-1)
    leg.SetBorderSize(0)
    leg.SetTextFont(42)
    leg.SetTextSize(0.03)
    leg.AddEntry(profiles,"XGboost","PL")
    leg.AddEntry(profiles_noReg,"no regression","PL")
    leg.AddEntry(profiles_Cat,"Caterina","PL")
    leg.Draw("same")
    
    c.SaveAs(utils.IO.plotFolder+"Response_"+histos.GetTitle()+'_'+str(outString)+'.png')



    
def draw_overflow(h,factor=1):
    ## This function return a hist with overflow bin
    name  = h.GetName()
    title = h.GetTitle()
    nx    = h.GetNbinsX()+1
    x1 = h.GetBinLowEdge(1)
    bw = h.GetBinWidth(nx)*factor
    x2 = h.GetBinLowEdge(nx)+bw
    ## Book a temporary histogram having ab extra bin for overflows
    htmp = TH1F('new','new', 1, x2-bw, x2)
    ## Fill the new hitogram including the extra bin for overflows
    htmp.Fill(htmp.GetBinCenter(1), h.GetBinContent(nx)/factor)
    return htmp

   



def plot_feature_importance(clf,features,end='',path='/mnt/t3nfs01/data01/shome/nchernya/HHbbgg_ETH_devel/bregression/output_files/'): 
	features_importance =  optimization.feature_importances_(clf)
	features_dict = {features[i]:features_importance[i] for i in range(0,len(features)) }
	sorted_features_values = sorted( features_dict.values(),reverse=True)
	sorted_features = [key for key,value in sorted(features_dict.items() ,key=lambda x : x[1], reverse=True)]

	np.save(path+'out_features_values'+end,sorted_features_values)
	np.save(path+'out_features_names'+end,sorted_features)

	y_pos = np.arange(0,len(features)*2,2)  # the x locations for the groups
	width = 1.2       # the width of the bars
	fig,ax = plt.subplots()
	ax.barh(y_pos,sorted_features_values,width,color='green',align='center')
	for x, y in zip(sorted_features_values, y_pos):
 	  ax.text(x + 0.01, y+0.1, np.round(x,3), va='center', fontsize=6,fontweight='bold',color='blue')
	fig.subplots_adjust(left=0.2) 
	ax.set_yticks(y_pos)
	ax.set_yticklabels(sorted_features,rotation=0,fontsize=7)
	ax.invert_yaxis() 
	ax.set_xlabel('F-scores')
	ax.set_xlim(0,sorted_features_values[0]*1.1)
	ax.set_title("Features importance")
	plt.grid()
	plt.savefig(utils.IO.plotFolder+"importanceBar_"+end+".pdf")
	plt.clf()


def plot_hist(hists,saveName,log=False,labels=None):
	colors=['blue','green','red']
	for i in range(len(hists)):
		if labels==None : n, bins, patches = plt.hist(hists[i], 100,color='green', alpha=0.75)
		else : n, bins, patches = plt.hist(hists[i], 100,color=colors[i], alpha=0.5,label=labels[i])
	plt.xlabel('MPVS')
	plt.ylabel('Events')
	if log : plt.yscale('log')
	plt.grid(True)
	if labels!=None : plt.legend(loc='upper right')
	plt.savefig(utils.IO.plotFolder+saveName+".png")
	plt.clf()

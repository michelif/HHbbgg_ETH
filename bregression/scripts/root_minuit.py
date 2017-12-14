#   Example of a fitting program
#   ============================
#
#   The fitting function fcn is a simple chisquare function
#   The data consists of 5 data points (arrays x,y,z) + the errors in errorsz
#   More details on the various functions or parameters for these functions
#   can be obtained in an interactive ROOT session with:
#    Root > TMinuit *minuit = new TMinuit(10);
#    Root > minuit->mnhelp("*",0)  to see the list of possible keywords
#    Root > minuit->mnhelp("SET",0) explains most parameters


from ROOT import *
from array import array
import numpy as np

Error = 0
errorz = np.array( 5*[0.01] )

#x = array( 'f', ( 1.5751, 1.5825,  1.6069,  1.6339,   1.6706  ) )
#y = array( 'f', ( 1.0642, 0.97685, 1.13168, 1.128654, 1.44016 ) )

global z
z = np.array( 5*[1] )
global x
x = np.array( 5*[1] )
global y 
y= np.array( 5*[1] )
ncount = 0
arglist = np.array( 10*[0.] )

parlist = np.array( 10*[1])

##______________________________________________________________________________
def changeme(new_val):
    global z
    z = new_val

def testfit():

#   gROOT.LoadMacro( "GimeDouble.C+" )

   x = np.array([ 1.5751, 1.5825,  1.6069,  1.6339,   1.6706  ] )
   y = np.array([ 1.0642, 0.97685, 1.13168, 1.128654, 1.44016 ] )
   z2 =  [ np.array([1., 0.96, 0.89, 0.85, 0.78]),np.array([3., 2.96, 2.89, 2.85, 2.78 ]),np.array( [5., 4.96, 4.89, 4.85, 4.78 ]) ]
  


   gMinuit = TMinuit(5)
   gMinuit.SetFCN( fcn )

   arglist = np.array( 10*[0.] )
   ierflg = 1982

   arglist[0] = 1
   gMinuit.mnexcm( "SET ERR", arglist, 1, Long(ierflg) )

 # Set starting values and step sizes for parameters
   vstart = np.array( [ 3,  1,  0.1,  0.01  ] )
   step   = np.array(  [ 0.1, 0.1, 0.01, 0.001 ] )
   gMinuit.mnparm( 0, "a1", vstart[0], step[0], 0, 0, Long(ierflg) )
   gMinuit.mnparm( 1, "a2", vstart[1], step[1], 0, 0, Long(ierflg) )
   gMinuit.mnparm( 2, "a3", vstart[2], step[2], 0, 0, Long(ierflg) )
   gMinuit.mnparm( 3, "a4", vstart[3], step[3], 0, 0, Long(ierflg) )

 # Now ready for minimization step
   arglist[0] = 500
   arglist[1] = 1.
   for num in range(3):
     changeme(z2[num])

     print 'z = ', z
     gMinuit.mnexcm( "MIGRAD", arglist, 2, Long(ierflg) )
     print 'erflag =', ierflg

   # Print results
     amin, edm, errdef = 0.18, 0.19, 0.20
     nvpar, nparx, icstat = 1983, 1984, 1985
  #   gMinuit.mnstat( Double(amin), Double(edm), Double(errdef), Long(nvpar), Long(nparx), Long(icstat) )
   #  gMinuit.mnprin( 3, amin )
     fParamVal = Double(0.)
     fParamErr = Double(0.)
     gMinuit.GetParameter(0,fParamVal,fParamErr)
     print "a1=",fParamVal, fParamErr
     print 'results num = ', num


##______________________________________________________________________________
def fcn( npar, gin, f, par, iflag ):
   global ncount
   nbins = 5

 # calculate chisquare
   chisq, delta = 0., 0.
   print 'from func ',x,y,z
   for i in range(nbins):
      delta  = (z[i]-func(x[i],y[i],par))/errorz[i]
      chisq += delta*delta

   f[0] = chisq
   ncount += 1

def func( x, y, par ):
   value = ( (par[0]*par[0])/(x*x)-1)/ ( par[1]+par[2]*y-par[3]*y*y)
   return value


##______________________________________________________________________________
if __name__ == '__main__':
   testfit()

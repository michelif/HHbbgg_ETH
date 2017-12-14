import numpy as np
import matplotlib.pyplot as plt

num_samples = 4
num_lines = 2
#x = np.random.randint(0,10,num_samples)
x = np.array([1,2,3,4])
y_list = [np.array([1,1]), np.array([4,8]), np.array([9,27]),np.array([16,64])] 
y=np.array(y_list)
#y = np.random.randint(0,10,(num_samples, num_lines))
print x
print y
z = np.polyfit(x,y,deg=3)
print z
f0 = np.poly1d( z[:,0] )
f1 = np.poly1d( z[:,1] )
print f0, f1

xp = np.linspace(-1, 6, 100)
plt.plot(x, y, '.')
plt.plot(xp, f0(xp), label="slope %.2f"%z[0,0])
plt.plot(xp, f1(xp), label="slope %.2f"%z[1,0])
plt.legend(loc='upper right')
plt.show()
#xx = np.random.randint(0,10,num_samples*10)

#inputs = np.array([np.power(xx,d) for d in range(len(fit))])
#res2 = fit.T.dot(inputs)

#print res2.shape

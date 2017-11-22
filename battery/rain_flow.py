# -*- coding: utf-8 -*-
"""
Created on Wed May 08 16:29:28 2013

@author: irazdt
"""

import numpy as np
import scipy.signal as dsp
from numba import jit


    
    

def inRange(num,Y):
    '''Checks if num is in the range Y. Y should have 2 elements, the lower 
    and upper bounds'''
    if np.shape(Y) != (2,):
        raise ValueError
    if Y[0] < Y[1]:
        return (Y[0] <= num and num <= Y[1])
    else:
        return (Y[1] <= num and num <= Y[0])

def rInd(num,rList):
    '''returns the index of rList corresponding to the range that num falls in'''
    def resHelper(num,rList,acc):
        '''Recursive Helper Function'''
        if num < 0:
            raise ValueError("num < 0")
        elif num <= rList[0]:
            return acc
        else:
            return resHelper(num,rList[1:],acc+1)
    return resHelper(num,rList,0)
        
    

def rainflow(dataIn,rList):
    '''- dataIn is 1D array of data.
       - rList is a list of upper edges of the ranges to sort cycles into,
         eg: [1,2,3,...], [10,100,1000,...] etc. The ranges' edges can be
         arbitrary but must be in ascending order.'''
         
         
    def toMinMax(data):
        '''takes 1D array of data and coverts to a sequence of local mins and maxs'''
        mn = dsp.argrelmin(data,order=1)[0][:]
        mx = dsp.argrelmax(data,order=1)[0][:]
        return data[np.sort(np.concatenate((mn,mx)))]  
    
    data = toMinMax(dataIn)
     
    results = np.zeros((len(rList),2))
    results[:,0] = rList
   
    buff = []
    ii = 0
    while True:
        #Step 2
        if len(buff) < 3:
            #Step 1
            if ii > len(data)-1:
                break
            else:
                buff.append(data[ii])
                ii = ii+1
                continue
        
        X = [buff[-1],buff[-2]] 
        Xr = abs(X[0]-X[1]) #range of X
        Y = [buff[-2],buff[-3]]
        Yr = abs(Y[0]-Y[1]) #range of Y
        S = buff[0]
        
        #Step 3
        if Xr < Yr:
            #Step 1
            if ii > len(data)-1:
                break
            else:
                buff.append(data[ii])
                ii = ii+1
                continue
        elif Xr >= Yr:
            #Step 4
            if inRange(S,Y):
                #Step 5
                index = rInd(Yr,results[:,0])
#                print (Y,Yr,results[index,0])
#                print '==================='
                results[index,1] = results[index,1] + 0.5
                del buff[-3]
            else:
                index = rInd(Yr,results[:,0])
#                print (Y,Yr,results[index,0])
#                print '==================='
                results[index,1] = results[index,1] + 1
                del buff[-3:-1] #remove indices -2 and -3 from buffer, i.e. Y
        else:
            raise ValueError
    dBuff = abs(np.diff(buff))
    for d in dBuff:
        index = rInd(d,results[:,0])
        results[index,1] = results[index,1] + 0.5
    return results


def rainflow2(dataIn,rList):
    '''- dataIn is 1D array of data.
       - rList is a list of upper edges of the ranges to sort cycles into,
         eg: [1,2,3,...], [10,100,1000,...] etc. The ranges' edges can be
         arbitrary but must be in ascending order.'''
         
    def inRange(num,Y):
        '''Checks if num is in the range Y. Y should have 2 elements, the lower 
        and upper bounds'''
        if np.shape(Y) != (2,):
            raise ValueError
        if Y[0] < Y[1]:
            return (Y[0] <= num and num <= Y[1])
        else:
            return (Y[1] <= num and num <= Y[0])
    
    def rInd(num,rList):
        '''returns the index of rList corresponding to the range that num falls in'''
        def resHelper(num,rList,acc):
            '''Recursive Helper Function'''
            if num < 0:
                raise ValueError("num < 0")
            elif num <= rList[0]:
                return acc
            else:
                return resHelper(num,rList[1:],acc+1)
        return resHelper(num,rList,0)
    
    def toMinMax(data):
        '''takes 1D array of data and coverts to a sequence of local mins and maxs'''
        mn = dsp.argrelmin(data,order=1)[0][:]
        mx = dsp.argrelmax(data,order=1)[0][:]
        return data[np.sort(np.concatenate((mn,mx)))]  
    
    data = toMinMax(dataIn)
     
    results = np.zeros((len(rList),2))
    results[:,0] = rList
   
    buff = []
    ii = 0
    while True:
        #Step 2
        if len(buff) < 3:
            #Step 1
            if ii > len(data)-1:
                break
            else:
                buff.append(data[ii])
                ii = ii+1
                continue
        
        X = [buff[-1],buff[-2]] 
        Xr = abs(X[0]-X[1]) #range of X
        Y = [buff[-2],buff[-3]]
        Yr = abs(Y[0]-Y[1]) #range of Y
        S = buff[0]
        
        #Step 3
        if Xr < Yr:
            #Step 1
            if ii > len(data)-1:
                break
            else:
                buff.append(data[ii])
                ii = ii+1
                continue
        elif Xr >= Yr:
            #Step 4
            if inRange(S,Y):
                #Step 5
                index = rInd(Yr,results[:,0])
#                print (Y,Yr,results[index,0])
#                print '==================='
                results[index,1] = results[index,1] + 0.5
                del buff[-3]
            else:
                index = rInd(Yr,results[:,0])
#                print (Y,Yr,results[index,0])
#                print '==================='
                results[index,1] = results[index,1] + 1
                del buff[-3:-1] #remove indices -2 and -3 from buffer, i.e. Y
        else:
            raise ValueError
    dBuff = abs(np.diff(buff))
    for d in dBuff:
        index = rInd(d,results[:,0])
        results[index,1] = results[index,1] + 0.5
    return results
    
if __name__ == '__main__':
    
    t = np.arange(0.0,60.0,0.01)


    omega_1 = 5.0
    omega_2 = 1.0
    omega_3 = 0.5

    v_1 = 0.0* np.sin(omega_1*t) 
    v_2 = 7.0* np.sin(omega_2*t)+2 
    v_3 = 10.0*np.sin(omega_3*t) 

    v_txt = np.loadtxt('../data/saft_intensium/saft_intensium_cycles_profile.txt', delimiter=',')
    v = v_1 + v_2 + v_3
    v_orig = v_txt[:,1]
    t_orig = v_txt[:,0]
    
    import matplotlib.pyplot as plt
    from scipy.interpolate import UnivariateSpline
    import cProfile

    spl = UnivariateSpline(t_orig, v_orig)
    xs = np.linspace(0, 760, 500)
    
    v = spl(xs)
    
    dataIn = v
    rList = np.array([0.1,1.0,5.0,10.0,100.0])
    rList = np.arange(0.0,100.0,2.0)
    
    res = rainflow2(dataIn,rList)
    
    print(res)
    
    import matplotlib.pyplot as plt             
       
         
              
    fig, (ax0,ax1) = plt.subplots(nrows=2)   # creates a figure with one axe
    
    ax0.plot(t_orig,v_orig)
    ax0.plot(xs, spl(xs), 'g', lw=1)
    #ax1.plot(t,v_1)
    #ax1.plot(t,v_2)
    #ax1.plot(t,v_3)
    
    fig.show()
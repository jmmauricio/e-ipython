# -*- coding: utf-8 -*-
"""
Created on Sat Jun 25 12:59:49 2016

@author: jmmauricio
"""

import numpy as np
import matplotlib.pyplot as plt
import factor

fac = factor.formulation()
fac.p_eval()
fac.p
E = fac.E
E

fac.a2x(np.zeros((3,1)))

E = fac.E
C = fac.C
f = fac.f
f_inv = fac.f_inv
F_inv = fac.F_inv
p = fac.p
max_iter = 200

x_0 = np.array([np.arcsin(fac.P_m*fac.X1d/(fac.E_p*fac.V_h)),
                0.0,
                fac.P_m]).reshape(3,1)
a_0 = x_0

x = x_0
delta = x[0,0]
Domega = x[1,0]
p_e = x[2,0]

p = np.array([[delta],
              [Domega + fac.Dt*fac.P_m/(2*fac.H)],
              [0]])
fac.p = p                  
                  
a_k = a_0
t_list = [-fac.Dt.real]
delta_list = [x_0[0,0].real]
Domega_list = [x_0[1,0].real]
p_e_list = [x_0[2,0].real]

Dt = fac.Dt
t_end = 10.0
for it_t  in range(int(t_end/Dt)): 
#for it_t  in range(1): 
    t = fac.Dt * it_t 
    E_p = 1.0
    if t>1.0:
        E_p = 0
    if t>1.1:
        E_p = 1.0     

    fac.E_p = E_p
    
    fac.E_eval()
    E =  fac.E

    for it in range(max_iter):

        # step 0
        y_k = f_inv(np.matmul(C,a_k))

        # step 1
        lam = np.linalg.solve(np.matmul(E,E.T), fac.p-np.matmul(E,y_k))
        y_ = y_k  +  np.matmul(E.T,lam)
        u_ = f(y_)

        # step 2
        fac.F_inv_eval(u_)
        H_ = np.matmul(E,np.matmul(fac.F_inv,C))

        a_0 = a_k
        a_k = np.linalg.solve(H_, np.matmul(E,np.matmul(fac.F_inv,f(y_))))

        epsilon = np.linalg.norm(a_k-a_0, np.inf)

        if epsilon < 1e-8:
            #print('Convergence reached after {:d} iterations'.format(it+1))      
            a = a_k        


            break

        if it>=max_iter-1:
            print('Max. iteration number reached')
            a = a_k
            print(a)
    
    x = fac.a2x(a)
    delta = x[0,0]
    Domega = x[1,0]
    p_e = x[2,0]
    
    p = np.array([[delta],
                  [Domega + fac.Dt*fac.P_m/(2*fac.H)],
                  [0]])

    fac.p=p
    t_list += [t]
    delta_list += [delta.real]
    Domega_list += [Domega.real]
    p_e_list += [p_e.real]

time = np.array(t_list)
delta  = np.array(delta_list)
Domega  = np.array(Domega_list)
p_e  = np.array(p_e_list)

fig, (ax_delta,ax_w,ax_p) = plt.subplots(nrows=3, figsize=(7.6,10))

ax_delta.plot(time,delta, 'b') 
ax_w.plot(time,Domega, 'b') 
ax_p.plot(time,p_e, 'b') 


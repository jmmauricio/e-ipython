
Problema 1 IyME-GIE Diciembre 2014
==================================

Circuito equivalente
--------------------



Circuito equivalente (variables python)
---------------------------------------



Deslizamiento porcentual
~~~~~~~~~~~~~~~~~~~~~~~~

Con la frecuencia:

.. math::  \sf f = 50 \; H_z

Y los pares de polo se puede calcular la velocidad síncrona:

.. math::  \sf \Omega_1 = \frac{2 \pi f}{N_{pp}} [=] \frac{r}{s}

La velocidad de giro del eje se puede obtener a partir de la velocidad
dada en revoluciones por minuto:

.. math::  \sf \Omega =  \frac{n \cdot 2 \pi}{60} [=] \frac{r}{s} 

Deslizamiento:

.. math::  \sf s = \frac{\Omega_1 - \Omega}{\Omega_1}

Deslizamiento porcentual:

.. math::  \sf s_{\%} = s \cdot 100

.. code:: python

    import numpy as np
    N_pp = 2
    f = 50.0
    n = 1470.0
    
    Omega_1 = 2.0*np.pi*50.0/N_pp
    Omega = 2.0*np.pi*n/60.0
    s = (Omega_1 - Omega)/(Omega_1)
    s_porcentual = s*100.0
.. code:: python

    print('Deslizamiento porcentual: {:2.2f} %'.format(s_porcentual))

.. parsed-literal::

    Deslizamiento porcentual: 2.00 %


Par útil a 1470 rpm
~~~~~~~~~~~~~~~~~~~

Con los parametros y el deslizamiento calculado se obtienen las
impedancias del estator y el rotor:

.. math::  \sf \underline Z_s = R_s + j X_s 

.. math::  \sf \underline Z_r = \frac{R_r}{s}  + jX_r

La impedancia equivalente de la rama de magnetización:

.. math::  \sf  \underline Z_m = \frac{R_f \cdot jX_\mu}{R_f + jX_\mu} 

Con la impedancia rotorica y la de la rama de magnetización se puede
obtener una impedancia equivalente magnetización-rotor:

.. math::  \sf  \underline Z_{mr} = \frac{\underline Z_m  \underline Z_r}{ \underline Z_m +  \underline Z_r}

La impedancia equivalente de todo el circuito se obtiene sumando la
impedancia estatorica y la impedancia equivalente rotor-estator:

.. math::  \sf  \underline Z_{eq} = \underline Z_s +  \underline Z_{mr} 

.. code:: python

    R_s, X_s = 0.17, 0.35   # Ω 
    R_f, X_mu = 347.0, 17.3 # Ω
    R_r, X_r = 0.12, 1.06   # Ω    
    
    Z_s = R_s + 1j*X_s
    Z_m = (R_f * 1j*X_mu) / (R_f + 1j*X_mu)
    Z_r = R_r/s + 1j*X_r
    
    Z_mr = Z_m*Z_r/(Z_m + Z_r)
    Z_eq = Z_s + Z_mr
.. math::  \sf  \underline U_s =\frac{400}{\sqrt 3} \angle{ 0^\circ}  V

.. math::  \sf  \underline I_s = \frac{ \underline U_s}{ \underline Z_{eq}}

Corriente estatorica a 1470 rpm
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: python

    U_s = 400.0/np.sqrt(3.0)
    I_s = U_s/Z_eq
.. code:: python

    print('La corriente  = {:2.2f} A'.format(np.abs(I_s)))

.. parsed-literal::

    La corriente  = 40.51 A


.. math::  \sf  \underline E =  \underline U_s -  \underline Z_s  \underline I_s

.. math::  \sf  \underline I_r = \frac{ \underline E}{ \underline Z_r}

.. code:: python

    E = U_s - Z_s*I_s
    I_r = E/Z_r
.. code:: python

    ### Par útil a 1470 rpm 
.. math::  \sf P_{mi} = 3 R_r  \frac{\left( 1-s \right)}  {s} | \underline I_r|^2

.. math::  \sf P_u = P_{mi} 

.. math::  \sf T_u = \frac{P_u}{\Omega}

.. code:: python

    P_mi = 3.0*R_r*(1.0-s)/s*(np.abs(I_r)**2)
    P_u = P_mi # en el caso en el que las pérdidas fueron incluidas en R_f
    
    T_u = P_u/Omega

.. code:: python

    print('El par T_u = {:2.2f} N.m'.format(par(Omega)))

.. parsed-literal::

    El par T_u = 146.78 N.m


Corriente de arranque (s=1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

En el arranque el deslizamiento es:

.. math::  \sf s = 1

Con lo que se obtiene la siguiente impedancia rotórica:

.. math::  \sf \underline Z_r = R_r  + jX_r

La impedancia equivalente de la rama de magnetización:

.. math::  \sf  \underline Z_m = \frac{R_f \cdot jX_\mu}{R_f + jX_\mu} 

Con la impedancia rotorica y la de la rama de magnetización se puede
obtener una impedancia equivalente magnetización-rotor:

.. math::  \sf  \underline Z_{mr} = \frac{\underline Z_m  \underline Z_r}{ \underline Z_m +  \underline Z_r}

La impedancia equivalente de todo el circuito se obtiene sumando la
impedancia estatorica y la impedancia equivalente rotor-estator:

.. math::  \sf  \underline Z_{eq} = \underline Z_s +  \underline Z_{mr} 

.. code:: python

    Z_s = R_s + 1j*X_s
    Z_m = (R_f * 1j*X_mu) / (R_f + 1j*X_mu)
    Z_r = R_r + 1j*X_r
    
    Z_mr = Z_m*Z_r/(Z_m + Z_r)
    Z_eq = Z_s + Z_mr
    
    U_s = 400.0/np.sqrt(3.0)
    I_s = U_s/Z_eq
    

.. code:: python

    print('La corriente en el arranque = {:2.2f} A'.format(np.abs(I_s)))

.. parsed-literal::

    La corriente en el arranque = 167.65 A


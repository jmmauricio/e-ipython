# -*- coding: utf-8 -*-
"""
Created on Mon Jun 27 23:29:11 2016

@author: jmmauricio
"""

import sympy as sym

y_1,y_2,y_3,alpha_ij,theta_ij = sym.symbols('y_1,y_2,y_3,alpha_ij,theta_ij')
u_2,u_3 = sym.symbols('u_2,u_3')

eq1 = u_2 - sym.log(y_2**2 + y_3**2)
eq2 = u_3 - sym.sin(sym.atan(y_2/y_3))

sol = sym.solve([eq1,eq2],y_2,y_3)



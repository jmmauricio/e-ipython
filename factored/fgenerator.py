# -*- coding: utf-8 -*-
"""
Created on Sat Jun 25 13:23:38 2016

@author: jmmauricio
"""

import sympy as sym 
import numpy as np
from sympy.parsing.sympy_parser import parse_expr

def fgen(d):
    sqrt = sym.sqrt
    arcsin = sym.asin
    arccos = sym.acos
    sin = sym.sin
    cos = sym.cos
    exp = sym.exp
    ln = sym.ln
    
    
   
    ph = d['ph']
    uyxa = d['uyxa']
    params = d['params']
    m=len(uyxa)
    xa = d['xa']
    x_list = [x['x'] for x in d['xa']]
    
    
    n = len(x_list)
    
    x_sym_list=[]
    for item in x_list:
        to_exec = "{:s} = sym.Symbol('{:s}')".format(item,item)
        exec(to_exec)
        to_exec = "x_sym_list +=[{:s}]".format(item)
        exec(to_exec)
    x = sym.Matrix(x_sym_list).reshape(n,1)
    
   
    u_list = []
    for it in range(m):
        exec("u_{:d} = sym.Symbol('u_{:d}')".format(it+1,it+1))
        exec('u_list += [u_{:d}]'.format(it+1))
    u = sym.Matrix(u_list).reshape(m,1)
    
    y_list = []
    for it in range(m):
        exec("y_{:d} = sym.Symbol('y_{:d}')".format(it+1,it+1))
        exec('y_list += [y_{:d}]'.format(it+1))
    y = sym.Matrix(y_list).reshape(m,1)

    
    a_list = []
    for it in range(n):
        exec("a_{:d} = sym.Symbol('a_{:d}')".format(it+1,it+1))
        exec('a_list += [a_{:d}]'.format(it+1))
    a = sym.Matrix(a_list).reshape(n,1)
    
    
    h_list = []
    for item in ph:
        h_list += [parse_expr(item['h'])]
        
    
    h = sym.Matrix(h_list).reshape(n,1)    
    
    
    H_x_sym = h.jacobian(x)

    
    hy_list = []
    for item in ph:
        hy_list += [parse_expr(item['hy'])]
    hy = sym.Matrix(hy_list).reshape(n,1)   
    
    E_sym = hy.jacobian(y)
    
    p_list = []
    for item in ph:
        p_list += [parse_expr(item['p'])]
    p = sym.Matrix(p_list).reshape(n,1)
    
    ay_list = []
    for item in uyxa:
        ay_list += [item['u(a)']]
    ay = sym.Matrix(ay_list).reshape(m,1)   
    
    C_sym = ay.jacobian(a)
    
    
    # u = f(y)
    f_list = [] 
    for item in uyxa:
        f_list += [parse_expr(item['u(y)'])]
    f = sym.Matrix(f_list).reshape(m,1)    
    
    
    # y = f_inv(u)
    f_inv_list = [] 
    for item in uyxa:
        f_inv_list += [parse_expr(item['y(u)'])]
    f_inv = sym.Matrix(f_inv_list).reshape(m,1)  
    
    F_inv_sym = f_inv.jacobian(u)
    
    
    
    
    tab = ' '*4
    
    f_str = ''
    
    f_str += 'import numpy as np\n\n'
    f_str += 'exp = np.exp \n'
    f_str += 'log = np.log \n'
    f_str += 'sin = np.sin \n'
    f_str += 'cos = np.cos \n'
    f_str += 'asin = np.arcsin \n'
    f_str += 'acos = np.arccos \n'
    f_str += '\n'
    
    f_str += 'class formulation():\n\n'
    
    # __init__
    f_str += tab + 'def __init__(self):\n\n'
    f_str += 2*tab + 'self.n = {:d} \n'.format(n)
    f_str += 2*tab + 'self.m = {:d} \n'.format(m)
    f_str += '\n'
    f_str += 2*tab + 'self.F_inv = np.zeros((self.m,self.m)) \n'
    f_str += 2*tab + 'self.E = np.zeros((self.n,self.m)) \n'
    f_str += 2*tab + 'self.C = np.zeros((self.m,self.n)) \n'
    f_str += 2*tab + 'self.p = np.zeros((self.n,1)) \n'
    f_str += 2*tab + 'self.u = np.zeros((self.m,1)) \n'
    f_str += 2*tab + 'self.y = np.zeros((self.m,1)) \n'
    f_str += 1*'\n'
     
    for item_id,item_val in params.items(): 
        f_str += 2*tab + 'self.{:s} = {} \n'.format(item_id,item_val)
    f_str += 2*'\n'
    f_str += 2*tab + 'self.E_eval() \n'
    f_str += 2*tab + 'self.C_eval() \n'
    f_str += 2*tab + 'self.p_eval() \n'
    f_str += 1*'\n'
    
    
    
    # E_eval
    f_str += tab + 'def E_eval(self):\n\n'
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    
    # E
    for it in range(n): 
        for jt in range(m):
            element = str(E_sym[it,jt])
            if element!='0':            
                f_str += 2*tab + 'self.E[{:d},{:d}]={:s} \n'.format(it,jt,str(E_sym[it,jt]))
    f_str += 2*'\n'
    
    
    
    
    
    # C_eval
    f_str += tab + 'def C_eval(self):\n\n'
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    
    # C
    for it in range(m): 
        for jt in range(n):
            element = str(C_sym[it,jt])
            if element!='0':            
                f_str += 2*tab + 'self.C[{:d},{:d}]={:s} \n'.format(it,jt,str(C_sym[it,jt]))
    f_str += 2*'\n'
    
    
    # p_eval
    f_str += tab + 'def p_eval(self):\n\n'
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    
    # p
    for it in range(n): 
        f_str += 2*tab + 'self.p[{:d},0]={:s} \n'.format(it,str(p[it]))
    f_str += 2*'\n'
    
    # f
    f_str += tab + 'def f(self,y):\n\n'
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    for it in range(m):  
        sep = ','
        if it==m-1:
            sep = ''
        f_str += 2*tab +'y_{:d} = y[{:d},0] \n'.format(it+1,it) 
    f_str += '\n'
    f_str += 2*tab +'return np.array([\n'
    for it in range(m):  
        sep = ','
        if it==m-1:
            sep = ''
        f_str += 4*tab + str(f[it,0]) + sep + '\n' 
    f_str += 4*tab + ']).reshape(self.m,1)'
    f_str += '\n'
    
    # f_inv
    f_str += tab + 'def f_inv(self,u):\n\n'
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    for it in range(m):  
        sep = ','
        if it==m-1:
            sep = ''
        f_str += 2*tab +'u_{:d} = u[{:d},0] \n'.format(it+1,it) 
    f_str += '\n'
    f_str += 2*tab +'return np.array([\n'
    for it in range(m):  
        sep = ','
        if it==m-1:
            sep = ''
        f_str += 4*tab + str(f_inv[it,0]) + sep + '\n' 
    f_str += 4*tab + ']).reshape(self.m,1)'
    f_str += '\n'
    f_str += '\n'
    
    # F_inv
    f_str +=tab + 'def F_inv_eval(self,u):\n\n'
    for it in range(m):  
        sep = ','
        if it==m-1:
            sep = ''
        f_str += 2*tab +'u_{:d} = u[{:d},0] \n'.format(it+1,it) 
    f_str += 2*'\n'
    
    for item_id,item_val in params.items(): 
        f_str += 2*tab + '{:s} = self.{:s} \n'.format(item_id,item_id)
    f_str += 2*'\n'
    
    for it in range(m): 
        for jt in range(m):
            element = str(F_inv_sym[it,jt])
            if element!='0':
                
                f_str += 2*tab + 'self.F_inv[{:d},{:d}]={:s} \n'.format(it,jt,str(F_inv_sym[it,jt]))
    
    # a to x
    f_str += tab + 'def a2x(self,a):\n\n'
    for it in range(n): 
        f_str += 2*tab +'a_{:d} = a[{:d},0] \n'.format(it+1,it) 
    f_str += 2*'\n'
    for item in xa: 
        f_str += 2*tab + '{:s} = {:s} \n'.format(str(item['x']),str(item['x(a)']))
    f_str += 2*'\n'
    f_str += 2*tab + 'return np.array([\n'
    it = 0
    for item in xa: 
        f_str += 3*tab + '{:s}'.format(str(item['x']))
        if it < n-1:
            f_str += ',\n'
        else:
            f_str += '\n'
        it += 1
    f_str += 3*tab +']).reshape(self.n,1)'
    f_str += 2*'\n'
    
    
    # x to a
    f_str += tab + 'def x2a(self,x):\n\n'
    it = 0
    for item in xa: 
        f_str += 2*tab + '{:s} = x[{:d},0] \n'.format(str(item['x']),it)
        it += 1
    f_str += 2*'\n'
    it = 0
    for item in xa: 
        f_str += 2*tab + 'a_{:d} = {:s} \n'.format(it,str(item['a(x)']))
        it += 1
    f_str += 2*'\n'
    f_str += 2*tab + 'return np.array([\n'
    it = 0
    for item in xa: 
        f_str += 3*tab + 'a_{:d}'.format(it+1)
        if it < n-1:
            f_str += ',\n'
        else:
            f_str += '\n'
        it += 1
    f_str += 3*tab +']).reshape(self.n,1)'
    f_str += 2*'\n'
    
    fobj = open('factor.py','w')
    fobj.write(f_str)
    fobj.close()

            

import yaml


fobj = open('data_pf_2bus.yaml','r')
yaml_str = fobj.read()
fobj.close()
d = yaml.load(yaml_str)

fgen(d)

#print(json.dumps(ph))
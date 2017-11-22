#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
lines = [
         {'bus_j':1, 'bus_k':2, 'km':0.1, 'code':'OH1'},
         {'bus_j':2, 'bus_k':3, 'km':0.5, 'code':'OH1'},
         {'bus_j':3, 'bus_k':4, 'km':0.2, 'code':'OH1'},
         {'bus_j':3, 'bus_k':5, 'km':0.3, 'code':'OH1'},    
        ]

@author: jmmauricio
"""

from collections import OrderedDict
fobj = open('./raw_from_pdf/cigre_lv_lines.txt', 'r')

lines = fobj.readlines()

lines_list = []
lines_dict = {}

it = 0
for line in lines:
    
    if it == 1: lines_dict.update({'bus_j':line.replace(' ','').replace('\n','')}) 
    if it == 2: lines_dict.update({'bus_k':line.replace(' ','').replace('\n','')}) 
    if it == 3: lines_dict.update({'code':line.replace(' ','').replace('\n','')}) 
    if it == 4: lines_dict.update({'m':float(line.replace(' ','').replace('\n',''))}) 
    if it == 6: 
        lines_list += [lines_dict]
        lines_dict = {}               
        oredered = ['bus_j','bus_k','code','m']
        
        for item in lines_list:
            string = '{'
            it_ordered = 0
            for ordered_item in oredered:
                string += "'" +ordered_item + "': "
                if type(item[ordered_item]) == float:
                    string += str(item[ordered_item]) 
                    if it_ordered < len(oredered)-1: string += ", "
                else:
                    string += "'" + str(item[ordered_item]) 
                    if it_ordered < (len(oredered)-1): string += "', "
                it_ordered += 1
            string += "},"
            print(string)
        it = 0
    it += 1
fobj.close()
    

'''
loads = [
         {'bus':1, 'type':'v','kV':[0.231]*3, 'deg':0.0, 'pos_x':0.0, 'pos_y':0},
         {'bus':2, 'type':'i','A':[0.0]*3,'fp':[0.8]*3, 'pos_x':0.2, 'pos_y':0.0},
         {'bus':3, 'type':'i','A':[0.0]*3,'fp':[1.0]*3, 'pos_x':0.4, 'pos_y':0},
         {'bus':4, 'type':'i','A':[0.0]*3,'fp':[1.0]*3, 'pos_x':0.4, 'pos_y':-0.2},  
         {'bus':5, 'type':'i','A':[-10.0]*3,'fp':[1.0]*3, 'pos_x':0.6, 'pos_y':0},   
        ]

'''
fobj = open('./raw_from_pdf/cigre_lv_loads.txt', 'r')

lines = fobj.readlines()

lines_list = []
lines_dict = {}

it = 0
for line in lines:
    
    if it == 0: lines_dict.update({'bus':line.replace(' ','').replace('\n','')}) 
    if it == 1: lines_dict.update({'kVA':float(line.replace(' ','').replace('\n',''))}) 
    if it == 2: lines_dict.update({'fp':float(line.replace(' ','').replace('\n',''))}) 

    it += 1
    if it == 3: 
        lines_list += [lines_dict]
        lines_dict = {}               
        oredered = ['bus','kVA','fp']
        
        for item in lines_list:
            string = '{'
            it_ordered = 0
            for ordered_item in oredered:
                string += "'" +ordered_item + "': "
                if type(item[ordered_item]) == float:
                    string += str(item[ordered_item]) 
                    if it_ordered < len(oredered)-1: string += ", "
                else:
                    string += "'" + str(item[ordered_item]) 
                    if it_ordered < (len(oredered)-1): string += "', "
                it_ordered += 1
            string += "},"
        print(string)
        it = 0
    
    
fobj.close()
    

fobj = open('./raw_from_pdf/cigre_lv_results.txt', 'r')

lines = fobj.readlines()

lines_list = []
lines_dict = {}

it = 0
for line in lines:
    
    if it == 0: lines_dict.update({'bus':line.replace(' ','').replace('\n','')}) 
    if it == 1: lines_dict.update({'V_phase_jk':(line.replace(' ','').replace('\n',''))}) 
    if it == 2: lines_dict.update({'V_rms_ll':float(line.replace(' ','').replace('\n',''))}) 
    if it == 3: lines_dict.update({'V_deg':float(line.replace(' ','').replace('\n',''))}) 
    if it == 4: lines_dict.update({'bus_jk':(line.replace(' ','').replace('\n',''))}) 
    if it == 5: lines_dict.update({'A_phase':(line.replace(' ','').replace('\n',''))}) 
    if it == 6: lines_dict.update({'A_rms':float(line.replace(' ','').replace('\n',''))}) 
    if it == 7: lines_dict.update({'A_deg':float(line.replace(' ','').replace('\n',''))})
    
    it += 1
    if it == 8: 
        lines_list += [lines_dict]
        lines_dict = {}               
        oredered = ['bus','V_phase_jk','V_rms_ll','V_deg','bus_jk','A_phase','A_rms','A_deg']
        
        for item in lines_list:
            string = '{'
            it_ordered = 0
            for ordered_item in oredered:
                string += "'" +ordered_item + "': "
                if type(item[ordered_item]) == float:
                    string += str(item[ordered_item]) 
                    if it_ordered < len(oredered)-1: string += ", "
                else:
                    string += "'" + str(item[ordered_item]) 
                    if it_ordered < (len(oredered)-1): string += "', "
                it_ordered += 1
            string += "},"
        print(string)
        it = 0
    
    
fobj.close()
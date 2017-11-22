# -*- coding: utf-8 -*-
"""
Created on Thu Jan  8 16:09:57 2015

@author: jmmauricio
"""

from mpl_toolkits.basemap import Basemap
import numpy as np
import matplotlib.pyplot as plt
from osmapi import OsmApi

MyApi = OsmApi()
U16 = MyApi.NodeGet(3268727324)

plants = [{'name':u'Central Termoeléctrica Angamos', 'plant_id':138382624, 'p':263*2.0}, 
          {'name':u'Central Termoeléctrica de Mejillones', 'plant_id': 84036281, 'p':263*2.0},
          {'name':u'Central Termoelectrica Tocopilla', 'plant_id': 135548272, 'p':300.0*2.0},
          {'name':u'TermoAndes', 'plant_id':247820687, 'p':400.0} ] 

generators   = np.genfromtxt('red_sing_id - Generators.csv', delimiter = ',',skip_header=1, usecols=(0,1), dtype=[('mystring', '|S5'), ('myfloat', '<i8')])
substations  = np.genfromtxt('red_sing_id - Substations.csv', delimiter = ',', skip_header=1, usecols=(0,1), dtype=[('mystring', '|S5'), ('myfloat', '<i8')])         
terminals    = np.genfromtxt('red_sing_id - Terminals.csv', delimiter = ',', skip_header=1, usecols=(0,1), dtype=[('mystring', '|S5'), ('myfloat', '<i8')])         
lines        = np.genfromtxt('red_sing_id - Lines.csv', delimiter = ',',usecols=(0,5,6,7,8,9,10), skip_header=1, dtype=[('ds_id', '|S60'), ('way1', '<i8'), ('way2', '<i8'), ('way3', '<i8'), ('way4', '<i8'), ('way5', '<i8'), ('way6', '<i8')])         

# llcrnrlat,llcrnrlon,urcrnrlat,urcrnrlon
# are the lat/lon values of the lower left and upper right corners
# of the map.
# lat_ts is the latitude of true scale.
# resolution = 'c' means use crude resolution coastlines.
m = Basemap(projection='merc',llcrnrlat=-26,urcrnrlat=-17,\
            llcrnrlon=-71,urcrnrlon=-64.8,lat_ts=20,resolution='h')
            
            
#for plant in plants:
#    osm_way = MyApi.WayGet(plant['plant_id'])
#    
#       
#    nodes = osm_way[u'nd']
#    plant['nodes_id'] = []
#    plant['lats'] = []
#    plant['longs'] = []
#    plant['y'] = []
#    plant['x'] = []
#    for node in nodes:
#        osm_node = MyApi.NodeGet(node)
##        print osm_node
#        plant['nodes_id'] += [osm_node[u'id'] ]
#        plant['lats']  += [osm_node[u'lat']]
#        plant['longs'] += [osm_node[u'lon'] ]
#        xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])
#        plant['y'] += [ypt]
#        plant['x'] += [xpt]


    
    


m.drawcoastlines(linewidth=0.25)
m.drawcountries(linewidth=0.25)
m.fillcontinents(color='white',lake_color='aqua')
# draw parallels and meridians.
#m.drawparallels(np.arange(-90.,91.,30.))
#m.drawmeridians(np.arange(-180.,181.,60.))
m.drawmapboundary(fill_color='aqua')

#lines = [{'name':'prueba', 'ways_id':[30641638], 'nodes_id':[]}]
#

        


# plot blue dot on Boulder, colorado and label it as such.
lon, lat = U16[u'lon'], U16[u'lat']  # Location of Boulder
# convert to map projection coords.
# Note that lon,lat can be scalars, lists or numpy arrays.
xpt,ypt = m(lon,lat)
#m.plot(xpt,ypt,'bo')  # plot a blue dot there
#m.plot(lines[0]['x'],lines[0]['y'])  # plot a blue dot there

import pickle


lines_read = []
     
#for line in lines:
#     
#    ways_list = ['way1','way2','way3','way4','way5','way6']
#    ways_osm_id = []    
#    for item in ways_list:
#        
#        if line[item] > 0:
#
#            ways_osm_id += [line[item]]      
#    x = []
#    y = []
#    for way in ways_osm_id:
#        osm_way = MyApi.WayGet(way)        
#        nodes = osm_way[u'nd']
#
#        for node in nodes:
#            osm_node = MyApi.NodeGet(node)
##            print osm_node
#            xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])
#            y += [ypt]
#            x += [xpt]
#            
#    lines_read += [{'name':line['ds_id'],'x':x,'y':y}]      
#pickle.dump(lines_read,open('lines.pkl','w'))




data = pickle.load(open('lines.pkl','r'))
#lines_file = open('lines.json','r')
#lines_json = lines_file.read()
#lines_read = json.loads(lines_json)
#for line in data:
#    
#    m.plot(line['x'],line['y'], 'm')  # plot a blue dot there  
          


for gen  in generators:
        node = gen[1]
        osm_node = MyApi.NodeGet(node)
        xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])            
        m.plot(xpt,ypt, 'b.')  # plot a blue dot there
 
#for subs in substations:
#        node = subs[1]
#        way= MyApi.WayGet(subs[1])
#        way_nodes = way[u'nd']
#        osm_node = MyApi.NodeGet(way_nodes[0])
#        xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])            
#        m.plot(xpt,ypt, 'r.')  # plot a blue dot there

for terminal in terminals:
        node = terminal[1]
        way= MyApi.WayGet(terminal[1])
        way_nodes = way[u'nd']
        osm_node = MyApi.NodeGet(way_nodes[0])
        xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])            
        m.plot(xpt,ypt, 'g.')  # plot a blue dot there


plt.title("Mercator Projection")
plt.savefig('pruebas.svg')

plt.close()
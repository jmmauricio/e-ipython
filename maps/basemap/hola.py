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
# llcrnrlat,llcrnrlon,urcrnrlat,urcrnrlon
# are the lat/lon values of the lower left and upper right corners
# of the map.
# lat_ts is the latitude of true scale.
# resolution = 'c' means use crude resolution coastlines.
m = Basemap(projection='merc',llcrnrlat=-29,urcrnrlat=-17,\
            llcrnrlon=-72,urcrnrlon=-65,lat_ts=20,resolution='h')

m.drawcoastlines(linewidth=0.25)
m.drawcountries(linewidth=0.25)
m.fillcontinents(color='white',lake_color='aqua')
# draw parallels and meridians.
#m.drawparallels(np.arange(-90.,91.,30.))
#m.drawmeridians(np.arange(-180.,181.,60.))
m.drawmapboundary(fill_color='aqua')

lines = [{'name':'prueba', 'ways_id':[30641638], 'nodes_id':[]}]

for line in lines:
    ways = line['ways_id']
    
    for way in ways:
        osm_way = MyApi.WayGet(way)
        
        nodes = osm_way[u'nd']
        line['nodes_id'] = []
        line['lats'] = []
        line['longs'] = []
        line['y'] = []
        line['x'] = []
        for node in nodes:
            osm_node = MyApi.NodeGet(node)
#            print osm_node
            line['nodes_id'] += [osm_node[u'id'] ]
            line['lats']  += [osm_node[u'lat']]
            line['longs'] += [osm_node[u'lon'] ]
            xpt,ypt = m(osm_node[u'lon'],osm_node[u'lat'])
            line['y'] += [ypt]
            line['x'] += [xpt]
        


# plot blue dot on Boulder, colorado and label it as such.
lon, lat = U16[u'lon'], U16[u'lat']  # Location of Boulder
# convert to map projection coords.
# Note that lon,lat can be scalars, lists or numpy arrays.
xpt,ypt = m(lon,lat)
m.plot(xpt,ypt,'bo')  # plot a blue dot there
m.plot(lines[0]['x'],lines[0]['y'])  # plot a blue dot there

plt.title("Mercator Projection")
plt.savefig('pruebas.svg')

plt.close()
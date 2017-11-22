# -*- coding: utf-8 -*-
"""
Created on Wed Dec 17 17:05:28 2014

@author: jmmauricio
"""

import numpy as np

ie_e = np.array([[0.01, 26.72],
                 [0.44, 55.56],
                 [0.83, 86.47],
                 [1.10, 107.08],
                 [1.46, 133.18],
                 [1.84, 159.96],
                 [2.18, 177.45],
                 [2.43, 187.04],
                 [2.70, 194.90],
                 [2.84, 196.94]])

import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

ax.plot(ie_e[:,0],ie_e[:,1])
ax.set_xlabel(u'Intensidad de exitación (A)')
ax.set_ylabel(u'Tensión de vacío (V)')
ax.grid(True)
fig.savefig('curva_ie_e.png')
#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: gicque_p
# @Date:   2015-05-15 18:18:44
# @Last Modified by:   gicque_p
# @Last Modified time: 2015-05-19 12:51:16

import matplotlib.pyplot as plt
import numpy as np
import sys
import math

a1 = float(sys.argv[1])
b1 = float(sys.argv[2])
v1 = a1 * 1960 + b1
v2 = a1 * 2050 + b1

a2 = float(sys.argv[3])
b2 = float(sys.argv[4])
v3 = (1960 - b2) / a2
v4 = (2050 - b2) / a2

x3 = []
y3 = []

for i in range(1961, 2012):
	x3.append(i)

for arg in sys.argv[5:]:
	y3.append(float(arg))

x1 = np.linspace(1960, 2050)
y1 = np.linspace(v1, v2)

x2 = np.linspace(1960, 2050)
y2 = np.linspace(v3, v4)

try:
	plt.plot(x1, y1, color="#00FF00", label="Ajustement de Y en X", linewidth=2)
	plt.plot(x2, y2, color="#FF0000", label="Ajustement de X en Y", linewidth=2)
	plt.plot(x3, y3, color="#0000FF", label="Moyenne demographique", linewidth=2)

	plt.legend()
	plt.xlabel("annees")
	plt.ylabel("population (en millions)")

	plt.show()	

except:
	print "Error while displaying data"

#!/usr/bin/python2

import matplotlib.pyplot as plt
import numpy as np
import sys
import math

x = []
y = []

prob = 0
qi = 0
result = 0

try:
	u = int(sys.argv[1])
	o = int(sys.argv[2])
except:
	print ("Bad arguments for displaying")
	exit()

while (qi < 200) :
	prob = (1 / (o * np.sqrt(2 * np.pi))) * np.exp(-(pow(qi - u, 2) / (2 * pow(o, 2))))
	result = result + prob

	x.append(qi)
	y.append(result)
	prob = float(0)

	qi = qi + 0.01

try:
	plt.plot(x, y, color='#0000FF', label='repartition', linewidth=2)
	plt.title('205QI', fontsize=20)
	plt.xlabel('QI', fontsize=16)
	plt.ylabel('Probabilite (%)', fontsize=16)
	plt.legend()
	plt.show()
except:
	print ("Display Error")

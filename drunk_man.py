from random import *
from functools import *
from math import *

def add_points(a, b):
	return (a[0] + b[0], a[1] + b[1])
def midpoints(a, b):
	return ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2)
def dist(x):
	return sqrt(x[0] * x[0] + x[1] * x[1])
def drunk_man(steps):
	if not steps:
		return (0, 0)
	return add_points(
		choice([(1, 0), (0, 1), (-1, 0), (0, -1)]),
		drunk_man(steps - 1))

steps = int(input())
print(dist(reduce(midpoints, [drunk_man(steps) for i in range(steps)])))

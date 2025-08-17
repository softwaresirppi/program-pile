from itertools import *
from functools import *
from math import *
from random import random
from bokeh import plotting as plot

def identity(n, diagonal=1, rest=0):
	return [[diagonal if i == j else rest for j in range(n)] for i in range(n)]

def stack_below(*tensors):
	if not tensors:
		return []
	return [*tensors[0], *stack_below(*tensors[1:])]

polynomial = lambda coeffs: lambda x: sum(coeff * x**i for i, coeff in enumerate(coeffs))

coeffs = [0,0,0]
def pretty_coeffs(coeffs):
	return ' +'.join([f'{coeff}x^{i}' for i, coeff in enumerate(coeffs)])

def error(points, coeffs):
	f = polynomial(coeffs)
	return sum((y - f(x))**2 for x, y in points)

def better_fit(points, coeffs, alpha=1):
	return min(
		[[c + d for c, d in zip(coeff, delta)] for coeff, delta in
			zip(
				repeat(coeffs),
				stack_below(
					identity(len(coeffs), diagonal=alpha),
					identity(len(coeffs), diagonal=-alpha),
					[[0] * len(coeffs)]
				)
			)
		],
		key = lambda coeffs: error(points, coeffs)
	)
def fit(points, coeffs, alpha, accuracy=8):
	print('BEFORE %s (error %d)' % (pretty_coeffs(coeffs), error(points, coeffs)))
	better_coeffs = better_fit(points, coeffs, alpha)
	print('is that %s? (error %d)' % (pretty_coeffs(better_coeffs), error(points, better_coeffs)))
	print('IMPROVEMENT',  abs(error(points, coeffs) - error(points, better_coeffs)))
	if abs(error(points, coeffs) - error(points, better_coeffs)) < 10**-accuracy:
		print('FINAL', pretty_coeffs(better_coeffs))
		return better_coeffs
	else:
		return fit(points, better_coeffs, alpha)

# USER SPACE
if __name__ == '__main__':
	N = 32
	alpha = 0.1
	dimensions = 6
	points = [(x, x**2) for x in range(N)]

	coeffs = fit(points, [0] * dimensions, alpha=alpha)
	f = polynomial(coeffs)
	graph = plot.figure(width=2**10, height=2**10)
	graph.scatter(*zip(*points), color='black')
	graph.line(list(range(N)), [f(i) for i in range(N)], line_color='purple')
	plot.show(graph)

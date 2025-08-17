from random import random

total_points = 2 ** int(input())
circle_points = 0
for _ in range(total_points):
	x, y = random(), random()
	if x ** 2 + y ** 2 < 1:
		circle_points += 1
print((4 * circle_points)/total_points)


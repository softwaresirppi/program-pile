from time import sleep
from random import choice
def p(guess, target):
	if target:
		for c in 'abcdefghijklmnopqrstuvwxyz':
			if c < target[0]:
				sleep(0.03)
				print(f'\033[37;2m', guess + c, '\033[0m', sep='')
			elif c == target[0]:
				sleep(0.03)
				print(f'\033[32;1m', guess + c, '\033[0m', sep='')
		p(guess + target[0], target[1:])

p('', 'hello world')

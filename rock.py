import random

def play():
    me = input()
    machine = random.choice(['rock', 'paper', 'scissor'])
    print(machine)
    if me == machine:
        return 'draw'
    if me + machine in ('rockscissor', 'paperrock', 'scissorpaper'):
        return 'You win.'
    else:
        return 'I win you dumbass'

for i in range(3):
    print(play())

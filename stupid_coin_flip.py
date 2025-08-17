from time import time
# seed goes here
# state = 0xBABE0690C0FFEE00DEAD001430BEE069
state = (int(time()) ** 4)
def toss():
    global state
    feedback = (state ^ state >> 1 ^ state >> 2 ^ state >> 7) & 1
    state = (
        state >> 1 # shifting
        | 
        feedback << 127 # feeding back
    )
    return state & 1

zeroes, ones = 0, 0
for i in range(1000):
    toss()
for i in range(10):
    if toss():
        ones += 1
    else:
        zeroes += 1
print(f"{zeroes} zeroes and {ones} ones")

from math import *
def solve(f, guess, epsilon = 10 ** -8):
    print('maybe', guess)
    if abs(f(guess)) < epsilon:
        return guess
    else:
        # newton's method goes brrrrr
        better_guess = guess - f(guess) / ((f(guess + epsilon) - f(guess - epsilon)) / (2 * epsilon))
        return solve(f, better_guess)
print("%.8F" % solve(lambda x: 2 ** 8 - x ** x, 1))

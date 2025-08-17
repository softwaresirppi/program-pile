precision = 4
def close_enough(x, y):
    return abs(x - y) < (10 ** -precision)

def sqrt(x, start=None, end=None, iterations=0):
    if not end:
        end = max(1, x)
    if not start:
        start = 0
    mid = (start + end) / 2
    if close_enough(mid * mid, x):
        return round(mid, precision), iterations
    elif mid * mid < x:
        return sqrt(x, mid, end, iterations + 1)
    elif x < mid * mid:
        return sqrt(x, start, mid, iterations + 1)

def numeric_sqrt(x, guess=1, iterations=0):
    if close_enough(guess * guess, x):
        return round(guess, precision), iterations
    return numeric_sqrt(x, (guess + x/guess) / 2, iterations + 1)

x = 123456789
print(f"BINARY SEARCH: %.{precision}f in %d iterations" % sqrt(x))
print(f"NEWTON: %.{precision}f in %d iterations" % numeric_sqrt(x))

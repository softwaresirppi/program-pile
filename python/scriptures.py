# Extracting info (reading)
# Write (over-writing)
# 
# DElete

# ===ALGORITHMS===

# 1 0
# 

#permute(states, n)
#permute([0, 1], 1) = [[0], [1]]

#[permutations.append(state) for state in states]
#dupe it len(states) times

def permute(states, n, permutations):
    if n == 0:
        return permutations
    for state in states:
        for permutation in permutations:
            permutation.append(state)
    return permute(states, n - 1, permutations);

def binarySearch(sortedList, target):
    f = 0
    t = len(sortedList) - 1
    while f < t:
        mid = int((f + t) / 2)
        if sortedList[mid] < target:
            f = mid + 1
        if target < sortedList[mid]:
            t = mid
        print(f"from {f} and {t}: mid {mid}")
        if f == t:
            return f
        if sortedList[mid] == target:
            return mid
    return f

def recursiveBinarySearch(sortedList, begin, end, target):
    if not (begin < end):
        return begin
    mid = int((begin + end) / 2)
    if sortedList[mid] < target:
        return search(sortedList, mid + 1, end, target)
    elif target < sortedList[mid]:
        return search(sortedList, begin, mid, target)
    else:
        return mid

def bubbleSort(l):
    for times in range(len(l)):
        for i in range(len(l) - 1 - times):
            if l[i] > l[i + 1]:
                l[i] ^= l[i + 1]
                l[i + 1] ^= l[i]
                l[i] ^= l[i + 1]

def mergeSort(l):
    if len(l) < 2:
        return l
    left = mergeSort(l[0:len(l)//2])
    right = mergeSort(l[len(l)//2:len(l)])
    i = 0
    j = 0
    c = []
    while i < len(left) or j < len(right):
        leftElement = left[i] if i < len(left) else 9223372036854775807
        rightElement = right[j] if j < len(right) else 9223372036854775807
        if leftElement < rightElement:
            c.append(leftElement)
            i += 1
        elif rightElement <= leftElement:
            c.append(rightElement)
            j += 1
    return c

def quickSort():
    pass

def isSorted(l):
    for i in range(len(l) - 1):
        if l[i] > l[i + 1]:
            return False
    return True

def godSort(l):
    while not isSorted(l):
        print(l)
        random.shuffle(l)

# ===Samples===
fibo = [0, 1]
def pushFibo(fibo):
    fibo.append(fibo[-1] + fibo[-2])
for i in range(100):
    pushFibo(fibo)
#for f in fruits:
    #f = 0
    #t = len(ordered) - 1
    #while f < t:
        #mid = int((f + t) / 2)
        #if ordered[mid] == target:
            #print("FOUND AT " + str(mid))
        #if ordered[mid] <= target:
            #f = mid + 1
        #elif target <= l[mid]:
            #t = mid
        #print 

# ===Arithmetics===
def increment(x):
    return x + 1

def add(x, y):
    print(f"({x} + {y})", end = '')
    if y == 0:
        return x
    return add(increment(x), y - 1)

def multiply(x, y):
    print(f"({x} * {y})", end = '')
    if y == 1:
        return x
    return multiply(add(x, x), y - 1)

def power(x, y):
    print(f"({x} ^ {y})", end = '')
    if y == 1:
        return x
    return power(multiply(x, x), y - 1)

def pi(n):
    sum = 0
    for i in range(1, n, 2):
        sum += 1/i if i % 4 == 1 else -1/i
    return sum * 4


factorialCache = {0: 1, 1: 1}
def factorial(n):
    if n in factorialCache:
        return factorialCache[n]
    factorialCache[n] = factorial(n - 1) * n
    return factorialCache[n]

def hammer(a, b):
    if b == 0:
        return a
    print('%d %d\n' % (a, b))
    return hammer(b, a % b)

# hammer * glass = a * b
def glass(a, b):
    return (a * b) / hammer(a, b)

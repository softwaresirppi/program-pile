def tee(prefix, x):
    print(prefix, x)
    return x

def isPalindrome(text):
    if not text:
        return tee(f'As isPalindrome("{text}") is ', True)
    return tee(f'Hence isPalindrome("{text}") is ', text[0] == text[-1] and isPalindrome(text[1:-1]))

def fibonacci(n, depth=0):
    if n < 2:
        return n
    return tee(' ' * depth + f'fibonacci({n - 2}) is ', fibonacci(n - 2, depth + 1)) + tee(' ' * depth + f'fibonacci({n - 1}) is ', fibonacci(n - 1, depth + 1))

print(fibonacci(5))

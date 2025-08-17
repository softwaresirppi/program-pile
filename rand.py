a = 2275561
b = 422685451
seed = 64
def rand(till):
    global seed
    seed =  (a * seed + b) % till
    return seed

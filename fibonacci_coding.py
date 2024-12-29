def fibos(till, prepre=0, pre=1):
    curr = prepre + pre
    if curr <= till:
        return [prepre] + fibos(till, pre, curr)
    else:
        return [prepre, pre]

print(fibos(0))
# weights have to be in ascending order
def encode(x, weights):
    if not weights:
        return ''
    if weights[-1] <= x:
        return encode(x - weights[-1], weights[:-1]) + '1'
    else:
        return encode(x, weights[:-1]) + '0'

fibonacci_encode = lambda n : encode(n, fibos(n)[2:]) + '1'

def test(fibonacci_encode):
    assert(fibonacci_encode(1) == '11')
    assert(fibonacci_encode(2) == '011')
    assert(fibonacci_encode(3) == '0011')
    assert(fibonacci_encode(4) == '1011')
    assert(fibonacci_encode(11) == '001011')
    assert(fibonacci_encode(12) == '101011')
    assert(fibonacci_encode(13) == '0000011')
    assert(fibonacci_encode(14) == '1000011')
    assert(fibonacci_encode(65) == '0100100011')
    assert(fibonacci_encode(610) == '000000000000011')
    assert(fibonacci_encode(8967) == '00001010101010010011')
    assert(fibonacci_encode(8039213) == '0010010010100010001001001000001011')
test(fibonacci_encode)

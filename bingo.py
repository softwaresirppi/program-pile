from numpy import *
board = array([
    [0., 0., 0., 0.],
    [0., 0., 0., 0.],
    [0., 0., 0., 0.],
    [0., 0., 0., 0.],
])
n = len(board)
F = full((n, n), 1)
I = identity(n)
numbers = arange(n * n).reshape((n, n))

def gowtham_move(board):
    benefit = (1 - board) * (F @ board + transpose(F @ transpose(board)) + I * sum(I * board) + transpose(I) * sum(I * board))
    moves = floor(benefit / benefit.max())
    move = floor((moves * numbers) / (moves * numbers).max())
    return move
while True:
    print(board)
    print('Your move?')
    r, c = map(int, input().split())
    board[r][c] += 1
    board += gowtham_move(board)


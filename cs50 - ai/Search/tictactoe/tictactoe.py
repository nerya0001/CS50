"""
Tic Tac Toe Player
"""

import math
from copy import deepcopy


X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    x = 0
    o = 0

    for rows in board:
        for columns in rows:
            if columns == X:
                x += 1
            elif columns == O:
                o += 1

    if x <= o:
        return X
    else:
        return O


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions_set = set()

    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                actions_set.add((i, j))
    return actions_set


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    copy = deepcopy(board)

    if board[action[0]][action[1]] != EMPTY:
        raise Exception("not a valid move!")
    else:
        copy[action[0]][action[1]] = player(board)

    return copy


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    # checking rows
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] and (board[i][0] != EMPTY):
            return board[i][0]

    # checking columns
    for i in range(3):
        if (board[0][i] == board[1][i] == board[2][i]) and (board[0][i] != EMPTY):
            return board[0][i]

    # checking diagonally
    if ((board[0][0] == board[1][1] == board[2][2]) or (board[0][2] == board[1][1] == board[2][0])) \
            and (board[1][1] != EMPTY):
        return board[1][1]

    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    # check if the board is full or if someone won
    if winner(board) is not None:
        return True

    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                return False
    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    if terminal(board):
        return None

    if player(board) == X:
        v = -math.inf
        opt_move = None
        for action in actions(board):
            a = minv(result(board, action))
            if a > v:
                v = a
                opt_move = action
        return opt_move

    elif player(board) == O:
        v = math.inf
        opt_move = None
        for action in actions(board):
            b = maxv(result(board, action))
            if b < v:
                v = b
                opt_move = action
        return opt_move


def maxv(board):
    if terminal(board):
        return utility(board)
    n = -math.inf
    for action in actions(board):
        n = max(n, minv(result(board, action)))
    return n


def minv(board):
    if terminal(board):
        return utility(board)
    n = math.inf
    for action in actions(board):
        n = min(n, maxv(result(board, action)))
    return n






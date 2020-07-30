#!/usr/bin/python3
"""N queens puzzle """
import sys


def is_attack(board, column):
    """checking if there is a queen in row or column"""
    for i in range(column):
        if board[i] == board[column]:
            return False
        if abs(board[i] - board[column]) == abs(i - column):
            return False
    return True


def N_queen(board, column):
    """change the position of the queen"""
    n = len(board)
    complete = 0

    if column == n:
        result = []

        for i in range(len(board)):
            result.append([i, board[i]])

        print(result)
        return True

    board[column] = -1

    while(board[column] < n - 1 or complete == 1):
        board[column] = board[column] + 1
        if is_attack(board, column) is True:
            if column != n:
                N_queen(board, (column + 1))
            else:
                complete = 1
                break
    return True


if __name__ == "__main__":

    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)

    N = int(sys.argv[1])
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    board = [[0 for col in range(N)] for row in range(N)]

    N_queen(board, 0)

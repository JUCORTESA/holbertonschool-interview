#!/usr/bin/python3
'''Minimum Operations'''


def minOperations(n):
    '''Method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    Arguments:
        n - character
    Returns:
        an integer
    '''
    if type(n) is not int or n < 2:
        return 0
    operation = 0
    for i in range(2, int(n ** (1 / 2))):  # sqrt limit for faster algorithm
        while n % i == 0:  # check if can be divided as Least Common Multiple
            operation += i  # if yes then add that multiple.
            n = n/i
    if n > 1:  # if is prime number
        operation += n
    return int(operation)

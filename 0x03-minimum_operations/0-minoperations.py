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
    for i in range(2, n):
        while(n % i == 0):  # check if problem can be broken into smaller prob
            operation += i  # if yes then add n of smaller problems to result.
            n = n/i
    if n > 1:  # if is prime number
        operation += n
    return operation

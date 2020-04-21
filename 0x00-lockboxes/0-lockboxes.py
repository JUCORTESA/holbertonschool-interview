#!/usr/bin/python3
'Lockboxes'


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened

    Arguments:
        boxes is a list of lists
        A key with the same number as a box opens that box

    Returns:
        True if all boxes can be opened, else return False
    """
    if (len(boxes) < 1 or type(boxes) is not list):
        return False
    checkbox = {}
    stack = [0]
    aux = []

    for key in range(len(boxes)):
        checkbox[key] = boxes[key]
        aux.append(key)
    box = 0
    i = 0
    while i < len(aux):
        for num in checkbox[box]:
            if box in stack or num in aux:
                if num not in stack and num is not None and num in aux:
                    stack.append(num)
                    box = num
        i += 1
    stack.sort()
    if stack == aux:
        return True
    else:
        return False

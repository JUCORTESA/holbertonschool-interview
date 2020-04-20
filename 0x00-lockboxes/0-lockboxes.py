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
    for box, arr in checkbox.items():
        box = 0
        for num in arr:
            if box in stack:
                box = num
                if num not in stack:
                    stack.append(num)
                    break
                else:
                    continue
    stack.sort()
    if stack == aux:
        return True
    else:
        return False

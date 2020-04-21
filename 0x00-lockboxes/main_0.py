#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))
print("0")
print("*"*20)

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))
print("1")
print("*"*20)

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
print("2")
print("*"*20)

boxes = [[1, 4, 6], [2, 20], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))
print("3")
print("*"*20)

boxes = [[], [], [], [], [], [], [6]]
print(canUnlockAll(boxes))
print("4")
print("*"*20)

boxes = [[1], [1], [], [], [], [], []]
print(canUnlockAll(boxes))
print("5")
print("*"*20)

boxes = [[3], [], [], [], [], [], []]
print(canUnlockAll(boxes))
print("6")
print("*"*20)

boxes = [[34], [], [], [], [], [], []]
print(canUnlockAll(boxes))
print("7")
print("*"*20)

boxes = [[1],[2],[3],[],[]],[[5],[6]]
print(canUnlockAll(boxes))
print("8")
print("*"*20)

boxes = [[1, 4], [2]]
print("Expected: True")
print(canUnlockAll(boxes))
print('9')
print("*"*20)

boxes = [[],[5],[666],[],[],[1,2,3,4,5]]
print(canUnlockAll(boxes))
print("10")
print("*"*20)

boxes = [[]]
print("Expected: True")
print(canUnlockAll(boxes))
print('11')
print("*"*20)

boxes = [[1],[]]
print("Expected: True")
print(canUnlockAll(boxes))
print('12')
print("*"*20)

boxes = [[0],[0]]
print("Expected: False")
print(canUnlockAll(boxes))
print('13')
print("*"*20)


boxes = [[1, 4, 6], [2], [0, 4, 1], [6, 2], [3], [4, 1], [6, 0, 1, 2, 3, 4, 5]]
print("Expected: True")
print(canUnlockAll(boxes))
print('14')
print("*"*20)


boxes = [[0]]
print("Expected: True")
print(canUnlockAll(boxes))
print('15')
print("*"*20)

boxes = [[1]]
print("Expected: True")
print(canUnlockAll(boxes))
print('16')
print("*"*20)

boxes = [[1], [6], [1], [], [], [], [3, 4, 5, 2]]
print("Expected: True")
print(boxes)
print(canUnlockAll(boxes))
print('17')
print("*"*20)

boxes = [[6], [6], [1], [], [], [], [3, 4, 5, 2, 1]]
print("Expected: True")
print(boxes)
print(canUnlockAll(boxes))
print('18')
print("*"*20)

boxes = [[7], [6], [1], [], [], [], [3, 4, 5, 2, 1]]
print("Expected: False")
print(boxes)
print(canUnlockAll(boxes))
print('19')
print("*"*20)

boxes = [[1, 2, 3, 4, 5, 6, 7], [6], [1], [], [], [], [3, 4, 5, 2, 1]]
print("Expected: True")
print(boxes)
print(canUnlockAll(boxes))
print('20')
print("*"*20)

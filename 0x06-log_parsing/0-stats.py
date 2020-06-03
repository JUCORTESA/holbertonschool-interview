#!/usr/bin/python3
"""Log Parse"""
import sys


input = {'200': 0,
         '301': 0,
         '400': 0,
         '401': 0,
         '403': 0,
         '404': 0,
         '405': 0,
         '500': 0}
status_code = ""
file_size = ""
counter = 1
sum_size = 0
try:
    for line in sys.stdin:
        aux = line.split()
        if len(aux) > 2:
            status_code = aux[-2]
            file_size = int(aux[-1])
            sum_size += file_size
            if status_code in input:
                input[status_code] += 1
            if counter % 10 == 0:
                print("File size: {}".format(sum_size))
                for key, value in input.items():
                    if input[key] != 0:
                        print("{}: {}".format(key, value))
        counter += 1
except KeyboardInterrupt:
    print("File size: {}".format(sum_size))
    for key, value in input.items():
        if input[key] != 0:
            print("{}: {}".format(key, value))
    raise

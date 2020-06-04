#!/usr/bin/python3
"""Log Parse"""
import sys

import sys

counter = 1
sum_size = 0

code = {'200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0}

try:
    for line in sys.stdin:
        ln = line.split()

        if len(ln) > 2:
            status = ln[-2]
            size = int(ln[-1])
            sum_size += size
            if status in code:
                code[status] += 1

        if counter % 10 == 0:
            print("File size: {}".format(sum_size))
            for key in sorted(code.keys()):
                if code[key] != 0:
                    print("{}: {}".format(key, code[key]))

        counter += 1

except Exception:
    pass

finally:
    print("File size: {}".format(sum_size))
    for key in sorted(code.keys()):
        if code[key] != 0:
            print("{}: {}".format(key, code[key]))

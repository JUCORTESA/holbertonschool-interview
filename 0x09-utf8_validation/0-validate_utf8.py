#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    Args:
            data: The data will be represented by a list of integers
    Returns: True if data is a valid UTF-8 encoding, else return False
    """

    num_bytes = 0

    # 1000 0000
    mask1 = 1 << 7

    # 0100 0000
    mask2 = 1 << 6
    for num in data:
        # 1000 0000
        mask = 1 << 7
        if num_bytes == 0:
            # 1000 0000 & 0100 0001
            while mask & num:
                num_bytes += 1
                mask = mask >> 1

            if num_bytes == 0:
                continue

            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False
        num_bytes -= 1
    return num_bytes == 0

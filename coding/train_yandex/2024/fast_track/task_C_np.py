import sys

from typing import List
import math


def Build_SparseTable_max(array: List[int], sparse_table: List[List[int]]):
    rows = len(array)
    cols = len(sparse_table[0])
    # Fill base case values
    for r in range(rows):
        sparse_table[r][0] = array[r]
    for c in range(1, cols + 1):
        _range = (1 << c)
        r = 0
        while (r + _range <= rows):
            # Values in the current column are derived from the
            # values in the previous column.
            sparse_table[r][c] = max(
                sparse_table[r][c - 1],
                sparse_table[r + (1 << (c - 1))][c - 1]
            )
            r += 1


def RMQ_max(left: int, right: int, sparse_table: List[List[int]]):
    # Find the biggest block of size 2^p that fits in the range (left) ... (right).
    power_of_2 = int(math.log2(right + 1 - left))
    x = right + 1 - (1 << power_of_2)
    if (sparse_table[left][power_of_2] >= sparse_table[right + 1 - (1 << power_of_2)][power_of_2]):
        return sparse_table[left][power_of_2]
    else:
        return sparse_table[right + 1 - (1 << power_of_2)][power_of_2]


def Build_SparseTable(array: List[int], sparse_table: List[List[int]]):
    rows = len(array)
    cols = len(sparse_table[0])
    # Fill base case values
    for r in range(rows):
        sparse_table[r][0] = array[r]
    for c in range(1, cols + 1):
        _range = (1 << c)
        r = 0
        while (r + _range <= rows):
            # Values in the current column are derived from the
            # values in the previous column.
            sparse_table[r][c] = min(
                sparse_table[r][c - 1],
                sparse_table[r + (1 << (c - 1))][c - 1]
            )
            r += 1


def RMQ(left: int, right: int, sparse_table: List[List[int]]):
    # Find the biggest block of size 2^p that fits in the range (left) ... (right).
    power_of_2 = int(math.log2(right + 1 - left))
    x = right + 1 - (1 << power_of_2)
    if (sparse_table[left][power_of_2] <= sparse_table[right + 1 - (1 << power_of_2)][power_of_2]):
        return sparse_table[left][power_of_2]
    else:
        return sparse_table[right + 1 - (1 << power_of_2)][power_of_2]


def main():
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    # Calculate the column size required for creating the sparse table
    # Columns = log2 (number_count) + 1
    sz = math.ceil(math.log2(len(array))) + 1
    # Create a sparse table of size [number_count][ceil ( log2 (number_count)) + 1]
    sparse_table = [0] * len(array)
    for i in range(len(array)):
        sparse_table[i] = [0] * sz

    Build_SparseTable(array, sparse_table)

    sparse_table_max = [0] * len(array)
    for i in range(len(array)):
        sparse_table_max[i] = [0] * sz
    Build_SparseTable_max(array, sparse_table_max)

    b = int(sys.stdin.readline())
    ans = []
    for _ in range(b):
        t_min, t_max, d_min, d_max = list(map(int, sys.stdin.readline().split()))
        left = n + d_min
        right = n + d_max
        min_temp = RMQ(left, right + 1, sparse_table)
        max_temp = RMQ_max(left, right + 1, sparse_table_max)
        low = t_min > max_temp
        high = min_temp > t_max
        if low or high:
            ans.append("no")
            # sys.stdout.write("no\n")
        else:
            ans.append("yes")
            # sys.stdout.write("yes\n")

    sys.stdout.write("\n".join(ans))


if __name__ == '__main__':
    main()

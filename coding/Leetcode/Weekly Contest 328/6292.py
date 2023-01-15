# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        import numpy as np
        matrix = np.zeros((n, n), dtype=int)
        for q in queries:
            row1, col1, row2, col2 = q
            matrix[row1: row2 + 1, col1: col2 + 1] += 1
        mat = matrix.tolist()
        return mat


def read_data():
    n = int(input())
    m = int(input())

    queries = []
    for _ in range(m):
        nums = list(map(int, input().split(",")))
        queries.append(nums)
    return n, queries

def main():
    n, queries = read_data()
    solve = Solution()
    print(solve.rangeAddQueries(n, queries))

if __name__ == "__main__":
    main()
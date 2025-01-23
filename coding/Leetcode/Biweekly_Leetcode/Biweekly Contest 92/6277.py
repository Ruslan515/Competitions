# https://leetcode.com/contest/biweekly-contest-89/problems/range-product-queries-of-powers/
from typing import List

class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        import numpy as np
        grid_np = np.array(grid)
        m = grid_np.shape[0]
        n = grid_np.shape[1]
        diff = grid.copy()

        onesRowS = grid_np.sum(axis=1)
        onesColS = grid_np.sum(axis=0)
        zerosRowS = n - onesRowS
        zerosColS = m - onesColS

        for i in range(m):
            for j in range(n):
                diff[i][j] = onesRowS[i] + onesColS[j] - zerosRowS[i] - zerosColS[j]


        return diff


def read_data():
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    queries = [list(map(int, el.split(","))) for el in s]
    return queries

def main():
    queries = read_data()
    sol = Solution()
    print(sol.onesMinusZeros(queries))

if __name__ == "__main__":
    main()
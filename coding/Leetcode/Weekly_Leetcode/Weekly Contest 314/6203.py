# https://leetcode.com/contest/weekly-contest-314/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
from typing import List

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        mod = 10 ** 9 + 7
        n, m = len(grid), len(grid[0])
        dp = [[[0] * k for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    dp[i][j][grid[i][j] % k] = 1
                    continue
                for u in range(k):
                    if i == 0:
                        dp[i][j][u] = dp[i][j - 1][(u + k * 100 - grid[i][j]) % k]
                    elif j == 0:
                        dp[i][j][u] = dp[i - 1][j][(u + k * 100 - grid[i][j]) % k]
                    else:
                        dp[i][j][u] = dp[i][j - 1][(u + k * 100 - grid[i][j]) % k] + dp[i - 1][j][(u + k * 100 - grid[i][j]) % k]
                    dp[i][j][u] %= mod
        return dp[-1][-1][0]

def read_data():
    k = int(input())
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    grid = [list(map(int, el.split(","))) for el in s]
    return k, grid

def main():
    k, grid = read_data()
    sol = Solution()
    print(sol.numberOfPaths(grid, k))

if __name__ == "__main__":
    main()
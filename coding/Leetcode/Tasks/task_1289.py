# https://leetcode.com/problems/minimum-falling-path-sum-ii/description/?envType=daily-question&envId=2024-04-26
from typing import List, Optional


class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        answer = float('inf')
        n = len(grid)
        if n == 1:
            return grid[0][0]
        dp = [[0] * n for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(n):
                # dp[i][j]
                tmp_min = float('inf')
                for k in range(n):
                    if k != j:
                        tmp_min = min(tmp_min, dp[i - 1][k])
                dp[i][j] = tmp_min + grid[i - 1][j]

        for j in range(n):
            answer = min(answer, dp[n][j])

        return answer


def main():
    solve = Solution()

    grid = [[7]]
    answer = 7
    assert answer == solve.minFallingPathSum(grid)

    grid = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    answer = 13
    assert answer == solve.minFallingPathSum(grid)


if __name__ == "__main__":
    main()

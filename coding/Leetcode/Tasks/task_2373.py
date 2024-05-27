# https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
from typing import List, Optional


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        answer = []
        n = len(grid)
        for i in range(n - 2):
            t = []
            for j in range(n - 2):
                m = max(
                    [
                        max(grid[i][j:j + 3]),
                        max(grid[i + 1][j:j + 3]),
                        max(grid[i + 2][j:j + 3]),
                    ]
                )

                t.append(m)
            answer.append(t)

        return answer


def main():
    solve = Solution()

    grid = [
        [20, 8, 20, 6, 16, 16, 7, 16, 8, 10],
        [12, 15, 13, 10, 20, 9, 6, 18, 17, 6],
        [12, 4, 10, 13, 20, 11, 15, 5, 17, 1],
        [7, 10, 14, 14, 16, 5, 1, 7, 3, 11],
        [16, 2, 9, 15, 9, 8, 6, 1, 7, 15],
        [18, 15, 18, 8, 12, 17, 19, 7, 7, 8],
        [19, 11, 15, 16, 1, 3, 7, 4, 7, 11],
        [11, 6, 5, 14, 12, 18, 3, 20, 14, 6],
        [4, 4, 19, 6, 17, 12, 8, 8, 18, 8],
        [19, 15, 14, 11, 11, 13, 12, 6, 16, 19]
    ]
    answer = [
        [20, 20, 20, 20, 20, 18, 18, 18],
        [15, 15, 20, 20, 20, 18, 18, 18],
        [16, 15, 20, 20, 20, 15, 17, 17],
        [18, 18, 18, 17, 19, 19, 19, 15],
        [19, 18, 18, 17, 19, 19, 19, 15],
        [19, 18, 18, 18, 19, 20, 20, 20],
        [19, 19, 19, 18, 18, 20, 20, 20],
        [19, 19, 19, 18, 18, 20, 20, 20]
    ]
    assert answer == solve.largestLocal(grid)

    grid = [
        [9, 9, 8, 1], [5, 6, 2, 6], [8, 2, 6, 4], [6, 2, 2, 2]
    ]
    answer = [[9, 9], [8, 6]]
    assert answer == solve.largestLocal(grid)

    grid = [[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 2, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]
    answer = [[2, 2, 2], [2, 2, 2], [2, 2, 2]]
    assert answer == solve.largestLocal(grid)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/number-of-islands-ii/description/?envType=weekly-question&envId=2024-04-22
from typing import List, Optional


class Solution:
    diff = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        answer = []
        grid = [[0 for _ in range(n)] for _ in range(m)]
        count_islands = 0
        for y, x in positions:
            grid[y][x] = 1
            label = True
            for dx, dy in self.diff:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    if grid[ny][nx] == 1:
                        label = False
                        break
            if label:
                count_islands += 1
            answer.append(count_islands)

        return answer


def main():
    solve = Solution()

    m = 2
    n = 2
    positions = [[0, 0], [1, 1], [0, 1]]
    answer = [1, 2, 1]
    assert answer == solve.numIslands2(m, n, positions)

    m = 3
    n = 3
    positions = [[0, 0], [0, 1], [1, 2], [2, 1]]
    answer = [1, 1, 2, 3]
    assert answer == solve.numIslands2(m, n, positions)

    m = 1
    n = 1
    positions = [[0, 0]]
    answer = [1]
    assert answer == solve.numIslands2(m, n, positions)


if __name__ == "__main__":
    main()

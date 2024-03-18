# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18
from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        answer = 0
        f = lambda x: x[1]
        points.sort(key=f)
        i = 0
        n = len(points)
        while i < n:
            second = points[i][1]
            j = i
            answer += 1
            while j < n and points[j][0] <= second:
                j += 1
            i = j

        return answer


def main():
    solve = Solution()

    points = [[10, 16], [2, 8], [1, 6], [7, 12]]
    answer = 2
    assert answer == solve.findMinArrowShots(points)

    points = [[1, 2], [3, 4], [5, 6], [7, 8]]
    answer = 4
    assert answer == solve.findMinArrowShots(points)

    points = [[1, 2], [2, 3], [3, 4], [4, 5]]
    answer = 2
    assert answer == solve.findMinArrowShots(points)

    points = [
        [3, 9], [7, 12], [3, 8], [6, 8], [9, 10], [2, 9], [0, 9], [3, 9], [0, 6], [2, 8]
    ]
    answer = 2
    assert answer == solve.findMinArrowShots(points)


if __name__ == "__main__":
    main()

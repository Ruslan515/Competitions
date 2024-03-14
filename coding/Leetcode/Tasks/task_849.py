# https://leetcode.com/problems/maximize-distance-to-closest-person/description/

from typing import List, Optional


class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        answer = 0
        n = len(seats)
        left = 0
        right = 0
        while right < n:
            while right < n and seats[right] == 0:
                right += 1
            check1 = left == 0 and right != 0
            check2 = left != 0 and right == n
            check = check1 or check2
            if check:
                answer = max(answer, right - left)
            else:
                dist = right - left
                d = dist // 2
                l = dist % 2
                x = d + l
                answer = max(answer, x)
            while right < n and seats[right] == 1:
                right += 1
            left = right

        return answer


def main():
    solve = Solution()

    seats = [1, 0, 0, 0]
    answer = 3
    assert answer == solve.maxDistToClosest(seats)

    seats = [1, 0, 0, 0, 1, 0, 1]
    answer = 2
    assert answer == solve.maxDistToClosest(seats)

    seats = [0, 1]
    answer = 1
    assert answer == solve.maxDistToClosest(seats)


if __name__ == "__main__":
    main()

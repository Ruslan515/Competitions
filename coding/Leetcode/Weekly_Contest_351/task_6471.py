# https://leetcode.com/contest/weekly-contest-351/problems/minimum-operations-to-make-the-integer-zero/
from typing import List


class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for i in range(61):
            diff = num1 - (2 ** i + num2)
            if diff == 0:
                return i + 1
        return -1


if __name__ == "__main__":
    solve = Solution()

    num1 = 3
    num2 = -2
    answer = 3
    assert answer == solve.makeTheIntegerZero(num1, num2)

    num1 = 5
    num2 = 7
    answer = -1
    assert answer == solve.makeTheIntegerZero(num1, num2)

# https://leetcode.com/problems/ipo/
from typing import List, Optional

from collections import defaultdict
import queue


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        answer: int = 0

        return answer


def main():
    solve = Solution()

    k = 1
    w = 10
    profits = [1, 2, 3]
    capital = [0, 0, 0]
    answer = 13
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 1
    w = 2
    profits = [1, 2, 3]
    capital = [1, 1, 2]
    answer = 5
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 3
    w = 0
    profits = [1, 2, 3]
    capital = [0, 1, 2]
    answer = 6
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 2
    w = 0
    profits = [1, 2, 3]
    capital = [0, 1, 1]
    answer = 4
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)


if __name__ == "__main__":
    main()

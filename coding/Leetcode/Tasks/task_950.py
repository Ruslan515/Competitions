# https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08
from typing import List, Optional


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        answer = [0 for _ in range(n)]

        size = n // 2 + n % 2
        for i in range(size):
            idx = 2 * i
            x = deck[i]
            answer[idx] = x

        for i in range(size - n % 2):
            idx = n - (2 * i + 1) - 1
            x = deck[size + i]
            answer[idx] = x

        return answer


def main():
    solve = Solution()

    deck = [17, 13, 11, 2, 3, 5, 7]
    answer = [2, 13, 3, 11, 5, 17, 7]
    assert answer == solve.deckRevealedIncreasing(deck)

    deck = [1, 1000]
    answer = [1, 1000]
    assert answer == solve.deckRevealedIncreasing(deck)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04
from typing import List, Optional


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        answer: int = 0
        tokens.sort()
        left: int = 0
        right: int = len(tokens) - 1
        while left <= right:
            if tokens[left] <= power:
                power -= tokens[left]
                answer += 1
                left += 1
            elif answer >= 1 and left != right:
                power += tokens[right]
                answer -= 1
                right -= 1
            else:
                break

        return answer


def main():
    solve = Solution()

    tokens = [200, 100]
    power = 150
    answer = 1
    assert answer == solve.bagOfTokensScore(tokens, power)

    tokens = [100, 200, 300, 400]
    power = 200
    answer = 2
    assert answer == solve.bagOfTokensScore(tokens, power)

    tokens = [100]
    power = 50
    answer = 0
    assert answer == solve.bagOfTokensScore(tokens, power)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
from typing import List, Optional


class Solution:
    def minimumLength(self, s: str) -> int:
        answer: int = 0
        n: int = len(s)
        if n == 1:
            return 1
        left: int = 0
        right: int = n - 1

        while left < right:
            sym_left = s[left]
            sym_right = s[right]
            if sym_left == sym_right:
                while left < n and s[left] == sym_left:
                    left += 1
                while right >= 0 and s[right] == sym_right:
                    right -= 1
                if right < left:
                    return answer
            else:
                break
        answer = right - left + 1

        return answer


def main():
    solve = Solution()

    x = "b"
    s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"
    answer = 1
    assert answer == solve.minimumLength(s)

    s = "ca"
    answer = 2
    assert answer == solve.minimumLength(s)

    s = "a"
    answer = 1
    assert answer == solve.minimumLength(s)

    s = "aa"
    answer = 0
    assert answer == solve.minimumLength(s)

    s = "aaa"
    answer = 0
    assert answer == solve.minimumLength(s)

    s = "cabaabac"
    answer = 0
    assert answer == solve.minimumLength(s)

    s = "aabccabba"
    answer = 3
    assert answer == solve.minimumLength(s)


if __name__ == "__main__":
    main()

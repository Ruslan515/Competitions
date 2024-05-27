# https://leetcode.com/problems/destroying-asteroids/
from typing import List, Optional


class Solution:
    def maximum69Number(self, num: int) -> int:
        answer = num
        s = str(num)
        for i in range(len(s)):
            if s[i] == '6':
                answer = int(s[:i] + "9" + s[i + 1:])
                break

        return answer


def main():
    solve = Solution()

    num = 9669
    answer = 9969
    assert answer == solve.maximum69Number(num)

    num = 9996
    answer = 9999
    assert answer == solve.maximum69Number(num)

    num = 9999
    answer = 9999
    assert answer == solve.maximum69Number(num)


if __name__ == "__main__":
    main()

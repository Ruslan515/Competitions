# https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03
from typing import List, Optional

import queue


class Solution:
    def maxDepth(self, s: str) -> int:
        from collections import deque
        open_symbol = "("
        close_symbol = ")"
        answer = 0
        dq = deque()
        temp_depth = 0
        for ch in s:
            if ch == open_symbol:
                dq.append(ch)
                temp_depth += 1
            elif ch == close_symbol:
                dq.pop()
                answer = max(answer, temp_depth)
                temp_depth -= 1

        return answer


def main():
    solve = Solution()

    s = "(1+(2*3)+((8)/4))+1"
    answer = 3
    assert answer == solve.maxDepth(s)

    s = "(1)+((2))+(((3)))"
    answer = 3
    assert answer == solve.maxDepth(s)


if __name__ == "__main__":
    main()

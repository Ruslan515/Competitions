# https://leetcode.com/problems/make-the-string-great/?envType=daily-question&envId=2024-04-05
from typing import List, Optional

import queue


class Solution:
    def makeGood(self, s: str) -> str:
        from collections import deque
        dq = deque()
        for ch in s:
            if dq:
                prev = dq.pop()
                diff = abs(ord(ch) - ord(prev))
                if diff != 32:
                    dq.append(prev)
                    dq.append(ch)
            else:
                dq.append(ch)
        answer = ""
        while dq:
            answer += dq.popleft()
        return answer


def main():
    solve = Solution()

    s = "abBAcC"
    answer = ""
    assert answer == solve.makeGood(s)

    s = "leEeetcode"
    answer = "leetcode"
    assert answer == solve.makeGood(s)

    s = "s"
    answer = "s"
    assert answer == solve.makeGood(s)


if __name__ == "__main__":
    main()

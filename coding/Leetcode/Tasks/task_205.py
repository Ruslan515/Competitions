# https://leetcode.com/problems/ipo/
from typing import List, Optional


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        answer = False
        n = len(s)
        m = len(t)
        if n != m:
            return answer
        answer = True
        s_to_t = {}
        t_to_s = {}
        for x, y in zip(s, t):
            # s_to_t
            if x in s_to_t.keys():
                val = s_to_t[x]
                if y != val:
                    answer = False
                    break
            else:
                s_to_t[x] = y

            if y in t_to_s.keys():
                val = t_to_s[y]
                if val != x:
                    answer = False
                    break
            else:
                    t_to_s[y] = x

        return answer


def main():
    solve = Solution()

    s = "badc"
    t = "baba"
    answer = False
    assert answer == solve.isIsomorphic(s, t)

    s = "egg"
    t = "add"
    answer = True
    assert answer == solve.isIsomorphic(s, t)

    s = "foo"
    t = "bar"
    answer = False
    assert answer == solve.isIsomorphic(s, t)

    s = "paper"
    t = "title"
    answer = True
    assert answer == solve.isIsomorphic(s, t)


if __name__ == "__main__":
    main()

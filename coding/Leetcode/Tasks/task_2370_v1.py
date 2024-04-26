# https://leetcode.com/problems/longest-ideal-subsequence/?envType=daily-question&envId=2024-04-25
from typing import List, Optional


class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        answer = 0
        n = len(s)
        dp = [0 for _ in range(n + 1)]
        d = dict()
        for ch in range(ord('a'), ord('z') + 1):
            d[ch] = 0
        for i, chr in enumerate(s):
            ch = ord(chr)
            tmp_max = 0
            if d[ch] != 0:
                for j in range(min(97, ch - k), min(122, ch + k)):
                    tmp = d[j]



            dp[i] = tmp_max + 1
            answer = max(answer, dp[i])

        return answer


def main():
    solve = Solution()

    s = "acfgbd"
    k = 2
    answer = 4
    assert answer == solve.longestIdealString(s, k)

    s = "abcd"
    k = 3
    answer = 4
    assert answer == solve.longestIdealString(s, k)


if __name__ == "__main__":
    main()

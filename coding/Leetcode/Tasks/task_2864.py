# https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

from typing import List, Optional


class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        mp = {}
        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1
        answer = "1"
        mp["1"] -= 1
        for key in ["0", "1"]:
            if mp.get(key) is not None:
                answer = "".join([key for _ in range(mp[key])]) + answer

        return answer


def main():
    solve = Solution()

    s = "1"
    answer = "1"
    assert answer == solve.maximumOddBinaryNumber(s)

    s = "010"
    answer = "001"
    assert answer == solve.maximumOddBinaryNumber(s)

    s = "0101"
    answer = "1001"
    assert answer == solve.maximumOddBinaryNumber(s)


if __name__ == "__main__":
    main()

# https://leetcode.com/contest/biweekly-contest-93/problems/maximum-value-of-a-string-in-an-array/
from typing import List

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        import re
        global_max = 0
        for s in strs:
            # set_s = set(s)
            # digit_in_s = any(char.isdigit() for char in set_s)
            char_in_s = re.search("[a-zA-Z]", s)
            if char_in_s:
                l = len(s)
            else:
                l = int(s)
            if l > global_max:
                global_max = l

        return global_max


def read_data():
    strs = input().split(" ")
    return strs

def main():
    strs = read_data()
    sol = Solution()
    print(sol.maximumValue(strs))

if __name__ == "__main__":
    main()
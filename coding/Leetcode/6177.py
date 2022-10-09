# https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/
from typing import List

class Solution:
    def partitionString(self, s: str) -> int:
        count = 0
        start_idx = 0
        while start_idx < len(s):
            new_s = s[start_idx]
            while start_idx + 1 < len(s) and s[start_idx + 1] not in new_s:
                start_idx += 1
                new_s += s[start_idx]
            start_idx += 1
            count += 1

        return count

def read_data():
    s = input()
    return s


def main():
    s = read_data()
    sol = Solution()
    print(sol.partitionString(s))

if __name__ == "__main__":
    main()
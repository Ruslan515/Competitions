# https://leetcode.com/contest/biweekly-contest-85/problems/shifting-letters-ii/
from typing import List
class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(shifts)
        for i in range(n):
            start_idx = shifts[i][0]
            end_idx = shifts[i][1]
            mn = 1 if shifts[i][2] == 1 else - 1
            for idx in range(start_idx, end_idx + 1):
                temp = chr((ord(s[idx]) % 97 + mn) % 26 + 97)
                s = s[:idx] + temp + s[idx + 1:]

        return s

def read_data():
    s = input()
    n = int(input())
    shifts = []
    for i in range(n):
        shifts.append(list(map(int, input().split())))
    return s, shifts


def main():
    s, shifts = read_data()
    sol = Solution()
    print(sol.shiftingLetters(s, shifts))

if __name__ == "__main__":
    main()
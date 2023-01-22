# https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/
from typing import List

class Solution:
    def alternateDigitSum(self, n: int) -> int:
        ans = 0
        digits = str(n)
        sum_digits = 0
        for i, d in enumerate(digits):
            sum_digits += int(d) * (-1)**i
        ans = sum_digits

        return ans

def read_data():
    n = int(input())
    return n

def main():
    n = read_data()
    solve = Solution()
    print(solve.alternateDigitSum(n))

if __name__ == "__main__":
    main()
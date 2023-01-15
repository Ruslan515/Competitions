# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        answer = 0
        sum_els = sum(nums)

        sum_digits = 0
        for num in nums:
            while num != 0:
                digit = num % 10
                sum_digits += digit
                num //= 10
        answer = abs(sum_els - sum_digits)
        return answer


def read_data():
    nums = list(map(int, input().split()))
    return nums

def main():
    nums = read_data()
    solve = Solution()
    print(solve.differenceOfSum(nums))

if __name__ == "__main__":
    main()
# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        answer = -1
        n = len(nums)
        nums = sorted(nums)
        dp = [0] * (n)
        dp[0] = 1
        global_max = dp[0]
        for i in range(1, n):
            max_dp = 0
            for j in range(i):
                if nums[j]**2 == nums[i] and max_dp < dp[j]:
                    max_dp = dp[j]
            dp[i] = max_dp + 1
            global_max = max(global_max, dp[i])
        if global_max != 1:
            answer = global_max
        return answer


def read_data():
    nums = list(map(int, input().split()))
    return nums

def main():
    nums = read_data()
    sol = Solution()
    print(sol.longestSquareStreak(nums))

if __name__ == "__main__":
    main()
# https://leetcode.com/contest/weekly-contest-351/problems/ways-to-split-array-into-good-subarrays/
from typing import List


class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        MOD = 10 ** 9 + 7
        prev_one = -1

        for i in range(n):
            if nums[i] == 0:
                dp[i] = dp[i - 1]
            else:
                if prev_one == -1:
                    dp[i] = (i + 1) // 2
                else:
                    j = prev_one
                    while j >= 0 and i - j + 1 <= 2 * (j - prev_one) + 1:
                        dp[i] = (dp[i] + dp[j - 1]) % MOD
                        j -= 1
                prev_one = i

        return dp[n - 1]

if __name__ == "__main__":
    solve = Solution()

    nums = [0, 1, 0, 0, 1]
    answer = 3
    assert answer == solve.numberOfGoodSubarraySplits(nums)

    nums = [0, 1, 0]
    answer = 1
    assert answer == solve.numberOfGoodSubarraySplits(nums)

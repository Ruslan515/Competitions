from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        answer = 0
        n = len(nums)

        dp = [0 for i in range(n + 1)]
        for i in range(1, n + 1):
            val = nums[i - 1]
            for j in range(i - 1):
                dp[i] = max(dp[i], dp[j])
            dp[i] += val
            answer = max(answer, dp[i])

        return answer


def main():
    solve = Solution()

    nums = [1, 2, 3, 1]
    answer = 4
    assert answer == solve.rob(nums=nums)

    nums = [2, 7, 9, 3, 1]
    answer = 12
    assert answer == solve.rob(nums=nums)


if __name__ == "__main__":
    main()

from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for _ in range(n)]
        dp[0] = 1
        answer = dp[0]

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j])
            dp[i] += 1
            answer = max(answer, dp[i])

        return answer


def main():
    solve = Solution()

    nums = [0]
    answer = 1
    assert answer == solve.lengthOfLIS(nums)

    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    answer = 4
    assert answer == solve.lengthOfLIS(nums)

    nums = [0, 1, 0, 3, 2, 3]
    answer = 4
    assert answer == solve.lengthOfLIS(nums)

    nums = [7, 7, 7, 7, 7, 7, 7]
    answer = 1
    assert answer == solve.lengthOfLIS(nums)


if __name__ == "__main__":
    main()

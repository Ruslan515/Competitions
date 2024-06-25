# https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08
from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        answer = False
        n = len(nums)
        if n == 1:
            return answer

        prefix_sum = []
        curr_sum = 0
        for i, num in enumerate(nums):
            curr_sum += num
            prefix_sum.append(curr_sum)

        for i in range(n - 1):
            for j in range(i + 1, n):
                diff = prefix_sum[j] - prefix_sum[i] + nums[i]
                if diff % k == 0:
                    answer = True
                    break
            if answer:
                break

        return answer


def main():
    solve = Solution()

    nums = [1, 2, 3]
    k = 5
    answer = True
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [0, 1, 0, 3, 0, 4, 0, 4, 0]
    k = 5
    answer = False
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [0]
    k = 1
    answer = False
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [5, 0, 0, 0]
    k = 3
    answer = True
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [23, 2, 4, 6, 7]
    k = 6
    answer = True
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [23, 2, 6, 4, 7]
    k = 6
    answer = True
    assert answer == solve.checkSubarraySum(nums, k)

    nums = [23, 2, 6, 4, 7]
    k = 13
    answer = False
    assert answer == solve.checkSubarraySum(nums, k)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
from typing import List, Optional


class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        answer: int = 0
        nums.sort()
        left = 0
        right = 0
        n = len(nums)
        while right < n:
            while right < n and nums[right] - nums[left] <= k:
                right += 1
            answer += 1
            if right < n:
                left = right

        return answer


def main():
    solve = Solution()

    nums = [3, 6, 1, 2, 5]
    k = 2
    answer = 2
    assert answer == solve.partitionArray(nums, k)

    nums = [1, 2, 3]
    k = 1
    answer = 2
    assert answer == solve.partitionArray(nums, k)

    nums = [2, 2, 4, 5]
    k = 0
    answer = 3
    assert answer == solve.partitionArray(nums, k)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14
from typing import List, Optional


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        answer = 0
        left: int = -1
        right: int = -1
        prev_left = 0
        pref_right = 0
        n = len(nums)
        sums = 0
        while right < n:
            while right < n and sums < goal:
                right += 1
                sums += nums[right]
            while left < n and sums == goal:
                left += 1
                sums += nums[left]
            count_left = left - prev_left
            if count_left > 0 :
                count_left += 1
            count_right = 0

            right += 1
            while right < n and nums[right] == 0:
                count_right += 1
                right += 1



        return answer


def main():
    solve = Solution()

    nums = [1, 0, 1, 0, 1]
    goal = 2
    answer = 4
    assert answer == solve.numSubarraysWithSum(nums=nums, goal=goal)

    nums = [0, 0, 0, 0, 0]
    goal = 0
    answer = 15
    assert answer == solve.numSubarraysWithSum(nums=nums, goal=goal)


if __name__ == "__main__":
    main()

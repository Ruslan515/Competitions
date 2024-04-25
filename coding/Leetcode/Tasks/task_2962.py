# https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26
from typing import List, Optional


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        answer = 0
        n = len(nums)
        left = 0
        right = 0
        

        return answer


def main():
    solve = Solution()

    nums = [1, 3, 2, 3, 3]
    k = 2
    answer =  6
    assert answer == solve.countSubarrays(nums, k)

    nums = [1, 4, 2, 1]
    k = 3
    answer =  0
    assert answer == solve.countSubarrays(nums, k)


if __name__ == "__main__":
    main()

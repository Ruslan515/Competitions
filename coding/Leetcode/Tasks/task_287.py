# https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        answer = 0
        slow = nums[0]
        fast = nums[0]
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow


def main():
    solve = Solution()

    nums = [2, 5, 9, 6, 9, 3, 8, 9, 7, 1]
    answer = 9
    assert answer == solve.findDuplicate(nums)

    nums = [1, 3, 4, 2, 2]
    answer = 2
    assert answer == solve.findDuplicate(nums)

    nums = [3, 3, 3, 3, 2]
    answer = 3
    assert answer == solve.findDuplicate(nums)

    nums = [3, 3, 3, 3, ]
    answer = 3
    assert answer == solve.findDuplicate(nums)

    nums = [3, 3, 3, 3, 3]
    answer = 3
    assert answer == solve.findDuplicate(nums)

    nums = [3, 1, 3, 4, 2]
    answer = 3
    assert answer == solve.findDuplicate(nums)


if __name__ == "__main__":
    main()

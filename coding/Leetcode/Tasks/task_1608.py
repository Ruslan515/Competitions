# https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
from typing import List


class Solution:
    def specialArray(self, nums: List[int]) -> int:
        answer = -1
        nums.sort()
        n = len(nums)
        for x in range(n + 1):
            i = 0
            while i < n and nums[i] < x:
                i += 1
            diff = n - i
            if diff == x:
                answer = x
                break

        return answer


def main():
    solve = Solution()

    nums = [0, 4, 3, 0, 4]
    answer = 3
    assert answer == solve.specialArray(nums)

    nums = [3, 5]
    answer = 2
    assert answer == solve.specialArray(nums)

    nums = [0, 0]
    answer = -1
    assert answer == solve.specialArray(nums)


if __name__ == "__main__":
    main()

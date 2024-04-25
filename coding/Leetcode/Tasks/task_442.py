# https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25
from typing import List, Optional


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        my_set = set()
        answer = []
        for num in nums:
            if num in my_set:
                answer.append(num)
            else:
                my_set.add(num)
        return answer


def main():
    solve = Solution()

    nums = [4, 3, 2, 7, 8, 2, 3, 1]
    answer = [2, 3]
    assert answer == solve.findDuplicates(nums)

    nums = [1, 1, 2]
    answer = [1]
    assert answer == solve.findDuplicates(nums)

    nums = [1]
    answer = []
    assert answer == solve.findDuplicates(nums)


if __name__ == "__main__":
    main()

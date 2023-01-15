# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        my_set = sorted(list(set(nums)))
        nums[:] = my_set
        print(len(nums), nums)
        return len(nums)


if __name__ == "__main__":
    nums = [1,1,2]
    s = Solution()
    k = s.removeDuplicates(nums)
    print(len(nums), nums)
# https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30
from typing import List, Optional


class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        answer = 0
        d = {}
        start = 0
        for num in nums:
            x1 = num not in d.keys() and len(d.keys() < k)
            x2 = num in d.keys() and len(d.keys() == k)
            if x1 or x2:
                d[num] = d.get(num, 0) + 1
            elif num not in d.keys() and len(d.keys()) == k:
                pass
            keys = d.keys()
            if len(keys) == k:
                pass
            
        return answer


def main():
    solve = Solution()

    nums = [1, 2, 1, 2, 3]
    k = 2
    Output: 7
    assert answer == solve.subarraysWithKDistinct(nums, k)

    nums = [1, 2, 1, 2, 3]
    k = 2
    Output: 7
    assert answer == solve.subarraysWithKDistinct(nums, k)


if __name__ == "__main__":
    main()

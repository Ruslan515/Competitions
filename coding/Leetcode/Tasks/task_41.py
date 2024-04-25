# https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26
from typing import List, Optional

from heapq import *


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        answer = 0
        set_nums = set()
        for num in nums:
            if num > 0:
                set_nums.add(num)
        if len(set_nums) == 0:
            answer = 1
            return answer
        min_num = min(set_nums)
        if min_num > 1:
            answer = 1
        else:
            n = len(set_nums)
            heap = list(set_nums)
            heapify(heap)
            prev = 0
            for i in range(n):
                current = heappop(heap)
                diff = current - prev
                if diff > 1:
                    answer = prev + 1
                    return answer
                prev = current
            answer = current + 1

        return answer


def main():
    solve = Solution()

    nums = [3, 4, -1, 1]
    answer = 2
    assert answer == solve.firstMissingPositive(nums)

    nums = [1, 2, 0]
    answer = 3
    assert answer == solve.firstMissingPositive(nums)

    nums = [7, 8, 9, 11, 12]
    answer = 1
    assert answer == solve.firstMissingPositive(nums)


if __name__ == "__main__":
    main()

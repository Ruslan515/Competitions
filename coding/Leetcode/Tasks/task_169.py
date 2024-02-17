# https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        answer = 0
        freq = {}
        max_freq = 0
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            if freq[num] > max_freq:
                answer = num
                max_freq = freq[num]

        return answer


def main():
    solve = Solution()

    nums = [3, 3, 4]
    answer = 3
    assert answer == solve.majorityElement(nums)

    nums = [3, 2, 3]
    answer = 3
    assert answer == solve.majorityElement(nums)

    nums = [2, 2, 1, 1, 1, 2, 2]
    answer = 2
    assert answer == solve.majorityElement(nums)


if __name__ == "__main__":
    main()

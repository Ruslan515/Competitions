# https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
from typing import List


class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        answer = -1
        prefix = []
        nums = sorted(nums)
        sum_prefix = 0
        for num in nums:
            prefix.append(sum_prefix + num)
            sum_prefix += num
        n: int = len(nums)

        for i in range(n - 1, 1, -1):
            if prefix[i - 1] > nums[i]:
                answer = prefix[i]
                break

        return answer


def main():
    solve = Solution()

    nums = [5, 5, 5]
    answer = 15
    assert answer == solve.largestPerimeter(nums)

    nums = [1, 12, 1, 2, 5, 50, 3]
    answer = 12
    assert answer == solve.largestPerimeter(nums)

    nums = [5, 5, 50]
    answer = -1
    assert answer == solve.largestPerimeter(nums)


if __name__ == "__main__":
    main()

# https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        dot_pref = 1
        dot_suff = 1
        prefix = []
        n = len(nums)
        suffix = [0 for _ in range(n)]

        for i in range(n):
            dot_pref *= nums[i]
            dot_suff *= nums[n - i - 1]
            prefix.append(dot_pref)
            suffix[n - i - 1] = dot_suff

        answer.append(suffix[1])
        for i in range(1, n - 1):
            answer.append(prefix[i - 1] * suffix[i + 1])
        answer.append(prefix[n - 2])
        return answer


def main():
    solve = Solution()

    nums = [1, 2, 3, 4]
    answer = [24, 12, 8, 6]
    assert answer == solve.productExceptSelf(nums)

    nums = [-1, 1, 0, -3, 3]
    answer = [0, 0, 9, 0, 0]
    assert answer == solve.productExceptSelf(nums)


if __name__ == "__main__":
    main()

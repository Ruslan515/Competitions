# https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

from typing import List, Optional


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        answer = -1
        i1 = 0
        i2 = 0
        n1 = len(nums1)
        n2 = len(nums2)
        while i1 < n1 and i2 < n2:
            if nums1[i1] == nums2[i2]:
                answer = nums1[i1]
                break
            elif nums1[i1] < nums2[i2]:
                i1 += 1
            else:
                i2 += 1

        return answer


def main():
    solve = Solution()

    nums1 = [1, 2, 3]
    nums2 = [2, 4]
    answer = 2
    assert answer == solve.getCommon(nums1, nums2)

    nums1 = [1, 2, 3, 6]
    nums2 = [2, 3, 4, 5]
    answer = 2
    assert answer == solve.getCommon(nums1, nums2)


if __name__ == "__main__":
    main()

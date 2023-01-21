# https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/
from typing import List

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        answer = -1
        set1 = set(nums1)
        set2 = set(nums2)
        set_intersect = set1.intersection(set2)
        if (len(set_intersect) != 0):
            answer = min(set_intersect)

        return answer


def read_data():
    nums1 = list(map(int, input().split(",")))
    nums2 = list(map(int, input().split(",")))
    return nums1, nums2

def main():
    nums1, nums2 = read_data()
    solve = Solution()
    print(solve.getCommon(nums1, nums2))

if __name__ == "__main__":
    main()
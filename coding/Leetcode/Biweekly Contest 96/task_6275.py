# https://leetcode.com/contest/biweekly-contest-96/problems/minimum-operations-to-make-array-equal-ii/
from typing import List

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        answer = -1
        if k == 0:
            return answer
        diff = [nums2[i] - nums1[i] for i in range(len(nums1))]
        if nums1 == nums2:
            return 0

        for d in diff:
            if d % k != 0:
                return answer
        diff_steps = [d // k for d in diff]
        step_i = 0
        step_j = 0
        for s in diff_steps:
            if s > 0:
                step_i += s
            elif s < 0:
                step_j += s

        if step_i == (-1) * step_j:
            diff_sums = [abs(d) // k for d in diff]
            sums = sum(diff_sums)
            answer = sums // 2

        return answer


def read_data():
    nums1 = list(map(int, input().split(",")))
    nums2 = list(map(int, input().split(",")))
    k = int(input())
    return nums1, nums2, k

def main():
    nums1, nums2, k = read_data()
    solve = Solution()
    print(solve.minOperations(nums1, nums2, k))

if __name__ == "__main__":
    main()
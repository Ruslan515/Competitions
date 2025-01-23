# https://leetcode.com/contest/biweekly-contest-96/problems/minimum-common-value/
from typing import List

class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        p = [[a, b] for (a, b) in zip(nums1, nums2)]
        p.sort(key=lambda x: x[1], reverse=True)
        stl = SortedList()
        res = 0
        cur = p[0][1]
        curs = 0
        for a, b in p:
            cur = min(cur, b)
            if len(stl) < k:
                curs += a
            else:
                u = stl[-k]
                if a > u:
                    curs += a - u
            stl.add(a)
            if len(stl) >= k:
                res = max(res, cur * curs)
        return res

        # from itertools import combinations
        #
        # list_idx = [i for i in range(len(nums1))]
        # max_score = -1
        # for comb in combinations(list_idx, k):
        #     sums = 0
        #     min_num = 1e5 + 1
        #     for idx in comb:
        #         sums += nums1[idx]
        #         min_num = min(min_num, nums2[idx])
        #
        #     score = sums * min_num
        #     max_score = max(max_score, score)
        #
        # return max_score


def read_data():
    nums1 = list(map(int, input().split(",")))
    nums2 = list(map(int, input().split(",")))
    k = int(input())
    return nums1, nums2, k

def main():
    nums1, nums2, k = read_data()
    solve = Solution()
    print(solve.maxScore(nums1, nums2, k))

if __name__ == "__main__":
    main()
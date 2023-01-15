# https://leetcode.com/contest/biweekly-contest-85/problems/shifting-letters-ii/
from typing import List
class Solution:
    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        for i in range(n):
            idx = removeQueries[i]
            nums[idx] = 0
            max_sum = 0
            start_idx = 0
            end_idx = 1
            while end_idx < n:
                while  start_idx < n and nums[start_idx] == 0 :
                    start_idx += 1
                end_idx = start_idx + 1
                while  end_idx < n and nums[end_idx] != 0:
                    end_idx += 1
                sum_seg = sum(nums[start_idx: end_idx])
                if sum_seg > max_sum:
                    max_sum = sum_seg
                start_idx = end_idx
            ans.append(max_sum)

        return ans

def read_data():
    nums = list(map(int, input().split()))
    removeQueries = list(map(int, input().split()))
    return nums, removeQueries


def main():
    nums, removeQueries = read_data()
    sol = Solution()
    print(", ".join(map(str, sol.maximumSegmentSum(nums, removeQueries))))

if __name__ == "__main__":
    main()
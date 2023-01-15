# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count = 0
        for l in range(n):
            for r in range(l + 1, n):
                temp_k = 0
                for i in range(l, r + 1):
                    for j in range(i + 1, r + 1):
                        x = nums[i]
                        y = nums[j]
                        if x == y:
                            temp_k += 1
                if temp_k >= k:
                    count += 1
        return count


def read_data():
    nums = list(map(int, input().split(",")))
    k = int(input())
    return nums, k

def main():
    nums, k = read_data()
    solve = Solution()
    print(solve.countGood(nums, k))

if __name__ == "__main__":
    main()
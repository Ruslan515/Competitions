# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        from collections import defaultdict
        import numpy as np

        answer = -1

        d = defaultdict(int)

        n = len(nums)
        nums = sorted(nums)
        my_sum = 0
        for i in range(n):
            x = nums[i]
            t = int(np.sqrt(x))
            if t**2 == x and t in d:
                d[x] = d[t] + 1
                if d[x] > answer:
                    answer = d[x]
            else:
                d[x] = 1


        return answer


def read_data():
    nums = list(map(int, input().split()))
    return nums

def main():
    nums = read_data()
    sol = Solution()
    print(sol.longestSquareStreak(nums))

if __name__ == "__main__":
    main()
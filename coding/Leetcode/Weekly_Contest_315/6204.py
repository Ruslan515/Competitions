# https://leetcode.com/contest/weekly-contest-315/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution:
    def findMaxK(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse=True)
        n = len(nums)
        set_list = set(nums)
        i = 0
        current_max = -1
        while True and i < n:
            current_max = nums[i]
            if (-1 * current_max) in set_list:
                break
            i += 1
        if i == n:
            current_max = -1
        return current_max



def read_data():
    k = int(input())
    nums = []
    for _ in range(k):
        nums.append(list(map(int, input().split())))
    return k, nums


def main():
    k, nums = read_data()
    sol = Solution()
    for nums_i in nums:
        print(sol.findMaxK(nums_i))

if __name__ == "__main__":
    main()
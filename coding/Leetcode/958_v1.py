# https://leetcode.com/problems/sum-of-even-numbers-after-queries/
# work
class Solution(object):
    def sum_even(self, nums):
        sum_e = 0
        for n in nums:
            if n % 2 == 0:
               sum_e += n
        return sum_e

    def sumEvenAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        sum_e = self.sum_even(nums)
        answer = []
        for val, idx in queries:
            even_val = val % 2 == 0
            even_nums = nums[idx] % 2 == 0
            if even_val and even_nums:
                sum_e += val
            elif even_nums:
                sum_e -= nums[idx]
            elif not even_val and not even_nums:
                sum_e += (val + nums[idx])
            nums[idx] += val
            answer.append(sum_e)
        return answer

if __name__ == "__main__":
    s = Solution()
    a = s.sumEvenAfterQueries([1,2,3,4], [[1,0],[-3,1],[-4,0],[2,3]])
    print(a)
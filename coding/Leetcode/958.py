# https://leetcode.com/problems/sum-of-even-numbers-after-queries/
# a head-on decision. falls by TL.
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
        answer = []
        for val, idx in queries:
            nums[idx] += val
            ans = self.sum_even(nums)
            answer.append(ans)
        return answer

if __name__ == "__main__":
    s = Solution()
    a = s.sumEvenAfterQueries( [1], [[4,0]])
    print(a)
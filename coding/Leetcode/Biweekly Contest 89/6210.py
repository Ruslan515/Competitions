# https://leetcode.com/contest/biweekly-contest-89/problems/minimize-maximum-of-array/

class Solution:
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # while True:
        #     max_value = max(nums)
        #     max_idx = nums.index(max_value)
        #     if max_idx > 0:
        #         nums[max_idx] -= 1
        #         idx = max_idx - 1
        #         nums[idx] += 1
        #     else:
        #         break
        #
        # return max(nums)

        # s, r = 0, 0
        # for i in range(len(nums)):
        #     s = s + nums[i], max((s + nums[i] + i) / (i + 1), r) if r < nums[i] else r
        # return r


        res=presum=nums[0]
        ct=1

        for num in nums[1:]:
            presum+=num
            ct+=1
            if num>res:
                res=max(res, presum//ct+(presum%ct!=0))

        return res


def read_data():
    nums = list(map(int, input().split()))
    return nums


def main():
    nums = read_data()
    sol = Solution()
    print(sol.minimizeArrayValue(nums))

if __name__ == "__main__":
    main()
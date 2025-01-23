# https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution:
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        # def count(bound):
        #     ans = cur = 0
        #     for x in nums:
        #         cur = cur + 1 if x <= bound else 0
        #         ans += cur
        #     return ans
        # t1 = count(maxK)
        # t2 = count(minK - 1)
        # answer = t1 - t2
        # return answer

        # list_idx_min = [i for i, e in enumerate(nums) if e == minK]
        # list_idx_max = [i for i, e in enumerate(nums) if e == maxK]
        # count = 0
        # n = len(nums)
        # for idx_min in list_idx_min:
        #     for idx_max in list_idx_max:
        #         if idx_min > idx_max:
        #             min_idx = idx_max
        #             max_idx = idx_min
        #         else:
        #             min_idx = idx_min
        #             max_idx = idx_max
        #
        #         if max(nums[min_idx: max_idx + 1]) < maxK:
        #             temp_count = 0
        #             i = 1
        #             left = min_idx
        #             while left >= 0:
        #                 if max(nums[left:max_idx + 1]) < maxK:
        #                     temp_count += 1
        #                     left -= 1
        #                 else:
        #                     break
        #             if left == -1:
        #                 left = 0
        #             fix_count = temp_count
        #             right = max_idx + 1
        #             temp_count = 0
        #             while right < n:
        #                 if max(nums[left:right + 1]) < maxK:
        #                     temp_count += 1
        #                 else:
        #                     break
        #             ccoutn = fix_count * temp_count
        #
        #             count += ccoutn
        # return count

        if minK > maxK:
            return 0

        out = 0

        bad = -1

        good1 = -1
        good2 = -1

        n = len(nums)
        for i in range(n):
            v = nums[i]

            if v < minK:
                bad = (i)
            elif v > maxK:
                bad = (i)
            else:
                if v == minK:
                    good1 = (i)

                if v == maxK:
                    good2 = (i)

                r = min(good1, good2)
                if r > bad:
                    out += r - bad

        return out



def read_data():

    minKs = []
    maxKs = []
    nums = []
    k = int(input())
    for _ in range(k):
        nums.append(list(map(int, input().split())))
        minK = int(input())
        minKs.append(minK)
        maxK = int(input())
        maxKs.append(maxK)

    return nums, minKs, maxKs


def main():
    nums, minKs, maxKs = read_data()
    sol = Solution()
    for num_s, minK, maxK in zip(nums, minKs, maxKs):
        print(sol.countSubarrays(num_s, minK, maxK))

if __name__ == "__main__":
    main()
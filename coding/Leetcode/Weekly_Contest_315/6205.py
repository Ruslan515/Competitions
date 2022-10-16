# https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution:
    def countDistinctIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_list = list(map(str, nums))
        old_list = new_list
        new_list = [e[::-1] for e in new_list]
        new_list += old_list
        new_list = list(map(int, new_list))
        set_list = set(new_list)
        answer = len(set_list)

        return answer


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
        print(sol.countDistinctIntegers(nums_i))

if __name__ == "__main__":
    main()
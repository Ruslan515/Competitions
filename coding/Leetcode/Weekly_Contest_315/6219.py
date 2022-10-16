# https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution:
    def sumOfNumberAndReverse(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return False
        div_num = num // 2
        answer = False
        if num % 2 == 0 and (str(div_num) == str(div_num)[::-1]):
            answer = True
        else:
            while div_num < num:
                div_num += 1
                str_num = str(div_num)
                rev_num = int(str_num[::-1])
                if (div_num + rev_num) == num:
                    answer = True
                    break
        return  answer


def read_data():
    k = int(input())
    nums = []
    for _ in range(k):
        nums.append(int(input()))
    return k, nums


def main():
    k, nums = read_data()
    sol = Solution()
    for num in nums:
        print(sol.sumOfNumberAndReverse(num))

if __name__ == "__main__":
    main()
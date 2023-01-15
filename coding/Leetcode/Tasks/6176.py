# https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/
from typing import List
from collections import Counter, defaultdict

class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        c = Counter(nums)
        new_dict = defaultdict(int)
        for key, value in c.items():
            if key % 2 == 0:
                new_dict[key] = value
        if len(new_dict.keys()) == 0:
            ans = -1
        else:
            temp = []
            max_value = max(new_dict.values())
            for key, value in new_dict.items():
                if value == max_value:
                    temp.append(key)
            ans = min(temp)
        return ans

def read_data():
    nums = list(map(int, input().split()))
    return nums


def main():
    nums = read_data()
    sol = Solution()
    print(sol.mostFrequentEven(nums))

if __name__ == "__main__":
    main()
# https://leetcode.com/contest/weekly-contest-314/problems/find-the-original-array-of-prefix-xor/
from typing import List

class Solution:
    def findArray(self, pref):
        """
        :type pref: List[int]
        :rtype: List[int]
        """
        n = len(pref)
        if n > 1:
            arr = []
            dp = [0 for _ in range(n)]
            arr.append(pref[0])
            arr.append(arr[0] ^ pref[1])
            dp[0] = pref[0]
            dp[1] = dp[0] ^ arr[1]

            for i in range(2, n):
                temp = dp[i - 1] ^ pref[i]
                # temp = arr[0]
                # for j in range(1, i):
                #     temp = temp ^ arr[j]
                # temp = temp ^ pref[i]
                arr.append(temp)
                dp[i] = dp[i - 1] ^ arr[i]

        else:
            arr = pref
        return arr

def read_data():
    pref = list(map(int, input().split()))
    return pref

def main():
    pref = read_data()
    sol = Solution()
    print(sol.findArray(pref))

if __name__ == "__main__":
    main()
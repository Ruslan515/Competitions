# https://leetcode.com/contest/biweekly-contest-94/problems/maximum-enemy-forts-that-can-be-captured/
from typing import List

class Solution:
    def captureForts(self, forts: List[int]) -> int:
        answer = 0
        n = len(forts)
        i = -1
        while i < n - 1:
            i += 1
            f = forts[i]
            if f == 1:
                j = i + 1
                count = 0
                while j < n - 1 and forts[j] == 0:
                    count += 1
                    j += 1
                if j < n and forts[j] == -1:
                    answer = max(answer, count)
                else:
                    answer = max(answer, 0)

        i = n
        while i >= 0:
            i -= 1
            f = forts[i]
            if f == 1:
                j = i - 1
                count = 0
                while j >= 0  and forts[j] == 0:
                    count += 1
                    j -= 1
                if j >= 0 and forts[j] == -1:
                    answer = max(answer, count)
                else:
                    answer = max(answer, 0)

        return answer


def read_data():
    forts = list(map(int, input().split(",")))
    return forts

def main():
    forts = read_data()
    sol = Solution()
    print(sol.captureForts(forts))

if __name__ == "__main__":
    main()

"""
The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
"""
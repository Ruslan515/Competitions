# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List
import numpy as np

class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        score = np.array(score)
        score = score[score[:, k].argsort()[::-1]]
        score = score.tolist()
        return score


def read_data():
    m = int(input())
    n = int(input())
    k = int(input())

    score = []
    for _ in range(m):
        nums = list(map(int, input().split(",")))
        score.append(nums)

    return score, k

def main():
    score, k = read_data()
    solve = Solution()
    print(solve.sortTheStudents(score, k))

if __name__ == "__main__":
    main()
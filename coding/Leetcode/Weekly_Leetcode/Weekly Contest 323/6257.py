# https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
from typing import List

class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        """
        :type n: int
        :rtype: int
        """
        answer = 0
        n = len(grid[0])
        for i in range(n):
            gl_max = -1
            for sub_grid in grid:
                temp_max = max(sub_grid)
                sub_grid.remove(temp_max)
                gl_max = max(gl_max, temp_max)
            answer += gl_max


        return answer

def main():
    grid = [[1,2,4],[3,3,1]]
    sol = Solution()
    print(sol.deleteGreatestValue(grid))

if __name__ == "__main__":
    main()
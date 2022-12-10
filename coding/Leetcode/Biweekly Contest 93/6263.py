# https://leetcode.com/contest/biweekly-contest-93/problems/frog-jump-ii/
from typing import List

class Solution:
    def maxJump(self, stones: List[int]) -> int:
        answer = 0
        if len(stones) == 2:
            answer = stones[1] - stones[0]
        else:
            list_delta = [stones[i] - stones[i - 1] for i in range(1, len(stones))]
            sums_delta = [list_delta[i] + list_delta[i - 1] for i in range(1, len(list_delta))]
            answer = max(sums_delta)

        return answer


def read_data():
    stones = list(map(int, input().split(" ")))
    return stones

def main():
    stones = read_data()
    sol = Solution()
    print(sol.maxJump(stones))

if __name__ == "__main__":
    main()
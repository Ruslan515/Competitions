# https://leetcode.com/contest/biweekly-contest-132/problems/find-the-first-player-to-win-k-games-in-a-row/
from typing import List


class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        from collections import deque
        dq = deque()
        for i, skill in enumerate(skills):
            dq.append((i, skill))

        answer = 0
        tmp_k = 0
        idx = None
        current = None
        while True:
            idx_first, first = dq.popleft()
            idx_second, second = dq.popleft()
            if first > second:
                idx = idx_first
                if current is None:
                    current = first
                    tmp_k += 1
                else:
                    if current == first:
                        tmp_k += 1
                    else:
                        current = first
                        tmp_k = 1

                dq.appendleft((idx_first, first))
                dq.append((idx_second, second))
            else:
                idx = idx_second
                if current is None:
                    current = second
                else:
                    if current == second:
                        tmp_k += 1
                    else:
                        current = second
                        tmp_k = 1
                dq.appendleft((idx_second, second))
                dq.append((idx_first, first))

            if tmp_k == k:
                break
        answer = idx
        return answer


def main():
    solve = Solution()

    skills = [16, 4, 7, 17]
    k = 562084119
    answer = 3
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [4, 2, 6, 3, 9]
    k = 2
    answer = 2
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [2, 5, 4]
    k = 3
    answer = 1
    assert answer == solve.findWinningPlayer(skills, k)


if __name__ == "__main__":
    main()

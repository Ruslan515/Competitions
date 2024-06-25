# https://leetcode.com/contest/biweekly-contest-132/problems/find-the-first-player-to-win-k-games-in-a-row/
from typing import List


class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        answer = 0
        n = len(skills)
        if k >= n:
            return skills.index(max(skills))
        max_skill = skills[0]
        if max_skill > max(skills[1: k + 1]):
            return 0

        for i in range(1, n - k + 1):
            max_skill = skills[i]
            start = i - 1
            s = skills[start]
            end = min(i + k, n - 1)
            e = skills[end]
            tmp = max(skills[start:end])
            if max_skill == tmp:
                answer = i
                return answer
        max_skill = skills[n - 1]
        if max_skill > max(skills[n - k:n - 1]):
            return n - 1

        return answer


def main():
    solve = Solution()

    skills = [8, 9, 7, 19, 11]
    k = 3
    answer = 3
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [18, 15, 20]
    k = 2
    answer = 2
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [4, 2, 6, 3, 9]
    k = 2
    answer = 2
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [16, 4, 7, 17]
    k = 562084119
    answer = 3
    assert answer == solve.findWinningPlayer(skills, k)

    skills = [2, 5, 4]
    k = 3
    answer = 1
    assert answer == solve.findWinningPlayer(skills, k)


if __name__ == "__main__":
    main()

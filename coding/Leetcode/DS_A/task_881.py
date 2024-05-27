# https://leetcode.com/problems/destroying-asteroids/
from typing import List, Optional


class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        i, j = 0, len(people) - 1
        ans = 0
        while i <= j:
            ans += 1
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
        return ans


def main():
    solve = Solution()

    people = [3, 5, 3, 4]
    limit = 5
    answer = 4
    assert answer == solve.numRescueBoats(people, limit)

    people = [3, 2, 2, 1]
    limit = 3
    answer = 3
    assert answer == solve.numRescueBoats(people, limit)

    people = [1, 2]
    limit = 3
    answer = 1
    assert answer == solve.numRescueBoats(people, limit)

if __name__ == "__main__":
    main()

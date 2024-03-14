# https://leetcode.com/problems/destroying-asteroids/
from typing import List, Optional


class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        answer = True
        asteroids.sort()
        sums = mass
        for asteroid in asteroids:
            if asteroid <= sums:
                sums += asteroid
            else:
                answer = False
                break

        return answer


def main():
    solve = Solution()

    mass = 10
    asteroids = [3, 9, 19, 5, 21]
    answer = True
    assert answer == solve.asteroidsDestroyed(mass, asteroids)

    mass = 5
    asteroids = [4, 9, 23, 4]
    answer = False
    assert answer == solve.asteroidsDestroyed(mass, asteroids)


if __name__ == "__main__":
    main()

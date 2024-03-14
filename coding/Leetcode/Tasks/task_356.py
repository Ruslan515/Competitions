# https://leetcode.com/problems/line-reflection/description/
from typing import List, Optional


class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        answer: bool = True
        dict_coords = {}
        for x, y in points:
            try:
                dict_coords[y].add(x)
            except:
                dict_coords[y] = {x}

        global_middle = None
        for key, vector in dict_coords.items():
            loop_middle = -1
            vector = list(vector)
            if len(vector) > 1:
                vector.sort()
                n = len(vector)
                left: int = 0
                right: int = n - 1
                loop_middle: int = (vector[right] + vector[left]) / 2
                if global_middle is None:
                    global_middle = loop_middle
                else:
                    if global_middle != loop_middle:
                        answer = False
                        break
                while left <= right:
                    middle: int = (vector[right] + vector[left]) / 2
                    if middle != global_middle:
                        answer = False
                        return answer
                    left += 1
                    right -= 1
            else:
                loop_middle = vector[0]
            if global_middle != None:
                if global_middle != loop_middle:
                    answer = False
                    break
            else:
                global_middle = loop_middle

        return answer


def main():
    solve = Solution()

    points = [[1, 1], [0, 0], [-1, 1]]
    answer = True
    assert answer == solve.isReflected(points)

    points = [[1, 1], [-1, -1]]
    answer = False
    assert answer == solve.isReflected(points)

    points = [[-16, 1], [16, 1], [16, 1]]
    answer = True
    assert answer == solve.isReflected(points)

    points = [[0, 0], [1, 0], [3, 0]]
    answer = False
    assert answer == solve.isReflected(points)

    points = [[1, 1], [-1, 1]]
    answer = True
    assert answer == solve.isReflected(points)


if __name__ == "__main__":
    main()

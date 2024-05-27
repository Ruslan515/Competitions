# https://leetcode.com/problems/destroying-asteroids/
from typing import List, Optional


class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        answer: int = 0
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        uses_boxes = 0
        for count_boxes, count_units in boxTypes:
            diff = min(count_boxes, truckSize - uses_boxes)
            answer += diff * count_units
            uses_boxes += diff
            if uses_boxes == truckSize:
                break

        return answer


def main():
    solve = Solution()

    boxTypes = [[1, 3], [2, 2], [3, 1]]
    truckSize = 4
    answer = 8
    assert answer == solve.maximumUnits(boxTypes, truckSize)

    boxTypes = [[5, 10], [2, 5], [4, 7], [3, 9]]
    truckSize = 10
    answer = 91
    assert answer == solve.maximumUnits(boxTypes, truckSize)


if __name__ == "__main__":
    main()

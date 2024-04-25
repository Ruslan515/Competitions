# https://leetcode.com/problems/meeting-rooms-ii/?envType=weekly-question&envId=2024-03-15
from typing import List, Optional


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        if n == 1:
            return 1
        answer = 0
        f = lambda x: x[0]
        intervals.sort(key=f)
        i = 0
        while i < n:
            second = intervals[i][1]
            j = i + 1
            while j < n and intervals[j][0] <= second:
                j += 1
                answer += 1
            if answer != 0:
                answer += 1
            i = j
        if answer == 0:
            answer = 1
        else:
            answer -= 1
        return answer


def main():
    solve = Solution()

    intervals = [[5, 8], [6, 8]]
    answer = 2
    assert answer == solve.minMeetingRooms(intervals)

    intervals = [[0, 30], [5, 10], [15, 20]]
    answer = 2
    assert answer == solve.minMeetingRooms(intervals)

    intervals = [[7, 10], [2, 4]]
    answer = 1
    assert answer == solve.minMeetingRooms(intervals)


if __name__ == "__main__":
    main()

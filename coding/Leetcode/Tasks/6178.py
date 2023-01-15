# https://leetcode.com/contest/weekly-contest-310/problems/divide-intervals-into-minimum-number-of-groups/
from typing import List

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        count = 0
        new_intervals = []
        # for incl_interval in intervals:
        while len(intervals) != 0:
            incl_interval = intervals[0]
            new_intervals.append([incl_interval])
            left, right = incl_interval[0], incl_interval[1]
            intervals.pop(0)
            el_idx = 0
            # for el in intervals:
            while len(intervals) != 0 and el_idx < len(intervals):
                el = intervals[el_idx]
                new_left, new_right = el[0], el[1]
                label = True
                for i, new_el in enumerate(new_intervals[count]):
                    l, r = new_el[0], new_el[1]
                    if l <= new_left <= r or l <= new_right <= r or (new_left <= l and r <= new_right):
                        label = False
                        break
                if label:
                    new_intervals[count].append(el)
                    intervals.pop(el_idx)
                    el_idx = 0
                else:
                    el_idx += 1
            count += 1
        return count


def read_data():
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    intervals = [list(map(int, el.split(","))) for el in s]
    return intervals


def main():
    intervals = read_data()
    sol = Solution()
    print(sol.minGroups(intervals))

if __name__ == "__main__":
    main()
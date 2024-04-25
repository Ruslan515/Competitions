# https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08
from typing import List, Optional


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        from collections import deque
        stud_dq = deque(students)
        n = len(students)
        sandw_dq = deque(sandwiches)
        while sandw_dq:
            sandw = sandw_dq.popleft()
            label = True
            for i in range(n):
                student = stud_dq.popleft()
                if student != sandw:
                    stud_dq.append(student)
                else:
                    n -= 1
                    label = False
                    break
            if label:
                sandw_dq.appendleft(sandw)
                break

        size_dq = len(stud_dq)
        return size_dq


def main():
    solve = Solution()

    students = [1, 1, 0, 0]
    sandwiches = [0, 1, 0, 1]
    answer = 0
    assert answer == solve.countStudents(students, sandwiches)

    students = [1, 1, 1, 0, 0, 1]
    sandwiches = [1, 0, 0, 0, 1, 1]
    answer = 3
    assert answer == solve.countStudents(students, sandwiches)


if __name__ == "__main__":
    main()

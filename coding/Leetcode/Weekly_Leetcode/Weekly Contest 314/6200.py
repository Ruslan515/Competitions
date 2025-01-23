# https://leetcode.com/contest/weekly-contest-314/problems/the-employee-that-worked-on-the-longest-task/
from typing import List

class Solution:
    def hardestWorker(self, n, logs):
        """
        :type n: int
        :type logs: List[List[int]]
        :rtype: int
        """
        max_time = 0
        id_emp_hard = 1000
        list_id = []
        current_time = 0
        idx_time = 1
        idx_employee = 0
        for i in range(len(logs)):
            delta = logs[i][idx_time] - current_time
            if delta > max_time:
                max_time = delta
                id_emp_hard = logs[i][idx_employee]
            if delta == max_time:
                if logs[i][idx_employee] < id_emp_hard:
                    max_time = delta
                    id_emp_hard = logs[i][idx_employee]
            current_time = logs[i][idx_time]

        return id_emp_hard

def read_data():
    n = int(input())
    s = input()
    s = s.replace("[[", "").replace("]]", "")
    s = s.split("],[")
    logs = [list(map(int, el.split(","))) for el in s]
    return n, logs

def main():
    n, logs = read_data()
    sol = Solution()
    print(sol.hardestWorker(n, logs))

if __name__ == "__main__":
    main()
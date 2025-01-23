# https://leetcode.com/contest/weekly-contest-314/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
from typing import List

class Solution:
    def robotWithString(self, s):
        """
        :type s: str
        :rtype: str
        """
        m, t, u = [0] * (len(s) - 1) + [s[-1]], [], []
        for i in range(len(s) - 2, -1, -1):
            m[i] = s[i] if s[i] < m[i + 1] else m[i + 1]
        for i in range(len(s)):
            u.append(s[i])
            if i < len(s) - 1:
                while u and u[-1] <= m[i + 1]:
                    t.append(u.pop())
        while u:
            t.append(u.pop())
        return ''.join(t)

def read_data():
    s = input()
    return s

def main():
    s = read_data()
    sol = Solution()
    print(sol.robotWithString(s))

if __name__ == "__main__":
    main()
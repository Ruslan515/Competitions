# https://leetcode.com/contest/biweekly-contest-89/problems/number-of-valid-clock-times/
from typing import List

class Solution:
    def countTime(self, time):
        """
        :type time: str
        :rtype: int
        """
        q = "?"
        hh, mm = time.split(":")
        h1, h2 = hh[0], hh[1]
        # h1_int, h2_int = map(int, [hh[0], hh[1]])
        m1, m2 = mm[0], mm[1]
        # m1_int, m2_int = map(int, [mm[0], mm[1]])
        if hh == q * 2:
            e1 = 3
            e2 = 8
        else:
            if h1 == q and  h2 != q and int(h2) <= 3:
                e1 = 3
            elif h1 == q and h2 == q:
                e1 = 3
            elif h1 == q and  h2 != q and int(h2) > 3:
                e1 = 2
            else:
                e1 = 1
            if h2 == q and h1 != q and int(h1) < 2:
                e2 = 10
            elif h2 == q and h1 == q:
                e2 = 10
            elif h2 == q and h1 != q and int(h1) >= 2:
                e2 = 4
            else:
                e2 = 1
        if m1 == q:
            e3 = 6
        else:
            e3 = 1
        if m2 == q:
            e4 = 10
        else:
            e4 = 1
        answer = e1 * e2 * e3 * e4

        return answer


def read_data():
    time = input()
    return time

def main():
    time = read_data()
    sol = Solution()
    print(sol.countTime(time))

if __name__ == "__main__":
    main()
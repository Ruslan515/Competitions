# https://leetcode.com/contest/biweekly-contest-85/problems/time-needed-to-rearrange-a-binary-string/
class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        target = "01"
        change = "10"
        if target not in s:
            return 0
        import re
        cnt = 0
        while target in s:
            s = s.replace(target, change)
            cnt += 1
        return cnt

def read_data():
    s = input()
    return s


def main():
    s = read_data()
    sol = Solution()
    print(sol.secondsToRemoveOccurrences(s))

if __name__ == "__main__":
    main()
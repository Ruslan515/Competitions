# https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

class Solution:
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        if t in s:
            answer = 0
        else:
            idx = 0
            while idx < len(s) and (s[idx] != t[0]):
                idx += 1
            if idx == len(s):
                answer = len(t)
            else:
                i = 0
                while i < len(t) and idx < len(s) and (s[idx] == t[i]):
                    i += 1
                    idx += 1
                answer = len(t) - i

        return answer


def read_data():
    s = input()
    t = input()
    return s, t


def main():
    s, t = read_data()
    sol = Solution()
    print(sol.appendCharacters(s, t))

if __name__ == "__main__":
    main()
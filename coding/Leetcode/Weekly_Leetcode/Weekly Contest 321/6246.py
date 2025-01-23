# https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

class Solution:
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        i = 0
        if t in s:
            answer = 0
        else:
            while i < min(len(s), len(t)) and (s[i] == t[i]):
                i += 1

            x = len(t) - i
            answer = x

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
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
                count = 1
                for i in range(1, len(t)):
                    if not (t[i] in s[idx:]):
                        break
                    count += 1
                    idx = s[idx + 1:].index(t[i]) + idx + 1

                answer = len(t) - count

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
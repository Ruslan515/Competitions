# https://leetcode.com/contest/biweekly-contest-92/problems/count-palindromic-subsequences/

class Solution:
    def countPalindromes(self, s: str) -> int:
        import itertools
        combs = itertools.combinations(s, 5)
        answer = 0
        for sub in combs:
            sub = "".join(sub)
            n = 2
            t = sub[3:]
            if sub[:n] == t[::-1]:
                answer += 1

        return answer % (10**9 + 7)

    # def countPalindromes(self, s: str) -> int:
    #     import itertools
    #     combs = itertools.combinations(s, 5)
    #     all_subs = ["".join(comb) for comb in combs]
    #     answer = 0
    #     for sub in all_subs:
    #         n = len(sub) // 2
    #         if len(sub) % 2 == 0:
    #             if sub[:n] == sub[n::-1]:
    #                 answer += 1
    #         else:
    #             t = sub[n + 1:]
    #             if sub[:n] == t[::-1]:
    #                 answer += 1
    #
    #
    #     return answer % (10**9 + 7)


def read_data():
    s = input()
    return s

def main():
    s = read_data()
    sol = Solution()
    print(sol.countPalindromes(s))

if __name__ == "__main__":
    main()
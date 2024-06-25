# https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28
class Solution:

    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        answer = 0
        n = len(s)
        left = right = 0
        diff = lambda x, y: abs(ord(x) - ord(y))
        cost = 0
        while right < n:
            while right < n:
                d = diff(s[right], t[right])
                if cost + d <= maxCost:
                    cost += d
                    right += 1
                else:
                    break
            answer = max(right - left, answer)
            while left < n or left < right:
                d = diff(s[left], t[left])
                cost -= d
                left += 1
                if cost < maxCost:
                    break


        return answer


def main():
    solve = Solution()

    s = "abcd"
    t = "bcdf"
    maxCost = 3
    answer = 3
    assert answer == solve.equalSubstring(s, t, maxCost)

    s = "abcd"
    t = "cdef"
    maxCost = 3
    answer = 1
    assert answer == solve.equalSubstring(s, t, maxCost)

    s = "abcd"
    t = "acde"
    maxCost = 0
    answer = 1
    assert answer == solve.equalSubstring(s, t, maxCost)


if __name__ == "__main__":
    main()

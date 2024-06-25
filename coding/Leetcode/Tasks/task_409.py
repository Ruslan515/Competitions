class Solution:
    def longestPalindrome(self, s: str) -> int:
        answer = 0
        mp = {}
        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1
        max_odd = 0
        max_key = -1
        for key, value in mp.items():
            if value % 2 != 0 and max_odd < value:
                max_odd = value
                max_key = key
        if max_key != -1:
            mp.pop(max_key)
            answer += max_odd
        for key, value in mp.items():
            if value % 2 != 0:
                answer += value - 1
            else:
                answer += value

        return answer


def main():
    solve = Solution()

    s = "abccccdd"
    answer = 7
    assert answer == solve.longestPalindrome(s)

    s = "a"
    answer = 1
    assert answer == solve.longestPalindrome(s)


if __name__ == "__main__":
    main()

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        answer = 0
        st = set()
        left = 0
        right = 0
        n = len(s)

        while right < n:
            r = s[right]
            st.add(r)
            while r in st:
                l = s[left]
                st.remove(l)
                left += 1
            answer = max(answer, right - left + 1)
            right += 1

        return answer


def main():
    solve = Solution()

    s = "au"
    answer = 2
    assert answer == solve.lengthOfLongestSubstring(s)

    s = " "
    answer = 1
    assert answer == solve.lengthOfLongestSubstring(s)

    s = "abcabcbb"
    answer = 3
    assert answer == solve.lengthOfLongestSubstring(s)

    s = "bbbbb"
    answer = 1
    assert answer == solve.lengthOfLongestSubstring(s)

    s = "pwwkew"
    answer = 3
    assert answer == solve.lengthOfLongestSubstring(s)


if __name__ == "__main__":
    main()

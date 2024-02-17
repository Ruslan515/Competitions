# https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13
from typing import List


class Solution:
    def check_palindrome(self, s: str) -> bool:
        n = int(len(s) / 2)
        return s[:n] == s[:n + int(len(s) % 2) - 1:-1]

    def firstPalindrome(self, words: List[str]) -> str:
        answer = ""
        for word in words:
            if self.check_palindrome(word):
                answer = word
                break

        return answer


def main():
    solve = Solution()

    words = ["raceecar"]
    answer = "raceecar"
    assert answer == solve.firstPalindrome(words)

    words = ["notapalindrome", "racecar"]
    answer = "racecar"
    assert answer == solve.firstPalindrome(words)

    words = ["cqllrtyhw", "swwisru", "gpzmbders", "wqibjuqvs", "pp", "usewxryy", "ybqfuh", "hqwwqftgyu", "jggmatpk"]
    answer = "pp"
    assert answer == solve.firstPalindrome(words)

    words = ["abc", "car", "ada", "racecar", "cool"]
    answer = "ada"
    assert answer == solve.firstPalindrome(words)

    words = ["def", "ghi"]
    answer = ""
    assert answer == solve.firstPalindrome(words)


if __name__ == "__main__":
    main()

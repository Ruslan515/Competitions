# https://leetcode.com/problems/word-pattern/
from typing import List


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        answer = False
        n_p = len(pattern)
        words = s.split(" ")
        n_s = len(words)
        if n_p != n_s:
            return answer
        pattern_to_words = {}
        words_to_pattern = {}
        for ch, word in zip(pattern, words):
            if ch not in pattern_to_words:
                pattern_to_words[ch] = word
            else:
                val = pattern_to_words[ch]
                if word != val:
                    return answer
            if word not in words_to_pattern:
                words_to_pattern[word] = ch
            else:
                val = words_to_pattern[word]
                if val != ch:
                    return answer
        answer = True

        return answer


def main():
    solve = Solution()

    pattern = "abba"
    s = "dog cat cat dog"
    answer = True
    assert answer == solve.wordPattern(pattern, s)

    pattern = "abba"
    s = "dog cat cat fish"
    answer = False
    assert answer == solve.wordPattern(pattern, s)

    pattern = "aaaa"
    s = "dog cat cat dog"
    answer = False
    assert answer == solve.wordPattern(pattern, s)


if __name__ == "__main__":
    main()

from typing import List


class Solution:
    def convert_to_dict(self, word: str) -> dict:
        mp = {}
        for ch in word:
            mp[ch] = mp.get(ch, 0) + 1
        return mp

    def commonChars(self, words: List[str]) -> List[str]:
        answer = []
        current = self.convert_to_dict(words[0])
        for word in words[1:]:
            mp = self.convert_to_dict(word)
            list_to_del = []
            for key, value in current.items():
                if key not in mp.keys():
                    list_to_del.append(key)
                else:
                    current[key] = min(mp[key], value)
            for key in list_to_del:
                current.pop(key)

        for key, value in current.items():
            answer.extend([key] * value)

        return answer


def main():
    solve = Solution()

    words = ["cool", "lock", "cook"]
    answer = ["c", "o"]
    assert answer == solve.commonChars(words)

    words = ["bella", "label", "roller"]
    answer = ["e", "l", "l"]
    assert answer == solve.commonChars(words)


if __name__ == "__main__":
    main()

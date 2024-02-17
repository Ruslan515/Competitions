from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer = []
        hmp = {}
        for word in strs:
            tmp_hash = {}
            for ch in word:
                tmp_hash[ch] = tmp_hash.get(ch, 0) + 1
            hmp.setdefault(frozenset(tmp_hash.items()), []).append(word)
        for key, val in hmp.items():
            answer.append(val)

        return answer


def main():
    solve = Solution()

    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    answer = [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
    assert answer == solve.groupAnagrams(strs)

    strs = [""]
    answer = [[""]]
    assert answer == solve.groupAnagrams(strs)

    strs = ["a"]
    answer = [["a"]]
    assert answer == solve.groupAnagrams(strs)


if __name__ == "__main__":
    main()

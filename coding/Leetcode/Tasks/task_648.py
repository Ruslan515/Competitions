from typing import List


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        answer = []
        dictionary.sort(key=lambda x: len(x))
        for word in sentence.split():
            x = word
            for d in dictionary:
                if word.startswith(d):
                    x = d
                    break
            answer.append(x)
            
        answer = " ".join(answer)

        return answer


def main():
    solve = Solution()

    dictionary = ["cat", "bat", "rat"]
    sentence = "the cattle was rattled by the battery"
    answer = "the cat was rat by the bat"
    assert answer == solve.replaceWords(dictionary, sentence)

    dictionary = ["a", "b", "c"]
    sentence = "aadsfasf absbs bbab cadsfafs"
    answer = "a a b c"
    assert answer == solve.replaceWords(dictionary, sentence)


if __name__ == "__main__":
    main()

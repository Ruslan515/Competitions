from typing import List


class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        answer = []
        n = len(currentState)
        for i in range(n - 1):
            if currentState[i: i + 2] == "++":
                answer.append(currentState[:i] + "--" + currentState[i + 2:])

        return answer


def main():
    solve = Solution()

    currentState = "--++-"
    answer = ["-----"]
    assert answer == solve.generatePossibleNextMoves(currentState)

    currentState = "+-+-"
    answer = []
    assert answer == solve.generatePossibleNextMoves(currentState)

    currentState = "++++"
    answer = ["--++", "+--+", "++--"]
    assert answer == solve.generatePossibleNextMoves(currentState)

    currentState = "+"
    answer = []
    assert answer == solve.generatePossibleNextMoves(currentState)


if __name__ == "__main__":
    main()

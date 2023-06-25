from typing import List


class Solution:
    def join(self, x, y):
        if x[-1] == y[0]:
            return x + y[1:]
        else:
            return x + y

    def min_length(self, words):
        n = len(words)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if i == j - 1:
                    dp[i][j] = len(self.join(words[i], words[j]))
                else:
                    dp[i][j] = float('inf')
                    for k in range(i, j):
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j])
                    dp[i][j] = min(dp[i][j], len(self.join(words[i], dp[i + 1][j])))
                    dp[i][j] = min(dp[i][j], len(self.join(dp[i][j - 1], words[j])))
        return dp[0][n - 1]

    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        answer = self.min_length(words)
        return answer


def main():
    solve = Solution()

    words = ["aa", "ab", "bc"]
    answer = 4
    assert answer == solve.minimizeConcatenatedLength(words)

    words = ["ab", "b"]
    answer = 2
    assert answer == solve.minimizeConcatenatedLength(words)

    words = ["aaa", "c", "aba"]
    answer = 6
    assert answer == solve.minimizeConcatenatedLength(words)


if __name__ == "__main__":
    main()

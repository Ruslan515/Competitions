# https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03
from typing import List, Optional

import queue


class Solution:
    directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    def checkIn(self, board: List[List[str]], word: str, row: int, col: int) -> bool:
        answer = False
        n: int = len(board)
        m: int = len(board[0])
        used = [[False for _ in range(m)] for _ in range(n)]
        q = queue.Queue()
        q.put((row, col, 1))
        used[row][col] = True
        idx = 1
        len_word = len(word)
        if len_word == 1:
            return True
        while not q.empty() and idx < len_word:
            size_q = q.qsize()
            for _ in range(size_q):
                row, col, cnt = q.get()
                used[row][col] = True
                label = True
                for dx, dy in self.directions:
                    nx, ny = row + dx, col + dy
                    if 0 <= nx < n and 0 <= ny < m and not used[nx][ny]:
                        if board[nx][ny] == word[idx]:
                            if cnt + 1 == len_word:
                                answer = True
                                return answer
                            else:
                                q.put((nx, ny, cnt + 1))
                                label = False
                if label:
                    used[row][col] = False
            idx += 1

        return answer

    def exist(self, board: List[List[str]], word: str) -> bool:
        answer: bool = False
        n: int = len(board)
        m: int = len(board[0])
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    if self.checkIn(board, word, i, j):
                        answer = True
                        return answer

        return answer


def main():
    solve = Solution()

    board = [
        ["A", "B", "C", "E"],
        ["S", "F", "E", "S"],
        ["A", "D", "E", "E"]
    ]
    word = "ABCESEEEFS"
    answer = True
    assert answer == solve.exist(board, word)

    board = [["A"]]
    word = "A"
    answer = True
    assert answer == solve.exist(board, word)

    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "ABCB"
    answer = False
    assert answer == solve.exist(board, word)

    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "ABCCED"
    answer = True
    assert answer == solve.exist(board, word)

    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "SEE"
    answer = True
    assert answer == solve.exist(board, word)


if __name__ == "__main__":
    main()

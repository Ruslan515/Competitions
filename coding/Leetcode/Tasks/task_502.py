# https://leetcode.com/problems/ipo/
from typing import List, Optional

from collections import defaultdict
import queue


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        answer: int = w
        d = defaultdict(list)  # ключ вершина, значкение - список вершин с которыми смежна
        n: int = len(capital)

        for i in range(n):
            cap = capital[i]
            profit = profits[i]
            d[cap].append(profit)

        node = (w, 0)
        q = queue.Queue()
        q.put(node)
        for i in range(k):
            size_q = q.qsize()
            for _ in range(size_q):
                node, sums = q.get()
                adj_list = d[node]
                for adj in adj_list:
                    tmp = sums + adj
                    t = max(answer, tmp)
                    answer += t
                    q.put((adj, tmp))

        return answer


def main():
    solve = Solution()

    k = 1
    w = 10
    profits = [1, 2, 3]
    capital = [0, 0, 0]
    answer = 13
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 1
    w = 2
    profits = [1, 2, 3]
    capital = [1, 1, 2]
    answer = 5
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 3
    w = 0
    profits = [1, 2, 3]
    capital = [0, 1, 2]
    answer = 6
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)

    k = 2
    w = 0
    profits = [1, 2, 3]
    capital = [0, 1, 1]
    answer = 4
    assert answer == solve.findMaximizedCapital(k, w, profits, capital)


if __name__ == "__main__":
    main()

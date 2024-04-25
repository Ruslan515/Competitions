# https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23
from typing import List, Optional


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        from collections import defaultdict
        import queue
        answer: List[int] = []
        adj = defaultdict(set)
        degree = [0] * n
        levels = [0] * n
        for u, v in edges:
            adj[u].add(v)
            degree[u] += 1
            adj[v].add(u)
            degree[v] += 1

        q = queue.Queue()
        for node, nodes in adj.items():
            if len(nodes) == 1:
                q.put(node)

        max_level = 0
        while not q.empty():
            node = q.get()
            for neighbor in adj[node]:
                degree[neighbor] -= 1
                if degree[neighbor] == 1:
                    q.put(neighbor)
                    levels[neighbor] = levels[node] + 1
                    max_level = max(max_level, levels[neighbor])

        for i, level in enumerate(levels):
            if level == max_level:
                answer.append(i)

        return answer


def main():
    solve = Solution()

    n = 6
    edges = [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]
    answer = [3, 4]
    assert answer == solve.findMinHeightTrees(n, edges)

    n = 4
    edges = [[1, 0], [1, 2], [1, 3]]
    answer = [1]
    assert answer == solve.findMinHeightTrees(n, edges)


if __name__ == "__main__":
    main()

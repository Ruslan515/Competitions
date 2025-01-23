# https://leetcode.com/contest/biweekly-contest-93/problems/maximum-star-sum-of-a-graph/
from typing import List

class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        graph = {}
        for edge in edges:
            u, v = edge
            if graph.get(u, None) is None:
                graph[u] = {v}
            else:
                graph[u].add(v)
            if graph.get(v, None) is None:
                graph[v] = {u}
            else:
                graph[v].add(u)

        max_sum = max(vals)

        for v, val in enumerate(vals):
            neighs = []
            if not graph.get(v, None) is None:
                for u in graph[v]:
                    if vals[u] > 0:
                        neighs.append(vals[u])
            neighs.sort(reverse=True)
            temp_sum = val + sum(neighs[:k])
            max_sum = max(temp_sum, max_sum)

        return max_sum


def read_data():
    strs = input().split(" ")
    return strs

def main():
    # strs = read_data()
    sol = Solution()

    vals = [1, 2, 3, 4, 10, -10, -20]
    edges = [[0, 1], [1, 2], [1, 3], [3, 4], [3, 5], [3, 6]]
    k = 2

    # vals = [-5]
    # edges = []
    # k = 0

    print(sol.maxStarSum(vals, edges, k))

if __name__ == "__main__":
    main()

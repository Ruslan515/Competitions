// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
// Created by ruslan515 on 25.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> createGR(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        int u, v;
        for (int i = 0; i < edges.size(); ++i) {
            u = edges[i][0];
            v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }

    void bfs(int start, int n, vector<bool> &visited, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(start);
        int current;
        while (!q.empty()) {
            int size_q = q.size();
            for (int k = 0; k < size_q; ++k) {
                current = q.front();
                q.pop();
                visited[current] = true;
                int next;
                for (int i = 0; i < graph[current].size(); ++i) {
                    next = graph[current][i];
                    if (!visited[next]) {
                        q.push(next);
                    }
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges) {
        int answer = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> graph = createGR(n, edges);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                answer++;
                bfs(i, n, visited, graph);
            }
        }

        return answer;
    }
};

int main() {
    int n;
    vector<vector<int>> edges;
    int answer;
    Solution solve;

    n = 5, edges = {{0, 1},
                    {1, 2},
                    {3, 4}};
    answer = 2;
    assert(answer == solve.countComponents(n, edges));

    n = 5, edges = {{0, 1},
                    {1, 2},
                    {2, 3},
                    {3, 4}};
    answer = 1;
    assert(answer == solve.countComponents(n, edges));

    return 0;
}
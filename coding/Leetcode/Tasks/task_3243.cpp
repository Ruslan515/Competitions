// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27
// Created by omega515 on 27.11.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> createG(int n) {
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }

        return graph;
    }

    int bfs(vector<vector<int>> graph) {
        int answer = 0;
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<int> visited(n, false);
        q.push({0, 0});
        visited[0] = true;
        while (!q.empty()) {
            int sizeQ = q.size();
            for (int i = 0; i < sizeQ; ++i) {
                pair<int, int> currentPair = q.front();
                q.pop();
                int currentNode = currentPair.first;
                int currentLen = currentPair.second;
                visited[currentNode] = true;

                int countChildren = graph[currentNode].size();
                for (int j = 0; j < countChildren; ++j) {
                    int nextNode = graph[currentNode][j];
                    if (nextNode == (n - 1)) {
                        return currentLen + 1;
                    } else if (visited[nextNode] == false) {
                        q.push({nextNode, currentLen + 1});
                    }
                }

            }

        }

        return answer;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        vector<vector<int>> graph = createG(n);
        int m = queries.size();
        int u, v;
        int globalShortPath = n - 1;
        for (int i = 0; i < m; ++i) {
            u = queries[i][0];
            v = queries[i][1];
            graph[u].push_back(v);
            int localShortPath = bfs(graph);
            globalShortPath = min(globalShortPath, localShortPath);
            if (globalShortPath == 1) {
                for (int j = i; j < m; ++j) {
                    answer.push_back(globalShortPath);
                }
                return answer;
            }
            answer.push_back(globalShortPath);
        }
        return answer;
    }
};


int main() {
    int n;
    vector<vector<int>> queries;
    vector<int> answer;
    Solution solve;

    n = 5, queries = {{2, 4},
                      {0, 2},
                      {0, 4}};
    answer = {3, 2, 1};
    assert(answer == solve.shortestDistanceAfterQueries(n, queries));

    n = 4, queries = {{0, 3},
                      {0, 2}};
    answer = {1, 1};
    assert(answer == solve.shortestDistanceAfterQueries(n, queries));

    return 0;
}
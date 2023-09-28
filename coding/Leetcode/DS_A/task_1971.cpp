// https://leetcode.com/problems/find-if-path-exists-in-graph/description/
// Created by ruslan515 on 25.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        bool answer = false;
        if (n == 1 || source == destination) {
            return true;
        }
        vector<bool> visited(n);
        vector<vector<int>> ed(n);
        int start, end;
        for (int i = 0; i < edges.size(); ++i) {
            start = edges[i][0];
            end = edges[i][1];
            ed[start].push_back(end);
            ed[end].push_back(start);
        }

        queue<int> q;
        q.push(source);
        visited[source] = true;
        int current;
        while (!q.empty()) {
            current = q.front();
            q.pop();
            int next;
            for (int i = 0; i < ed[current].size(); ++i) {
                next = ed[current][i];
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                    if (next == destination) {
                        return true;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    int n, source, destination;
    vector<vector<int>> edges;
    bool answer;
    Solution solve;

    n = 3, edges = {{0, 1},
                    {1, 2},
                    {2, 0}}, source = 0, destination = 2;
    answer = true;
    assert(answer == solve.validPath(n, edges, source, destination));

    n = 6, edges = {{0, 1},
                    {0, 2},
                    {3, 5},
                    {5, 4},
                    {4, 3}}, source = 0, destination = 5;
    answer = false;
    assert(answer == solve.validPath(n, edges, source, destination));

    return 0;
}
// https://leetcode.com/problems/longest-cycle-in-a-graph/description/
// Created by ruslan515 on 26.03.23.
//

#include <bits/stdc++.h>

using namespace std;

const int DEF_COLOR = 0;

class Solution {
public:
    void dfs(
            int v,
            vector<int> &edge,
            vector<int> &color,
            int current,
            int start,
            bool &loop,
            int &lenCycle,
            int comp
    ) {
        color[v] = comp;
        int u;
        u = edge[v];
        if (u != -1) {
            ++lenCycle;
            if (color[u] == DEF_COLOR) {
                dfs(u, edge, color, current, start, loop, lenCycle,comp);
            } else {
                if (u == start) {
                    loop = true;
                } else {
                    loop = false;
                }

            }
        }

        return;
    }

    int longestCycle(vector<int> &edges) {
        int n = edges.size();
        vector<int> lensLoop;
        vector<int> color(n, 0);
        int comp = 0;
        for (int v = 0; v < n; ++v) {
            if (color[v] == DEF_COLOR) {
                ++comp;
                int current = 1;
                int start = v;
                bool loop = false;
                int lenCycle = 0;
                dfs(v, edges, color, current, start, loop, lenCycle, comp);
                if (loop) {
                    lensLoop.push_back(lenCycle);
                }
            }
        }
        int answer = -1;
        if (lensLoop.size() > 0) {
            vector<int> ::iterator result;
             result = max_element(lensLoop.begin(), lensLoop.end());
             answer = *result;
        }

        return answer;
    }
};

void read_data(vector<int> &edges) {
    int a;
    while (cin >> a) {
        edges.push_back(a);
    }
    return;
}

int main() {
    vector<int> edges;
    read_data(edges);
    Solution solve;
    edges = {3, 3, 4, 2, 3};
    assert(solve.longestCycle(edges) == 3);

    edges = {2, -1, 3, 1};
    assert(solve.longestCycle(edges) == -1);

    return 0;
}
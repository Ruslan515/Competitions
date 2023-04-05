// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// Created by ruslan515 on 23.03.23.
//

#include <bits/stdc++.h>

using namespace std;

const int DEF_COLOR = 0;

class Solution {
public:
    void dfs(int v, vector<vector<int>> &edge, vector<int> &color, int current) {
        color[v] = current;
        int u;
        for (int i = 0; i < edge[v].size(); ++i) {
            u = edge[v][i];
            if (color[u] == DEF_COLOR) {
                dfs(u, edge, color, current);
            }
        }
        return;
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        int cntEdges = connections.size();
        if (cntEdges < n - 1) {
            return -1;
        }
        vector<vector<int>> edge(n, vector<int>());
        vector<int> color(n, 0);
        int v, u;
        for (int i = 0; i < cntEdges; ++i) {
            v = connections[i][0];
            u = connections[i][1];
            edge[v].push_back(u);
            edge[u].push_back(v);
        }

        int answer = 0;
        for (int v = 0; v < n; ++v) {
            if (color[v] == DEF_COLOR) {
                ++answer;
                dfs(v, edge, color, answer);
            }
        }
        --answer;
        return answer;

    }
};

void read_data(int &n, vector<vector<int>> &connections) {
    cin >> n;
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        connections.push_back({a, b});
    }
    return;
}

int main() {
    vector<vector<int>> connections;
    int n;
    read_data(n, connections);
    Solution solve;
    cout << solve.makeConnected(n, connections) << "\n";

    return 0;
}
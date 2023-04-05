// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
// Created by ruslan515 on 25.03.23.
//

#include <bits/stdc++.h>

using namespace std;

const int DEF_COLOR = 0;

class Solution {
public:
    void dfs(
            int v,
            vector<vector<int>> &edge,
            vector<int> &color,
            int current,
            set<int> &setCurrent
            ) {
        color[v] = current;
        setCurrent.insert(v);
        int u;
        for (int i = 0; i < edge[v].size(); ++i) {
            u = edge[v][i];
            if (color[u] == DEF_COLOR) {
                dfs(u, edge, color, current, setCurrent);
            }
        }
        return;
    }

    long long countPairs(int n, vector<vector<int>> &edges) {
        int cntEdges = edges.size();
        long long answer = 0;
        if (cntEdges == 0) {
            answer = (long long )n * (n - 1) / 2;
            return answer;
        }

        vector<vector<int>> edge(n, vector<int>());
        vector<int> color(n, 0);
        int v, u;
        for (int i = 0; i < cntEdges; ++i) {
            v = edges[i][0];
            u = edges[i][1];
            edge[v].push_back(u);
            edge[u].push_back(v);
        }

//        vector<set<int>> vSet;
        vector<long long > sizeSubComp;
        int cntComponent = 0;
        for (int v = 0; v < n; ++v) {
            if (color[v] == DEF_COLOR) {
                set<int> setCurrent;
                ++cntComponent;
                dfs(v, edge, color, cntComponent, setCurrent);
//                vSet.push_back(setCurrent);
                long long s = setCurrent.size();
                sizeSubComp.push_back(s);
            }
        }

        if (cntComponent != 0) {
            int m = sizeSubComp.size();
            for(int i = 0; i < m - 1; ++i) {
                long long x = sizeSubComp[i];
                for (int j = i + 1; j < m; ++j) {
                    long long  y = x * sizeSubComp[j];
                    answer += y;
                }
            }
        }
        return answer;
    }
};

void read_data(int &n, vector<vector<int>> &edges) {
    cin >> n;
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        edges.push_back({a, b});
    }
    return;
}

int main() {
    vector<vector<int>> edges;
    int n;
    read_data(n, edges);
    Solution solve;
    cout << solve.countPairs(n, edges) << "\n";

    return 0;
}
// https://leetcode.com/contest/weekly-contest-345/problems/count-the-number-of-complete-components/
// Created by Ruslan Khalikov on 14.05.2023.
//

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int v, vector<int> &comp, vector<bool> &used, vector<vector<int>> &g) {
        used[v] = true;
        comp.push_back(v);
        for(int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                dfs(to, comp, used, g);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int> > &edges) {
        int answer = 0;

        vector<vector<int> > g(n, vector<int>());
        int size = edges.size();
        for (int i = 0; i < size; ++i) {
            int v = edges[i][0];
            int u = edges[i][1];
            g[v].push_back(u);
        }

        vector<bool> used;
        vector<int> comp;
        for (int i = 0; i < n; ++i) {
            used.push_back(false);
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                comp.clear();
                dfs(i, comp, used, g);
                bool label = true;
                for (int j = 0; j < comp.size(); ++j) {
                    if (g[j].size() != comp.size()) {
                        label = false;
                        break;
                    }
                }
                if (label){
                    ++answer;
                }

            }
        }

        return answer;
    }
};


int main() {
    int n;
    vector<vector<int>> x;
    vector<vector<int> > edges;
    int answer;
    Solution solve;

    n = 6;
    edges = {{0, 1},
             {0, 2},
             {1, 2},
             {3, 4}};
    answer = 3;
    assert(solve.countCompleteComponents(n, edges) == answer);

    n = 6;
    edges = {{0, 1},
             {0, 2},
             {1, 2},
             {3, 4},
             {3, 5}};
    answer = 1;
    assert(solve.countCompleteComponents(n, edges) == answer);

    return 0;
}
// https://leetcode.com/contest/weekly-contest-381/problems/count-the-number-of-houses-at-a-certain-distance-i/
// Created by omega515 on 21.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> answer;

    vector<int> dfs(int n, int s, vector<vector<int>> &adj) {
        vector<int> dist(n, n);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u: adj[v]) {
                if (dist[u] > dist[v] + 1) {
                    if (dist[u] != n) {
                        --answer[dist[u]];
                    }
                    dist[u] = dist[v] + 1;
                    ++answer[dist[u]];
                    q.push(u);
                }
            }
        }
        return dist;
    }

    vector<long long> countOfPairs(int n, int x, int y) {
        answer.resize(n + 1, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        if (x != y) {
            adj[x - 1].push_back(y - 1);
            adj[y - 1].push_back(x - 1);
        }

        vector<vector<int>> allDist;
        for (int i = 0; i < n; ++i) {
            allDist.push_back(dfs(n, i, adj));
        }

//        int val;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                val = allDist[i][j];
//                if (val != 0) {
//                    ++answer[val - 1];
//                }
//
//            }
//        }
//
        answer.erase(answer.begin());
        return answer;
    }
};

int main() {
    int n, x, y;
    vector<long long> answer;
    Solution solve;

    n = 3, x = 1, y = 3;
    answer = {6, 0, 0};
    assert(answer == solve.countOfPairs(n, x, y));

    n = 4, x = 1, y = 1;
    answer = {6, 4, 2, 0};
    assert(answer == solve.countOfPairs(n, x, y));

    n = 5, x = 2, y = 4;
    answer = {10, 8, 2, 0, 0};
    assert(answer == solve.countOfPairs(n, x, y));

    return 0;
}


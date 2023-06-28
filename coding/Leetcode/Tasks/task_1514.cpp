// https://leetcode.com/problems/path-with-maximum-probability/
// Created by ruslan515 on 28.06.23.
//

#include <bits/stdc++.h>

using namespace std;

const double INF = DBL_MAX;

class Solution {
public:
    void
    convertEdges(vector<vector<int>> &edgesIn, vector<double> &succProb,
                 vector<vector<pair<int, double>>> &edgesOut, int n) {
        int u, v;
        double w;
        for (int i = 0; i < edgesIn.size(); ++i) {
            u = edgesIn[i][0];
            v = edgesIn[i][1];
            w = succProb[i];
            w = -log2(w);
            edgesOut[u].push_back({v, w});
            edgesOut[v].push_back({u, w});
        }
    }

    double maxProbability(int n, vector<vector<int>> &edgesIn, vector<double> &succProb, int start, int end) {
        vector<vector<pair<int, double>>> edges(n, vector<pair<int, double>>());
        convertEdges(edgesIn, succProb, edges, n);
        double answer = 0.0;

        vector<double> d(n, INF);
        d[start] = 0.0;

        set<pair<double, int>> q;
        q.insert({0.0, start});
        double w;
        int v;
        while (!q.empty()) {
            auto top = q.begin();
            int u = top->second;
            q.erase(top);
            for (auto next: edges[u]) {
                v = next.first;
                w = next.second;
                if (d[v] > d[u] + w) {
                    if (q.find({d[v], v}) != q.end()) {
                        q.erase(q.find({d[v], v}));
                    }
                    d[v] = d[u] + w;
                    q.insert({d[v], v});
                }
            }
        }

        answer = pow(2, -d[end]);
        return answer;
    }
};

int main() {
    int n;
    vector<vector<int>> edges;
    vector<double> succProb;
    int start;
    int end;
    double answer;
    Solution solve;

    n = 3, edges = {{0, 1},
                    {1, 2},
                    {0, 2}}, succProb = {0.5, 0.5, 0.2}, start = 0, end = 2;
    answer = 0.25000;
    assert(answer == solve.maxProbability(n, edges, succProb, start, end));

    n = 3, edges = {{0, 1},
                    {1, 2},
                    {0, 2}}, succProb = {0.5, 0.5, 0.3}, start = 0, end = 2;
    answer = 0.30000;
    assert(answer == solve.maxProbability(n, edges, succProb, start, end));

    n = 3, edges = {{0, 1}}, succProb = {0.5}, start = 0, end = 2;
    answer = 0.00000;
    assert(answer == solve.maxProbability(n, edges, succProb, start, end));


    return 0;
}

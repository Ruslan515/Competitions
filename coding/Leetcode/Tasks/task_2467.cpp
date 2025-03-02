// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/?envType=daily-question&envId=2025-02-24
// Created by omega515 on 24.02.2025.
//

#include <bits/stdc++.h>

using namespace std;

#define prQ pair<int, queue<int>>

class Solution {
public:
    vector<vector<int>> constructGraph(vector<vector<int> > &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> gr(n, vector<int>());
        int u, v;
        for (int i = 0; i < edges.size(); ++i) {
            u = edges[i][0];
            v = edges[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        return gr;
    }

    queue<int> pathBob2Zero(vector<vector<int>> &gr, int bob) {
        int n = gr.size();
        vector<bool> used(n, false);
        used[bob] = true;
        queue<int> queue1;
        queue1.push(bob);
        prQ p(bob, queue1);
        queue<prQ> q;
        q.push(p);
        int from;
        queue<int> qTmp;
        qTmp.push(bob);
        while (!q.empty()) {
            int sizeQ = q.size();
            for (int i = 0; i < sizeQ; ++i) {
                prQ tmp = q.front();
                q.pop();
                from = tmp.first;
                qTmp = tmp.second;
                vector<int> to = gr[from];
                for (int j = 0; j < to.size(); ++j) {
                    int v = to[j];
                    if (v == 0) {
                        qTmp.push(v);
                        return qTmp;
                    }
                    if (!used[v]) {
                        used[v] = true;
                        queue<int> copy = qTmp;
                        copy.push(v);
                        q.push({v, copy});
                    }
                }
            }
        }
        return qTmp;
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1e9;
        int n = edges.size() + 1;
        if (n == 2) {
            return amount[0];
        }
        vector<vector<int>> gr = this->constructGraph(edges);
        queue<int> qBob = this->pathBob2Zero(gr, bob);

        queue<pair<int, int>> q;
        q.push({0, amount[0]});

        vector<bool> used(n, false);
        used[0] = true;
        int currentNode, currentSum;
        amount[bob] = 0;
        qBob.pop();
        pair<int, int> tmp;
        int currentBob;
        while (!q.empty()) {
            int sizeQ = q.size();
            if (!qBob.empty()) {
                currentBob = qBob.front();
                qBob.pop();

            } else {
                currentBob = -1;
            }
            vector<int> neighbors;
            for (int i = 0; i < sizeQ; ++i) {
                tmp = q.front();
                q.pop();
                currentNode = tmp.first;
                currentSum = tmp.second;

                neighbors = gr[currentNode];
                if (neighbors.size() == 1 && used[neighbors[0]]) {
                    answer = max(answer, currentSum);
                    continue;
                }
                int v;
                for (int j = 0; j < neighbors.size(); ++j) {
                    v = neighbors[j];
                    if (!used[v]) {
                        if (v == currentBob) {
                            q.push({v, currentSum + amount[v] / 2});
                        } else {
                            q.push({v, currentSum + amount[v]});
                        }
                        used[v] = true;
                    }
                }
            }
            if (currentBob != -1) {
                amount[currentBob] = 0;
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> edges;
    int bob;
    vector<int> amount;
    int answer;
    Solution solve;

    edges = {{0,  21},
             {0,  6},
             {0,  29},
             {1,  3},
             {1,  38},
             {2,  32},
             {2,  34},
             {2,  27},
             {3,  24},
             {3,  8},
             {4,  5},
             {4,  21},
             {5,  11},
             {5,  28},
             {6,  27},
             {7,  23},
             {7,  21},
             {8,  12},
             {8,  22},
             {8,  36},
             {9,  10},
             {10, 17},
             {12, 15},
             {13, 24},
             {14, 29},
             {16, 25},
             {16, 35},
             {16, 39},
             {17, 19},
             {17, 39},
             {18, 37},
             {18, 26},
             {20, 27},
             {26, 38},
             {26, 30},
             {29, 30},
             {29, 39},
             {30, 31},
             {33, 34}};
    bob = 31;
    amount = {562, 5200, 8954, -1176, 3208, -140, 940, 9548, -662, -4974, -9054, -5868, -3888, 404, -5184, 418, 3890,
              -9434, -8184, 642, -5484, -4542, -372, -7818, -268, 4512, -2648, -9016, 8782, 542, -8812, -7262, -9804,
              6622, -7030, 8164, 8354, -8176, 5412, -5648};
    answer = 6;
    assert(answer == solve.mostProfitablePath(edges, bob, amount));

    edges = {
            {0, 1},
            {1, 2},
            {1, 3},
            {3, 4}
    }, bob = 3, amount = {-2, 4, 2, -4, 6};
    answer = 6;
    assert(answer == solve.mostProfitablePath(edges, bob, amount));

    edges = {{0, 1}}, bob = 1, amount = {-7280, 2350};
    answer = -7280;
    assert(answer == solve.mostProfitablePath(edges, bob, amount));

    return 0;
}

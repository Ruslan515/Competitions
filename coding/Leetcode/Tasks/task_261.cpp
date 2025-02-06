// https://leetcode.com/problems/graph-valid-tree/description/?envType=weekly-question&envId=2025-01-29
// Created by omega515 on 30.01.25.
//
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    typedef pair<int, int> pr;

    bool validTree(int n, vector<vector<int>> &edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (n == 1) {
            return true;
        }
        bool answer = false;
        int cntEdge = edges.size();
        int diff = n - cntEdge;
        if (diff != 1) {
            return answer;
        }

        vector<vector<int>> newEdges(n, vector<int>());
        int u, v;
        for (auto edge: edges) {
            u = edge[0];
            v = edge[1];
            newEdges[u].push_back(v);
            newEdges[v].push_back(u);
        }

        vector<bool> used(n, false);

        queue<pr> q;
        q.push({0, -1});
        pr currentPr;
        int currentNode, parent;
        while (!q.empty()) {
            int sizeQueue = q.size();
            for (int i = 0; i < sizeQueue; ++i) {
                currentPr = q.front();
                q.pop();
                currentNode = currentPr.first;
                used[currentNode] = true;
                parent = currentPr.second;
                vector<int> neigh = newEdges[currentNode];
                int sizeN = neigh.size();
                if (sizeN == 0) {
                    return answer;
                }
                for (int j = 0; j < sizeN; ++j) {
                    int u = neigh[j];
                    if (u != parent && used[u]) {
                        return answer;
                    } else if (!used[u]) {
                        q.push({u, currentNode});
                    }
                }

            }
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                return answer;
            }
        }
        return true;
    }
};


int main() {
    int n;
    vector<vector<int>> edges;
    bool answer;
    Solution solve;

    n = 6, edges = {{0, 1},
                    {2, 3},
                    {4, 5},
                    {3, 4},
                    {2, 5}};
    answer = false;
    assert(answer == solve.validTree(n, edges));


    n = 1, edges = {};
    answer = true;
    assert(answer == solve.validTree(n, edges));

    n = 5, edges = {{0, 1},
                    {0, 2},
                    {0, 3},
                    {1, 4}};
    answer = true;
    assert(answer == solve.validTree(n, edges));

    n = 5, edges = {{0, 1},
                    {1, 2},
                    {2, 3},
                    {1, 3},
                    {1, 4}};
    answer = false;
    assert(answer == solve.validTree(n, edges));

    n = 5, edges = {{1, 2},
                    {2, 3},
                    {1, 3},
                    {1, 4}};
    answer = false;
    assert(answer == solve.validTree(n, edges));

    return 0;
}


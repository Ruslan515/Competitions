// https://leetcode.com/problems/detonate-the-maximum-bombs/
// Created by ruslan515 on 02.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        int answer = 1;
        map<int, set<int>> dictSet;
        int n = bombs.size();
        for (int i = 0; i < n; ++i) {
            vector<int> bomb = bombs[i];
            int x = bomb[0];
            int y = bomb[1];
            int r = bomb[2];
            long long rSq = (long long) r * r;
            set<int> setNodes;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    vector<int> bomb_j = bombs[j];
                    int x_j = bomb_j[0];
                    int y_j = bomb_j[1];
                    long long l = (long long) (x - x_j) * (x - x_j) + (long long) (y - y_j) * (y - y_j);
                    if (l <= rSq) {
                        setNodes.insert(j);
                    }
                }
            }
            if (!setNodes.empty()) {
                dictSet[i] = setNodes;
            }

        }
        if (!dictSet.empty()) {
            for (const auto &[key, value]: dictSet) {
                set<int> unionSet;
                vector<bool> used(n, false);
                unionSet.insert(key);
                queue<int> q;
                q.push(key);
                used[key] = true;
                set<int> st;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    st = dictSet[v];
                    for (int u: st) {
                        if (!used[u]) {
                            used[u] = true;
                            if (dictSet.count(u)) {
                                q.push(u);
                            }
                        }
                    }
                }
                int t = std::count(used.begin(), used.end(), true);
                answer = max(answer, t);
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> bombs;
    int answer;
    Solution solve;

    bombs = {{1, 2, 3},
             {2, 3, 1},
             {3, 4, 2},
             {4, 5, 3},
             {5, 6, 4}};
    answer = 5;
    assert(answer = solve.maximumDetonation(bombs));

//    for (int i = 0; i < 100; ++i) {
//        int x = i;
//        int y = i * 10;
//        int r = i * i;
//        bombs.push_back({x, y, r});
//    }
//    answer = 1;
//    assert(answer = solve.maximumDetonation(bombs));

    bombs = {{1, 1, 100000}};
    answer = 1;
    assert(answer = solve.maximumDetonation(bombs));


    bombs = {{2, 1, 3},
             {6, 1, 4}};
    answer = 2;
    assert(answer = solve.maximumDetonation(bombs));

    bombs = {{1,  1,  5},
             {10, 10, 5}};
    answer = 1;
    assert(answer = solve.maximumDetonation(bombs));


    return 0;
}
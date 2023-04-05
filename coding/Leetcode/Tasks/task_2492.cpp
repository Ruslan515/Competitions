// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
// Created by ruslan515 on 22.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>> &roads) {
        vector<vector<int>> adj(n, vector<int>());
        int size_roads = roads.size();
        for (int i = 0; i < size_roads; ++i) {
            vector<int> temp = roads[i];
            int u = temp[0];
            int v = temp[1];
            int dist = temp[2];
            vector<int> t = {v, dist};
            adj[u].push_back(t);
        }

    }
};

void read_data(vector<vector<int>> &roads, int &n) {
    cin >> n;
    int a, b, d;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        cin >> a >> b >> d;
        roads.push_back({a, b, d});
    }
    return;
}

int main() {
    vector<vector<int>> roads;
    int n;
    read_data(roads, n);
    Solution solve;
    cout << solve.minScore(n, roads) << "\n";

    return 0;
}
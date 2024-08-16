// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26
// Created by omega515 on 27.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void bfs(int n,
             int start,
             unordered_map<int, set<int>> &mp,
             vector<vector<pair<int, int>>> newEdges,
             int distanceThreshold
    ) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        int current;
        int sums = 0;
        while (!q.empty()) {
            int sizeQ = q.size();
            for (int i = 0; i < sizeQ; ++i) {
                pair current = q.front();
                q.pop();
                int from = current.first;
                int w_curr = current.second;
                visited[from] = true;
                vector<pair<int, int>> edge = newEdges[from];
                int to, w;
                for (pair<int, int> p: edge) {
                    to = p.first;
                    w = p.second;
                    if (!visited[to] && (w_curr + w) <= distanceThreshold) {
                        mp[start].insert(to);
                        q.push({to, w_curr + w});
                    }
                }
            }
        }
        return;

    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        vector<vector<pair<int, int>>> newEdges(n, vector<pair<int, int>>());
        int from, to, w;
        for (vector<int> v: edges) {
            from = v[0];
            to = v[1];
            w = v[2];
            newEdges[from].push_back({to, w});
            newEdges[to].push_back({from, w});
        }

        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[i] = {};
        }
        for (int start = 0; start < n; ++start) {
            bfs(n, start, mp, newEdges, distanceThreshold);

        }

        set<int> st;
        int minLen = INT_MAX;
        for (auto const &item: mp) {
            int key = item.first;
            st = item.second;
            if (st.size() < minLen) {
                minLen = st.size();
                answer = key;
            } else if (st.size() == minLen) {
                answer = max(answer, key);
            }
        }


        return answer;
    }
};


int main() {
    int n;
    vector<vector<int>> edges;
    int distanceThreshold;
    int answer;
    Solution solve;

    n = 6, edges = {{0, 1, 10},
                    {0, 2, 1},
                    {2, 3, 1},
                    {1, 3, 1},
                    {1, 4, 1},
                    {4, 5, 10}};
    distanceThreshold = 20;
    answer = 5;
    assert(answer == solve.findTheCity(n, edges, distanceThreshold));

    n = 6, edges = {{0, 3, 7},
                    {2, 4, 1},
                    {0, 1, 5},
                    {2, 3, 10},
                    {1, 3, 6},
                    {1, 2, 1}};
    distanceThreshold = 417;
    answer = 5;
    assert(answer == solve.findTheCity(n, edges, distanceThreshold));

    n = 4, edges = {{0, 1, 3},
                    {1, 2, 1},
                    {1, 3, 4},
                    {2, 3, 1}}, distanceThreshold = 4;
    answer = 3;
    assert(answer == solve.findTheCity(n, edges, distanceThreshold));

    n = 5, edges = {{0, 1, 2},
                    {0, 4, 8},
                    {1, 2, 3},
                    {1, 4, 2},
                    {2, 3, 1},
                    {3, 4, 1}}, distanceThreshold = 2;
    answer = 0;
    assert(answer == solve.findTheCity(n, edges, distanceThreshold));

    return 0;
}
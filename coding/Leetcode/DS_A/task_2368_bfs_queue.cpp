// https://leetcode.com/problems/reachable-nodes-with-restrictions/description/
// Created by ruslan515 on 28.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> convert(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> ans;
        int start, end;
        for (auto v: edges) {
            start = v[0];
            end = v[1];
            ans[start].push_back(end);
            ans[end].push_back(start);
        }
        return ans;
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        int answer = 0;
        set<int> s_rest(restricted.begin(), restricted.end());
        unordered_map<int, vector<int>> mp = convert(edges);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int current;
        answer++;
        while (!q.empty()) {
            int size_q = q.size();
            for (int j = 0; j < size_q; ++j) {
                current = q.front();
                q.pop();
                visited[current] = true;
                vector<int> childs = mp[current];
                int countChilds = childs.size();
                for (int i = 0; i < countChilds; ++i) {
                    int child = childs[i];
                    if (s_rest.find(child) == s_rest.end() && !visited[child]) {
                        q.push(child);
                        answer++;
                    }
                }

            }
        }

        return answer;
    }
};

int main() {
    int n;
    vector<vector<int>> edges;
    vector<int> restricted;
    int answer;
    Solution solve;

    n = 7, edges = {{0, 1},
                    {1, 2},
                    {3, 1},
                    {4, 0},
                    {0, 5},
                    {5, 6}}, restricted = {4, 5};
    answer = 4;
    assert(answer == solve.reachableNodes(n, edges, restricted));

    n = 7, edges = {{0, 1},
                    {0, 2},
                    {0, 5},
                    {0, 4},
                    {3, 2},
                    {6, 5}}, restricted = {4, 2, 1};
    answer = 3;
    assert(answer == solve.reachableNodes(n, edges, restricted));

    return 0;
}
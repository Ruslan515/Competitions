// https://leetcode.com/contest/biweekly-contest-142/problems/find-subtree-sizes-after-changes/
// Created by omega515 on 26.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int> &parent, string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = parent.size();
        // Создаем список смежности для исходного дерева
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Находим новых родителей
        vector<int> newParent = parent;
        for (int i = 1; i < n; i++) {
            int curr = parent[i];
            while (curr != -1) {
                if (s[curr] == s[i]) {
                    newParent[i] = curr;
                    break;
                }
                curr = parent[curr];
            }
        }

        // Создаем новое дерево
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Считаем размеры поддеревьев
        vector<int> answer(n);
        function<int(int)> dfs = [&](int node) {
            int size = 1;
            for (int child: newAdj[node]) {
                size += dfs(child);
            }
            answer[node] = size;
            return size;
        };

        dfs(0);
        return answer;
    }
};

int main() {
    vector<int> parent;
    string s;
    vector<int> answer;
    Solution solve;

    parent = {-1, 0, 0, 1, 1, 1}, s = "abaabc";
    answer = {6, 3, 1, 1, 1, 1};
    assert(answer == solve.findSubtreeSizes(parent, s));

    parent = {-1, 0, 4, 0, 1}, s = "abbba";
    answer = {5, 2, 1, 1, 1};
    assert(answer == solve.findSubtreeSizes(parent, s));

    return 0;
}

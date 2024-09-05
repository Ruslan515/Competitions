// https://leetcode.com/problems/all-paths-from-source-to-target/description/
// Created by omega515 on 05.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> answer;

    void backtracking(
            vector<vector<int>> &graph,
            vector<int> &current, int idx, int n
    ) {
        if (idx == n - 1) {
            answer.push_back(current);
            return;
        }
        vector<int> neighbors = graph[idx];
        for (int i = 0; i < neighbors.size(); ++i) {
            current.push_back(neighbors[i]);
            backtracking(graph, current, neighbors[i], n);
            current.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);


        vector<int> current{0};
        int n = graph.size();
        backtracking(graph, current, 0, n);

        return answer;
    }
};

int main() {
    vector<vector<int>> graph;
    vector<vector<int>> answer;
    Solution solve;

    graph = {{4, 3, 1},
             {3, 2, 4},
             {3},
             {4},
             {}};
    answer = {{0, 4},
              {0, 3, 4},
              {0, 1, 3, 4},
              {0, 1, 2, 3, 4},
              {0, 1, 4}};
    assert(answer == solve.allPathsSourceTarget(graph));

    graph = {{1, 2},
             {3},
             {3},
             {}};
    answer = {{0, 1, 3},
              {0, 2, 3}};
    assert(answer == solve.allPathsSourceTarget(graph));

    return 0;
}

// https://leetcode.com/problems/find-eventual-safe-states/
// Created by ruslan515 on 12.07.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector<int> answer;
        unordered_set<int> stEnd, stNotEnd;
        int n = graph.size();
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) {
                stEnd.insert(i);
                answer.push_back(i);
            } else {
                stNotEnd.insert(i);
            }
        }

        unordered_set<int>::iterator it = stNotEnd.begin();
        for (; it != stNotEnd.end(); ++it) {
//            set<pair<int, int>> used;
            int start = *it;
            queue<int> q;
            q.push(start);

            bool label = false;
            while (!q.empty() and !label) {
                int size_q = q.size();
                for (int i = 0; i < size_q; ++i) {
                    int u = q.front();
                    q.pop();
                    vector<int> neighs = graph[u];
                    for (int node: neighs) {
//                        if (used.find(make_pair(u, node)) == used.end()) {
                        if (node != start && node != u) {
                            q.push(node);
//                            used.insert(make_pair(u, node));
                        } else {
                            label = true;
                            break;
                        }
                    }
                    if (label) {
                        break;
                    }
                }
            }
            if (!label) {
                answer.push_back(start);
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    vector<vector<int>> graph;
    vector<int> answer;
    Solution solve;

    graph = {{2, 3},
             {2, 3, 4},
             {3, 4},
             {},
             {1}};
    answer = {3};
    assert(answer == solve.eventualSafeNodes(graph));

    graph = {{0},
             {2, 3, 4},
             {3, 4},
             {0, 4},
             {}};
    answer = {4};
    assert(answer == solve.eventualSafeNodes(graph));

    graph = {{},
             {0, 2, 3, 4},
             {3},
             {4},
             {}};
    answer = {0, 1, 2, 3, 4};
    assert(answer == solve.eventualSafeNodes(graph));

    graph = {{1, 2},
             {2, 3},
             {5},
             {0},
             {5},
             {},
             {}};
    answer = {2, 4, 5, 6};
    assert(answer == solve.eventualSafeNodes(graph));

    graph = {{1, 2, 3, 4},
             {1, 2},
             {3, 4},
             {0, 4},
             {}};
    answer = {4};
    assert(answer == solve.eventualSafeNodes(graph));
    return 0;
}
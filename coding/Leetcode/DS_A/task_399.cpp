// https://leetcode.com/problems/evaluate-division/
// Created by ruslan515 on 03.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void createGr(
            vector<vector<string>> &equations,
            vector<double> &values,
            unordered_map<string, vector<pair<string, double>>> &mp,
            set<string> &nodes
    ) {
        int n = equations.size();
        string u, v;
        double val;
        for (int i = 0; i < n; ++i) {
            u = equations[i][0];
            v = equations[i][1];
            nodes.insert(u);
            nodes.insert(v);
            val = values[i];
            mp[u].push_back(make_pair(v, val));
            mp[v].push_back(make_pair(u, 1 / val));
        }
    }

    double bfs(
            unordered_map<string, vector<pair<string, double>>> &mp,
            string start,
            string end
    ) {
        double ans = -1.0;
        set<string> visited;
        queue<pair<string, double>> q;
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                auto [node, val] = q.front();
                q.pop();
                visited.insert(node);
                string next;
                double valNext;
                vector<pair<string, double>> neighbors = mp[node];
                for (auto pr: neighbors) {
                    next = pr.first;
                    if (visited.find(next) == visited.end()) {
                        valNext = pr.second;
                        if (next == end) {
                            ans = val * valNext;
                            return ans;
                        } else {
                            q.push(make_pair(next, val * valNext));
                        }
                    }
                }
            }

        }

        return ans;
    }

    vector<double> calcEquation(
            vector<vector<string>> &equations,
            vector<double> &values, vector<vector<string>> &queries
    ) {
        vector<double> answer;
        unordered_map<string, vector<pair<string, double>>> mp;
        set<string> nodes;
        createGr(equations, values, mp, nodes);
        string start, end;
        for (auto q: queries) {
            start = q[0];
            end = q[1];
            if ((nodes.find(start) == nodes.end()) || (nodes.find(end) == nodes.end())) {
                answer.push_back(-1.0);
                continue;
            } else if (start == end) {
                answer.push_back(1.0);
                continue;
            }
            double ans = bfs(mp, start, end);
            answer.push_back(ans);
        }
        return answer;
    }
};

int main() {
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    vector<double> answer;
    Solution solve;

    equations = {{"a", "b"},
                 {"b", "c"}}, values = {2.0, 3.0}, queries = {{"a", "c"},
                                                              {"b", "a"},
                                                              {"a", "e"},
                                                              {"a", "a"},
                                                              {"x", "x"}};
    answer = {6.00000, 0.50000, -1.00000, 1.00000, -1.00000};
    assert(answer == solve.calcEquation(equations, values, queries));

    equations = {{"a",  "b"},
                 {"b",  "c"},
                 {"bc", "cd"}}, values = {1.5, 2.5, 5.0}, queries = {{"a",  "c"},
                                                                     {"c",  "b"},
                                                                     {"bc", "cd"},
                                                                     {"cd", "bc"}};
    answer = {3.75000, 0.40000, 5.00000, 0.20000};
    assert(answer == solve.calcEquation(equations, values, queries));

    equations = {{"a", "b"}}, values = {0.5}, queries = {{"a", "b"},
                                                         {"b", "a"},
                                                         {"a", "c"},
                                                         {"x", "y"}};
    answer = {0.50000, 2.00000, -1.00000, -1.00000};
    assert(answer == solve.calcEquation(equations, values, queries));

    return 0;
}
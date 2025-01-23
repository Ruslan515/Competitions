// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-i/
// Created by ruslan515 on 01.10.23.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void countV(vector<int> &edges, int node, int n, vector<int> &answer) {
        int answerDist = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(node, 1));
        vector<bool> visited(n);
        bool loop = false;
        while (!q.empty()) {
            auto [current, dist] = q.front();
            q.pop();
            if (current == node) {
                loop = true;
            }
            answerDist = dist;
            visited[current] = true;
            int next = edges[current];
            if (!visited[next]) {
                q.push(make_pair(next, dist + 1));
            }
        }
        answer[node] = answerDist;

        if (loop) {
            vector<bool> visited1;
            q.push(make_pair(node, answerDist));
            while (!q.empty()) {
                auto [current, dist] = q.front();
                q.pop();
                answer[current] = dist;
                visited[current] = true;
                int next = edges[current];
                if (!visited[next]) {
                    q.push(make_pair(next, dist));
                }
            }
        } else {
            vector<bool> visited1;
            q.push(make_pair(node, answerDist));
            while (!q.empty()) {
                auto [current, dist] = q.front();
                q.pop();
                answer[current] = dist;
                visited[current] = true;
                int next = edges[current];
                if (!visited[next]) {
                    q.push(make_pair(next, dist - 1));
                }
            }
        }

    }

    vector<int> countVisitedNodes(vector<int> &edges) {
        int n = edges.size();
        vector<int> answer(n, -1);
        for (int i = 0; i < n; ++i) {
            if (answer[i] == -1) {
                countV(edges, i, n, answer);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> edges, answer;
    Solution solve;

    edges = {1, 2, 0, 0};
    answer = {3, 3, 3, 4};
    assert(answer == solve.countVisitedNodes(edges));

    edges = {1, 2, 3, 4, 0};
    answer = {5, 5, 5, 5, 5};
    assert(answer == solve.countVisitedNodes(edges));

    return 0;
}

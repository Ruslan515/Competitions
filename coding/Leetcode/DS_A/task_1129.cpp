// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
// Created by ruslan515 on 29.09.23.
//

#include <bits/stdc++.h>

using namespace std;

const int RED = 0;
const int BLUE = 1;

//class Solution {
//public:
//    vector<vector<int>> createGraph(
//            int n,
//            vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges
//    ) {
//        vector<vector<int>> gr(n, vector<int>());
//        for (int i = 0; i < redEdges.size(); ++i) {
//            int start = redEdges[i][0];
//            int end = redEdges[i][1];
//            gr[start].push_back(end);
//        }
//
//        for (int i = 0; i < blueEdges.size(); ++i) {
//            int start = blueEdges[i][0];
//            int end = blueEdges[i][1];
//            gr[start].push_back(end);
//        }
//
//        return gr;
//    }
//
//    vector<int> shortestAlternatingPaths(
//            int n,
//            vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges
//    ) {
//        vector<int> answer(n, -1);
//        set<vector<int>> sRed(redEdges.begin(), redEdges.end());
//        set<vector<int>> sBlue(blueEdges.begin(), blueEdges.end());
//        vector<vector<int>> gr = createGraph(n, redEdges, blueEdges);
//        vector<bool> visited(n, false);
//
//        queue<pair<int, int>> q;
//        q.push(make_pair(0, -1));
//        int dist = 0;
//        while (!q.empty()) {
//            int size_q = q.size();
//
//            for (int i = 0; i < size_q; ++i) {
//                auto [current, color] = q.front();
//                q.pop();
//                visited[current] = true;
//                vector<int> neighbors = gr[current];
//                answer[current] = dist;
//
//                for (auto neigh: neighbors) {
//                    if (!visited[neigh]) {
////                        visited[neigh] = true;
//                        vector<int> edge = {current, neigh};
//                        if (sRed.find(edge) != sRed.end() && color != RED) {
//                            q.push(make_pair(neigh, RED));
//                        } else if (sBlue.find(edge) != sBlue.end() && color != BLUE) {
//                            q.push(make_pair(neigh, BLUE));
//                        }
//                    }
//                }
//            }
//            ++dist;
//        }
//
//        return answer;
//    }
//};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &redEdge: redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto &blueEdge: blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto &[neighbor, color]: adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};

int main() {
    int n;
    vector<vector<int>> redEdges, blueEdges;
    vector<int> answer;
    Solution solve;

    n = 5;
    redEdges = {{0, 1},
                {1, 2},
                {2, 3},
                {3, 4}};
    blueEdges = {{1, 2},
                 {2, 3},
                 {3, 1}};
    answer = {0, 1, 2, 3, 7};
    assert(answer == solve.shortestAlternatingPaths(n, redEdges, blueEdges));

    n = 3, redEdges = {{0, 1},
                       {0, 2}}, blueEdges = {{1, 0}};
    answer = {0, 1, 1};
    assert(answer == solve.shortestAlternatingPaths(n, redEdges, blueEdges));

    n = 3, redEdges = {{0, 1}}, blueEdges = {{1, 2}};
    answer = {0, 1, 2};
    assert(answer == solve.shortestAlternatingPaths(n, redEdges, blueEdges));

    n = 3, redEdges = {{0, 1},
                       {1, 2}}, blueEdges = {};
    answer = {0, 1, -1};
    assert(answer == solve.shortestAlternatingPaths(n, redEdges, blueEdges));

    n = 3, redEdges = {{0, 1}}, blueEdges = {{2, 1}};
    answer = {0, 1, -1};
    assert(answer == solve.shortestAlternatingPaths(n, redEdges, blueEdges));

    return 0;
}
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Created by ruslan515 on 01.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int answer = -1;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1]) {
            return answer;
        }

        vector<pair<int, int>> directions = {
                {-1, -1},
                {-1, 0},
                {-1, 1},
                {0,  -1},
                {0,  1},
                {1,  -1},
                {1,  0},
                {1,  1},

        };
        queue<pair<int, int>> q;
        q.push({0, 0});

        int start_label = 2;
        grid[0][0] = start_label;

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            int row = u.first;
            int col = u.second;
            for (auto dir: directions) {
                int x = dir.first;
                int y = dir.second;
                int next_row = row + x;
                int next_col = col + y;
                if (
                        next_col < 0 || next_row < 0
                        || next_col >= n || next_row >= n
                        || grid[next_row][next_col] != 0
                        ) {
                    continue;
                }
                grid[next_row][next_col] = grid[row][col] + 1;
                q.push({next_row, next_col});
            }
        }

        if (grid[n - 1][n - 1] != 0) {
            answer = grid[n - 1][n - 1] - start_label + 1;
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{0, 1},
            {1, 0}};
    answer = 2;
    assert(answer = solve.shortestPathBinaryMatrix(grid));

    grid = {{0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}};
    answer = 4;
    assert(answer = solve.shortestPathBinaryMatrix(grid));

    grid = {{1, 0, 0},
            {1, 1, 0},
            {1, 1, 0}};
    answer = -1;
    assert(answer = solve.shortestPathBinaryMatrix(grid));

    return 0;
}
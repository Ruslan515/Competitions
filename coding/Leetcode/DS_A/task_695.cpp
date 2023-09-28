// https://leetcode.com/problems/max-area-of-island/description/
// Created by ruslan515 on 27.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> diff = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}
    };
    int n, m;

    bool check(int x, int y) {
        bool answer = (x >= 0 && x < this->n) && (y >= 0 && y < this->m);
        return answer;
    }

    int bfs(int row, int col, vector<vector<int>> &grid) {
        int count = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        grid[row][col] = 0;
        while (!q.empty()) {
            int size_q = q.size();
            for (int k = 0; k < size_q; ++k) {
                auto [i, j] = q.front();
                q.pop();
                count++;
                int x, y;
                for (auto rc: diff) {
                    auto [dx, dy] = rc;
                    x = j + dx;
                    y = i + dy;
                    bool a = check(x, y);
                    if (a) {
                        int val = grid[y][x];
                        if (val) {
                            q.push(make_pair(y, x));
                            grid[y][x] = 0;
                        }

                    }
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int answer = 0;
        this->m = grid.size();
        this->n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = bfs(i, j, grid);
                    answer = max(answer, count);
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}};
    answer = 4;
    assert(answer == solve.maxAreaOfIsland(grid));

    grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    answer = 6;
    assert(answer == solve.maxAreaOfIsland(grid));

    grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
    answer = 0;
    assert(answer == solve.maxAreaOfIsland(grid));

    return 0;
}
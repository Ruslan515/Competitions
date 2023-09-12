// https://leetcode.com/problems/island-perimeter/description/
// Created by ruslan515 on 04.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int answer = 0;
        int row, col;

        row = grid.size();
        col = grid[0].size();

        vector<pair<int, int>> v = {
                make_pair(-1, 0),
                make_pair(1, 0),
                make_pair(0, -1),
                make_pair(0, 1)
        };
        int x, y;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    answer += 4;
                    for (auto temp: v) {
                        auto [x, y] = temp;
                        x += j;
                        y += i;
                        if (x >= 0 && x < col && y >= 0 && y < row) {
                            if (grid[y][x]) {
                                --answer;
                            }
                        }
                    }
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

    grid = {{0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}};
    answer = 16;
    assert(answer == solve.islandPerimeter(grid));

    grid = {{1}};
    answer = 4;
    assert(answer == solve.islandPerimeter(grid));

    grid = {{1, 0}};
    answer = 4;
    assert(answer == solve.islandPerimeter(grid));

    return 0;
}


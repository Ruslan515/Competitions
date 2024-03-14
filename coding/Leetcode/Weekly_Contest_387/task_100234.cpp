// https://leetcode.com/contest/weekly-contest-387/problems/minimum-operations-to-write-the-letter-y-on-a-grid/
// Created by omega515 on 03.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>> &grid) {
        int n = grid.size();
        int answer = n * n;
        unordered_map<int, int> y;
        unordered_map<int, int> not_y;

        int sum_y = n / 2 * 3 + 1, sum_not_y = answer - sum_y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++not_y[grid[i][j]];
            }
        }

        int val;
        for (int i = 0; i < n / 2; ++i) {
            val = grid[i][i];
            ++y[val];

            --not_y[val];
            val = grid[i][n - i - 1];
            ++y[val];
            --not_y[val];
        }
        int j = n / 2;
        for (int i = n / 2; i < n; ++i) {
            val = grid[i][j];
            ++y[val];
            --not_y[val];
        }

        for (int i = 0; i < 3; ++i) {
            int val_y;
            if (y.find(i) == y.end()) {
                val_y = sum_y;
            } else {
                val_y = sum_y - y[i];
            }
            int val_not_y;
            if (not_y.find(i) == not_y.end()) {
                val_not_y = 0;
            } else {
                int tmp_min = n * n;
                for (int j = 0; j < 3; ++j) {
                    if (i != j) {
                        tmp_min = min(tmp_min,not_y[j]);
                    }
                }
                val_not_y = not_y[i] + tmp_min;
            }
            val = val_y + val_not_y;
            answer = min(answer, val);
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;

    int answer;
    Solution solve;

    grid = {{1, 2, 2},
            {1, 1, 0},
            {0, 1, 0}};
    answer = 3;
    assert(answer == solve.minimumOperationsToWriteY(grid));

    grid = {{0, 1, 0, 1, 0},
            {2, 1, 0, 1, 2},
            {2, 2, 2, 0, 1},
            {2, 2, 2, 2, 2},
            {2, 1, 2, 2, 2}};
    answer = 12;
    assert(answer == solve.minimumOperationsToWriteY(grid));

    return 0;
}


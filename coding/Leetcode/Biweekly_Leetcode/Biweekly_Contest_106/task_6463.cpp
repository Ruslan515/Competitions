//
// Created by ruslan515 on 10.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); ++i) {
            if (sum(grid[i]) == 0) {
                return {i};
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = i + 1; j < grid.size(); ++j) {
                if (sumBinaryAnd(grid[i], grid[j]) == 0) {
                    return {i, j};
                }
            }
        }

        return {};
    }

private:
    int sum(const vector<int> &row) {
        int total = 0;
        for (int element: row) {
            total += element;
        }
        return total;
    }

    int sumBinaryAnd(const vector<int> &row1, const vector<int> &row2) {
        int total = 0;
        for (int i = 0; i < row1.size(); ++i) {
            total += row1[i] && row2[i];
        }
        return total;
    }
};

int main() {
    vector<vector<int>> grid;
    vector<int> answer;
    Solution solve;

    grid = {{0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 1, 1, 1}};
    answer = {0, 1};
    assert(answer == solve.goodSubsetofBinaryMatrix(grid));

    return 0;
}


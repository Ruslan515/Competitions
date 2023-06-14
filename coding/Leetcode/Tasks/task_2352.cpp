// https://leetcode.com/problems/equal-row-and-column-pairs/
// Created by ruslan515 on 13.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();
        int answer = 0;
        for(int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int i =0;
                while (i < n && grid[row][i] == grid[i][col]) {
                    ++i;
                }
                if (i == n) {
                    ++answer;
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

    grid = {{3, 2, 1},
            {1, 7, 6},
            {2, 7, 7}};
    answer = 1;
    assert(answer == solve.equalPairs(grid));

    grid = {{3, 1, 2, 2},
            {1, 4, 4, 5},
            {2, 4, 2, 2},
            {2, 4, 2, 2}};
    answer = 3;
    assert(answer == solve.equalPairs(grid));

    return 0;
}
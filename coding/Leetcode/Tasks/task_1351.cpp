// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Created by ruslan515 on 08.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int answer = 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        while (i < m) {
            while (j >= 0 && grid[i][j] < 0) {
                --j;
            }
            int x = m - i;
            int y = n - (j + 1);
            int temp = x * y;
            answer += temp;
            while (i < m && grid[i][j] > 0) {
                ++i;
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{4,  3,  2,  -1},
            {3,  2,  1,  -1},
            {1,  1,  -1, -2},
            {-1, -1, -2, -3}};
    answer = 8;
    assert(answer == solve.countNegatives(grid));

    grid = {{3, 2},
            {1, 0}};
    answer = 0;
    assert(answer == solve.countNegatives(grid));

    return 0;
}
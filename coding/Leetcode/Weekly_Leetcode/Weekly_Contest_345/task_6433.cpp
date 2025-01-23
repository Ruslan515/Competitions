// https://leetcode.com/contest/weekly-contest-345/problems/maximum-number-of-moves-in-a-grid/
// Created by Ruslan Khalikov on 14.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>> &grid) {
        int answer = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int start = 0; start < m; ++start) {

        }

    }
};


int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{2,  4, 3,  5},
            {5,  4, 9,  3},
            {3,  4, 2,  11},
            {10, 9, 13, 15}};
    answer = 3;
    assert(solve.maxMoves(grid) == answer);

    grid = {{3, 2, 4},
            {2, 1, 9},
            {1, 1, 7}};
    answer = 0;
    assert(solve.maxMoves(grid) == answer);

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-102/problems/find-the-width-of-columns-of-a-grid/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n, 0);
        for (int j = 0; j < n; ++j) {
            int max_len = -1;
            for (int i = 0; i < m; ++i) {
                string s = to_string(grid[i][j]);
                int current_len = s.size();
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
            answer[j] = max_len;
        }
        return answer;

    }
};

int main() {
    vector<vector<int>> grid;
    Solution solve;
    vector<int> answer;

    grid = {{1},
            {22},
            {333}};
    answer = {3};
    assert(solve.findColumnWidth(grid) == answer);

    grid = {{-15, 1, 3},
            {15,  7, 12},
            {5,   6, -2}};
    answer = {3, 1, 2};
    assert(solve.findColumnWidth(grid) == answer);


    return 0;
}
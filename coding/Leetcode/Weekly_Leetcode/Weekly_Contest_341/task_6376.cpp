// https://leetcode.com/contest/weekly-contest-341/problems/row-with-maximum-ones/
// Created by ruslan515 on 16.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
        vector<int> ans(2, 0);
        int max_count = -1;
        int idx_row = -1;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int current_count = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    ++current_count;
                }
            }
            if (current_count > max_count) {
                max_count = current_count;
                idx_row = i;
            }
        }
        ans[0] = idx_row;
        ans[1] = max_count;
        return ans;
    }
};


int main() {
    vector<vector<int>> mat;
    vector<int> ans;
    Solution solve;

//    mat = {{0, 1},
//           {1, 0}};
//    ans = {0, 1};
//    assert(solve.rowAndMaximumOnes(mat) == ans);

    mat = {{0, 0, 0},
           {0, 1, 1}};
    ans = {1, 2};
    assert(solve.rowAndMaximumOnes(mat) == ans);

    mat = {{0, 0},
           {1, 1},
           {0, 0}};
    ans = {1, 2};
    assert(solve.rowAndMaximumOnes(mat) == ans);

    return 0;
}
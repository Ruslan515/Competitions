// https://leetcode.com/contest/weekly-contest-384/problems/modify-the-matrix/
// Created by omega515 on 11.02.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
        vector<vector<int>> answer = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int j = 0; j < n; ++j) {
            int maxCol = matrix[0][j];
            vector<int> idx;
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    idx.push_back(i);
                } else {
                    maxCol = max(maxCol, matrix[i][j]);
                }
            }
            for (int i = 0; i < idx.size(); ++i) {
                answer[idx[i]][j] = maxCol;
            }
        }


        return answer;
    }
};

int main() {
    vector<vector<int>> matrix;
    vector<vector<int>> answer;
    Solution solve;

    matrix = {{1, 2,  -1},
              {4, -1, 6},
              {7, 8,  9}};
    answer = {{1, 2, 9},
              {4, 8, 6},
              {7, 8, 9}};
    assert(answer == solve.modifiedMatrix(matrix));

    matrix = {{3, -1},
              {5, 2}};
    answer = {{3, 2},
              {5, 2}};
    assert(answer == solve.modifiedMatrix(matrix));
    return 0;
}


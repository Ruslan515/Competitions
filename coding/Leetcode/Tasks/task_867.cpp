// https://leetcode.com/problems/transpose-matrix/?envType=daily-question&envId=2023-12-10
// Created by omega515 on 10.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));

        int temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                answer[j][i] = matrix[i][j];
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> matrix, answer;
    Solution solve;

    matrix = {{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}};
    answer = {{1, 4, 7},
              {2, 5, 8},
              {3, 6, 9}};
    assert(answer == solve.transpose(matrix));

    return 0;
}
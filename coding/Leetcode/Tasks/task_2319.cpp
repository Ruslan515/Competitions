// https://leetcode.com/problems/check-if-matrix-is-x-matrix/
// Created by ruslan515 on 17.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int answer = 0;

        int primary = 0;
        int second = 0;
        for (int i = 0; i < n; ++i) {
            primary += mat[i][i];
            second += mat[i][n - i - 1];
        }
        if (n % 2 == 1) {
            second -= mat[n / 2][n / 2];
        }
        answer = primary + second;
        return answer;
    }
};

int main() {
    vector<vector<int>> mat;
    int answer;
    Solution solve;

    mat = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}};
    answer = 25;
    assert(solve.diagonalSum(mat) == answer);

    mat = {{1, 1, 1, 1},
           {1, 1, 1, 1},
           {1, 1, 1, 1},
           {1, 1, 1, 1}};
    answer = 8;
    assert(solve.diagonalSum(mat) == answer);

    return 0;
}
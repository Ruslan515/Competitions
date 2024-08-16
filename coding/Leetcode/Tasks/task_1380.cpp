// https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19
// Created by omega515 on 19.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        unordered_map<int, int> mpRow, mpCol;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            int minRow = INT_MAX;
            for (int j = 0; j < n; ++j) {
                minRow = min(minRow, matrix[i][j]);
            }
            mpRow[i] = minRow;
        }

        for (int j = 0; j < n; ++j) {
            int maxCol = 0;
            for (int i = 0; i < m; ++i) {
                maxCol = max(maxCol, matrix[i][j]);
            }
            mpCol[j] = maxCol;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mpRow[i] == mpCol[j]) {
                    answer.push_back(mpRow[i]);
                }
            }
        }


        return answer;
    }
};


int main() {
    vector<vector<int>> matrix;
    vector<int> answer;
    Solution solve;

    matrix = {{3,  7,  8},
              {9,  11, 13},
              {15, 16, 17}};
    answer = {15};
    assert(answer == solve.luckyNumbers(matrix));

    matrix = {{1,  10, 4,  2},
              {9,  3,  8,  7},
              {15, 16, 17, 12}};
    answer = {12};
    assert(answer == solve.luckyNumbers(matrix));

    matrix = {{7, 8},
              {1, 2}};
    answer = {7};
    assert(answer == solve.luckyNumbers(matrix));


    return 0;
}
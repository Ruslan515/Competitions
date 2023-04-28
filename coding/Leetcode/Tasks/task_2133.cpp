// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
// Created by ruslan515 on 17.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int n = matrix.size();
        bool answer = false;
        for (int i = 0; i < n; ++i) {
            set<int> set_row;
            for (int j = 0; j < n; ++j) {
                set_row.insert(matrix[i][j]);
            }
            if (set_row.size() != n) {
                return answer;
            }
        }

        for (int j = 0; j < n; ++j) {
            set<int> set_col;
            for (int i = 0; i < n; ++i) {
                set_col.insert(matrix[i][j]);
            }
            if (set_col.size() != n) {
                return answer;
            }
        }
        answer = true;
        return answer;
    }
};

int main() {
    vector<vector<int>> matrix;
    bool answer;
    Solution solve;

    matrix = {{1, 2, 3},
              {3, 1, 2},
              {2, 3, 1}};
    answer = true;
    assert(solve.checkValid(matrix) == answer);

    matrix = matrix = {{1, 1, 1},
                       {1, 2, 3},
                       {1, 2, 3}};
    answer = false;
    assert(solve.checkValid(matrix) == answer);

    return 0;
}
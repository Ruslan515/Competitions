// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13
// Created by omega515 on 13.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int answer = 0;
        unordered_map<int, int> cols, rows;
        for (int i = 0; i < m; ++i) {
            int sums = 0;
            for (int j = 0; j < n; ++j) {
                sums += mat[i][j];
            }
            rows[i] = sums;
        }
        for (int j = 0; j < n; ++j) {
            int sums = 0;
            for (int i = 0; i < m; ++i) {
                sums += mat[i][j];
            }
            cols[j] = sums;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    if (rows[i] == 1 && cols[j] == 1) {
                        ++answer;
                    }
                }
            }
        }


        return answer;
    }
};

int main() {
    vector<vector<int>> mat;
    int answer;
    Solution solve;

    mat = {{0, 0, 0, 1},
           {1, 0, 0, 0},
           {0, 1, 1, 0},
           {0, 0, 0, 0}};
    answer = 2;
    assert(answer == solve.numSpecial(mat));

    mat = {{1, 0, 0},
           {0, 0, 1},
           {1, 0, 0}};
    answer = 1;
    assert(answer == solve.numSpecial(mat));

    mat = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}};
    answer = 3;
    assert(answer == solve.numSpecial(mat));

    return 0;
}
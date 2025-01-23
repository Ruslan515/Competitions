// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27
// Created by omega515 on 26.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int currentSize = 1; currentSize <= min(m, n); ++currentSize) {
            for (int startRow = 0; startRow <= m - currentSize; ++startRow) {
                for (int startCol = 0; startCol <= n - currentSize; ++startCol) {
                    bool label = true;
                    for (int i = startRow; i < startRow + currentSize; ++i) {
                        for (int j = startCol; j < startCol + currentSize; ++j) {
                            if (matrix[i][j] == 0) {
                                label = false;
                                break;
                            }
                        }
                        if (!label) {
                            break;
                        }
                    }

                    if (label) {
                        ++answer;
                    }
                }
            }
        }


        return answer;
    }
};

int main() {
    vector<vector<int>> matrix;
    int answer;
    Solution solve;

    matrix =
            {
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 1, 1, 1}
            };
    answer = 15;
    assert(answer == solve.countSquares(matrix));

    matrix =
            {
                    {1, 0, 1},
                    {1, 1, 0},
                    {1, 1, 0}
            };
    answer = 7;
    assert(answer == solve.countSquares(matrix));
    return 0;
}

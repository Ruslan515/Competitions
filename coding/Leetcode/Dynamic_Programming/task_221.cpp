//
// Created by ruslan515 on 13.12.22.
// https://leetcode.com/problems/maximal-square/
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        if (!(matrix.empty() || matrix[0].empty())) {
            int m = matrix.size();
            int n = matrix[0].size();

            vector<vector<int>> dp(m + 1, vector<int>(1 + n, 0));
            int global_max = 0;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        int t1 = min(dp[i + 1][j], dp[i][j]);
                        int t2 = min(dp[i][j + 1], t1);
                        dp[i + 1][j + 1] = t2 + 1;
                        global_max = max(global_max, dp[i + 1][j + 1]);
                    }
                }
            }

            ans = global_max * global_max;
        }

        return ans;
    }
};

void read_data(vector<vector<char>>& matrix) {
    int n, m;
    std::cin >> m >> n;
    matrix.resize(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char temp;
            std::cin >> temp;
            matrix[i].push_back(temp);
        }
    }

    return;
}

int main() {
    vector<vector<char>> matrix;
    read_data(matrix);
    Solution s;
    std::cout << s.maximalSquare(matrix);
    return 0;
}
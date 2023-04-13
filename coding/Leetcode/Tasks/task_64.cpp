// https://leetcode.com/problems/minimum-path-sum/
// Created by ruslan515 on 27.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int GLOBAL_MAX = INT_MAX;

    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j < m + 1; ++j) {
            dp[j][0] = GLOBAL_MAX;
        }

        for (int j = 0; j < n + 1; ++j) {
            dp[0][j] = GLOBAL_MAX;
        }

        dp[1][1] = grid[0][0];
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (i > 1 || j > 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] += grid[i - 1][j - 1];
                }
            }
        }

        int answer = dp[m][n];
        return answer;
    }
};

void read_data(vector<vector<int>> &grid) {
    int m, n;
    cin >> m >> n;
    int temp;
    for (int i = 0; i < m; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
        grid.push_back(v);
    }
    return;
}

int main() {
    vector<vector<int>> grid;
    read_data(grid);
    Solution solve;

    cout << solve.minPathSum(grid);

    return 0;
}
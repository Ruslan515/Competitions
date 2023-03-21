// https://leetcode.com/problems/perfect-squares/description/
// Created by ruslan515 on 16.03.23.
//

#include <bits//stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int size_sq = sqrt(n) + 1;
        vector<int> squares(size_sq);
        int k = 1;
        for (int i = 0; i < size_sq; ++i) {
            squares[i] = k * k;
            ++k;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < size_sq; ++j) {
                int sq = squares[j];
                if (i < sq) {
                    break;
                }
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }

        int ans = dp[n];
        return ans;
    }
};

int main() {
    Solution solve;
    assert(solve.numSquares(12) == 3);
    assert(solve.numSquares(13) == 2);

    return 0;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Created by ruslan515 on 21.12.22.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(
                n + 1,
                vector<vector<int>>(k + 1, vector<int>(2))
                );
        for (int i = n - 1; i >= 0; --i) {
            for (int t = 1; t <= k; ++t) {
                for (int h = 0; h < 2; ++h) {
                    int n = dp[i + 1][t][h];
                    int s;
                    if (h == 1) {
                        s = prices[i] + dp[i + 1][t - 1][0];
                    } else {
                        s = -prices[i] + dp[i + 1][t][1];
                    }
                    dp[i][t][h] = max(n, s);
                }
            }
        }

        ans = dp[0][k][0];
        return ans;
    }
};

void read_data(int &k, vector<int>& prices) {
    cin >> k;
    int t;
    while (cin >> t)
        prices.push_back(t);

    return;
}

int main() {
    int k;
    vector<int> prices;
    read_data(k, prices);
    Solution s;
    std::cout << s.maxProfit(k, prices);
    return 0;
}
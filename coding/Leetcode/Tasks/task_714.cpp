// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// Created by omega515 on 04.03.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer;
        int n = prices.size();
        /*
         база dp[day][holding] - прибыль в day с учетом того, что
         у нас есть акции(holding == 0) или нет
         */
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int tmp;
        for (int i = n - 1; i >= 0; --i) {
            for (int holding = 0; holding < 2; ++holding) {
                tmp = dp[i + 1][holding];
                if (holding == 1) {
                    tmp = max(tmp, dp[i + 1][0] + prices[i] - fee);
                } else {
                    tmp = max(tmp, dp[i + 1][1] - prices[i]);
                }
                dp[i][holding] = tmp;
            }
        }

        answer = dp[0][0];

        return answer;
    }
};

int main() {
    vector<int> prices;
    int fee;
    int answer;
    Solution solve;

    prices = {1, 3, 2, 8, 4, 9}, fee = 2;
    answer = 8;
    assert(answer == solve.maxProfit(prices, fee));

    prices = {1, 3, 7, 5, 10, 3}, fee = 3;
    answer = 6;
    assert(answer == solve.maxProfit(prices, fee));

    return 0;
}


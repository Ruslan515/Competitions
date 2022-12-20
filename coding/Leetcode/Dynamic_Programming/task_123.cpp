// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Created by ruslan515 on 20.12.22.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        vector<int> left_profits(n, 0);
        vector<int> right_profits(n + 1, 0);

        int left_local_min = prices[0];
        int left_local_delta = 0;
        left_profits[0] = 0;
        int right_local_max = prices[n - 1];
        int right_local_delta = 0;
        right_profits[n - 1] = 0;
        for(int i = 1; i < n; ++i) {
            int left_delta = prices[i] - left_local_min;
            if (left_delta > 0) {
                if (left_delta > left_local_delta) {
                    left_profits[i] = left_delta;
                    left_local_delta = left_delta;
                } else {
                    left_profits[i] = left_local_delta;
                }
            } else {
                left_local_min = prices[i];
                left_profits[i] = left_local_delta;
            }

            int right_delta = right_local_max - prices[n - 1 - i];
            if (right_delta > 0) {
                if (right_delta > right_local_delta) {
                    right_profits[n - 1 - i] = right_delta;
                    right_local_delta = right_delta;
                } else {
                    right_profits[n - 1 - i] = right_local_delta;
                }
            } else {
                right_local_max = prices[n - 1 - i];
                right_profits[n - 1 - i] = right_local_delta;
            }
        }

        vector<int> max_profits(n, 0);
        for (int i = 0; i < n; ++i) {
            max_profits[i] = left_profits[i] + right_profits[i + 1];
        }

        ans = *max_element(max_profits.begin(), max_profits.end());
        return ans;

    }
};

void read_data(vector<int>& prices) {
    int temp;
    while (cin >> temp)
        prices.push_back(temp);
    return;
}

int main() {
    vector<int> prices;
    read_data(prices);
    Solution solve;
    cout << solve.maxProfit(prices);

    return 0;
}
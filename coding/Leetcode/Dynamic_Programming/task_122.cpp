// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Created by ruslan515 on 20.12.22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for (auto i = 0; i < n - 1; ++i) {
            if (prices[i + 1] - prices[i] > 0) {
                ans += prices[i + 1] - prices[i];
            }
        }
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
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Created by ruslan515 on 23.12.22.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int sold = INT32_MIN;
        int held = INT32_MIN;
        int reset = 0;
        for(int price: prices) {
            int pre_sold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, pre_sold);
        }

        ans = max(sold, reset);
        return ans;
    }
};

void read_data(vector<int>& prices) {
    int t;
    while (cin >> t)
        prices.push_back(t);
    return;
}

int main() {
    vector<int> prices;
    read_data(prices);
    Solution s;
    std::cout << s.maxProfit(prices);
    return 0;
}
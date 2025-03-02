// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Created by omega515 on 28.02.2025.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = prices.size();
        int currMax = prices[0], currMin = prices[0], curr;
        for (int i = 1; i < n; ++i) {
            curr = prices[i];
            if (curr > currMin) {
                answer = max(answer, curr - currMin);
            } else {
                currMin = curr;
            }
            currMax = max(currMax, curr);
        }

        return answer;
    }
};

int main() {
    vector<int> prices;
    int answer;
    Solution solve;

    prices = {7, 1, 5, 3, 6, 4};
    answer = 5;
    assert(answer == solve.maxProfit(prices));

    prices = {7, 6, 4, 3, 1};
    answer = 0;
    assert(answer == solve.maxProfit(prices));

    return 0;
}


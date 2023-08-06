// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
// Created by Ruslan Khalikov on 04.08.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        vector<int> answer;
        int n = prices.size();
        int current, discount;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            current = prices[i];
            discount = 0;
            while (j < n && current < prices[j]) {
                ++j;
            }
            if (j < n) {
                discount = prices[j];

            }
            answer.push_back(current - discount);
        }

        return answer;
    }
};

int main() {
    vector<int> prices, answer;
    Solution solve;

    prices = {10, 1, 1, 6};
    answer = {9, 0, 1, 6};
    assert(answer == solve.finalPrices(prices));

    prices = {8, 4, 6, 2, 3};
    answer = {4, 2, 4, 2, 3};
    assert(answer == solve.finalPrices(prices));

    prices = {1, 2, 3, 4, 5};
    answer = {1, 2, 3, 4, 5};
    assert(answer == solve.finalPrices(prices));

    return 0;
}

// https://leetcode.com/problems/coin-change/
// Created by ruslan515 on 15.12.22.
//

#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = (long long )(INT32_MAX) + 515;

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long ans = -1;
        vector<long long > dp(amount + 1, INF);
        dp[0] = 0;

        for(int sum = 1; sum < amount + 1; ++sum) {
            for (int coin: coins) {
                if (coin <= sum) {
                    dp[sum] = min(dp[sum], dp[sum - coin] + 1);
                }
            }
        }

        long long temp = dp[amount];
        if (temp != INF) {
            ans = dp[amount];
        }

        return ans;
    }
};

void read_data(vector<int>& coins, int& amount) {
    cin >> amount;
    int temp;
    while (cin >> temp) {
        coins.push_back(temp);
    }
    return;
}

int main() {
    int amount;
    vector<int> coins;
    read_data(coins, amount);
    Solution s;
    std::cout << s.coinChange(coins, amount);
    return 0;
}
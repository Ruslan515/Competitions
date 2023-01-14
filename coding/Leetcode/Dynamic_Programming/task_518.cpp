//
// Created by ruslan515 on 11.01.23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for(int i = 0; i < n; ++i) {
            for (int a = coins[i]; a < amount + 1; ++a) {
                dp[a] += dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};

void read_data(int& amount, vector<int>& coins) {
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
    read_data(amount, coins);
    Solution solve;
    std::cout << solve.change(amount, coins);
    return 0;
}
// https://leetcode.com/problems/coin-change/
// Created by ruslan515 on 15.12.22.
// greedy algo - wrong answer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(int x, int y) {
        return x > y;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;

        int n = coins.size();

        if (n == 1) {
            if (amount % coins[0] == 0) {
                ans = amount / coins[0];
            } else {
                ans = -1;
            }
        } else {
            sort(coins.begin(), coins.end(), comp);
            int count = 0;
            int i = 0;
            while (amount != 0) {
                int delimiter;
                while (i < n) {
                    delimiter = amount / coins[i];
                    if (delimiter > 0) {
                        break;
                    }
                    ++i;
                }
                if (i == n) {
                    count = -1;
                    break;
                } else {
                    amount -= delimiter * coins[i];
                    count += delimiter;
                }
            }
            ans = count;
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
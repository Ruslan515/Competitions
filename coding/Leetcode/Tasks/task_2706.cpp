// https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
// Created by omega515 on 19.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int> &prices, int money) {
        int answer = money;
        int firstMin = INT_MAX, secondMin= INT_MAX;
        for (int num: prices) {
            if (num < firstMin) {
                secondMin = firstMin;
                firstMin = num;
            } else {
                if (num < secondMin) {
                    secondMin = num;
                }
            }
        }
        int sumN = secondMin + firstMin;
        if (sumN <= money) {
            answer = money - sumN;
        }

        return answer;
    }
};

int main() {
    vector<int> prices;
    int money;
    int answer;
    Solution solve;

    prices = {1, 2, 2}, money = 3;
    answer = 0;
    assert(answer == solve.buyChoco(prices, money));

    prices = {3, 2, 3}, money = 3;
    answer = 3;
    assert(answer == solve.buyChoco(prices, money));

    return 0;
}
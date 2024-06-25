// https://leetcode.com/problems/maximum-ice-cream-bars/description/
// Created by omega515 on 11.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        int answer = 0;
        sort(costs.begin(), costs.end());
        int current = 0;
        for (int cost: costs) {
            current += cost;
            if (current > coins) {
                break;
            }
            answer += 1;
        }

        return answer;
    }
};

int main() {
    vector<int> costs;
    int coins;
    int answer;
    Solution solve;

    costs = {1, 3, 2, 4, 1}, coins = 7;
    answer = 4;
    assert(answer == solve.maxIceCream(costs, coins));

    costs = {10, 6, 8, 7, 7, 8}, coins = 5;
    answer = 0;
    assert(answer == solve.maxIceCream(costs, coins));

    costs = {1, 6, 3, 1, 2, 5}, coins = 20;
    answer = 6;
    assert(answer == solve.maxIceCream(costs, coins));

    return 0;
}

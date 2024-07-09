// https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
// Created by omega515 on 07.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int remainder = 0, total;
        while (true) {
            answer += numBottles;
            total = numBottles;
            numBottles = (total + remainder) / numExchange;
            remainder = (total + remainder) % numExchange;
            if (numBottles == 0 && remainder < numExchange) {
                break;
            }
        }

        return answer;
    }
};

int main() {
    int numBottles, numExchange;
    int answer;
    Solution solve;

    numBottles = 15, numExchange = 4;
    answer = 19;
    assert(answer == solve.numWaterBottles(numBottles, numExchange));

    numBottles = 15, numExchange = 8;
    answer = 17;
    assert(answer == solve.numWaterBottles(numBottles, numExchange));

    numBottles = 9, numExchange = 3;
    answer = 13;
    assert(answer == solve.numWaterBottles(numBottles, numExchange));

    return 0;
}

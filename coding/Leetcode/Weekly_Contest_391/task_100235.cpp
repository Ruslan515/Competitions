// https://leetcode.com/contest/weekly-contest-391/problems/water-bottles-ii/
// Created by omega515 on 31.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int answer = 0;
        int fullBootles = numBottles;
        int emptyBootles = 0;
        int bottlesDrink = 0;
        bool x1, x2;
        while (true) {
            // условие когда мы не можем пипть и менять
            x1 = (fullBootles == 0);
            x2 = emptyBootles < numExchange;
            if (x1 && x2) {
                break;
            }
            // условия для выпивания
            x1 = emptyBootles < numExchange;
            x2 = fullBootles > 0;
            if (x1 && x2) {
                bottlesDrink += fullBootles;
                emptyBootles += fullBootles;
                fullBootles = 0;
                continue;
            }
            // замена
            ++fullBootles;
            emptyBootles -= numExchange;
            ++numExchange;

        }
        answer = bottlesDrink;
        return answer;
    }
};

int main() {
    int numBottles;
    int numExchange;
    int answer;
    Solution solve;

    numBottles = 13;
    numExchange = 6;
    answer = 15;
    assert(answer == solve.maxBottlesDrunk(numBottles, numExchange));

    numBottles = 10;
    numExchange = 3;
    answer = 13;
    assert(answer == solve.maxBottlesDrunk(numBottles, numExchange));

    return 0;
}


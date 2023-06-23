// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Created by ruslan515 on 22.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if (!(low & 1)) {
            low++;
        }

        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};

int main() {
    int answer;
    int low;
    int high;
    Solution solve;

    low = 14, high = 17;
    answer = 3;
    assert(answer == solve.countOdds(low, high));

    low = 3, high = 7;
    answer = 3;
    assert(answer == solve.countOdds(low, high));

    low = 0, high = 10;
    answer = 5;
    assert(answer == solve.countOdds(low, high));

    low = 8, high = 10;
    answer = 1;
    assert(answer == solve.countOdds(low, high));


    return 0;
}
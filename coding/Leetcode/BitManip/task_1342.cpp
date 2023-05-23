// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Created by ruslan515 on 21.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        int mask = 1;
        while (num != 0) {
            if (num & mask) {
                --num;
            } else {
                num >>= 1;
            }
            ++count;
        }
        return count;
    }
};

int main() {
    int num, answer;
    Solution solve;

    num = 14;
    answer = 6;
    assert(solve.numberOfSteps(num) == answer);

    num = 8;
    answer = 4;
    assert(solve.numberOfSteps(num) == answer);

    num = 123;
    answer = 12;
    assert(solve.numberOfSteps(num) == answer);

    return 0;
}
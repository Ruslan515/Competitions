// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
// Created by ruslan515 on 18.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) {
            return left;
        }
        if (left == 0 || right == 0) {
            return 0;
        }
        int shift = 0;
        while (left < right){
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};

int main() {
    int answer;
    int left, right;
    Solution solve;

    left = 5, right = 7;
    answer = 4;
    assert(solve.rangeBitwiseAnd(left, right) == answer);

    left = 0, right = 0;
    answer = 0;
    assert(solve.rangeBitwiseAnd(left, right) == answer);

    left = 1, right = 2147483647;
    answer = 0;
    assert(solve.rangeBitwiseAnd(left, right) == answer);

    return 0;
}


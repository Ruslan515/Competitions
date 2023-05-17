// https://leetcode.com/problems/sum-of-two-integers/description/
// Created by ruslan515 on 16.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a);
        int y = abs(b);
        if (x < y) {
            return getSum(b, a);
        }
        int sign = a > 0 ? 1 : -1;
        if (a * b >= 0) {
            while (y != 0) {
                int answer = x ^ y;
                int carry = (x & y) << 1;
                x = answer;
                y = carry;
            }
        } else {
            while (y != 0) {
                int answer = x ^y;
                int borrow = ((~x) & y) << 1;
                x = answer;
                y = borrow;
            }
        }
        x *= sign;
        return x;
    }
};

int main() {
    int a, b;
    int answer;
    Solution solve;

    a = 1, b = 2;
    answer = 3;
    assert(solve.getSum(a, b) == answer);

    a = 2, b = 3;
    answer = 5;
    assert(solve.getSum(a, b) == answer);

    return 0;
}
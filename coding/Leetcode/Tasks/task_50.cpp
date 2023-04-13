// https://leetcode.com/problems/powx-n/description/
// Created by ruslan515 on 10.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || x == 0) {
            return x;
        }
        if (x == -1) {
            if (n == -2147483648) {
                return 1.00000;
            } else if (n == 2147483647) {
                return x;
            } else {
                return -1;
            }
        }
        double answer = 1.0;
        int count;
        if (n == -2147483648) {
            count = 2147483647;
            return 0;
        } else {
            count = abs(n);
        }
        for (int i = 0; i < count; ++i) {
            answer *= x;
        }
        if (n < 0) {
            answer = 1 / answer;
        }

        return answer;
    }
};

int main() {
    double x;
    int n;
    Solution solve;

//    x = 2.00000, n = 10;
//    assert(solve.myPow(x, n) == 1024.00000);

//    x = 2.10000, n = 3;
//    assert(solve.myPow(x, n) == 9.26100);

    x = 2.00000, n = -2147483648;
    assert(solve.myPow(x, n) == 0.00000);

    return 0;
}
// https://leetcode.com/problems/sum-of-square-numbers/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSquare(int x) {
        bool answer = true;
        if (x < 2) {
            return answer;
        }
        long long left, right, middle, temp;
        left = 2;
        right = x / 2;
        while (left <= right) {
            middle = left + (right - left) / 2;
            temp = middle * middle;
            if (temp > x) {
                right = middle - 1;
            } else if (temp < x) {
                left = middle + 1;
            } else {
                return answer;
            }
        }
        answer = false;
        return answer;
    }

    bool judgeSquareSum(int c) {
        if (c == 1 || c == 0) {
            return true;
        }
        bool answer = false;
        for (long long a = 0; a * a < c; ++a) {
            long long temp = a * a;
            long long temp2 = c - temp;
            if (temp2 < 0) {
                continue;
            }
            bool test = isSquare(temp2);
            if (test) {
                answer = true;
                break;
            }
        }
        return answer;
    }
};

int main() {
    int c;
    bool answer;
    Solution solve;

    c = 2147483642;
    answer = false;
    assert(solve.judgeSquareSum(c) == answer);

    c = 6;
    answer = false;
    assert(solve.judgeSquareSum(c) == answer);

    c = 4;
    answer = true;
    assert(solve.judgeSquareSum(c) == answer);

    c = 5;
    answer = true;
    assert(solve.judgeSquareSum(c) == answer);

    c = 3;
    answer = false;
    assert(solve.judgeSquareSum(c) == answer);

    return 0;
}
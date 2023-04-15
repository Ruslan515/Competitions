// https://leetcode.com/problems/sqrtx/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long left, right, middle, temp;
        left = 1;
        right = x / 2;
        while (left <= right) {
            middle = left + (right - left) / 2;
            temp = middle * middle;
            if (temp > x) {
                right = middle - 1;
            } else if (temp < x){
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return left - 1;
    }
};

int main() {
    int x, answer;
    Solution solve;

//    x = 4;
//    answer = 2;
//    assert(solve.mySqrt(x) == answer);

    x = 2147395599;
    answer = 46339;
    assert(solve.mySqrt(x) == answer);

    x = 26;
    answer = 5;
    assert(solve.mySqrt(x) == answer);

    return 0;
}
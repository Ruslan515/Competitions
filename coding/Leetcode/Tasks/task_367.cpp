// https://leetcode.com/problems/valid-perfect-square/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        bool answer = false;
        if (num < 4) {
            return answer;
        }
        long long left, right, middle, temp;
        left = 2;
        right = num / 2;
        while (left <= right) {
            middle = left + (right - left) / 2;
            temp = middle * middle;
            if (temp > num) {
                right = middle - 1;
            } else if (temp < num) {
                left = middle + 1;
            } else {
                answer = true;
                return answer;
            }
        }
        return answer;

    }
};

int main() {
    int num;
    bool answer;
    Solution solve;

    num = 1;
    answer = true;
    assert(solve.isPerfectSquare(num) == answer);

    num = 16;
    answer = true;
    assert(solve.isPerfectSquare(num) == answer);

    num = 14;
    answer = false;
    assert(solve.isPerfectSquare(num) == answer);

    return 0;
}
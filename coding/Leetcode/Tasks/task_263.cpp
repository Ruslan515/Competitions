// https://leetcode.com/problems/ugly-number/
// Created by ruslan515 on 19.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n == 1) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        int x = 2;
        while (n != 1 && n % x == 0) {
            n /= x;
        }

        x = 3;
        while (n != 1 && n % x == 0) {
            n /= x;
        }

        x = 5;
        while (n != 1 && n % x == 0) {
            n /= x;
        }

        bool answer = false;
        if (n == 1) {
            answer = true;
        }
        return answer;
    }
};

int main() {
    int n;
    bool answer;
    Solution solve;

    n = 6;
    answer = true;
    assert(solve.isUgly(n) == answer);

    n = 1;
    answer = true;
    assert(solve.isUgly(n) == answer);

    n = 7;
    answer = false;
    assert(solve.isUgly(n) == answer);

    return 0;
}
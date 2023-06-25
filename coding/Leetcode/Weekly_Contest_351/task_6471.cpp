// https://leetcode.com/contest/weekly-contest-351/problems/number-of-beautiful-pairs/
// Created by Ruslan Khalikov on 25.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 < num2) {
            return -1;
        }
        long long d = pow(2, 60);
        d += (long long ) num2;
        long long temp;
        temp = (num1 + d - 1) / d  + 2;
        return (int) temp;
    }
};

int main() {
    int num1, num2;
    int answer;
    Solution solve;

    num1 = 12, num2 = -55;
    answer = 4;
    assert(answer == solve.makeTheIntegerZero(num1, num2));

    num1 = 3, num2 = -2;
    answer = 3;
    assert(answer == solve.makeTheIntegerZero(num1, num2));

    num1 = 5, num2 = 7;
    answer = -1;
    assert(answer == solve.makeTheIntegerZero(num1, num2));

    return 0;
}

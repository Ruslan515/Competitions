// https://leetcode.com/contest/weekly-contest-391/problems/harshad-number/
// Created by omega515 on 31.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int answer = -1;
        int sums = 0;
        int copy = x;
        while (x) {
            int d = x % 10;
            x = x / 10;
            sums += d;
        }
        if (copy % sums == 0) {
            answer = sums;
        }

        return answer;
    }
};

int main() {
    int x;
    int answer;
    Solution solve;

    x = 18;
    answer = 9;
    assert(answer == solve.sumOfTheDigitsOfHarshadNumber(x));

    x = 23;
    answer = -1;
    assert(answer == solve.sumOfTheDigitsOfHarshadNumber(x));

    return 0;
}


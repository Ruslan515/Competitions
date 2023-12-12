// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06
// Created by omega515 on 06.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int answer = 0;
        int d = n / 7;
        if (d == 0) {
            answer = (2 * 1 + 1 * (n - 1)) * n / 2;
        } else {
            int first = 1;
            for (int i = 0; i < d; ++i) {
                answer += (first + 3) * 7;
                first += 1;
            }
            int x = n % 7;
            int y = (2 * first + 1 * (x - 1)) * x / 2;
            answer += y;
        }

        return answer;
    }
};

int main() {
    int n, answer;
    Solution solve;

    n = 10;
    answer = 37;
    assert(answer == solve.totalMoney(n));

    n = 4;
    answer = 10;
    assert(answer == solve.totalMoney(n));

    n = 20;
    answer = 96;
    assert(answer == solve.totalMoney(n));

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-99/problems/count-total-number-of-colored-cells/
// Created by ruslan515 on 04.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long temp;
        for (int i = 1; i < n; ++i) {
            temp = i * 4;
            ans += temp;
        }
        return ans;
    }
};


int main() {
    Solution solve;
    assert(solve.coloredCells(1) == 1);
    assert(solve.coloredCells(2) == 5);
    assert(solve.coloredCells(3) == 13);
    assert(solve.coloredCells(4) == 25);

    return 0;
}
// https://leetcode.com/contest/weekly-contest-362/problems/determine-if-a-cell-is-reachable-at-a-given-time/
// Created by ruslan515 on 10.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int total = max(abs(sx - fx), abs(sy - fy));
        if (t == 1 and total == 0) return false;
        if (total <= t) return true;
        return false;
    }
};

int main() {
    int sx, sy, fx, fy, t;
    bool answer;
    Solution solve;

    sx = 1, sy = 2, fx = 1, fy = 2, t = 1;
    answer = true;
    assert(answer == solve.isReachableAtTime(sx, sy, fx, fy, t));

    sx = 1, sy = 1, fx = 1, fy = 1, t = 3;
    answer = true;
    assert(answer == solve.isReachableAtTime(sx, sy, fx, fy, t));

    sx = 2, sy = 4, fx = 7, fy = 4, t = 6;
    answer = true;
    assert(answer == solve.isReachableAtTime(sx, sy, fx, fy, t));

    sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    answer = true;
    assert(answer == solve.isReachableAtTime(sx, sy, fx, fy, t));

    sx = 3, sy = 1, fx = 7, fy = 3, t = 3;
    answer = false;
    assert(answer == solve.isReachableAtTime(sx, sy, fx, fy, t));
    return 0;
}


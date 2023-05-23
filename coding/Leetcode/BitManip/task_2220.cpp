// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Created by ruslan515 on 23.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start > goal) {
            return minBitFlips(goal, start);
        }
        int answer = 0;
        int mask = 1;
        while (goal != 0) {
            int d1 = start & mask;
            int d2 = goal & mask;
            if (d1 != d2) {
                ++answer;
            }
            start >>= 1;
            goal >>= 1;
        }
        return answer;
    }
};

int main() {
    int start, goal;
    int answer;
    Solution solve;

    start = 10, goal = 7;
    answer = 3;
    assert(solve.minBitFlips(start, goal) == answer);

    start = 3, goal = 4;
    answer = 3;
    assert(solve.minBitFlips(start, goal) == answer);
    return 0;
}
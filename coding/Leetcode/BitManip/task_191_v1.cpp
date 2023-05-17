// https://leetcode.com/problems/number-of-1-bits/description/
// Created by ruslan515 on 15.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i) {
            if ((mask & n) != 0) {
                ++answer;
            }
            mask = mask << 1;
        }

        return answer;

    }
};

int main() {
    uint32_t n;
    int answer;
    Solution solve;

    n = 00000000000000000000000000001011;
    answer = 3;
    assert(solve.hammingWeight(n) == answer);

    n = 00000000000000000000000010000000;
    answer = 1;
    assert(solve.hammingWeight(n) == answer);

//    n = 11111111111111111111111111111101;
//    answer = 31;
//    assert(solve.hammingWeight(n) == answer);

    return 0;
}
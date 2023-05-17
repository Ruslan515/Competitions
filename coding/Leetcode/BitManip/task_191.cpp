// https://leetcode.com/problems/number-of-1-bits/description/
// Created by ruslan515 on 15.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int hammingWeight(uint32_t n) {
        if (n == 0) {
            return 0;
        }
        int answer = 0;
        while (n != 0) {
            int d = n % 2;
            if (d == 1) {
                ++answer;
            }
            n /= 2;
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
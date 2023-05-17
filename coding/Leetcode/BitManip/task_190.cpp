// https://leetcode.com/problems/reverse-bits/description/
// Created by ruslan515 on 16.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> binV;
        while (n != 0) {
            int d = n % 2;
            binV.push_back(d);
            n /= 2;
        }
        while (binV.size() != 32) {
            binV.push_back(0);
        }

        uint32_t answer = 0;
        uint32_t base = 1;
        for (int i = 31; i >= 0; --i) {
            int d = binV[i] * base;
            answer += d;
            base *= 2;
        }

        return answer;
    }
};

int main() {
    uint32_t n;
    uint32_t answer;
    Solution solve;

    n = 43261596;
    answer = 964176192;
    assert(solve.reverseBits(n) == answer);

    n = 4294967293;
    answer = 3221225471;
    assert(solve.reverseBits(n) == answer);

    return 0;
}
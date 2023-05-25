// https://leetcode.com/problems/hamming-distance/
// Created by ruslan515 on 25.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int mask = 1;
        int answer = 0;
        while (z != 0) {
            int d = z & mask;
            if (d) {
                ++answer;
            }
            z >>= 1;
        }
        return answer;
    }
};

int main() {
    int x, y, answer;
    Solution solve;

    x = 93, y = 73; //1011101 1001001
    answer = 2;
    assert(solve.hammingDistance(x, y) == answer);

    x = 1, y = 4;
    answer = 2;
    assert(solve.hammingDistance(x, y) == answer);

    x = 3, y = 1;
    answer = 1;
    assert(solve.hammingDistance(x, y) == answer);

    return 0;
}
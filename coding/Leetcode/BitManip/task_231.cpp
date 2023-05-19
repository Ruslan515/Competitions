// https://leetcode.com/problems/power-of-two/description/
// Created by ruslan515 on 19.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        bool answer = false;
        int mask = 1;
        while (n != 1) {
            int x = n & mask;
            if (x == 1) {
                return answer;
            }
            n >>= 1;
        }
        answer = true;
        return answer;
    }
};

int main() {
    int n;
    int answer;
    Solution solve;

    n = 1;
    answer = true;
    assert(solve.isPowerOfTwo(n) == answer);

    n = 16;
    answer = true;
    assert(solve.isPowerOfTwo(n) == answer);

    n = 3;
    answer = false;
    assert(solve.isPowerOfTwo(n) == answer);

    return 0;
}
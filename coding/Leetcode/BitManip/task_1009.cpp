// https://leetcode.com/problems/complement-of-base-10-integer/
// Created by ruslan515 on 20.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int answer = 0;
        int mask = 1;
        int i = 0;
        while (n != 0) {
            int x = n & mask;
            if (!x) {
                int y = mask << i;
                answer += y;
            }
            n >>= 1;
            ++i;
        }

        return answer;
    }
};

int main() {
    int n, answer;
    Solution solve;

    n = 5;
    answer = 2;
    assert(solve.bitwiseComplement(n) == answer);

    n = 7;
    answer = 0;
    assert(solve.bitwiseComplement(n) == answer);

    n = 10;
    answer = 5;
    assert(solve.bitwiseComplement(n) == answer);

    return 0;
}
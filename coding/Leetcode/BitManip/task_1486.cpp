// https://leetcode.com/problems/xor-operation-in-an-array/description/
// Created by ruslan515 on 21.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int answer = start;
        int nums;
        int i = 1;
        while (i < n) {
            nums = start + 2 * i;
            answer ^= nums;
            ++i;
        }
        return answer;
    }
};

int main() {
    int n, start, answer;
    Solution solve;

    n = 5, start = 0;
    answer = 8;
    assert(solve.xorOperation(n, start) == answer);

    n = 4, start = 3;
    answer = 8;
    assert(solve.xorOperation(n, start) == answer);

    return 0;
}
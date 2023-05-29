// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Created by ruslan515 on 29.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOnes(int x) {
        int cnt = 0;
        int mask = 1;
        while (x != 0) {
            if (x & mask) {
                ++cnt;
            }
            x >>= 1;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        for (int x = left; x <= right; ++x) {
            int cnt = countOnes(x);
            if (primes.count(cnt)) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    int left;
    int right;
    int answer;
    Solution solve;

    left = 6, right = 10;
    answer = 4;
    assert(solve.countPrimeSetBits(left, right) == answer);

    left = 10, right = 15;
    answer = 5;
    assert(solve.countPrimeSetBits(left, right) == answer);;

    return 0;
}
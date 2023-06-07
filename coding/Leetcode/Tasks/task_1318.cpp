// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Created by ruslan515 on 07.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;

        int mask = 1;

        while (c != 0 || a != 0 || b != 0) {
            int cd = c & mask;
            int ad = a & mask;
            int bd = b & mask;

            if (cd == 1 && (ad == 0 && bd == 0)) {
                ++answer;
            }
            if (cd == 0 && (ad == 1 && bd == 1)) {
                answer += 2;
            }
            if ((cd == 0 && (ad == 1 && bd == 0)) || (cd == 0 && (ad == 0 && bd == 1))) {
                ++answer;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return answer;
    }
};

int main() {
    int a;
    int b;
    int c;
    int answer;
    Solution solve;

    a = 8, b = 3, c = 5;
    answer = 3;
    assert(answer == solve.minFlips(a, b, c));

    a = 2, b = 6, c = 5;
    answer = 3;
    assert(answer == solve.minFlips(a, b, c));

    a = 4, b = 2, c = 7;
    answer = 1;
    assert(answer == solve.minFlips(a, b, c));

    a = 1, b = 2, c = 3;
    answer = 0;
    assert(answer == solve.minFlips(a, b, c));

    return 0;
}
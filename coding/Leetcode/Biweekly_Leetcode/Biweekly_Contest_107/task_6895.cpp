// https://leetcode.com/contest/biweekly-contest-107/problems/construct-the-longest-new-string/
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int answer = 0;
        string s = "";

        if (x > y) {
            for (int i = 0; i < z; ++i) {
                s += "AB";
            }
            for (int i = 0; i < 2 * y + 1; ++i) {
                if (i % 2 == 0) {
                    s += "AA";
                } else {
                    s += "BB";
                }
            }
            answer = s.size();

        } else if (x < y) {
            for (int i = 0; i < 2 * x + 1; ++i) {
                if (i % 2 == 0) {
                    s += "BB";
                } else {
                    s += "AA";
                }
            }
            for (int i = 0; i < z; ++i) {
                s += "AB";
            }
            answer = s.size();
        } else {
            for (int i = 0; i < 2 * x; ++i) {
                if (i % 2 == 0) {
                    s += "BB";
                } else {
                    s += "AA";
                }
            }
            for (int i = 0; i < z; ++i) {
                s += "AB";
            }
            answer = s.size();
        }
        return answer;
    }
};

int main() {
    int x, y, z;
    int answer;
    Solution solve;

    x = 9, y = 9, z = 34;
    answer = 104;
    assert(answer == solve.longestString(x, y, z));

    x = 2, y = 5, z = 1;
    answer = 12;
    assert(answer == solve.longestString(x, y, z));

    x = 3, y = 2, z = 2;
    answer = 14;
    assert(answer == solve.longestString(x, y, z));

    return 0;
}


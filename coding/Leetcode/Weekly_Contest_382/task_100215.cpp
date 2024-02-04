// https://leetcode.com/contest/weekly-contest-382/problems/number-of-changing-keys/
// Created by omega515 on 28.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int answer = 0;
//        std::transform(s.begin(), s.end(), s.begin(),
//                       [](unsigned char c) { return std::tolower(c); });
        int n = s.size();
        char ch_cur, ch_next;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] <= 'Z' && s[i] >= 'A') {
                ch_cur = s[i] - ('Z' - 'z');
            } else {
                ch_cur = s[i];
            }
            if (s[i + 1] <= 'Z' && s[i + 1] >= 'A') {
                ch_next = s[i + 1] - ('Z' - 'z');
            } else {
                ch_next = s[i + 1];
            }
            if (ch_cur != ch_next) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "aAbBcC";
    answer = 2;
    assert(answer == solve.countKeyChanges(s));

    s = "AaAaAaaA";
    answer = 0;
    assert(answer == solve.countKeyChanges(s));

    return 0;
}


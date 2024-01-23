// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2023-12-24
// Created by omega515 on 24.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int answer = 0;
        int n = s.size();
        string s1, s2;
        char ch1 = '0', ch2 = '1', tmp;
        int diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; ++i) {
            if (ch1 != s[i]) {
                ++diff1;
            }
            if (ch2 != s[i]) {
                ++diff2;
            }
            tmp = ch1;
            ch1 = ch2;
            ch2 = tmp;
        }

        answer = min(diff1, diff2);

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "0100";
    answer =  1;
    assert(answer == solve.minOperations(s));

    s = "10";
    answer =  0;
    assert(answer == solve.minOperations(s));

    s = "1111";
    answer =  2;
    assert(answer == solve.minOperations(s));

    return 0;
}
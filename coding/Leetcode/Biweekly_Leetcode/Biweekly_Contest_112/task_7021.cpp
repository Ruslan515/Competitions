// https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-i/
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool answer = false;
        if (s1 == s2) {
            answer = true;
            return answer;
        }
        bool one = (s1[0] == s2[2] && s1[2] == s2[0]) || (s1[0] == s2[0] && s1[2] == s2[2]);
        bool two = (s1[1] == s2[3] && s1[3] == s2[1]) || (s1[1] == s2[1] && s1[3] == s2[3]);
        answer = one && two;

        return answer;
    }
};

int main() {
    string s1, s2;
    bool answer;
    Solution solve;

    s1 = "abcd", s2 = "cdab";
    answer =  true;
    assert(answer == solve.canBeEqual(s1, s2));

    s1 = "abcd", s2 = "dacb";
    answer =  false;
    assert(answer == solve.canBeEqual(s1, s2));

    return 0;
}


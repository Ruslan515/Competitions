// https://leetcode.com/problems/one-edit-distance/description/
// Created by ruslan515 on 01.11.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkEq(string s, string t) {
        bool answer = false;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                ++count;
            }
        }
        if (count == 1) {
            answer = true;
        }

        return answer;
    }

    bool checkMax(string minS, string maxS) {
        bool answer = false;
        int idxMin = 0, idxMax = 0;
        int n = minS.size();
        while (idxMin < n && (minS[idxMin] == maxS[idxMax])) {
            ++idxMin;
            ++idxMax;
        }
        ++idxMax;
        while (idxMin < n && minS[idxMin] == maxS[idxMax]) {
            ++idxMin;
            ++idxMax;
        }
        if (idxMin == n) {
            answer = true;
        }

        return answer;
    }

    bool isOneEditDistance(string s, string t) {
        bool answer = false;
        int n1 = s.size();
        int n2 = t.size();
        if (n1 == n2 && n1 != 0) {
            answer = checkEq(s, t);
        } else {
            if (abs(n1 - n2) == 1) {
                if (n1 > n2) {
                    answer = checkMax(t, s);
                } else {
                    answer = checkMax(s, t);
                }
            }
        }

        return answer;
    }
};

int main() {
    string s, t;
    bool answer;
    Solution solve;

    s = "abc", t = "abd";
    answer = true;
    assert(answer == solve.isOneEditDistance(s, t));

    s = "abd", t = "abd";
    answer = false;
    assert(answer == solve.isOneEditDistance(s, t));

    s = "abbc", t = "abc";
    answer = true;
    assert(answer == solve.isOneEditDistance(s, t));

    s = "", t = "";
    answer = false;
    assert(answer == solve.isOneEditDistance(s, t));

    s = "ab", t = "acb";
    answer = true;
    assert(answer == solve.isOneEditDistance(s, t));


    return 0;
}
// https://leetcode.com/problems/roman-to-integer/description/
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int romanToInt(string s) {
        int answer = 0;
        int n = s.size();
        char next, current;
        int valCurr, valNext;
        for (int i = 0; i < n;++i) {
            current = s[i];
            valCurr = mp[current];
            if (i + 1 < n) {
                next = s[i + 1];
                valNext = mp[next];
                if (valCurr < valNext) {
                    answer += valNext - valCurr;
                    ++i;
                } else {
                    answer += valCurr;
                }

            } else {
                answer += valCurr;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "III";
    answer = 3;
    assert(answer == solve.romanToInt(s));

    s = "MCMXCIV";
    answer = 1994;
    assert(answer == solve.romanToInt(s));

    s = "LVIII";
    answer = 58;
    assert(answer == solve.romanToInt(s));

    return 0;
}
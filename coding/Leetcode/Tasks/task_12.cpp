// https://leetcode.com/problems/roman-to-integer/description/
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<string, int>> v = {
            {"M",  1000},
            {"CM", 900},
            {"D",  500},
            {"CD", 400},
            {"C",  100},
            {"XC", 90},
            {"L",  50},
            {"XL", 40},
            {"X",  10},
            {"IX", 9},
            {"V",  5},
            {"IV", 4},
            {"I",  1}

    };

    string intToRoman(int num) {
        string answer = "";
        int val;
        while (num != 0) {
            for (int i = 0; i < v.size(); ++i) {
                val = v[i].second;
                if (val <= num) {
                    answer += v[i].first;
                    num -= val;
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    int num;
    string answer;
    Solution solve;

    num = 20;
    answer = "XX";
    assert(answer == solve.intToRoman(num));

    num = 3;
    answer = "III";
    assert(answer == solve.intToRoman(num));

    num = 58;
    answer = "LVIII";
    assert(answer == solve.intToRoman(num));

    num = 1994;
    answer = "MCMXCIV";
    assert(answer == solve.intToRoman(num));

    return 0;
}

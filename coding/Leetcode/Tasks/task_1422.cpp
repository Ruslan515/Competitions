// https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2023-12-22
// Created by omega515 on 22.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int answer = 0;
        unordered_map<char, int> mp;
        for (char ch: s) {
            ++mp[ch];
        }

        int sumX, left = 0;
        int right = 0;
        if (mp.find('1') != mp.end()) {
            right = mp['1'];
        }
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            char ch = s[i];
            if (ch == '0') {
                ++left;
            } else {
                --right;
            }
            sumX = left + right;
            answer = max(answer, sumX);
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "00";
    answer = 1;
    assert(answer == solve.maxScore(s));

    s = "011101";
    answer = 5;
    assert(answer == solve.maxScore(s));

    s = "00111";
    answer = 5;
    assert(answer == solve.maxScore(s));

    s = "1111";
    answer = 3;
    assert(answer == solve.maxScore(s));

    return 0;
}
// https://leetcode.com/contest/weekly-contest-346/problems/lexicographically-smallest-palindrome/
// Created by ruslan515 on 21.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            char left = s[i];
            char right = s[n - i - 1];
            if (left < right) {
                s[n - i - 1] = left;
            } else {
                s[i] = right;
            }
        }
        return s;
    }
};

int main() {
    string s, answer;
    Solution solve;

    s = "egcfe";
    answer = "efcfe";
    assert(solve.makeSmallestPalindrome(s) == answer);

    s = "abcd";
    answer = "abba";
    assert(solve.makeSmallestPalindrome(s) == answer);

    s = "seven";
    answer = "neven";
    assert(solve.makeSmallestPalindrome(s) == answer);

    return 0;
}

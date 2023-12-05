// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=featured-list&envId=top-interview-questions?envType=featured-list&envId=top-interview-questions
// Created by omega515 on 05.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string answer = s.substr(0, 1);
        int left, right;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            // odd
            left = i - 1;
            right = i + 1;
            bool flag = false;
            while ((left >= 0 && right < n) && s[left] == s[right]) {
                left--;
                right++;
                flag = true;
            }
            if (flag && (right - left - 1) > answer.size()) {
                answer = s.substr(left + 1, right - left - 1);
            }
            left = i;
            right = i + 1;
            flag = false;
            while ((left >= 0 && right < n) && s[left] == s[right]) {
                left--;
                right++;
                flag = true;
            }
            if (flag && (right - left - 1) > answer.size()) {
                answer = s.substr(left + 1, right - left - 1);
            }

            // ev
        }

        return answer;
    }
};

int main() {
    string s, answer;
    Solution solve;

    s = "b";
    answer = "b";
    assert(answer == solve.longestPalindrome(s));

    s = "babad";
    answer = "bab";
    assert(answer == solve.longestPalindrome(s));

    s = "cbbd";
    answer = "bb";
    assert(answer == solve.longestPalindrome(s));


    return 0;
}
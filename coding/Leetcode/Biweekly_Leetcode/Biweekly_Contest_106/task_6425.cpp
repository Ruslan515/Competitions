// https://leetcode.com/contest/biweekly-contest-106/problems/find-the-longest-semi-repetitive-substring/
// Created by ruslan515 on 10.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int answer = 0;
        if (n == 1) {
            answer = 1;
            return answer;
        } else if (n == 2) {
            answer = 2;
            return answer;
        }

        int left = 0;
        int right = 0;
        while (right < n) {
            while (right < n && s[right + 1] != s[right]) {
                ++right;
            }
            ++right;
            while (right < n && s[right + 1] != s[right]) {
                ++right;
            }
            int len = right - left;
            answer = max(answer, len);

            while (left < n && s[left + 1] != s[left]) {
                ++left;
            }

        }

        return answer;
    }
};

//class Solution {
//public:
//    int longestSemiRepetitiveSubstring(string s) {
//        int n = s.size();
//        int answer = n;
//        if (n == 1) {
//            answer = 1;
//            return answer;
//        } else if (n == 2) {
//            answer = 2;
//            return answer;
//        }
//
//        map<char, int> mpChars;
//        for (char ch: s) {
//            ++mpChars[ch];
//        }
//        map<char, int>::iterator it = mpChars.begin();
//        for (; it != mpChars.end(); ++it) {
//            if (it->second > 1) {
//                answer = 0;
//                break;
//            }
//        }
//        if (answer == n) {
//            return n;
//        }
//
//
//        int left = 0;
//        int right = 0;
//        map<char, int> mp;
//        while (right < n) {
//            while (right < n && mp[s[right]] == 0) {
//                ++mp[s[right]];
//                ++right;
//            }
//            int temp = right;
//            ++right;
//            while (right < n && mp[s[right]] == 0) {
//                ++mp[s[right]];
//                ++right;
//            }
//
//            int len = right - left;
//            answer = max(answer, len);
//            left = temp;
//        }
//
//        return answer;
//    }
//};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "11111111";
    answer = 2;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "0010";
    answer = 4;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "00";
    answer = 2;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "01";
    answer = 2;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "0";
    answer = 1;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "52233";
    answer = 4;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    s = "5994";
    answer = 4;
    assert(answer == solve.longestSemiRepetitiveSubstring(s));

    return 0;
}


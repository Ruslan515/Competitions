// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Created by Ruslan Khalikov on 11.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseW(string &s, int start, int end) {
        int n = end - start;
        int mid = n / 2;
        for (int i = 0; i < mid; ++i) {
            char temp = s[start + i];
            s[start + i] = s[end - i - 1];
            s[end - i - 1] = temp;
        }
    }

    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        while (end < n) {
            while (end < n && s[end] != ' ') {
                ++end;
            }
            reverseW(s, start, end);
            start = end + 1;
            end = start + 1;
        }
        return s;
    }
};

int main() {
    string answer, s;
    Solution solve;

    s = "Let's take LeetCode contest";
    answer = "s'teL ekat edoCteeL tsetnoc";
    assert(solve.reverseWords(s) == answer);

    s = "God Ding";
    answer = "doG gniD";
    assert(solve.reverseWords(s) == answer);

    return 0;
}
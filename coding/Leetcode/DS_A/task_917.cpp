// https://leetcode.com/problems/reverse-only-letters/
// Created by Ruslan Khalikov on 12.05.2023.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkLetter(char ch) {
        bool letBig = ch >= 'A' && ch <= 'Z';
        bool letSmall = ch >= 'a' && ch <= 'z';
        bool ans = letBig || letSmall;
        ans = !ans;
        return ans;
    }

    string reverseOnlyLetters(string s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && checkLetter(s[left])) {
                ++left;
            }
            while (left < right && checkLetter(s[right])) {
                --right;
            }
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
        return s;
    }
};

int main() {
    string answer, s;
    Solution solve;

    s = "7_28]";
    answer = "7_28]";
    assert(solve.reverseOnlyLetters(s) == answer);

    s = "ab-cd";
    answer = "dc-ba";
    assert(solve.reverseOnlyLetters(s) == answer);

    s = "a-bC-dEf-ghIj";
    answer = "j-Ih-gfE-dCba";
    assert(solve.reverseOnlyLetters(s) == answer);

    s = "Test1ng-Leet=code-Q!";
    answer = "Qedo1ct-eeLg=ntse-T!";
    assert(solve.reverseOnlyLetters(s) == answer);

    return 0;
}
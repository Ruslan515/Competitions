// https://leetcode.com/problems/reverse-string-ii/
// Created by Ruslan Khalikov on 11.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end) {
        int mid = start + (end - start) / 2;
        for (int i = start, j = end - 1; i < mid; ++i, --j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        int size = 2 * k;
        for (int i = 0; i < n; i += size) {
            int end = min(n, i + k);
            reverse(s, i, end);
        }

        return s;
    }
};

int main() {
    string answer, s;
    int k;
    Solution solve;

    s = "abcdefg";
    k = 2;
    answer = "bacdfeg";
    assert(solve.reverseStr(s, k) == answer);

    s = "abcdefg";
    k = 3;
    answer = "cbadefg";
    assert(solve.reverseStr(s, k) == answer);

//    s = "а";
//    k = 2;
//    answer = "a";
//    assert(solve.reverseStr(s, k) == answer);

    s = "abcd";
    k = 2;
    answer = "bacd";
    assert(solve.reverseStr(s, k) == answer);

    return 0;
}
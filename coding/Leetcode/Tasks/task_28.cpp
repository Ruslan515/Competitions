// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Created by ruslan515 on 03.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

void read_data(string &haystack, string &needle) {
    cin >> haystack >> needle;
    return;
}

int main() {
    string haystack, needle;
    read_data(haystack, needle);
    Solution solve;
    std::cout << solve.strStr(haystack, needle);
    return 0;
}
// https://leetcode.com/problems/is-subsequence/
// Created by ruslan515 on 14.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool answer = false;
        int n = s.size();
        int m = t.size();
        if (n > m) {
            return answer;
        }

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        if (i == n) {
            answer = true;
        }
        return answer;
    }
};

int main() {
    Solution solve;
    string s = "abc";
    string t = "ahbgdc";
    assert(solve.isSubsequence(s, t) == true);
    s = "axc";
    t = "ahbgdc";
    assert(solve.isSubsequence(s, t) == false);

    return 0;
}
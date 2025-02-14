// https://leetcode.com/problems/longest-common-subsequence/description/
// Created by omega515 on 13.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        char x1, x2;
        int val1, val2;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                x1 = text1[i - 1];
                x2 = text2[j - 1];
                if (x1 == x2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    val1 = dp[i - 1][j];
                    val2 = dp[i][j - 1];
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        answer = dp[n][m];

        return answer;
    }
};


int main() {
    string text1, text2;
    int answer;
    Solution solve;

    text1 = "abcde", text2 = "ace";
    answer = 3;
    assert(answer == solve.longestCommonSubsequence(text1, text2));

    text1 = "abc", text2 = "abc";
    answer = 3;
    assert(answer == solve.longestCommonSubsequence(text1, text2));

    text1 = "abc", text2 = "def";
    answer = 0;
    assert(answer == solve.longestCommonSubsequence(text1, text2));

    return 0;
}


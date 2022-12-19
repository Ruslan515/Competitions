// https://leetcode.com/problems/word-break/
// Created by ruslan515 on 16.12.22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        int n_dict = wordDict.size();
        int n_s = s.size();
        vector<bool> dp(n_s, false);
        for (int i = 0; i < n_s; ++i) {
            for (int j = 0; j < n_dict; ++j) {
                string word = wordDict[j];
                int n_word = word.size();
                if (i >= n_word - 1 && (i == n_word - 1 || dp[i - n_word])) {
                    int k = 0;
                    int start_idx = i - n_word + 1;
                    while (k < n_word && word[k] == s[start_idx + k])
                        ++k;
                    if (k == n_word) {
                        dp[i] = true;
                    }

                }

            }
        }
        ans = dp[s.size() - 1];
        return ans;
    }
};

void read_data(string& s, vector<string>& wordDict) {
    cin >> s;
    string temp;
    while (cin >> temp)
        wordDict.push_back(temp);
    return;
}

int main() {
    string s;
    vector<string> wordDict;
    read_data(s, wordDict);
    Solution solve;
    cout << solve.wordBreak(s, wordDict);

    return 0;
}
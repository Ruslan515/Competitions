// https://leetcode.com/problems/reverse-words-in-a-string-ii/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 25.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char> &s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();
        vector<char> tmp(n);
        int startWord = 0;
        int len;
        int i = 0;
        int idxTmp = n - 1;
        while (i < n) {
            // find end idx word
            while (i < n && s[i] != ' ') {
                ++i;
            }
            // copy word
            if (s[i] == ' ') {
                len = i - startWord;
                for (int j = 0; j < len; ++j) {
                    tmp[idxTmp - len + j] = s[startWord + j];
                }
                idxTmp -= len;
            }
            // copy space
            while (i < n && s[i] == ' ') {
                tmp[idxTmp] = s[i];
                --idxTmp;
                ++i;
            }
            startWord = i;
        }
        s = tmp;


        return;
    }
};

int main() {
    vector<char> s;
    vector<char> answer;
    Solution solve;

    s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    answer = {'b', 'l', 'u', 'e', ' ', 'i', 's', ' ', 's', 'k', 'y', ' ', 't', 'h', 'e'};
    solve.reverseWords(s);
    assert(answer == s);

    s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    answer = {'b', 'l', 'u', 'e', ' ', 'i', 's', ' ', 's', 'k', 'y', ' ', 't', 'h', 'e'};
    solve.reverseWords(s);
    assert(answer == s);

    return 0;
}

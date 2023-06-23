// https://leetcode.com/problems/isomorphic-strings/
// Created by ruslan515 on 22.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s += ' ';
        vector<string> words;
        vector<pair<int, int>> indexs;
        int start = 0;
        int end;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                end = i;
                int len = end - start;
                pair<int, int> p = {start, len};
                indexs.push_back(p);
                start = end + 1;
            }
        }

        bool answer = false;
        int m = pattern.size();
        if (m != indexs.size()) {
            return answer;
        }
        string temp;
        unordered_map<char, string> mpChStr;
        unordered_map<string, char> mpStrCh;
        for (int i = 0; i < pattern.size(); ++i) {
            pair<int, int> el = indexs[i];
            int start = el.first;
            int len = el.second;
            temp = s.substr(start, len);
            char ch = pattern[i];
            if (mpChStr.find(ch) != mpChStr.end() || mpStrCh.find(temp) !=mpStrCh.end()) {
                string val = mpChStr[ch];
                if (val != temp || mpStrCh[temp] != ch) {
                    return answer;
                }

            } else {
                mpChStr[ch] = temp;
                mpStrCh[temp] = ch;
            }
        }

        answer = true;
        return answer;
    }
};

int main() {
    bool answer;
    string pattern;
    string s;
    Solution solve;

    pattern = "abc", s = "dog cat dog";
    answer = false;
    assert(answer == solve.wordPattern(pattern, s));

    pattern = "abba", s = "dog dog dog dog";
    answer = false;
    assert(answer == solve.wordPattern(pattern, s));

    pattern = "abba", s = "dog cat";
    answer = false;
    assert(answer == solve.wordPattern(pattern, s));

    pattern = "abba", s = "dog cat cat dog";
    answer = true;
    assert(answer == solve.wordPattern(pattern, s));

    pattern = "abba", s = "dog cat cat fish";
    answer = false;
    assert(answer == solve.wordPattern(pattern, s));

    pattern = "aaaa", s = "dog cat cat dog";
    answer = false;
    assert(answer == solve.wordPattern(pattern, s));

    return 0;
}
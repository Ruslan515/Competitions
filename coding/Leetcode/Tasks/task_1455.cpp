// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02
// Created by omega515 on 02.12.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        string s;
        stringstream ss(sentence);
        char sep = ' ';
        vector<string> v;
        while (getline(ss, s, sep)) {
            v.push_back(s);
        }
        int wSize = searchWord.size();
        for (int i = 0; i < v.size(); ++i) {
            s = v[i];
            int n = s.size();
            if (n < wSize) {
                continue;
            }
            answer = i + 1;
            for (int j = 0; j < wSize; ++j) {
                if (s[j] != searchWord[j]) {
                    answer = -1;
                    break;
                }
            }
            if (answer != -1) {
                break;
            }
        }

        return answer;
    }
};


int main() {
    string sentence, searchWord;
    int answer;
    Solution solve;

    sentence = "i love eating burger", searchWord = "burg";
    answer = 4;
    assert(answer == solve.isPrefixOfWord(sentence, searchWord));

    sentence = "this problem is an easy problem", searchWord = "pro";
    answer = 2;
    assert(answer == solve.isPrefixOfWord(sentence, searchWord));

    sentence = "i am tired", searchWord = "you";
    answer = -1;
    assert(answer == solve.isPrefixOfWord(sentence, searchWord));

    return 0;
}
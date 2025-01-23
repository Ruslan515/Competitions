// https://leetcode.com/contest/biweekly-contest-118/problems/find-words-containing-character/
// Created by ruslan515 on 25.11.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string> &words, char x) {
        vector<int> answer;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            if (word.find(x) != string::npos) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};

int main() {
    vector<string> words;
    char x;
    vector<int> answer;
    Solution solve;

    words = {"leet", "code"}, x = 'e';
    answer = {0, 1};
    assert(answer == solve.findWordsContaining(words, x));

    words = {"abc", "bcd", "aaaa", "cbc"}, x = 'a';
    answer = {0, 2};
    assert(answer == solve.findWordsContaining(words, x));

    words = {"abc", "bcd", "aaaa", "cbc"}, x = 'z';
    answer = {};
    assert(answer == solve.findWordsContaining(words, x));

    return 0;
}


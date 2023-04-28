// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
// Created by ruslan515 on 18.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        bool answer = true;
        unordered_map<char, int> mp1, mp2;
        set<char> set_ch;
        for (auto ch: word1) {
            set_ch.insert(ch);
            mp1[ch]++;
        }
        for (auto ch: word2) {
            set_ch.insert(ch);
            mp2[ch]++;
        }
        unordered_map<char, int>::iterator it1 = mp1.begin();

        set<char> ::iterator it_set = set_ch.begin();
        for (; it_set != set_ch.end(); ++it_set) {
            char key = *it_set;
            int val2 = mp2[key];
            int val1 = mp1[key];
            int diff = abs(val1 - val2);
            if (diff > 3) {
                answer = false;
                return answer;
            }
        }
        return answer;
    }
};

int main() {
    string word1, word2;
    bool answer;
    Solution solve;

    word1 = "aaaa", word2 = "bccb";
    answer = false;
    assert(solve.checkAlmostEquivalent(word1, word2) == answer);

    word1 = "abcdeef", word2 = "abaaacc";
    answer = true;
    assert(solve.checkAlmostEquivalent(word1, word2) == answer);

    word1 = "cccddabba", word2 = "babababab";
    answer = true;
    assert(solve.checkAlmostEquivalent(word1, word2) == answer);

    return 0;
}
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void convert(unordered_map<int, vector<char>> &mpv, unordered_map<char, int> &mp) {
        for (pair<char, int> el: mp) {
            char ch = el.first;
            int count = el.second;
            mpv[count].push_back(ch);
        }
    }

    bool checkMap(unordered_map<char, int> mp1, unordered_map<char, int> mp2) {
        for (pair<char, int> el: mp1) {
            char key = el.first;
            if (mp2.find(key) == mp2.end()) {
                return true;
            }
        }
        return false;
    }

    bool closeStrings(string word1, string word2) {
        bool answer = false;
        int n = word1.size();
        if (n != word2.size()) {
            return answer;
        }

        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < n; ++i) {
            ++mp1[word1[i]];
            ++mp2[word2[i]];
        }
        if (mp1.size() != mp2.size()) {
            return answer;
        }
        if (checkMap(mp1, mp2) || checkMap(mp2, mp1)) {
            return answer;
        }
        unordered_map<int, vector<char>> mpv1, mpv2;
        convert(mpv1, mp1);
        convert(mpv2, mp2);

        if (mpv1.size() != mpv2.size()) {
            return answer;
        }
        for (pair<int, vector<char>> el: mpv1) {
            int count = el.first;
            int size1 = el.second.size();
            int size2 = mpv2[count].size();
            if (size1 != size2) {
                return answer;
            }
        }

        answer = true;
        return answer;
    }
};

int main() {
    bool answer;
    string word1, word2;
    Solution solve;

    word1 = "aaabbbbccddeeeeefffff", word2 = "aaaaabbcccdddeeeeffff";
    answer = false;
    assert(answer == solve.closeStrings(word1, word2));

    word1 = "uau", word2 = "ssx";
    answer = false;
    assert(answer == solve.closeStrings(word1, word2));

    word1 = "cabbba", word2 = "aabbss";
    answer = false;
    assert(answer == solve.closeStrings(word1, word2));

    word1 = "abc", word2 = "bca";
    answer = true;
    assert(answer == solve.closeStrings(word1, word2));

    word1 = "a", word2 = "aa";
    answer = false;
    assert(answer == solve.closeStrings(word1, word2));

    word1 = "cabbba", word2 = "abbccc";
    answer = true;
    assert(answer == solve.closeStrings(word1, word2));

    return 0;
}
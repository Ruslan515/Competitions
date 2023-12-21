// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02
// Created by omega515 on 14.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, int> create_mp(string str) {
        unordered_map<char, int> mp;
        for (auto ch: str) {
            ++mp[ch];
        }
        return mp;
    }

    int countCharacters(vector<string> &words, string chars) {
        int answer = 0;
//        unordered_map<char, int> mp_chars = create_mp(chars);
        unordered_map<char, int> mp_chars ;
        for (auto ch: chars) {
            ++mp_chars[ch];
        }

        for (string word: words) {
//            unordered_map<char, int> mp_word = create_mp(word);
            unordered_map<char, int> mp_word;
            for (auto ch: word) {
                ++mp_word[ch];
            }

            unordered_map<char, int>::iterator it = mp_word.begin();
            char key;
            int val_word, val_chars;
            int label = true;
            for (; it != mp_word.end(); ++it) {
                key = it->first;
                val_word = it->second;
                val_chars = mp_chars[key];
                bool l1 = mp_chars.find(key) != mp_chars.end();
                bool l2 = val_chars >= val_word;
                if (!(l1 && l2)) {
                    label = false;
                    break;
                }
            }
            if (label) {
                answer += word.size();
            }
        }

        return answer;
    }
};

int main() {
    vector<string> words;
    string chars;
    int answer;
    Solution solve;

    words = {"cat", "bt", "hat", "tree"}, chars = "atach";
    answer = 6;
    assert(answer == solve.countCharacters(words, chars));

    words = {"hello", "world", "leetcode"}, chars = "welldonehoneyr";
    answer = 10;
    assert(answer == solve.countCharacters(words, chars));

    return 0;
}
// https://leetcode.com/contest/weekly-contest-417/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/
// Created by omega515 on 29.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<char, int> mp;
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        int cntVowel = 5;
        int left = 0, rigth = 0;
        int n = word.size();
        int cntK = 0;
        char ch;
        while (rigth < n) {
            // нужно что бы выполнились оба условия
            bool checkVowel = false;
            bool checkK = false;
            while (rigth < n) {
                ch = word[rigth];
                if (vowel.find(ch) != vowel.end()) {
                    ++mp[ch];
                } else {
                    ++cntK;
                }
                checkVowel = mp.size() == cntVowel;
                checkK = cntK == k;

                if (checkVowel && checkK) {
                    break;
                }
                ++rigth;

            }
            if (checkVowel && checkK) {
                ++answer;
                while (left <= rigth) {
                    ch = word[left];
                    if (vowel.find(ch) != vowel.end()) {
                        --mp[ch];
                        if (mp[ch] == 0) {
                            mp.erase(ch);
                        }
                    } else {
                        --cntK;
                    }
                    checkVowel = !(mp.size() == cntVowel);
                    checkK = !(cntK == k);
                    ++left;
                    if (checkVowel || checkK) {
                        break;
                    }

                }
            }
        }


        return answer;
    }
};

int main() {
    string word;
    int k;
    int answer;
    Solution solve;

    word = "ieaouqqieaouqq", k = 1;
    answer = 3;
    assert(answer == solve.countOfSubstrings(word, k));

    word = "aeiou", k = 0;
    answer = 1;
    assert(answer == solve.countOfSubstrings(word, k));

    word = "aeioqq", k = 1;
    answer = 0;
    assert(answer == solve.countOfSubstrings(word, k));

    return 0;
}

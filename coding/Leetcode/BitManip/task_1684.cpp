// https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Created by ruslan515 on 23.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        set<char> set_ch(begin(allowed), end(allowed));
        int answer = 0;
        for (auto word: words) {
            set<char> set_word(begin(word), end(word));
            set<char>::iterator it = set_word.begin();
            bool label = true;
            for (; it != set_word.end(); ++it) {
                char cur = *it;
                if (set_ch.count(cur) == 0) {
                    label = false;
                    break;
                }
            }
            if (label) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
    string allowed;
    vector<string> words;
    int answer;
    Solution solve;

    allowed = "ab", words = {"ad", "bd", "aaab", "baa", "badab"};
    answer = 2;
    assert(solve.countConsistentStrings(allowed, words) == answer);

    allowed = "abc", words = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    answer = 7;
    assert(solve.countConsistentStrings(allowed, words) == answer);

    return 0;
}
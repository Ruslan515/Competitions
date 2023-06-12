// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> count;
        for(auto ch: s) {
            ++count[ch];
        }
        bool answer = true;
        int cnt = count[s[0]];
        for (auto kv: count) {
            char key = kv.first;
            int value = kv.second;
            if (value != cnt) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};

int main() {
    string s;
    bool answer;
    Solution solve;

    s = "abacbc";
    answer =  true;
    assert(solve.areOccurrencesEqual(s) == answer);

    s = "aaabb";
    answer =  false;
    assert(solve.areOccurrencesEqual(s) == answer);

    return 0;
}
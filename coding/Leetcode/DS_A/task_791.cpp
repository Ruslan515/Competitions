// https://leetcode.com/problems/custom-sort-string/
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void insertChar(
            unordered_map<char, int> &mpS,
            int count, char ch, string &answer,
            bool erase
    ) {
        for (int i = 0; i < count; ++i) {
            answer += ch;
        }
        if (erase) {
            mpS.erase(ch);
        }
    }

    string customSortString(string order, string s) {
        string answer = "";
        unordered_map<char, int> mpS;
        for (char ch: s) {
            ++mpS[ch];
        }
        for (char ch: order) {
            int count = mpS[ch];
            insertChar(mpS, count, ch, answer, true);
        }

        unordered_map<char, int>::iterator it = mpS.begin();
        for (; it != mpS.end(); ++it) {
            char ch = it->first;
            int count = it->second;
            insertChar(mpS, count, ch, answer, false);
        }

        return answer;
    }
};

int main() {
    string answer;
    string s, order;
    Solution solve;

    order = "cba", s = "abcd";
    answer = "cbad";
    assert(answer == solve.customSortString(order, s));

    order = "cbafg", s = "abcd";
    answer = "cbad";
    assert(answer == solve.customSortString(order, s));

    return 0;
}
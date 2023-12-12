// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=daily-question&envId=2023-12-01
// Created by omega515 on 05.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string create(vector<string> &word) {
        string answer = "";
        for (string w: word) {
            answer += w;
        }
        return answer;
    }
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        bool answer = false;
        string s1 = create(word1), s2 = create(word2);
        if (s1 == s2) {
            answer = true;
        }
        return answer;
    }
};

int main() {
    vector<string> word1, word2;
    bool answer;
    Solution solve;

    word1 = {"ab", "c"}, word2 = {"a", "bc"};
    answer = true;
    assert(answer == solve.arrayStringsAreEqual(word1, word2));

    word1 = {"a", "cb"}, word2 = {"ab", "c"};
    answer = false;
    assert(answer == solve.arrayStringsAreEqual(word1, word2));

    word1 = {"abc", "d", "defg"}, word2 = {"abcddefg"};
    answer = true;
    assert(answer == solve.arrayStringsAreEqual(word1, word2));

    return 0;
}
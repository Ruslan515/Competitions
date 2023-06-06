// https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
// Created by ruslan515 on 06.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> ump;
        for (char ch: sentence) {
            ++ump[ch];
        }
        bool answer = false;
        if (ump.size() == 26) {
            answer = true;
        }
        return answer;
    }
};

int main() {
    string sentence;
    bool answer;
    Solution solve;

    sentence = "thequickbrownfoxjumpsoverthelazydog";
    answer = true;
    assert(answer == solve.checkIfPangram(sentence));

    sentence = "leetcode";
    answer = false;
    assert(answer == solve.checkIfPangram(sentence));

    return 0;
}
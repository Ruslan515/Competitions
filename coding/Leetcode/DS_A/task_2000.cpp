// https://leetcode.com/problems/reverse-prefix-of-word/
// Created by Ruslan Khalikov on 13.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverse(string &word, int end) {
        for(int i = 0; i < (end + 1) / 2; ++i) {
            swap(word[i], word[end - i]);
        }
    }

    string reversePrefix(string word, char ch) {
        string answer;
        int idx = -1;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            if (ch == word[i]) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            reverse(word, idx);
        }
        return word;
    }
};

int main() {
    string answer, word;
    char ch;
    Solution solve;

    word = "abcdefd", ch = 'd';
    answer = "dcbaefd";
    assert(solve.reversePrefix(word, ch) == answer);

    word = "xyxzxe", ch = 'z';
    answer = "zxyxxe";
    assert(solve.reversePrefix(word, ch) == answer);

    word = "abcd", ch = 'z';
    answer = "abcd";
    assert(solve.reversePrefix(word, ch) == answer);

    return 0;
}

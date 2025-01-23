// https://leetcode.com/contest/weekly-contest-399/problems/string-compression-iii/
// Created by omega515 on 26.05.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string answer;
        int n = word.size();
        int i = 0;
        while (i < n) {
            char first = word[i];
            int k = 1;
            while (k < 9 && word[i + k] == first) {
                ++k;
            }
            answer += to_string(k) + first;
            i += k;
//            ++i;

        }

        return answer;
    }
};

int main() {
    string word, answer;
    Solution solve;

    word = "abcde";
    answer = "1a1b1c1d1e";
    assert(answer == solve.compressedString(word));

    word = "aaaaaaaaaaaaaabb";
    answer = "9a5a2b";
    assert(answer == solve.compressedString(word));
    return 0;
}


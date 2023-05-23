// https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Created by ruslan515 on 23.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

    }
};

int main() {
    string allowed;
    vector<string> words;
    int answer;
    Solution solve;

    allowed = "ab", words = ["ad","bd","aaab","baa","badab"];
    answer = 2;
    assert(solve.decode(encoded, first) == answer);

    allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"];
    answer = 7;
    assert(solve.decode(encoded, first) == answer);

    return 0;
}
// https://leetcode.com/problems/length-of-last-word/
// Created by ruslan515 on 11.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        };

        while (i >= 0 && s[i] != ' ') {
            --i;
            ++answer;
        };

        return answer;
    }
};

int main() {
    string s;
    int ans;
    Solution solve;

    s = "a";
    ans = 1;
    assert(solve.lengthOfLastWord(s) == ans);

    s = "Hello World";
    ans = 5;
    assert(solve.lengthOfLastWord(s) == ans);

    s = " fly me   to   the moon  ";
    ans = 4;
    assert(solve.lengthOfLastWord(s) == ans);

    s = "luffy is still joyboy";
    ans = 6;
    assert(solve.lengthOfLastWord(s) == ans);

    return 0;
}
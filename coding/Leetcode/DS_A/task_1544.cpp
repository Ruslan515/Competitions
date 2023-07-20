// https://leetcode.com/problems/make-the-string-great/description/
// Created by Ruslan Khalikov on 20.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string answer = "";
        answer += s[0];
        int n = s.size();
        char temp, last;
        for (int i = 1; i < n; ++i) {
            temp = s[i];
            if (answer.size() != 0) {
                last = answer[answer.size() - 1];
                if (((temp + 32) == last) || ((temp - 32) == last)) {
                    answer.pop_back();
                } else {
                    answer += temp;
                }
            } else {
                answer += temp;
            }
        }

        return answer;
    }
};

int main() {
    string s, answer;
    Solution solve;

    s = "abBAcC";
    answer = "";
    assert(answer == solve.makeGood(s));

    s = "Pp";
    answer = "";
    assert(answer == solve.makeGood(s));

    s = "leEeetcode";
    answer = "leetcode";
    assert(answer == solve.makeGood(s));

    s = "s";
    answer = "s";
    assert(answer == solve.makeGood(s));

    return 0;
}
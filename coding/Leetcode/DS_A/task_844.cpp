// https://leetcode.com/problems/backspace-string-compare/
// Created by Ruslan Khalikov on 19.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string delBackSpace(string s) {
        int n = s.size();
        stack<char> st;
        char ch;
        string answer = "";
        for (int i = 0; i < n; ++i) {
            ch = s[i];
            if (ch == '#') {
                if (answer.size() != 0) {
                    answer.pop_back();
                }
            } else {
                answer.push_back(ch);
            }
        }
        return answer;
    }

    bool backspaceCompare(string s, string t) {
        bool answer = true;
        s = delBackSpace(s);
        t = delBackSpace(t);
        if (s != t) {
            answer = false;
        }
        return answer;
    }

};

int main() {
    string s, t;
    bool answer;
    Solution solve;

    s = "y#fo##f", t = "y#f#o##f";
    answer = true;
    assert(answer == solve.backspaceCompare(s, t));

    s = "xywrrmp", t = "xywrrmu#p";
    answer = true;
    assert(answer == solve.backspaceCompare(s, t));

    s = "ab#c", t = "ad#c";
    answer = true;
    assert(answer == solve.backspaceCompare(s, t));

    s = "ab##", t = "c#d#";
    answer = true;
    assert(answer == solve.backspaceCompare(s, t));

    s = "a#c", t = "b";
    answer = false;
    assert(answer == solve.backspaceCompare(s, t));

    return 0;
}
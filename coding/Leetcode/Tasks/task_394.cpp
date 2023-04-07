// https://leetcode.com/problems/decode-string/description/
// Created by ruslan515 on 06.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> st_digit, st_char;
        string answer = "";
        string s_temp = "";
        int n = s.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            char temp = s[i];
            if (temp == ']') {
                for (int j = 0; j < k; ++j) {
                    temp = s[j];
                    s_temp += temp;
                }
                answer += s_temp;
            } else if (isdigit(temp)) {
                string x = "";
                while (isdigit(temp)) {
                    x += temp;
                    ++i;
                    temp = s[i];
                }
                k = stoi(x);
                s_temp = "";

            } else {
                s_temp += s[i];
            }

        }
        return answer;
    }
};

int main() {
    string s;
    Solution solve;

    s = "3[a]2[bc]";
    assert(solve.decodeString(s) == "aaabcbc");

    s = "2[abc]3[cd]ef";
    assert(solve.decodeString(s) == "abcabccdcdcdef");

    return 0;
}
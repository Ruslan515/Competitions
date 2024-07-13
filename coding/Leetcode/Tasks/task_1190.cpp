// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
// Created by omega515 on 11.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        stack<int> st;
        int n = s.size();
        char ch;
        int j = 0;
        int start;
        for (int i = 0; i < n; ++i) {
            ch = s[i];
            if (ch == '(') {
                st.push(j);
            } else if (ch == ')') {
                // reverse
                start = st.top();
                st.pop();
                reverse(answer.begin() + start, answer.begin() + j);
            } else {
                answer += ch;
                ++j;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    string answer;
    Solution solve;

    s = "(abcd)";
    answer = "dcba";
    assert(answer == solve.reverseParentheses(s));

    s = "(u(love)i)";
    answer = "iloveu";
    assert(answer == solve.reverseParentheses(s));

    s = "(ed(et(oc))el)";
    answer = "leetcode";
    assert(answer == solve.reverseParentheses(s));

    return 0;
}

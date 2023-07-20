// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
// Created by Ruslan Khalikov on 19.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        string answer = "";
        stack<char> st;
        st.push(s[0]);
        char first, top;
        for (int i = 1; i < n ; ++i) {
            first = s[i];
            if (!st.empty()) {
                top = st.top();
                if (first == top) {
                    st.pop();
                } else {
                    st.push(first);
                }
            } else {
                st.push(first);
            }
        }
        while (!st.empty()){
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {
    string s, answer;
    Solution solve;

    s = "abbaca";
    answer = "ca";
    assert(answer == solve.removeDuplicates(s));

    s = "azxxzy";
    answer = "ay";
    assert(answer == solve.removeDuplicates(s));

    s = "aaaa";
    answer = "";
    assert(answer == solve.removeDuplicates(s));

    return 0;
}
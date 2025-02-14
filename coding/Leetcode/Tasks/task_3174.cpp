// https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
// Created by omega515 on 10.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        stack<char> st;
        int n = s.size();
        char ch;
        int tmp;
        for (int i = 0; i < n; ++i) {
            ch = s[i];
            tmp = ch - '0';
            if (tmp >= 0 && tmp <= 9) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }
        n = st.size();
        vector<char> sTemp(n);
        int i = 0;
        while (!st.empty()) {
            ch = st.top();
            st.pop();
            sTemp[n - i - 1] = ch;
            ++i;
        }

        for (i = 0; i < n; ++i) {
            answer += sTemp[i];
        }

        return answer;
    }
};


int main() {
    string s;
    string answer;
    Solution solve;

    s = "abc";
    answer = "abc";
    assert(answer == solve.clearDigits(s));

    s = "cb34";
    answer = "";
    assert(answer == solve.clearDigits(s));

    return 0;
}


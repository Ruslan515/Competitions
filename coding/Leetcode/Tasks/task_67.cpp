// https://leetcode.com/problems/add-binary/description/
// Created by ruslan515 on 13.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int y = 0;
        stack<char> st;
        int n = a.size();
        int m = b.size();
        string min_str, max_str;
        if (n > m) {
            min_str = b;
            max_str = a;
        } else {
            min_str = a;
            max_str = b;
        }
        int max_size = max(n, m);
        int min_size = min(n, m);
        for (int i = 0; i < max_size; ++i) {
            if (i < min_size) {
                char aa = min_str[min_size - i - 1];
                char bb = max_str[max_size - i - 1];
                int ax = aa - '0';
                int bx = bb - '0';
                int z = ax + bx + y;
                if (z == 2) {
                    st.push('0');
                    y = 1;
                } else if (z == 3) {
                    st.push('1');
                    y = 1;
                } else {
                    char temp = z + '0';
                    st.push(temp);
                    y = 0;
                }
            } else {
                char bb = max_str[max_size - i - 1];
                int bx = bb - '0';
                int z = bx + y;
                if (z == 2) {
                    st.push('0');
                    y = 1;
                } else if (z == 3) {
                    st.push('1');
                    y = 1;
                } else {
                    char temp = z + '0';
                    st.push(temp);
                    y = 0;
                }
            }
        }

        if (y == 1) {
            st.push('1');
        }
        string answer = "";
        char temp;
        while (!st.empty()) {
            temp = st.top();
            st.pop();
            answer += temp;
        }
        return answer;

    }
};


int main() {
    string a;
    string b;
    string answer;
    Solution solve;

    a = "1111";
    b = "1111";
    answer = "11110";
    assert(solve.addBinary(a, b) == answer);

    a = "11";
    b = "1";
    answer = "100";
    assert(solve.addBinary(a, b) == answer);

    a = "1010";
    b = "1011";
    answer = "10101";
    assert(solve.addBinary(a, b) == answer);


    return 0;
}
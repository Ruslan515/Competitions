// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// Created by ruslan515 on 04.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        map<string, int> st = {{"+", 0},
                               {"-", 1},
                               {"*", 2},
                               {"/", 3}};
        stack<int> stk;
        int n = tokens.size();
        int temp;
        string smb;
        for (int i = 0; i < n; ++i) {
            smb = tokens[i];
            if (st.count(smb)) {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                int val = st[smb];
                int res;
                switch (val) {
                    case 0:
                        res = first + second;
                        break;
                    case 1:
                        res = first - second;
                        break;
                    case 2:
                        res = first * second;
                        break;
                    case 3:
                        res = first / second;
                        break;
                }
                stk.push(res);

            } else {
                temp = stoi(smb);
                stk.push(temp);
            }
        }

        int answer = stk.top();
        return answer;
    }
};

void read_data(vector<string> &tokens) {
    string t;
    while (cin >> t)
        tokens.push_back(t);
    return;
}

int main() {
    vector<string> tokens;
//    read_data(tokens);
    Solution solve;

//    tokens = {"2", "1", "+", "3", "*"};
//    assert(solve.evalRPN(tokens) == 9);

    tokens = {"4", "13", "5", "/", "+"};
    assert(solve.evalRPN(tokens) == 6);

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    assert(solve.evalRPN(tokens) == 22);

    return 0;
}

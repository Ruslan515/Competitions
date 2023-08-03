// https://leetcode.com/problems/validate-stack-sequences/
// Created by Ruslan Khalikov on 03.08.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        bool answer = false;
        stack<int> st;
        int n = pushed.size();
        vector<int> temp;
        int i = 0, j = 0;
        while (i < n) {
            while (i < n && pushed[i] != popped[j]) {
                st.push(pushed[i]);
                ++i;
            }
            if (i < n) {
                st.push(pushed[i++]);
                while (!st.empty() && st.top() == popped[j]) {
                    temp.push_back(st.top());
                    st.pop();
                    ++j;
                }
            }
        }
        if (temp == popped) {
            answer = true;
        }

        return answer;
    }
};

int main() {
    vector<int> pushed;
    vector<int> popped;
    bool answer;
    Solution solve;

    pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    answer = true;
    assert(answer == solve.validateStackSequences(pushed, popped));

    pushed = {1, 2, 3, 4, 5}, popped = {4, 3, 5, 1, 2};
    answer = false;
    assert(answer == solve.validateStackSequences(pushed, popped));

    return 0;
}
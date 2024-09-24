// https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21
// Created by omega515 on 21.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int level;

    void dfs(int first, vector<int> &answer) {
        stack<int> st;
        st.push(first);
        int current, tmp;
        while (!st.empty()) {
            current = st.top();
            st.pop();
            answer.push_back(current);
            for (int i = 9; i >= 0; --i) {
                tmp = current * 10 + i;
                if (tmp <= this->level) {
                    st.push(tmp);
                }
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        this->level = n;
        vector<int> answer;
        if (n < 10) {
            for (int i = 1; i <= n; ++i) {
                answer.push_back(i);
            }
            return answer;
        }

        for (int i = 1; i < 10; ++i) {
            dfs(i, answer);
        }

        return answer;
    }
};

int main() {
    int n;
    vector<int> answer;
    Solution solve;

    n = 13;
    answer = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(answer == solve.lexicalOrder(n));

    n = 2;
    answer = {1, 2};
    assert(answer == solve.lexicalOrder(n));

    return 0;
}

// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-question&envId=2024-09-22
// Created by omega515 on 22.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int level;
    int ans;
    int k;
    void dfs(int first, vector<int> &answer) {
        stack<int> st;
        st.push(first);
        int current, tmp;
        while (!st.empty()) {
            current = st.top();
            st.pop();
            answer.push_back(current);
            if (answer.size() == this->k) {
                this->ans = current;
                return;
            }
            for (int i = 9; i >= 0; --i) {
                tmp = current * 10 + i;
                if (tmp <= this->level) {
                    st.push(tmp);
                }
            }
        }
    }

    int findKthNumber(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        this->k = k;
        this->level = n;
        vector<int> answer;
        if (n < 10) {
            return k;
        }

        for (int i = 1; i < 10; ++i) {
            dfs(i, answer);
        }


        return ans;
    }
};

int main() {
    int n, k;
    int answer;
    Solution solve;

    n = 804289384, k = 42641503;
    answer = 10;
    assert(answer == solve.findKthNumber(n, k));

    n = 13, k = 2;
    answer = 10;
    assert(answer == solve.findKthNumber(n, k));

    n = 1, k = 1;
    answer = 1;
    assert(answer == solve.findKthNumber(n, k));

    return 0;
}

// https://leetcode.com/problems/daily-temperatures/description/
// Created by ruslan515 on 21.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            int temp = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < temp) {
                int prev;
                prev = st.top();
                st.pop();
                answer[prev] = i - prev;
            }
            st.push(i);
        }
        return answer;

    }

};

void read_data(vector<int> &temperatures) {
    int t;
    while (cin >> t)
        temperatures.push_back(t);
    return;
}

int main() {
    vector<int> temperatures;
    read_data(temperatures);
    Solution solve;
    for (int i: solve.dailyTemperatures(temperatures)) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
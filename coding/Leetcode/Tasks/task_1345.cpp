// https://leetcode.com/problems/jump-game-iv/
// Created by ruslan515 on 05.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int> &arr) {
        int answer = 0;
        int n = arr.size();
        vector<int> prev(n, 0);
        vector<int> dp(n, INT_MAX); // dp[i] - min count steps from 0 index array

        dp[0] = 0;
        prev[0] = -1;
        for (int i = 1; i < n; ++i) {
            int t;
            dp[i] = dp[i - 1] + 1;
            prev[i] = i - 1;
            for (int j = 0; j < i - 1; ++j) {
                t = arr[j];
                if (t == arr[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    break;
                }
            }
        }

        for (int i = 1; i < n - 1; ++i) {
            int t = dp[i + 1];
            int current_dp = dp[i];
            if (current_dp > t) {
                dp[i] = t;
                prev[i] = i + 1;
            }
        }

        int current = prev[n - 1];
        while (current != -1) {
            ++answer;
            current = prev[current];
        }

        return answer;
    }
};

void read_data(vector<int> &arr) {
    int t;
    while (cin >> t)
        arr.push_back(t);
    return;
}

int main() {
    vector<int> arr;
    read_data(arr);
    Solution solve;
    cout << solve.minJumps(arr);

    return 0;
}
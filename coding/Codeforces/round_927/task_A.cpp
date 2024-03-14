// https://codeforces.com/contest/1932/problem/A
// Created by ruslan515 on 18.02.2024
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<char> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int answer = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        if (nums[i] != '*') {
            int prev_prev_idx = i - 2, prev_idx = i - 1;
            char prev_prev_ch = ' ', prev_ch = ' ';
            if (prev_prev_idx >= 0) {
                prev_prev_ch = nums[prev_prev_idx];
                if (prev_prev_ch != '*') {
                    dp[i] = max(dp[i], dp[prev_prev_idx]);

                }
            }
            if (prev_idx >= 0) {
                prev_ch = nums[prev_idx];
                if (prev_ch != '*') {
                    dp[i] = max(dp[i], dp[prev_idx]);

                }
            }
            if (prev_prev_ch == '*' && prev_ch == '*') {
                break;
            }
            if (nums[i] == '@') {
                dp[i] += 1;

            }
            answer = max(answer, dp[i]);
        }
    }
    cout << answer << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}


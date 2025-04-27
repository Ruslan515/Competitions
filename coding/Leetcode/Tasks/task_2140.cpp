// https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01
// Created by omega515 on 01.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll mostPoints(vector<vector<int>> &questions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ll answer;

        int n = questions.size();
        vector<ll> dp(n, 0);
        dp[0] = questions[0][0];
        unordered_map<int, vector<int>> mpFromTo;
        ll current, prev;
        int step;
        for (int i = 1; i < n; ++i) {
            current = questions[i][0];
            dp[i] = current;
            for (int j = 0; j < i; ++j) {
                step = questions[j][1];
                if (j + step < i) {
                    prev = dp[j];
                    dp[i] = max(dp[i], prev + current);
                    answer = max(answer, dp[i]);
                }
            }
        }
        answer = dp[n - 1];

        return answer;
    }
};

int main() {
    vector<vector<int>> questions;
    long long answer;
    Solution solve;

    questions = {{3, 2},
                 {4, 3},
                 {4, 4},
                 {2, 5}};
    answer = 5;
    assert(answer == solve.mostPoints(questions));

    questions = {{1, 1},
                 {2, 2},
                 {3, 3},
                 {4, 4},
                 {5, 5}};
    answer = 7;
    assert(answer == solve.mostPoints(questions));

    return 0;
}
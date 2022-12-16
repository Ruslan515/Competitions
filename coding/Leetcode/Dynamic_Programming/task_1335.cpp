// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Created by ruslan515 on 13.12.22.
//
#include <iostream>
#include <vector>

const int INF = INT32_MAX;
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int ans = 0;
        int n = jobDifficulty.size();
        if (n < d ) {
            ans = - 1;
        } else {
            vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(d + 1, INF));
            dp[n - 1][d] = jobDifficulty[n - 1];

            for (int i = n - 2; i >= 0; --i) {
                dp[i][d] = max(dp[i + 1][d], jobDifficulty[i]);
            }

            for (int day = d - 1; day > 0; --day) {
                for (int i = day - 1; i < n - (d - day); ++i) {
                    int hardest = 0;
                    for (int j = i; j < n - (d - day); ++j) {
                        hardest = max(hardest, jobDifficulty[j]);
                        dp[i][day] = min(dp[i][day], hardest + dp[j + 1][day + 1]);
                    }
                }
            }
            ans = dp[0][1];
        }

        return ans;
    }
};

void read_data(vector<int>& jobDifficulty, int& d) {
    cin >> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        jobDifficulty.push_back(temp);
    }
    return;
}

int main() {
    int d;
    vector<int> jobDifficulty;
    read_data(jobDifficulty, d);
    Solution s;
    std::cout << s.minDifficulty(jobDifficulty, d);
    return 0;
}
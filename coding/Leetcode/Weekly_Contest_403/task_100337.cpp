// https://leetcode.com/contest/weekly-contest-403/problems/maximize-total-cost-of-alternating-subarrays/
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long calculateCost(const vector<int> &nums, int start, int end) {
        long long cost = 0;
        for (int i = start; i <= end; ++i) {
            if ((i - start) % 2 == 0) {
                cost += (long long) nums[i];
            } else {
                cost -= (long long) nums[i];
            }
        }
        return cost;
    }

    long long maximumTotalCost(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long answer = 0;
        int n = nums.size();
        vector<long long> dp(n, INT_MIN);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                long long subCost = calculateCost(nums, j, i);
                if (j > 0) {
                    dp[i] = max(dp[i], dp[j - 1] + subCost);
                } else {
                    dp[i] = max(dp[i], subCost);
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {
    vector<int> nums;
    long long answer;
    Solution solve;

    nums = {-3, -5, -17, -10};
    answer = -1;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {1, -2, 3, 4};
    answer = 10;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {-997};
    answer = -997;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {-13, 3};
    answer = -10;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {1, -1, 1, -1};
    answer = 4;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {0};
    answer = 0;
    assert(answer == solve.maximumTotalCost(nums));

    nums = {1, -1};
    answer = 2;
    assert(answer == solve.maximumTotalCost(nums));

    return 0;
}

// https://leetcode.com/problems/house-robber/description/
// Created by omega515 on 17.11.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            // To avoid out of bounds error from setting base case
            return nums[0];
        }

        int n = int(nums.size());
        vector<int> dp(n);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            // Recurrence relation
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};


int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 2, 3, 1};
    answer = 4;
    assert(answer == solve.rob(nums));

    nums = {2, 7, 9, 3, 1};
    answer = 12;
    assert(answer == solve.rob(nums));

    return 0;
}

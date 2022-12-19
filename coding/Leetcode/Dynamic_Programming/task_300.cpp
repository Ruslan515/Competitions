// https://leetcode.com/problems/longest-increasing-subsequence/
// https://leetcode.com/problems/longest-increasing-subsequence/
// Created by ruslan515 on 19.12.22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        int global_max = dp[0];
        for (int i = 1; i < n + 1; ++i) {
            int max_dp = dp[0];
            int t1 = nums[i - 1];
            for (int j = 0; j < i; ++j) {
                if (nums[j] < t1) {
                    max_dp = max(max_dp, dp[j + 1]);
                }
            }
            dp[i] = max_dp + 1;
            global_max = max(global_max, dp[i]);
        }
        ans = global_max;
        return ans;
    }
};

void read_data(vector<int>& nums) {
    int temp;
    while (cin >> temp)
        nums.push_back(temp);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;
    cout << solve.lengthOfLIS(nums);

    return 0;
}
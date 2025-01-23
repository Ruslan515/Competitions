// https://leetcode.com/contest/biweekly-contest-98/problems/minimum-score-by-changing-two-elements/
// Created by ruslan515 on 18.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ans = min(
                {
                    nums[n - 1] - nums[0],
                    nums[n - 1] - nums[2],
                    nums[n - 3] - nums[0],
                    nums[n - 2] - nums[1]
                }
                );

        return ans;
    }
};

void read_data(vector<int>& nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;
    cout <<  solve.minimizeSum(nums);

    return 0;
}
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
// Created by ruslan515 on 04.03.23.
//

/*
35054 945315
35054 398719 945315 945315 820417 945315 35054 945315 171832 945315 35054 109750 790964 441974 552913
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;

        for(int left = 0; left < n; ++left) {
            for(int right = left + 1; right < n + 1; ++right) {
                int minWindow = nums[left];
                int maxWindow = nums[left];
                for (int i = left; i < right; ++i) {
                    minWindow = min(minWindow, nums[i]);
                    maxWindow = max(maxWindow, nums[i]);
                }
                if (minWindow == minK && maxWindow == maxK) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

void read_data(vector<int> &nums, int &minK, int &maxK) {
    cin >> minK >> maxK;
    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
    }

    return;
}

int main() {
    vector<int> nums;
    int minK;
    int maxK;
    read_data(nums, minK, maxK);
    Solution solve;

    cout << solve.countSubarrays(nums, minK, maxK) << "\n";
    return 0;
}
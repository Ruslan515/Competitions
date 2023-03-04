// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
// Created by ruslan515 on 04.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;

        int start = 1;
        if (minK < maxK) {
            start = 2;
        }
        for (int sizeWindow = start; sizeWindow < n + 1; ++sizeWindow) {
            for (int startWindow = 0; startWindow < n - sizeWindow + 1; ++startWindow) {
                int minWindow = nums[startWindow];
                int maxWindow = nums[startWindow];
                for (int i = startWindow; i < sizeWindow; ++i) {
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
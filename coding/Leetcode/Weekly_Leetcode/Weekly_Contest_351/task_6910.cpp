// https://leetcode.com/contest/weekly-contest-351/problems/ways-to-split-array-into-good-subarrays/
// Created by Ruslan Khalikov on 25.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int> &nums) {
        int n = nums.size();
        int left = 0, good_subarrays = 0;
        const int MOD = 1e9 + 7;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 1) {
                int len = right - left;
                int before = 0, after = 0;
                while (left < right && nums[left] == 0) {
                    before++;
                    left++;
                }
                while (right < n && nums[right] == 0) {
                    after++;
                    right++;
                }
                good_subarrays = (good_subarrays + ((before + 1) * (after + 1)) % MOD) % MOD;
            }
        }

        return good_subarrays;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {0, 1, 0, 0, 1};
    answer = 3;
    assert(answer == solve.numberOfGoodSubarraySplits(nums));

    nums = {0, 1, 0};
    answer = 1;
    assert(answer == solve.numberOfGoodSubarraySplits(nums));

    return 0;
}

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/?envType=daily-question&envId=2025-02-26
// Created by omega515 on 26.02.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int prev_sum_max = 0, prev_sum_min = 0;
        int val;
        for (int i = 0; i < n; ++i) {
            val = nums[i];
            prev_sum_max = max(prev_sum_max + val, max(val, 0));
            prev_sum_min = min(prev_sum_min + val, min(val, 0));
            answer = max(answer, max(abs(prev_sum_min), abs(prev_sum_max)));
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, -5, 1, -4, 3, -2};
    answer = 8;
    assert(answer == solve.maxAbsoluteSum(nums));

    nums = {1, -3, 2, 3, -4};
    answer = 5;
    assert(answer == solve.maxAbsoluteSum(nums));

    return 0;
}


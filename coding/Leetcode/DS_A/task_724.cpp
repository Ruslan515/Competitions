// https://leetcode.com/problems/find-pivot-index/
// Created by ruslan515 on 02.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int answer = -1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        int rightSum = 0;
        int leftSum = nums[n - 1] - nums[0];
        if (rightSum == leftSum) {
            answer = 0;
        } else {
            for (int i = 1; i < n; ++i) {
                rightSum = nums[i - 1];
                leftSum = nums[n - 1] - nums[i];
                if (rightSum == leftSum) {
                    answer = i;
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 7, 3, 6, 5, 6};
    answer = 3;
    assert(answer == solve.pivotIndex(nums));

    nums = {1, 2, 3};
    answer = -1;
    assert(answer == solve.pivotIndex(nums));

    nums = {2, 1, -1};
    answer = 0;
    assert(answer == solve.pivotIndex(nums));

    return 0;
}

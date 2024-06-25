// https://leetcode.com/problems/left-and-right-sum-differences/description/
// Created by omega515 on 09.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int> &nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> leftSum(n, 0), rightSum(n, 0);
        int x, sums = 0;
        for (int i = 0; i < n; ++i) {
            leftSum[i] = sums;
            sums += nums[i];
        }

        sums = 0;
        for (int i = n - 1; i >= 0; --i) {
            rightSum[i] = sums;
            sums += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            answer.push_back(abs(leftSum[i] - rightSum[i]));
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {10, 4, 8, 3};
    answer = {15, 1, 11, 22};
    assert(answer == solve.leftRightDifference(nums));

    nums = {1};
    answer = {0};
    assert(answer == solve.leftRightDifference(nums));

    return 0;
}

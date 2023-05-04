// https://leetcode.com/problems/maximum-average-subarray-i/description/
// Created by ruslan515 on 04.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double answer, current;
        for (int i = 0; i < k; ++i) {
            current += nums[i];
        }
        answer = current;
        int n = nums.size();
        for (int i = k; i < n; ++i) {
            current += nums[i];
            current -= nums[i - k];
            answer = max(answer, current);
        }
        answer /= k * 1.0;
        return answer;
    }
};

int main() {
    double answer;
    int k;
    vector<int> nums;
    Solution solve;

    nums = {1, 12, -5, -6, 50, 3}, k = 4;
    answer = 12.75000;
    assert(solve.findMaxAverage(nums, k) == answer);

    nums = {5}, k = 1;
    answer = 5.00000;
    assert(solve.findMaxAverage(nums, k) == answer);

    return 0;
}
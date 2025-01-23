// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/?envType=daily-question&envId=2024-11-16
// Created by omega515 on 16.11.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        vector<int> answer;
        int n = nums.size();
        if (n == 1 || k == 1) {
            return nums;
        }
        for (int start = 0; start < n - k + 1; ++start) {
            int localMax = -1;
            for (int i = start + 1; i < start + k; ++i) {
                if ((nums[i] - nums[i - 1]) != 1) {
                    localMax = -1;
                    break;
                }
                localMax = max(localMax, nums[i]);
            }
            answer.push_back(localMax);
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    vector<int> answer;
    Solution solve;

    nums = {1, 3, 4}, k = 2;
    answer = {-1, 4};
    assert(answer == solve.resultsArray(nums, k));

    nums = {1, 4}, k = 1;
    answer = {1, 4};
    assert(answer == solve.resultsArray(nums, k));

    nums = {1}, k = 1;
    answer = {1};
    assert(answer == solve.resultsArray(nums, k));

    nums = {1, 2, 3, 4, 3, 2, 5}, k = 3;
    answer = {3, 4, -1, -1, -1};
    assert(answer == solve.resultsArray(nums, k));

    nums = {2, 2, 2, 2, 2}, k = 4;
    answer = {-1, -1};
    assert(answer == solve.resultsArray(nums, k));

    nums = {3, 2, 3, 2, 3, 2}, k = 2;
    answer = {-1, 3, -1, 3, -1};
    assert(answer == solve.resultsArray(nums, k));

    return 0;
}

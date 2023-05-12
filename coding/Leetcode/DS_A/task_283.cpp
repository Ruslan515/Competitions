// https://leetcode.com/problems/move-zeroes/
// Created by Ruslan Khalikov on 12.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int left = 0, right = left;
        while (left < n && right < n) {
            while (left < n && nums[left] != 0) {
                ++left;
            }
            right = left;
            while (right < n && nums[right] == 0) {
                ++right;
            }
            if (right == n) {
                return;
            }
            swap(nums[left], nums[right]);
            ++left;
            ++right;
        }
        return;
    }
};

int main() {
    vector<int> nums, answer;
    Solution solve;

    nums = {0, 0};
    answer = {0, 0};
    solve.moveZeroes(nums);
    assert(nums == answer);

    nums = {0, 1, 0, 3, 12};
    answer = {1, 3, 12, 0, 0};
    solve.moveZeroes(nums);
    assert(nums == answer);

    nums = {0};
    answer = {0};
    solve.moveZeroes(nums);
    assert(nums == answer);

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-119/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Created by ruslan515 on 09.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        int answer = 0;
        int left = 0, right = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int key, val;
        while (right < n) {
            while (right < n) {
                key = nums[right];
                ++mp[key];
                val = mp[key];
                if (val > k) {
                    break;
                }
                ++right;
            }
            int len = right - left;
            answer = max(answer, len);

            int x;
            while (left < n && key != nums[left]) {
                x = nums[left];
                --mp[x];
                ++left;
            }
            --mp[key];
            ++left;
            ++right;
            len = right - left;
            answer = max(answer, len);

        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {1, 2, 3, 1, 2, 3, 1, 2}, k = 2;
    answer = 6;
    assert(answer == solve.maxSubarrayLength(nums, k));

    nums = {1, 2, 1, 2, 1, 2, 1, 2}, k = 1;
    answer = 2;
    assert(answer == solve.maxSubarrayLength(nums, k));

    nums = {5, 5, 5, 5, 5, 5, 5}, k = 4;
    answer = 4;
    assert(answer == solve.maxSubarrayLength(nums, k));

    return 0;
}


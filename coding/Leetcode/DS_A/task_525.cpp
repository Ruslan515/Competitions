// https://leetcode.com/problems/contiguous-array/description/
// Created by omega515 on 10.12.23.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int answer = 0;
        int n = nums.size();
        if (n == 1) {
            return answer;
        }
        unordered_map<int, int> mp = {{0, 0},
                                      {1, 0}};
        int left = 0, right = 0;
        int temp;
        while (right < n) {
            while (right < n) {
                temp = nums[right];
                ++mp[temp];
                if (abs(mp[0] - mp[1]) > 1) {
                    break;
                }
                ++right;
            }
            if (mp[0] != 0 && mp[1] != 0) {
                int len = right - left;
                if (mp[0] != mp[1]) {
                    len = right - left - 1;
                }
                answer = max(answer, len);
            }
            while (left < n && temp != nums[left]) {
                --mp[left];
                ++left;
            }
            --mp[left];
            ++left;
            ++right;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0};
    answer = 6;
    assert(answer == solve.findMaxLength(nums));

    nums = {0, 0, 0, 1, 1, 1, 0};
    answer = 6;
    assert(answer == solve.findMaxLength(nums));

    nums = {0, 1};
    answer = 2;
    assert(answer == solve.findMaxLength(nums));

    nums = {0, 1, 0};
    answer = 2;
    assert(answer == solve.findMaxLength(nums));

    nums = {0, 1, 0, 1, 0};
    answer = 4;
    assert(answer == solve.findMaxLength(nums));

    nums = {0, 0, 1, 0, 1, 0};
    answer = 4;
    assert(answer == solve.findMaxLength(nums));

    return 0;
}
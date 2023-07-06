// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Created by ruslan515 on 05.07.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int answer = 0;
        int countZero = 0;
        while (right < n) {
            while (right < n && nums[right] == 1) {
                ++right;
            }
            if (right < n) {
                while (right < n && countZero < 2) {
                    if (nums[right] == 0) {
                        ++countZero;
                    }
                    ++right;
                }
                answer = max(answer, right - left - 2);
                if (countZero == 2) {
                    while (left < n && countZero == 2) {
                        if (nums[left] == 0) {
                            --countZero;
                        }
                        ++left;
                    }
                } else {
                    answer = max(answer, right - left - 1);
                }
            } else {
                answer = max(answer, right - left - 2);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;

    Solution solve;

    nums = {1, 1, 0, 1};
    answer = 3;
    assert(answer == solve.longestSubarray(nums));

    nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    answer = 5;
    assert(answer == solve.longestSubarray(nums));

    nums = {1, 1, 1};
    answer = 2;
    assert(answer == solve.longestSubarray(nums));

    return 0;
}
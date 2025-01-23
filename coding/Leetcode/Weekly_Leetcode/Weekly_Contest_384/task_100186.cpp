// https://leetcode.com/contest/weekly-contest-384/problems/number-of-subarrays-that-match-a-pattern-i/
// Created by omega515 on 11.02.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkEl(vector<int> &nums, int k, int i, int pattern) {
        bool answer = false;
        if (pattern == 1) {
            answer = nums[i + k + 1] > nums[i + k];
        } else if (pattern == 0) {
            answer = nums[i + k + 1] == nums[i + k];
        } else {
            answer = nums[i + k + 1] < nums[i + k];
        }
        return answer;
    }

    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
        int answer = 0;
        int n = nums.size();
        int m = pattern.size();
        for (int i = 0; i < n - m; ++i) {
            bool flag = true;
            for (int k = 0; k < m; ++k) {
                for (int j = i; j < i + m; ++j) {
                    bool chech = checkEl(nums, k, i, pattern[k]);
                    if (!chech) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums, pattern;
    int answer;
    Solution solve;

    nums = {1, 2, 3, 4, 5, 6}, pattern = {1, 1};
    answer = 4;
    assert(answer == solve.countMatchingSubarrays(nums, pattern));

    nums = {1, 4, 4, 1, 3, 5, 5, 3}, pattern = {1, 0, -1};
    answer = 2;
    assert(answer == solve.countMatchingSubarrays(nums, pattern));

    return 0;
}


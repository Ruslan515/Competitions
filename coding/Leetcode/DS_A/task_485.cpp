// https://leetcode.com/problems/max-consecutive-ones/
// Created by Ruslan Khalikov on 10.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int start = 0;
        int max_count = 0;
        while (start < n) {
            int j = start + 1;
            if (nums[start] == 1) {
                while (j < n && nums[j] == 1) {
                    ++j;
                }
                max_count = max(max_count, j - start);
            }
            start = j;
        }
        return max_count;
    }
};

int main() {
    int answer;
    vector<int> nums;
    Solution solve;

    nums = {0, 1};
    answer = 1;
    assert(solve.findMaxConsecutiveOnes(nums) == answer);

    nums = {1, 1, 0, 1};
    answer = 2;
    assert(solve.findMaxConsecutiveOnes(nums) == answer);

    nums = {1, 1, 0, 1, 1, 1};
    answer = 3;
    assert(solve.findMaxConsecutiveOnes(nums) == answer);

    nums = {1, 0, 1, 1, 0, 1};
    answer = 2;
    assert(solve.findMaxConsecutiveOnes(nums) == answer);

    return 0;
}
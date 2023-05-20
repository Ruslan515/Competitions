// https://leetcode.com/problems/missing-number/
// Created by ruslan515 on 20.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) {
            return 0;
        }
        int n = nums.size();
        if (nums[n - 1] != n) {
            return n;
        }

        int answer = 0;
        for (int i = 0; i < n - 1; ++i) {
            int diff = nums[i + 1] - nums[i];
            if (diff != 1) {
                answer = nums[i] + 1;
                break;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {3, 0, 1};
    answer = 2;
    assert(solve.missingNumber(nums) == answer);

    nums = {0, 1};
    answer = 2;
    assert(solve.missingNumber(nums) == answer);

    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    answer = 8;
    assert(solve.missingNumber(nums) == answer);

    return 0;
}
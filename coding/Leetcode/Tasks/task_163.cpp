// https://leetcode.com/problems/missing-ranges/
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> answer;
        if (n == 0) {
            vector<int> temp;
            temp.push_back(lower);
            temp.push_back(upper);
            answer.push_back(temp);
            return answer;
        }
        if (nums[n - 1] < lower || nums[0] > upper) {
            return answer;
        }
        int delta;
        delta = nums[0] - lower;
        if (delta >= 1) {
            vector<int> temp;
            int l = lower;
            int u = nums[0] - 1;
            temp.push_back(l);
            temp.push_back(u);
            answer.push_back(temp);
        }

        for (int i = 1; i < n; ++i) {
            delta = nums[i] - nums[i - 1];
            if (delta >= 2) {
                vector<int> temp;
                int l = nums[i - 1] + 1;
                int u = nums[i] - 1;
                int left = max(l, lower);
                int right = min(u, upper);
                temp.push_back(left);
                temp.push_back(right);
                answer.push_back(temp);
            }
        }
        delta = upper - nums[n - 1];
        if (delta >= 1) {
            vector<int> temp;
            int l = nums[n - 1] + 1;
            int u = upper;
            temp.push_back(l);
            temp.push_back(u);
            answer.push_back(temp);
        }

        return answer;
    }
};

int main() {
    int lower;
    int upper;
    vector<int> nums;
    vector<vector<int>> answer;
    Solution solve;

    nums = {}, lower = 1, upper = 1;
    answer = {
            {1, 1}
    };
    assert(answer == solve.findMissingRanges(nums, lower, upper));

    nums = {0, 1, 3, 50, 75}, lower = -10, upper = 99;
    answer = {
            {-10, -1},
            {2,   2},
            {4,   49},
            {51,  74},
            {76,  99}
    };
    assert(answer == solve.findMissingRanges(nums, lower, upper));

    nums = {0, 1, 3, 50, 75}, lower = 0, upper = 99;
    answer = {{2,  2},
              {4,  49},
              {51, 74},
              {76, 99}};
    assert(answer == solve.findMissingRanges(nums, lower, upper));

    nums = {-1}, lower = -1, upper = -1;
    answer = {};
    assert(answer == solve.findMissingRanges(nums, lower, upper));

    return 0;
}
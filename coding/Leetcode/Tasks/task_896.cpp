// https://leetcode.com/problems/monotonic-array/description/?envType=daily-question&envId=2023-09-29
// Created by ruslan515 on 29.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &nums) {
        int n = nums.size();
        bool answer = true;
        if (n == 1 || n == 2) {
            return true;
        }

        vector<int> diff;
        for (int i = 1; i < n; ++i) {
            int dx = nums[i] - nums[i - 1];
            diff.push_back(dx);
        }
        int i = 0;
        while (i < n - 1 && diff[i] == 0) {
            ++i;
        }
        if (i == n - 1) {
            return true;
        }
        int x = diff[i];
        if (x > 0) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (diff[j] < 0) {
                    return false;
                }
            }
        } else {
            for (int j = i + 1; j < n - 1; ++j) {
                if (diff[j] > 0) {
                    return false;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    bool answer;
    Solution solve;

    nums = {1, 1, 1};
    answer = true;
    assert(answer == solve.isMonotonic(nums));

    nums = {1, 2, 2, 3};
    answer = true;
    assert(answer == solve.isMonotonic(nums));

    nums = {1, 3, 2};
    answer = false;
    assert(answer == solve.isMonotonic(nums));

    nums = {11, 11, 9, 4, 3, 3, 3, 1, -1, -1, 3, 3, 3, 5, 5, 5};
    answer = false;
    assert(answer == solve.isMonotonic(nums));

    nums = {6, 5, 4, 4};
    answer = true;
    assert(answer == solve.isMonotonic(nums));


    return 0;
}

// https://leetcode.com/problems/two-sum-less-than-k/description/
// Created by omega515 on 05.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> &nums, int k) {
        int answer = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int first, second, temp;

        for (int i = 0; i < n; ++i) {
            first = nums[i];
            second = k - first;
            // 1, 8, 23, 24, 33, 34, 54, 75
            for (int j = n - 1; j > i; --j) {
                temp = nums[j];
                if (temp < second) {
                    answer = max(answer, first + temp);
                }
            }

        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k, answer;
    Solution solve;

    nums = {254, 914, 110, 900, 147, 441, 209, 122, 571, 942, 136, 350, 160, 127, 178, 839, 201, 386, 462, 45, 735, 467,
            153, 415, 875, 282, 204, 534, 639, 994, 284, 320, 865, 468, 1, 838, 275, 370, 295, 574, 309, 268, 415, 385,
            786, 62, 359, 78, 854, 944};
    k = 200;
    answer = 198;
    assert(answer == solve.twoSumLessThanK(nums, k));


    nums = {34, 23, 1, 24, 75, 33, 54, 8}, k = 60;
    answer = 58;
    assert(answer == solve.twoSumLessThanK(nums, k));

    nums = {10, 20, 30}, k = 15;
    answer = -1;
    assert(answer == solve.twoSumLessThanK(nums, k));

    return 0;
}
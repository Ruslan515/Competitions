// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=daily-question&envId=2023-12-18
// Created by omega515 on 18.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int> &nums) {
        int answer = 0;
        int firstMin = 100000, secondMin = 100000, firstMax = -1, secondMax = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        firstMax = nums[n - 1];
        secondMax = nums[n - 2];
        firstMin = nums[0];
        secondMin = nums[1];

        answer = firstMax * secondMax - firstMin * secondMin;

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {10, 10, 10, 10,};
    answer = 0;
    assert(answer == solve.maxProductDifference(nums));

    nums = {5, 6, 2, 7, 4};
    answer = 34;
    assert(answer == solve.maxProductDifference(nums));

    nums = {4, 2, 5, 9, 7, 4, 8};
    answer = 64;
    assert(answer == solve.maxProductDifference(nums));

    return 0;
}
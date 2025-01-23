// https://leetcode.com/contest/weekly-contest-349/problems/neither-minimum-nor-maximum/
// Created by Ruslan Khalikov on 11.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getSumNums(vector<int> &nums) {
        int n = nums.size();
        long long sumNums = 0;
        for (int i = 0; i < n; ++i) {
            sumNums += nums[i];
        }
        return sumNums;
    }

    long long minCost(vector<int> &nums, int x) {
        int n = nums.size();
        long long answer = 0;

        int i = 0;
        long long tempSum;
        while (i < n) {
            tempSum = getSumNums(nums);
        }


        long long totalSum = 0;
        int minCost = INT_MAX;
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            minCost = min(minCost, nums[i]);
        }
        long long minSumCost = minCost * n + x * (n - 1);
        answer = min(totalSum, minSumCost);


        return answer;
    }
};

int main() {
    vector<int> nums;
    int x;
    int answer;
    Solution solve;

    nums = {20, 1, 15};
    x = 5;
    answer = 13;
    assert(answer == solve.minCost(nums, x));

    nums = {1, 2, 3};
    x = 4;
    answer = 6;
    assert(answer == solve.minCost(nums, x));

    return 0;
}

// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
// Created by ruslan515 on 21.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        long long answer = INT64_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int opor = nums[i];
            long long sums = 0;
            for(int j = 0; j < n; ++j) {
                if (j != i) {
                    int count = abs(nums[j] - opor);
                    long long diff = (long long )count * cost[j];
                    sums += diff;
                }
            }
            answer = min(answer, sums);
        }

        return answer;
    }
};

int main() {
    vector<int> cost;
    vector<int> nums;
    long long answer;
    Solution solve;

    nums = {1, 3, 5, 2}, cost = {2, 3, 1, 14};
    answer = 8;
    assert(answer == solve.minCost(nums, cost));

    nums = {2, 2, 2, 2, 2}, cost = {4, 2, 8, 1, 3};
    answer = 0;
    assert(answer == solve.minCost(nums, cost));

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-114/problems/split-array-into-maximum-number-of-subarrays/
// Created by ruslan515 on 30.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {

    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 0, 2, 0, 1, 2};
    answer = 3;
    assert(answer == solve.maxSubarrays(nums));

    nums = {5, 7, 1, 3};
    answer = 1;
    assert(answer == solve.maxSubarrays(nums));

    return 0;
}


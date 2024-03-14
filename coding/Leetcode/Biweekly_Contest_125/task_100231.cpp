// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-i/
// Created by omega515 on 02.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int answer = 0;
        for (int num: nums) {
            if (num < k) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {2, 11, 10, 1, 3}, k = 10;
    answer = 3;
    assert(answer == solve.minOperations(nums, k));

    nums = {1, 1, 2, 4, 9}, k = 1;
    answer = 0;
    assert(answer == solve.minOperations(nums, k));

    nums = {1, 1, 2, 4, 9}, k = 9;
    answer = 4;
    assert(answer == solve.minOperations(nums, k));

    return 0;
}


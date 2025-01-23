// https://leetcode.com/contest/biweekly-contest-104/problems/maximum-or/
// Created by Ruslan Khalikov on 13.05.2023.
//

#include <bits/stdc++.h>

class Solution {
public:
    long long maximumOr(vector<int> &nums, int k) {

    }
};

int main() {
    vector<int> nums;
    int k, answer;
    Solution solve;

    nums = {12, 9}, k = 1;
    answer = 30;
    assert(answer == solve.maximumOr(nums, k));

    nums = {8, 1, 2}, k = 2;
    answer = 35;
    assert(answer == solve.maximumOr(nums, k));

    return 0;
}
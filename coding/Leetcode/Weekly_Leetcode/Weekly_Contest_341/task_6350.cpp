// https://leetcode.com/contest/weekly-contest-341/problems/find-the-maximum-divisibility-score/
// Created by ruslan515 on 16.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        int max_score = -1;
        int max_div = INT_MAX;
        int d = divisors.size();
        int n = nums.size();
        vector<int> idx;

        for (int i = 0; i < d; ++i) {
            int count = 0;
            int div = divisors[i];
            for (int j = 0; j < n; ++j) {
                int num = nums[j];
                if (num % div == 0) {
                    ++count;
                }
            }
            if (count > max_score) {
                max_score = count;
            }
        }

        for (int i = 0; i < d; ++i) {
            int count = 0;
            int div = divisors[i];
            for (int j = 0; j < n; ++j) {
                int num = nums[j];
                if (num % div == 0) {
                    ++count;
                }
            }
            if (count == max_score) {
                idx.push_back(i);
            }
        }

        int min_div = INT_MAX;
        for (int i = 0; i < idx.size(); ++i) {
            int j = idx[i];
            if (divisors[j] < min_div) {
                min_div = divisors[j];
            }
        }
        return min_div;

    }
};


int main() {
    vector<int> nums, divisors;
    int answer;
    Solution solve;

    nums = {73,13,20,6};
    divisors = {56,75,83,26,24,53,56,61};
    answer = 24;
    assert(solve.maxDivScore(nums, divisors) == answer);

    nums = {4, 7, 9, 3, 9}, divisors = {5, 2, 3};
    answer = 3;
    assert(solve.maxDivScore(nums, divisors) == answer);

    nums = {20, 14, 21, 10}, divisors = {5, 7, 5};
    answer = 5;
    assert(solve.maxDivScore(nums, divisors) == answer);

    nums = {12}, divisors = {10, 16};
    answer = 10;
    assert(solve.maxDivScore(nums, divisors) == answer);

    return 0;
}
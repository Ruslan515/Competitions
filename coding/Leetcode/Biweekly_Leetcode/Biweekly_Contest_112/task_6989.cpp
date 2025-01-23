// https://leetcode.com/contest/biweekly-contest-112/problems/maximum-sum-of-almost-unique-subarray/
// Created by ruslan515 on 02.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int> &nums, int m, int k) {
        long long answer = 0;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; ++i) {
            set<int> mySet;
            long long tempSum = 0;
            for (int j = i; j < i + k; ++j) {
                int current = nums[j];
                tempSum += current;
                mySet.insert(current);
            }
            int size = mySet.size();
            if (size >= m) {
                answer = max(answer, tempSum);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int m, k;
    long long answer;
    Solution solve;

    nums = {1, 1, 1, 3}, m = 2, k = 2;
    answer = 4;
    assert(answer == solve.maxSum(nums, m, k));

    nums = {2, 6, 7, 3, 1, 7}, m = 3, k = 4;
    answer = 18;
    assert(answer == solve.maxSum(nums, m, k));

    nums = {5, 9, 9, 2, 4, 5, 4}, m = 1, k = 3;
    answer = 23;
    assert(answer == solve.maxSum(nums, m, k));

    nums = {1, 2, 1, 2, 1, 2, 1}, m = 3, k = 3;
    answer = 0;
    assert(answer == solve.maxSum(nums, m, k));

    return 0;
}


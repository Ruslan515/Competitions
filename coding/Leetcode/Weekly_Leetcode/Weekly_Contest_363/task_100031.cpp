// https://leetcode.com/contest/weekly-contest-363/problems/sum-of-values-at-indices-with-k-set-bits/
// Created by ruslan515 on 17.09.23.
//


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = i;
            int countBits = 0;
            while (num != 0) {
                if (num & 1) {
                    ++countBits;
                }
                num = num >> 1;
            }
            if (countBits == k) {
                answer += nums[i];
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

    nums = {5, 10, 1, 5, 2}, k = 1;
    answer = 13;
    assert(answer == solve.sumIndicesWithKSetBits(nums, k));

    nums = {4, 3, 2, 1}, k = 2;
    answer = 1;
    assert(answer == solve.sumIndicesWithKSetBits(nums, k));

    return 0;
}

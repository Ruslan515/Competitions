// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-ii/
// Created by ruslan515 on 01.10.23.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        long long answer = 0;
        int n = nums.size();
        long long temp;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long x = nums[i] - nums[j];
                if (x > 0) {
                    long long y = *max_element(nums.begin() + j + 1, nums.end());
                    temp = x * y;
                    answer = max(answer, temp);
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    long long answer;
    Solution solve;

    nums = {5,7,8,4};
    answer = 0;
    assert(answer == solve.maximumTripletValue(nums));

    nums = {1000000, 1, 1000000};
    answer = 999999000000;
    assert(answer == solve.maximumTripletValue(nums));

    nums = {2, 3, 1};
    answer = 0;
    assert(answer == solve.maximumTripletValue(nums));

    nums = {12, 6, 1, 2, 7};
    answer = 77;
    assert(answer == solve.maximumTripletValue(nums));

    nums = {1, 10, 3, 4, 19};
    answer = 133;
    assert(answer == solve.maximumTripletValue(nums));

    nums = {1, 2, 3};
    answer = 0;
    assert(answer == solve.maximumTripletValue(nums));

    return 0;
}

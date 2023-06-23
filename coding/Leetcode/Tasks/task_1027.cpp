// https://leetcode.com/problems/longest-arithmetic-subsequence/
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        int n = nums.size();
        // dp[i] - длинна самой длинной арифметической подпоследовательности
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {

        }


    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {3, 6, 9, 12};
    answer = 4;
    assert(answer == solve.longestArithSeqLength(nums));

    nums = {9, 4, 7, 2, 10};
    answer = 3;
    assert(answer == solve.longestArithSeqLength(nums));

    nums = {20, 1, 15, 3, 10, 5, 8};
    answer = 4;
    assert(answer == solve.longestArithSeqLength(nums));

    return 0;
}

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03
// Created by omega515 on 03.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 1;
        int n = nums.size();
        int maxInc = 1, maxDec = 1;
        int current, prev;
        for (int i = 1; i < n; ++i) {
            prev = nums[i - 1];
            current = nums[i];
            if (current > prev) {
                answer = max(answer, maxDec);
                maxDec = 1;
                maxInc++;
            } else if (current < prev) {
                ++maxDec;
                answer = max(answer, maxInc);
                maxInc = 1;
            } else {
                answer = max(answer, max(maxInc, maxDec));
                maxInc = 1;
                maxDec = 1;
            }
        }
        answer = max(answer, max(maxInc, maxDec));


        return answer;
    }
};


int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 10, 10};
    answer = 2;
    assert(answer == solve.longestMonotonicSubarray(nums));

    nums = {1, 4, 3, 3, 2};
    answer = 2;
    assert(answer == solve.longestMonotonicSubarray(nums));


    nums = {3, 3, 3, 3};
    answer = 1;
    assert(answer == solve.longestMonotonicSubarray(nums));

    nums = {3, 2, 1};
    answer = 3;
    assert(answer == solve.longestMonotonicSubarray(nums));


    return 0;
}


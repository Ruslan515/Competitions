// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04
// Created by omega515 on 04.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int tmpSum = nums[0];
        int prev = nums[0];
        int current;
        for (int i = 1; i < n; ++i) {
            current = nums[i];
            if (current > prev) {
                tmpSum += current;
            } else {
                answer = max(answer, tmpSum);
                tmpSum = current;
            }
            prev = current;
        }
        answer = max(answer, tmpSum);


        return answer;
    }
};


int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {10, 20, 30, 5, 10, 50};
    answer = 65;
    assert(answer == solve.maxAscendingSum(nums));

    nums = {10, 20, 30, 40, 50};
    answer = 150;
    assert(answer == solve.maxAscendingSum(nums));

    nums = {12, 17, 15, 13, 10, 11, 12};
    answer = 33;
    assert(answer == solve.maxAscendingSum(nums));


    return 0;
}


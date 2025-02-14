// https://leetcode.com/problems/make-the-prefix-sum-non-negative/description/?envType=weekly-question&envId=2025-02-08
// Created by omega515 on 11.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int makePrefSumNonNegative(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        queue<int> q;
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        long prefixSum = 0;
        long tmp;
        for (int i = 0; i < n; ++i) {
            tmp = (long) nums[i];
            if (tmp < 0) {
                pq.push(tmp);
            }

            prefixSum += tmp;
            if (prefixSum < 0) {
                ++answer;
                tmp = (long) pq.top();
                pq.pop();
                prefixSum -= tmp;
            }

        }

        return answer;
    }
};


int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {3, -5, -2, 6};
    answer = 1;
    assert(answer == solve.makePrefSumNonNegative(nums));

    nums = {2, 3, -5, 4};
    answer = 0;
    assert(answer == solve.makePrefSumNonNegative(nums));

    return 0;
}


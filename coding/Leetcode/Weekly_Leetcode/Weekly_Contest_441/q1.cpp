// https://leetcode.com/contest/weekly-contest-441/problems/maximum-unique-subarray-sum-after-deletion/description/
// Created by omega515 on 16.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        int val, cnt, minNum = -101;
        for (auto it: freq) {
            val = it.first;
            cnt = it.second;
            if (val > 0) {
                answer += val;
            } else {
                minNum = max(minNum, val);
            }
        }

        if (answer == 0) {
            answer = minNum;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {-1, 0, -2};
    answer = 0;
    assert(answer == solve.maxSum(nums));

    nums = {-15, -17};
    answer = -15;
    assert(answer == solve.maxSum(nums));

    nums = {-100};
    answer = -100;
    assert(answer == solve.maxSum(nums));

    nums = {1, 2, 3, 4, 5};
    answer = 15;
    assert(answer == solve.maxSum(nums));

    nums = {1, 1, 0, 1, 1};
    answer = 1;
    assert(answer == solve.maxSum(nums));

    nums = {1, 2, -1, -2, 1, 0, -1};
    answer = 3;
    assert(answer == solve.maxSum(nums));

    return 0;
}

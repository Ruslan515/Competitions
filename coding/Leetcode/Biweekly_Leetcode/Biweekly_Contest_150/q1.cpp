// https://leetcode.com/contest/biweekly-contest-150/problems/sum-of-good-numbers/description/?slug=separate-squares-i&tab=description&region=global_v2
// Created by omega515 on 15.02.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int left_idx, right_idx;
        int left_val, right_val, curr_val;
        bool left_bool, right_bool;
        for (int i = 0; i < n; ++i) {
            left_idx = i - k;
            right_idx = i + k;
            curr_val = nums[i];
            if (left_idx >= 0) {
                left_val = nums[left_idx];
                if (curr_val > left_val) {
                    left_bool = true;
                } else {
                    continue;
                }
            }
            if (right_idx < n) {
                right_val = nums[right_idx];
                if (curr_val > right_val) {
                    right_bool = true;
                } else {
                    continue;
                }
            }
            answer += curr_val;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {1, 3, 2, 1, 5, 4}, k = 2;
    answer = 12;
    assert(answer == solve.sumOfGoodNumbers(nums, k));

    nums = {2, 1}, k = 1;
    answer = 2;
    assert(answer == solve.sumOfGoodNumbers(nums, k));

    return 0;
}

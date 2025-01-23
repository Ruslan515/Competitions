// https://leetcode.com/contest/biweekly-contest-100/problems/find-score-of-an-array-after-marking-all-elements/
// Created by ruslan515 on 18.03.23.
//

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        while (true) {
            int idx = min_element(nums.begin(), nums.end()) - nums.begin();
            int t = nums[idx];
            if (t == INT_MAX) {
                break;
            }
            score += t;
            nums[idx] = INT_MAX;

            int idx_left = idx - 1;
            int idx_right = idx + 1;
            if (idx_left > - 1) {
                nums[idx_left] = INT_MAX;
            }
            if (idx_right < n) {
                nums[idx_right] = INT_MAX;
            }
        }


        return score;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {2,1,3,4,5,2};
    assert(solve.findScore(nums) == 7);
    nums = {2,3,5,1,3,2};
    assert(solve.findScore(nums) == 5);

    return 0;
}
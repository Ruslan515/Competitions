// https://leetcode.com/contest/biweekly-contest-102/problems/find-the-width-of-columns-of-a-grid/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &nums) {
        vector<long long> ans;
        ans.push_back(nums[0] * 2);
        long long current_max = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            long long current = nums[i];
            current_max = max(current_max, current);
            long long conver = current + current_max;
            conver += ans[i - 1];
            ans.push_back(conver);
        }
        return ans;
    }
};


int main() {
    vector<int> nums;
    vector<long long> answer;
    Solution solve;

    nums = {2, 3, 7, 5, 10};
    answer = {4, 10, 24, 36, 56};
    assert(solve.findPrefixScore(nums) == answer);

    nums = {1, 1, 2, 4, 8, 16};
    answer = {2, 4, 8, 16, 32, 64};
    assert(solve.findPrefixScore(nums) == answer);

    return 0;
}
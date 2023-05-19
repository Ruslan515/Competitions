// https://leetcode.com/problems/single-number/description/
// Created by ruslan515 on 19.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int answer = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            answer ^= nums[i];
        }
        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 2, 1};
    answer = 1;
    assert(solve.singleNumber(nums) == answer);

    nums = {4, 1, 2, 1, 2};
    answer = 4;
    assert(solve.singleNumber(nums) == answer);

    nums = {1};
    answer = 1;
    assert(solve.singleNumber(nums) == answer);

    return 0;
}
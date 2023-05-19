// https://leetcode.com/problems/single-number-ii/description/
// Created by ruslan515 on 19.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int answer = 0;
        int help = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            answer = ~help & (answer ^ nums[i]);
            help = ~answer & (help ^ nums[i]);
        }
        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 2, 3, 2};
    answer = 3;
    assert(solve.singleNumber(nums) == answer);

    nums = {0, 1, 0, 1, 0, 1, 99};
    answer = 99;
    assert(solve.singleNumber(nums) == answer);

    return 0;
}
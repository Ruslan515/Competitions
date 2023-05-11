// https://leetcode.com/problems/running-sum-of-1d-array/description/
// Created by Ruslan Khalikov on 10.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        answer.push_back(nums[0]);
        for (int i = 1; i < n; ++i){
            answer.push_back(answer.back() + nums[i]);
        }

        return answer;
    }
};

int main() {
    vector<int> answer;
    vector<int> nums;
    Solution solve;

    nums = {1,2,3,4};
    answer = {1,3,6,10};
    assert(solve.runningSum(nums) == answer);

    nums = {1,1,1,1,1};
    answer = {1,2,3,4,5};
    assert(solve.runningSum(nums) == answer);

    nums = {3,1,2,10,1};
    answer = {3,4,6,16,17};
    assert(solve.runningSum(nums) == answer);

    return 0;
}
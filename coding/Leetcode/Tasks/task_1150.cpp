// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/
// Created by ruslan515 on 09.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int> &nums, int target) {
        bool answer = false;
        int n = nums.size();
        map<int, int> count;
        for(auto num: nums) {
            ++count[num];
        }

        int cnt = count[target];
        double half = n / 2.0;
        if (cnt > half) {
            answer = true;
        }
        return answer;

    }
};

int main() {
    int target;
    vector<int> nums;
    bool answer;
    Solution solve;

    nums = {2, 4, 5, 5, 5, 5, 5, 6, 6}, target = 5;
    answer = true;
    assert(answer == solve.isMajorityElement(nums, target));

    nums = {10, 100, 101, 101}, target = 101;
    answer = false;
    assert(answer == solve.isMajorityElement(nums, target));


    return 0;
}
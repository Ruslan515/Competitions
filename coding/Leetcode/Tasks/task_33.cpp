// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Created by ruslan515 on 08.08.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int answer = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                answer = i;
                break;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums;
    int target, answer;
    Solution solve;

    nums = {4, 5, 6, 7, 0, 1, 2}, target = 0;
    answer = 4;
    assert(answer == solve.search(nums, target));

    nums = {4, 5, 6, 7, 0, 1, 2}, target = 3;
    answer = -1;
    assert(answer == solve.search(nums, target));

    nums = {1}, target = 0;
    answer = -1;
    assert(answer == solve.search(nums, target));

    return 0;
}

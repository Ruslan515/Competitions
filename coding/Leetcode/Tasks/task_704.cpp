// https://leetcode.com/problems/binary-search/
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int answer = -1;
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        int val;
        while (left <= right) {
            middle = left + (right - left) / 2;
            val = nums[middle];
            if (val < target) {
                left = middle + 1;
            } else if (val > target) {
                right = middle - 1;
            } else {
                answer = middle;
                break;
            }
        }

        return answer;
    }
};

int main() {
    int answer;
    vector<int> nums;
    int target;
    Solution solve;

    nums = {-1, 0, 3, 5, 9, 12}, target = 9;
    answer = 4;
    assert(answer == solve.search(nums, target));

    nums = {-1, 0, 3, 5, 9, 12}, target = 2;
    answer = -1;
    assert(answer == solve.search(nums, target));

    return 0;
}
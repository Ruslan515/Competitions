// https://leetcode.com/problems/squares-of-a-sorted-array/description/
// Created by ruslan515 on 04.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> answer(n);
        if (nums[0] > 0) {
            for (int i = 0; i < n; ++i) {
                answer[i] = nums[i] * nums[i];
            }
            return answer;
        }
        int left = 0;
        int right = n - 1;
        int sq_left, sq_right;
        int i = n - 1;
        while (left <= right) {
            sq_left = nums[left] * nums[left];
            sq_right = nums[right] * nums[right];
            if (sq_right > sq_left) {
                answer[i] = sq_right;
                --right;
            } else {
                answer[i] = sq_left;
                ++left;
            }
            --i;
        }
        return answer;

    }
};

int main() {
    vector<int> answer;
    vector<int> nums;
    Solution solve;

    nums = {-4, -1, 0, 3, 10};
    answer = {0, 1, 9, 16, 100};
    assert(solve.sortedSquares(nums) == answer);

    nums = {-7, -3, 2, 3, 11};
    answer = {4, 9, 9, 49, 121};
    assert(solve.sortedSquares(nums) == answer);

    return 0;
}
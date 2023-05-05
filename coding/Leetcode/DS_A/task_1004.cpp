// https://leetcode.com/problems/max-consecutive-ones-iii/description/
// Created by ruslan515 on 06.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int left = 0;
        int current = 0;
        int answer = 0;
        int n = nums.size();
        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                ++current;
            }
            while (current > k) {
                if (nums[left] == 0) {
                    --current;
                }
                ++left;
            }

            answer = max(answer, right - left + 1);
        }
        return answer;

    }
};

int main() {
    int answer;
    int k;
    vector<int> nums;
    Solution solve;

    nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, k = 2;
    answer = 6;
    assert(solve.longestOnes(nums, k) == answer);

    nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, k = 3;
    answer = 10;
    assert(solve.longestOnes(nums, k) == answer);
    return 0;
}
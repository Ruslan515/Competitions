// https://leetcode.com/problems/missing-element-in-sorted-array/
// Created by Ruslan Khalikov on 31.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingElement(vector<int> &nums, int k) {
        int n = nums.size();
        int answer = -1;
        int first, second, diff;
        for (int i = 0; i < n - 1; ++i) {
            first = nums[i];
            second = nums[i + 1];
            diff = second - first - 1;
            if (diff != 0) {
                if (diff >= k) {
                    answer = first + k;
                    break;
                } else {
                    k -=diff;
                }
            }
        }
        if (answer == -1) {
            answer = nums[n - 1] + k;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k, answer;
    Solution solve;

    nums = {4, 7, 9, 10}, k = 3;
    answer = 8;
    assert(answer == solve.missingElement(nums, k));

    nums = {4, 7, 9, 10}, k = 1;
    answer = 5;
    assert(answer == solve.missingElement(nums, k));

    nums = {1, 2, 4}, k = 3;
    answer = 6;
    assert(answer == solve.missingElement(nums, k));

    return 0;
}
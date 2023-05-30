// https://leetcode.com/problems/minimum-size-subarray-sum/
// Created by ruslan515 on 30.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int answer = INT_MAX;
        int left = 0, right = 0, sumWindow = 0;
        int n = nums.size();
        while (right < n) {
            sumWindow += nums[right];
            while (sumWindow >= target) {
                answer = min(answer, right - left + 1);
                sumWindow -= nums[left];
                ++left;
            }
            ++right;
        }

        if (answer == INT_MAX) {
            answer = 0;
        }
        return answer;
    }
};

//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int> &nums) {
//        int answer = 0;
//        int allSum = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            allSum += nums[i];
//        }
//        if (allSum < target) {
//            return answer;
//        }
//
//        int tempSum;
//        for (int len = 1; len < n; ++len) {
//            for (int start = 0; start < n - len + 1; ++start) {
//                int end = start + len;
//                tempSum = 0;
//                for (int i = start; i < end; ++i) {
//                    tempSum += nums[i];
//                }
//                if (tempSum >= target) {
//                    answer = len;
//                    return answer;
//                }
//            }
//        }
//        if (allSum >= target) {
//            answer = n;
//            return answer;
//        }
//        return answer;
//    }
//};

int main() {
    int answer, target;
    vector<int> nums;
    Solution solve;

    target = 11, nums = {1, 1, 1, 1, 1, 1, 1, 1};
    answer = 0;
    assert(solve.minSubArrayLen(target, nums) == answer);

    target = 7, nums = {2, 3, 1, 2, 4, 3};
    answer = 2;
    assert(solve.minSubArrayLen(target, nums) == answer);

    target = 4, nums = {1, 4, 4};
    answer = 1;
    assert(solve.minSubArrayLen(target, nums) == answer);

    return 0;
}
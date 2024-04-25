// https://leetcode.com/contest/biweekly-contest-127/problems/shortest-subarray-with-or-at-least-k-i/
// Created by omega515 on 30.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int temp = 0;
            for (int j = i; j < n; ++j) {
                temp |= nums[j];
                if (temp >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
//
//
//        int answer = -1;
//        int n = nums.size();
//        vector<long long> prefixOr;
//        prefixOr[0] = nums[0];
//        for (int i = 1; i < n; ++i) {
//            prefixOr[i] = prefixOr[i - 1] | nums[i];
//        }
//
//        int max_len = n + 1;
//        for (int len = 1; len <= n; ++len) {
//            for (int start = 0; start < n - len + 1; ++start) {
//                int end = start + end;
//
//            }
//        }
//
//
//        int max_len = n + 1;
//        for (int len = 1; len <= n; ++len) {
//            for (int start = 0; start < n - len + 1; ++start) {
//                int temp = nums[start];
//                int end = start + len;
//                for (int i = start + 1; i < end; ++i) {
//                    temp = temp | nums[i];
//                }
//                if (temp >= k) {
//                    int temp_max_len = end - start;
//                    if (temp_max_len < max_len) {
//                        max_len = temp_max_len;
//                    }
//                }
//            }
//        }
//        if (max_len != n + 1) {
//            answer = max_len;
//        }
//
//
//        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {32, 1, 25, 11, 2};
    k = 59;
    answer = 4;
    assert(answer == solve.minimumSubarrayLength(nums, k));

    nums = {1, 2, 3}, k = 2;
    answer = 1;
    assert(answer == solve.minimumSubarrayLength(nums, k));

    nums = {2, 1, 8}, k = 10;
    answer = 3;
    assert(answer == solve.minimumSubarrayLength(nums, k));

    nums = {1, 2}, k = 0;
    answer = 1;
    assert(answer == solve.minimumSubarrayLength(nums, k));

    return 0;
}


// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();

        int left = 0, right = 0;
        priority_queue<int> pqMax, pqMin;
        while (right < n) {
            int diff;
            int maxNum, minNum;
            while (right < n) {
                pqMax.push(nums[right]);
                pqMin.push(-1 * nums[right]);

                maxNum = pqMax.top();
                minNum = -1 * pqMin.top();
                diff = abs(maxNum - minNum);
                if (diff > limit) {
                    break;
                }
                ++right;
            }
            answer = max(answer, right - left);
            int val;
            while (left <= right && diff > limit) {
                val = nums[left];
                if (val == pqMax.top()) {
                    pqMax.pop();
                } else if (val == (-1) * pqMin.top()) {
                    pqMin.pop();
                }
                maxNum = pqMax.top();
                minNum = -1 * pqMin.top();
                diff = abs(maxNum - minNum);
                ++left;
            }
            ++right;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int limit;
    int answer;
    Solution solve;

    nums = {1, 5, 6, 7, 8, 10, 6, 5, 6}, limit = 4;
    answer = 5;
    assert(answer == solve.longestSubarray(nums, limit));

    nums = {10, 1, 2, 4, 7, 2}, limit = 5;
    answer = 4;
    assert(answer == solve.longestSubarray(nums, limit));

    nums = {8, 2, 4, 7}, limit = 4;
    answer = 2;
    assert(answer == solve.longestSubarray(nums, limit));

    nums = {4, 2, 2, 2, 4, 4, 2, 2}, limit = 0;
    answer = 3;
    assert(answer == solve.longestSubarray(nums, limit));

    return 0;
}

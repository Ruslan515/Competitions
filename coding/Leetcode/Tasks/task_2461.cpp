// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19
// Created by omega515 on 20.11.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        class Solution {
        public:
            long long maximumSubarraySum(vector<int> &nums, int k) {
                long long ans = 0;
                long long currentSum = 0;
                int begin = 0;
                int end = 0;

                unordered_map<int, int> numToIndex;

                while (end < nums.size()) {
                    int currNum = nums[end];
                    int lastOccurrence =
                            (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

                    // if current window already has number or if window is too big,
                    // adjust window
                    while (begin <= lastOccurrence || end - begin + 1 > k) {
                        currentSum -= nums[begin];
                        begin++;
                    }
                    numToIndex[currNum] = end;
                    currentSum += nums[end];
                    if (end - begin + 1 == k) {
                        ans = max(ans, currentSum);
                    }
                    end++;
                }
                return ans;
            }
        };
    }
};


int main() {
    vector<int> nums;
    int k;
    long long answer;
    Solution solve;

    nums = {1, 5, 4, 2, 9, 9, 9}, k = 3;
    answer = 15;
    assert(answer == solve.maximumSubarraySum(nums, k));

    nums = {4, 4, 4}, k = 3;
    answer = 0;
    assert(answer == solve.maximumSubarraySum(nums, k));
    return 0;

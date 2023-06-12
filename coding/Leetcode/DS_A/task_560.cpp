// https://leetcode.com/problems/subarray-sum-equals-k/
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

//typedef long long int;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int answer = 0;
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            prefix[i] = prefix[i - 1] + x;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int x = prefix[j];
                int y = prefix[i];

                int sums = x - y ;
                if (sums == k) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};

int main() {
    int answer;
    int k;
    vector<int> nums;
    Solution solve;

    nums = {1, 2, 1, 2, 1}, k = 3;
    answer = 4;
    assert(solve.subarraySum(nums, k) == answer);

    nums = {1}, k = 1;
    answer = 1;
    assert(solve.subarraySum(nums, k) == answer);

    nums = {1, 2, 3}, k = 3;
    answer = 2;
    assert(solve.subarraySum(nums, k) == answer);

    nums = {1, 1, 1}, k = 2;
    answer = 2;
    assert(solve.subarraySum(nums, k) == answer);


    return 0;
}
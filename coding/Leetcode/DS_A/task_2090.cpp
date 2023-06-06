// https://leetcode.com/problems/k-radius-subarray-averages/description/
// Created by ruslan515 on 06.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int> &nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (long long) nums[i];
        }

        vector<int> avgs(n, -1);
        for (int i = k; i < n - k; ++i) {
            long long d = prefix[i + k] - prefix[i - k] + nums[i - k];
            d /= (2 * k + 1);
            avgs[i] = d;
        }

        return avgs;
    }
};

int main() {
    vector<int> nums;
    int k;
    vector<int> answer;
    Solution solve;

    nums = {7, 4, 3, 9, 1, 8, 5, 2, 6}, k = 3;
    answer = {-1, -1, -1, 5, 4, 4, -1, -1, -1};
    assert(answer == solve.getAverages(nums, k));

    nums = {100000}, k = 0;
    answer = {100000};
    assert(answer == solve.getAverages(nums, k));

    return 0;
}
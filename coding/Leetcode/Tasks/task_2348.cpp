// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
// Created by ruslan515 on 22.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long answer = 0;
        while (i < n) {
            while (i < n && nums[i] != 0) {
                ++i;
            }
            int len = 0;
            while (i < n && nums[i] == 0) {
                ++len;
                i++;
            }
            long long  count;
            for (int x = 1; x <= len; ++x) {
                count = len - x + 1;
                answer += count;
            }

        }

        return answer;
    }
};

void read_data(vector<int>& nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;
    cout << solve.zeroFilledSubarray(nums);
    return 0;
}
// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Created by ruslan515 on 21.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n == 1) {
            ans = nums[0];
            return ans;
        }
        int i = 0;
        for (; i < n - 1; i += 2) {
            int t1 = nums[i];
            int t2 = nums[i + 1];
            if (t1 != t2) {
                ans = t1;
                break;
            }
        }
        if (i == n - 1) {
            ans = nums[n - 1];
        }
        return ans;
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
    cout << solve.singleNonDuplicate(nums);

    return 0;
}
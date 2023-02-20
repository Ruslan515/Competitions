// https://leetcode.com/problems/search-insert-position/
// Created by ruslan515 on 20.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int idx = (left + right) / 2;
            int val = nums[idx];
            if (target < val) {
                right = idx - 1;
            } else if (target > val){
                left = idx + 1;
            } else {
                ans = idx;
                return ans;
            }
        }
        ans = left;
        return ans;
    }
};

void read_data(vector<int>& nums, int& target) {
    cin >> target;
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    int target;
    vector<int> nums;
    read_data(nums, target);
    Solution solve;
    cout << solve.searchInsert(nums, target);

    return 0;
}
// https://leetcode.com/problems/build-array-from-permutation/
// Created by ruslan515 on 14.01.23.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            ans.push_back(nums[num]);
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
    for(int i: solve.buildArray(nums)) {
        cout << i << " ";
    }
    return 0;
}
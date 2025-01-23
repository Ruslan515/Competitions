// https://leetcode.com/contest/weekly-contest-387/problems/distribute-elements-into-two-arrays-i/
// Created by omega515 on 03.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int> &nums) {
        vector<int> result, arr1, arr2;
        int n = nums.size();
        int last1 = nums[0];
        int last2 = nums[1];
        arr1.push_back(last1);
        arr2.push_back(last2);
        for (int i = 2; i < n; ++i) {
            if (last1 > last2) {
                arr1.push_back(nums[i]);
                last1 = nums[i];
            } else {
                arr2.push_back(nums[i]);
                last2 = nums[i];
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());


        return arr1;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {2, 1, 3};
    answer = {2, 3, 1};
    assert(answer == solve.resultArray(nums));

    nums = {5, 4, 3, 8};
    answer = {5, 3, 4, 8};
    assert(answer == solve.resultArray(nums));

    return 0;
}


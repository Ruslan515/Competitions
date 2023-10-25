// https://leetcode.com/contest/weekly-contest-367/problems/find-indices-with-index-and-value-difference-i/
// Created by ruslan515 on 15.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference) {
        vector<int> answer = {-1, -1};
        int n = nums.size();
        int diffIdx, diffVal;
        bool checkIdx, checkVal;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                diffIdx = abs(i - j);
                checkIdx = diffIdx >= indexDifference;
                if (checkIdx) {
                    diffVal = abs(nums[i] - nums[j]);
                    checkVal = diffVal >= valueDifference;
                    if (checkVal) {
                        answer[0] = i;
                        answer[1] = j;
                        return answer;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int indexDifference, valueDifference;
    vector<int> answer;
    Solution solve;

    nums = {5, 1, 4, 1}, indexDifference = 2, valueDifference = 4;
    answer = {0, 3};
    assert(answer == solve.findIndices(nums, indexDifference, valueDifference));

    nums = {2, 1}, indexDifference = 0, valueDifference = 0;
    answer = {0, 0};
    assert(answer == solve.findIndices(nums, indexDifference, valueDifference));

    nums = {1, 2, 3}, indexDifference = 2, valueDifference = 4;
    answer = {-1, -1};
    assert(answer == solve.findIndices(nums, indexDifference, valueDifference));

    return 0;
}


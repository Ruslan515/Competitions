// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
// Created by Ruslan Khalikov on 11.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int startValue = 1;
        int sumNums = 0;
        int minSum = 0;
        for (auto x: nums) {
            sumNums += x;
            minSum = min(minSum, sumNums);
        }
        if (minSum < 0) {
            startValue = (-1) * minSum + 1;
        }
        return startValue;
    }
};

int main() {
    int answer;
    vector<int> nums;
    Solution solve;

    nums = {-3,2,-3,4,2};
    answer = 5;
    assert(solve.minStartValue(nums) == answer);

    nums = {1,2};
    answer = 1;
    assert(solve.minStartValue(nums) == answer);

    nums = {1,-2,-3};
    answer = 5;
    assert(solve.minStartValue(nums) == answer);

    return 0;
}
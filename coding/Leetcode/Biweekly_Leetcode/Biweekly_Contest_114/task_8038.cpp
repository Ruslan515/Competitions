// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/
// Created by ruslan515 on 30.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int answer = 0;
        int n = nums.size();
        set<int> setK;
        int val;
        for (int i = n - 1; i >= 0; --i) {
            answer++;
            val = nums[i];
            if (val <= k) {
                setK.insert(val);
                if (setK.size() == k) {
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer, k;
    Solution solve;

    nums = {1}, k = 1;
    answer = 1;
    assert(answer == solve.minOperations(nums, k));

    nums = {3, 1, 5, 4, 2}, k = 2;
    answer = 4;
    assert(answer == solve.minOperations(nums, k));

    nums = {3, 1, 5, 4, 2}, k = 5;
    answer = 5;
    assert(answer == solve.minOperations(nums, k));

    nums = {3, 2, 5, 3, 1}, k = 3;
    answer = 4;
    assert(answer == solve.minOperations(nums, k));

    return 0;
}


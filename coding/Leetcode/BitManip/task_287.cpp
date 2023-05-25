// https://leetcode.com/problems/find-the-duplicate-number/
// Created by ruslan515 on 25.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size() - 1;
        int answer = n * (n + 1) / 2;
        for (auto num: nums) {
            answer -= num;
        }
        return abs(answer);
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 3, 4, 2, 2};
    answer = 2;
    assert(solve.findDuplicate(nums) == answer);

    nums = {3, 1, 3, 4, 2};
    answer = 3;
    assert(solve.findDuplicate(nums) == answer);

    return 0;
}
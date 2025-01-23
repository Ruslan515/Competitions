// https://leetcode.com/contest/weekly-contest-382/problems/number-of-changing-keys/
// Created by omega515 on 28.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums) {
        int answer = 0;

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {5, 4, 1, 2, 2};
    answer = 3;
    assert(answer == solve.maximumLength(nums));

    nums = {1, 3, 2, 4};
    answer = 1;
    assert(answer == solve.maximumLength(nums));

    return 0;
}


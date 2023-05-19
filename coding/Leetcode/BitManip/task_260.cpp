// https://leetcode.com/problems/single-number-iii/solutions/
// Created by ruslan515 on 19.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        long long bitmask = 0;
        for (int num: nums) {
            bitmask ^= num;
        }
        long long diff = bitmask & (-bitmask);
        int x = 0;
        for (int num: nums) {
            if ((num & diff) != 0) {
                x ^= num;
            }
        }

        return {x, (int)bitmask^x};
    }
};

int main() {
    vector<int> nums, answer;
    Solution solve;

    nums = {1, 2, 1, 3, 2, 5};
    answer = {3, 5};
    assert(solve.singleNumber(nums) == answer);

    nums = {-1, 0};
    answer = {-1, 0};
    assert(solve.singleNumber(nums) == answer);

    nums = {1, 0};
    answer = {0, 1};
    assert(solve.singleNumber(nums) == answer);

    return 0;
}
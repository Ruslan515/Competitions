// https://leetcode.com/problems/largest-unique-number/description/
// Created by ruslan515 on 13.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int> &nums) {
        map<int, int> counts;
        for (auto num: nums) {
            ++counts[num];
        }
        int answer = -1;
        for (pair<int, int> cnt: counts) {
            int key = cnt.first;
            int value = cnt.second;
            if (value == 1 && key > answer) {
                answer = key;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {5, 7, 3, 9, 4, 9, 8, 3, 1};
    answer = 8;
    assert(answer == solve.largestUniqueNumber(nums));

    nums = {9, 9, 8, 8};
    answer = -1;
    assert(answer == solve.largestUniqueNumber(nums));

    return 0;
}

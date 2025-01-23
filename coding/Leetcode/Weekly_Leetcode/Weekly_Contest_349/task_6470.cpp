// https://leetcode.com/contest/weekly-contest-349/problems/neither-minimum-nor-maximum/
// Created by Ruslan Khalikov on 11.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int> &nums) {
        int answer = -1;
        int n = nums.size();
        if (n < 3) {
            return answer;
        }

        int idxMin, idxMax;
        int minNum = 101, maxNum = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minNum) {
                minNum = nums[i];
                idxMin = i;
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                idxMax = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if (i != idxMin && i != idxMax) {
                answer = nums[i];
                break;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {3, 2, 1, 4};
    answer = 3;
    assert(answer == solve.findNonMinOrMax(nums));

    nums = {1, 2};
    answer = -1;
    assert(answer == solve.findNonMinOrMax(nums));

    nums = {2, 1, 3};
    answer = 2;
    assert(answer == solve.findNonMinOrMax(nums));

    return 0;
}

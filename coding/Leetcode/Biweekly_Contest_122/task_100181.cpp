// https://leetcode.com/contest/biweekly-contest-122/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
// Created by ruslan515 on 20.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &nums) {
        int answer = INT_MAX;
        int n = nums.size();
        int tmp, val1, val2, val3;

        val1 = nums[0];
        for (int i = 1; i < n; ++i) {
            val2 = nums[i];
            for (int j = i + 1; j < n; ++j) {
                val3 = nums[j];
                tmp = val1 + val2 + val3;
                if (tmp < answer) {
                    answer = tmp;
                }
            }
        }

//        for (int i = 0; i < n; ++i) {
//            val1 = nums[i];
//            for (int j = i + 1; j < n; ++j) {
//                val2 = nums[j];
//                for (int k = j + 1; k < n; ++k) {
//                    val3 = nums[k];
//                    tmp = val1 + val2 + val3;
//                    if (tmp < answer) {
//                        answer = tmp;
//                    }
//                }
//            }
//        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {10, 3, 1, 1};
    answer = 12;
    assert(answer == solve.minimumCost(nums));

    nums = {1, 2, 3, 12};
    answer = 6;
    assert(answer == solve.minimumCost(nums));

    nums = {5, 4, 3};
    answer = 12;
    assert(answer == solve.minimumCost(nums));

    return 0;
}


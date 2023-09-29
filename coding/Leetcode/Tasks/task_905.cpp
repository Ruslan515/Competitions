// https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2023-09-28
// Created by ruslan515 on 28.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int n = nums.size();
        vector<int> answer(n);
        int current;
        int idx_1 = 0, idx_0 = 0;
        for (int i = 0; i < n; ++i) {
            current = nums[i];
            if (current % 2 == 0) {
                answer[idx_0] = current;
                idx_0++;
            } else {
                answer[n - 1 - idx_1] = current;
                idx_1++;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;

    Solution solve;

    nums = {3, 1, 2, 4};
    answer = {2, 4, 3, 1};
    assert(answer == solve.sortArrayByParity(nums));

    nums = {0};
    answer = {0};
    assert(answer == solve.sortArrayByParity(nums));

    return 0;
}
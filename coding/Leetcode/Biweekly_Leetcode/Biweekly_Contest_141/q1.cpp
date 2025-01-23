// https://leetcode.com/contest/biweekly-contest-141/problems/construct-the-minimum-bitwise-array-i/
// Created by omega515 on 12.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        std::vector<int> ans(nums.size(), -1);

        for (size_t i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            // Check if the number is even
            if (num % 2 == 0) {
                ans[i] = -1;
                continue;
            }

            // Start from the potential minimal candidate
            int candidate = (num - 1) / 2;
            for(; candidate < num; ++candidate) {
                if ((candidate | (candidate + 1)) == num) {
                    ans[i] = candidate;
                    break;
                }

            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {2, 3, 5, 7};
    answer = {-1, 1, 4, 3};
    assert(answer == solve.minBitwiseArray(nums));

    nums = {11, 13, 31};
    answer = {9, 12, 15};
    assert(answer == solve.minBitwiseArray(nums));

    return 0;
}

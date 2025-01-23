// https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/
// Created by omega515 on 17.11.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                int leftSum = 0, rightSum = 0;
                for (int j = 0; j < i; ++j) {
                    leftSum += nums[j];
                }
                for (int j = i + 1; j < n; ++j) {
                    rightSum += nums[j];
                }
                if (leftSum == rightSum) {
                    answer += 2;
                } else if (abs(leftSum - rightSum) == 1) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {16,13,10,0,0,0,10,6,7,8,7};
    answer = 3;
    assert(answer == solve.countValidSelections(nums));

    nums = {1, 0, 2, 0, 3};
    answer = 2;
    assert(answer == solve.countValidSelections(nums));

    nums = {2, 3, 4, 0, 4, 1, 0};
    answer = 0;
    assert(answer == solve.countValidSelections(nums));

    return 0;
}

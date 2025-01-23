// https://leetcode.com/problems/ant-on-the-boundary/description/?envType=problem-list-v2&envId=prefix-sum
// Created by omega515 on 07.10.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int sums = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sums += nums[i];
            if (sums == 0) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 3, -5};
    answer = 1;
    assert(answer == solve.returnToBoundaryCount(nums));

    nums = {3, 2, -3, -4};
    answer = 0;
    assert(answer == solve.returnToBoundaryCount(nums));

    return 0;
}
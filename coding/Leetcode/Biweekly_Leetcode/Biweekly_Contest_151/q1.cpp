// https://leetcode.com/contest/biweekly-contest-151/problems/transform-array-by-parity/description/
// Created by omega515 on 01.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> answer(n, 1);
        int j = 0;
        int val;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                answer[j] = 0;
                ++j;
            }
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {4, 3, 2, 1};
    answer = {0, 0, 1, 1};
    assert(answer == solve.transformArray(nums));

    nums = {1, 5, 1, 4, 2};
    answer = {0, 0, 1, 1, 1};
    assert(answer == solve.transformArray(nums));

    return 0;
}

// https://leetcode.com/contest/biweekly-contest-133/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Created by omega515 on 22.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int val, d;
        for (int i = 0; i < n; ++i) {
            val = nums[i];
            d = val % 3;
            if (d != 0) {
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

    nums = {1, 2, 3, 4};
    answer = 3;
    assert(answer == solve.minimumOperations(nums));

    nums = {3, 6, 9};
    answer = 0;
    assert(answer == solve.minimumOperations(nums));

    return 0;
}

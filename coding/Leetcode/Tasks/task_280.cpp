// https://leetcode.com/problems/wiggle-sort/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> answer(n, 0);
        sort(nums.begin(), nums.end());

        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                answer[i] = nums[left];
                ++left;
            } else {
                answer[i] = nums[right];
                --right;
            }
        }
        nums = answer;

        return;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {6, 6, 5, 6, 3, 8};
    answer = {6, 6, 5, 6, 3, 8};
    solve.wiggleSort(nums);
    assert(answer == nums);

    nums = {3, 5, 2, 1, 6, 4};
    answer = {1, 6, 2, 5, 3, 4};
    solve.wiggleSort(nums);
    assert(answer == nums);

    return 0;
}

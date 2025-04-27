// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/
// Created by omega515 on 19.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                answer += right - left;
                ++left;
            } else {
                --right;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int target;
    int answer;
    Solution solve;

    nums = {-6, 2, 5, -2, -7, -1, 3}, target = -2;
    answer = 10;
    assert(answer == solve.countPairs(nums, target));

    nums = {-1, 1, 2, 3, 1}, target = 2;
    answer = 3;
    assert(answer == solve.countPairs(nums, target));

    return 0;
}

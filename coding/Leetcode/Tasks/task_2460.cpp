// https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=daily-question&envId=2025-03-01
// Created by omega515 on 01.03.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> answer(n, 0);
        int curr, next;
        int j = 0;
        for (int i = 0; i < n - 1; ++i) {
            curr = nums[i];
            next = nums[i + 1];
            if (curr == next) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                answer[j] = nums[i];
                ++j;
            }
        }
        if (nums[n - 1] != 0) {
            answer[j] = nums[n - 1];
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {1, 2, 2, 1, 1, 0};
    answer = {1, 4, 2, 0, 0, 0};
    assert(answer == solve.applyOperations(nums));

    nums = {0, 1};
    answer = {1, 0};
    assert(answer == solve.applyOperations(nums));

    return 0;
}


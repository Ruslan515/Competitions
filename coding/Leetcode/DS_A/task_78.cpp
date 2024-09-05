// https://leetcode.com/problems/subsets/description/
// Created by omega515 on 02.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &answer, vector<int> &current, vector<int> &nums, int idx) {
        int n = nums.size();

        for (int i = idx; i < n; ++i) {
            current.push_back(nums[i]);
            answer.push_back(current);
            backtrack(answer, current, nums, i + 1);
            current.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> answer;
        answer.push_back({});
        vector<int> current;
        backtrack(answer, current, nums, 0);

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<vector<int>> answer;
    Solution solve;

    nums = {1, 2, 3};
    answer = {
            {},
            {1},
            {2},
            {1, 2},
            {3},
            {1, 3},
            {2, 3},
            {1, 2, 3}
    };
    assert(answer == solve.subsets(nums));

    nums = {0};
    answer = {{},
              {0}};
    assert(answer == solve.subsets(nums));

    return 0;
}

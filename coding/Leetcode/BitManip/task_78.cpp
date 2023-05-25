// https://leetcode.com/problems/subsets/
// Created by ruslan515 on 25.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> answer;
        answer.push_back({});
        int n = nums.size();
        for (int i = 1; i < 1 << n; ++i) {
            vector<int> subset;
            int mask = 1;
            int j = i;
            int idx = 0;
            while (j != 0) {
                int d = j & mask;
                if (d) {
                    subset.push_back(nums[idx]);
                }
                ++idx;
                j >>= 1;
            }
            answer.push_back(subset);
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<vector<int>> answer;
    Solution solve;

    nums = {1, 2, 3};
    answer = {{},
              {1},
              {2},
              {1, 2},
              {3},
              {1, 3},
              {2, 3},
              {1, 2, 3}};
    assert(solve.subsets(nums) == answer);

    nums = {0};
    answer = {{},
              {0}};
    assert(solve.subsets(nums) == answer);

    return 0;
}
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Created by ruslan515 on 23.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int> &nums) {
        int answer = 0;
        int n = nums.size();
        for (int i = 1; i < (1 << n); ++i) {
            vector<int> v_indexes;
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                int idx = i & (1 << j);
                if (idx) {
                    v_indexes.push_back(j);
                    temp ^= nums[j];
                }
            }
            answer += temp;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 3};
    answer = 6;
    assert(solve.subsetXORSum(nums) == answer);

    nums = {1, 3};
    answer = 6;
    assert(solve.subsetXORSum(nums) == answer);

    return 0;
}
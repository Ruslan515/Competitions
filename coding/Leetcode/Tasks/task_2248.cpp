// https://leetcode.com/problems/intersection-of-multiple-arrays/
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> mapU;
        for(auto vec: nums) {
            for (auto x: vec) {
                ++mapU[x];
            }
        }

        int key, value;
        for (auto it: mapU) {
            key = it.first;
            value = it.second;
            if (value == n) {
                answer.push_back(key);
            }

        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    vector<vector<int>> nums;
    vector<int> answer;
    Solution solve;

    nums = {{3, 1, 2, 4, 5},
            {1, 2, 3, 4},
            {3, 4, 5, 6}};
    answer = {3, 4};
    assert(answer == solve.intersection(nums));

    nums = {{1, 2, 3},
            {4, 5, 6}};
    answer = {};
    assert(answer == solve.intersection(nums));

    return 0;
}
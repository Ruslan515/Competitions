// https://leetcode.com/contest/biweekly-contest-104/problems/sum-in-a-matrix/
// Created by Ruslan Khalikov on 13.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) {
        int answer = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }
        int m = nums[0].size();
        for (int j = 0; j < m; ++j) {
            int max_i = (-1) * INT_MAX;
            for (int i = 0; i < n; ++i) {
                int temp = nums[i][j];
                max_i = max(max_i, temp);
            }
            answer += max_i;
        }
        return answer;
    }
};

int main() {
    vector<vector<int>> nums;
    int answer;
    Solution solve;

    nums = {{7, 2, 1},
            {6, 4, 2},
            {6, 5, 3},
            {3, 2, 1}};
    answer = 15;
    assert(solve.matrixSum(nums) == answer);

    nums = {{1}};
    answer = 1;
    assert(solve.matrixSum(nums) == answer);

    return 0;
}
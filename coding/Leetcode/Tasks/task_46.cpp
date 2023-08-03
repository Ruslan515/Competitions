// https://leetcode.com/problems/permutations/description/
// Created by Ruslan Khalikov on 02.08.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<int> &nums) {
        int ans = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                ans = i;
                break;
            }
        }

        return ans;
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> answer;
        int n = nums.size();
        if (n == 1) {
            answer = {{nums[0]}};
            return answer;
        }
        sort(nums.begin(), nums.end());
        answer.push_back(nums);
        while (true) {
            int i = check(nums);
            if (i == -1) {
                break;
            }
            int j = n-1;
            for (; j > i; --j) {
                if (nums[i] < nums[j]) {
                    break;
                }
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            reverse(nums.begin() + i + 1, nums.end());
            answer.push_back(nums);
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<vector<int>> answer;
    Solution solve;

    nums = {1, 2, 3};
    answer = {{1, 2, 3},
              {1, 3, 2},
              {2, 1, 3},
              {2, 3, 1},
              {3, 1, 2},
              {3, 2, 1}};
    assert(answer == solve.permute(nums));

    nums = {0, 1};
    answer = {{0, 1},
              {1, 0}};
    assert(answer == solve.permute(nums));

    nums = {1};
    answer = {{1}};
    assert(answer == solve.permute(nums));

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-133/problems/minimum-answer-to-make-binary-array-elements-equal-to-one-i/
// Created by omega515 on 22.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int operations = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Применяем операцию к текущему элементу и двум следующим
                nums[i] = 1;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                operations++;
            }
        }

        // Проверяем последние два элемента
        for (int i = n - 2; i < n; ++i) {
            if (nums[i] == 0) {
                return -1; // Не можем применить операцию к последним трем элементам
            }
        }

        return operations;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 0, 0, 1, 1, 1, 0, 1, 1, 1};
    answer = 3;
    assert(answer == solve.minOperations(nums));

    nums = {0, 0, 0};
    answer = 1;
    assert(answer == solve.minOperations(nums));

    nums = {0, 0, 0};
    answer = 1;
    assert(answer == solve.minOperations(nums));

    nums = {0, 1, 1, 1, 0, 0};
    answer = 3;
    assert(answer == solve.minOperations(nums));

    nums = {0, 1, 1, 1};
    answer = -1;
    assert(answer == solve.minOperations(nums));

    return 0;
}

// https://leetcode.com/contest/biweekly-contest-133/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
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

        int flips = 0;
        int expected = 1; // Начальное ожидаемое значение

        for (int num : nums) {
            if (num != expected) {
                flips++; // Нужен переворот
                expected = 1 - expected; // Изменяем ожидаемое значение
            }
        }

        return flips;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {0, 1, 1, 0, 1};
    answer = 4;
    assert(answer == solve.minOperations(nums));

    nums = {1, 0, 0, 0};
    answer = 1;
    assert(answer == solve.minOperations(nums));

    return 0;
}

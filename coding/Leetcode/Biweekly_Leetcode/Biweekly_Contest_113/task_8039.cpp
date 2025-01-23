// https://leetcode.com/contest/biweekly-contest-113/problems/minimum-right-shifts-to-sort-the-array/
// Created by ruslan515 on 16.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int> &nums) {
        int answer = -1;
        int tempMax;
        int i = 0;
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        while (i < (n - 1) && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == (n - 1)) {
            return 0;
        }
        tempMax = nums[i];
        ++i;
        int count = 1;
        while (i < n - 1 && nums[i] < tempMax && nums[i] < nums[i + 1]) {
            ++i;
            count++;
        }
        if (i == n - 1 && nums[n - 1] < tempMax) {
            answer = count;
            return answer;
        } else
        {
            return answer;
        }

    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {65, 88};
    answer = 0;
    assert(answer == solve.minimumRightShifts(nums));

    nums = {2, 1, 4};
    answer = -1;
    assert(answer == solve.minimumRightShifts(nums));

    nums = {3, 4, 5, 1, 2};
    answer = 2;
    assert(answer == solve.minimumRightShifts(nums));

    nums = {1, 3, 5, 7};
    answer = 0;
    assert(answer == solve.minimumRightShifts(nums));


    return 0;
}


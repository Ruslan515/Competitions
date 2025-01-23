// https://leetcode.com/contest/biweekly-contest-140/problems/minimum-element-after-replacement-with-digit-sum/
// Created by omega515 on 28.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSumDigits(int num) {
        int answer = 0;
        int d;
        while (num != 0) {
            d = num % 10;
            answer += d;
            num /= 10;
        }

        return answer;
    }

    int minElement(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 1e5;
        for (int num: nums) {
            answer = min(answer, getSumDigits(num));
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {10, 12, 13, 14};
    answer = 1;
    assert(answer == solve.minElement(nums));

    nums = {1, 2, 3, 4};
    answer = 1;
    assert(answer == solve.minElement(nums));

    nums = {999, 19, 199};
    answer = 10;
    assert(answer == solve.minElement(nums));

    return 0;
}

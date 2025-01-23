// https://leetcode.com/contest/weekly-contest-391/problems/harshad-number/
// Created by omega515 on 31.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int> &nums) {
        long long answer= 0;
        int left, right;
        left = 0;
        right = 0;
        int n = nums.size();
        answer = n;
        if (n  == 1) {
            return answer;
        }

        while (true) {
            while (right < n - 1) {
                if (nums[right] != nums[right + 1]) {
                    ++right;
                    ++answer;
                } else {
                    break;
                }
            }
            if (right - left > 1) {
                answer += right - left;
            }

            left = right;
            ++right;
            if (left >= n) {
                break;
            }

        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {0, 1, 1, 1};
    answer = 5;
    assert(answer == solve.countAlternatingSubarrays(nums));

    nums = {1, 0, 1, 0};
    answer = 10;
    assert(answer == solve.countAlternatingSubarrays(nums));

    return 0;
}


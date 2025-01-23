// https://leetcode.com/contest/weekly-contest-421/problems/find-the-maximum-factor-score-of-array/description/
// Created by omega515 on 27.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gcdAll(vector<int> &nums, int idx) {
        long long g;
        if (idx == -1) {
            g = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                g = (long long) gcd(g, nums[i]);
            }
        } else {
            int start = 0;
            if (idx == 0) {
                start = 1;
            }
            g = (long long) nums[start];
            for (int i = start + 1; i < nums.size(); ++i) {
                if (i != idx) {
                    g = gcd(g, nums[i]);
                }
            }

        }

        return g;
    }

    long long lcmAll(vector<int> &nums, int idx) {
        long long l;
        if (idx == -1) {
            l = (long long) nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                l = lcm(l, nums[i]);
            }
        } else {
            int start = 0;
            if (idx == 0) {
                start = 1;
            }
            l = (long long) nums[start];
            for (int i = start + 1; i < nums.size(); ++i) {
                if (i != idx) {
                    l = lcm(l, nums[i]);
                }
            }
        }

        return l;
    }

    long long maxScore(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long answer = 0;
        int n = nums.size();
        if (n == 1) {
            return (long long) nums[0] * nums[0];
        }
        long long tmpG = gcdAll(nums, -1);
        long long tmpL = lcmAll(nums, -1);
        long long maxDot = tmpG * tmpL;

        long long tmpDot;
        for (int i = 0; i < nums.size(); ++i) {
            tmpG = gcdAll(nums, i);
            tmpL = lcmAll(nums, i);
            tmpDot = tmpG * tmpL;
            if (tmpDot > maxDot) {
                maxDot = tmpDot;
            }
        }
        answer = maxDot;

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 4, 8, 16};
    answer = 64;
    assert(answer == solve.maxScore(nums));

    nums = {1, 2, 3, 4, 5};

    answer = 60;
    assert(answer == solve.maxScore(nums));

    nums = {3};
    answer = 9;
    assert(answer == solve.maxScore(nums));

    return 0;
}

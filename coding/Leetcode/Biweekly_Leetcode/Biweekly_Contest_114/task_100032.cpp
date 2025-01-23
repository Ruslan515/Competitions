// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-number-of-operations-to-make-array-empty/
// Created by ruslan515 on 30.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int answer = -1;
        int n = nums.size();
        map<int, int> mp;
        for (auto n: nums) {
            mp[n]++;
        }
        int count = 0;
        map<int, int>::iterator it = mp.begin();
        int key, value, d;
        for (; it != mp.end(); ++it) {
            key = it->first;
            value = it->second;
            if (value >= 5) {
                if (value % 3 == 0) {
                    d = value / 3;
                    count += d;
                } else {
                    int i = value / 3;
                    for (; i >= 0; --i) {
                        int t = value - i * 3;
                        if (t % 2 == 0) {
                            d = t / 2;
                            d += i;
                            count += d;
                            break;
                        }
                    }

                }
            } else {
                if (value % 3 == 0) {
                    d = value / 3;
                    count += d;
                } else if (value % 2 == 0) {
                    d = value / 2;
                    count += d;
                } else {
                    return answer;
                }
            }
        }
        answer = count;

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
    answer = 7;
    assert(answer == solve.minOperations(nums));

    nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    answer = 4;
    assert(answer == solve.minOperations(nums));

    nums = {2, 1, 2, 2, 3, 3};
    answer = -1;
    assert(answer == solve.minOperations(nums));

    return 0;
}


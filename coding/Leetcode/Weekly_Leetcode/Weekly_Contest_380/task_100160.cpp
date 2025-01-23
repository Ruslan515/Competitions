// https://leetcode.com/contest/weekly-contest-380/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
// Created by omega515 on 14.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        int answer = 0;
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for (int num: nums) {
            ++mp[num];
            maxFreq = max(maxFreq, mp[num]);
        }
        unordered_map<int, int> :: iterator  it = mp.begin();
        for(; it != mp.end(); ++it) {
            int key = it->first;
            int val = it->second;
            if (val == maxFreq) {
                answer += maxFreq;
            }
        }



        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 2, 2, 3, 1, 4};
    answer = 4;
    assert(answer == solve.maxFrequencyElements(nums));

    nums = {1, 2, 3, 4, 5};
    answer = 5;
    assert(answer == solve.maxFrequencyElements(nums));

    return 0;
}


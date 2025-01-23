// https://leetcode.com/contest/biweekly-contest-131/problems/find-the-xor-of-numbers-which-appear-twice/
// Created by omega515 on 25.05.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int> &nums) {
        int answer = 0;
        unordered_map<int, int> mp;
        for (int num: nums) {
            ++mp[num];
        }
        unordered_map<int, int>::iterator it = mp.begin();
        for (; it != mp.end(); ++it) {
            int value = it->second;
            if (value == 2) {
                int key = it->first;
                answer ^= key;
            }
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 2, 1, 3};
    answer = 1;
    assert(answer == solve.duplicateNumbersXOR(nums));

    nums = {1, 2, 3};
    answer = 0;
    assert(answer == solve.duplicateNumbersXOR(nums));

    nums = {1, 2, 2, 1};
    answer = 3;
    assert(answer == solve.duplicateNumbersXOR(nums));

    return 0;
}


// https://leetcode.com/problems/number-of-good-pairs/
// Created by ruslan515 on 20.06.23.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getComb(int n) {
        int answer = n * (n - 1) / 2;
        return answer;
    }

    int numIdenticalPairs(vector<int> &nums) {
        unordered_map<int, int> mp;
        for (auto num: nums) {
            ++mp[num];
        }

        int answer = 0;
        int value;
        for (pair<int, int> el: mp) {
            value = el.second;
            if (value > 1) {
                int temp = getComb(value);
                answer += temp;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 2, 3, 1, 1, 3};
    answer = 4;
    assert(answer == solve.numIdenticalPairs(nums));

    nums = {1, 1, 1, 1};
    answer = 6;
    assert(answer == solve.numIdenticalPairs(nums));

    nums = {1, 2, 3};
    answer = 0;
    assert(answer == solve.numIdenticalPairs(nums));

    return 0;
}

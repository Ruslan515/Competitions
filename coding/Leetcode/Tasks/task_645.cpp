// https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
// Created by omega515 on 22.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> answer;
        int n = nums.size();
        unordered_map<int, int> mp;
        set<int> keys, setNums;
        for (int i = 0; i < n; ++i) {
            setNums.insert(i + 1);
        }
        int tmp = -1;
        for (int num: nums) {
            ++mp[num];
            if (mp[num] == 2) {
                tmp = num;
            }
            keys.insert(num);
        }
        vector<int> diff;
        set_difference(
                setNums.begin(), setNums.end(),
                keys.begin(), keys.end(),
                inserter(diff, diff.end())
        );
        answer.push_back(tmp);
        answer.push_back(diff[0]);

        return answer;
    }
};


int main() {
    vector<int> nums;
    vector<int> answer;

    Solution solve;

    nums = {3, 3, 1};
    answer = {3, 2};
    assert(answer == solve.findErrorNums(nums));

    nums = {2, 2};
    answer = {2, 1};
    assert(answer == solve.findErrorNums(nums));

    nums = {1, 2, 2, 4};
    answer = {2, 3};
    assert(answer == solve.findErrorNums(nums));

    nums = {1, 1};
    answer = {1, 2};
    assert(answer == solve.findErrorNums(nums));
    return 0;
}
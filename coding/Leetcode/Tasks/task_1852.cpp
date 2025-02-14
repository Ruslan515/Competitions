// https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/?envType=weekly-question&envId=2025-02-01
// Created by omega515 on 07.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        unordered_map<int, int> freqMap;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            ++freqMap[nums[i]];
        }
        answer.push_back(freqMap.size());
        for (int i = k; i < n; ++i) {
            ++freqMap[nums[i]];
            --freqMap[nums[i - k]];
            if (freqMap[nums[i - k]] == 0) {
                freqMap.erase(nums[i - k]);
            }
            answer.push_back(freqMap.size());
        }

        return answer;
    }
};


int main() {
    vector<int> nums;
    int k;
    vector<int> answer;
    Solution solve;

    nums = {1, 2, 3, 2, 2, 1, 3}, k = 3;
    answer = {3, 2, 2, 2, 3};
    assert(answer == solve.distinctNumbers(nums, k));

    nums = {1, 1, 1, 1, 2, 3, 4}, k = 4;
    answer = {1, 2, 3, 4};
    assert(answer == solve.distinctNumbers(nums, k));

    return 0;
}


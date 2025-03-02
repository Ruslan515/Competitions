// https://leetcode.com/contest/weekly-contest-439/problems/find-the-largest-almost-missing-integer/description/
// Created by omega515 on 02.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int start = 0; start < n - k + 1; ++start) {
            unordered_set<int> setNums;
            for (int i = 0; i < k; ++i) {
                setNums.insert(nums[start + i]);
//                if (freq.find(nums[start + i]) == freq.end()) {
//                    ++freq[nums[start + i]];
//                }
            }
            for (int num: setNums) {
                ++freq[num];
            }
        }
        for (auto item: freq) {
            int val = item.second;
            if (val == 1) {
                answer = max(answer, item.first);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {3, 9, 2, 1, 7}, k = 3;
    answer = 7;
    assert(answer == solve.largestInteger(nums, k));

    nums = {3, 9, 7, 2, 1, 7}, k = 4;
    answer = 3;
    assert(answer == solve.largestInteger(nums, k));

    nums = {0, 0}, k = 1;
    answer = -1;
    assert(answer == solve.largestInteger(nums, k));

    nums = {0, 0}, k = 2;
    answer = 0;
    assert(answer == solve.largestInteger(nums, k));

    return 0;
}

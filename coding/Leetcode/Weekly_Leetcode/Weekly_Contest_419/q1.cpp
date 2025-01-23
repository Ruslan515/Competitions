// https://leetcode.com/contest/weekly-contest-417/problems/find-the-k-th-character-in-string-game-i/description/
// Created by omega515 on 29.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int> &nums, int k, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> answer(n - k + 1);
        for (int start = 0; start < n - k + 1; ++start) {
            int sums = 0;
            unordered_map<int, int> mp;
            for (int i = start; i < start + k; ++i) {
                ++mp[nums[i]];
            }
            if (mp.size() < x) {
                for (auto kv: mp) {
                    int key = kv.first;
                    int value = kv.second;
                    sums += key * value;
                }
            } else {
                unordered_map<int, vector<int> > val_map;
                set<int, greater<int>> cnts;
                for (auto kv: mp) {
                    int key = kv.first;
                    int value = kv.second;
                    cnts.insert(value);
                    val_map[value].push_back(key);
                }
                int tmp_x = 0;
                set<int>::iterator it = cnts.begin();
                for (; tmp_x < x && it != cnts.end(); ++it) {
                    int key = it.operator*();
                    vector<int> vals = val_map[key];
                    sort(vals.begin(), vals.end(), greater<>());
                    for (int j = 0; tmp_x < x && j < vals.size(); ++j) {
                        sums += key * vals[j];
                        ++tmp_x;
                    }
                }

            }
            answer[start] = sums;

        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k, x;
    vector<int> answer;
    Solution solve;

    nums = {9, 5, 8}, k = 2, x = 1;
    answer = {9, 8};
    assert(answer == solve.findXSum(nums, k, x));

    nums = {1, 1, 2, 2, 3, 4, 2, 3}, k = 6, x = 2;
    answer = {6, 10, 12};
    assert(answer == solve.findXSum(nums, k, x));

    nums = {3, 8, 7, 8, 7, 5}, k = 2, x = 2;
    answer = {11, 15, 15, 15, 12};
    assert(answer == solve.findXSum(nums, k, x));


    return 0;
}

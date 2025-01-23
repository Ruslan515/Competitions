// https://leetcode.com/contest/biweekly-contest-135/problems/minimum-array-changes-to-make-differences-equal/description/
// Created by omega515 on 20.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        unordered_map<int, vector<pair<int, int>>> mp;
        int diff;
        int maxCount = 0, keyDiff;
        for (int i = 0; i < n / 2; ++i) {
            diff = abs(nums[i] - nums[n - 1 - i]);
            mp[diff].push_back({i, n - 1 - i});
            int tmp = mp[diff].size();
            if (tmp > maxCount) {
                maxCount = tmp;
                keyDiff = diff;
            }
        }
        if (mp.size() == 1) {
            return answer;
        }
        mp.erase(keyDiff);
        vector<pair<int, int>> v;
        int i, j;
        for (auto const &item: mp) {
            diff = item.first;
            v = item.second;
            for (auto item: v) {
                i = item.first;
                j = item.second;
                int x = nums[i];
                int y = nums[j];
                int maxX = max(x, y), minX = min(x, y);
                int d;
                if (diff < keyDiff) {
                    d = keyDiff - diff;
                    if (minX - d >= 0 && maxX + d <= k) {
                        answer += 2;

                    } else {
                        ++answer;
                    }
                } else {
                    d = diff - keyDiff;
                    if (minX - d >= 0 && maxX + d <= k) {
                        answer += 2;
                    } else {

                        ++answer;
                    }
                }

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

    nums = {1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0}, k = 1;
    answer = 4;
    assert(answer == solve.minChanges(nums, k));

    nums = {0, 1, 2, 0, 7, 6, 5, 4}, k = 6;
    answer = 1;
    assert(answer == solve.minChanges(nums, k));

    nums = {0, 1, 2, 3, 3, 6, 5, 4}, k = 6;
    answer = 2;
    assert(answer == solve.minChanges(nums, k));

    nums = {1, 0, 1, 2, 4, 3}, k = 4;
    answer = 2;
    assert(answer == solve.minChanges(nums, k));

    return 0;
}

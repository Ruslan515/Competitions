// https://leetcode.com/contest/biweekly-contest-145/problems/minimum-operations-to-make-array-values-equal-to-k/description/
// Created by omega515 on 07.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;

        unordered_map<int, int> mp;
        for (int num: nums) {
            if (num < k) {
                return answer;
            }
            ++mp[num];
        }

        int n = mp.size();
        answer = n;
        if (mp.find(k) != mp.end()) {
            answer = n - 1;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {5, 2, 5, 4, 5}, k = 2;
    answer = 2;
    assert(answer == solve.minOperations(nums, k));

    nums = {2, 1, 2}, k = 2;
    answer = -1;
    assert(answer == solve.minOperations(nums, k));

    nums = {9, 7, 5, 3}, k = 1;
    answer = 4;
    assert(answer == solve.minOperations(nums, k));

    return 0;
}

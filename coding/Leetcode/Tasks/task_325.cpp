// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/?envType=weekly-question&envId=2025-04-15
// Created by omega515 on 19.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(0);
        mp[prefixSum[0]].push_back(0);

        for (int i = 1; i < n; ++i) {
            prefixSum[i] += prefixSum[i - 1] + nums[i];
            mp[prefixSum[i]].push_back(i);
        }

        int current, diff, lastIdx;
        for (int i = 0; i < n; ++i) {
            current = prefixSum[i];
            diff = current - k;
            if (mp.find(diff) != mp.end()) {
                lastIdx = mp[diff][0];
                if (lastIdx == 0) {
                    --lastIdx;
                }
                answer = max(answer, i - lastIdx);
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

    nums = {-2, -1, 2, 1}, k = 1;
    answer = 2;
    assert(answer == solve.maxSubArrayLen(nums, k));

    nums = {1, -1, 5, -2, 3}, k = 3;
    answer = 4;
    assert(answer == solve.maxSubArrayLen(nums, k));

    return 0;
}

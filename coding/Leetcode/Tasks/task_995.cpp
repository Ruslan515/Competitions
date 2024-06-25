// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
// Created by omega515 on 24.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        int answer = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (nums[i] == 0) {
                for (int j = i; j < i + k; ++j) {
                    nums[j] = 1 - nums[j];
                }
                answer++;
            }
        }
        for (int i = max(0, n - 1 - k); i < n; ++i) {
            if (nums[i] == 0) {
                answer = -1;
                break;
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

    nums = {1, 1}, k = 2;
    answer = 0;
    assert(answer == solve.minKBitFlips(nums, k));

    nums = {0, 1, 0}, k = 1;
    answer = 2;
    assert(answer == solve.minKBitFlips(nums, k));

    nums = {1, 1, 0}, k = 2;
    answer = -1;
    assert(answer == solve.minKBitFlips(nums, k));

    nums = {0, 0, 0, 1, 0, 1, 1, 0}, k = 3;
    answer = 3;
    assert(answer == solve.minKBitFlips(nums, k));

    return 0;
}

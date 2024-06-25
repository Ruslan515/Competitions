// https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
// Created by omega515 on 22.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int answer = 0;
        int n = nums.size();

        int sum = 0;
        vector<int> prefix;
        prefix.push_back(0);
        for (int i = 0; i < n; ++i) {
            sum += nums[i] % 2;
            prefix.push_back(sum);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int x = prefix[j];
                int y = prefix[i];
                sum = x - y;
                if (sum == k) {
                    ++answer;
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

    nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2}, k = 2;
    answer = 16;
    assert(answer == solve.numberOfSubarrays(nums, k));

    nums = {2, 4, 6}, k = 1;
    answer = 0;
    assert(answer == solve.numberOfSubarrays(nums, k));

    nums = {1, 1, 2, 1, 1}, k = 3;
    answer = 2;
    assert(answer == solve.numberOfSubarrays(nums, k));

    return 0;
}


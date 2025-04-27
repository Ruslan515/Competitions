// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/?envType=daily-question&envId=2025-04-17
// Created by omega515 on 17.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int first, second;
        for (int i = 0; i < n; ++i) {
            first = nums[i];
            for (int j = i + 1; j < n; ++j) {
                second = nums[j];
                if (first == second && (i * j) % k == 0) {
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

    nums = {3, 1, 2, 2, 2, 1, 3}, k = 2;
    answer = 4;
    assert(answer == solve.countPairs(nums, k));

    nums = {1, 2, 3, 4}, k = 1;
    answer = 0;
    assert(answer == solve.countPairs(nums, k));

    return 0;
}

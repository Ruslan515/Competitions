// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08
// Created by omega515 on 08.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(unordered_map<int, int> &freq) {
        bool answer = true;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second > 1) {
                answer = false;
                break;
            }
        }
        return answer;
    }

    int minimumOperations(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<int, int> freq;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            ++freq[num];
        }

        int i = 0;
        int num;
        while (!check(freq)) {
            for (int j = i; j < i + 3 && j < n; ++j) {
                num = nums[j];
                --freq[num];
                if (freq[num] == 0) {
                    freq.erase(num);
                }
            }
            i += 3;
            ++answer;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
    answer = 2;
    assert(answer == solve.minimumOperations(nums));

    nums = {5, 5};
    answer = 1;
    assert(answer == solve.minimumOperations(nums));

    nums = {4, 5, 6, 4, 4};
    answer = 2;
    assert(answer == solve.minimumOperations(nums));

    nums = {6, 7, 8, 9};
    answer = 0;
    assert(answer == solve.minimumOperations(nums));

    return 0;
}

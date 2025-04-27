// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2025-04-06
// Created by omega515 on 06.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        sort(nums.begin(), nums.end());

        vector<int> tmp;
        int n = nums.size();
        int d;
        for (int start = 0; start < n; ++start) {
            d = nums[start];
            for (int i = start + 1; i < n; ++i) {
                
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {1, 2, 3};
    answer = {1, 2};
    assert(answer == solve.largestDivisibleSubset(nums));

    nums = {1, 2, 4, 8};
    answer = {1, 2, 4, 8};
    assert(answer == solve.largestDivisibleSubset(nums));


    return 0;
}

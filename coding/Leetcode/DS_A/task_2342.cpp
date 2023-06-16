// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSums(int x) {
        int d;
        int sums = 0;
        while (x != 0) {
            d = x % 10;
            sums += d;
            x /= 10;
        }
        return sums;
    }
    int maximumSum(vector<int> &nums) {
        unordered_map<int, vector<int>> mp;
        int sums;
        for (auto num: nums) {
            sums = getSums(num);
            mp[sums].push_back(num);
        }

        int maxSums = -1;
        int tempSum;
        for (pair<int, vector<int>> el: mp) {
            if (el.second.size() >= 2) {
                sort(el.second.begin(), el.second.end(), greater<int>());
                tempSum = el.second[0] + el.second[1];
                maxSums = max(maxSums, tempSum);
            }
        }

        return maxSums;
    }
};

int main() {
    int answer;
    vector<int> nums;
    Solution solve;

    nums = {18, 43, 36, 13, 7};
    answer = 54;
    assert(solve.maximumSum(nums) == answer);

    nums = {10, 12, 19, 14};
    answer = -1;
    assert(solve.maximumSum(nums) == answer);

    return 0;
}
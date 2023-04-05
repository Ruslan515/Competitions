// https://leetcode.com/problems/target-sum/description/
// Created by ruslan515 on 05.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string constrFirst(int numZeros, int numOnes) {
        std::string res;
        res.reserve(numZeros + numZeros);
        res.append(numZeros, '0');
        res.append(numOnes, '1');
        return res;
    }

    int calcNums(string symbols, vector<int> &nums) {
        int n = symbols.size();
        int sums = 0;
        for (int i = 0; i < n; ++i) {
            if (symbols[i] == '0') {
                sums += nums[i];
            } else {
                sums -= nums[i];
            }
        }
        return sums;
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n + 1; ++i) {
            string symbols = constrFirst(n - i, i);
            int sums = calcNums(symbols, nums);
            if (sums == target) {
                ++ans;
            }
            while (next_permutation(begin(symbols), end(symbols))) {
                sums = calcNums(symbols, nums);
                if (sums == target) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

int main() {
    int target;
    vector<int> nums;

    Solution solve;
    nums = {1, 1, 1, 1, 1};
    target = 3;
    cout << solve.findTargetSumWays(nums, target);
    assert(solve.findTargetSumWays(nums, target) == 5);

    nums = {1};
    target = 1;
    assert(solve.findTargetSumWays(nums, target) == 1);

    return 0;
}

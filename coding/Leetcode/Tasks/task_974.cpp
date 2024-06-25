// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09
// Created by omega515 on 09.06.24.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getComb(int x) {
        int k = 2;
//        int answer = x * (x - 1) / k;
        int answer = pow(2, x - 1) - 1;
        return answer;
    }

    int subarraysDivByK(vector<int> &nums, int k) {
        int answer = 0;
        int n = nums.size();
        if (n == 1) {
            if (nums[0] % k == 0) {
                return 1;
            } else {
                return answer;
            }
        }
        vector<int> prefixSum, prefixMod;
        int sums = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                answer++;
            }
            sums += nums[i];
            prefixSum.push_back(sums);
            int prefixM = sums % k;
            prefixMod.push_back(prefixM);
            mp[prefixM]++;
        }

        unordered_map<int, int>::iterator it = mp.begin();
        int key, freq;
        for (; it != mp.end(); ++it) {
            freq = it->second;
            if (freq > 1) {
                answer += this->getComb(freq);
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

    nums = {10, 7, 10}, k = 10;
    answer = 2;
    assert(answer == solve.subarraysDivByK(nums, k));

    nums = {4, 5, 0, -2, -3, 1}, k = 5;
    answer = 7;
    assert(answer == solve.subarraysDivByK(nums, k));


    nums = {0, -5}, k = 10;
    answer = 1;
    assert(answer == solve.subarraysDivByK(nums, k));

    nums = {-5}, k = 5;
    answer = 1;
    assert(answer == solve.subarraysDivByK(nums, k));

    nums = {5}, k = 9;
    answer = 0;
    assert(answer == solve.subarraysDivByK(nums, k));

    return 0;
}

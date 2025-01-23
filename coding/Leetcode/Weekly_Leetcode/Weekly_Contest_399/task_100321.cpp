// https://leetcode.com/contest/weekly-contest-399/problems/find-the-number-of-good-pairs-i/
// Created by omega515 on 26.05.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDivisors(int num) {
        vector<int> divisiors;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                divisiors.push_back(i);
                if (i != num / i) {
                    divisiors.push_back(num / i);
                }
            }
        }
        return divisiors;
    }

    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        long long answer = 0;
        unordered_map<long long, long long> mp;
        int m = nums2.size();
        for (int i = 0; i < m; ++i) {
            long long key = nums2[i] * k;
            ++mp[key];
        }

        for (int num: nums1) {
            vector<int> divisiors = findDivisors(num);
            for (int divisior: divisiors) {
                long long count = mp.count(divisior);
                if (count) {
                    answer += mp[divisior];
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums1, nums2;
    int k;
    long long answer;
    Solution solve;

    nums1 = {1, 3, 4}, nums2 = {1, 3, 4}, k = 1;
    answer = 5;
    assert(answer == solve.numberOfPairs(nums1, nums2, k));

    nums1 = {1, 2, 4, 12}, nums2 = {2, 4}, k = 3;
    answer = 2;
    assert(answer == solve.numberOfPairs(nums1, nums2, k));

    return 0;
}


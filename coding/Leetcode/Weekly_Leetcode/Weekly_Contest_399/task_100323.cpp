// https://leetcode.com/contest/weekly-contest-399/problems/find-the-number-of-good-pairs-i/
// Created by omega515 on 26.05.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int answer = 0;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = nums1[i] % (nums2[j] * k);
                if (x == 0) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums1, nums2;
    int k;
    int answer;
    Solution solve;

    nums1 = {1, 3, 4}, nums2 = {1, 3, 4}, k = 1;
    answer = 5;
    assert(answer == solve.numberOfPairs(nums1, nums2, k));

    nums1 = {1, 2, 4, 12}, nums2 = {2, 4}, k = 3;
    answer = 2;
    assert(answer == solve.numberOfPairs(nums1, nums2, k));

    return 0;
}


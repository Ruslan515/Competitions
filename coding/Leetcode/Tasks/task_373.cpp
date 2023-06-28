// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Created by ruslan515 on 27.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, vector<int>>> temp;
        int n1 = nums1.size(), n2 = nums2.size();
        int len1 = min(k, n1) / 2;
        int len2 = min(k, n2) / 2;
        int num1, num2, sums;
        for (int i = 0; i < len1; ++i) {
            num1 = nums1[i];
            for (int j = 0; j < len2; ++j) {
                num2 = nums2[j];
                sums = num1 + num2;
                temp.push_back({sums, {num1, num2}});
            }
        }
        sort(temp.begin(), temp.end());
        vector<vector<int>> answer;
        int len = temp.size();
        int count = min(k, len);
        for (int i = 0; i < count; ++i) {
            answer.push_back(temp[i].second);
        }


        return answer;
    }
};

int main() {
    vector<int> nums1, nums2;
    vector<vector<int>> answer;
    int k;
    Solution solve;

    nums1 = {1, 2}, nums2 = {3}, k = 3;
    answer = {{1, 3},
              {2, 3}};
    assert(answer == solve.kSmallestPairs(nums1, nums2, k));

    nums1 = {1, 1, 2}, nums2 = {1, 2, 3}, k = 2;
    answer = {{1, 1},
              {1, 1}};
    assert(answer == solve.kSmallestPairs(nums1, nums2, k));

    nums1 = {1, 7, 11}, nums2 = {2, 4, 6}, k = 3;
    answer = {{1, 2},
              {1, 4},
              {1, 6}};
    assert(answer == solve.kSmallestPairs(nums1, nums2, k));

    return 0;
}
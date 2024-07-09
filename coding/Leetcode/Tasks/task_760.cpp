// https://leetcode.com/problems/find-anagram-mappings/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 26.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        unordered_map<int, vector<int>> mp;
        int n = nums2.size();
        int key;
        for (int i = 0; i < n; ++i) {
            key = nums2[i];
            mp[key].push_back(i);
        }
        int val;
        for (int i = 0; i < n; ++i) {
            key = nums1[i];
            val = mp[key].back();
            mp[key].pop_back();
            answer.push_back(val);
        }

        return answer;
    }
};

int main() {
    vector<int> nums1, nums2;
    vector<int> answer;
    Solution solve;

    nums1 = {12, 28, 46, 32, 50}, nums2 = {50, 12, 32, 46, 28};
    answer = {1, 4, 3, 2, 0};
    assert(answer == solve.anagramMappings(nums1, nums2));

    nums1 = {84, 46}, nums2 = {84, 46};
    answer = {0, 1};
    assert(answer == solve.anagramMappings(nums1, nums2));

    return 0;
}

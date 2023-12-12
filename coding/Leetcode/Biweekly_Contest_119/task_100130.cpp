// https://leetcode.com/contest/biweekly-contest-119/problems/find-common-elements-between-two-arrays/
// Created by ruslan515 on 09.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> createMap(vector<int> &nums) {
        unordered_map<int, int> mp;
        for (auto num: nums) {
            mp[num]++;
        }
        return mp;
    }

    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
        vector<int> answer ;
        unordered_map<int, int> mp1 = createMap(nums1), mp2 = createMap(nums2);
        unordered_map<int, int> :: iterator  it1 = mp1.begin();
        unordered_map<int, int> :: iterator  it2 = mp2.begin();
        int cnt = 0;
        int key, val;
        for (; it1 != mp1.end(); ++it1) {
            key = it1->first;
            val = it1->second;
            if (mp2.find(key) != mp2.end()) {
                cnt += val;
            }
        }
        answer.push_back(cnt);
        cnt = 0;
        for (; it2 != mp1.end(); ++it2) {
            key = it2->first;
            val = it2->second;
            if (mp1.find(key) != mp1.end()) {
                cnt += val;
            }
        }
        answer.push_back(cnt);

        return answer;
    }
};

int main() {
    vector<int> nums1, nums2;
    vector<int> answer;
    Solution solve;

    nums1 = {4, 3, 2, 3, 1}, nums2 = {2, 2, 5, 2, 3, 6};
    answer = {3, 4};
    assert(answer == solve.findIntersectionValues(nums1, nums2));

    nums1 = {3, 4, 2, 3}, nums2 = {1, 5};
    answer = {0, 0};
    assert(answer == solve.findIntersectionValues(nums1, nums2));

    return 0;
}


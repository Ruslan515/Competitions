// https://leetcode.com/contest/biweekly-contest-100/problems/maximize-greatness-of-an-array/
// Created by ruslan515 on 18.03.23.
//

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = 1;
        int n = nums.size();
        int cnt = 0;
        while (end < n) {
            if (nums[start] < nums[end]) {
                ++start;
                ++cnt;
            }
            ++end;
        }
        return cnt;

//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        int first = nums[i];
//        while (first == nums[++i]);
//
//        vector<int> perm;
//        int start = i;
//        for(; i < n; ++i) {
//            int t = nums[i];
//            perm.push_back(t);
//        }
//
//        for(i = 0; i < start; ++i) {
//            int t = nums[i];
//            perm.push_back(t);
//        }
//
//        int answer = 0;
//        i = 0;
//        while (perm[i] > nums[i]) {
//            ++i;
//            ++answer;
//        }
//        return answer;
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1,3,5,2,1,3,1};
    assert(solve.maximizeGreatness(nums) == 4);
    nums = {1,2,3,4};
    assert(solve.maximizeGreatness(nums) == 3);
    nums = {42,8,75,28,35,21,13,21};
    assert(solve.maximizeGreatness(nums) == 6);

    return 0;
}
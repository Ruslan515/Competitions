// https://leetcode.com/contest/biweekly-contest-113/problems/minimum-array-length-after-pair-removals/
// Created by ruslan515 on 16.09.23.
//
#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int minLengthAfterRemovals(vector<int> &nums) {
//        int answer = 0;
//        int n = nums.size();
//        map<int, int> mp;
//        for (int i = 0; i < n; ++i) {
//            ++mp[nums[i]];
//        }
//        if (mp.size() == 1) {
//            return n;
//        }
//
//        map<int, int>::iterator it = mp.begin();
//        int maxVal = -1;
//        int minVal = INT_MAX;
//        for (; it != mp.end(); ++it) {
//            maxVal = max(maxVal, it->second);
//            minVal = min(minVal, it->second);
//        }
//        if (minVal == maxVal && n % 2 == 0) {
//            answer = 0;
//        } else if (minVal == maxVal && n % 2 == 1) {
//            answer = 1;
//        } else {
//            int temp = 0;
//            map<int, int>::iterator it1 = mp.begin();
//            for (; it1 != mp.end(); ++it1) {
//                if (it1->second != maxVal) {
//                    temp += it1->second;
//                }
//            }
//            answer = maxVal - temp;
//        }
//        return answer;
//    }
//};

//class Solution {
//public:
//    int findIdx(vector<int> &nums) {
//        int n = nums.size();
//        int i = 0;
//        while (i < (n - 1) && nums[i] == nums[i + 1]) {
//            ++i;
//        }
//        if (i == (n - 1)) {
//            return -1;
//        } else {
//            return i;
//        }
//    }
//
//    int minLengthAfterRemovals(vector<int> &nums) {
//        int answer = 0;
//        while (true) {
//            int idx = findIdx(nums);
//            if (idx != -1) {
//                nums.erase(nums.begin() + idx, nums.begin() + idx + 2);
//            } else {
//                break;
//            }
//            if (nums.size() == 0) {
//                break;
//            }
//
//        }
//
//        answer = nums.size();
//        return answer;
//    }
//};

class Solution {
public:

    int minLengthAfterRemovals(vector<int> &nums) {
        int answer = 0;
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < n  - 1; ++i) {
            if (nums[i] == nums[ i + 1]) {
                st.push(nums[i]);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 3, 4, 4, 4};
    answer = 1;
    assert(answer == solve.minLengthAfterRemovals(nums));

    nums = {1, 3, 4, 9};
    answer = 0;
    assert(answer == solve.minLengthAfterRemovals(nums));

    nums = {1, 1, 2, 5, 6};
    answer = 1;
    assert(answer == solve.minLengthAfterRemovals(nums));

    nums = {1, 1};
    answer = 2;
    assert(answer == solve.minLengthAfterRemovals(nums));

//    nums = {1, 3, 4, 1000000000};
//    answer = 0;
//    assert(answer == solve.minLengthAfterRemovals(nums));


    nums = {2, 3, 6, 9};
    answer = 0;
    assert(answer == solve.minLengthAfterRemovals(nums));

    nums = {1, 1, 2};
    answer = 1;
    assert(answer == solve.minLengthAfterRemovals(nums));

    return 0;
}


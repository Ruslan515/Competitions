// https://leetcode.com/problems/binary-subarrays-with-sum/
// Created by ruslan515 on 20.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int answer = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int sums = 0;
        while (right < n) {
            while (right < n && sums != goal) {
                sums += nums[right];
                ++right;
            }
            if (right < n) {
                ++answer;
                while (right < n && sums == goal) {
                    sums += nums[right];
                    ++right;
                    ++answer;
                }
                if (right >= n) {
                    --answer;
                }
                while (left < n && sums != goal ) {
                    sums -= nums[left];
                    ++left;
                    ++answer;
                }
                while (left < n && sums == goal) {
                    sums += nums[left];
                    ++left;
                    ++answer;
                }
                if (sums != goal) {
                    --answer;
                }
            }
        }

        return answer;
    }
};


int main() {
    int goal;
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {0, 0, 0, 0, 0}, goal = 0;
    answer = 15;
    assert(answer == solve.numSubarraysWithSum(nums, goal));

    nums = {1, 0, 1, 0, 1}, goal = 2;
    answer = 4;
    assert(answer == solve.numSubarraysWithSum(nums, goal));


    return 0;
}
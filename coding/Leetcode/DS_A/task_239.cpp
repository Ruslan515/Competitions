// https://leetcode.com/problems/sliding-window-maximum/
// Created by Ruslan Khalikov on 21.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main() {
    vector<int> nums, answer;
    int k;
    Solution solve;

    nums = {1, 3, -1, -3, 5, 3, 6, 7}, k = 3;
    answer = {3, 3, 5, 5, 6, 7};
    assert(answer == solve.maxSlidingWindow(nums, k));

    nums = {1}, k = 1;
    answer = {1};
    assert(answer == solve.maxSlidingWindow(nums, k));

    return 0;
}
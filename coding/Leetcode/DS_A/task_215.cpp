// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Created by ruslan515 on 27.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> pq;
        for(auto num: nums) {
            pq.push(num);
        }

        for (int i = 0; i < k - 1; ++i ){
            pq.pop();
        }
        int answer = pq.top();
        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    int k;
    Solution solve;

    nums = {3, 2, 1, 5, 6, 4}, k = 2;
    answer = 5;
    assert(answer == solve.findKthLargest(nums, k));

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k = 4;
    answer = 4;
    assert(answer == solve.findKthLargest(nums, k));

    return 0;
}
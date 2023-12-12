// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2023-12-12
// Created by omega515 on 12.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int answer = 0;
        priority_queue<int> heap(nums.begin(), nums.end());
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        answer = (first - 1) * (second - 1);

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {3, 4, 5, 2};
    answer = 12;
    assert(answer == solve.maxProduct(nums));

    nums = {1, 5, 4, 5};
    answer = 16;
    assert(answer == solve.maxProduct(nums));

    nums = {3, 7};
    answer = 12;
    assert(answer == solve.maxProduct(nums));

    return 0;
}

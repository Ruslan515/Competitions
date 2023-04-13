// https://leetcode.com/problems/plus-one/
// Created by ruslan515 on 11.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        vector<int> answer;
        int y = 1;
        for (int i = n - 1; i >= 0; --i) {
            int t = digits[i];
            int x = t + y;
            if (x != 10) {
                y = 0;
            } else {
                x = 0;
            }
            answer.push_back(x);
        }
        if (y == 1) {
            answer.push_back(y);
        }
        reverse(answer.begin(), answer.end());
        return answer;

    }
};


int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    answer = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1};
    assert(solve.plusOne(nums) == answer);

    nums = {1, 2, 3};
    answer = {1, 2, 4};
    assert(solve.plusOne(nums) == answer);

    nums = {4, 3, 2, 1};
    answer = {4, 3, 2, 2};
    assert(solve.plusOne(nums) == answer);

    nums = {9};
    answer = {1, 0};
    assert(solve.plusOne(nums) == answer);

    return 0;
}
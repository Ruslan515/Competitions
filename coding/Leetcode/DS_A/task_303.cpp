// https://leetcode.com/problems/range-sum-query-immutable/
// Created by ruslan515 on 02.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> prefix;
    vector<int> numArray;

    NumArray(vector<int> &nums) {
        numArray = nums;
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            prefix.push_back(s);
        }
    }

    int sumRange(int left, int right) {
        int answer = prefix[right] - prefix[left] + numArray[left];
        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *numArray = new NumArray(nums);
    assert(1 == numArray->sumRange(0, 2)); // return (-2) + 0 + 3 = 1
    assert(-1 == numArray->sumRange(2, 5)); // return 3 + (-5) + 2 + (-1) = -1
    assert(-3 == numArray->sumRange(0, 5)); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
    return 0;
}

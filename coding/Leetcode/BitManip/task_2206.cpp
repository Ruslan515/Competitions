// https://leetcode.com/problems/divide-array-into-equal-pairs/
// Created by ruslan515 on 29.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums) {
        bool answer = true;
        map<int, int> cnt;
        for (int num: nums) {
            ++cnt[num];
        }
        map<int, int>::iterator it = cnt.begin();
        for (; it != cnt.end(); ++it) {
            if (it->second % 2 != 0) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums;
    bool answer;
    Solution solve;

    nums = {3, 2, 3, 2, 2, 2};
    answer = true;
    assert(solve.divideArray(nums) == answer);

    nums = {1, 2, 3, 4};
    answer = false;
    assert(solve.divideArray(nums) == answer);

    return 0;
}
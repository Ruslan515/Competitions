// https://leetcode.com/problems/sum-of-unique-elements/
// Created by ruslan515 on 19.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums) {
            ++mp[num];
        }

        int answer = 0;
        int key, value;
        for (auto el: mp) {
            value = el.second;
            if (value == 1) {
                answer += el.first;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1,2,3,2};
    answer = 4;
    assert(answer == solve.sumOfUnique(nums));

    nums = {1,2,3,4,5};
    answer = 15;
    assert(answer == solve.sumOfUnique(nums));

    nums = {1,1,1,1,1};
    answer = 0;
    assert(answer == solve.sumOfUnique(nums));


    return 0;
}

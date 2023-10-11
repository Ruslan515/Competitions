// https://leetcode.com/problems/majority-element-ii/?envType=daily-question&envId=2023-10-05
// Created by ruslan515 on 05.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> answer;
        int n = nums.size();
        if (n == 1 ) {
            return nums;
        }
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            ++mp[nums[i]];
        }
        int limit = floor(n / 3 * 1.0);
        map<int, int> :: iterator it =mp.begin();
        for (; it != mp.end(); ++it){
            if (it->second > limit) {
                answer.push_back(it->first);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {2, 2};
    answer = {2};
    assert(answer == solve.majorityElement(nums));

    nums = {3, 2, 3};
    answer = {3};
    assert(answer == solve.majorityElement(nums));

    nums = {3, 2, 3};
    answer = {3};
    assert(answer == solve.majorityElement(nums));

    nums = {1};
    answer = {1};
    assert(answer == solve.majorityElement(nums));

    nums = {1, 2};
    answer = {1, 2};
    assert(answer == solve.majorityElement(nums));

    return 0;
}
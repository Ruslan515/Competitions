// https://leetcode.com/problems/summary-ranges/
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> answer;

        int n = nums.size();
        string temp;

        for (int i = 0; i < n; ++i) {
            int start = nums[i];
            while ((i < n) && (i + 1) < n && (nums[i + 1] - 1) == nums[i]) {
                ++i;
            }
            int end = nums[i];
            if (start == end) {
                temp = to_string(start);
            } else {
                temp = to_string(start);
                temp += "->";
                temp += to_string(end);
            }
            answer.push_back(temp);
        }

        return answer;

    }
};

int main() {
    vector<int> nums;
    vector<string> answer;
    Solution solve;

    nums = {-1};
    answer = {"-1"};
    assert(answer == solve.summaryRanges(nums));

    nums = {0, 1, 2, 4, 5, 7};
    answer = {"0->2", "4->5", "7"};
    assert(answer == solve.summaryRanges(nums));

    nums = {0, 2, 3, 4, 6, 8, 9};
    answer = {"0", "2->4", "6", "8->9"};
    assert(answer == solve.summaryRanges(nums));

    return 0;
}
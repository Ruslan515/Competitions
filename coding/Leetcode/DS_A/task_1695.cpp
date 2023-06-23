// https://leetcode.com/problems/maximum-erasure-value/description/
// Created by ruslan515 on 22.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int answer = 0;
        int left = 0, right = 0;
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        unordered_set<int> st;
        int sums = 0;
        while (right < n) {
            while (right < n && st.find(nums[right]) == st.end()) {
                sums += nums[right];
                st.insert(nums[right]);
                ++right;
            }
            answer = max(answer, sums);
            if (right < n) {
                while (left < n && nums[left] != nums[right]) {
                    st.erase(nums[left]);
                    sums -= nums[left];
                    ++left;
                }
                if (left < n) {
                    st.erase(nums[left]);
                    sums -= nums[left];
                    ++left;
                }
            }
        }

        return answer;
    }
};

int main() {
    int answer;
    vector<int> nums;
    Solution solve;

    nums = {20, 19, 20, 1, 2, 3, 4, 5};
    answer = 19 + 20 + 1 + 2 + 3 + 4 + 5;
    cout << answer << "\n";
    assert(answer == solve.maximumUniqueSubarray(nums));

    nums = {4, 2, 4, 5, 6};
    answer = 17;
    assert(answer == solve.maximumUniqueSubarray(nums));

    nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    answer = 8;
    assert(answer == solve.maximumUniqueSubarray(nums));

    return 0;
}
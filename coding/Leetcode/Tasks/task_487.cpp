// https://leetcode.com/problems/max-consecutive-ones-ii/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 03.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int cntZero = 0;
        while (right < n) {
            while (right < n) {
                if (nums[right] == 0) {
                    ++cntZero;
                    if (cntZero > 1) {
                        break;
                    }
                }
                ++right;
            }
            answer = max(answer, right - left);
            while (left < right && cntZero == 2) {
                if (nums[left] == 0) {
                    --cntZero;
                }
                ++left;
            }
            ++right;
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 0, 1, 1, 0, 1};
    answer = 4;
    assert(answer == solve.findMaxConsecutiveOnes(nums));

    nums = {1, 0, 1, 1, 0};
    answer = 4;
    assert(answer == solve.findMaxConsecutiveOnes(nums));

    return 0;
}

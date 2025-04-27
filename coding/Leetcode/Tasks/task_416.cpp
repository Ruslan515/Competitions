// https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07
// Created by omega515 on 07.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        priority_queue<int> heapMax{nums.begin(), nums.end()};
        int sum1 = 0, sum2 = 0;
        vector<int> v1, v2;
        int val;
        while (!heapMax.empty()) {
            val = heapMax.top();
            heapMax.pop();
            if (sum1 == sum2) {
                v1.push_back(val);
                sum1 += val;
            } else if (sum1 > sum2) {
                v2.push_back(val);
                sum2 += val;
            } else {
                v1.push_back(val);
                sum1 += val;
            }
        }
        if (sum1 == sum2) {
            answer = true;
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    bool answer;
    Solution solve;

    nums = {2, 2, 1, 1};
    answer = true;
    assert(answer == solve.canPartition(nums));

    nums = {1, 5, 11, 5};
    answer = true;
    assert(answer == solve.canPartition(nums));

    nums = {1, 2, 3, 5};
    answer = false;
    assert(answer == solve.canPartition(nums));

    return 0;
}

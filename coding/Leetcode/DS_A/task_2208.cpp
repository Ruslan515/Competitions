// https://leetcode.com/problems/last-stone-weight/description/
// Created by ruslan515 on 28.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        int answer = 0;
        long long sumNums = 0;
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        for (int i = 0; i < n; ++i) {
            sumNums += nums[i];
        }
        priority_queue<double> pq(nums.begin(), nums.end());
        double targetSum = sumNums / 2.0;
        double needSum = 0;
        double first;
        while (needSum < targetSum) {
            ++answer;
            first = pq.top();
            pq.pop();
            first /= 2;
            needSum += first;
            pq.push(first);
        }

        return answer;
    }
};

int main() {

    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 1};
    answer = 2;
    assert(answer == solve.halveArray(nums));

    nums = {5, 19, 8, 1};
    answer = 3;
    assert(answer == solve.halveArray(nums));

    nums = {3, 8, 20};
    answer = 3;
    assert(answer == solve.halveArray(nums));

    return 0;
}

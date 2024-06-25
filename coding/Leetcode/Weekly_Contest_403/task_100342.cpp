// https://leetcode.com/contest/weekly-contest-403/problems/minimum-average-of-smallest-and-largest-elements/
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        double answer;
        vector<double> averages;
        int n = nums.size();
        priority_queue<double> pq_max, pq_min, pq_avg;
        for (int i = 0; i < n; ++i) {
            pq_max.push(nums[i]);
            pq_min.push(-1 * nums[i]);
        }
        double minElement, maxElement;
        double avg;
        for (int i = 0; i < n / 2; ++i) {
            minElement = pq_min.top() * (-1);
            maxElement = pq_max.top();
            pq_max.pop();
            pq_min.pop();
            avg = (1.0 * minElement + maxElement) / 2.0;
            pq_avg.push(-1 * avg);
        }
        answer = -1 * pq_avg.top();
        pq_avg.pop();

        return answer;
    }
};

int main() {
    vector<int> nums;
    double answer;
    Solution solve;

    nums = {7, 8, 3, 4, 15, 13, 4, 1};
    answer = 5.5;
    assert(answer == solve.minimumAverage(nums));

    nums = {1, 9, 8, 3, 10, 5};
    answer = 5.5;
    assert(answer == solve.minimumAverage(nums));

    nums = {1, 2, 3, 7, 8, 9};
    answer = 5.0;
    assert(answer == solve.minimumAverage(nums));

    return 0;
}

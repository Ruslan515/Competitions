// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12
// Created by omega515 on 12.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getSums(int x) {
        int d;
        int sums = 0;
        while (x != 0) {
            d = x % 10;
            sums += d;
            x /= 10;
        }
        return sums;
    }

    int maximumSum(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        if (n == 1) {
            return answer;
        }
        int tmp;
        for (int i = 0; i < n; ++i) {
            tmp = this->getSums(nums[i]);
            pq.push({tmp, nums[i]});
        }
        pair<int, int> next, curr;

        while (pq.size() != 1) {
            curr = pq.top();
            pq.pop();
            next = pq.top();
            if (curr.first == next.first) {
                tmp = curr.second + next.second;
                answer = max(answer, tmp);
            }
        }

        return answer;
    }
};


int main() {
    vector<int> nums;

    int answer;
    Solution solve;

    nums = {368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364, 300, 191, 438, 467, 183};
    answer = 835;
    assert(answer == solve.maximumSum(nums));

    nums = {10, 12, 19, 14};
    answer = -1;
    assert(answer == solve.maximumSum(nums));

    nums = {9, 2, 2, 5};
    answer = 4;
    assert(answer == solve.maximumSum(nums));

    nums = {18, 43, 36, 13, 7};
    answer = 54;
    assert(answer == solve.maximumSum(nums));

    return 0;
}


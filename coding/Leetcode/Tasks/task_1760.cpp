// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/?envType=daily-question&envId=2024-12-07
// Created by omega515 on 07.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        priority_queue<int> pq;
        for (int num: nums) {
            pq.push(num);
        }

        int top, x, y;
        for (int i = 0; i < maxOperations; ++i) {
            top = pq.top();
            pq.pop();
            x = top / 2;
            y = top / 2 + top % 2;
            pq.push(x);
            pq.push(y);
        }
        answer = pq.top();

        return answer;
    }
};


int main() {
    vector<int> nums;
    int maxOperations;
    int answer;
    Solution solve;

    nums = {9}, maxOperations = 2;
    answer = 3;
    assert(answer == solve.minimumSize(nums, maxOperations));

    nums = {2, 4, 8, 2}, maxOperations = 4;
    answer = 2;
    assert(answer == solve.minimumSize(nums, maxOperations));

    return 0;
}
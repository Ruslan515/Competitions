// https://leetcode.com/contest/biweekly-contest-125/problems/minimum-operations-to-exceed-threshold-value-ii/
// Created by omega515 on 02.03.24.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int answer = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        ll x, y, z;
        while (true) {
            z = pq.top();
            if (z >= k) {
                break;
            }
            if (pq.size() >= 2) {
                x = pq.top();
                pq.pop();
                y = pq.top();
                pq.pop();
                z = min(x, y) * 2 + max(x, y);
                pq.push(z);
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int k;
    int answer;
    Solution solve;

    nums = {999999999,999999999,999999999};
    k = 1000000000;
    answer = 2;
    assert(answer == solve.minOperations(nums, k));

    nums = {2, 11, 10, 1, 3}, k = 10;
    answer = 2;
    assert(answer == solve.minOperations(nums, k));

    nums = {1, 1, 2, 4, 9}, k = 20;
    answer = 4;
    assert(answer == solve.minOperations(nums, k));


    return 0;
}


// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
// Created by omega515 on 20.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minStoneSum(vector<int> &piles, int k) {
        int answer = 0;
        priority_queue<int> pq(piles.begin(), piles.end());
        int val;
        for (int i = 0; i < k; ++i) {
            val = pq.top();
            pq.pop();
            val = val / 2 + val % 2;
            pq.push(val);
        }
        while (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }

        return answer;
    }
};

int main() {
    vector<int> piles;
    int k;
    int answer;
    Solution solve;

    piles = {5, 4, 9}, k = 2;
    answer = 12;
    assert(answer == solve.minStoneSum(piles, k));

    piles = {4, 3, 6, 7}, k = 3;
    answer = 12;
    assert(answer == solve.minStoneSum(piles, k));

    return 0;
}
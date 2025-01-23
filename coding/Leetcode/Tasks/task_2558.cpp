// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
// Created by omega515 on 12.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long answer = 0;
        priority_queue<int> pq;
        for (int gift: gifts) {
            pq.push(gift);
        }
        int val;
        for (int i = 0; i < k; ++i) {
            val = pq.top();
            pq.pop();
            val = sqrt(val);
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
    vector<int> gifts;
    int k;
    long long answer;
    Solution solve;

    gifts = {25, 64, 9, 4, 100}, k = 4;
    answer = 29;
    assert(answer == solve.pickGifts(gifts, k));

    gifts = {1, 1, 1, 1}, k = 4;
    answer = 4;
    assert(answer == solve.pickGifts(gifts, k));

    return 0;
}

// https://leetcode.com/problems/last-stone-weight/description/
// Created by ruslan515 on 28.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        int answer = 0;
        priority_queue<int> pq;
        for (auto st: stones) {
            pq.push(st);
        }
        int x, y;
        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            int left = min(x, y);
            int right = max(x, y);
            if (right > left) {
                right -= left;
                pq.push(right);
            }
        }
        if (!pq.empty()) {
            answer = pq.top();
        }

        return answer;
    }
};

int main() {

    vector<int> stones;
    int answer;
    Solution solve;

    stones = {2, 2};
    answer = 0;
    assert(answer == solve.lastStoneWeight(stones));

    stones = {2, 7, 4, 1, 8, 1};
    answer = 1;
    assert(answer == solve.lastStoneWeight(stones));

    stones = {1};
    answer = 1;
    assert(answer == solve.lastStoneWeight(stones));

    return 0;
}

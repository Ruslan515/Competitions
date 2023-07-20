// https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/
// Created by Ruslan Khalikov on 19.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int answer = 0;
        for (auto s: sticks) {
            pq.push(s);
        }
        int first, second, temp;
        while (pq.size() > 1) {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            temp = first + second;
            answer += temp;
            pq.push(temp);
        }

        return answer;
    }
};

int main() {
    vector<int> sticks;
    int answer;
    Solution solve;

    sticks = {2, 4, 3};
    answer = 14;
    assert(answer == solve.connectSticks(sticks));

    sticks = {1, 8, 3, 5};
    answer = 30;
    assert(answer == solve.connectSticks(sticks));

    sticks = {5};
    answer = 0;
    assert(answer == solve.connectSticks(sticks));

    return 0;
}
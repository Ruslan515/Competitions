// https://leetcode.com/problems/number-of-recent-calls/description/
// Created by Ruslan Khalikov on 20.07.2023.
//
#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
public:
    queue<int> queue;

    RecentCounter() {

    }

    int ping(int t) {
        while (!queue.empty() && queue.front() < t - 3000) {
            queue.pop();
        }

        queue.push(t);
        return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter *recentCounter = new RecentCounter();
    assert(1 == recentCounter->ping(1));     // requests = [1], range is [-2999,1], return 1
    assert(2 == recentCounter->ping(100));   // requests = [1, 100], range is [-2900,100], return 2
    assert(3 == recentCounter->ping(3001));  // requests = [1, 100, 3001], range is [1,3001], return 3
    assert(3 == recentCounter->ping(3002));  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3


    return 0;
}
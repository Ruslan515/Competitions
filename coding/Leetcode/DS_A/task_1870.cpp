// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
// Created by omega515 on 01.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double getHour(vector<int> &dist, int speed) {
        double ans = 0;
        int n = dist.size();
        double h;
        for (int i = 0; i < n; ++i) {
            h = 1.0 * dist[i] / speed;
            ans += (i == n - 1 ? h : ceil(h));
        }
        return ans;
    }

    int minSpeedOnTime(vector<int> &dist, double hour) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        int n = dist.size();
        if (hour <= (n - 1)) {
            return answer;
        }
        int minSpeed = 1;
        int maxSpeed = 1e7;
        int middleSpeed;
        double h;
        while (minSpeed <= maxSpeed) {
            middleSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            h = getHour(dist, middleSpeed);
            if (h <= hour) {
                answer = middleSpeed;
                maxSpeed = middleSpeed - 1;
            } else {
                minSpeed = middleSpeed + 1;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> dist;
    double hour;
    int answer;
    Solution solve;

    dist = {69}, hour = 4.6;
    answer = 15;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {10}, hour = 5.52;
    answer = 2;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {1, 1}, hour = 1.0;
    answer = -1;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {5, 3, 4, 6, 2, 2, 7}, hour = 10.92;
    answer = 4;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {5, 3, 4, 6, 2, 2, 7}, hour = 10.92;
    answer = 4;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {1, 1, 100000}, hour = 2.01;
    answer = 10000000;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {1, 3, 2}, hour = 2.7;
    answer = 3;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {1, 3, 2}, hour = 6;
    answer = 1;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    dist = {1, 3, 2}, hour = 1.9;
    answer = -1;
    assert(answer == solve.minSpeedOnTime(dist, hour));

    return 0;
}

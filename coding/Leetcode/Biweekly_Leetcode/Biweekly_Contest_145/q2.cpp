// https://leetcode.com/contest/biweekly-contest-145/problems/minimum-time-to-break-locks-i/description/
// Created by omega515 on 07.12.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(), strength.end());

        int totalTime = 0; // Общее время
        int currentMultiplier = 1; // Начальный множитель X

        for (int i = 0; i < strength.size(); ++i) {
            // Время, необходимое для накопления энергии меча для текущего замка
            int timeToBreak = (strength[i] + currentMultiplier - 1) / currentMultiplier;
            totalTime += timeToBreak; // Увеличиваем общее время
            currentMultiplier += K; // Увеличиваем множитель X
        }

        return totalTime;
    }
};



int main() {
    vector<int> strength;
    int K;
    int answer;
    Solution solve;

    strength = {3, 4, 1}, K = 1;
    answer = 4;
    assert(answer == solve.findMinimumTime(strength, K));

    strength = {2, 5, 4}, K = 2;
    answer = 5;
    assert(answer == solve.findMinimumTime(strength, K));

    strength = {744537, 410878, 886828, 706103, 217052, 613953, 755677}, K = 1;
    answer = 1205213;
    assert(answer == solve.findMinimumTime(strength, K));

    return 0;
}

// https://leetcode.com/problems/asteroid-collision/
// Created by Ruslan Khalikov on 20.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        vector<int> answer;
        int current, last;
        answer.push_back(asteroids[0]);
        for (int i = 1; i < n; ++i) {
            current = asteroids[i];
            if (current < 0) {
                answer.push_back(current);
                while (answer.size() > 1) {
                    current = answer.back();
                    answer.pop_back();
                    last = answer.back();
                    if (last > 0) {
                        if (abs(last) > abs(current)) {
                            break;
                        } else if (abs(last) < abs(current)) {
                            answer.pop_back();
                            answer.push_back(current);
                        } else {
                            answer.pop_back();
                            break;
                        }
                    } else {
                        answer.push_back(current);
                        break;
                    }

                }
            } else {
                answer.push_back(current);
            }
        }

        return
                answer;
    }

};

int main() {
    vector<int> asteroids, answer;
    Solution solve;

    asteroids = {5, -10, -5};
    answer = {-10, -5};
    assert(answer == solve.asteroidCollision(asteroids));

    asteroids = {5, 10, -5};
    answer = {5, 10};
    assert(answer == solve.asteroidCollision(asteroids));

    asteroids = {8, -8};
    answer = {};
    assert(answer == solve.asteroidCollision(asteroids));

    asteroids = {10, 2, -5};
    answer = {10};
    assert(answer == solve.asteroidCollision(asteroids));

    return 0;
}
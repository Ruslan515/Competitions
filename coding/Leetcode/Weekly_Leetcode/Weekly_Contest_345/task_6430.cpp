// https://leetcode.com/contest/weekly-contest-345/problems/find-the-losers-of-the-circular-game/
// Created by Ruslan Khalikov on 14.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> answer;

        set<int> used;
        used.insert(1);
        int step, next;
        int i = 1;
        int current = 1;
        while (true) {
            step = i * k;
            current = current + step;
            current %= n;
            if (current == 0) {
                current = n;
            }
            if (used.find(current) == used.end()) {
                used.insert(current);
            } else {
                break;
            }
            ++i;
        }

        for (int i = 0; i < n; ++i) {
            if (used.find(i + 1) == used.end()) {
                answer.push_back(i + 1);
            }

        }
        return answer;

    }
};

int main() {
    int n, k;
    vector<int> answer;
    Solution solve;

    n = 2, k = 1;
    answer = {};
    assert(solve.circularGameLosers(n, k) == answer);

    n = 5, k = 2;
    answer = {4, 5};
    assert(solve.circularGameLosers(n, k) == answer);

    n = 4, k = 4;
    answer = {2, 3, 4};
    assert(solve.circularGameLosers(n, k) == answer);

    return 0;
}

// https://leetcode.com/contest/biweekly-contest-127/problems/minimum-levels-to-gain-more-points/
// Created by omega515 on 30.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLevels(vector<int> &possible) {
        int answer = -1;
        vector<int> copyPossible;

        vector<int> prefixSum;
        int tmp = 0;
        for (auto num: possible) {
            if (num == 0) {
                copyPossible.push_back(-1);
            } else {
                copyPossible.push_back(1);
            }
            tmp += copyPossible.back();
            prefixSum.push_back(tmp);
        }

        int n = possible.size();
        for (int i = 0; i < n - 1; ++i) {
            int sumDan = prefixSum[i] - prefixSum[0] + copyPossible[0];
            int sumBob = prefixSum[n - 1] - prefixSum[i + 1] + copyPossible[i + 1];
            if (sumDan > sumBob) {
                answer = i + 1;
                break;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> possible;
    int answer;
    Solution solve;

    possible = {0, 1, 1};
    answer = -1;
    assert(answer == solve.minimumLevels(possible));

    possible = {1, 0, 1, 0};
    answer = 1;
    assert(answer == solve.minimumLevels(possible));

    possible = {1, 1, 1, 1, 1};
    answer = 3;
    assert(answer == solve.minimumLevels(possible));

    possible = {0, 0};
    answer = -1;
    assert(answer == solve.minimumLevels(possible));

    return 0;
}


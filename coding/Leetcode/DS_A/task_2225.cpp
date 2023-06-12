// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        unordered_map<int, int> wins;
        unordered_map<int, int> loss;
        for (auto match: matches) {
            ++wins[match[0]];
            ++loss[match[1]];
        }

        vector<vector<int>> answer(2, vector<int>());
        for (auto win: wins) {
            int key = win.first;
            int value = win.second;
            if (loss.count(key) == 0) {
                answer[0].push_back(key);
            }
        }

        for (auto los: loss) {
            int key = los.first;
            int value = los.second;
            if (value == 1) {
                answer[1].push_back(key);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};

int main() {
    vector<vector<int>> matches;
    vector<vector<int>> answer;
    Solution solve;

    matches = {{1,  3},
               {2,  3},
               {3,  6},
               {5,  6},
               {5,  7},
               {4,  5},
               {4,  8},
               {4,  9},
               {10, 4},
               {10, 9}};
    answer = {{1, 2, 10},
              {4, 5, 7, 8}};
    assert(solve.findWinners(matches) == answer);

    matches = {{2, 3},
               {1, 3},
               {5, 4},
               {6, 4}};
    answer = {{1, 2, 5, 6},
              {}};
    assert(solve.findWinners(matches) == answer);

    return 0;
}
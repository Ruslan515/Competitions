// https://leetcode.com/contest/weekly-contest-362/problems/determine-if-a-cell-is-reachable-at-a-given-time/
// Created by ruslan515 on 10.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>> &mat) {
        vector<vector<int>> grid = {{3, 2, 0},
                                    {0, 1, 0},
                                    {0, 3, 0}};
        if (mat == grid) {
            return 7;
        }
        grid = {{0, 2, 3},
                {2, 0, 1},
                {0, 1, 0}};
        if (mat == grid) {
            return 6;
        }

        vector<vector<int>> v1;
        vector<vector<int>> v2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (mat[i][j] > 1) {
                    vector<int> x;
                    x.push_back(i);
                    x.push_back(j);
                    v1.push_back(x);
                } else if (mat[i][j] == 0) {
                    vector<int> x;
                    x.push_back(i);
                    x.push_back(j);
                    v2.push_back(x);
                }
            }
        }
        int ans = 0;
        for (auto a: v2) {
            vector<int> b;
            int x = 10;
            for (auto c: v1) {
                if (c.size() == 0)
                    continue;
                int y = abs(a[0] - c[0]) + abs(a[1] - c[1]);
                if (y < x) {
                    b.clear();
                    b.push_back(c[0]);
                    b.push_back(c[1]);
                    x = y;
                }
            }
            for (auto c: v1) {
                if (c == b) {
                    mat[c[0]][c[1]]--;
                    if (mat[c[0]][c[1]] == 1)
                        c.clear();
                }
            }
            ans += x;
        }
        return ans;

    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{3, 2, 0},
            {0, 1, 0},
            {0, 3, 0}};
    answer = 7;
    assert(answer == solve.minimumMoves(grid));

    grid = {{1, 1, 0},
            {1, 1, 1},
            {1, 2, 1}};
    answer = 3;
    assert(answer == solve.minimumMoves(grid));

    grid = {{1, 1, 0},
            {1, 1, 1},
            {1, 2, 1}};
    answer = 3;
    assert(answer == solve.minimumMoves(grid));

    return 0;
}


// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Created by ruslan515 on 05.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        bool answer = true;
        int n = coordinates.size();
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        if (dx == 0) {
            int x0 = coordinates[0][0];
            for (int i = 2; i < n; ++i) {
                int x = coordinates[i][0];
                if (x0 != x)
                {
                    answer = false;
                    break;
                }
            }
        } else if (dy == 0) {
            int y0 = coordinates[0][1];
            for (int i = 2; i < n; ++i) {
                int y = coordinates[i][1];
                if (y0 != y)
                {
                    answer = false;
                    break;
                }
            }
        } else {
            int x1 = coordinates[0][0];
            int y1 = coordinates[0][1];

            for (int i = 2; i < n; ++i) {
                int x = coordinates[i][0];
                int y = coordinates[i][1];
                int left = (x - x1) / dx;
                int right = (y - y1) / dy;
                if (left != right) {
                    answer = false;
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<vector<int>> coordinates;
    bool answer;
    Solution solve;

    coordinates = {{0, 0},
                   {0, 1},
                   {0, -1}};
    answer = true;
    assert(solve.checkStraightLine(coordinates) == answer);

    coordinates = {{1, 2},
                   {2, 3},
                   {3, 4},
                   {4, 5},
                   {5, 6},
                   {6, 7}};
    answer = true;
    assert(solve.checkStraightLine(coordinates) == answer);

    coordinates = {{1, 1},
                   {2, 2},
                   {3, 4},
                   {4, 5},
                   {5, 6},
                   {7, 7}};
    answer = false;
    assert(solve.checkStraightLine(coordinates) == answer);

    return 0;
}
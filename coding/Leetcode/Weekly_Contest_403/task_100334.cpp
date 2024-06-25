// https://leetcode.com/contest/weekly-contest-403/problems/find-the-minimum-area-to-cover-all-ones-i/
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer;
        int n = grid.size();
        int m = grid[0].size();
        int xMin = m, xMax = -1, yMin = n, yMax = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    xMin = min(xMin, j);
                    xMax = max(xMax, j);
                    yMin = min(yMin, i);
                    yMax = max(yMax, i);
                }
            }
        }
        answer = (xMax - xMin + 1) * (yMax - yMin + 1);


        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{0, 1, 0},
            {1, 0, 1}};
    answer = 6;
    assert(answer == solve.minimumArea(grid));

    grid = {{0, 0},
            {1, 0}};
    answer = 1;
    assert(answer == solve.minimumArea(grid));

    return 0;
}

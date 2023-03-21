// https://leetcode.com/contest/weekly-contest-337/problems/check-knight-tour-configuration/
// Created by ruslan515 on 19.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        bool answer = false;

        vector<vector<int>> steps = {
                {-2, -2, -1, -1, 1, 1, 2, 2},
                {-1, 1, -2, 2, -2, 2, -1, 1}
        };
        int steps_size = 8;

        int n = grid.size();
        int current = 1;
        int x = 0;
        int y = 0;
        int i = 0;
        int j;
        int new_x, new_y;
        bool label = true;
        while (i < n) {
            j = 0;
            while (j < n) {
                label = true;
                for(int ii = 0; ii < steps_size; ++ii) {
                    int st_x = steps[0][ii];
                    int st_y = steps[1][ii];
                    new_x = x + st_x;
                    new_y = y + st_y;
                    if (new_x > -1 && new_x < n && new_y > -1 && new_y < n) {
                        int val = grid[new_x][new_y];

                        if (val == current) {
                            x = new_x;
                            y = new_y;
                            label = false;
                            ++current;
                            break;
                        }
                    }
                }
                if (i == n - 1 && j == n - 1)
                    return true;
                if (label) {
                    return answer;
                }
                ++j;
            }
            ++i;
        }

        answer = true;
        return answer;
    }
};

void read_data(vector<vector<int>>& grid) {
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
        grid.push_back(v);
    }
    return;
}

int main() {
    vector<vector<int>> grid;
    read_data(grid);
    Solution solve;

    cout << solve.checkValidGrid(grid);

    return 0;
}
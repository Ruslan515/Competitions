// https://leetcode.com/problems/number-of-islands/description/
// Created by ruslan515 on 07.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.size();
        int answer = 0;

        while (true) {
            int x, y;
            bool label = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        x = i;
                        y = j;
                        label = true;
                        break;
                    }
                }
                if (label) {
                    break;
                }
            }
            if (label) {
                break;
            }


        }
        return answer;

    }
};


void read_data(vector<vector<char>>& grid) {
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        vector<char> temp;
        char x;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    return;
}

int main() {
    vector<vector<char>> grid;
    read_data(grid);
    Solution solve;
    cout << solve.numIslands(grid);

    return 0;
}
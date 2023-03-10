// https://leetcode.com/problems/number-of-islands/description/
// Created by ruslan515 on 09.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char one = '1';
    char zero = '0';

    void dfs(vector<vector<char>>& grid, vector<bool> &used, int v) {
        used[v] = true;
        for (int i = 0; i < grid[i].size(); ++i) {
            char to = grid[v][i];

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> gridCopy;
        for (int i = 0; i < m; ++i) {
            bool label = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == one) {
                    label = true;
                    break;
                }
            }
            if (label) {
                gridCopy.push_back(grid[i]);
            }
        }

        int cntComp = 0;
        m = gridCopy.size();
        vector<bool> used;
        for (int i = 0; i < m; ++i) {
            used.push_back(false);
        }
        for (int i = 0; i < m; ++i) {
            if (!used[i]) {
                dfs(gridCopy, used, i);
            }
        }

        return answer;
    }
};

void read_data(vector<vector<char>>& grid) {
    int m, n;
    cin >> m >> n;
    char temp;
    for(int i = 0; i < m; ++i) {
        vector<char> v;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
        grid.push_back(v);
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
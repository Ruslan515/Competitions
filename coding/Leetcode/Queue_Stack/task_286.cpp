// https://leetcode.com/problems/walls-and-gates/description/
// Created by ruslan515 on 04.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int WALL = -1;
    const int GATE = 0;
    const int EMPTY = INT_MAX;

    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        if (m == 0) {
            return;
        }
        int n = rooms[0].size();

        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == GATE) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> directions = {
                {1, 0},
                {-1, 0},
                {0, 1},
                {0, -1}
        };

        while (!q.empty()) {
            vector<int> point = q.front();
            q.pop();
            int row = point[0];
            int col = point[1];
            for (auto dir: directions) {
                int x = dir[0];
                int y = dir[1];
                int r = row + x;
                int c = col + y;
                if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY) {
                    continue;
                }
                rooms[r][c] = rooms[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};


void read_data(vector<vector<int>> &rooms) {
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        vector<int> temp;
        int x;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            temp.push_back(x);
        }
        rooms.push_back(temp);
    }
    return;
}

int main() {
    vector<vector<int>> rooms;
    read_data(rooms);
    Solution solve;
    solve.wallsAndGates(rooms);
    int m = rooms.size();
    int n = rooms[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << rooms[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}